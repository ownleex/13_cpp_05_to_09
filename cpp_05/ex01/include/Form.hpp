/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:53:47 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/29 23:53:49 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat; // Déclaration anticipée

class Form {
private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    // Constructeurs et destructeur
    Form();
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& src);
    ~Form();
    
    // Opérateur d'affectation
    Form& operator=(const Form& rhs);
    
    // Getters
    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    
    // Fonction de signature
    void beSigned(const Bureaucrat& bureaucrat);
    
    // Classes d'exception
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

// Surcharge de l'opérateur de flux
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif