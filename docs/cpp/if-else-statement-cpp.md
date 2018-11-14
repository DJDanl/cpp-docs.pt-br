---
title: Instrução if-else (C++)
ms.date: 07/17/2017
f1_keywords:
- else_cpp
- if_cpp
helpviewer_keywords:
- if keyword [C++]
- else keyword [C++]
- if keyword [C++], if-else
ms.assetid: f8c45cde-6bce-42ae-81db-426b3dbd4caa
ms.openlocfilehash: 16aa65ab64d9fd855ae3306da88f8eb14eec759c
ms.sourcegitcommit: 1819bd2ff79fba7ec172504b9a34455c70c73f10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2018
ms.locfileid: "51330821"
---
# <a name="if-else-statement-c"></a>Instrução if-else (C++)

Controla a ramificação condicional. As instruções na *bloco if* são executados somente se o *expressão if* é avaliada como um valor diferente de zero (ou TRUE). Se o valor de *expressão* for diferente de zero *instrução1* e quaisquer outras instruções no bloco são executadas e o-bloco else, se presente, será ignorado. Se o valor de *expressão* for zero, em seguida, o bloco de if é ignorado e o-bloco else, se presente, é executado. São expressões que são avaliadas como diferente de zero

- TRUE
- um ponteiro não nulo,
- qualquer valor aritmético diferente de zero, ou
- tipo de um tipo de classe que define uma conversão inequívoca para uma aritmética, booliano ou ponteiro. (Para obter informações sobre conversões, consulte [conversões padrão](../cpp/standard-conversions.md).)

## <a name="syntax"></a>Sintaxe

```cpp
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
    void do_something(){}
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

## <a name="if_with_init"></a> Se a instrução com um inicializador

**Visual Studio 2017 versão 15.3 e posterior** (disponível com [/std: c + + 17](../build/reference/std-specify-language-standard-version.md)): uma **se** instrução também pode conter uma expressão que declara e inicializa uma variável nomeada. Use este formulário da instrução if quando a variável é necessária somente dentro do escopo do bloco if.

## <a name="example"></a>Exemplo

```cpp
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

## <a name="a-nameifconstexpr-if-constexpr-statements"></a><a name="if_constexpr"> Se as instruções de constexpr

**Visual Studio 2017 versão 15.3 e posterior** (disponível com [/std: c + + 17](../build/reference/std-specify-language-standard-version.md)): em modelos de função, você pode usar um **se constexpr** instrução para tomar decisões de ramificação de tempo de compilação sem precisar recorrer a várias sobrecargas de função. Por exemplo, você pode escrever uma única função esse parâmetro de identificadores desempacotar (nenhuma sobrecarga de parâmetro de zero é necessária):

```cpp
template <class T, class... Rest>
void f(T&& t, Rest&&... r)
{
    // handle t
    do_something(t);

    // handle r conditionally
    if constexpr (sizeof...(r))
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

[Instruções de seleção](../cpp/selection-statements-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Instrução switch (C++)](../cpp/switch-statement-cpp.md)