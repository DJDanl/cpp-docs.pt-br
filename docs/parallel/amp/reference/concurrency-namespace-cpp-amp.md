---
title: Namespace de simultaneidade (C++ AMP) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: AMP/Concurrency
dev_langs: C++
helpviewer_keywords: Concurrency namespace
ms.assetid: b5aab265-3bac-42c5-8ead-f92ce05ef267
caps.latest.revision: "28"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 4c4dd1773e74334f342ebb7e3cd64b68e6bab2b0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
|[Namespace Concurrency::direct3d](concurrency-direct3d-namespace.md)|Fornece funções que oferecem suporte à interoperabilidade D3D. Permite o uso direto de D3D recursos de computação no código de AMP e o uso de recursos criados em AMP D3D código, sem criar cópias redundantes de intermediárias. Você pode usar C++ AMP incrementalmente acelerar as seções de computação intensa de seus aplicativos DirectX e usar a API do D3D em dados produzidos de cálculos AMP.|  
|[Namespace Concurrency::fast_math](concurrency-fast-math-namespace.md)|Funções no `fast_math` namespace não são compatíveis com C99. Somente as versões de precisão única de cada função são fornecidas. Essas funções usam as funções intrínsecas DirectX, que são mais rápidas que as funções correspondentes no `precise_math` namespace e não requerem suporte estendido de precisão dupla do Accelerator, mas eles são menos precisos. Há duas versões de cada função de compatibilidade de nível de origem com o código de C99; ambas as versões levar e retornam valores de precisão simples.|  
|[Namespace Concurrency::graphics](concurrency-graphics-namespace.md)|Fornece tipos e funções que são projetadas para programação de elementos gráficos.|  
|[Namespace Concurrency::precise_math](concurrency-precise-math-namespace.md)|Funções no `precise_math` namespace são C99 compatíveis. Versões de precisão simples e precisão dupla de cada função são incluídas. Essas funções — isso inclui as funções de precisão simples — requerem suporte estendido de precisão dupla no acelerador.|  
  
### <a name="classes"></a>Classes  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Classe accelerator](accelerator-class.md)|Representa uma abstração de um nó de computação física com otimização de ponto de distribuição.|  
|[Classe accelerator_view](accelerator-view-class.md)|Representa uma abstração de dispositivo virtual em um acelerador de C++ AMP paralelo de dados.|  
|[Classe accelerator_view_removed](accelerator-view-removed-class.md)|A exceção que é lançada quando uma chamada de DirectX subjacente falhar porque o mecanismo de tempo limite detecção e recuperação do Windows.|  
|[Classe array](array-class.md)|Uma agregação de dados um `accelerator_view` no domínio de grade. É uma coleção de variáveis para cada elemento em um domínio de grade. Cada variável contém um valor que corresponde a algum tipo de C++.|  
|[Classe array_view](array-view-class.md)|Representa uma exibição dos dados em uma matriz\<T, N >.|  
|[Classe completion_future](completion-future-class.md)|Representa um futuro que corresponde a uma operação assíncrona do C++ AMP.|  
|[Classe extent](extent-class.md)|Representa um vetor de valores de inteiro de N que especificam os limites de um espaço N-dimensional que tem uma origem de 0. Os valores no vetor de coordenadas são ordenados do mais significativos para menos significativo. Por exemplo, no espaço de 3-dimensional cartesiano, o vetor de extensão (7,5,3) representa um espaço no qual a coordenada z varia de 0 a 7, os intervalos de coordenada y de 0 a 5, e a coordenada x varia de 0 a 3.|  
|[Classe index](index-class.md)|Define um ponto de índice N-dimensional.|  
|[Classe invalid_compute_domain](invalid-compute-domain-class.md)|A exceção que é lançada quando o tempo de execução não pode iniciar um kernel usando o domínio de computação especificado no `parallel_for_each` site de chamada.|  
|[Classe out_of_memory](out-of-memory-class.md)|A exceção que é lançada quando um método falhar devido a uma falta de memória de sistema ou dispositivo.|  
|[Classe runtime_exception](runtime-exception-class.md)|O tipo base para exceções na biblioteca do C++ AMP.|  
|[Classe tile_barrier](tile-barrier-class.md)|Uma classe de recurso que só é instanciável pelo sistema e é passada para um lado a lado `parallel_for_each` lambda como parte do `tiled_index` parâmetro. Ele fornece um método, `wait()`, cujo propósito é sincronizar a execução de threads que estão em execução no grupo de thread (bloco).|  
|[Classe tiled_extent](tiled-extent-class.md)|Um `tiled_extent` objeto é um `extent` objeto de um a três dimensões que subdivide o espaço de extensão em blocos unidimensionais, bidimensionais e tridimensionais.|  
|[Classe tiled_index](tiled-index-class.md)|Fornece um índice em uma `tiled_grid` objeto. Essa classe tem propriedades para acessar o elemento relativo à origem do bloco local relativo à origem global.|  
|[Classe uninitialized_object](uninitialized-object-class.md)|A exceção que é lançada quando é usado um objeto não inicializado.|  
|[Classe unsupported_feature](unsupported-feature-class.md)|A exceção que é lançada quando é usado um recurso sem suporte.|  
  
