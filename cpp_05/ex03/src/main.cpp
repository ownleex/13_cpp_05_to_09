/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:15:16 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/05/16 23:15:47 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    std::cout << "=== Test de l'Intern ===" << std::endl;
    
    Intern anonymousIntern;
    Bureaucrat manager("Manager", 50);
    Bureaucrat president("Président", 1);
    
    std::cout << "\n--- Création de formulaires valides ---" << std::endl;
    
    try {
        AForm* shrub = anonymousIntern.makeForm("shrubbery creation", "jardin");
        std::cout << *shrub << std::endl;
        
        manager.signForm(*shrub);
        manager.executeForm(*shrub);
        
        delete shrub;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    try {
        AForm* robotomy = anonymousIntern.makeForm("robotomy request", "Bender");
        std::cout << *robotomy << std::endl;
        
        manager.signForm(*robotomy);
        president.executeForm(*robotomy);
        
        delete robotomy;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    try {
        AForm* pardon = anonymousIntern.makeForm("presidential pardon", "Ford Prefect");
        std::cout << *pardon << std::endl;
        
        manager.signForm(*pardon);
        president.executeForm(*pardon);
        
        delete pardon;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Tentative de création d'un formulaire invalide ---" << std::endl;
    
    try {
        AForm* invalidForm = anonymousIntern.makeForm("form inexistant", "cible");
        std::cout << *invalidForm << std::endl; // Cette ligne ne devrait pas s'exécuter
        
        delete invalidForm;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Scénario de l'exemple du sujet ---" << std::endl;
    
    try {
        Intern someRandomIntern;
        AForm* rrf;
        
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *rrf << std::endl;
        
        president.signForm(*rrf);
        president.executeForm(*rrf);
        
        delete rrf;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}