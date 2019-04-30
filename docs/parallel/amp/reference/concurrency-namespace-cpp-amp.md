---
title: Namespace Concurrency (C++ AMP)
ms.date: 11/04/2016
f1_keywords:
- AMP/Concurrency
helpviewer_keywords:
- Concurrency namespace
ms.assetid: b5aab265-3bac-42c5-8ead-f92ce05ef267
ms.openlocfilehash: e0870eb046f1cec091a72d49c94a2fea41484340
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64346031"
---
# <a name="concurrency-namespace-c-amp"></a>Namespace Concurrency (C++ AMP)

Fornece classes e funções que aceleram a execução de código C++ no hardware paralelo de dados. Para obter mais informações, consulte [visão geral do C++ AMP](../cpp-amp-overview.md)

## <a name="syntax"></a>Sintaxe

```
namespace Concurrency;
```

## <a name="members"></a>Membros

### <a name="namespaces"></a>Namespaces

|Nome|Descrição|
|----------|-----------------|
|[Namespace Concurrency::direct3d](concurrency-direct3d-namespace.md)|Fornece funções que suportam a interoperabilidade D3D. Permite o uso contínuo de recursos de D3D para cálculos no código de AMP e o uso de recursos criados no AMP no código D3D, sem criar cópias intermediários redundantes. Você pode usar o C++ AMP acelerar de forma crescente as seções intensas de cálculo dos seus aplicativos DirectX e usar o D3D API em dados gerados pelos cálculos AMP.|
|[Namespace Concurrency::fast_math](concurrency-fast-math-namespace.md)|Funções no `fast_math` namespace não são compatíveis com C99. São fornecidas apenas versões de precisão simples de cada função. Essas funções usam as funções intrínsecas do DirectX, que são mais rápidas que as funções correspondentes no `precise_math` namespace e não exigem suporte de precisão dupla estendido no Acelerador, mas eles são menos precisos. Há duas versões de cada função para compatibilidade no nível de código-fonte com código C99; as duas versões adotam e retornam valores de precisão simples.|
|[Namespace Concurrency::graphics](concurrency-graphics-namespace.md)|Fornece tipos e funções projetadas para programação de elementos gráficos.|
|[Namespace Concurrency::precise_math](concurrency-precise-math-namespace.md)|Funções no `precise_math` namespace são compatíveis com C99. Versões de precisão simples e de precisão dupla de cada função são incluídas. Essas funções — isso inclui as funções de precisão simples — exigem suporte de precisão dupla estendido no acelerador.|

### <a name="classes"></a>Classes

|Nome|Descrição|
|----------|-----------------|
|[Classe accelerator](accelerator-class.md)|Representa uma abstração de um nó de computação físico otimizado por DP.|
|[Classe accelerator_view](accelerator-view-class.md)|Representa uma abstração de dispositivo virtual em um acelerador de dados paralelo do C++ AMP.|
|[Classe accelerator_view_removed](accelerator-view-removed-class.md)|A exceção que é lançada quando uma chamada subjacente de DirectX falha devido ao mecanismo de tempo limite detecção e recuperação do Windows.|
|[Classe array](array-class.md)|Um agregado de dados em um `accelerator_view` no domínio da grade. É uma coleção de variáveis, uma para cada elemento em um domínio da grade. Cada variável contém um valor que corresponde a algum tipo de C++.|
|[Classe array_view](array-view-class.md)|Representa uma exibição dos dados em uma matriz\<T, N >.|
|[Classe completion_future](completion-future-class.md)|Representa um futuro que corresponde à operação assíncrona de C++ AMP.|
|[Classe extent](extent-class.md)|Representa um vetor de N valores inteiros que especificam os limites de um espaço N-dimensional que tenha uma origem de 0. Os valores no vetor de coordenadas são ordenados do mais significativo para o menos significativo. Por exemplo, no espaço Cartesiano de 3-dimensional, o vetor de extensão (7,5,3) representa um espaço no qual a coordenada z varia de 0 a 7, a coordenada y varia de 0 a 5, e a coordenada x varia de 0 a 3.|
|[Classe index](index-class.md)|Define um ponto de índice N-dimensional.|
|[Classe invalid_compute_domain](invalid-compute-domain-class.md)|A exceção que é lançada quando o tempo de execução não pode iniciar um kernel usando o domínio de cálculo especificado no `parallel_for_each` site de chamada.|
|[Classe out_of_memory](out-of-memory-class.md)|A exceção que é lançada quando um método falhar devido à falta de memória do sistema ou do dispositivo.|
|[Classe runtime_exception](runtime-exception-class.md)|O tipo base para exceções na biblioteca do C++ AMP.|
|[Classe tile_barrier](tile-barrier-class.md)|Uma classe de recurso que só é que pode ser criado pelo sistema e é passada para um lado a lado `parallel_for_each` lambda como parte do `tiled_index` parâmetro. Ele fornece um método, `wait()`, cujo objetivo é sincronizar a execução de threads que estão em execução no grupo de segmentos (tile).|
|[Classe tiled_extent](tiled-extent-class.md)|Um `tiled_extent` objeto é um `extent` objeto de um a três dimensões que subdividem o espaço de extensão em blocos unidimensionais, bidimensionais ou tridimensionais.|
|[Classe tiled_index](tiled-index-class.md)|Fornece um índice em uma `tiled_grid` objeto. Essa classe possui propriedades para acessar o elemento relativo à origem do bloco local e relativo à origem global.|
|[Classe uninitialized_object](uninitialized-object-class.md)|A exceção que é lançada quando um objeto não inicializado é usado.|
|[Classe unsupported_feature](unsupported-feature-class.md)|A exceção que é lançada quando um recurso sem suporte é usado.|

