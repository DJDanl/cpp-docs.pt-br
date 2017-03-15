---
title: 'Namespace Concurrency:: Graphics | Documentos do Microsoft'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- amp_graphics/Concurrency::graphics
- amp_short_vectors/Concurrency::graphics
dev_langs:
- C++
ms.assetid: 4529d3b1-d7da-4ffb-82bf-080915e0f23e
caps.latest.revision: 14
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
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: fd29b427307e336d560a2caf42e4fc5228e8071f
ms.lasthandoff: 02/25/2017

---
# <a name="concurrencygraphics-namespace"></a>Namespace Concurrency::graphics
O namespace de gráficos fornece tipos e funções que são projetadas para programação de gráficos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
namespace graphics;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="namespaces"></a>Namespaces  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Namespace Concurrency::Graphics::Direct3D](concurrency-graphics-direct3d-namespace.md)|Fornece funções para interoperabilidade do Direct3D.|  
  
### <a name="typedefs"></a>Typedefs  
  
|Nome|Descrição|  
|----------|-----------------|  
|`uint`|O tipo de elemento para [classe uint_2](uint-2-class.md), [classe uint_3](uint-3-class.md), e [classe uint_4](uint-4-class.md). Definido como `typedef unsigned int uint;`.|  
  
### <a name="enumerations"></a>Enumerações  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Enumeração address_mode](concurrency-graphics-namespace-enums.md#address_mode).|Especifica os modos de endereço com suporte para amostragem de textura.|  
|[Enumeração filter_mode](concurrency-graphics-namespace-enums.md#filter_mode)|Especifica os modos de filtro com suporte para amostragem de textura.|  
  
### <a name="classes"></a>Classes  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Classe Texture](texture-class.md)|Uma textura é uma agregação em um accelerator_view no domínio do ponto de dados. É uma coleção de variáveis para cada elemento em um domínio de extensão. Cada variável contém um valor correspondente ao tipo primitivo do C++ (unsigned int, int, float, double), ou a norma de tipo escalar ou unorm (definido em Concurrency:: Graphics) ou tipos de vetor curto qualificados definidas no Concurrency:: Graphics.|  
|[Classe writeonly_texture_view](writeonly-texture-view-class.md)|Um writeonly_texture_view fornece acesso writeonly com uma textura.|  
|[Classe double_2](double-2-class.md)|Representa um vetor curto de 2 `double` valores.|  
|[Classe double_3](double-3-class.md)|Representa um vetor curto de 3 `double` valores.|  
|[Classe double_4](double-4-class.md)|Representa um vetor curto de 4 `double` valores.|  
|[Classe float_2](float-2-class.md)|Representa um vetor curto de 2 `float` valores.|  
|[Classe float_3](float-3-class.md)|Representa um vetor curto de 3 `float` valores.|  
|[Classe float_4](float-4-class.md)|Representa um vetor curto de 4 `float` valores.|  
|[Classe int_2](int-2-class.md)|Representa um vetor curto de 2 `int` valores.|  
|[Classe int_3](int-3-class.md)|Representa um vetor curto de 3 `int` valores.|  
|[Classe int_4](int-4-class.md)|Representa um vetor curto de 4 `int` valores.|  
|[Classe norm_2](norm-2-class.md)|Representa um vetor curto de 2 `norm` valores.|  
|[Classe norm_3](norm-3-class.md)|Representa um vetor curto de 3 `norm` valores.|  
|[Classe norm_4](norm-4-class.md)|Representa um vetor curto de 4 `norm` valores.|  
|[Classe uint_2](uint-2-class.md)|Representa um vetor curto de 2 `uint` valores.|  
|[Classe uint_3](uint-3-class.md)|Representa um vetor curto de 3 `uint` valores.|  
|[Classe uint_4](uint-4-class.md)|Representa um vetor curto de 4 `uint` valores.|  
|[Classe unorm_2](unorm-2-class.md)|Representa um vetor curto de 2 `unorm` valores.|  
|[Classe unorm_3](unorm-3-class.md)|Representa um vetor curto de 3 `unorm` valores.|  
|[Classe unorm_4](unorm-4-class.md)|Representa um vetor curto de 4 `unorm` valores.|  
|[Classe de amostra](sampler-class.md)|Representa a configuração de amostra usada para amostragem de textura.|  
|[Estrutura short_vector](short-vector-structure.md)|Fornece uma implementação básica de um vetor curta de valores.|  
|[Estrutura short_vector_traits](short-vector-traits-structure.md)|Fornece para recuperação de comprimento e tipo de um vetor curto.|  
|[Classe texture_view](texture-view-class.md)|Fornece acesso de leitura e gravação para uma textura.|  
  
### <a name="functions"></a>Funções  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Função Copy](concurrency-graphics-namespace-functions.md#copy)|Sobrecarregado. Copia o conteúdo da textura de origem para o buffer do host de destino.|  
|[Função copy_async](concurrency-graphics-namespace-functions.md#copy_async)|Sobrecarregado. Assincronamente copia o conteúdo da textura de origem para o buffer do host de destino.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp_graphics.h  
  
 **Namespace:** Simultaneidade  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)

