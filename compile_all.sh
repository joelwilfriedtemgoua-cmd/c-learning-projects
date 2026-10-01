#!/bin/bash

# 🔨 SCRIPT DE COMPILATION AUTOMATIQUE
# Compile tous les programmes C du repo

# Couleurs
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# Compteurs
compiled=0
failed=0
total=0

echo -e "${BLUE}╔═════════════════════════════════════════════╗${NC}"
echo -e "${BLUE}║  🔨 COMPILATION AUTOMATIQUE DE TOUS LES    ║${NC}"
echo -e "${BLUE}║     PROGRAMMES C                           ║${NC}"
echo -e "${BLUE}╚═════════════════════════════════════════════╝${NC}"
echo ""

# Fonction pour compiler un fichier .c
compile_file() {
    local file=$1
    local dir=$(dirname "$file")
    local filename=$(basename "$file" .c)
    local output="$dir/$filename"
    
    total=$((total + 1))
    
    echo -ne "${CYAN}[${total}]${NC} Compilation: $(basename "$file")... "
    
    if gcc "$file" -o "$output" 2>/dev/null; then
        echo -e "${GREEN}✓${NC}"
        compiled=$((compiled + 1))
    else
        echo -e "${RED}✗${NC}"
        failed=$((failed + 1))
        # Essayer avec pkg-config pour GTK4
        if gcc "$file" -o "$output" $(pkg-config --cflags --libs gtk4) 2>/dev/null; then
            echo -e "         ${GREEN}✓ (avec GTK4)${NC}"
            compiled=$((compiled + 1))
            failed=$((failed - 1))
        fi
    fi
}

# 1️⃣ CONSOLE PROGRAMS - BASICS
echo -e "${YELLOW}📂 console-programs/basics/${NC}"
for file in console-programs/basics/*.c; do
    if [ -f "$file" ]; then
        compile_file "$file"
    fi
done

echo ""

# 2️⃣ CONSOLE PROGRAMS - MATH
echo -e "${YELLOW}📂 console-programs/math/${NC}"
for file in console-programs/math/*.c; do
    if [ -f "$file" ]; then
        compile_file "$file"
    fi
done

echo ""

# 3️⃣ CONSOLE PROGRAMS - STRING
echo -e "${YELLOW}📂 console-programs/string/${NC}"
for file in console-programs/string/*.c; do
    if [ -f "$file" ]; then
        compile_file "$file"
    fi
done

echo ""

# 4️⃣ CONSOLE PROGRAMS - CONVERSION
echo -e "${YELLOW}📂 console-programs/conversion/${NC}"
for file in console-programs/conversion/*.c; do
    if [ -f "$file" ]; then
        compile_file "$file"
    fi
done

echo ""

# 5️⃣ CONSOLE PROGRAMS - ARRAYS
echo -e "${YELLOW}📂 console-programs/arrays/${NC}"
for file in console-programs/arrays/*.c; do
    if [ -f "$file" ]; then
        compile_file "$file"
    fi
done

echo ""

# 6️⃣ CONSOLE PROGRAMS - UTILITIES
echo -e "${YELLOW}📂 console-programs/utilities/${NC}"
for file in console-programs/utilities/*.c; do
    if [ -f "$file" ]; then
        compile_file "$file"
    fi
done

echo ""

# 7️⃣ CALCULATOR GTK4
echo -e "${YELLOW}📂 calculator-gtk4/${NC}"
if [ -d "calculator-gtk4" ] && [ -f "calculator-gtk4/Makefile" ]; then
    echo -ne "${CYAN}[${total}]${NC} Compilation: calculatrice GTK4... "
    total=$((total + 1))
    if cd calculator-gtk4 && make >/dev/null 2>&1; then
        echo -e "${GREEN}✓${NC}"
        compiled=$((compiled + 1))
        cd ..
    else
        echo -e "${RED}✗${NC}"
        failed=$((failed + 1))
        cd ..
    fi
    echo ""
fi

# 8️⃣ TODO APP GTK4 (quand il sera créé)
if [ -d "todo-app-gtk4" ] && [ -f "todo-app-gtk4/Makefile" ]; then
    echo -e "${YELLOW}📂 todo-app-gtk4/${NC}"
    echo -ne "${CYAN}[${total}]${NC} Compilation: todo-app GTK4... "
    total=$((total + 1))
    if cd todo-app-gtk4 && make >/dev/null 2>&1; then
        echo -e "${GREEN}✓${NC}"
        compiled=$((compiled + 1))
        cd ..
    else
        echo -e "${RED}✗${NC}"
        failed=$((failed + 1))
        cd ..
    fi
    echo ""
fi

# 📊 RÉSUMÉ
echo ""
echo -e "${BLUE}╔═════════════════════════════════════════════╗${NC}"
echo -e "${BLUE}║  📊 RÉSUMÉ DE COMPILATION                  ║${NC}"
echo -e "${BLUE}╚═════════════════════════════════════════════╝${NC}"
echo ""
echo -e "  Total        : ${CYAN}${total}${NC} fichiers"
echo -e "  Réussis      : ${GREEN}${compiled}${NC} ✓"
echo -e "  Échoués      : ${RED}${failed}${NC} ✗"
echo ""

if [ $failed -eq 0 ]; then
    echo -e "${GREEN}✅ TOUS LES PROGRAMMES COMPILÉS AVEC SUCCÈS !${NC}"
else
    echo -e "${YELLOW}⚠️  ${failed} programme(s) n'ont pas pu être compilé(s)${NC}"
    echo -e "   Vérifiez les dépendances (GTK4, etc.)"
fi

echo ""

# 🚀 AFFICHER COMMENT EXÉCUTER
echo -e "${BLUE}╔═════════════════════════════════════════════╗${NC}"
echo -e "${BLUE}║  🚀 COMMENT EXÉCUTER LES PROGRAMMES        ║${NC}"
echo -e "${BLUE}╚═════════════════════════════════════════════╝${NC}"
echo ""
echo -e "${CYAN}Exemples :${NC}"
echo ""
echo -e "  ${GREEN}To-Do List Console :${NC}"
echo "    ./console-programs/utilities/todo"
echo ""
echo -e "  ${GREEN}Calculatrice :${NC}"
echo "    ./console-programs/basics/calculatrice"
echo ""
echo -e "  ${GREEN}Calcul IMC :${NC}"
echo "    ./console-programs/basics/imc"
echo ""
echo -e "  ${GREEN}Tous les programmes basics :${NC}"
echo "    ls console-programs/basics/ | grep -v '.c'"
echo ""
echo -e "  ${GREEN}Exécuter directement :${NC}"
echo "    ./console-programs/basics/hello"
echo "    ./console-programs/basics/age"
echo "    ./console-programs/basics/factoriel"
echo ""

# 💡 BONUS: Créer un script de menu interactif
echo -e "${BLUE}╔═════════════════════════════════════════════╗${NC}"
echo -e "${BLUE}║  💡 BONUS: Script de menu interactif        ║${NC}"
echo -e "${BLUE}╚═════════════════════════════════════════════╝${NC}"
echo ""
echo -e "  Si tu veux un menu pour choisir les programmes :"
echo "    ${CYAN}./run_program.sh${NC}"
echo ""
echo -e "  Crée-le avec :"
echo "    ${CYAN}touch run_program.sh && chmod +x run_program.sh${NC}"
echo ""
