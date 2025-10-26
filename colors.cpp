#include <iostream>
#include <string>

/*
 * ANSI Color Codes - Direct usage without extra includes
 * These work on Linux, macOS, and Windows 10+ terminals
 */

int main() {
    // ========== BASIC COLORS ==========
    
    // Text Colors
    std::cout << "\033[31m" << "Red text" << "\033[0m" << std::endl;
    std::cout << "\033[32m" << "Green text" << "\033[0m" << std::endl;
    std::cout << "\033[33m" << "Yellow text" << "\033[0m" << std::endl;
    std::cout << "\033[34m" << "Blue text" << "\033[0m" << std::endl;
    std::cout << "\033[35m" << "Magenta text" << "\033[0m" << std::endl;
    std::cout << "\033[36m" << "Cyan text" << "\033[0m" << std::endl;
    std::cout << "\033[37m" << "White text" << "\033[0m" << std::endl;
    
    std::cout << std::endl;
    
    // ========== BRIGHT COLORS ==========
    
    std::cout << "\033[91m" << "Bright Red" << "\033[0m" << std::endl;
    std::cout << "\033[92m" << "Bright Green" << "\033[0m" << std::endl;
    std::cout << "\033[93m" << "Bright Yellow" << "\033[0m" << std::endl;
    std::cout << "\033[94m" << "Bright Blue" << "\033[0m" << std::endl;
    std::cout << "\033[95m" << "Bright Magenta" << "\033[0m" << std::endl;
    std::cout << "\033[96m" << "Bright Cyan" << "\033[0m" << std::endl;
    
    std::cout << std::endl;
    
    // ========== TEXT STYLES ==========
    
    std::cout << "\033[1m" << "Bold text" << "\033[0m" << std::endl;
    std::cout << "\033[4m" << "Underlined text" << "\033[0m" << std::endl;
    std::cout << "\033[7m" << "Reversed/Inverted" << "\033[0m" << std::endl;
    
    std::cout << std::endl;
    
    // ========== COMBINED STYLES ==========
    
    std::cout << "\033[1;31m" << "Bold Red" << "\033[0m" << std::endl;
    std::cout << "\033[1;32m" << "Bold Green" << "\033[0m" << std::endl;
    std::cout << "\033[4;34m" << "Underlined Blue" << "\033[0m" << std::endl;
    std::cout << "\033[1;4;33m" << "Bold Underlined Yellow" << "\033[0m" << std::endl;
    
    std::cout << std::endl;
    
    // ========== BACKGROUND COLORS ==========
    
    std::cout << "\033[41m" << "Red background" << "\033[0m" << std::endl;
    std::cout << "\033[42m" << "Green background" << "\033[0m" << std::endl;
    std::cout << "\033[43m" << "Yellow background" << "\033[0m" << std::endl;
    std::cout << "\033[44m" << "Blue background" << "\033[0m" << std::endl;
    std::cout << "\033[45m" << "Magenta background" << "\033[0m" << std::endl;
    std::cout << "\033[46m" << "Cyan background" << "\033[0m" << std::endl;
    
    std::cout << std::endl;
    
    // ========== TEXT + BACKGROUND ==========
    
    std::cout << "\033[1;37;41m" << " Bold White on Red " << "\033[0m" << std::endl;
    std::cout << "\033[1;30;42m" << " Bold Black on Green " << "\033[0m" << std::endl;
    std::cout << "\033[1;37;44m" << " Bold White on Blue " << "\033[0m" << std::endl;
    
    return 0;
}

/*
 * ========== ANSI COLOR CODES REFERENCE ==========
 * 
 * Format: \033[CODEm
 * 
 * RESET:
 * \033[0m  - Reset all attributes
 * 
 * TEXT COLORS (30-37):
 * \033[30m - Black
 * \033[31m - Red
 * \033[32m - Green
 * \033[33m - Yellow
 * \033[34m - Blue
 * \033[35m - Magenta
 * \033[36m - Cyan
 * \033[37m - White
 * 
 * BRIGHT TEXT COLORS (90-97):
 * \033[90m - Bright Black (Gray)
 * \033[91m - Bright Red
 * \033[92m - Bright Green
 * \033[93m - Bright Yellow
 * \033[94m - Bright Blue
 * \033[95m - Bright Magenta
 * \033[96m - Bright Cyan
 * \033[97m - Bright White
 * 
 * BACKGROUND COLORS (40-47):
 * \033[40m - Black background
 * \033[41m - Red background
 * \033[42m - Green background
 * \033[43m - Yellow background
 * \033[44m - Blue background
 * \033[45m - Magenta background
 * \033[46m - Cyan background
 * \033[47m - White background
 * 
 * BRIGHT BACKGROUND COLORS (100-107):
 * \033[100m - Bright Black background
 * \033[101m - Bright Red background
 * \033[102m - Bright Green background
 * \033[103m - Bright Yellow background
 * \033[104m - Bright Blue background
 * \033[105m - Bright Magenta background
 * \033[106m - Bright Cyan background
 * \033[107m - Bright White background
 * 
 * TEXT STYLES:
 * \033[1m - Bold
 * \033[2m - Dim
 * \033[3m - Italic (not widely supported)
 * \033[4m - Underline
 * \033[5m - Blinking (not widely supported)
 * \033[7m - Reverse/Invert colors
 * \033[8m - Hidden (not widely supported)
 * \033[9m - Strikethrough (not widely supported)
 * 
 * COMBINING CODES:
 * \033[1;31m - Bold Red
 * \033[4;32m - Underlined Green
 * \033[1;4;33m - Bold Underlined Yellow
 * \033[1;37;41m - Bold White text on Red background
 * 
 * IMPORTANT: Always reset with \033[0m after colored text!
 */