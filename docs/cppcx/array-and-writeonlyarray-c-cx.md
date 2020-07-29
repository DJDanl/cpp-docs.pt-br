---
title: Matriz e WriteOnlyArray (C++/CX)
ms.date: 01/22/2017
ms.assetid: ef7cc5f9-cae6-4636-8220-f789e5b6aea4
ms.openlocfilehash: 1980fbcd1e2fa8cdaa48e00d2e7de9e45ac96a92
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87231020"
---
# <a name="array-and-writeonlyarray-ccx"></a>Matriz e WriteOnlyArray (C++/CX)

Você pode usar livremente matrizes regulares do estilo C ou [`std::array`](../standard-library/array-class-stl.md) em um programa C++/CX (embora [`std::vector`](../standard-library/vector-class.md) geralmente seja uma opção melhor), mas em qualquer API que é publicada nos metadados, você deve converter uma matriz C-style ou um vetor em um [`Platform::Array`](../cppcx/platform-array-class.md) [`Platform::WriteOnlyArray`](../cppcx/platform-writeonlyarray-class.md) tipo ou dependendo de como ele está sendo usado. O [`Platform::Array`](../cppcx/platform-array-class.md) tipo não é tão eficiente quanto tão potente quanto [`std::vector`](../standard-library/vector-class.md) , portanto, como uma diretriz geral, você deve evitar seu uso no código interno que executa muitas operações nos elementos da matriz.

Os seguintes tipos de matriz podem ser passados pela ABI:

1. `const Platform::Array^`

1. `Platform::Array^*`

1. `Platform::WriteOnlyArray`

1. valor de retorno de`Platform::Array^`

Você usa esses tipos de matriz para implementar os três tipos de padrões de matriz que são definidos pelo Windows Runtime.

PassArray\
Usada quando o chamador passa uma matriz a um método. O tipo de parâmetro de entrada C++ é **`const`** [`Platform::Array`](../cppcx/platform-array-class.md) \<T> .

FillArray\
Usada quando o chamador passa uma matriz ao método para preenchimento. O tipo de parâmetro de entrada C++ é [`Platform::WriteOnlyArray`](../cppcx/platform-writeonlyarray-class.md) \<T> .

ReceiveArray\
Usada quando o chamador recebe uma matriz que o método aloca. No C++/CX, é possível retornar a matriz no valor de retorno como um Array^ ou retorná-la o como um parâmetro de saída como o tipo Array^*.

## <a name="passarray-pattern"></a>Padrão de PassArray

Quando o código do cliente passa uma matriz para um método C++ e o método não o modifica, o método aceita a matriz como um `const Array^` . No nível da ABI (interface binária de aplicativo) Windows Runtime, isso é conhecido como um *PassArray*. O exemplo a seguir mostra como passar uma matriz alocada em JavaScript a uma função C++ que lê dela.

