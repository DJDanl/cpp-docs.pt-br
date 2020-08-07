---
title: Iterators
ms.date: 11/04/2016
helpviewer_keywords:
- iterator conventions
- C++ Standard Library, iterator conventions
ms.assetid: 2f746be7-b37d-4bfc-bf05-be4336ca982f
ms.openlocfilehash: c3bb2825ec6ad98f523fa4c3a616d0807eac50a8
ms.sourcegitcommit: 5ef9697b4cb1947bec9669be57bc920d2c4d82a6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2020
ms.locfileid: "87870146"
---
# <a name="iterators"></a>Iterators

Um iterador é um objeto que pode iterar em elementos em um contêiner da Biblioteca Padrão do C++ e fornecer acesso a elementos individuais. Os contêineres da Biblioteca Padrão do C++ fornecem iteradores de modo que todos os algoritmos possam acessar seus elementos de maneira padrão sem precisar se preocupar com o tipo do contêiner em que os elementos estão armazenados.

Você pode usar iteradores explicitamente usando funções membro e globais, como e e `begin()` `end()` operadores como `++` e `--` para avançar ou retroceder. Você também pode usar iteradores implicitamente com um loop for for ou (para alguns tipos de iteradores) o operador subscrito `[]` .

Na Biblioteca Padrão do C++, o início de uma sequência ou intervalo é o primeiro elemento. O final de uma sequência ou intervalo sempre é definido como um após o último elemento. As funções globais `begin` e os `end` iteradores de retorno para um contêiner especificado. O loop do iterador explícito típico sobre todos os elementos em um contêiner tem esta aparência:

```cpp
vector<int> vec{ 0,1,2,3,4 };
for (auto it = begin(vec); it != end(vec); it++)
{
    // Access element using dereference operator
    cout << *it << " ";
}
```

A mesma coisa pode ser feita de forma mais simples com um intervalo range-for:

```cpp
for (auto num : vec)
{
    // no dereference operator
    cout << num << " ";
}
```

Há cinco categorias de iteradores. Em ordem crescente de potência, as categorias são:

- **Saída**. Um *iterador de saída* `X` pode iterar em uma sequência usando o `++` operador e pode gravar um elemento apenas uma vez, usando o __`*`__ operador.

- **Entrada**. Um *iterador de entrada* `X` pode iterar em uma sequência usando o `++` operador e pode ler um elemento quantas vezes usar o `*` operador. Você pode comparar os iteradores de entrada usando `==` os `!=` operadores e. Depois de incrementar qualquer cópia de um iterador de entrada, nenhuma das outras cópias pode ser comparada, desreferenciada ou incrementada com segurança posteriormente.

- **Encaminhar**. Um *iterador progressivo* `X` pode iterar em uma sequência usando o operador + + e pode ler qualquer elemento ou escrever elementos não const a qualquer número de vezes usando o `*` operador. Você pode acessar os membros do elemento usando o `->` operador e comparar iteradores progressivos usando `==` os `!=` operadores e. Você pode fazer várias cópias de um iterador de avanço, cada uma das quais pode ser desreferenciada e incrementada de forma independente. Um iterador progressivo que é inicializado sem referência a qualquer contêiner é chamado de *iterador de encaminhamento nulo*. Iteradores de avanço nulos sempre são comparados como iguais.

- **Bidirecional**. Um *iterador bidirecional* `X` pode assumir o lugar de um iterador progressivo. No entanto, você também pode decrementar um iterador bidirecional, como no `--X` , `X--` ou `(V = *X--)` . É possível acessar membros do elemento e comparar iteradores bidirecionais da mesma forma que ocorre com iteradores de avanço.

- **Acesso aleatório**. Um *iterador de acesso aleatório* `X` pode assumir o lugar de um iterador bidirecional. Com um iterador de acesso aleatório, você pode usar o operador subscrito `[]` para acessar elementos. Você pode usar os `+` `-` operadores, `+=` e `-=` para avançar ou retroceder um número especificado de elementos e calcular a distância entre os iteradores. Você pode comparar iteradores bidirecionais usando `==` ,, `!=` ,, `<` `>` `<=` e `>=` .

Todos os iteradores podem ser atribuídos ou copiados. Eles são presumidos como objetos leves e geralmente são passados e retornados por valor, não por referência. Observe também que nenhuma das operações descritas anteriormente pode gerar uma exceção quando executada em um iterador válido.

A hierarquia das categorias de iterador pode ser resumida mostrando três sequências. Para acesso somente gravação a uma sequência, você pode usar qualquer um entre:

> iterador de saída \
> -> iterador de encaminhamento \
> -> iterador bidirecional \
> -> iterador de acesso aleatório

A seta para a direita significa "pode ser substituído por". Qualquer algoritmo que chama um iterador de saída deve funcionar bem com um iterador de avanço, por exemplo, mas *não* o oposto.

Para acesso somente leitura a uma sequência, você pode usar qualquer um entre:

> iterador de entrada \
> -> iterador de encaminhamento \
> -> iterador bidirecional \
> -> iterador de acesso aleatório

Um iterador de entrada é a mais fraca de todas as categorias, nesse caso.

Por fim, para acesso de leitura/gravação a uma sequência, você pode usar qualquer um entre:

> iterador progressivo \
> -> iterador bidirecional \
> -> iterador de acesso aleatório

Um ponteiro de objeto sempre pode servir como um iterador de acesso aleatório, de modo que ele pode servir como qualquer categoria de iterador se der suporte para o acesso de leitura/gravação adequado para a sequência que designa.

Um iterador `Iterator` diferente de um ponteiro de objeto também deve definir os tipos de membro exigidos pela especialização `iterator_traits<Iterator>`. Esses requisitos podem ser atendidos derivando-se `Iterator` do [iterador](../standard-library/iterator-struct.md)da classe base pública.

É importante entender as promessas e as limitações de cada categoria do iterador para ver como os iteradores são usados por contêineres e algoritmos na biblioteca padrão C++.

> [!NOTE]
> É possível evitar o uso de iteradores explicitamente usando loops range-for. Para obter mais informações, consulte [instrução com base em intervalo](../cpp/range-based-for-statement-cpp.md).

Agora, o Microsoft C++ oferece iteradores selecionados e iteradores de depuração para garantir que você não substitua os limites do seu contêiner. Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md) e [Suporte para iterador de depuração](../standard-library/debug-iterator-support.md).

## <a name="see-also"></a>Confira também

[Referência da biblioteca padrão do C++](../standard-library/cpp-standard-library-reference.md)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
