---
title: Namespace de simultaneidade (C++ AMP) | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- amp/Concurrency
dev_langs:
- C++
helpviewer_keywords:
- Concurrency namespace
ms.assetid: b5aab265-3bac-42c5-8ead-f92ce05ef267
caps.latest.revision: 28
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 22ba62ab8b3b4f9d14953dbab3edd8228ea85193
ms.openlocfilehash: a62955c94771320a64027f4f820434dd5e7984a1
ms.lasthandoff: 02/25/2017

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
|[Namespace Concurrency:: Direct3D](concurrency-direct3d-namespace.md)|Fornece funções que têm suporte D3D interoperabilidade. Permite o uso direto de D3D recursos de computação no código AMP e o uso de recursos criados em AMP D3D código, sem criar cópias redundantes de intermediárias. Você pode usar C++ AMP incrementalmente acelerar as seções de computação intensiva de seus aplicativos DirectX e usar a API D3D dados produzidos de computações AMP.|  
|[Namespace Concurrency:: fast_math](concurrency-fast-math-namespace.md)|Funções no `fast_math` namespace não são compatíveis com C99. São fornecidas somente versões de precisão única de cada função. Essas funções usam as funções intrínsecas DirectX, que são mais rápidas que as funções correspondentes no `precise_math` namespace e não requerem suporte estendido de precisão dupla do Accelerator, mas eles são menos precisos. Há duas versões de cada função de compatibilidade de nível de origem com o código de C99; ambas as versões levarem e retornam valores de precisão única.|  
|[Namespace Concurrency:: Graphics](concurrency-graphics-namespace.md)|Fornece tipos e funções que são projetadas para programação de gráficos.|  
|[Namespace Concurrency:: precise_math](concurrency-precise-math-namespace.md)|Funções no `precise_math` namespace são compatíveis com C99. Versões de precisão única e de precisão dupla de cada função estão incluídas. Essas funções — isso inclui as funções de precisão simples — exigem suporte estendido de precisão dupla do Accelerator.|  
  
### <a name="classes"></a>Classes  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Classe Accelerator](accelerator-class.md)|Representa uma abstração de um nó de computação física otimizado DP.|  
|[Classe accelerator_view](accelerator-view-class.md)|Representa uma abstração de dispositivo virtual em um acelerador do C++ AMP paralela de dados.|  
|[Classe accelerator_view_removed](accelerator-view-removed-class.md)|A exceção que é lançada quando uma chamada subjacente do DirectX falhar porque o mecanismo de tempo limite detecção e recuperação do Windows.|  
|[Classe Array](array-class.md)|Uma agregação de dados um `accelerator_view` no domínio de grade. É uma coleção de variáveis para cada elemento em um domínio de grade. Cada variável contém um valor que corresponde a algum tipo de C++.|  
|[Classe array_view](array-view-class.md)|Representa uma exibição dos dados em uma matriz\<T, N >.|  
|[Classe completion_future](completion-future-class.md)|Representa um futuro que corresponde a uma operação assíncrona de C++ AMP.|  
|[Classe extent](extent-class.md)|Representa um vetor de valores inteiros N que especificam os limites de um espaço N-dimensional que tem uma origem de 0. Os valores do vetor coordenadas serão ordenados da mais significativo para o menos significativo. Por exemplo, no espaço de 3-dimensional cartesiano, o vetor de extensão (7,5,3) representa um espaço no qual a coordenada z varia de 0 a 7, os intervalos de coordenada y de 0 a 5, e a coordenada x varia de 0 a 3.|  
|[Classe index](index-class.md)|Define um ponto de índice N-dimensional.|  
|[Classe invalid_compute_domain](invalid-compute-domain-class.md)|A exceção que é lançada quando o tempo de execução não pode iniciar um kernel usando o domínio de computação especificado no `parallel_for_each` site de chamada.|  
|[Classe out_of_memory](out-of-memory-class.md)|A exceção que é lançada quando um método falhar devido à falta de memória do sistema ou dispositivo.|  
|[Classe runtime_exception](runtime-exception-class.md)|O tipo base para exceções na biblioteca do C++ AMP.|  
|[Classe tile_barrier](tile-barrier-class.md)|Uma classe de recurso só pode ser criado por sistema e é passada para um lado a lado `parallel_for_each` lambda como parte do `tiled_index` parâmetro. Ele fornece um método, `wait()`, cuja finalidade é sincronizar a execução de threads que estão em execução no grupo de thread (lado a lado).|  
|[Classe tiled_extent](tiled-extent-class.md)|A `tiled_extent` objeto é uma `extent` objeto de um a três dimensões que subdivide o espaço de extensão em blocos unidimensionais, bidimensionais ou tridimensionais.|  
|[Classe tiled_index](tiled-index-class.md)|Fornece um índice em uma `tiled_grid` objeto. Essa classe tem propriedades para acessar o elemento relativo à origem do bloco local e relativo à origem global.|  
|[Classe uninitialized_object](uninitialized-object-class.md)|A exceção que é lançada quando é usado um objeto não inicializado.|  
|[Classe unsupported_feature](unsupported-feature-class.md)|A exceção que é lançada quando é usado um recurso sem suporte.|  
  
