---
title: Instrução if-else (C++) | Microsoft Docs
ms.custom: ''
ms.date: 07/17/2017
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- else_cpp
- if_cpp
dev_langs:
- C++
helpviewer_keywords:
- if keyword [C++]
- else keyword [C++]
- if keyword [C++], if-else
ms.assetid: f8c45cde-6bce-42ae-81db-426b3dbd4caa
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 15748249a39813edc4446fa25511d20361b0706c
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39405104"
---
# <a name="if-else-statement-c"></a>Instrução if-else (C++)
Controla a ramificação condicional. As instruções na *bloco if* são executados somente se o *expressão if* é avaliada como um valor diferente de zero (ou TRUE). Se o valor de *expressão* for diferente de zero *instrução1* e quaisquer outras instruções no bloco são executadas e o-bloco else, se presente, será ignorado. Se o valor de *expressão* for zero, em seguida, o bloco de if é ignorado e o-bloco else, se presente, é executado. São expressões que são avaliadas como diferente de zero
- TRUE
- um ponteiro não nulo,
- qualquer valor aritmético diferente de zero, ou 
- tipo de um tipo de classe que define uma conversão inequívoca para uma aritmética, booliano ou ponteiro. (Para obter informações sobre conversões, consulte [conversões padrão](../cpp/standard-conversions.md).)   
  
## <a name="syntax"></a>Sintaxe  
  
```  
if ( expression )  
{
   statement1;
   ...  
}
else  // optional
{
   statement2;
   ...
} 

// Visual Studio 2017 version 15.3 and later:
if ( initialization; expression )  
{
   statement1;
   ...  
}
else  // optional
{
   statement2;
   ...
}  

// Visual Studio 2017 version 15.3 and later:
if constexpr (expression)
{
    statement1;
    ...
}
else  // optional
{
   statement2;
   ...
} 
```  

## <a name="example"></a>Exemplo  

```cpp  
// if_else_statement.cpp  
#include <iostream>

using namespace std;

class C
{
    public:
    void do_somthing(){}
};
void init(C){}
bool is_true() { return true; }
int x = 10;

int main()
{
    if (is_true())
    {
        cout << "b is true!\n";  // executed
    }
    else
    {
        cout << "b is false!\n";
    }

  // no else statement
    if (x == 10)
    {
        x = 0; 
    }
    
  
    C* c;
  init(c);
    if (c)
    {
        c->do_something();
    }
    else
    {
        cout << "c is null!\n";
    }
}
```  
## <a name="if-statement-with-an-initializer"></a>Se a instrução com um inicializador
**Visual Studio 2017 versão 15.3 e posterior** (disponível com [/std: c + + 17](../build/reference/std-specify-language-standard-version.md)): uma **se** instrução também pode conter uma expressão que declara e inicializa uma variável nomeada. Use este formulário da instrução if quando a variável é necessária somente dentro do escopo do bloco if. 

```cpp
## Example  
#include <iostream>
#include <mutex>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

map<int, string> m;
mutex mx;
bool shared_flag; // guarded by mx
void unsafe_operation() {}

int main()
{

    if (auto it = m.find(10); it != m.end())
    {
        cout << it->second;
        return 0;
    }

    if (char buf[10]; fgets(buf, 10, stdin))
    {
        m[0] += buf;
    }

    if (lock_guard<mutex> lock(mx); shared_flag)
    {
        unsafe_operation();
        shared_flag = false;
    }

    string s{ "if" };
    if (auto keywords = { "if", "for", "while" }; any_of(keywords.begin(), keywords.end(), [&s](const char* kw) { return s == kw; }))
    {
        cout << "Error! Token must not be a keyword\n";
    }
}
```

 Em todas as formas dos **se** instrução *expressão*, que pode ter qualquer valor exceto uma estrutura, é avaliada, inclusive todos os efeitos colaterais. Controle passa do **se** instrução para a próxima instrução no programa, a menos que um dos *instrução*s contém um [quebra](../cpp/break-statement-cpp.md), [continuar](../cpp/continue-statement-cpp.md), ou [goto](../cpp/goto-statement-cpp.md).  
  
 O **else** cláusula de uma `if...else` instrução está associada com o mais próximo anterior **se** instrução no mesmo escopo que não tem um correspondente **else** instrução.   

## <a name="constexpr-if-statements"></a>constexpr se instruções
**Visual Studio 2017 versão 15.3 e posterior** (disponível com [/std: c + + 17](../build/reference/std-specify-language-standard-version.md)): em modelos de função, você pode usar um `constexpr if` instrução para tomar decisões de ramificação de tempo de compilação sem precisar recorrer a vários sobrecargas de função. Por exemplo, você pode escrever uma única função esse parâmetro de identificadores desempacotar (nenhuma sobrecarga de parâmetro de zero é necessária): 

```cpp
template <class T, class... Rest>
void f(T&& t, Rest&&... r)
{
// handle t
   do_something(t);

   // handle r conditionally
   constexpr if (sizeof...(r)) 
   {
      
      f(r...); 
   }
   else
   {
       g(r...);
   }
}
```

## <a name="see-also"></a>Consulte também  
 [Instruções de seleção](../cpp/selection-statements-cpp.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [Instrução switch (C++)](../cpp/switch-statement-cpp.md)