[!code-javascript[cx_arrays#101](../cppcx/codesnippet/JavaScript/array-and-writeonlyarray-c-_1.js)]

O snippet a seguir mostra o método do C++:

[!code-cpp[cx_arrays#01](../cppcx/codesnippet/CPP/js-array/class1.cpp#01)]

## <a name="receivearray-pattern"></a>Padrão ReceiveArray

No padrão *ReceiveArray* , o código do cliente declara uma matriz e a passa para um método que aloca a memória para ela e a inicializa. O tipo de parâmetro de entrada C++ é um ponteiro para o-Hat: `Array<T>^*` . O exemplo a seguir mostra como declarar um objeto de matriz em JavaScript e passá-lo a uma função C++ que aloca a memória, inicializa os elementos e o retorna ao JavaScript. O JavaScript trata a matriz alocada como um valor de retorno, mas a função C++ a trata como um parâmetro de saída.

[!code-javascript[cx_arrays#102](../cppcx/codesnippet/JavaScript/array-and-writeonlyarray-c-_3.js)]

O snippet a seguir mostra duas maneiras de implementar o método do C++:

[!code-cpp[cx_arrays#02](../cppcx/codesnippet/CPP/js-array/class1.cpp#02)]

## <a name="fill-arrays"></a>Matrizes de preenchimento

Quando você deseja alocar uma matriz no chamador e inicializá-la ou modificá-la no chamado, use `WriteOnlyArray`. O exemplo a seguir mostra como implementar uma função C++ que usa `WriteOnlyArray` e a chama do JavaScript.

[!code-javascript[cx_arrays#103](../cppcx/codesnippet/JavaScript/array-and-writeonlyarray-c-_5.js)]

O snippet a seguir mostra como implementar o método do C++:

[!code-cpp[cx_arrays#03](../cppcx/codesnippet/CPP/js-array/class1.cpp#03)]

## <a name="array-conversions"></a>Conversões de matriz

Este exemplo mostra como usar um [`Platform::Array`](../cppcx/platform-array-class.md) para construir outros tipos de coleções:

[!code-cpp[cx_arrays#05](../cppcx/codesnippet/CPP/js-array/class1.cpp#05)]

O exemplo a seguir mostra como construir um [`Platform::Array`](../cppcx/platform-array-class.md) de uma matriz de estilo C e retorná-lo a partir de um método público.

[!code-cpp[cx_arrays#06](../cppcx/codesnippet/CPP/js-array/class1.cpp#06)]

## <a name="jagged-arrays"></a>Matrizes denteadas

O sistema de tipos do Windows Runtime não oferece suporte ao conceito de matrizes denteadas e, portanto, você não pode usar `IVector<Platform::Array<T>>` como um valor de retorno ou parâmetro de método em um método público. Para passar uma matriz denteada ou uma sequência de sequências através da ABI, use `IVector<IVector<T>^>`.

## <a name="use-arrayreference-to-avoid-copying-data"></a>Usar ArrayReference para evitar a cópia de dados

Em alguns cenários em que os dados estão sendo passados pela ABI em um [`Platform::Array`](../cppcx/platform-array-class.md) e, em última análise, você deseja processar esses dados em uma matriz de estilo C para eficiência, é possível usar o [Platform:: ArrayReference](../cppcx/platform-arrayreference-class.md) para evitar a operação de cópia extra. Quando você passa um [`Platform::ArrayReference`](../cppcx/platform-arrayreference-class.md) como um argumento para um parâmetro que usa um `Platform::Array` , o `ArrayReference` irá armazenar os dados diretamente em uma matriz de estilo C que você especificar. Apenas esteja ciente de que `ArrayReference` não tem nenhum bloqueio nos dados de origem, portanto, se esses dados forem modificados ou excluídos em outro thread antes de a chamada ser concluída, os resultados serão indefinidos.

O trecho de código a seguir mostra como copiar os resultados de uma [`DataReader`](/uwp/api/windows.storage.streams.datareader) operação em um `Platform::Array` (o padrão usual) e, em seguida, como substituir `ArrayReference` para copiar os dados diretamente em uma matriz C-Style:

[!code-cpp[cx_arrays#07](../cppcx/codesnippet/CPP/js-array/class1.h#07)]

## <a name="avoid-exposing-an-array-as-a-property"></a>Evitar a exposição de uma matriz como uma propriedade

Em geral, você deve evitar expor um tipo `Platform::Array` como uma propriedade em uma classe ref, pois a matriz inteira será retornada mesmo quando o código do cliente estiver apenas tentando acessar um único elemento. Quando você precisa expor um contêiner de sequência como uma propriedade em uma classe ref pública, [`Windows::Foundation::IVector`](/uwp/api/windows.foundation.collections.ivector-1) é uma opção melhor. Em APIs privadas ou internas (que não são publicadas em metadados), considere o uso de um contêiner C++ padrão, como [`std::vector`](../standard-library/vector-class.md) .

## <a name="see-also"></a>Confira também

[Sistema de tipo](../cppcx/type-system-c-cx.md)<br/>
[Referência de linguagem do C++/CX](../cppcx/visual-c-language-reference-c-cx.md)<br/>
[Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)
