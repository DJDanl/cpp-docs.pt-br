---
title: "Namespace Concurrency (C++ AMP) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "amp/Concurrency"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Namespace Concurrency"
ms.assetid: b5aab265-3bac-42c5-8ead-f92ce05ef267
caps.latest.revision: 28
caps.handback.revision: 28
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Namespace Concurrency (C++ AMP)
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Fornece classes e funções que aceleram a execução de código C++ no hardware paralelo de dados. Para obter mais informações, consulte [Visão geral do C++ AMP](../../../parallel/amp/cpp-amp-overview.md)  
  
## <a name="syntax"></a>Sintaxe  
  
```  
namespace Concurrency;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="namespaces"></a>Namespaces  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Namespace Concurrency:: Direct3D](../../../parallel/amp/reference/concurrency-direct3d-namespace.md)|Fornece funções que têm suporte D3D interoperabilidade. Permite o uso direto de D3D recursos de computação no código AMP e o uso de recursos criados em AMP D3D código, sem criar cópias redundantes de intermediárias. Você pode usar C++ AMP incrementalmente acelerar as seções de computação intensiva de seus aplicativos DirectX e usar a API D3D dados produzidos de computações AMP.|  
|[Namespace Concurrency:: fast_math](../../../parallel/amp/reference/concurrency-fast-math-namespace.md)|Funções no `fast_math` namespace não são compatíveis com C99. São fornecidas somente versões de precisão única de cada função. Essas funções usam as funções intrínsecas DirectX, que são mais rápidas que as funções correspondentes no `precise_math` namespace e não requerem suporte estendido de precisão dupla do Accelerator, mas eles são menos precisos. Há duas versões de cada função de compatibilidade de nível de origem com o código de C99; ambas as versões levarem e retornam valores de precisão única.|  
|[Namespace Concurrency:: Graphics](../../../parallel/amp/reference/concurrency-graphics-namespace.md)|Fornece tipos e funções que são projetadas para programação de gráficos.|  
|[Namespace Concurrency:: precise_math](../Topic/Concurrency::precise_math%20Namespace.md)|Funções no `precise_math` namespace são compatíveis com C99. Versões de precisão única e de precisão dupla de cada função estão incluídas. Essas funções — isso inclui as funções de precisão simples — exigem suporte estendido de precisão dupla do Accelerator.|  
  
### <a name="classes"></a>Classes  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Classe Accelerator](../../../parallel/amp/reference/accelerator-class.md)|Representa uma abstração de um nó de computação física otimizado DP.|  
|[Classe accelerator_view](../Topic/accelerator_view%20Class.md)|Representa uma abstração de dispositivo virtual em um acelerador do C++ AMP paralela de dados.|  
|[Classe accelerator_view_removed](../../../parallel/amp/reference/accelerator-view-removed-class.md)|A exceção que é lançada quando uma chamada subjacente do DirectX falhar porque o mecanismo de tempo limite detecção e recuperação do Windows.|  
|[Classe Array](../../../parallel/amp/reference/array-class.md)|Uma agregação de dados um `accelerator_view` no domínio de grade. É uma coleção de variáveis para cada elemento em um domínio de grade. Cada variável contém um valor que corresponde a algum tipo de C++.|  
|[Classe array_view](../../../parallel/amp/reference/array-view-class.md)|Representa uma exibição dos dados em uma matriz \< T, N >.|  
|[Classe completion_future](../Topic/completion_future%20Class.md)|Representa um futuro que corresponde a uma operação assíncrona de C++ AMP.|  
|[Classe Extent](../Topic/extent%20Class%20\(C++%20AMP\).md)|Representa um vetor de valores inteiros N que especificam os limites de um espaço N-dimensional que tem uma origem de 0. Os valores do vetor coordenadas serão ordenados da mais significativo para o menos significativo. Por exemplo, no espaço de 3-dimensional cartesiano, o vetor de extensão (7,5,3) representa um espaço no qual a coordenada z varia de 0 a 7, os intervalos de coordenada y de 0 a 5, e a coordenada x varia de 0 a 3.|  
|[Classe index](../../../parallel/amp/reference/index-class.md)|Define um ponto de índice N-dimensional.|  
|[Classe invalid_compute_domain](../../../parallel/amp/reference/invalid-compute-domain-class.md)|A exceção que é lançada quando o tempo de execução não pode iniciar um kernel usando o domínio de computação especificado no `parallel_for_each` site de chamada.|  
|[Classe out_of_memory](../../../parallel/amp/reference/out-of-memory-class.md)|A exceção que é lançada quando um método falhar devido à falta de memória do sistema ou dispositivo.|  
|[Classe runtime_exception](../Topic/runtime_exception%20Class.md)|O tipo base para exceções na biblioteca do C++ AMP.|  
|[Classe tile_barrier](../Topic/tile_barrier%20Class.md)|Uma classe de recurso só pode ser criado por sistema e é passada para um lado a lado `parallel_for_each` lambda como parte do `tiled_index` parâmetro. Ele fornece um método, `wait()`, cuja finalidade é sincronizar a execução de threads que estão em execução no grupo de thread (lado a lado).|  
|[Classe tiled_extent](../../../parallel/amp/reference/tiled-extent-class.md)|Um `tiled_extent` objeto é uma `extent` objeto de um a três dimensões que subdivide o espaço de extensão em blocos unidimensionais, bidimensionais ou tridimensionais.|  
|[Classe tiled_index](../../../parallel/amp/reference/tiled-index-class.md)|Fornece um índice em uma `tiled_grid` objeto. Essa classe tem propriedades para acessar o elemento relativo à origem do bloco local e relativo à origem global.|  
|[Classe uninitialized_object](../../../parallel/amp/reference/uninitialized-object-class.md)|A exceção que é lançada quando é usado um objeto não inicializado.|  
|[Classe unsupported_feature](../../../parallel/amp/reference/unsupported-feature-class.md)|A exceção que é lançada quando é usado um recurso sem suporte.|  
  
### <a name="enumerations"></a>Enumerações  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Enumeração access_type](../Topic/access_type%20Enumeration.md)|Especifica o tipo de acesso de dados.|  
|[Enumeração queuing_mode](../../../parallel/amp/reference/queuing-mode-enumeration.md)|Especifica os modos de enfileiramento de mensagens que são compatíveis com o acelerador.|  
  
### <a name="operators"></a>Operadores  
  
|Operador|Descrição|  
|--------------|-----------------|  
|[operador = = operador (C++ AMP)](../Topic/operator==%20Operator%20\(C++%20AMP\).md)|Determina se as estruturas de dados especificado são iguais.|  
|[operador! = operador (C++ AMP)](../Topic/operator!=%20Operator%20\(C++%20AMP\).md)|Determina se as estruturas de dados especificado são diferentes.|  
|[operador Operator + (C++ AMP)](../Topic/operator+%20Operator%20\(C++%20AMP\).md)|Calcula a soma de component-wise dos argumentos especificados.|  
|[Operador (C++ AMP)](../Topic/operator-%20Operator%20\(C++%20AMP\)1.md)|Calcula a diferença component-wise entre os argumentos especificados.|  
|[operador * operador (C++ AMP)](../Topic/operator*%20Operator%20\(C++%20AMP\).md)|Calcula o produto component-wise dos argumentos especificados.|  
|[operador / operador (C++ AMP)](../Topic/operator-%20Operator%20\(C++%20AMP\)2.md)|Calcula o quociente component-wise dos argumentos especificados.|  
|[operador Operator % (C++ AMP)](../Topic/operator%25%20Operator%20\(C++%20AMP\).md)|Calcula o módulo do primeiro argumento especificado pelo segundo argumento especificado.|  
  
### <a name="functions"></a>Funções  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Função all_memory_fence](../Topic/all_memory_fence%20Function.md)|Bloqueia a execução de todos os threads em um bloco até que todos os acessos de memória foram concluídos.|  
|[Função amp_uninitialize](../Topic/amp_uninitialize%20Function.md)|O tempo de execução C++ AMP cancela a inicialização.|  
|[Função atomic_compare_exchange](../Topic/atomic_compare_exchange%20Function.md)|Sobrecarregado. Se o valor armazenado no local especificado compara igual ao valor especificado primeiro, o segundo valor especificado é armazenado no mesmo local como uma operação atômica.|  
|[Função atomic_exchange](../Topic/atomic_exchange%20Function%20\(C++%20AMP\).md)|Sobrecarregado. Define o valor armazenado no local especificado para o valor especificado como uma operação atômica.|  
|[Função atomic_fetch_add](../Topic/atomic_fetch_add%20Function%20\(C++%20AMP\).md)|Sobrecarregado. Define o valor armazenado no local especificado para a soma do valor e um valor especificado como uma operação atômica.|  
|[Função atomic_fetch_and](../Topic/atomic_fetch_and%20Function%20\(C++%20AMP\).md)|Sobrecarregado. Define o valor armazenado no local especificado para o bit a bit `and` de valor e um valor especificado como uma operação atômica.|  
|[Função atomic_fetch_dec](../Topic/atomic_fetch_dec%20Function.md)|Sobrecarregado. Diminui o valor armazenado no local especificado e armazena o resultado no mesmo local como uma operação atômica.|  
|[Função atomic_fetch_inc](../Topic/atomic_fetch_inc%20Function.md)|Sobrecarregado. Incrementa o valor armazenado no local especificado e armazena o resultado no mesmo local como uma operação atômica.|  
|[Função atomic_fetch_max](../Topic/atomic_fetch_max%20Function.md)|Sobrecarregado. Define o valor armazenado no local especificado para o maior valor e um valor especificado como uma operação atômica.|  
|[Função atomic_fetch_min](../Topic/atomic_fetch_min%20Function.md)|Sobrecarregado. Define o valor armazenado no local especificado para o menor valor e um valor especificado como uma operação atômica.|  
|[Função atomic_fetch_or](../Topic/atomic_fetch_or%20Function%20\(C++%20AMP\).md)|Sobrecarregado. Define o valor armazenado no local especificado para o bit a bit `or` de valor e um valor especificado como uma operação atômica.|  
|[Função atomic_fetch_sub](../Topic/atomic_fetch_sub%20Function%20\(C++%20AMP\).md)|Sobrecarregado. Define o valor armazenado no local especificado para a diferença de valor e um valor especificado como uma operação atômica.|  
|[Função atomic_fetch_xor](../Topic/atomic_fetch_xor%20Function%20\(C++%20AMP\).md)|Sobrecarregado. Define o valor armazenado no local especificado para o bit a bit `xor` de valor e um valor especificado como uma operação atômica.|  
|[Função Copy](../Topic/copy%20Function.md)|Copia um objeto C++ AMP. Todos os requisitos de transferência de dados síncrona são atendidos. Não não possível copiar dados quando o código será executado o código em um acelerador. A forma geral dessa função é `copy(src, dest)`.|  
|[Função copy_async](../Topic/copy_async%20Function.md)|Copia um objeto C++ AMP e retorna [completion_future](../Topic/completion_future%20Class.md) que pode ser aguardado. Dados não podem ser copiados quando o código está sendo executado em um acelerador. A forma geral dessa função é `copy(src, dest)`.|  
|[Função direct3d_abort](../Topic/direct3d_abort%20Function.md)|Anula a execução de uma função que tem o `restrict(amp)` cláusula de restrição.|  
|[Função direct3d_errorf](../Topic/direct3d_errorf%20Function.md)|Imprime uma cadeia de caracteres formatada para o Visual Studio **saída** janela e gera um [runtime_exception](../Topic/runtime_exception%20Class.md) exceção que possui a mesma formatação de cadeia de caracteres.|  
|[Função direct3d_printf](../Topic/direct3d_printf%20Function.md)|Imprime uma cadeia de caracteres formatada para o Visual Studio **saída** janela. Ele é chamado de uma função que tem o `restrict(amp)` cláusula de restrição.|  
|[Função global_memory_fence](../Topic/global_memory_fence%20Function.md)|Bloqueia a execução de todos os threads em um bloco até que toda a memória global acessa foram concluídas.|  
|[Função parallel_for_each (C++ AMP)](../Topic/parallel_for_each%20Function%20\(C++%20AMP\).md)|Executa uma função em todo o domínio de computação.|  
|[Função tile_static_memory_fence](../Topic/tile_static_memory_fence%20Function.md)|Bloqueia a execução de todos os threads em um bloco até `tile_static` acessos de memória foram concluídos.|  
  
## <a name="constants"></a>Constantes  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Constante HLSL_MAX_NUM_BUFFERS](../Topic/HLSL_MAX_NUM_BUFFERS%20Constant.md)|O número máximo de buffers permitido pelo DirectX.|  
|[Constante MODULENAME_MAX_LENGTH](../Topic/MODULENAME_MAX_LENGTH%20Constant.md)|Armazena o comprimento máximo do nome do módulo. Esse valor deve ser o mesmo no compilador e o tempo de execução.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp.h  
  
## <a name="see-also"></a>Consulte também  
 [Referência (C++ AMP)](../../../parallel/amp/reference/reference-cpp-amp.md)



