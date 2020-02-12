---
title: Namespace Concurrency (C++ AMP)
ms.date: 11/04/2016
f1_keywords:
- AMP/Concurrency
helpviewer_keywords:
- Concurrency namespace
ms.assetid: b5aab265-3bac-42c5-8ead-f92ce05ef267
ms.openlocfilehash: 34c3c10fa6bec2737ba78a71c282f90f284a28c2
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77139367"
---
# <a name="concurrency-namespace-c-amp"></a>Namespace Concurrency (C++ AMP)

Fornece classes e funções que aceleram a execução de C++ código em hardware de dados paralelos. Para obter mais informações, consulte [ C++ amp Overview](../cpp-amp-overview.md)

## <a name="syntax"></a>Sintaxe

```cpp
namespace Concurrency;
```

## <a name="members"></a>Membros

### <a name="namespaces"></a>{1&gt;Namespaces&lt;1}

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Namespace Concurrency::direct3d](concurrency-direct3d-namespace.md)|Fornece funções que dão suporte à interoperabilidade do D3D. Permite o uso contínuo de recursos do D3D para computação no código de AMP e o uso de recursos criados no código do AMP in D3D, sem a criação de cópias intermediárias redundantes. Você pode usar C++ o amp para acelerar de forma incremental as seções de computação intensiva de seus aplicativos do DirectX e usar a API do D3D em dados produzidos por meio de cálculos de amp.|
|[Namespace Concurrency::fast_math](concurrency-fast-math-namespace.md)|As funções no namespace `fast_math` não são compatíveis com C99. Somente as versões de precisão única de cada função são fornecidas. Essas funções usam as funções intrínsecas do DirectX, que são mais rápidas do que as funções correspondentes no namespace `precise_math` e não exigem suporte estendido de precisão dupla no acelerador, mas elas são menos precisas. Há duas versões de cada função para compatibilidade em nível de origem com o código C99; ambas as versões levam e retornam valores de precisão única.|
|[Namespace Concurrency::graphics](concurrency-graphics-namespace.md)|Fornece tipos e funções que são projetados para programação de gráficos.|
|[Namespace Concurrency::precise_math](concurrency-precise-math-namespace.md)|As funções no namespace `precise_math` são compatíveis com C99. As versões de precisão única e de precisão dupla de cada função são incluídas. Essas funções – isso inclui as funções de precisão única — exigem suporte estendido de precisão dupla no acelerador.|

### <a name="classes"></a>Classes

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Classe accelerator](accelerator-class.md)|Representa uma abstração de um nó de computação físico com otimização de DP.|
|[Classe accelerator_view](accelerator-view-class.md)|Representa uma abstração de dispositivo virtual em C++ um acelerador de dados-paralelo de amp.|
|[Classe accelerator_view_removed](accelerator-view-removed-class.md)|A exceção que é lançada quando uma chamada DirectX subjacente falha devido ao mecanismo de detecção e recuperação do tempo limite do Windows.|
|[Classe array](array-class.md)|Uma agregação de dados em um `accelerator_view` no domínio da grade. É uma coleção de variáveis, uma para cada elemento em um domínio de grade. Cada variável contém um valor que corresponde a algum C++ tipo.|
|[Classe array_view](array-view-class.md)|Representa uma exibição dos dados em uma matriz\<T, N >.|
|[Classe completion_future](completion-future-class.md)|Representa um futuro que corresponde a uma C++ operação de amp-Asynchronous.|
|[Classe extent](extent-class.md)|Representa um vetor de N valores inteiros que especificam os limites de um espaço N-dimensional que tem uma origem de 0. Os valores no vetor de coordenadas são ordenados do mais significativo para o menos significativo. Por exemplo, no espaço cartesiano tridimensional, o vetor de extensão (7, 5, 3) representa um espaço no qual a coordenada z varia de 0 a 7, a coordenada y varia de 0 a 5 e a coordenada x varia de 0 a 3.|
|[Classe index](index-class.md)|Define um ponto de índice N-dimensional.|
|[Classe invalid_compute_domain](invalid-compute-domain-class.md)|A exceção que é lançada quando o tempo de execução não pode iniciar um kernel usando o domínio de computação especificado no site de chamada `parallel_for_each`.|
|[Classe out_of_memory](out-of-memory-class.md)|A exceção que é lançada quando um método falha devido à falta de memória do sistema ou do dispositivo.|
|[Classe runtime_exception](runtime-exception-class.md)|O tipo base para exceções na biblioteca C++ amp.|
|[Classe tile_barrier](tile-barrier-class.md)|Uma classe de funcionalidade que só é creatable pelo sistema e é passada para um lado `parallel_for_each` lambda como parte do parâmetro `tiled_index`. Ele fornece um método, `wait()`, cuja finalidade é sincronizar a execução de threads em execução no grupo de threads (bloco).|
|[Classe tiled_extent](tiled-extent-class.md)|Um objeto de `tiled_extent` é um objeto de `extent` de uma a três dimensões que subdivide o espaço de extensão em blocos unidimensionais, bidimensionais ou tridimensionais.|
|[Classe tiled_index](tiled-index-class.md)|Fornece um índice em um objeto `tiled_grid`. Essa classe tem propriedades para acessar o elemento em relação à origem do bloco local e em relação à origem global.|
|[Classe uninitialized_object](uninitialized-object-class.md)|A exceção que é lançada quando um objeto não inicializado é usado.|
|[Classe unsupported_feature](unsupported-feature-class.md)|A exceção que é lançada quando um recurso sem suporte é usado.|