### <a name="enumerations"></a>Enumerações

|Nome|Descrição|
|----------|-----------------|
|[Enumeração access_type](concurrency-namespace-enums-amp.md#access_type)|Especifica o tipo de acesso de dados.|
|[Enumeração queuing_mode](concurrency-namespace-enums-amp.md#queuing_mode)|Especifica os modos de enfileiramento de mensagens que são suportados no acelerador.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|--------------|-----------------|
|[operador = = operador (C++ AMP)](concurrency-namespace-operators-amp.md#operator_eq_eq)|Determina se as estruturas de dados especificado são iguais.|
|[operador! = operador (C++ AMP)](concurrency-namespace-operators-amp.md#operator_neq)|Determina se as estruturas de dados especificados são desiguais.|
|[operador + operador (C++ AMP)](concurrency-namespace-operators-amp.md#operator_add)|Calcula a soma em todo componente dos argumentos especificados.|
|[operador Operator-(C++ AMP)](concurrency-namespace-operators-amp.md#operator-)|Calcula a diferença em entre os argumentos especificados.|
|[operador * operador (C++ AMP)](concurrency-namespace-operators-amp.md#operator_star)|Calcula o produto em todo componente dos argumentos especificados.|
|[operador / operador (C++ AMP)](concurrency-namespace-operators-amp.md#operator_div)|Calcula o quociente em todo componente dos argumentos especificados.|
|[operador Operator % (C++ AMP)](concurrency-namespace-operators-amp.md#operator_mod)|Calcula o módulo do primeiro argumento especificado pelo segundo argumento especificado.|

### <a name="functions"></a>Funções

|Nome|Descrição|
|----------|-----------------|
|[all_memory_fence](concurrency-namespace-functions-amp.md#all_memory_fence)|Impede a execução de todos os threads em um bloco até que todos os acessos de memória sejam concluídos.|
|[amp_uninitialize](concurrency-namespace-functions-amp.md#amp_uninitialize)|Encerra o tempo de execução C++ AMP.|
|[atomic_compare_exchange](concurrency-namespace-functions-amp.md#atomic_compare_exchange)|Sobrecarregado. Se o valor armazenado no local especificado compara igual ao primeiro valor especificado, o segundo valor especificado é armazenado no mesmo local como uma operação atômica.|
|[atomic_exchange](concurrency-namespace-functions-amp.md#atomic_exchange)|Sobrecarregado. Define o valor armazenado no local especificado para o valor especificado como uma operação atômica.|
|[atomic_fetch_add](concurrency-namespace-functions-amp.md#atomic_fetch_add)|Sobrecarregado. Define o valor armazenado no local especificado para a soma desse valor e um valor especificado como uma operação atômica.|
|[atomic_fetch_and](concurrency-namespace-functions-amp.md#atomic_fetch_and)|Sobrecarregado. Define o valor armazenado no local especificado para o bit a bit `and` desse valor e um valor especificado como uma operação atômica.|
|[atomic_fetch_dec](concurrency-namespace-functions-amp.md#atomic_fetch_dec)|Sobrecarregado. Decrementa o valor armazenado no local especificado e armazena o resultado no mesmo local como uma operação atômica.|
|[atomic_fetch_inc](concurrency-namespace-functions-amp.md#atomic_fetch_inc)|Sobrecarregado. Incrementa o valor armazenado no local especificado e armazena o resultado no mesmo local como uma operação atômica.|
|[atomic_fetch_max](concurrency-namespace-functions-amp.md#atomic_fetch_max)|Sobrecarregado. Define o valor armazenado no local especificado como o maior desse valor e um valor especificado como uma operação atômica.|
|[atomic_fetch_min](concurrency-namespace-functions-amp.md#atomic_fetch_min)|Sobrecarregado. Define o valor armazenado no local especificado para o menor desse valor e um valor especificado como uma operação atômica.|
|[atomic_fetch_or](concurrency-namespace-functions-amp.md#atomic_fetch_or)|Sobrecarregado. Define o valor armazenado no local especificado para o bit a bit `or` desse valor e um valor especificado como uma operação atômica.|
|[atomic_fetch_sub](concurrency-namespace-functions-amp.md#atomic_fetch_sub)|Sobrecarregado. Define o valor armazenado no local especificado para a diferença desse valor e um valor especificado como uma operação atômica.|
|[atomic_fetch_xor](concurrency-namespace-functions-amp.md#atomic_fetch_xor)|Sobrecarregado. Define o valor armazenado no local especificado para o bit a bit `xor` desse valor e um valor especificado como uma operação atômica.|
|[copy](concurrency-namespace-functions-amp.md#copy)|Copia um objeto C++ AMP. Todos os requisitos de transferência de dados síncronos são atendidos. Dados não podem ser copiados quando o código está executando código em um acelerador. A forma geral dessa função é `copy(src, dest)`.|
|[copy_async](concurrency-namespace-functions-amp.md#copy_async)|Copia um C++ objeto AMP e retorna [completion_future](completion-future-class.md) que pode ser esperado. Dados não podem ser copiados quando o código está em execução em um acelerador. A forma geral dessa função é `copy(src, dest)`.|
|[direct3d_abort](concurrency-namespace-functions-amp.md#direct3d_abort)|Anula a execução de uma função que tem o `restrict(amp)` cláusula de restrição.|
|[direct3d_errorf](concurrency-namespace-functions-amp.md#direct3d_errorf)|Imprime uma cadeia de caracteres formatada para o Visual Studio **saída** janela e gera um [runtime_exception](runtime-exception-class.md) exceção que tem a mesma formatação de cadeia de caracteres.|
|[direct3d_printf](concurrency-namespace-functions-amp.md#direct3d_printf)|Imprime uma cadeia de caracteres formatada para o Visual Studio **saída** janela. Ele é chamado de uma função que tem o `restrict(amp)` cláusula de restrição.|
|[global_memory_fence](concurrency-namespace-functions-amp.md#global_memory_fence)|Impede a execução de todos os threads em um bloco até que toda a memória global acessa tenha sido concluído.|
|[Função parallel_for_each (C++ AMP)](concurrency-namespace-functions-amp.md#parallel_for_each)|Executa uma função entre o domínio de cálculo.|
|[tile_static_memory_fence](concurrency-namespace-functions-amp.md#tile_static_memory_fence)|Impede a execução de todos os threads em um bloco até que `tile_static` acessos de memória sejam concluídos.|

## <a name="constants"></a>Constantes

|Nome|Descrição|
|----------|-----------------|
|[HLSL_MAX_NUM_BUFFERS Constant](concurrency-namespace-constants-amp.md#hlsl_max_num_buffers)|O número máximo de buffers permitido pelo DirectX.|
|[Constante MODULENAME_MAX_LENGTH](concurrency-namespace-constants-amp.md#modulename_max_length)|Armazena o comprimento máximo do nome do módulo. Esse valor deve ser o mesmo no compilador e o tempo de execução.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amp. h

## <a name="see-also"></a>Consulte também

[Referência (C++ AMP)](reference-cpp-amp.md)