### <a name="enumerations"></a>Enumerações  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Enumeração access_type](concurrency-namespace-enums-amp.md#access_type)|Especifica o tipo de acesso de dados.|  
|[Enumeração queuing_mode](concurrency-namespace-enums-amp.md#queuing_mode)|Especifica os modos de enfileiramento de mensagens que são compatíveis com o acelerador.|  
  
### <a name="operators"></a>Operadores  
  
|Operador|Descrição|  
|--------------|-----------------|  
|[operador = = operador (C++ AMP)](concurrency-namespace-operators-amp.md#operator_eq_eq)|Determina se as estruturas de dados especificado são iguais.|  
|[operador! = operador (C++ AMP)](concurrency-namespace-operators-amp.md#operator_neq)|Determina se as estruturas de dados especificado são diferentes.|  
|[operador Operator + (C++ AMP)](concurrency-namespace-operators-amp.md#operator_add)|Calcula a soma de component-wise dos argumentos especificados.|  
|[Operador (C++ AMP)](concurrency-namespace-operators-amp.md#operator-)|Calcula a diferença component-wise entre os argumentos especificados.|  
|[operador * operador (C++ AMP)](concurrency-namespace-operators-amp.md#operator_star)|Calcula o produto component-wise dos argumentos especificados.|  
|[operador / operador (C++ AMP)](concurrency-namespace-operators-amp.md#operator_div)|Calcula o quociente component-wise dos argumentos especificados.|  
|[operador Operator % (C++ AMP)](concurrency-namespace-operators-amp.md#operator_mod)|Calcula o módulo do primeiro argumento especificado pelo segundo argumento especificado.|  
  
### <a name="functions"></a>Funções  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Função all_memory_fence](concurrency-namespace-functions-amp.md#all_memory_fence)|Bloqueia a execução de todos os threads em um bloco até que todos os acessos de memória foram concluídos.|  
|[Função amp_uninitialize](concurrency-namespace-functions-amp.md#amp_uninitialize)|O tempo de execução C++ AMP cancela a inicialização.|  
|[Função atomic_compare_exchange](concurrency-namespace-functions-amp.md#atomic_compare_exchange)|Sobrecarregado. Se o valor armazenado no local especificado compara igual ao valor especificado primeiro, o segundo valor especificado é armazenado no mesmo local como uma operação atômica.|  
|[Função atomic_exchange](concurrency-namespace-functions-amp.md#atomic_exchange)|Sobrecarregado. Define o valor armazenado no local especificado para o valor especificado como uma operação atômica.|  
|[Função atomic_fetch_add](concurrency-namespace-functions-amp.md#atomic_fetch_add)|Sobrecarregado. Define o valor armazenado no local especificado para a soma do valor e um valor especificado como uma operação atômica.|  
|[Função atomic_fetch_and](concurrency-namespace-functions-amp.md#atomic_fetch_and)|Sobrecarregado. Define o valor armazenado no local especificado para o bit a bit `and` de valor e um valor especificado como uma operação atômica.|  
|[Função atomic_fetch_dec](concurrency-namespace-functions-amp.md#atomic_fetch_dec)|Sobrecarregado. Diminui o valor armazenado no local especificado e armazena o resultado no mesmo local como uma operação atômica.|  
|[Função atomic_fetch_inc](concurrency-namespace-functions-amp.md#atomic_fetch_inc)|Sobrecarregado. Incrementa o valor armazenado no local especificado e armazena o resultado no mesmo local como uma operação atômica.|  
|[Função atomic_fetch_max](concurrency-namespace-functions-amp.md#atomic_fetch_max)|Sobrecarregado. Define o valor armazenado no local especificado para o maior valor e um valor especificado como uma operação atômica.|  
|[Função atomic_fetch_min](concurrency-namespace-functions-amp.md#atomic_fetch_min)|Sobrecarregado. Define o valor armazenado no local especificado para o menor valor e um valor especificado como uma operação atômica.|  
|[Função atomic_fetch_or](concurrency-namespace-functions-amp.md#atomic_fetch_or)|Sobrecarregado. Define o valor armazenado no local especificado para o bit a bit `or` de valor e um valor especificado como uma operação atômica.|  
|[Função atomic_fetch_sub](concurrency-namespace-functions-amp.md#atomic_fetch_sub)|Sobrecarregado. Define o valor armazenado no local especificado para a diferença de valor e um valor especificado como uma operação atômica.|  
|[Função atomic_fetch_xor](concurrency-namespace-functions-amp.md#atomic_fetch_xor)|Sobrecarregado. Define o valor armazenado no local especificado para o bit a bit `xor` de valor e um valor especificado como uma operação atômica.|  
|[Função Copy](concurrency-namespace-functions-amp.md#copy)|Copia um objeto C++ AMP. Todos os requisitos de transferência de dados síncrona são atendidos. Não não possível copiar dados quando o código será executado o código em um acelerador. A forma geral dessa função é `copy(src, dest)`.|  
|[Função copy_async](concurrency-namespace-functions-amp.md#copy_async)|Copia um objeto C++ AMP e retorna [completion_future](completion-future-class.md) que pode ser aguardado. Dados não podem ser copiados quando o código está sendo executado em um acelerador. A forma geral dessa função é `copy(src, dest)`.|  
|[Função direct3d_abort](concurrency-namespace-functions-amp.md#direct3d_abort)|Anula a execução de uma função que tem o `restrict(amp)` cláusula de restrição.|  
|[Função direct3d_errorf](concurrency-namespace-functions-amp.md#direct3d_errorf)|Imprime uma cadeia de caracteres formatada para o Visual Studio **saída** janela e gera um [runtime_exception](runtime-exception-class.md) exceção que possui a mesma formatação de cadeia de caracteres.|  
|[Função direct3d_printf](concurrency-namespace-functions-amp.md#direct3d_printf)|Imprime uma cadeia de caracteres formatada para o Visual Studio **saída** janela. Ele é chamado de uma função que tem o `restrict(amp)` cláusula de restrição.|  
|[Função global_memory_fence](concurrency-namespace-functions-amp.md#global_memory_fence)|Bloqueia a execução de todos os threads em um bloco até que toda a memória global acessa foram concluídas.|  
|[Função parallel_for_each (C++ AMP)](concurrency-namespace-functions-amp.md#parallel_for_each)|Executa uma função em todo o domínio de computação.|  
|[Função tile_static_memory_fence](concurrency-namespace-functions-amp.md#tile_static_memory_fence)|Bloqueia a execução de todos os threads em um bloco até `tile_static` acessos de memória foram concluídos.|  
  
## <a name="constants"></a>Constantes  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Constante HLSL_MAX_NUM_BUFFERS](concurrency-namespace-constants-amp.md#hlsl_max_num_buffers)|O número máximo de buffers permitido pelo DirectX.|  
|[Constante MODULENAME_MAX_LENGTH](concurrency-namespace-constants-amp.md#modulename_max_length)|Armazena o comprimento máximo do nome do módulo. Esse valor deve ser o mesmo no compilador e o tempo de execução.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp.h  
  
## <a name="see-also"></a>Consulte também  
 [Referência (C++ AMP)](reference-cpp-amp.md)




