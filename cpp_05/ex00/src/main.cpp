/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:07:54 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/29 23:02:54 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "=== Test des constructeurs ===" << std::endl;
    
    try {
        std::cout << "Test constructeur standard: " << std::endl;
        Bureaucrat normal("Normal", 75);
        std::cout << normal << std::endl;
        
        std::cout << "\nTest grade trop élevé (0): " << std::endl;
        Bureaucrat tooHigh("TooHigh", 0);
        std::cout << "Cette ligne ne devrait pas s'afficher" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "\nTest grade trop bas (151): " << std::endl;
        Bureaucrat tooLow("TooLow", 151);
        std::cout << "Cette ligne ne devrait pas s'afficher" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test d'incrémentation et de décrémentation ===" << std::endl;
    
    try {
        std::cout << "Test incrémentation standard: " << std::endl;
        Bureaucrat b("Bob", 10);
        std::cout << "Avant: " << b << std::endl;
        b.incrementGrade();
        std::cout << "Après incrémentation: " << b << std::endl;
        
        std::cout << "\nTest décrémentation standard: " << std::endl;
        std::cout << "Avant: " << b << std::endl;
        b.decrementGrade();
        std::cout << "Après décrémentation: " << b << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "\nTest incrémentation à la limite (grade 1): " << std::endl;
        Bureaucrat b("TopGrade", 1);
        std::cout << "Avant: " << b << std::endl;
        b.incrementGrade();
        std::cout << "Cette ligne ne devrait pas s'afficher" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "\nTest décrémentation à la limite (grade 150): " << std::endl;
        Bureaucrat b("BottomGrade", 150);
        std::cout << "Avant: " << b << std::endl;
        b.decrementGrade();
        std::cout << "Cette ligne ne devrait pas s'afficher" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test de copie ===" << std::endl;
    Bureaucrat original("Original", 42);
    Bureaucrat copie(original);
    std::cout << "Original: " << original << std::endl;
    std::cout << "Copie: " << copie << std::endl;
    
    return 0;
}