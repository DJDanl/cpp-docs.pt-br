---
title: constexpr (C++) | Microsoft Docs
ms.custom: ''
ms.date: 04/06/2018
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-language
ms.tgt_pltfrm: ''
ms.topic: language-reference
f1_keywords:
- constexpr_cpp
dev_langs:
- C++
ms.assetid: c6458ccb-51c6-4a16-aa61-f69e6f4e04f7
caps.latest.revision: 3
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5218e576a1aa0436ccb7696d208b1ba2049263b0
ms.sourcegitcommit: 770f6c4a57200aaa9e8ac6e08a3631a4b4bdca05
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/16/2018
---
# <a name="constexpr-c"></a>constexpr (C++)

A palavra-chave **constexpr** foi introduzido no C++ 11 e aprimorado na 14 C + +. Isso significa que *expressão constante*. Como **const**, ele pode ser aplicado a variáveis de modo que será gerado um erro do compilador se qualquer código tentar modificar o valor. Ao contrário de **const**, **constexpr** também podem ser aplicadas às funções e construtores de classe. **constexpr** indica que o valor ou o valor de retorno é constante e, se possível, será calculado em tempo de compilação.

Um **constexpr** valor integral pode ser usado sempre que um inteiro constante é necessário, como em argumentos de template e declarações de matriz. E quando um valor pode ser calculado em tempo de compilação em vez de tempo de execução, ele pode ajudar seu programa executado mais rapidamente e usar menos memória.

