#include "NT_item.h"


NT_item::NT_item(NT_item_data data) : m_data(data)
{
	m_left_time = data.m_end_time - time(NULL);
}



NT_item_disposable::NT_item_disposable(NT_item_data data) : NT_item(data)
{

}
