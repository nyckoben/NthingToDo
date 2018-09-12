#include "NT_db.h"

NT_db::NT_db()
{
	if (sqlite3_open("NT_database.db", &m_p_db)) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(m_p_db));
		return;
	}
	creat_table_for_item();
// 	NT_item_data data;
// 	data.m_description = "nycko";
// 	data.m_start_time = time(NULL);
// 	data.m_end_time = time(NULL) + 3600;
// 	add_item_data_to_db(data);
}
NT_db::~NT_db()
{
	sqlite3_close(m_p_db);

}

int get_item_data_callback(void *p_data, int argc, char **argv, char **azColName) 
{
	std::set<NT_item_data> *p_set_data = (std::set<NT_item_data>*)p_data;
	NT_item_data item_data;
	int i;
	for (i = 0; i < argc; i++) 
	{
		if (!strcmp(azColName[i], "id"))
		{
			item_data.m_id = atoi(argv[i]);
		}
		else if (!strcmp(azColName[i], "description"))
		{
			item_data.m_description = argv[i];
		}
		else if (!strcmp(azColName[i], "stime"))
		{
			item_data.m_start_time = atoi(argv[i]);
		}
		else if (!strcmp(azColName[i], "etime"))
		{
			item_data.m_end_time = atoi(argv[i]);
		}
		else if (!strcmp(azColName[i], "level"))
		{
			item_data.m_level = atoi(argv[i]);
		}
	}
	p_set_data->insert(item_data);
	return 0;
}

int NT_db::get_item_data_from_db(time_t before_time, std::set<NT_item_data> &data)
{
	if (!m_p_db)
	{
		return -1;
	}
	time_t tNow = time(NULL);
	char tNow_s[64] = { 0 };
	char tEnd_s[64] = { 0 };
	itoa(tNow, tNow_s, 10);
	itoa(tNow + 60 * 60 * 24, tEnd_s, 10);
	std::string sql = "SELECT * from " + m_table_name + " where etime between " + tNow_s + " and " + tEnd_s + ";";

	/* Execute SQL statement */
	char *zErrMsg = 0;
	if (SQLITE_OK != sqlite3_exec(m_p_db, sql.c_str(), get_item_data_callback, &data, &zErrMsg)) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		return -1;
	}
	return 0;
}


int NT_db::add_item_data_to_db(NT_item_data &data)
{
	if (!m_p_db)
	{
		return -1;
	}
	char sql[256] = { 0 };
	sprintf(sql
		,"INSERT INTO %s (description, stime, etime, level) VALUES (\"%s\", %lld, %lld, %d );"
		, m_table_name.c_str(), data.m_description.c_str(), data.m_start_time, data.m_end_time, data.m_level);

	/* Execute SQL statement */
	char *zErrMsg = 0;
	if (SQLITE_OK != sqlite3_exec(m_p_db, sql, NULL, NULL, &zErrMsg)) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		return -1;
	}
	return 0;
}

int NT_db::del_item_data_to_db(int id)
{
	if (!m_p_db)
	{
		return -1;
	}
	char sql[256] = { 0 };
	sprintf(sql
		, "DELETE %s WHERE id=%d;"
		, m_table_name.c_str(), id);

	/* Execute SQL statement */
	char *zErrMsg = 0;
	if (SQLITE_OK != sqlite3_exec(m_p_db, sql, NULL, NULL, &zErrMsg)) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		return -1;
	}
	return 0;
}

int NT_db::creat_table_for_item()
{
	if (!m_p_db)
	{
		return -1;
	}

	std::string sql = "CREATE TABLE " + m_table_name + "("  \
		"id INTEGER  PRIMARY KEY AUTOINCREMENT," \
		"description           TEXT    NOT NULL," \
		"stime            UNSIGNED BIG INT     NOT NULL," \
		"etime            UNSIGNED BIG INT     NOT NULL," \
		"level			TEXT NOT NULL);";

	/* Execute SQL statement */
	char *zErrMsg = 0;
	if (sqlite3_exec(m_p_db, sql.c_str(), NULL, NULL, &zErrMsg) != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		return -1;
	}
	return 0;
}