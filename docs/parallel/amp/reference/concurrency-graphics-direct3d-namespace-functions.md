---
title: Funções de namespace Concurrency::Graphics::Direct3D | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- amp_graphics/Concurrency::graphics::direct3d::get_sampler
- amp_graphics/Concurrency::graphics::direct3d::make_sampler
- amp_graphics/Concurrency::graphics::direct3d::make_texture
dev_langs:
- C++
ms.assetid: 11ee1d42-333e-4ae9-95ac-4cf68c06d13d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2ed95ed8df8a42dc62684c71a3005c2f33fecd18
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33686328"
---
# <a name="concurrencygraphicsdirect3d-namespace-functions"></a>Funções de namespace Concurrency::Graphics::Direct3D
||||  
|-|-|-|  
|[get_sampler](#get_sampler)|[get_texture](#get_texture)|[make_sampler](#make_sampler)|  
|[make_texture](#make_texture)|[msad4](#msad4)|  

 
##  <a name="get_sampler"></a>  get_sampler  
 Obter a interface de estado de amostra D3D do Accelerator determinado exibir que representa o objeto de amostra especificado.  
  
```  
IUnknown* get_sampler(
    const Concurrency::accelerator_view& _Av,  
    const sampler& _Sampler) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Av`  
 Uma exibição de acelerador D3D no qual o estado de amostra D3D será criado.  
  
 `_Sampler`  
 Um objeto de amostra para o qual a interface de estado de amostra D3D subjacente é criada.  
  
### <a name="return-value"></a>Valor de retorno  
 O ponteiro de interface IUnknown correspondente para o estado de amostra D3D que representa o classificador especificado.  
  
##  <a name="get_texture"></a>  get_texture  
 Obtém a interface de textura Direct3D subjacente especificado [textura](texture-class.md) objeto.  
  
```  
template<
    typename value_type,  
    int _Rank  
>  
_Ret_ IUnknown *get_texture(
    const texture<value_type, _Rank>& _Texture) restrict(cpu);

 
template<
    typename value_type,  
    int _Rank  
>  
_Ret_ IUnknown *get_texture(
    const writeonly_texture_view<value_type, _Rank>& _Texture) restrict(cpu);

 
template<
    typename value_type,  
    int _Rank  
>  
_Ret_ IUnknown *get_texture(
    const texture_view<value_type, _Rank>& _Texture) restrict(cpu);

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `value_type`  
 O tipo de elemento da textura.  
  
 `_Rank`  
 A classificação da textura.  
  
 `_Texture`  
 Uma textura ou um modo de exibição de textura associado a accelerator_view para o qual a interface de textura Direct3D subjacente é retornada.  
  
### <a name="return-value"></a>Valor de retorno  
 O ponteiro de interface IUnknown correspondente para a textura Direct3D subjacente a textura.  
  
##  <a name="make_sampler"></a>  make_sampler  
 Crie uma amostra de um ponteiro de interface do estado de amostra D3D.  
  
```  
sampler make_sampler(_In_ IUnknown* _D3D_sampler) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_D3D_sampler`  
 Ponteiro de interface IUnknown do estado D3D amostra para criar o classificador de.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma amostra representa o estado de amostra do D3D fornecido.  
  
##  <a name="make_texture"></a>  make_texture  
 Cria um [textura](texture-class.md) objeto usando os parâmetros especificados.  
  
```  
template<
    typename value_type,  
    int _Rank  
>  
texture<value_type, _Rank> make_texture(
    const Concurrency::accelerator_view& _Av,  
    _In_ IUnknown* _D3D_texture,  
    DXGI_FORMAT _View_format = DXGI_FORMAT_UNKNOWN) restrict(cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `value_type`  
 O tipo dos elementos na textura.  
  
 `_Rank`  
 A classificação da textura.  
  
 `_Av`  
 Uma exibição de acelerador D3D no qual a textura será criado.  
  
 `_D3D_texture`  
 Ponteiro de interface IUnknown da textura para criar a textura de D3D.  
  
 `_View_format`  
 O formato DXGI usado para exibições criadas a partir este textura. Passe DXGI_FORMAT_UNKNOWN (o padrão) para obter o formato do formato de _D3D_texture subjacente e value_type desse modelo. O formato fornecido deve ser compatível com o formato de _D3D_texture subjacente.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma textura usando a textura D3D fornecida.  
  
##  <a name="msad4"></a>  msad4  
 Compara um valor de referência de 4 bytes e um valor de 8 bytes de origem e um vetor de 4 somas é acumulado. Cada soma corresponde à soma mascarada de diferenças absolutas de alinhamentos de byte diferente entre o valor de referência e o valor de origem.  
  
```  
inline uint4 msad4(
    uint _Reference,  
    uint2 _Source,  
    uint4 _Accum) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Reference`  
 A matriz de referência de 4 bytes em um valor uint  
  
 `_Source`  
 A matriz de origem de 8 bytes de um vetor de dois valores uint.  
  
 `_Accum`  
 Um vetor de valores de 4 a ser adicionado à soma mascarada de diferenças absolutas de alinhamentos de byte diferente entre o valor de referência e o valor de origem.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um vetor de 4 somas. Cada soma corresponde à soma mascarada de diferenças absolutas de alinhamentos de byte diferente entre o valor de referência e o valor de origem.  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp_graphics.h  
  
 **Namespace:** Concurrency::graphics::direct3d 

## <a name="see-also"></a>Consulte também  
 [Namespace Concurrency::graphics::direct3d](concurrency-graphics-direct3d-namespace.md)