### <a name="enumerations"></a>Enumerações

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Enumeração de access_type](concurrency-namespace-enums-amp.md#access_type)|Especifica o tipo de acesso a dados.|
|[Enumeração de queuing_mode](concurrency-namespace-enums-amp.md#queuing_mode)|Especifica os modos de enfileiramento com suporte no acelerador.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|--------------|-----------------|
|[operador = = operador (C++ amp)](concurrency-namespace-operators-amp.md#operator_eq_eq)|Determina se as estruturas de dados especificadas são iguais.|
|[operador! = operador (C++ amp)](concurrency-namespace-operators-amp.md#operator_neq)|Determina se as estruturas de dados especificadas são desiguais.|
|[operador + operador (C++ amp)](concurrency-namespace-operators-amp.md#operator_add)|Computa a soma de componentes dos argumentos especificados.|
|[operador-operador (C++ amp)](concurrency-namespace-operators-amp.md#operator-)|Computa a diferença de componente entre os argumentos especificados.|
|[operador Operator * (C++ amp)](concurrency-namespace-operators-amp.md#operator_star)|Computa o produto com componente dos argumentos especificados.|
|[operador/operador (C++ amp)](concurrency-namespace-operators-amp.md#operator_div)|Computa o quociente de componente dos argumentos especificados.|
|[operador% Operator (C++ amp)](concurrency-namespace-operators-amp.md#operator_mod)|Computa o módulo do primeiro argumento especificado pelo segundo argumento especificado.|

### <a name="functions"></a>{1&gt;Funções&lt;1}

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[all_memory_fence](concurrency-namespace-functions-amp.md#all_memory_fence)|Bloqueia a execução de todos os threads em um bloco até que todos os acessos à memória tenham sido concluídos.|
|[amp_uninitialize](concurrency-namespace-functions-amp.md#amp_uninitialize)|Desinicializa o C++ tempo de execução de amp.|
|[atomic_compare_exchange](concurrency-namespace-functions-amp.md#atomic_compare_exchange)|Sobrecarregado. Se o valor armazenado no local especificado for comparado igual ao primeiro valor especificado, o segundo valor especificado será armazenado no mesmo local que uma operação atômica.|
|[atomic_exchange](concurrency-namespace-functions-amp.md#atomic_exchange)|Sobrecarregado. Define o valor armazenado no local especificado para o valor especificado como uma operação atômica.|
|[atomic_fetch_add](concurrency-namespace-functions-amp.md#atomic_fetch_add)|Sobrecarregado. Define o valor armazenado no local especificado para a soma desse valor e um valor especificado como uma operação atômica.|
|[atomic_fetch_and](concurrency-namespace-functions-amp.md#atomic_fetch_and)|Sobrecarregado. Define o valor armazenado no local especificado para a `and` bit a bit desse valor e um valor especificado como uma operação atômica.|
|[atomic_fetch_dec](concurrency-namespace-functions-amp.md#atomic_fetch_dec)|Sobrecarregado. Decrementa o valor armazenado no local especificado e armazena o resultado no mesmo local que uma operação atômica.|
|[atomic_fetch_inc](concurrency-namespace-functions-amp.md#atomic_fetch_inc)|Sobrecarregado. Incrementa o valor armazenado no local especificado e armazena o resultado no mesmo local que uma operação atômica.|
|[atomic_fetch_max](concurrency-namespace-functions-amp.md#atomic_fetch_max)|Sobrecarregado. Define o valor armazenado no local especificado para o maior valor e um valor especificado como uma operação atômica.|
|[atomic_fetch_min](concurrency-namespace-functions-amp.md#atomic_fetch_min)|Sobrecarregado. Define o valor armazenado no local especificado para o menor valor e um valor especificado como uma operação atômica.|
|[atomic_fetch_or](concurrency-namespace-functions-amp.md#atomic_fetch_or)|Sobrecarregado. Define o valor armazenado no local especificado para a `or` bit a bit desse valor e um valor especificado como uma operação atômica.|
|[atomic_fetch_sub](concurrency-namespace-functions-amp.md#atomic_fetch_sub)|Sobrecarregado. Define o valor armazenado no local especificado para a diferença desse valor e um valor especificado como uma operação atômica.|
|[atomic_fetch_xor](concurrency-namespace-functions-amp.md#atomic_fetch_xor)|Sobrecarregado. Define o valor armazenado no local especificado para a `xor` bit a bit desse valor e um valor especificado como uma operação atômica.|
|[copy](concurrency-namespace-functions-amp.md#copy)|Copia um C++ objeto amp. Todos os requisitos de transferência de dados síncronas são atendidos. Os dados não podem ser copiados quando o código está executando o código em um acelerador. A forma geral dessa função é `copy(src, dest)`.|
|[copy_async](concurrency-namespace-functions-amp.md#copy_async)|Copia um C++ objeto amp e retorna [completion_future](completion-future-class.md) que pode ser aguardado. Os dados não podem ser copiados quando o código está sendo executado em um acelerador. A forma geral dessa função é `copy(src, dest)`.|
|[direct3d_abort](concurrency-namespace-functions-amp.md#direct3d_abort)|Anula a execução de uma função que tem a cláusula de restrição `restrict(amp)`.|
|[direct3d_errorf](concurrency-namespace-functions-amp.md#direct3d_errorf)|Imprime uma cadeia de caracteres formatada na janela de **saída** do Visual Studio e gera uma [runtime_exception](runtime-exception-class.md) exceção que tem a mesma cadeia de caracteres de formatação.|
|[direct3d_printf](concurrency-namespace-functions-amp.md#direct3d_printf)|Imprime uma cadeia de caracteres formatada na janela de **saída** do Visual Studio. Ele é chamado de uma função que tem a cláusula de restrição `restrict(amp)`.|
|[global_memory_fence](concurrency-namespace-functions-amp.md#global_memory_fence)|Bloqueia a execução de todos os threads em um bloco até que todos os acessos de memória global tenham sido concluídos.|
|[Função parallel_for_each (C++ amp)](concurrency-namespace-functions-amp.md#parallel_for_each)|Executa uma função no domínio de computação.|
|[tile_static_memory_fence](concurrency-namespace-functions-amp.md#tile_static_memory_fence)|Bloqueia a execução de todos os threads em um bloco até que `tile_static` acessos à memória sejam concluídos.|

## <a name="constants"></a>{1&gt;Constantes&lt;1}

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Constante HLSL_MAX_NUM_BUFFERS](concurrency-namespace-constants-amp.md#hlsl_max_num_buffers)|O número máximo de buffers permitidos pelo DirectX.|
|[Constante MODULENAME_MAX_LENGTH](concurrency-namespace-constants-amp.md#modulename_max_length)|Armazena o comprimento máximo do nome do módulo. Esse valor deve ser o mesmo no compilador e no tempo de execução.|

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** amp. h

## <a name="see-also"></a>Consulte também

[Referência (C++ AMP)](reference-cpp-amp.md)
