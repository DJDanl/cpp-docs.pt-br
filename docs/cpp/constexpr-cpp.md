---
title: :::no-loc(constexpr):::C
description: 'Guia para a :::no-loc(constexpr)::: palavra-chave da linguagem C++.'
ms.date: 01/28/2020
f1_keywords:
- :::no-loc(constexpr):::_cpp
ms.assetid: c6458ccb-51c6-4a16-aa61-f69e6f4e04f7
no-loc:
- ':::no-loc(constexpr):::'
- ':::no-loc(const):::'
- ':::no-loc(inline):::'
- ':::no-loc(goto):::'
- ':::no-loc(try):::'
- ':::no-loc(if):::'
- ':::no-loc(switch):::'
- ':::no-loc(for):::'
- ':::no-loc(while):::'
ms.openlocfilehash: d66dc333b7ac9fba94221dc4efa723c7919ef88f
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229019"
---
# <a name="no-locconstexpr-c"></a>:::no-loc(constexpr):::C

A palavra-chave **`:::no-loc(constexpr):::`** foi introduzida no c++ 11 e aprimorada no c++ 14. Significa * :::no-loc(const)::: expressão Ant*. Como **`:::no-loc(const):::`** , ele pode ser aplicado a variáveis: um erro do compilador é gerado quando qualquer código tenta obter :::no-loc(if)::: o valor de mod y. Ao contrário **`:::no-loc(const):::`** de, **`:::no-loc(constexpr):::`** também pode ser aplicado a funções e à classe :::no-loc(const)::: ructors. **`:::no-loc(constexpr):::`** indica que o valor, ou valor de retorno, é :::no-loc(const)::: Ant e, quando possível, é calculado no momento da compilação.

Um **`:::no-loc(constexpr):::`** valor integral pode ser usado sempre :::no-loc(const)::: que um inteiro é necessário, como em argumentos de modelo e declarações de matriz. E quando um valor é calculado em tempo de compilação em vez de tempo de execução, ele ajuda o programa a ser executado mais rapidamente e usa menos memória.

