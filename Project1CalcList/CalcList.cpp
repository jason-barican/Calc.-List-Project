//Jason Barican U18728557
//Samuel Sau U44954874

#include "CalcList.hpp"


/*File for function definitions from CalcList.hpp*/

//Constructor
CalcList::CalcList():CalcListInterface() {

	current = new CalcNode;
	current->n_operator = ADDITION;
	current->operand = 0.0;
	current->total = 0.0;
	current->next = current;
}
//Destructor, keep removing nodes while linked list not empty
CalcList::~CalcList() {

	while (steps != 0){
        //checks if list is empty, throw exception
	if (operation_count == 0)) {
        throw ("Invalid operation: Empty List");
	}

	//restores previous total and removes last operation - "undo feature"
	else {
        //decrement number of operations when removing
		--operation_count;
        //assigns a pointer that will be removed for that particular element
		CalcNode* old = current->next;

		//just set current to null if reference itself
		if (old == current) {
                current = nullptr;
        }
		else {
            //reassign the next pointer to point to next node
			current->next = old->next;
		}
		//delete the temporary node, such that
		delete old;
	}
	}
}

//returns total
double CalcList::total() const{
	return current->next->total;
}

void CalcList::newOperation(const FUNCTIONS func, const double operand) {

	//increase operation count
	++operation_count;
	//adds in the beginning of the Linked List
	CalcNode* before_current = new CalcNode;

    //initializes to add default for linked list
	before_current->next = nullptr;
	before_current->total = 0.0;
	before_current->operand = 0.0;
	before_current->n_operator = ADDITION;

	//If list is empty, create a new node and set to itself
	if (current == nullptr) {
		before_current->total = element;
		current = before_current;
		current->next = before_current;
	}

	//Or just put the node and make it for current's next
	else {
		before_current->next = current->next;
		before_current->total = current->next->total;
		current->next = before_current;
	}

	//updates new node with operator, operand, and total
	switch (func) {

	case ADDITION:
		current->next->n_operator = ADDITION;
		current->next->operand = operand;
		current->next->total += operand;
		break;

	case SUBTRACTION:
		current->next->n_operator = SUBTRACTION;
		current->next->operand = operand;
		current->next->nodes_total -= operand;
		break;

	case MULTIPLICATION:
		current->next->n_operator = MULTIPLICATION;
		current->next->operand = operand;
		current->next->total *= operand;
		break;

    //Throws division error if operand is == 0
	case DIVISION:
		if (operand >= 0 && operand < 1.00) {
            removeLastOperation();
            throw("Division Error... Cannot divide by 0");
        }
        //if successful (anything but 0)
		else {
			cursor->next->n_operator = DIVISION;
			cursor->next->operand = operand;
			cursor->next->total /= operand;
			break;
		}
    //throws error if our arithmetic operation was not valid
	default:
		throw ("Invalid arithmetic operation...");
		break;
	}
}

//Undo the last operation from user input
void CalcList::removeLastOperation() {

	//checks if list is empty, throw exception
	if (operation_count == 0)) {
        throw ("Invalid operation: Empty List");
	}

	//restores previous total and removes last operation - "undo feature"
	else {
        //decrement number of operations when removing
		--operation_count;
        //assigns a pointer that will be removed for that particular element
		CalcNode* old = current->next;

		//just set current to null if reference itself
		if (old == current) {
                current = nullptr;
        }
		else {
            //reassign the next pointer to point to next node
			current->next = old->next;
		}
		//delete the temporary node, such that
		delete old;
	}
}

/*Converts operations to string and outputs to user*/
std::string CalcList::toString(unsigned short precision) const {

	/*String stream will get past operation in string buffer*/
	std::stringstream ss;
	//Initialized as empty string and will convert the data to string
	std::string to_string = "";
	//Temporarily hold number of operations
	int temp_operation_count = operation_count;

	CalcNode* temp = new CalcNode;
	node_ptr = current->next;

    //precisely define the string stream's numerical value
	ss.precision(precision);

	//as long as the total number of operations is not 0, then we keep continuing to output to ss
	while(node_ptr->total != 0){
		ss << temp_operation_count << ": ";

		ss << std::fixed << node_ptr->next->total;

		if (node_ptr->n_operator == ADDITION) {
			ss << "+";
		}
		else if (node_ptr->n_operator == SUBTRACTION) {
			ss << "-";
		}
		else if (node_ptr->n_operator == MULTIPLICATION) {
			ss << "*";
		}
		else if (node_ptr->n_operator == DIVISION) {
			ss << "/";
		}
		ss << node_ptr->n_operand;
		ss << "=";
		ss << node_ptr->total;
		ss << std::endl;

		node_ptr = node_ptr->next;
		--temp_operation_count;
	}
	to_string = ss.str();/*Convert and return*/
	return to_string;
}
