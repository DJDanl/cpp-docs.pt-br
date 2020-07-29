---
title: Namespace Concurrency::graphics
ms.date: 11/04/2016
f1_keywords:
- AMP_GRAPHICS/Concurrency
ms.assetid: 4529d3b1-d7da-4ffb-82bf-080915e0f23e
ms.openlocfilehash: 942b3bbace85fa297bba6cd4b509f67006a4aed3
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226731"
---
# <a name="concurrencygraphics-namespace"></a>Namespace Concurrency::graphics

O namespace de gráficos fornece tipos e funções que são projetados para programação de gráficos.

## <a name="syntax"></a>Sintaxe

```cpp
namespace graphics;
```

## <a name="members"></a>Membros

### <a name="namespaces"></a>Namespaces

|Nome|Descrição|
|----------|-----------------|
|[Concurrency:: Graphics::d namespace irect3d](concurrency-graphics-direct3d-namespace.md)|Fornece funções para o Direct3D Interop.|

### <a name="typedefs"></a>Typedefs

|Nome|Descrição|
|----------|-----------------|
|`uint`|O tipo de elemento para classe de [uint_2](uint-2-class.md), classe de [uint_3](uint-3-class.md)e [classe de uint_4](uint-4-class.md). Definido como `typedef unsigned int uint;`.|

### <a name="enumerations"></a>Enumerações

|Nome|Descrição|
|----------|-----------------|
|[enumeração de address_mode](concurrency-graphics-namespace-enums.md#address_mode).|Especifica os modos de endereço com suporte para amostragem de textura.|
|[Enumeração filter_mode](concurrency-graphics-namespace-enums.md#filter_mode)|Especifica os modos de filtro com suporte para amostragem de textura.|

### <a name="classes"></a>Classes

|Nome|Descrição|
|----------|-----------------|
|[Classe de textura](texture-class.md)|Uma textura é uma agregação de dados em um accelerator_view no domínio de extensão. É uma coleção de variáveis, uma para cada elemento em um domínio de extensão. Cada variável contém um valor correspondente ao tipo primitivo do C++ (não assinado int, int, float, Double) ou Scalar do tipo escalar ou unorm (definido em Concurrency:: Graphics) ou tipos de vetores curtos qualificados definidos em Concurrency:: Graphics.|
|[Classe writeonly_texture_view](writeonly-texture-view-class.md)|Um writeonly_texture_view fornece acesso de WriteOnly a uma textura.|
|[Classe double_2](double-2-class.md)|Representa um pequeno vetor de dois **`double`** valores.|
|[Classe double_3](double-3-class.md)|Representa um pequeno vetor de 3 **`double`** valores.|
|[Classe double_4](double-4-class.md)|Representa um pequeno vetor de quatro **`double`** valores.|
|[Classe float_2](float-2-class.md)|Representa um pequeno vetor de dois **`float`** valores.|
|[Classe float_3](float-3-class.md)|Representa um pequeno vetor de 3 **`float`** valores.|
|[Classe float_4](float-4-class.md)|Representa um pequeno vetor de quatro **`float`** valores.|
|[Classe int_2](int-2-class.md)|Representa um pequeno vetor de dois **`int`** valores.|
|[Classe int_3](int-3-class.md)|Representa um pequeno vetor de 3 **`int`** valores.|
|[Classe int_4](int-4-class.md)|Representa um pequeno vetor de quatro **`int`** valores.|
|[Classe norm_2](norm-2-class.md)|Representa um pequeno vetor de dois `norm` valores.|
|[Classe norm_3](norm-3-class.md)|Representa um pequeno vetor de 3 `norm` valores.|
|[Classe norm_4](norm-4-class.md)|Representa um pequeno vetor de quatro `norm` valores.|
|[Classe uint_2](uint-2-class.md)|Representa um pequeno vetor de dois `uint` valores.|
|[Classe uint_3](uint-3-class.md)|Representa um pequeno vetor de 3 `uint` valores.|
|[Classe uint_4](uint-4-class.md)|Representa um pequeno vetor de quatro `uint` valores.|
|[Classe unorm_2](unorm-2-class.md)|Representa um pequeno vetor de dois `unorm` valores.|
|[Classe unorm_3](unorm-3-class.md)|Representa um pequeno vetor de 3 `unorm` valores.|
|[Classe unorm_4](unorm-4-class.md)|Representa um pequeno vetor de quatro `unorm` valores.|
|[Classe de amostra](sampler-class.md)|Representa a configuração de amostra usada para amostragem de textura.|
|[Estrutura short_vector](short-vector-structure.md)|Fornece uma implementação básica de um pequeno vetor de valores.|
|[Estrutura short_vector_traits](short-vector-traits-structure.md)|Fornece a recuperação do comprimento e do tipo de um vetor curto.|
|[Classe texture_view](texture-view-class.md)|Fornece acesso de leitura e acesso de gravação a uma textura.|

### <a name="functions"></a>Funções

|Nome|Descrição|
|----------|-----------------|
|[copy](concurrency-graphics-namespace-functions.md#copy)|Sobrecarregado. Copia o conteúdo da textura de origem no buffer do host de destino.|
|[copy_async](concurrency-graphics-namespace-functions.md#copy_async)|Sobrecarregado. Copia de forma assíncrona o conteúdo da textura de origem para o buffer de host de destino.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amp_graphics. h

**Namespace:** Simultaneidade

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