Para limitar a complexidade de cálculos de Ant em tempo de compilação :::no-loc(const)::: e seus possíveis impactos no tempo de compilação, o padrão c++ 14 exige que os tipos em :::no-loc(const)::: expressões de Ant sejam [tipos literais](trivial-standard-layout-and-pod-types.md#literal_types).

## <a name="syntax"></a>Sintaxe

> **`:::no-loc(constexpr):::`***tipo literal* *ident :::no-loc(if)::: Ier* **=** * :::no-loc(const)::: Ant-Expression* **;**\
> **`:::no-loc(constexpr):::`***tipo literal* *ident :::no-loc(if)::: Ier* **{** * :::no-loc(const)::: Ant-Expression* **}** **;**\
> **`:::no-loc(constexpr):::`***tipo literal* *ident :::no-loc(if)::: Ier* **(** *params* **)** **;**\
> **`:::no-loc(constexpr):::`***ctor* **(** *params* **)** **;**

## <a name="parameters"></a>parâmetros

*params*\
Um ou mais parâmetros, cada um deles deve ser um tipo literal e, por sua vez, deve ser uma :::no-loc(const)::: expressão Ant.

## <a name="return-value"></a>Valor retornado

Uma **`:::no-loc(constexpr):::`** variável ou função deve retornar um [tipo literal](trivial-standard-layout-and-pod-types.md#literal_types).

## <a name="no-locconstexpr-variables"></a>Variáveis :::no-loc(constexpr):::

A :::no-loc(if)::: ferência de d principal entre **`:::no-loc(const):::`** e **`:::no-loc(constexpr):::`** variáveis é que a inicialização de uma **`:::no-loc(const):::`** variável pode ser adiada até o tempo de execução. Uma **`:::no-loc(constexpr):::`** variável deve ser inicializada em tempo de compilação.  Todas as **`:::no-loc(constexpr):::`** variáveis são **`:::no-loc(const):::`** .

- Uma variável pode ser declarada com **`:::no-loc(constexpr):::`** , quando tem um tipo literal e é inicializada. Se a inicialização for por :::no-loc(for)::: med por um :::no-loc(const)::: ructor, o :::no-loc(const)::: ructor deverá ser declarado como **`:::no-loc(constexpr):::`** .

- Uma referência pode ser declarada como **`:::no-loc(constexpr):::`** quando ambas as condições são atendidas: o objeto referenciado é inicializado por uma :::no-loc(const)::: expressão Ant e todas as conversões implícitas invocadas durante a inicialização também são :::no-loc(const)::: expressões de Ant.

- Todas as declarações de uma **`:::no-loc(constexpr):::`** variável ou função devem ter a **`:::no-loc(constexpr):::`** especificação :::no-loc(if)::: Ier.

```cpp
:::no-loc(constexpr)::: float x = 42.0;
:::no-loc(constexpr)::: float y{108};
:::no-loc(constexpr)::: float z = exp(5, 3);
:::no-loc(constexpr)::: int i; // Error! Not initialized
int j = 0;
:::no-loc(constexpr)::: int k = j + 1; //Error! j not a :::no-loc(const):::ant expression
```

## <a name="no-locconstexpr-functions"></a><a name=":::no-loc(constexpr):::_functions"></a>:::no-loc(constexpr):::funções do

Uma **`:::no-loc(constexpr):::`** função é aquela cujo valor de retorno é computáveis no momento da compilação quando o código de consumo exigir. O consumo de código requer o valor de retorno no momento da compilação para inicializar uma **`:::no-loc(constexpr):::`** variável ou para fornecer um argumento de modelo sem tipo. Quando seus argumentos são **`:::no-loc(constexpr):::`** valores, uma **`:::no-loc(constexpr):::`** função produz um Ant em tempo de compilação :::no-loc(const)::: . Quando chamado com não **`:::no-loc(constexpr):::`** argumentos, ou quando seu valor não é necessário no momento da compilação, ele produz um valor em tempo de execução como uma função regular. (Esse comportamento duplo evita que você precise escrever **`:::no-loc(constexpr):::`** e não **`:::no-loc(constexpr):::`** versões da mesma função.)

Uma **`:::no-loc(constexpr):::`** função ou :::no-loc(const)::: ructor é implicitamente **`:::no-loc(inline):::`** .

As regras a seguir se aplicam a :::no-loc(constexpr)::: funções do:

- Uma **`:::no-loc(constexpr):::`** função deve aceitar e retornar apenas [tipos literais](trivial-standard-layout-and-pod-types.md#literal_types).

- Uma **`:::no-loc(constexpr):::`** função pode ser recursiva.

- Não pode ser [virtual](../cpp/virtual-cpp.md). Um :::no-loc(const)::: ructor não pode ser definido como **`:::no-loc(constexpr):::`** quando a classe delimitadora tem quaisquer classes base virtuais.

- O corpo pode ser definido como `= default` ou `= delete` .

- O corpo não pode conter **`:::no-loc(goto):::`** instruções ou **`:::no-loc(try):::`** blocos.

- Uma especialização explícita de um não **`:::no-loc(constexpr):::`** modelo pode ser declarada como **`:::no-loc(constexpr):::`** :

- Uma especialização explícita de um **`:::no-loc(constexpr):::`** modelo também não precisa ser **`:::no-loc(constexpr):::`** :

As regras a seguir se aplicam a **`:::no-loc(constexpr):::`** funções no Visual Studio 2017 e posteriores:

- Ele pode conter **`:::no-loc(if):::`** instruções and e **`:::no-loc(switch):::`** todas as instruções de looping, incluindo **`:::no-loc(for):::`** com base em intervalo **`:::no-loc(for):::`** , **`:::no-loc(while):::`** e **do :::no-loc(while)::: -**.

- Ele pode conter declarações de variáveis locais, mas a variável deve ser inicializada. Ele deve ser um tipo literal e não pode ser **`static`** ou thread-local. A variável declarada localmente não deve ser **`:::no-loc(const):::`** e pode ser mutada.

- Uma **`:::no-loc(constexpr):::`** função não **`static`** membro não precisa ser implicitamente **`:::no-loc(const):::`** .

```cpp
:::no-loc(constexpr)::: float exp(float x, int n)
{
    return n == 0 ? 1 :
        n % 2 == 0 ? exp(x * x, n / 2) :
        exp(x * x, (n - 1) / 2) * x;
};
```

> [!TIP]
> No depurador do Visual Studio, ao depurar uma compilação de depuração não otimizada, você pode saber se uma **`:::no-loc(constexpr):::`** função está sendo avaliada em tempo de compilação, colocando um ponto de interrupção dentro dele. Se o ponto de interrupção for atingido, a função foi chamada em tempo de execução.  Caso contrário, a função foi chamada em tempo de compilação.

## <a name="extern-no-locconstexpr"></a>externo:::no-loc(constexpr):::

A opção de compilador [/Zc: externConstexpr](../build/reference/zc-extern:::no-loc(constexpr):::.md) faz com que o compilador aplique [vínculo externo](../c-language/external-linkage.md) a variáveis declaradas usando **extern :::no-loc(constexpr)::: **. Em versões anteriores do Visual Studio, por padrão ou quando **/Zc: externConstexpr-** é spec :::no-loc(if)::: negado, o Visual Studio aplica vínculo interno a **`:::no-loc(constexpr):::`** variáveis, mesmo quando a **`extern`** palavra-chave é usada. A opção **/Zc: externConstexpr** está disponível a partir da atualização 15,6 do Visual Studio 2017 e está desativada por padrão. A opção [/permissive-](../build/reference/permissive-standards-con:::no-loc(for):::mance.md) não habilita **/Zc: externConstexpr**.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra **`:::no-loc(constexpr):::`** variáveis, funções e um tipo definido pelo usuário. Na última instrução em `main()` , a **`:::no-loc(constexpr):::`** função de membro `GetValue()` é uma chamada de tempo de execução porque o valor não precisa ser conhecido no momento da compilação.

```cpp
// :::no-loc(constexpr):::.cpp
// Compile with: cl /EHsc /W4 :::no-loc(constexpr):::.cpp
#include <iostream>

using namespace std;

// Pass by value
:::no-loc(constexpr)::: float exp(float x, int n)
{
    return n == 0 ? 1 :
        n % 2 == 0 ? exp(x * x, n / 2) :
        exp(x * x, (n - 1) / 2) * x;
};

// Pass by reference
:::no-loc(constexpr)::: float exp2(:::no-loc(const)::: float& x, :::no-loc(const)::: int& n)
{
    return n == 0 ? 1 :
        n % 2 == 0 ? exp2(x * x, n / 2) :
        exp2(x * x, (n - 1) / 2) * x;
};

// Compile-time computation of array length
template<typename T, int N>
:::no-loc(constexpr)::: int length(:::no-loc(const)::: T(&)[N])
{
    return N;
}

// Recursive :::no-loc(constexpr)::: function
:::no-loc(constexpr)::: int fac(int n)
{
    return n == 1 ? 1 : n * fac(n - 1);
}

// User-defined type
class Foo
{
public:
    :::no-loc(constexpr)::: explicit Foo(int i) : _i(i) {}
    :::no-loc(constexpr)::: int GetValue() :::no-loc(const):::
    {
        return _i;
    }
private:
    int _i;
};

int main()
{
    // foo is :::no-loc(const)::::
    :::no-loc(constexpr)::: Foo foo(5);
    // foo = Foo(6); //Error!

    // Compile time:
    :::no-loc(constexpr)::: float x = exp(5, 3);
    :::no-loc(constexpr)::: float y { exp(2, 5) };
    :::no-loc(constexpr)::: int val = foo.GetValue();
    :::no-loc(constexpr)::: int f5 = fac(5);
    :::no-loc(const)::: int nums[] { 1, 2, 3, 4 };
    :::no-loc(const)::: int nums2[length(nums) * 2] { 1, 2, 3, 4, 5, 6, 7, 8 };

    // Run time:
    cout << "The value of foo is " << foo.GetValue() << endl;
}
```

## <a name="requirements"></a>Requisitos

Visual Studio 2015 ou posterior.

## <a name="see-also"></a>Confira também

[Declarações e definições](../cpp/declarations-and-definitions-cpp.md)\
[:::no-loc(const):::](../cpp/:::no-loc(const):::-cpp.md)
