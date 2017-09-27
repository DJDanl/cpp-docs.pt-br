---
title: "Instrução if-else (C++) | Microsoft Docs"
ms.custom: 
ms.date: 07/17/2017
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- else_cpp
- else
- if_cpp
- if
dev_langs:
- C++
helpviewer_keywords:
- if keyword [C++]
- else keyword [C++]
- if keyword [C++], if-else
ms.assetid: f8c45cde-6bce-42ae-81db-426b3dbd4caa
caps.latest.revision: 13
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 7f6d2a553e34b5f15e53fa142241af83d8e91255
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="if-else-statement-c"></a>Instrução if-else (C++)
Controla a ramificação condicional. Instruções o *blocos se* são executadas somente se o *expressão se* é avaliada como um valor diferente de zero (ou `true`). Se o valor de *expressão* é diferente de zero, *statement1* e quaisquer outras instruções no bloco são executadas e o outro bloco, se presente, será ignorado. Se o valor de *expressão* for zero, em seguida, o bloco se será ignorado e o outro bloco, se presente, é executado. São expressões avaliadas como diferente de zero
- `true`
- um ponteiro não null.
- qualquer valor de aritmética diferente de zero, ou 
- Digite um tipo de classe que define uma conversão ambígua em uma aritmética, booleano ou de ponteiro. (Para obter informações sobre as conversões, consulte [conversões padrão](../cpp/standard-conversions.md).)   
  
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
```  
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
**Visual Studio 2017 versão posterior e 15,3** (disponível com [/std:c + + 17](../build/reference/std-specify-language-standard-version.md)): um **se** instrução também pode conter uma expressão que declara e inicializa uma variável nomeada. Use este formulário da instrução if quando a variável é necessário apenas dentro do escopo do bloco if. 

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

 Em todos os formulários do **se** instrução, *expressão*, que pode ter qualquer valor, exceto uma estrutura, é avaliada, incluindo todos os efeitos de lado. Controle passa do **se** instrução para a próxima instrução no programa, a menos que uma da *instrução*s contém um [quebra](../cpp/break-statement-cpp.md), [continuar](../cpp/continue-statement-cpp.md), ou [goto](../cpp/goto-statement-cpp.md).  
  
 O **else** cláusula de um `if...else` instrução está associada com o mais próximo anterior **se** instrução no mesmo escopo que não tem um **else** instrução.   

## <a name="constexpr-if-statements"></a>constexpr se instruções
**Visual Studio 2017 versão posterior e 15,3** (disponível com [/std:c + + 17](../build/reference/std-specify-language-standard-version.md)): em modelos de função, você pode usar um **constexpr se** instrução para tomar decisões de ramificação de tempo de compilação sem precisar recorrer a várias sobrecargas de função. Por exemplo, você pode escrever uma única função esse parâmetro de identificadores desempacotar (nenhuma sobrecarga de parâmetro de zero é necessária): 

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
