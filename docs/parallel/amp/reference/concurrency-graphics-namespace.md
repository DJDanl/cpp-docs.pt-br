---
title: "Namespace Concurrency::graphics | Microsoft Docs"
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
  - "amp_graphics/Concurrency::graphics"
  - "amp_short_vectors/Concurrency::graphics"
dev_langs: 
  - "C++"
ms.assetid: 4529d3b1-d7da-4ffb-82bf-080915e0f23e
caps.latest.revision: 14
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Namespace Concurrency::graphics
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

O namespace de elementos gráficos fornece tipos e funções projetadas para a programação de elementos gráficos.  
  
## Sintaxe  
  
```  
namespace graphics;  
```  
  
## Membros  
  
### Namespaces  
  
|Nome|Descrição|  
|----------|---------------|  
|[Namespace Concurrency::graphics::direct3d](../../../parallel/amp/reference/concurrency-graphics-direct3d-namespace.md)|Fornece funções para a interoperabilidade de Direct3D.|  
  
### Typedefs  
  
|Nome|Descrição|  
|----------|---------------|  
|`uint`|O tipo de elemento para [Classe uint\_2](../../../parallel/amp/reference/uint-2-class.md), [Classe uint\_3](../../../parallel/amp/reference/uint-3-class.md), e [Classe uint\_4](../../../parallel/amp/reference/uint-4-class.md).  Definido como `typedef unsigned int uint;`.|  
  
### Enumerações  
  
|Nome|Descrição|  
|----------|---------------|  
|[Enumeração address\_mode](../Topic/address_mode%20Enumeration.md)|Especifica modos de endereço com suporte para a amostragem de textura.|  
|[Enumeração filter\_mode](../Topic/filter_mode%20Enumeration.md)|Especifica modos de filtro com suporte para a amostragem de textura.|  
  
### Classes  
  
|Nome|Descrição|  
|----------|---------------|  
|[Classe texture](../Topic/texture%20Class.md)|Uma textura é um agregado de dados em um accelerator\_view no domínio de extensão.  É uma coleção de variáveis, uma para cada elemento em um domínio de extensão.  Cada variável contém um valor correspondente a um tipo primitivo em C\+\+ \(unsigned int, int, float, double\), ou a um tipo escalar norm, ou unorm \(definido em concurrency::graphics\) ou a um tipo de vetor curto qualificado definido em concurrency::graphics.|  
|[Classe writeonly\_texture\_view](../Topic/writeonly_texture_view%20Class.md)|Um writeonly\_texture\_view fornece acesso somente\-escrita para uma textura.|  
|[Classe double\_2](../Topic/double_2%20Class.md)|Representa um vetor curto de 2 valores `double`.|  
|[Classe double\_3](../../../parallel/amp/reference/double-3-class.md)|Representa um vetor curto de 3 valores `double`.|  
|[Classe double\_4](../Topic/double_4%20Class.md)|Representa um vetor curto de 4 valores `double`.|  
|[Classe float\_2](../../../parallel/amp/reference/float-2-class.md)|Representa um vetor curto de 2 valores `float`.|  
|[Classe float\_3](../../../parallel/amp/reference/float-3-class.md)|Representa um vetor curto de 3 valores `float`.|  
|[Classe float\_4](../../../parallel/amp/reference/float-4-class.md)|Representa um vetor curto de 4 valores `float`.|  
|[Classe int\_2](../Topic/int_2%20Class.md)|Representa um vetor curto de 2 valores `int`.|  
|[Classe int\_3](../../../parallel/amp/reference/int-3-class.md)|Representa um vetor curto de 3 valores `int`.|  
|[Classe int\_4](../../../parallel/amp/reference/int-4-class.md)|Representa um vetor curto de 4 valores `int`.|  
|[Classe norm\_2](../../../parallel/amp/reference/norm-2-class.md)|Representa um vetor curto de 2 valores `norm`.|  
|[Classe norm\_3](../../../parallel/amp/reference/norm-3-class.md)|Representa um vetor curto de 3 valores `norm`.|  
|[Classe norm\_4](../../../parallel/amp/reference/norm-4-class.md)|Representa um vetor curto de 4 valores `norm`.|  
|[Classe uint\_2](../../../parallel/amp/reference/uint-2-class.md)|Representa um vetor curto de 2 valores `uint`.|  
|[Classe uint\_3](../../../parallel/amp/reference/uint-3-class.md)|Representa um vetor curto de 3 valores `uint`.|  
|[Classe uint\_4](../../../parallel/amp/reference/uint-4-class.md)|Representa um vetor curto de 4 valores `uint`.|  
|[Classe unorm\_2](../../../parallel/amp/reference/unorm-2-class.md)|Representa um vetor curto de 2 valores `unorm`.|  
|[Classe unorm\_3](../../../parallel/amp/reference/unorm-3-class.md)|Representa um vetor curto de 3 valores `unorm`.|  
|[Classe unorm\_4](../../../parallel/amp/reference/unorm-4-class.md)|Representa um vetor curto de 4 valores `unorm`.|  
|[Classe de amostra](../../../parallel/amp/reference/sampler-class.md)|Representa a configuração de amostra usada para amostragem de textura.|  
|[Estrutura short\_vector](../../../parallel/amp/reference/short-vector-structure.md)|Fornece uma implementação básica de um vetor curto de valores.|  
|[Estrutura short\_vector\_traits](../../../parallel/amp/reference/short-vector-traits-structure.md)|Fornece recuperação do comprimento e tipo de um vetor curto.|  
|[Classe texture\_view](../../../parallel/amp/reference/texture-view-class.md)|Fornece acesso de leitura e acesso de gravação a uma textura.|  
  
### Funções  
  
|Nome|Descrição|  
|----------|---------------|  
|[Função copy](../Topic/copy%20Function.md)|Sobrecarregado.  Copia o conteúdo da textura de origem para o buffer do host de destino.|  
|[Função copy\_async](../Topic/copy_async%20Function.md)|Sobrecarregado.  Copia assincronamente o conteúdo da textura de origem para o buffer do host de destino.|  
  
## Requisitos  
 **Cabeçalho:** amp\_graphics.h  
  
 **Namespace:** Simultaneidade  
  
## Consulte também  
 [Namespace Concurrency \(C\+\+ AMP\)](../../../parallel/amp/reference/concurrency-namespace-cpp-amp.md)