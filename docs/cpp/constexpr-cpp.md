---
title: constexpr C
description: Guia para a constexpr palavra-chave da linguagem C++.
ms.date: 01/28/2020
f1_keywords:
- constexpr_cpp
ms.assetid: c6458ccb-51c6-4a16-aa61-f69e6f4e04f7
no-loc:
- constexpr
- const
- inline
- goto
- try
- if
- switch
- for
- while
ms.openlocfilehash: 57ebf4bf69c768bfcd2e4d26a5c3334ca788b08f
ms.sourcegitcommit: a6b97f5d78299ad93675de2fe0f0561f528d26c7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/15/2020
ms.locfileid: "90569560"
---
# <a name="no-locconstexpr-c"></a>constexpr C

A palavra-chave **`constexpr`** foi introduzida no c++ 11 e aprimorada no c++ 14. Significa * const expressão Ant*. Como **`const`** , ele pode ser aplicado a variáveis: um erro do compilador é gerado quando qualquer código tenta obter if o valor de mod y. Ao contrário **`const`** de, **`constexpr`** também pode ser aplicado a funções e à classe const ructors. **`constexpr`** indica que o valor, ou valor de retorno, é const Ant e, quando possível, é calculado no momento da compilação.

Um **`constexpr`** valor integral pode ser usado sempre const que um inteiro é necessário, como em argumentos de modelo e declarações de matriz. E quando um valor é calculado em tempo de compilação em vez de tempo de execução, ele ajuda o programa a ser executado mais rapidamente e usa menos memória.

