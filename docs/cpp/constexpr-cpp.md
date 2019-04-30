---
title: constexpr (C++)
ms.date: 04/06/2018
f1_keywords:
- constexpr_cpp
ms.assetid: c6458ccb-51c6-4a16-aa61-f69e6f4e04f7
ms.openlocfilehash: 3ab3b75589864c95cb345be57db39c028a02f8db
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62399090"
---
# <a name="constexpr-c"></a>constexpr (C++)

A palavra-chave **constexpr** foi introduzido no c++11 e aprimorado no C + + 14. Isso significa *expressão constante*. Como o **const**, ele pode ser aplicado às variáveis para que um erro do compilador será gerado se nenhum código tenta modificar o valor. Diferentemente **const**, **constexpr** também pode ser aplicado a funções e construtores de classe. **constexpr** indica que o valor ou valor de retorno, é constante e, se possível, é calculado em tempo de compilação.

Um **constexpr** valor integral pode ser usado sempre que um inteiro de const é exigido, como em argumentos de modelo e declarações de matriz. E, quando um valor pode ser calculado em tempo de compilação em vez de tempo de execução, ele pode ajudar o seu programa executado mais rapidamente e usar menos memória.

Para limitar a complexidade dos cálculos de tempo de compilação constante e seus possíveis impactos no tempo de compilação, o padrão c++14 requer os tipos em expressões de constante ser [tipos de literal](trivial-standard-layout-and-pod-types.md#literal_types).

## <a name="syntax"></a>Sintaxe

> **constexpr** *tipo de literal* *identificador* ** = ** *expressão constante* **;** 
>  **constexpr** *tipo de literal* *identificador* **{** *expressão constante * **}** **;** 
>  **constexpr** *tipo de literal* *identificador* **(** *params* **)** **;** 
>  **constexpr** *ctor* **(** *params* **)** **;**

## <a name="parameters"></a>Parâmetros

*params*<br/>
Um ou mais parâmetros, cada um deles deve ser um tipo literal e deve-se ser uma expressão constante.

## <a name="return-value"></a>Valor de retorno

Uma variável constexpr ou função deve retornar um [tipo literal](trivial-standard-layout-and-pod-types.md#literal_types).

## <a name="constexpr-variables"></a>variáveis de constexpr

A principal diferença entre const e variáveis constexpr é que a inicialização de uma variável const pode ser adiada até o tempo de execução. Uma variável constexpr deve ser inicializada em tempo de compilação.  Todas as variáveis de constexpr são constantes.

- Uma variável pode ser declarada com **constexpr**, se ele tem um tipo literal e não é inicializado. Se a inicialização é executada por um construtor, o construtor deve ser declarado como **constexpr**.

- Uma referência pode ser declarada como constexpr se o objeto que faz referência a ele foi inicializado por uma expressão de constante e as conversões implícitas que são invocadas durante a inicialização também são expressões constantes.

- Todas as declarações de um **constexpr** variável ou função deve ter o **constexpr** especificador.

```cpp
constexpr float x = 42.0;
constexpr float y{108};
constexpr float z = exp(5, 3);
constexpr int i; // Error! Not initialized
int j = 0;
constexpr int k = j + 1; //Error! j not a constant expression
```

## <a name="constexpr_functions"></a> funções de constexpr

Um **constexpr** função é uma cujo valor de retorno pode ser calculado em tempo de compilação quando necessita de consumo código ele. Consumo código requer que o valor de retorno em tempo de compilação, por exemplo, para inicializar uma **constexpr** variável ou fornecer um argumento de modelo sem tipo. Quando os argumentos forem **constexpr** valores, um **constexpr** função produz uma constante de tempo de compilação. Quando chamado com não -**constexpr** argumentos, ou quando seu valor não é necessário no tempo de compilação, ele produz um valor em tempo de execução como uma função regular. (Esse comportamento duplo poupa de ter que escrever **constexpr** e não-**constexpr** versões da mesma função.)

Um **constexpr** a função ou construtor é implicitamente **embutido**.

As seguintes regras se aplicam a funções de constexpr:

- Um **constexpr** função deve aceitar e retornar apenas [tipos de literal](trivial-standard-layout-and-pod-types.md#literal_types).

- Um **constexpr** função pode ser recursivo.

- Ele não pode ser [virtual](../cpp/virtual-cpp.md). Um construtor não pode ser definido como constexpr se a classe delimitadora tiver quaisquer classes base virtuais.

- O corpo pode ser definido como `= default` ou `= delete`.

- O corpo não pode conter **goto** instruções ou blocos try.

- Uma especialização explícita de um modelo não constexpr pode ser declarada como **constexpr**:

- Uma especialização explícita de um **constexpr** modelo não precisa ser também **constexpr**:

As seguintes regras se aplicam a **constexpr** funções no Visual Studio 2017 e posterior:

- Ele pode conter **se** e **alternar** instruções e todas as instruções em loop incluindo **para**baseado em intervalo, **enquanto**e **fazer-enquanto**.

- Ele pode conter declarações de variável local, mas a variável deve ser inicializada, deve ser um tipo literal e não pode ser estático ou locais de thread. A variável local declarada não precisará ser const e pode modificar.

- Uma função de membro não estática constexpr não é necessário para que seja implicitamente const.

```cpp
constexpr float exp(float x, int n)
{
    return n == 0 ? 1 :
        n % 2 == 0 ? exp(x * x, n / 2) :
        exp(x * x, (n - 1) / 2) * x;
};
```

> [!TIP]
> No depurador do Visual Studio, quando a depuração não otimizado depurar build, você pode informar se um **constexpr** função está sendo avaliada no tempo de compilação, colocando um ponto de interrupção dentro dele. Se o ponto de interrupção for atingido, a função foi chamada no tempo de execução.  Caso contrário, a função foi chamada no tempo de compilação.

## <a name="extern-constexpr"></a>constexpr externo

O [/ZC: externconstexpr](../build/reference/zc-externconstexpr.md) opção de compilador faz o compilador aplique [vinculação externa](../c-language/external-linkage.md) para as variáveis declaradas usando **constexpr externo**. Em versões anteriores do Visual Studio e, por padrão ou se **/Zc:externConstexpr-** for especificado, vinculação interna para o Visual Studio aplicará **constexpr** mesmo variáveis a **extern** palavra-chave é usada. O **/ZC: externconstexpr** opção está disponível a partir do Visual Studio 2017 15.6 de atualização. e é desativado por padrão. O /permissive-option não habilita /ZC: externconstexpr.

## <a name="example"></a>Exemplo

A exemplo a seguir mostra **constexpr** variáveis, funções e um tipo definido pelo usuário. Na última instrução em Main (), o **constexpr** a função de membro GetValue () é uma chamada de tempo de execução porque o valor não é necessário para ser conhecido no tempo de compilação.

```cpp
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
constexpr int length(const T(&ary)[N])
{
    return N;
}

// Recursive constexpr function
constexpr int fac(int n)
{
    return n == 1 ? 1 : n*fac(n - 1);
}

// User-defined type
class Foo
{
public:
    constexpr explicit Foo(int i) : _i(i) {}
    constexpr int GetValue()
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

Visual Studio 2015

## <a name="see-also"></a>Consulte também

[Declarações e definições](../cpp/declarations-and-definitions-cpp.md)<br/>
[const](../cpp/const-cpp.md)
