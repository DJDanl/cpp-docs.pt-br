---
title: instrução if-else (C++)
description: Use as instruções if-else, if-else com inicializador e If-constexpr para controlar a ramificação condicional.
ms.date: 10/02/2020
f1_keywords:
- else_cpp
- if_cpp
helpviewer_keywords:
- if keyword [C++]
- else keyword [C++]
ms.assetid: f8c45cde-6bce-42ae-81db-426b3dbd4caa
ms.openlocfilehash: 20d828bf00a79687fe0a9fffbeb1a9cc56fae08c
ms.sourcegitcommit: 30792632548d1c71894f9fecbe2f554294b86020
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/06/2020
ms.locfileid: "91765293"
---
# <a name="if-else-statement-c"></a>instrução if-else (C++)

Uma instrução if-else controla a ramificação condicional. As instruções no *`if-branch`* serão executadas somente se o *`condition`* for avaliado como um valor diferente de zero (ou **`true`** ). Se o valor de *`condition`* for diferente de zero, a instrução a seguir será executada e a instrução após o opcional **`else`** será ignorada. Caso contrário, a instrução a seguir será ignorada e, se houver **`else`** , a instrução após a **`else`** execução será executada.

*`condition`* expressões que são avaliadas como diferentes de zero são:

- **`true`**
- um ponteiro não nulo,
- qualquer valor aritmético diferente de zero ou
- um tipo de classe que define uma conversão não ambígua para um tipo aritmético, booliano ou de ponteiro. (Para obter informações sobre conversões, consulte [conversões padrão](../cpp/standard-conversions.md).)

## <a name="syntax"></a>Sintaxe

*`init-statement`*:\
&emsp; *`expression-statement`*\
&emsp; *`simple-declaration`*

*`condition`*:\
&emsp; *`expression`*\
&emsp;*`attribute-specifier-seq`* <sub>*opt*</sub> *`decl-specifier-seq`* aceitar *`declarator`**`brace-or-equal-initializer`*

*`statement`*:\
&emsp; *`expression-statement`*\
&emsp; *`compound-statement`*

*`expression-statement`*:\
&emsp;*`expression`* <sub>*aceitar*</sub>**`;`**

*`compound-statement`*:\
&emsp;**`{`** *`statement-seq`* <sub>*aceitar*</sub>**`}`**

*`statement-seq`*:\
&emsp; *`statement`*\
&emsp; *`statement-seq`* *`statement`*

*`if-branch`*:\
&emsp; *`statement`*

*`else-branch`*:\
&emsp; *`statement`*

*`selection-statement`*:\
&emsp;**`if`** aceitar 17 **`constexpr`** <sub>*opt*</sub><sup>17</sup> **`(`** *`init-statement`* <sub>*opt*</sub><sup>17</sup> de 17 *`condition`* **`)`***`if-branch`*\
&emsp;**`if`** aceitar 17 **`constexpr`** <sub>*opt*</sub><sup>17</sup> **`(`** *`init-statement`* <sub>*opt*</sub><sup>17</sup> de 17 *`condition`* **`)`** *`if-branch`* **`else`***`else-branch`*

<sup>17</sup> este elemento opcional está disponível a partir de c++ 17.

## <a name="if-else-statements"></a>instruções if-else

Em todos os formulários da **`if`** instrução, *`condition`* , que pode ter qualquer valor, exceto uma estrutura, é avaliado, incluindo todos os efeitos colaterais. O controle passa da **`if`** instrução para a próxima instrução no programa, a menos que seja executado *`if-branch`* ou *`else-branch`* contenha um [`break`](../cpp/break-statement-cpp.md) , [`continue`](../cpp/continue-statement-cpp.md) ou [`goto`](../cpp/goto-statement-cpp.md) .

A **`else`** cláusula de uma `if...else` instrução é associada à instrução anterior mais próxima **`if`** no mesmo escopo que não tem uma **`else`** instrução correspondente.

### <a name="example"></a>Exemplo

Este código de exemplo mostra várias **`if`** instruções em uso, com e sem **`else`** :

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

## <a name="if-statement-with-an-initializer"></a><a name="if_with_init"></a> instrução If com um inicializador

A partir do C++ 17, uma **`if`** instrução também pode conter uma *`init-statement`* expressão que declara e Inicializa uma variável nomeada. Use essa forma da instrução If-quando a variável só for necessária dentro do escopo da instrução If-. **Específico da Microsoft**: esse formulário está disponível a partir do Visual Studio 2017 versão 15,3 e requer pelo menos a [`/std:c++17`](../build/reference/std-specify-language-standard-version.md) opção de compilador.

### <a name="example"></a>Exemplo

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

## <a name="a-nameif_constexpr-if-constexpr-statements"></a><a name="if_constexpr"> instruções constexpr If

A partir do C++ 17, você pode usar uma **`if constexpr`** instrução em modelos de função para tomar decisões de ramificação em tempo de compilação sem a necessidade de recorrer a várias sobrecargas de função. **Específico da Microsoft**: esse formulário está disponível a partir do Visual Studio 2017 versão 15,3 e requer pelo menos a [`/std:c++17`](../build/reference/std-specify-language-standard-version.md) opção de compilador.

### <a name="example"></a>Exemplo

Este exemplo mostra como você pode escrever uma única função que manipula o desempacotamento de parâmetro. Nenhuma sobrecarga de parâmetro zero é necessária:

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

[Instruções de seleção](../cpp/selection-statements-cpp.md)\
[Palavras-chave](../cpp/keywords-cpp.md)\
[`switch` Instrução (C++)](../cpp/switch-statement-cpp.md)
