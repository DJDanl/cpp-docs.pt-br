---
title: Classe de amostra | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- sampler
- AMP_GRAPHICS/sampler
- AMP_GRAPHICS/concurrency::sampler::graphics::sampler
- AMP_GRAPHICS/concurrency::sampler::graphics::get_address_mode
- AMP_GRAPHICS/concurrency::sampler::graphics::get_border_color
- AMP_GRAPHICS/concurrency::sampler::graphics::get_filter_mode
- AMP_GRAPHICS/concurrency::sampler::graphics::address_mode
- AMP_GRAPHICS/concurrency::sampler::graphics::border_color
- AMP_GRAPHICS/concurrency::sampler::graphics::filter_mode
dev_langs:
- C++
ms.assetid: 9a6a9807-497d-402d-b092-8c4d86275b80
caps.latest.revision: 7
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
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: f81208e40cb2a211b714af1efe801e81cd567374
ms.lasthandoff: 03/17/2017

---
# <a name="sampler-class"></a>Classe de amostra
A classe de amostra agrega informações de configuração de amostragem a ser usado para amostragem de textura.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class sampler;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[amostra de construtor](#ctor)|Sobrecarregado. Cria uma instância de amostra.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[get_address_mode](#get_address_mode)|Retorna o `address_mode` que foi associado ao objeto de amostra.|  
|[get_border_color](#get_border_color)|Retorna a cor da borda que está associado com o objeto de amostra.|  
|[get_filter_mode](#get_filter_mode)|Retorna o `filter_mode` que foi associado ao objeto de amostra.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operator=](#operator_eq)|Sobrecarregado. Operador de atribuição.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[address_mode](#address_mode)|Obtém o modo de endereço do `sampler` objeto.|  
|[border_color](#border_color)|Obtém a cor da borda do `sampler` objeto.|  
|[filter_mode](#filter_mode)|Obtém o modo de filtro do `sampler` objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `sampler`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp_graphics.h  
  
 **Namespace:** Concurrency:: Graphics  
  
##  <a name="ctor"></a>amostra de 

 Constrói uma instância do [classe de amostra](sampler-class.md).  
  
```  
sampler() restrict(cpu);

 *// [1] default constructor  
 
sampler(// [2] constructor  
    filter_mode _Filter_mode) restrict(cpu);

 
sampler(// [3] constructor  
    address_mode _Address_mode,  
    float_4 _Border_color = float_4(0.0f,
    0.0f,
    0.0f,
    0.0f)) restrict(cpu);

 
sampler(// [4] constructor  
    filter_mode _Filter_mode,  
    address_mode _Address_mode,  
    float_4 _Border_color = float_4(0.0f,
    0.0f,
    0.0f,
    0.0f)) restrict(cpu);

 
sampler(// [5] copy constructor  
    const sampler& _Other) restrict(amp,
    cpu);

 
sampler(// [6] move constructor  
    sampler&& _Other) restrict(amp,
    cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Filter_mode`  
 O modo de filtragem a ser usado na amostragem.  
  
 `_Address_mode`  
 O modo de endereçamento a ser usado em amostragem para todas as dimensões.  
  
 `_Border_color`  
 A cor da borda a ser usada se o modo de endereço é address_border. O valor padrão é `float_4(0.0f, 0.0f, 0.0f, 0.0f)`.  
  
 `_Other`  
 [5] construtor de cópia  
 O `sampler` objeto a ser copiado no novo `sampler` instância.  
  
 [6] construtor de movimentação  
 O `sampler` objeto se mova para a nova `sampler` instância.  
  
##  <a name="address_mode"></a>address_mode 

 Obtém o modo de endereço do `sampler` objeto.  
  
```  
__declspec(property(get= get_address_mode)) Concurrency::graphics::address_mode address_mode;  
```  
  
##  <a name="border_color"></a>border_color 

 Obtém a cor da borda do `sampler` objeto.  
  
```  
__declspec(property(get= get_border_color)) Concurrency::graphics::float_4 border_color;  
```  
  
##  <a name="filter_mode"></a>filter_mode 

 Obtém o modo de filtro do `sampler` objeto.  
  
```  
__declspec(property(get= get_filter_mode)) Concurrency::graphics::filter_mode filter_mode;  
```  
  
##  <a name="get_address_mode"></a>get_address_mode 

 Retorna o modo de filtro que está configurado para este `sampler`.  
  
```  
Concurrency::graphics::address_mode get_address_mode() const __GPU;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O modo de endereço que está configurado para a amostra.  
  
##  <a name="get_border_color"></a>get_border_color 

 Retorna a cor da borda que está configurada para este `sampler`.  
  
```  
Concurrency::graphics::float_4 get_border_color() const restrict(amp, cpu);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um float_4 que contém a cor da borda.  
  
##  <a name="get_filter_mode"></a>get_filter_mode 

 Retorna o modo de filtro que está configurado para este `sampler`.  
  
```  
Concurrency::graphics::filter_mode get_filter_mode() const restrict(amp, cpu);
```  
  
### <a name="return-value"></a>Valor de retorno  
 O modo de filtro que está configurado para a amostra.  
  
##  <a name="operator_eq"></a>operador = 

 Atribui o valor de outro objeto de amostra para uma amostra existente.  
  
```  
sampler& operator= (// [1] copy assignment operator const sampler& _Other) restrict(amp,
    cpu);

 
sampler& operator= (// [2] move assingment operator sampler&& _Other) restrict(amp,
    cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 [1] operador de atribuição de cópia  
 O `sampler` objeto a ser copiado no `sampler`.  
  
 [2] operador de atribuição de movimentação  
 O `sampler` objeto se mova em isso `sampler`.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a essa instância de amostra.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Concurrency::graphics](concurrency-graphics-namespace.md)

