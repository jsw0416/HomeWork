#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <cctype>    


std::string trim(const std::string& s)
{
    size_t b = s.find_first_not_of(" \t\r\n");
    if (b == std::string::npos) return "";
    size_t e = s.find_last_not_of(" \t\r\n");
    return s.substr(b, e - b + 1);
}
std::string toLower(std::string s) 
{
    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return s;
}

class PotionRecipe
{
public:
    std::string potionName;
    std::vector<std::string> ingredients;

    PotionRecipe(const std::string& name, const std::vector<std::string>& ingredients)
        : potionName(name), ingredients(ingredients) { }
};

class AlchemyWorkshop 
{
private:
    std::vector<PotionRecipe> recipes;

    static void printRecipe(const PotionRecipe& r)
    {
        std::cout << "- 물약 이름: " << r.potionName << "\n  > 필요 재료: ";
        for (size_t i = 0; i < r.ingredients.size(); ++i) 
        {
            std::cout << r.ingredients[i];
            if (i + 1 < r.ingredients.size()) std::cout << ", ";
        }
        std::cout << "\n";
    }

public:
    void addRecipe(const std::string& name, const std::vector<std::string>& ingredients)
    {
        recipes.emplace_back(name, ingredients);
        std::cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다.\n";
    }

    void displayAllRecipes() const 
    {
        if (recipes.empty()) 
        {
            std::cout << "아직 등록된 레시피가 없습니다.\n";
            return;
        }
        std::cout << "\n--- [ 전체 레시피 목록 ] ---\n";
        for (const auto& r : recipes) printRecipe(r);
        std::cout << "---------------------------\n";
    }

    const PotionRecipe* searchRecipeByName(const std::string& name) const
    {
        std::string q = toLower(trim(name));
        for (const auto& r : recipes)
        {
            if (toLower(r.potionName) == q) return &r;
        }
        return nullptr;
    }

    std::vector<const PotionRecipe*> searchRecipesByIngredient(const std::string& ingredient) const
    {
        std::vector<const PotionRecipe*> result;
        std::string q = toLower(trim(ingredient));
        if (q.empty()) return result;

        for (const auto& r : recipes)
        {
            for (const auto& ing : r.ingredients)
            {
                if (toLower(ing) == q)
                {
                    result.push_back(&r);
                    break;
                }
            }
        }
        return result;
    }
};

int readInt(const std::string& prompt)
{
    while (true)
    {
        std::cout << prompt;
        int v;
        if (std::cin >> v) 
        {
            std::cin.ignore(10000, '\n');
            return v;
        }
        std::cout << "잘못된 입력입니다. 숫자를 입력해주세요.\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
}

int main() 
{
    AlchemyWorkshop myWorkshop;

    while (true)
    {
        std::cout << "\n⚗️ 연금술 공방 관리 시스템\n"
            << "1. 레시피 추가\n"
            << "2. 모든 레시피 출력\n"
            << "3. 물약 이름으로 검색\n"
            << "4. 재료로 검색\n"
            << "5. 종료\n"
            << "선택: ";

        int choice;
        if (!(std::cin >> choice))
        {
            std::cout << "잘못된 입력입니다. 숫자를 입력해주세요. \n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        std::cin.ignore(10000, '\n'); 

        if (choice == 1)
        {
            std::string name;
            std::cout << "물약 이름: ";
            std::getline(std::cin, name);
            name = trim(name);

            std::vector<std::string> ingredients_input;
            std::cout << "필요한 재료들을 입력하세요. (입력 완료 시 '끝' 입력)\n";
            while (true)
            {
                std::cout << "재료 입력: ";
                std::string ing;
                std::getline(std::cin, ing);
                ing = trim(ing);
                if (toLower(ing) == "끝") break;
                if (!ing.empty()) ingredients_input.push_back(ing);
            }

            if (!name.empty() && !ingredients_input.empty())
            {
                myWorkshop.addRecipe(name, ingredients_input);
            }
            else
            {
                std::cout << ">> 이름 또는 재료가 비어 있어 레시피 추가를 취소합니다.\n";
            }
        }
        else if (choice == 2)
        {
            myWorkshop.displayAllRecipes();
        }
        else if (choice == 3)
        { 
            std::cout << "검색할 물약 이름: ";
            std::string q; std::getline(std::cin, q);
            const PotionRecipe* found = myWorkshop.searchRecipeByName(q);
            if (found)
            {
                std::cout << "\n--- [ 검색 결과: 이름 ] ---\n";
                std::cout << "- 물약 이름: " << found->potionName << "\n  > 필요 재료: ";
                for (size_t i = 0; i < found->ingredients.size(); ++i)
                {
                    std::cout << found->ingredients[i];
                    if (i + 1 < found->ingredients.size()) std::cout << ", ";
                }
                std::cout << "\n---------------------------\n";
            }
            else 
            {
                std::cout << "해당 이름의 레시피를 찾을 수 없습니다.\n";
            }
        }
        else if (choice == 4)
        { 
            std::cout << "검색할 재료 이름: ";
            std::string q; std::getline(std::cin, q);
            auto results = myWorkshop.searchRecipesByIngredient(q);

            if (results.empty())
            {
                std::cout << "해당 재료를 포함하는 레시피가 없습니다.\n";
            }
            else 
            {
                std::cout << "\n--- [ 검색 결과: 재료 '" << trim(q) << "' ] ---\n";
                for (auto* r : results)
                {
                    std::cout << "- 물약 이름: " << r->potionName << "\n  > 필요 재료: ";
                    for (size_t i = 0; i < r->ingredients.size(); ++i)
                    {
                        std::cout << r->ingredients[i];
                        if (i + 1 < r->ingredients.size()) std::cout << ", ";
                    }
                    std::cout << "\n";
                }
                std::cout << "---------------------------\n";
            }
        }
        else if (choice == 5)
        {
            std::cout << "공방 문을 닫습니다...\n";
            break;
        }
        else
        {
            std::cout << "잘못된 선택입니다. 다시 시도하세요.\n";
        }
    }
    return 0;
}
