---
title: Matriz e WriteOnlyArray (C++/CX)
ms.date: 01/22/2017
ms.assetid: ef7cc5f9-cae6-4636-8220-f789e5b6aea4
ms.openlocfilehash: e050fad38d4f70c651fc0ebfddb51a33e31da6f3
ms.sourcegitcommit: 89d9e1cb08fa872483d1cde98bc2a7c870e505e9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "82032402"
---
# <a name="array-and-writeonlyarray-ccx"></a>Matriz e WriteOnlyArray (C++/CX)

Você pode usar livremente matrizes de estilo C ou [std::array](../standard-library/array-class-stl.md) em um programa C++/CX (embora [o std::vetor](../standard-library/vector-class.md) seja muitas vezes uma escolha melhor), mas em qualquer API que seja publicada em metadados, você deve converter um array ou vetor de estilo C para uma [Plataforma::Array](../cppcx/platform-array-class.md) ou [Plataforma::WriteOnlyArray](../cppcx/platform-writeonlyarray-class.md) tipo, dependendo de como ele está sendo usado. O tipo [Platform::Array](../cppcx/platform-array-class.md) não é tão eficiente nem tão poderoso quanto [std::vector](../standard-library/vector-class.md), assim, como uma diretriz geral, você deve evitar seu uso no código interno que executa muitas operações nos elementos da matriz.

Os seguintes tipos de matriz podem ser passados pela ABI:

1. const Platform::Array^

1. Platform::Array^*

1. Platform::WriteOnlyArray

1. valor de retorno de Platform::Array^

Você usa esses tipos de array para implementar os três tipos de padrões de matriz definidos pelo Windows Runtime.

PassArray Usado quando o chamador passa uma matriz para um método. O tipo de parâmetro de `const`entrada C++ é [Plataforma::Array](../cppcx/platform-array-class.md)\<T>.

FillArray Usado quando o chamador passa uma matriz para o método a ser preenchido. O tipo de parâmetro de entrada C++ é [Plataforma:WriteOnlyArray](../cppcx/platform-writeonlyarray-class.md)\<T>.

ReceiveArray Usado quando o chamador recebe uma matriz que o método aloca. No C++/CX, é possível retornar a matriz no valor de retorno como um Array^ ou retorná-la o como um parâmetro de saída como o tipo Array^*.

## <a name="passarray-pattern"></a>Padrão de PassArray

Quando o código do cliente passa uma matriz para um método do C++ e o método não a modifica, o método aceita a matriz como Array^ const. No nível de interface binária do aplicativo Windows Runtime (ABI), isso é conhecido como PassArray. O exemplo a seguir mostra como passar uma matriz alocada em JavaScript a uma função C++ que lê dela.

