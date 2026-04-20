#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default_Form"), _isSigned(false), _signGrade(150), _execGrade(150)
{
}

// Validate grades during construction and throw exceptions if they are out of bounds
Form::Form(const std::string& name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) 
{
    if (_signGrade < 1 || _execGrade < 1)
        throw GradeTooHighException();
    if (_signGrade > 150 || _execGrade > 150)
        throw GradeTooLowException();
}

// Copy constructor and assignment operator only copy the _isSigned status, 
// as _name, _signGrade, and _execGrade are const
Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned),
      _signGrade(other._signGrade), _execGrade(other._execGrade)
{
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

Form::~Form()
{
}

const std::string& Form::getName() const
{
    return _name;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}

int Form::getSignGrade() const
{
    return _signGrade;
}

int Form::getExecGrade() const
{
    return _execGrade;
}

// Allows a Bureaucrat to sign the form if their grade is sufficient
void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "grade too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << form.getName()
        << ", signed: " << (form.getIsSigned() ? "yes" : "no")
        << ", sign grade " << form.getSignGrade()
        << ", exec grade " << form.getExecGrade() << ".";
    return os;
}
