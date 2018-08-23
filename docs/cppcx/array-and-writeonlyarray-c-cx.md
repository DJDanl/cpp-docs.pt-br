---
title: Matriz e WriteOnlyArray (C++ c++ /CX) | Microsoft Docs
ms.custom: ''
ms.date: 01/22/2017
ms.technology: cpp-windows
ms.topic: language-reference
ms.assetid: ef7cc5f9-cae6-4636-8220-f789e5b6aea4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: adad70bfa069a43382c06f60dea53bc2e53ff187
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42606106"
---
# <a name="array-and-writeonlyarray-ccx"></a>Matriz e WriteOnlyArray (C++/CX)
Você pode usar livremente matrizes regulares de estilo C ou [std:: array](../standard-library/array-class-stl.md) no C + c++ /CLI programa CX (embora [std:: Vector](../standard-library/vector-class.md) costuma ser uma opção melhor), mas em qualquer API publicada nos metadados, você deve converter uma matriz C-style ou de vetor para uma [Platform:: array](../cppcx/platform-array-class.md) ou [Platform:: writeonlyarray](../cppcx/platform-writeonlyarray-class.md) tipo, dependendo de como ele está sendo usado. O tipo [Platform::Array](../cppcx/platform-array-class.md) não é tão eficiente nem tão poderoso quanto [std::vector](../standard-library/vector-class.md), assim, como uma diretriz geral, você deve evitar seu uso no código interno que executa muitas operações nos elementos da matriz.  
  
 Os seguintes tipos de matriz podem ser passados pela ABI:  
  
1.  const Platform::Array^  
  
2.  Platform::Array^*  
  
3.  Platform::WriteOnlyArray  
  
4.  valor de retorno de Platform::Array^  
  
 Você pode usar esses tipos de matrizes para implementar os três tipos de padrões de matrizes que são definidos pelo tempo de execução do Windows.  
  
 PassArray  
 Usada quando o chamador passa uma matriz a um método. O tipo de parâmetro de entrada C++ é `const` [Platform:: array](../cppcx/platform-array-class.md)\<T >.  
  
 FillArray  
 Usada quando o chamador passa uma matriz ao método para preenchimento. O tipo de parâmetro de entrada C++ é [Platform:: writeonlyarray](../cppcx/platform-writeonlyarray-class.md)\<T >.  
  
 ReceiveArray  
 Usada quando o chamador recebe uma matriz que o método aloca. No C++/CX, é possível retornar a matriz no valor de retorno como um Array^ ou retorná-la o como um parâmetro de saída como o tipo Array^*.  
  