[!code-javascript[cx_arrays#101](../cppcx/codesnippet/JavaScript/array-and-writeonlyarray-c-_1.js)]

O snippet a seguir mostra o método do C++:

[!code-cpp[cx_arrays#01](../cppcx/codesnippet/CPP/js-array/class1.cpp#01)]

## <a name="receivearray-pattern"></a>Padrão ReceiveArray

No padrão ReceiveArray, o código do cliente declara uma matriz e a passa a um método que aloca a memória para ela e a inicializa. O tipo de parâmetro de entrada C++ `Array<T>^*`é um ponteiro-a-chapéu: . O exemplo a seguir mostra como declarar um objeto de matriz em JavaScript e passá-lo a uma função C++ que aloca a memória, inicializa os elementos e o retorna ao JavaScript. O JavaScript trata a matriz alocada como um valor de retorno, mas a função C++ a trata como um parâmetro de saída.

[!code-javascript[cx_arrays#102](../cppcx/codesnippet/JavaScript/array-and-writeonlyarray-c-_3.js)]

O snippet a seguir mostra duas maneiras de implementar o método do C++:

[!code-cpp[cx_arrays#02](../cppcx/codesnippet/CPP/js-array/class1.cpp#02)]

## <a name="fill-arrays"></a>Matrizes de preenchimento

Quando você deseja alocar uma matriz no chamador e inicializá-la ou modificá-la no chamado, use `WriteOnlyArray`. O exemplo a seguir mostra como implementar uma função C++ que usa `WriteOnlyArray` e a chama do JavaScript.

[!code-javascript[cx_arrays#103](../cppcx/codesnippet/JavaScript/array-and-writeonlyarray-c-_5.js)]

O snippet a seguir mostra como implementar o método do C++:

[!code-cpp[cx_arrays#03](../cppcx/codesnippet/CPP/js-array/class1.cpp#03)]

## <a name="array-conversions"></a>Conversões de matriz

Este exemplo mostra como usar um [Platform::Array](../cppcx/platform-array-class.md) para construir outros tipos de coleções:

[!code-cpp[cx_arrays#05](../cppcx/codesnippet/CPP/js-array/class1.cpp#05)]

O exemplo a seguir mostra como construir um [Platform::Array](../cppcx/platform-array-class.md) a partir de uma matriz C-style e retorná-lo de um método público.

[!code-cpp[cx_arrays#06](../cppcx/codesnippet/CPP/js-array/class1.cpp#06)]

## <a name="jagged-arrays"></a>Matrizes denteadas

O sistema de tipos do Windows Runtime não oferece suporte ao conceito de matrizes denteadas e, portanto, você não pode usar `IVector<Platform::Array<T>>` como um valor de retorno ou parâmetro de método em um método público. Para passar uma matriz denteada ou uma sequência de sequências através da ABI, use `IVector<IVector<T>^>`.

## <a name="use-arrayreference-to-avoid-copying-data"></a>Usar ArrayReference para evitar a cópia de dados

Em alguns cenários onde os dados estiverem sendo passados pela ABI para um [Platform::Array](../cppcx/platform-array-class.md)e você, por fim, desejar processar esses dados em uma matriz C-style para obter eficiência, poderá usar [Platform::ArrayReference](../cppcx/platform-arrayreference-class.md) para evitar a operação de cópia extra. Quando você passar um [Platform::ArrayReference](../cppcx/platform-arrayreference-class.md) como um argumento para um parâmetro que usa um `Platform::Array`, o `ArrayReference` armazenará os dados diretamente em uma matriz C-style especificada por você. Apenas esteja ciente de que `ArrayReference` não tem nenhum bloqueio nos dados de origem, portanto, se esses dados forem modificados ou excluídos em outro thread antes de a chamada ser concluída, os resultados serão indefinidos.

O seguinte snippet de código mostra como copiar os resultados de uma operação [DataReader](/uwp/api/windows.storage.streams.datareader) em um `Platform::Array` (o padrão comum) e como substituir `ArrayReference` para copiar os dados diretamente em uma matriz C-style:

[!code-cpp[cx_arrays#07](../cppcx/codesnippet/CPP/js-array/class1.h#07)]

## <a name="avoid-exposing-an-array-as-a-property"></a>Evitar a exposição de uma matriz como uma propriedade

Em geral, você deve evitar expor um tipo `Platform::Array` como uma propriedade em uma classe ref, pois a matriz inteira será retornada mesmo quando o código do cliente estiver apenas tentando acessar um único elemento. Quando você precisar expor um contêiner de sequências como uma propriedade em uma classe ref pública, [Windows::Foundation::IVector](/uwp/api/windows.foundation.collections.ivector-1) será uma opção melhor. Em APIs privadas ou internas (que não são publicadas nos metadados), pense na possibilidade de usar um contêiner padrão do C++, como [std::vector](../standard-library/vector-class.md).

## <a name="see-also"></a>Confira também

[Sistema de tipo](../cppcx/type-system-c-cx.md)<br/>
[Referência da linguagem C++/CX](../cppcx/visual-c-language-reference-c-cx.md)<br/>
[Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)
