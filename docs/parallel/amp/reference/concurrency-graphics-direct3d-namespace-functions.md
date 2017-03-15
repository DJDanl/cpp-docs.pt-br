---
title: "Funções de namespace Concurrency::Graphics::Direct3D | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 11ee1d42-333e-4ae9-95ac-4cf68c06d13d
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: aa7e91237eaa9ced297e2c5748359c23bb436df8
ms.lasthandoff: 02/25/2017

---
# <a name="concurrencygraphicsdirect3d-namespace-functions"></a>Funções de namespace Concurrency::Graphics::Direct3D
||||  
|-|-|-|  
|[Função get_sampler](#get_sampler)|[Função get_texture](#get_texture)|[Função make_sampler](#make_sampler)|  
|[Função make_texture](#make_texture)|[Função msad4](#msad4)|  
  
##  <a name="a-namegetsamplera--getsampler-function"></a><a name="get_sampler"></a>Função get_sampler  
 Obter a interface de estado de amostra D3D no Acelerador de determinado exibir que representa o objeto de amostra especificado.  
  
```  
IUnknown* get_sampler(
    const Concurrency::accelerator_view& _Av,  
    const sampler& _Sampler) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Av`  
 Uma exibição de acelerador D3D no qual o estado de amostra D3D deve ser criado.  
  
 `_Sampler`  
 Um objeto de amostra para o qual a interface de estado de amostra D3D subjacente é criada.  
  
### <a name="return-value"></a>Valor de retorno  
 O ponteiro de interface IUnknown correspondente para o estado de amostra D3D que representa o classificador de determinado.  
  
##  <a name="a-namegettexturea--gettexture-function"></a><a name="get_texture"></a>Função get_texture  
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
 Uma textura ou exibição de textura associados a accelerator_view para que a interface de textura Direct3D subjacente é retornada.  
  
### <a name="return-value"></a>Valor de retorno  
 O ponteiro de interface IUnknown correspondente para a textura do Direct3D subjacente a textura.  
  
##  <a name="a-namemakesamplera--makesampler-function"></a><a name="make_sampler"></a>Função make_sampler  
 Crie uma amostra de um ponteiro de interface D3D estado de amostra.  
  
```  
sampler make_sampler(_In_ IUnknown* _D3D_sampler) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_D3D_sampler`  
 Ponteiro de interface IUnknown do estado para criar o classificador de amostra D3D.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma amostra representa o estado de amostra do D3D fornecido.  
  
##  <a name="a-namemaketexturea--maketexture-function"></a><a name="make_texture"></a>Função make_texture  
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
 Uma exibição de acelerador D3D em que a textura deve ser criado.  
  
 `_D3D_texture`  
 Ponteiro de interface IUnknown da textura D3D para criar a textura de.  
  
 `_View_format`  
 O formato DXGI para usar para exibições criadas a partir esse textura. Passe DXGI_FORMAT_UNKNOWN (o padrão) para derivar o formato de formato subjacente de _D3D_texture e value_type deste modelo. O formato fornecido deve ser compatível com o formato subjacente do _D3D_texture.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma textura usando a textura D3D fornecida.  
  
##  <a name="a-namemsad4a--msad4-function"></a><a name="msad4"></a>Função msad4  
 Compara um valor de referência de 4 bytes e um valor de origem de 8 bytes e um vetor de 4 somas é acumulado. Cada soma corresponde à soma das diferenças absolutas de alinhamentos diferentes de bytes entre o valor de referência e o valor de origem mascarada.  
  
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
 A matriz de origem de 8 bytes em um vetor de dois valores uint.  
  
 `_Accum`  
 Um vetor de valores de 4 a ser adicionado à soma das diferenças absolutas dos alinhamentos diferentes de bytes entre o valor de referência e o valor de origem mascarada.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um vetor de 4 somas. Cada soma corresponde à soma das diferenças absolutas de alinhamentos diferentes de bytes entre o valor de referência e o valor de origem mascarada.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Concurrency::Graphics::Direct3D](concurrency-graphics-direct3d-namespace.md)