## <a name="passarray-pattern"></a>Padrão de PassArray  
 Quando o código do cliente passa uma matriz para um método do C++ e o método não a modifica, o método aceita a matriz como Array^ const. No nível da ABI (interface binária) do aplicativo de tempo de execução do Windows, isso é conhecido como PassArray. O exemplo a seguir mostra como passar uma matriz alocada em JavaScript a uma função C++ que lê dela.  
  
 [!code-javascript[cx_arrays#101](../cppcx/codesnippet/JavaScript/array-and-writeonlyarray-c-_1.js)]  
  
 O trecho a seguir mostra o método do C++:  
  
 [!code-cpp[cx_arrays#01](../cppcx/codesnippet/CPP/js-array/class1.cpp#01)]  
  
## <a name="receivearray-pattern"></a>Padrão ReceiveArray  
 No padrão ReceiveArray, o código do cliente declara uma matriz e a passa a um método que aloca a memória para ela e a inicializa. O tipo de parâmetro de entrada C++ é um ponteiro para hat: `Array<T>^*`. O exemplo a seguir mostra como declarar um objeto de matriz em JavaScript e passá-lo a uma função C++ que aloca a memória, inicializa os elementos e o retorna ao JavaScript. O JavaScript trata a matriz alocada como um valor de retorno, mas a função C++ a trata como um parâmetro de saída.  
  
 [!code-javascript[cx_arrays#102](../cppcx/codesnippet/JavaScript/array-and-writeonlyarray-c-_3.js)]  
  
 O trecho a seguir mostra duas maneiras de implementar o método do C++:  
  
 [!code-cpp[cx_arrays#02](../cppcx/codesnippet/CPP/js-array/class1.cpp#02)]  
  
## <a name="fill-arrays"></a>Matrizes de preenchimento  
 Quando você deseja alocar uma matriz no chamador e inicializá-la ou modificá-la no chamado, use `WriteOnlyArray`. O exemplo a seguir mostra como implementar uma função C++ que usa `WriteOnlyArray` e a chama do JavaScript.  
  
 [!code-javascript[cx_arrays#103](../cppcx/codesnippet/JavaScript/array-and-writeonlyarray-c-_5.js)]  
  
 O trecho a seguir mostra como implementar o método do C++:  
  
 [!code-cpp[cx_arrays#03](../cppcx/codesnippet/CPP/js-array/class1.cpp#03)]  
  
## <a name="array-conversions"></a>Conversões de matriz  
 Este exemplo mostra como usar um [Platform::Array](../cppcx/platform-array-class.md) para construir outros tipos de coleções:  
  
 [!code-cpp[cx_arrays#05](../cppcx/codesnippet/CPP/js-array/class1.cpp#05)]  
  
 O exemplo a seguir mostra como construir um [Platform::Array](../cppcx/platform-array-class.md) a partir de uma matriz C-style e retorná-lo de um método público.  
  
 [!code-cpp[cx_arrays#06](../cppcx/codesnippet/CPP/js-array/class1.cpp#06)]  
  
## <a name="jagged-arrays"></a>Matrizes denteadas  
 O sistema de tipos do Tempo de Execução do Windows não oferece suporte ao conceito de matrizes denteadas e, portanto, você não pode usar `IVector<Platform::Array<T>>` como um valor de retorno ou parâmetro de método em um método público. Para passar uma matriz denteada ou uma sequência de sequências através da ABI, use `IVector<IVector<T>^>`.  
  
## <a name="use-arrayreference-to-avoid-copying-data"></a>Usar ArrayReference para evitar a cópia de dados  
 Em alguns cenários onde os dados estiverem sendo passados pela ABI para um [Platform::Array](../cppcx/platform-array-class.md)e você, por fim, desejar processar esses dados em uma matriz C-style para obter eficiência, poderá usar [Platform::ArrayReference](../cppcx/platform-arrayreference-class.md) para evitar a operação de cópia extra. Quando você passar um [Platform::ArrayReference](../cppcx/platform-arrayreference-class.md) como um argumento para um parâmetro que usa um `Platform::Array`, o `ArrayReference` armazenará os dados diretamente em uma matriz C-style especificada por você. Apenas esteja ciente de que `ArrayReference` não tem nenhum bloqueio nos dados de origem, portanto, se esses dados forem modificados ou excluídos em outro thread antes de a chamada ser concluída, os resultados serão indefinidos.  
  
 O seguinte trecho de código mostra como copiar os resultados de uma operação [DataReader](http://msdn.microsoft.com/library/windows/apps/windows.storage.streams.datareader.aspx) em um `Platform::Array` (o padrão comum) e como substituir `ArrayReference` para copiar os dados diretamente em uma matriz C-style:  
  
 [!code-cpp[cx_arrays#07](../cppcx/codesnippet/CPP/js-array/class1.h#07)]  
  
## <a name="avoid-exposing-an-array-as-a-property"></a>Evitar a exposição de uma matriz como uma propriedade  
 Em geral, você deve evitar expor um tipo `Platform::Array` como uma propriedade em uma classe ref, pois a matriz inteira será retornada mesmo quando o código do cliente estiver apenas tentando acessar um único elemento. Quando você precisar expor um contêiner de sequências como uma propriedade em uma classe ref pública, [Windows::Foundation::IVector](http://msdn.microsoft.com/library/windows/apps/br206631.aspx) será uma opção melhor. Em APIs privadas ou internas (que não são publicadas nos metadados), pense na possibilidade de usar um contêiner padrão do C++, como [std::vector](../standard-library/vector-class.md).  
  
## <a name="see-also"></a>Consulte também  
 [Sistema de tipos](../cppcx/type-system-c-cx.md)   
 [Referência de linguagem do Visual C++](../cppcx/visual-c-language-reference-c-cx.md)   
 [Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)