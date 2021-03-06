/*******************************************************************************
 * This file is part of the "Data structures and algorithms" course. FMI 2018/19 
 *******************************************************************************/

/**
 * @file   main.cpp
 * @author Ivan Filipov
 * @date   02.2019
 * @brief  Main for example usage
 *         and running some tests 
 *         for our custom splay tree.
 */

#include <iostream> // std::cout

#include "../../../utils/student.h"
#include "splay_tree.hpp"

/** Run a fixed tree tests */
void run_basic_tests() {
	// create empty tree
	dsa::splay_tree<dsa::student> tree;
	// add some elements
	tree.insert({ "Ivancho", 40000 });
	tree.insert({ "Mariika", 25000 });
	tree.insert({ "Gencho", 50001 });
	tree.insert({ "Pencho", 25000 });
	tree.insert({ "Genka", 42000 });
	tree.insert({ "Penka", 25000 });
	tree.insert({ "Kalin", 40000 });
	tree.insert({ "Kalinka", 25000 });

	std::cout << "\ntree's element count = " << tree.size() << std::endl;
	tree.print_sorted_keys(std::cout);
	
	std::cout << "\n\nsearching for Ivancho :" << std::endl;
	try {
		const dsa::student& s = tree.find({ "Ivancho", 40000 });
		std::cout << "found! His fn is : " << s.fn << std::endl;
	} catch (...) {
		std::cout << "not found!" << std::endl;
	}
	
	std::cout << "\n\nsearching for Ivan :" << std::endl;
	try {
		const dsa::student& s = tree.find({ "Ivan", 200 });
		std::cout << "found! His fn is : " << s.fn << std::endl;
	} catch (...) {
		std::cout << "not found!" << std::endl;
	}

	std::cout << "\nremoving \"Genka\"...";
	try {
		tree.remove({ "Genka", 42000 });
		std::cout << "done!" << std::endl;
	} catch(...) {}
	tree.print_sorted_keys(std::cout);
	std::cout << std::endl;
}


int main() {
	
	std::cout << "running basic tests on given splay tree" << std::endl;
	run_basic_tests();

	return 0;
}