Para limitar a complexidade de cálculos de Ant em tempo de compilação const e seus possíveis impactos no tempo de compilação, o padrão c++ 14 exige que os tipos em const expressões de Ant sejam [tipos literais](trivial-standard-layout-and-pod-types.md#literal_types).

## <a name="syntax"></a>Syntax

> **`constexpr`***tipo literal* *ident if Ier* **=** * const Ant-Expression* **;**\
> **`constexpr`***tipo literal* *ident if Ier* **{** * const Ant-Expression* **}** **;**\
> **`constexpr`***tipo literal* *ident if Ier* **(** *params* **)** **;**\
> **`constexpr`***ctor* **(** *params* **)** **;**

## <a name="parameters"></a>Parâmetros

*params*\
Um ou mais parâmetros, cada um deles deve ser um tipo literal e, por sua vez, deve ser uma const expressão Ant.

## <a name="return-value"></a>Valor retornado

Uma **`constexpr`** variável ou função deve retornar um [tipo literal](trivial-standard-layout-and-pod-types.md#literal_types).

## <a name="no-locconstexpr-variables"></a>Variáveis constexpr

A if ferência de d principal entre **`const`** e **`constexpr`** variáveis é que a inicialização de uma **`const`** variável pode ser adiada até o tempo de execução. Uma **`constexpr`** variável deve ser inicializada em tempo de compilação.  Todas as **`constexpr`** variáveis são **`const`** .

- Uma variável pode ser declarada com **`constexpr`** , quando tem um tipo literal e é inicializada. Se a inicialização for por for med por um const ructor, o const ructor deverá ser declarado como **`constexpr`** .

- Uma referência pode ser declarada como **`constexpr`** quando ambas as condições são atendidas: o objeto referenciado é inicializado por uma const expressão Ant e todas as conversões implícitas invocadas durante a inicialização também são const expressões de Ant.

- Todas as declarações de uma **`constexpr`** variável ou função devem ter a **`constexpr`** especificação if Ier.

```cpp
constexpr float x = 42.0;
constexpr float y{108};
constexpr float z = exp(5, 3);
constexpr int i; // Error! Not initialized
int j = 0;
constexpr int k = j + 1; //Error! j not a constant expression
```

## <a name="no-locconstexpr-functions"></a><a name="constexpr_functions"></a>constexprfunções do

Uma **`constexpr`** função é aquela cujo valor de retorno é computáveis no momento da compilação quando o código de consumo exigir. O consumo de código requer o valor de retorno no momento da compilação para inicializar uma **`constexpr`** variável ou para fornecer um argumento de modelo sem tipo. Quando seus argumentos são **`constexpr`** valores, uma **`constexpr`** função produz um Ant em tempo de compilação const . Quando chamado com não **`constexpr`** argumentos, ou quando seu valor não é necessário no momento da compilação, ele produz um valor em tempo de execução como uma função regular. (Esse comportamento duplo evita que você precise escrever **`constexpr`** e não **`constexpr`** versões da mesma função.)

Uma **`constexpr`** função ou const ructor é implicitamente **`inline`** .

As regras a seguir se aplicam a constexpr funções do:

- Uma **`constexpr`** função deve aceitar e retornar apenas [tipos literais](trivial-standard-layout-and-pod-types.md#literal_types).

- Uma **`constexpr`** função pode ser recursiva.

- Não pode ser [virtual](../cpp/virtual-cpp.md). Um const ructor não pode ser definido como **`constexpr`** quando a classe delimitadora tem quaisquer classes base virtuais.

- O corpo pode ser definido como `= default` ou `= delete` .

- O corpo não pode conter **`goto`** instruções ou **`try`** blocos.

- Uma especialização explícita de um não **`constexpr`** modelo pode ser declarada como **`constexpr`** :

- Uma especialização explícita de um **`constexpr`** modelo também não precisa ser **`constexpr`** :

As regras a seguir se aplicam a **`constexpr`** funções no Visual Studio 2017 e posteriores:

- Ele pode conter **`if`** instruções and e **`switch`** todas as instruções de looping, incluindo **`for`** com base em intervalo **`for`** , **`while`** e **do while -**.

- Ele pode conter declarações de variáveis locais, mas a variável deve ser inicializada. Ele deve ser um tipo literal e não pode ser **`static`** ou thread-local. A variável declarada localmente não deve ser **`const`** e pode ser mutada.

- Uma **`constexpr`** função não **`static`** membro não precisa ser implicitamente **`const`** .

```cpp
constexpr float exp(float x, int n)
{
    return n == 0 ? 1 :
        n % 2 == 0 ? exp(x * x, n / 2) :
        exp(x * x, (n - 1) / 2) * x;
}
```

> [!TIP]
> No depurador do Visual Studio, ao depurar uma compilação de depuração não otimizada, você pode saber se uma **`constexpr`** função está sendo avaliada em tempo de compilação, colocando um ponto de interrupção dentro dele. Se o ponto de interrupção for atingido, a função foi chamada em tempo de execução.  Caso contrário, a função foi chamada em tempo de compilação.

## <a name="extern-no-locconstexpr"></a>externo constexpr

A opção de compilador [/Zc: externConstexpr](../build/reference/zc-externconstexpr.md) faz com que o compilador aplique [vínculo externo](../c-language/external-linkage.md) a variáveis declaradas usando **extern constexpr **. Em versões anteriores do Visual Studio, por padrão ou quando **/Zc: externConstexpr-** é spec if negado, o Visual Studio aplica vínculo interno a **`constexpr`** variáveis, mesmo quando a **`extern`** palavra-chave é usada. A opção **/Zc: externConstexpr** está disponível a partir da atualização 15,6 do Visual Studio 2017 e está desativada por padrão. A opção [/permissive-](../build/reference/permissive-standards-conformance.md) não habilita **/Zc: externConstexpr**.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra **`constexpr`** variáveis, funções e um tipo definido pelo usuário. Na última instrução em `main()` , a **`constexpr`** função de membro `GetValue()` é uma chamada de tempo de execução porque o valor não precisa ser conhecido no momento da compilação.

```cpp
// constexpr.cpp
// Compile with: cl /EHsc /W4 constexpr.cpp
#include <iostream>

using namespace std;

// Pass by value
constexpr float exp(float x, int n)
{
    return n == 0 ? 1 :
        n % 2 == 0 ? exp(x * x, n / 2) :
        exp(x * x, (n - 1) / 2) * x;
}

// Pass by reference
constexpr float exp2(const float& x, const int& n)
{
    return n == 0 ? 1 :
        n % 2 == 0 ? exp2(x * x, n / 2) :
        exp2(x * x, (n - 1) / 2) * x;
}

// Compile-time computation of array length
template<typename T, int N>
constexpr int length(const T(&)[N])
{
    return N;
}

// Recursive constexpr function
constexpr int fac(int n)
{
    return n == 1 ? 1 : n * fac(n - 1);
}

// User-defined type
class Foo
{
public:
    constexpr explicit Foo(int i) : _i(i) {}
    constexpr int GetValue() const
    {
        return _i;
    }
private:
    int _i;
};

int main()
{
    // foo is const:
    constexpr Foo foo(5);
    // foo = Foo(6); //Error!

    // Compile time:
    constexpr float x = exp(5, 3);
    constexpr float y { exp(2, 5) };
    constexpr int val = foo.GetValue();
    constexpr int f5 = fac(5);
    const int nums[] { 1, 2, 3, 4 };
    const int nums2[length(nums) * 2] { 1, 2, 3, 4, 5, 6, 7, 8 };

    // Run time:
    cout << "The value of foo is " << foo.GetValue() << endl;
}
```

## <a name="requirements"></a>Requisitos

Visual Studio 2015 ou posterior.

## <a name="see-also"></a>Confira também

[Declarações e definições](../cpp/declarations-and-definitions-cpp.md)\
[const](../cpp/const-cpp.md)
