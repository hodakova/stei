public class Calculator {
    public Calculator() { };

    public double calculate(double a, double b, char operation)
            throws InvalidOperationException, InvalidDivisionException {
        /**
         * Implementasi
         * Apabila operasi yang dimasukkan pengguna bukan `+`, `-`, `*`, atau `/`, maka
         * kalkulator akan mengembalikan pesan error dari kelas
         * `InvalidOperationException` dengan pesan `Invalid Operation: <operasi yang dimasukan>`
         * 
         * Apabila kalkulator menerima masukan pembagian terhadap 0, maka kalkulator
         * akan mengembalikan pesan error dari kelas `InvalidDivisionException`
         * dengan pesan `Invalid Division: Tidak dapat melakukan pembagian terhadap 0!`
         */
        if(operation == '+') { 
            return a + b;
        }
        else if(operation == '-') { 
            return a - b;
        }
        else if(operation == '*') { 
            return a * b;
        } 
        else if(operation == '/') { 
            if (b == 0) {
                throw new InvalidDivisionException();
            }
            else {
                return a / b;
            }
        }
        else {
            throw new InvalidOperationException(operation);
        }
    }
}

/**
 * Implementasikan:
 * 1. Calculator Exception
 * 2. InvalidOperationException
 * 3. InvalidDivisionException
 */
class CalculatorException extends Exception {}

class InvalidOperationException extends CalculatorException {
    public char operation;
    public InvalidOperationException(char operation) {
        this.operation = operation;
    }
    public String getMessage() {
        return "Invalid Operation: " + operation;
    }
}

class InvalidDivisionException extends CalculatorException {
    public InvalidDivisionException() {}
    public String getMessage() {
        return "Invalid Division: Tidak dapat melakukan pembagian terhadap 0!";
    }
}