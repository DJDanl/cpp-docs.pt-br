---
title: auto (C++)
ms.date: 12/10/2019
f1_keywords:
- auto_CPP
- auto
helpviewer_keywords:
- auto keyword [C++]
ms.assetid: e9d495d7-601c-4547-b897-998389a311f4
ms.openlocfilehash: be268635e61005efbdb01ed8c4eec79c7cb9b800
ms.sourcegitcommit: d9c94dcabd94537e304be0261b3263c2071b437b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/25/2020
ms.locfileid: "91353032"
---
# <a name="auto-c"></a>`auto` C

Deduz o tipo de uma variável declarada da expressão de inicialização.

> [!NOTE]
> O padrão C++ define um significado original e revisado para essa palavra-chave. Antes do Visual Studio 2010, a **`auto`** palavra-chave declara uma variável na classe de armazenamento *automática* ; ou seja, uma variável que tem um tempo de vida local. A partir do Visual Studio 2010, a **`auto`** palavra-chave declara uma variável cujo tipo é deduzido da expressão de inicialização em sua declaração. A opção de compilador [ `/Zc:auto`&#91; &#93;](../build/reference/zc-auto-deduce-variable-type.md) controla o significado da **`auto`** palavra-chave.

## <a name="syntax"></a>Sintaxe

> **`auto`***inicializador* de *Declarador***`;`**

> **`[](auto`***param1* **`, auto`** *param2***`) {};`**

## <a name="remarks"></a>Comentários

A **`auto`** palavra-chave direciona o compilador para usar a expressão de inicialização de uma variável declarada, ou parâmetro de expressão lambda, para deduzir seu tipo.

Recomendamos que você use a **`auto`** palavra-chave para a maioria das situações — a menos que você realmente queira uma conversão — porque ela fornece estes benefícios:

- **Robustez:** Se o tipo da expressão for alterado — isso incluirá quando um tipo de retorno de função for alterado — ele simplesmente funcionará.

- **Desempenho:** Você tem a garantia de que não haverá nenhuma conversão.

- **Usabilidade:** Você não precisa se preocupar com as dificuldades e erros de ortografia do nome do tipo.

- **Eficiência:** Sua codificação pode ser mais eficiente.

Casos de conversão nos quais você talvez não queira usar **`auto`** :

- Quando você desejar um tipo específico e nada mais serve.

- Tipos de auxiliares de modelo de expressão — por exemplo, `(valarray+valarray)` .

Para usar a **`auto`** palavra-chave, use-a em vez de um tipo para declarar uma variável e especifique uma expressão de inicialização. Além disso, você pode modificar a **`auto`** palavra-chave usando especificadores e declaradores como **`const`** , **`volatile`** , ponteiro ( **`*`** ), referência () e **`&`** referência de rvalue ( **`&&`** ). O compilador avalia a expressão e de inicialização e usa essas informações para deduzir o tipo da variável.

A expressão de inicialização pode ser uma atribuição (sintaxe de sinal de igual), uma inicialização direta (sintaxe de estilo de função), uma [`operator new`](new-operator-cpp.md) expressão ou a expressão de inicialização pode ser o parâmetro *para declaração de intervalo* em uma instrução de [instrução baseada em intervalo `for` (C++)](../cpp/range-based-for-statement-cpp.md) . Para obter mais informações, consulte [inicializadores](../cpp/initializers.md) e os exemplos de código mais adiante neste documento.

A **`auto`** palavra-chave é um espaço reservado para um tipo, mas não é um tipo. Portanto, a **`auto`** palavra-chave não pode ser usada em conversões ou operadores como [`sizeof`](../cpp/sizeof-operator.md) e (para C++/CLI) [`typeid`](../extensions/typeid-cpp-component-extensions.md) .

## <a name="usefulness"></a>Utilidade

A **`auto`** palavra-chave é uma maneira simples de declarar uma variável que tem um tipo complicado. Por exemplo, você pode usar **`auto`** para declarar uma variável em que a expressão de inicialização envolve modelos, ponteiros para funções ou ponteiros para membros.

Você também pode usar **`auto`** para declarar e inicializar uma variável para uma expressão lambda. Você não pode declarar o tipo da variável você mesmo pois o tipo de uma expressão lambda é conhecido apenas pelo compilador. Para obter mais informações, consulte [exemplos de expressões lambda](../cpp/examples-of-lambda-expressions.md).

## <a name="trailing-return-types"></a>Rastreamento de tipos de retorno

Você pode usar **`auto`** , junto com o **`decltype`** especificador de tipo, para ajudar a gravar bibliotecas de modelos. Use **`auto`** e **`decltype`** para declarar uma função de modelo cujo tipo de retorno depende dos tipos de seus argumentos de modelo. Ou use **`auto`** e **`decltype`** para declarar uma função de modelo que encapsula uma chamada para outra função e, em seguida, retorna qualquer que seja o tipo de retorno dessa outra função. Para obter mais informações, confira [`decltype`](../cpp/decltype-cpp.md).

## <a name="references-and-cv-qualifiers"></a>Referências e qualificadores CV

Observe que o uso **`auto`** de referências de Descartes, **`const`** qualificadores e **`volatile`** qualificadores. Considere o seguinte exemplo:

```cpp
// cl.exe /analyze /EHsc /W4
#include <iostream>

using namespace std;

int main( )
{
    int count = 10;
    int& countRef = count;
    auto myAuto = countRef;

    countRef = 11;
    cout << count << " ";

    myAuto = 12;
    cout << count << endl;
}
```

No exemplo anterior, myauto é um **`int`** , não uma **`int`** referência, portanto, a saída é `11 11` , não `11 12` como seria o caso se o qualificador de referência não tivesse sido descartado pelo **`auto`** .

## <a name="type-deduction-with-braced-initializers-c14"></a>Dedução de tipo com inicializadores de chaves (C++ 14)

O exemplo de código a seguir mostra como inicializar uma **`auto`** variável usando chaves. Observe a diferença entre B e C e entre A e e.

```cpp
#include <initializer_list>

int main()
{
    // std::initializer_list<int>
    auto A = { 1, 2 };

    // std::initializer_list<int>
    auto B = { 3 };

    // int
    auto C{ 4 };

    // C3535: cannot deduce type for 'auto' from initializer list'
    auto D = { 5, 6.7 };

    // C3518 in a direct-list-initialization context the type for 'auto'
    // can only be deduced from a single initializer expression
    auto E{ 8, 9 };

    return 0;
}
```

## <a name="restrictions-and-error-messages"></a>Limitações e mensagens de erro

A tabela a seguir lista as restrições sobre o uso da **`auto`** palavra-chave e a mensagem de erro de diagnóstico correspondente que o compilador emite.

|Número do erro|Descrição|
|------------------|-----------------|
|[C3530](../error-messages/compiler-errors-2/compiler-error-c3530.md)|A **`auto`** palavra-chave não pode ser combinada com nenhum outro especificador de tipo.|
|[C3531](../error-messages/compiler-errors-2/compiler-error-c3531.md)|Um símbolo declarado com a **`auto`** palavra-chave deve ter um inicializador.|
|[C3532](../error-messages/compiler-errors-2/compiler-error-c3532.md)|Você usou incorretamente a **`auto`** palavra-chave para declarar um tipo. Por exemplo, você declarou um tipo de retorno do método ou matriz.|
|[C3533](../error-messages/compiler-errors-2/compiler-error-c3533.md), [C3539](../error-messages/compiler-errors-2/compiler-error-c3539.md)|Um parâmetro ou argumento de modelo não pode ser declarado com a **`auto`** palavra-chave.|
|[C3535](../error-messages/compiler-errors-2/compiler-error-c3535.md)|Um parâmetro de método ou de modelo não pode ser declarado com a **`auto`** palavra-chave.|
|[C3536](../error-messages/compiler-errors-2/compiler-error-c3536.md)|Um símbolo não pode ser usado antes de ser inicializado. Na prática, isso significa que uma variável não pode ser usada para se inicializar.|
|[C3537](../error-messages/compiler-errors-2/compiler-error-c3537.md)|Não é possível converter em um tipo declarado com a **`auto`** palavra-chave.|
|[C3538](../error-messages/compiler-errors-2/compiler-error-c3538.md)|Todos os símbolos em uma lista de declaradores que são declarados com a **`auto`** palavra-chave devem ser resolvidos para o mesmo tipo. Para obter mais informações, consulte [declarações e definições](declarations-and-definitions-cpp.md).|
|[C3540](../error-messages/compiler-errors-2/compiler-error-c3540.md), [C3541](../error-messages/compiler-errors-2/compiler-error-c3541.md)|Os operadores [sizeof](../cpp/sizeof-operator.md) e [typeid](../extensions/typeid-cpp-component-extensions.md) não podem ser aplicados a um símbolo declarado com a **`auto`** palavra-chave.|

## <a name="examples"></a>Exemplos

Esses fragmentos de código ilustram algumas das maneiras pelas quais a **`auto`** palavra-chave pode ser usada.

As declarações a seguir são equivalentes. Na primeira instrução, a variável `j` é declarada como tipo **`int`** . Na segunda instrução, a variável `k` é deduzida para ser Type **`int`** porque a expressão de inicialização (0) é um número inteiro.

```cpp
int j = 0;  // Variable j is explicitly type int.
auto k = 0; // Variable k is implicitly type int because 0 is an integer.
```

As seguintes declarações são equivalentes, mas a segunda declaração é mais simples do que a primeira. Um dos motivos mais atraentes para usar a **`auto`** palavra-chave é a simplicidade.

```cpp
map<int,list<string>>::iterator i = m.begin();
auto i = m.begin();
```

O fragmento de código a seguir declara o tipo de variáveis `iter` e `elem` quando os **`for`** loops e de intervalo **`for`** começam.

```cpp
// cl /EHsc /nologo /W4
#include <deque>
using namespace std;

int main()
{
    deque<double> dqDoubleData(10, 0.1);

    for (auto iter = dqDoubleData.begin(); iter != dqDoubleData.end(); ++iter)
    { /* ... */ }

    // prefer range-for loops with the following information in mind
    // (this applies to any range-for with auto, not just deque)

    for (auto elem : dqDoubleData) // COPIES elements, not much better than the previous examples
    { /* ... */ }

    for (auto& elem : dqDoubleData) // observes and/or modifies elements IN-PLACE
    { /* ... */ }

    for (const auto& elem : dqDoubleData) // observes elements IN-PLACE
    { /* ... */ }
}
```

O fragmento de código a seguir usa a **`new`** declaração de operador e de ponteiro para declarar ponteiros.

```cpp
double x = 12.34;
auto *y = new auto(x), **z = new auto(&x);
```

O próximo fragmento de código declara vários símbolos em cada instrução de declaração. Observe que todos os símbolos em cada instrução são resolvidos para o mesmo tipo.

```cpp
auto x = 1, *y = &x, **z = &y; // Resolves to int.
auto a(2.01), *b (&a);         // Resolves to double.
auto c = 'a', *d(&c);          // Resolves to char.
auto m = 1, &n = m;            // Resolves to int.
```

Esse fragmento de código usa o operador condicional (`?:`) para declarar a variável `x` como um inteiro com o valor de 200:

```cpp
int v1 = 100, v2 = 200;
auto x = v1 > v2 ? v1 : v2;
```

O fragmento de código a seguir inicializa `x` a variável para o tipo, a **`int`** variável `y` para uma referência ao tipo **`const int`** e a variável `fp` para um ponteiro para uma função que retorna o tipo **`int`** .

```cpp
int f(int x) { return x; }
int main()
{
    auto x = f(0);
    const auto& y = f(1);
    int (*p)(int x);
    p = f;
    auto fp = p;
    //...
}
```

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[`/Zc:auto` (Deduzir tipo de variável)](../build/reference/zc-auto-deduce-variable-type.md)<br/>
[`sizeof` Operador](../cpp/sizeof-operator.md)<br/>
[`typeid`](../extensions/typeid-cpp-component-extensions.md)<br/>
[`operator new`](new-operator-cpp.md)<br/>
[Declarações e definições](declarations-and-definitions-cpp.md)<br/>
[Exemplos de expressões lambda](../cpp/examples-of-lambda-expressions.md)<br/>
[Inicializadores](../cpp/initializers.md)<br/>
[`decltype`](../cpp/decltype-cpp.md)
