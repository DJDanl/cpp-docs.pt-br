---
title: constexpr (C++)
ms.date: 08/05/2019
f1_keywords:
- constexpr_cpp
ms.assetid: c6458ccb-51c6-4a16-aa61-f69e6f4e04f7
ms.openlocfilehash: 5c98436f537b34b1c9050e057971938d48792db1
ms.sourcegitcommit: c3bf94210bdb73be80527166264d49e33784152c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2019
ms.locfileid: "68821105"
---
# <a name="constexpr-c"></a>constexpr (C++)

A palavra-chave **constexpr** foi introduzida no c++ 11 e aprimorada no c++ 14. Isso significa *expressão constante*. Como **const**, ele pode ser aplicado a variáveis para que um erro do compilador seja gerado se qualquer código tentar modificar o valor. Diferentemente de **const**, **constexpr** também pode ser aplicado a funções e construtores de classe. **constexpr** indica que o valor, ou valor de retorno, é constante e, se possível, é calculado no momento da compilação.

Um valor integral **constexpr** pode ser usado sempre que um inteiro const é necessário, como em argumentos de modelo e declarações de matriz. E quando um valor pode ser computado em tempo de compilação em vez de tempo de execução, ele pode ajudar seu programa a ser executado mais rapidamente e usar menos memória.

Para limitar a complexidade de cálculos constantes de tempo de compilação e seus possíveis impactos no tempo de compilação, o padrão C++ 14 exige que os tipos em expressões constantes sejam [tipos literais](trivial-standard-layout-and-pod-types.md#literal_types).

## <a name="syntax"></a>Sintaxe

> **constexpr** *tipo de literal* *identificador* **=** *expressão constante* **;** 
>  **constexpr** *tipo de literal* *identificador* **{** *expressão constante* **}** **;** 
>  **constexpr** *tipo de literal* *identificador* **(** *params* **)** **;** 
>  **constexpr** *ctor* **(** *params* **)** **;**

## <a name="parameters"></a>Parâmetros

*params*<br/>
Um ou mais parâmetros, cada um deles deve ser um tipo literal e deve ser uma expressão constante.

## <a name="return-value"></a>Valor de retorno

Uma variável ou função constexpr deve retornar um [tipo literal](trivial-standard-layout-and-pod-types.md#literal_types).

## <a name="constexpr-variables"></a>variáveis constexpr

A principal diferença entre as variáveis const e constexpr é que a inicialização de uma variável const pode ser adiada até o tempo de execução. Uma variável constexpr deve ser inicializada em tempo de compilação.  Todas as variáveis constexpr são const.

- Uma variável pode ser declarada com **constexpr**, se tiver um tipo literal e for inicializada. Se a inicialização for executada por um construtor, o Construtor deverá ser declarado como **constexpr**.

- Uma referência pode ser declarada como constexpr se o objeto ao qual ele faz referência foi inicializado por uma expressão constante e quaisquer conversões implícitas que são invocadas durante a inicialização também são expressões constantes.

- Todas as declarações de uma variável ou função **constexpr** devem ter o especificador **constexpr** .

```cpp
constexpr float x = 42.0;
constexpr float y{108};
constexpr float z = exp(5, 3);
constexpr int i; // Error! Not initialized
int j = 0;
constexpr int k = j + 1; //Error! j not a constant expression
```

## <a name="constexpr_functions"></a>funções constexpr

Uma função **constexpr** é aquela cujo valor de retorno pode ser calculado no momento da compilação quando o código de consumo exigir. O consumo de código requer o valor de retorno no momento da compilação, por exemplo, para inicializar uma variável **constexpr** ou fornecer um argumento de modelo sem tipo. Quando seus argumentos são valores **constexpr** , uma função **constexpr** produz uma constante de tempo de compilação. Quando chamado com argumentos não**constexpr** , ou quando seu valor não é necessário no momento da compilação, ele produz um valor em tempo de execução como uma função regular. (Esse comportamento duplo evita que você precise escrever versões **constexpr** e não-**constexpr** da mesma função.)

Uma função ou construtor **constexpr** é implicitamente **embutido**.

As regras a seguir se aplicam às funções constexpr:

- Uma função **constexpr** deve aceitar e retornar apenas [tipos literais](trivial-standard-layout-and-pod-types.md#literal_types).

- Uma função **constexpr** pode ser recursiva.

- Ele não pode ser [virtual](../cpp/virtual-cpp.md). Um construtor não poderá ser definido como constexpr se a classe de delimitadora tiver quaisquer classes base virtuais.

- O corpo pode ser definido como `= default` ou `= delete`.

- O corpo não pode conter instruções **goto** ou blocos try.

- Uma especialização explícita de um modelo não constexpr pode ser declarada como **constexpr**:

- Uma especialização explícita de um modelo **constexpr** também não tem que ser **constexpr**:

As regras a seguir se aplicam às funções **constexpr** no Visual Studio 2017 e posteriores:

- Ele pode conter instruções **If** e **switch** e todas as instruções de looping, incluindo **for**, com base em intervalo para, **while**e **while**.

- Ele pode conter declarações de variáveis locais, mas a variável deve ser inicializada, deve ser um tipo literal e não pode ser estática ou de thread-local. A variável declarada localmente não precisa ser const e pode ser modificada.

- Uma função de membro não estática constexpr não precisa ser implicitamente const.

```cpp
constexpr float exp(float x, int n)
{
    return n == 0 ? 1 :
        n % 2 == 0 ? exp(x * x, n / 2) :
        exp(x * x, (n - 1) / 2) * x;
};
```

> [!TIP]
> No depurador do Visual Studio, ao depurar uma compilação de depuração não otimizada, você pode dizer se uma função **constexpr** está sendo avaliada em tempo de compilação, colocando um ponto de interrupção dentro dele. Se o ponto de interrupção for atingido, a função foi chamada em tempo de execução.  Caso contrário, a função foi chamada em tempo de compilação.

## <a name="extern-constexpr"></a>constexpr externo

A opção de compilador [/Zc: externConstexpr](../build/reference/zc-externconstexpr.md) faz com que o compilador aplique [vínculo externo](../c-language/external-linkage.md) a variáveis declaradas usando **constexpr externo**. Em versões anteriores do Visual Studio e, por padrão, ou se **/Zc: externConstexpr-** for especificado, o Visual Studio aplicará vínculo interno a variáveis **constexpr** , mesmo que a palavra-chave **externa** seja usada. A opção **/Zc: externConstexpr** está disponível a partir da atualização 15,6 do Visual Studio 2017 e está desativada por padrão. A opção/permissive-não habilita **/Zc: externConstexpr**.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra variáveis **constexpr** , funções e um tipo definido pelo usuário. Na última instrução de Main (), a função de membro **constexpr** GetValue () é uma chamada de tempo de execução porque o valor não precisa ser conhecido no momento da compilação.

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

## <a name="requirements"></a>Requisitos

Visual Studio 2015 ou posterior.

## <a name="see-also"></a>Consulte também

[Declarações e definições](../cpp/declarations-and-definitions-cpp.md)\
[const](../cpp/const-cpp.md)
