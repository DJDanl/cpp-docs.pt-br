---
title: Instrução if-else (C++)
ms.date: 07/20/2019
description: Use as instruções if-else C++ no para controlar a ramificação condicional.
f1_keywords:
- else_cpp
- if_cpp
helpviewer_keywords:
- if keyword [C++]
- else keyword [C++]
ms.assetid: f8c45cde-6bce-42ae-81db-426b3dbd4caa
ms.openlocfilehash: fd2736d80d68249773c9aa6cf7cb9edffdaadac4
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80178425"
---
# <a name="if-else-statement-c"></a>Instrução if-else (C++)

Controla a ramificação condicional. As instruções em *If-Block* serão executadas somente se a *expressão If* for avaliada como um valor diferente de zero (ou true). Se o valor de *expression* for diferente de zero, *instrução1* e quaisquer outras instruções no bloco serão executadas e o else-Block, se presente, será ignorado. Se o valor de *expression* for zero, o If-Block será ignorado e o else-Block, se presente, será executado. Expressões que são avaliadas como não zero são

- TRUE
- um ponteiro não nulo,
- qualquer valor aritmético diferente de zero ou
- um tipo de classe que define uma conversão não ambígua para um tipo aritmético, booliano ou de ponteiro. (Para obter informações sobre conversões, consulte [conversões padrão](../cpp/standard-conversions.md).)

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

// C++17 - Visual Studio 2017 version 15.3 and later:
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

// C++17 - Visual Studio 2017 version 15.3 and later:
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

## <a name="if-statement-with-an-initializer"></a><a name="if_with_init"></a>instrução If com um inicializador

**Visual Studio 2017 versão 15,3 e posterior** (disponível com [/std: c++ 17](../build/reference/std-specify-language-standard-version.md)): uma instrução **If** também pode conter uma expressão que declara e Inicializa uma variável nomeada. Use essa forma da instrução If-quando a variável só for necessária dentro do escopo do bloco If.

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

Em todas as formas da instrução **If** , a *expressão*, que pode ter qualquer valor, exceto uma estrutura, é avaliada, incluindo todos os efeitos colaterais. O controle passa da instrução **If** para a próxima instrução no programa, a menos que um dos s da *instrução*contenha um [Break](../cpp/break-statement-cpp.md), [continue](../cpp/continue-statement-cpp.md)ou [goto](../cpp/goto-statement-cpp.md).

A cláusula **else** de uma instrução `if...else` é associada à instrução **If** anterior mais próxima no mesmo escopo que não tem uma instrução **else** correspondente.

## <a name="a-nameif_constexpr-if-constexpr-statements"></a><a name="if_constexpr"> se as instruções constexpr

**Visual Studio 2017 versão 15,3 e posterior** (disponível com [/std: c++ 17](../build/reference/std-specify-language-standard-version.md)): em modelos de função, você pode usar uma instrução **If constexpr** para tomar decisões de ramificação em tempo de compilação sem a necessidade de recorrer a várias sobrecargas de função. Por exemplo, você pode escrever uma única função que manipula o desempacotamento de parâmetro (nenhuma sobrecarga de parâmetro zero é necessária):

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

## <a name="see-also"></a>Confira também

[Instruções de seleção](../cpp/selection-statements-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Instrução switch (C++)](../cpp/switch-statement-cpp.md)