### <a name="enumerations"></a>Enumerações  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Enumeração access_type](concurrency-namespace-enums-amp.md#access_type)|Especifica o tipo de acesso de dados.|  
|[Enumeração queuing_mode](concurrency-namespace-enums-amp.md#queuing_mode)|Especifica os modos de enfileiramento de mensagens que têm suporte para o acelerador.|  
  
### <a name="operators"></a>Operadores  
  
|Operador|Descrição|  
|--------------|-----------------|  
|[operador = = operador (C++ AMP)](concurrency-namespace-operators-amp.md#operator_eq_eq)|Determina se as estruturas de dados especificado são iguais.|  
|[operador! = operador (C++ AMP)](concurrency-namespace-operators-amp.md#operator_neq)|Determina se as estruturas de dados especificado são diferentes.|  
|[operador + operador (C++ AMP)](concurrency-namespace-operators-amp.md#operator_add)|Calcula a soma de component-wise dos argumentos especificados.|  
|[operador Operator-(C++ AMP)](concurrency-namespace-operators-amp.md#operator-)|Calcula a diferença component-wise entre os argumentos especificados.|  
|[operador * operador (C++ AMP)](concurrency-namespace-operators-amp.md#operator_star)|Calcula o produto component-wise dos argumentos especificados.|  
|[operador / operador (C++ AMP)](concurrency-namespace-operators-amp.md#operator_div)|Calcula o quociente component-wise dos argumentos especificados.|  
|[operador % operador (C++ AMP)](concurrency-namespace-operators-amp.md#operator_mod)|Calcula o módulo do primeiro argumento especificado pelo segundo argumento especificado.|  
  
### <a name="functions"></a>Funções  
  
|Nome|Descrição|  
|----------|-----------------|  
|[all_memory_fence](concurrency-namespace-functions-amp.md#all_memory_fence)|Bloqueia a execução de todos os threads em um bloco até que todos os acessos de memória foram concluídos.|  
|[amp_uninitialize](concurrency-namespace-functions-amp.md#amp_uninitialize)|Uninitializes o tempo de execução C++ AMP.|  
|[atomic_compare_exchange](concurrency-namespace-functions-amp.md#atomic_compare_exchange)|Sobrecarregado. Se o valor armazenado no local especificado compara igual ao valor especificado primeiro, o segundo valor especificado é armazenado no mesmo local como uma operação atômica.|  
|[atomic_exchange](concurrency-namespace-functions-amp.md#atomic_exchange)|Sobrecarregado. Define o valor armazenado no local especificado para o valor especificado como uma operação atômica.|  
|[atomic_fetch_add](concurrency-namespace-functions-amp.md#atomic_fetch_add)|Sobrecarregado. Define o valor armazenado no local especificado para a soma de valor e um valor especificado como uma operação atômica.|  
|[atomic_fetch_and](concurrency-namespace-functions-amp.md#atomic_fetch_and)|Sobrecarregado. Define o valor armazenado no local especificado para o bit a bit `and` de valor e um valor especificado como uma operação atômica.|  
|[atomic_fetch_dec](concurrency-namespace-functions-amp.md#atomic_fetch_dec)|Sobrecarregado. Decrementa o valor armazenado no local especificado e armazena o resultado no mesmo local como uma operação atômica.|  
|[atomic_fetch_inc](concurrency-namespace-functions-amp.md#atomic_fetch_inc)|Sobrecarregado. Incrementa o valor armazenado no local especificado e armazena o resultado no mesmo local como uma operação atômica.|  
|[atomic_fetch_max](concurrency-namespace-functions-amp.md#atomic_fetch_max)|Sobrecarregado. Define o valor armazenado no local especificado para o maior do que valor e um valor especificado como uma operação atômica.|  
|[atomic_fetch_min](concurrency-namespace-functions-amp.md#atomic_fetch_min)|Sobrecarregado. Define o valor armazenado no local especificado para o menor valor e um valor especificado como uma operação atômica.|  
|[atomic_fetch_or](concurrency-namespace-functions-amp.md#atomic_fetch_or)|Sobrecarregado. Define o valor armazenado no local especificado para o bit a bit `or` de valor e um valor especificado como uma operação atômica.|  
|[atomic_fetch_sub](concurrency-namespace-functions-amp.md#atomic_fetch_sub)|Sobrecarregado. Define o valor armazenado no local especificado para a diferença de valor e um valor especificado como uma operação atômica.|  
|[atomic_fetch_xor](concurrency-namespace-functions-amp.md#atomic_fetch_xor)|Sobrecarregado. Define o valor armazenado no local especificado para o bit a bit `xor` de valor e um valor especificado como uma operação atômica.|  
|[copy](concurrency-namespace-functions-amp.md#copy)|Copia um objeto C++ AMP. Todos os requisitos de transferência de dados síncrono são atendidos. Não não possível copiar dados quando o código está executando código em um acelerador. O formato geral dessa função é `copy(src, dest)`.|  
|[copy_async](concurrency-namespace-functions-amp.md#copy_async)|Copia um objeto C++ AMP e retorna [completion_future](completion-future-class.md) que pode ser aguardado. Não não possível copiar dados quando o código está sendo executado em um acelerador. O formato geral dessa função é `copy(src, dest)`.|  
|[direct3d_abort](concurrency-namespace-functions-amp.md#direct3d_abort)|Anula a execução de uma função que tem o `restrict(amp)` cláusula de restrição.|  
|[direct3d_errorf](concurrency-namespace-functions-amp.md#direct3d_errorf)|Imprime uma cadeia de caracteres formatada para o Visual Studio **saída** janela e gera um [runtime_exception](runtime-exception-class.md) exceção com a mesma formatação de cadeia de caracteres.|  
|[direct3d_printf](concurrency-namespace-functions-amp.md#direct3d_printf)|Imprime uma cadeia de caracteres formatada para o Visual Studio **saída** janela. Ele é chamado de uma função que tem o `restrict(amp)` cláusula de restrição.|  
|[global_memory_fence](concurrency-namespace-functions-amp.md#global_memory_fence)|Bloqueia a execução de todos os threads em um bloco até que toda a memória global acessa foram concluídas.|  
|[Função (C++ AMP) parallel_for_each](concurrency-namespace-functions-amp.md#parallel_for_each)|Executa uma função em todo o domínio de computação.|  
|[tile_static_memory_fence](concurrency-namespace-functions-amp.md#tile_static_memory_fence)|Bloqueia a execução de todos os threads em um bloco até `tile_static` acessos de memória foram concluídos.|  
  
## <a name="constants"></a>Constantes  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Constante HLSL_MAX_NUM_BUFFERS](concurrency-namespace-constants-amp.md#hlsl_max_num_buffers)|O número máximo de buffers permitido por DirectX.|  
|[Constante MODULENAME_MAX_LENGTH](concurrency-namespace-constants-amp.md#modulename_max_length)|Armazena o comprimento máximo do nome do módulo. Esse valor deve ser o mesmo no compilador e o tempo de execução.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp.h  
  
## <a name="see-also"></a>Consulte também  
 [Referência (C++ AMP)](reference-cpp-amp.md)



