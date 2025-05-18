/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:15:16 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/05/15 20:11:52 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    std::cout << "=== Test des formulaires concrets ===" << std::endl;
    
    // Création des bureaucrates avec différents grades
    Bureaucrat Apprenti("Apprenti", 150);
    Bureaucrat employe("Employé", 100);
    Bureaucrat manager("Manager", 50);
    Bureaucrat directeur("Directeur", 25);
    Bureaucrat president("Président", 1);
    
    std::cout << "\n=== Test du formulaire ShrubberyCreationForm ===" << std::endl;
    try {
        ShrubberyCreationForm shrubberyForm("jardin");
        std::cout << shrubberyForm << std::endl;
        
        std::cout << "\nTentative de signature par un Apprenti (grade 150): " << std::endl;
        Apprenti.signForm(shrubberyForm);
        
        std::cout << "\nTentative de signature par un employé (grade 100): " << std::endl;
        employe.signForm(shrubberyForm);
        
        std::cout << "\nTentative d'exécution par un Apprenti: " << std::endl;
        Apprenti.executeForm(shrubberyForm);
        
        std::cout << "\nTentative d'exécution par un employé: " << std::endl;
        employe.executeForm(shrubberyForm);
    }
    catch (std::exception& e) {
        std::cout << "Exception inattendue: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test du formulaire RobotomyRequestForm ===" << std::endl;
    try {
        RobotomyRequestForm robotomyForm("Bender");
        std::cout << robotomyForm << std::endl;
        
        std::cout << "\nTentative de signature par un employé (grade 100): " << std::endl;
        employe.signForm(robotomyForm);
        
        std::cout << "\nTentative de signature par un manager (grade 50): " << std::endl;
        manager.signForm(robotomyForm);

        std::cout << "\nTentative de signature par un president (grade 1): " << std::endl;
        president.signForm(robotomyForm);
        
        std::cout << "\nTentative d'exécution par un employé: " << std::endl;
        employe.executeForm(robotomyForm);
        
        std::cout << "\nTentative d'exécution par un manager: " << std::endl;
        manager.executeForm(robotomyForm);

        std::cout << "\nTentative d'exécution par un president: " << std::endl;
        president.executeForm(robotomyForm);
    }
    catch (std::exception& e) {
        std::cout << "Exception inattendue: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test du formulaire PresidentialPardonForm ===" << std::endl;
    try {
        PresidentialPardonForm pardonForm("Arthur Dent");
        std::cout << pardonForm << std::endl;
        
        std::cout << "\nTentative de signature par un manager (grade 50): " << std::endl;
        manager.signForm(pardonForm);
        
        std::cout << "\nTentative de signature par un directeur (grade 25): " << std::endl;
        directeur.signForm(pardonForm);
        
        std::cout << "\nTentative d'exécution par un directeur: " << std::endl;
        directeur.executeForm(pardonForm);
        
        std::cout << "\nTentative d'exécution par un président: " << std::endl;
        president.executeForm(pardonForm);
    }
    catch (std::exception& e) {
        std::cout << "Exception inattendue: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test d'exécution d'un formulaire non signé ===" << std::endl;
    try {
        PresidentialPardonForm nonSignedForm("Marvin");
        std::cout << nonSignedForm << std::endl;
        
        std::cout << "\nTentative d'exécution par le président: " << std::endl;
        president.executeForm(nonSignedForm);
    }
    catch (std::exception& e) {
        std::cout << "Exception inattendue: " << e.what() << std::endl;
    }
    
    return 0;
}