Para limitar a complexidade da computação constantes de tempo de compilação e seus possíveis impactos de tempo de compilação, C + + 14 padrão requer que os tipos envolvidos em expressões de constante ser restrito a [tipos literais](trivial-standard-layout-and-pod-types.md#literal_types).

## <a name="syntax"></a>Sintaxe

```
constexpr  literal-type  identifier = constant-expression;
constexpr  literal-type  identifier { constant-expression };
constexpr literal-type identifier(params );
constexpr ctor (params);
```

## <a name="parameters"></a>Parâmetros

 *params*  
Um ou mais parâmetros que devem ser um tipo literal e devem-se ser uma expressão constante.

## <a name="return-value"></a>Valor de retorno


 Uma função ou variável constexpr deve retornar um [tipo literal](trivial-standard-layout-and-pod-types.md#literal_types).

## <a name="constexpr-variables"></a>variáveis de constexpr

 A principal diferença entre const e variáveis de constexpr é que a inicialização de uma variável const poderá ser adiada até o tempo de execução, enquanto uma variável constexpr deve ser inicializada em tempo de compilação.  Todas as variáveis de constexpr são constantes.

- Uma variável pode ser declarada com **constexpr**, se ele tem um tipo literal e é inicializado. Se a inicialização é executada por um construtor, o construtor deve ser declarado como **constexpr**.

- Uma referência pode ser declarada como constexpr se o objeto que faz referência foi inicializado por uma expressão constante e quaisquer conversões implícitas que são chamados durante a inicialização também são expressões de constante.

- Todas as declarações de um **constexpr** variável ou função deve ter o **constexpr** especificador.

```cpp
constexpr float x = 42.0;
constexpr float y{108};
constexpr float z = exp(5, 3);
constexpr int i; // Error! Not initialized
int j = 0;
constexpr int k = j + 1; //Error! j not a constant expression
```

## <a name="constexpr_functions"></a> funções constexpr

Um **constexpr** função é uma cujo valor de retorno pode ser computado em compilação quando o código de consumo exija isso.  Quando os argumentos são **constexpr** valores e código requer que o valor de retorno em tempo de compilação, por exemplo, para inicializar um **constexpr** variável ou forneça um argumento de tipo não template, ele produz uma constante de tempo de compilação. Quando chamado com não**constexpr** argumentos, ou quando seu valor não é necessário no tempo de compilação, ele gera um valor de tempo de execução como uma função regular.  (Esse comportamento duplo elimina a necessidade de escrever **constexpr** e não-**constexpr** versões da mesma função.)

Um **constexpr** construtor ou função é implicitamente **embutido**.

As seguintes regras se aplicam a funções constexpr:

- Um **constexpr** função deve aceitar e retornar somente [tipos literais](trivial-standard-layout-and-pod-types.md#literal_types).

- Um **constexpr** função pode ser recursivo.

- Ele não pode ser [virtual](../cpp/virtual-cpp.md). A um construtor não pode ser definido como constexpr se a classe delimitador tem todas as classes base virtuais.

- O corpo pode ser definido como **= padrão** ou **= excluir**.

- O corpo não pode conter **goto** instruções ou blocos try.

- Uma especialização explícita de um modelo de constexpr não pode ser declarada como **constexpr**:

- Uma especialização explícita de um **constexpr** modelo não tem também **constexpr**:

As seguintes regras se aplicam a **constexpr** funciona no Visual Studio de 2017 e posterior:

- Ele pode conter **se** e **alternar** instruções e todas as instruções em loop incluindo **para**, com base em intervalo, **enquanto**e **fazer-enquanto**.
 
- Ele pode conter declarações de variável local, mas a variável deve ser inicializada, deve ser um tipo literal e não pode ser estático ou o local de thread. A variável local declarada não é necessário para ser const e pode modificar.

- Uma função de membro não estática constexpr não deve ser implicitamente const.


```cpp
constexpr float exp(float x, int n)
{
    return n == 0 ? 1 :
        n % 2 == 0 ? exp(x * x, n / 2) :
        exp(x * x, (n - 1) / 2) * x;
};
```

> [!TIP]
> Observação: No depurador do Visual Studio, quando a depuração não otimizado depurar compilação, você pode informar se um **constexpr** função está sendo avaliada em tempo de compilação, colocando um ponto de interrupção dentro dele. Se o ponto de interrupção é atingido, a função foi chamada em tempo de execução.  Caso contrário, a função foi chamada em tempo de compilação.

## <a name="extern-constexpr"></a>extern constexpr

O [/Zc:externConstexpr](../build/reference/zc-externconstexpr.md) opção de compilador faz com que o compilador aplicar [vinculação externa]() para variáveis declaradas usando **constexpr extern**. Em versões anteriores do Visual Studio e, por padrão ou se **/Zc:externConstexpr-** for especificado, o Visual Studio se aplica a vinculação interna para **constexpr** se até mesmo variáveis de **extern** palavra-chave é usada. O **/Zc:externConstexpr** opção está disponível a partir do Visual Studio 2017 atualização 15,6. e é desativada por padrão. O /permissive-option não habilita /Zc:externConstexpr.

## <a name="example"></a>Exemplo

 A exemplo a seguir mostra **constexpr** variáveis, funções e um tipo definido pelo usuário. Observe que na última instrução em Main (), o **constexpr** GetValue() de função de membro é uma chamada de tempo de execução porque o valor não deve ser conhecido em tempo de compilação.

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

// Compile time computation of array length
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
    //foo is const:
    constexpr Foo foo(5);
    // foo = Foo(6); //Error!

    //Compile time:
    constexpr float x = exp(5, 3);
    constexpr float y { exp(2, 5) };
    constexpr int val = foo.GetValue();
    constexpr int f5 = fac(5);
    const int nums[] { 1, 2, 3, 4 };
    const int nums2[length(nums) * 2] { 1, 2, 3, 4, 5, 6, 7, 8 };

    //Run time:
    cout << "The value of foo is " << foo.GetValue() << endl;

}

```

## <a name="requirements"></a>Requisitos

Visual Studio 2015

## <a name="see-also"></a>Consulte também

- [Declarações e definições](../cpp/declarations-and-definitions-cpp.md)
- [const](../cpp/const-cpp.md)
