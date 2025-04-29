/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:54:20 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/29 23:54:22 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "=== Test des formulaires ===" << std::endl;
    
    try {
        std::cout << "Création d'un formulaire standard: " << std::endl;
        Form form("Permis de construire", 50, 25);
        std::cout << form << std::endl;
        
        std::cout << "\nTest de la construction avec grade trop élevé: " << std::endl;
        Form formInvalid1("Trop élevé", 0, 25);
        std::cout << "Cette ligne ne devrait pas s'afficher" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "\nTest de la construction avec grade trop bas: " << std::endl;
        Form formInvalid2("Trop bas", 50, 151);
        std::cout << "Cette ligne ne devrait pas s'afficher" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test de la signature de formulaires ===" << std::endl;
    
    try {
        Form taxForm("Déclaration d'impôts", 100, 50);
        Bureaucrat bob("Bob", 120);
        Bureaucrat alice("Alice", 80);
        
        std::cout << "État initial du formulaire: " << std::endl;
        std::cout << taxForm << std::endl;
        
        std::cout << "\nTentative de signature par " << bob << " (grade insuffisant): " << std::endl;
        bob.signForm(taxForm);
        
        std::cout << "\nTentative de signature par " << alice << " (grade suffisant): " << std::endl;
        alice.signForm(taxForm);
        
        std::cout << "\nÉtat du formulaire après tentatives: " << std::endl;
        std::cout << taxForm << std::endl;
        
        std::cout << "\nNouvelle tentative de signature (déjà signé): " << std::endl;
        alice.signForm(taxForm);
    }
    catch (std::exception& e) {
        std::cout << "Exception inattendue: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test de copie de formulaire ===" << std::endl;
    Form original("Original", 75, 50);
    Bureaucrat chef("Chef", 1);
    chef.signForm(original);
    
    Form copie = original;
    std::cout << "Formulaire original: " << std::endl;
    std::cout << original << std::endl;
    std::cout << "\nFormulaire copié: " << std::endl;
    std::cout << copie << std::endl;
    
    return 0;
}