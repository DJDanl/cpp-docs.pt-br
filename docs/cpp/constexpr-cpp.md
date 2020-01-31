---
title: constexpr (C++)
description: Guia para o C++ idioma constexpr palavra-chave.
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
ms.openlocfilehash: 4f34eef3217377ab50a2d80d42b5bea4b054c5be
ms.sourcegitcommit: b8c22e6d555cf833510753cba7a368d57e5886db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/29/2020
ms.locfileid: "76821773"
---
# <a name="opno-locconstexpr-c"></a>constexpr (C++)

A palavra-chave **constexpr** foi introduzida no c++ 11 e aprimorada no c++ 14. Isso significa *expressão constante*. Assim como **const** , ele pode ser aplicado a variáveis: um erro do compilador é gerado quando qualquer código tenta modificar o valor. Ao contrário de **const** , **constexpr** também pode ser aplicado a funções e construtores de classe. **constexpr** indica que o valor, ou valor de retorno, é constante e, quando possível, é calculado no momento da compilação.

Um valor integral de **constexpr** pode ser usado sempre que um inteiro de const é necessário, como em argumentos de modelo e declarações de matriz. E quando um valor é calculado em tempo de compilação em vez de tempo de execução, ele ajuda o programa a ser executado mais rapidamente e usa menos memória.

Para limitar a complexidade de cálculos constantes de tempo de compilação e seus possíveis impactos no tempo de compilação, o padrão C++ 14 exige que os tipos em expressões constantes sejam [tipos literais](trivial-standard-layout-and-pod-types.md#literal_types).

## <a name="syntax"></a>Sintaxe

> **constexpr** identificador *de tipo literal* **=** *expressão de constante* **;** \
> **constexpr** o identificador *de tipo literal* **{** *constante-expressão* **}** **;** \
> **constexpr** *identificador de tipo literal* **(** *params* **)** **;** \
> **constexpr** *ctor* **(** *params* **)** **;**

## <a name="parameters"></a>Parâmetros

*params*\
Um ou mais parâmetros, cada um deles deve ser um tipo literal e deve ser uma expressão constante.

## <a name="return-value"></a>Valor retornado

Uma **constexpr** variável ou função deve retornar um [tipo literal](trivial-standard-layout-and-pod-types.md#literal_types).

## <a name="opno-locconstexpr-variables"></a>Variáveis constexpr

A principal diferença entre as variáveis **const** e **constexpr** é que a inicialização de uma variável **const** pode ser adiada até o tempo de execução. Uma variável **constexpr** deve ser inicializada em tempo de compilação.  Todas as variáveis de **constexpr** são **const** .

- Uma variável pode ser declarada com **constexpr** , quando tem um tipo literal e é inicializada. Se a inicialização for executada por um construtor, o Construtor deverá ser declarado como **constexpr** .

- Uma referência pode ser declarada como **constexpr** quando ambas as condições são atendidas: o objeto referenciado é inicializado por uma expressão constante e todas as conversões implícitas invocadas durante a inicialização também são expressões constantes.

- Todas as declarações de uma variável ou função de **constexpr** devem ter o especificador de **constexpr** .

```cpp
constexpr float x = 42.0;
constexpr float y{108};
constexpr float z = exp(5, 3);
constexpr int i; // Error! Not initialized
int j = 0;
constexpr int k = j + 1; //Error! j not a constant expression
```

## <a name="constexpr_functions"></a>funções de constexpr

Uma função **constexpr** é aquela cujo valor de retorno é computáveis no momento da compilação quando o código de consumo exigir. O consumo de código requer o valor de retorno no momento da compilação para inicializar uma variável **constexpr** ou para fornecer um argumento de modelo sem tipo. Quando seus argumentos são **constexpr** valores, uma função **constexpr** produz uma constante de tempo de compilação. Quando chamado com argumentos não **constexpr** , ou quando seu valor não é necessário no momento da compilação, ele produz um valor em tempo de execução como uma função regular. (Esse comportamento duplo evita que você precise escrever **constexpr** e versões não **constexpr** da mesma função.)

Uma função **constexpr** ou um construtor é implicitamente **inline** .

As regras a seguir se aplicam às funções constexpr:

- Uma função **constexpr** deve aceitar e retornar apenas [tipos literais](trivial-standard-layout-and-pod-types.md#literal_types).

- Uma função **constexpr** pode ser recursiva.

- Não pode ser [virtual](../cpp/virtual-cpp.md). Um construtor não pode ser definido como **constexpr** quando a classe delimitadora tem quaisquer classes base virtuais.

- O corpo pode ser definido como `= default` ou `= delete`.

- O corpo não pode conter instruções de **goto** ou blocos de **try** .

- Uma especialização explícita de um modelo não **constexpr** pode ser declarada como **constexpr** :

- Uma especialização explícita de um modelo de **constexpr** também não precisa ser **constexpr** :

As regras a seguir se aplicam a **constexpr** funções no Visual Studio 2017 e posteriores:

- Ele pode conter instruções **if** e **switch** e todas as instruções de looping, incluindo **for** , **for** baseada em intervalo, **while** e **do-while** .

- Ele pode conter declarações de variáveis locais, mas a variável deve ser inicializada. Ele deve ser um tipo literal e não pode ser **estático** ou de thread-local. A variável declarada localmente não precisa ser **const** e pode ser mutada.

- Uma **constexpr** função membro não**estática** não deve ser implicitamente **const** .

```cpp
constexpr float exp(float x, int n)
{
    return n == 0 ? 1 :
        n % 2 == 0 ? exp(x * x, n / 2) :
        exp(x * x, (n - 1) / 2) * x;
};
```

> [!TIP]
> No depurador do Visual Studio, ao depurar uma compilação de depuração não otimizada, você pode saber se uma função de **constexpr** está sendo avaliada em tempo de compilação, colocando um ponto de interrupção dentro dele. Se o ponto de interrupção for atingido, a função foi chamada em tempo de execução.  Caso contrário, a função foi chamada em tempo de compilação.

## <a name="extern-opno-locconstexpr"></a>constexpr extern

A opção de compilador [/Zc: externConstexpr](../build/reference/zc-externconstexpr.md) faz com que o compilador aplique [vínculo externo](../c-language/external-linkage.md) a variáveis declaradas usando **constexprextern** . Em versões anteriores do Visual Studio, por padrão ou quando **/Zc: externConstexpr-** é especificado, o Visual Studio aplica vínculo interno a **constexpr** variáveis, mesmo quando a palavra-chave **externa** é usada. A opção **/Zc: externConstexpr** está disponível a partir da atualização 15,6 do Visual Studio 2017 e está desativada por padrão. A opção [/permissive-](../build/reference/permissive-standards-conformance.md) não habilita **/Zc: externConstexpr**.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra **constexpr** variáveis, funções e um tipo definido pelo usuário. Na última instrução em `main()`, a função membro **constexpr** `GetValue()` é uma chamada de tempo de execução porque o valor não precisa ser conhecido no momento da compilação.

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
};

// Pass by reference
constexpr float exp2(const float& x, const int& n)
{
    return n == 0 ? 1 :
        n % 2 == 0 ? exp2(x * x, n / 2) :
        exp2(x * x, (n - 1) / 2) * x;
};

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

## <a name="requirements"></a>Requisitos do

Visual Studio 2015 ou posterior.

## <a name="see-also"></a>Veja também

[Declarações e definições](../cpp/declarations-and-definitions-cpp.md)\
[const](../cpp/const-cpp.md)
