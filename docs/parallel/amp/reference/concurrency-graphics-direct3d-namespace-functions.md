---
title: Funções do namespace Concurrency::Graphics::Direct3D
ms.date: 11/04/2016
f1_keywords:
- amp_graphics/Concurrency::graphics::direct3d::get_sampler
- amp_graphics/Concurrency::graphics::direct3d::make_sampler
- amp_graphics/Concurrency::graphics::direct3d::make_texture
ms.assetid: 11ee1d42-333e-4ae9-95ac-4cf68c06d13d
ms.openlocfilehash: c19cc8697820c038875d55b41cde61120bda9df7
ms.sourcegitcommit: afd6fac7c519dbc47a4befaece14a919d4e0a8a2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2018
ms.locfileid: "51518367"
---
# <a name="concurrencygraphicsdirect3d-namespace-functions"></a>Funções do namespace Concurrency::Graphics::Direct3D

||||
|-|-|-|
|[get_sampler](#get_sampler)|[get_texture](#get_texture)|[make_sampler](#make_sampler)|
|[make_texture](#make_texture)|[msad4](#msad4)|

##  <a name="get_sampler"></a>  get_sampler

Obter a interface de estado de amostra D3D no Acelerador determinada exibição que representa o objeto de demonstrador especificado.

```
IUnknown* get_sampler(
    const Concurrency::accelerator_view& _Av,
    const sampler& _Sampler) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Av*<br/>
Uma exibição do acelerador D3D em que o estado de amostra D3D deverá ser criado.

*_Sampler*<br/>
Um objeto de amostra para o qual a interface de estado de amostra D3D subjacente é criada.

### <a name="return-value"></a>Valor de retorno

O ponteiro de interface IUnknown correspondente para o estado de demonstrador de D3D que representa a amostra determinada.

##  <a name="get_texture"></a>  get_texture

Obtém a interface de textura do Direct3D subjacente especificado [textura](texture-class.md) objeto.

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

*value_type*<br/>
O tipo de elemento da textura.

*_Rank*<br/>
A classificação da textura.

*_Texture*<br/>
Uma textura ou o modo de exibição de textura associado ao accelerator_view para o qual a interface de textura do Direct3D subjacente é retornada.

### <a name="return-value"></a>Valor de retorno

O ponteiro de interface IUnknown correspondente a textura Direct3D subjacente à textura.

##  <a name="make_sampler"></a>  make_sampler

Crie uma amostra de um ponteiro de interface de estado de amostra D3D.

```
sampler make_sampler(_In_ IUnknown* _D3D_sampler) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_D3D_sampler*<br/>
Ponteiro de interface IUnknown o estado de amostra de D3D para criar a amostra do.

### <a name="return-value"></a>Valor de retorno

Uma amostra representa o estado de amostra D3D fornecido.

##  <a name="make_texture"></a>  make_texture

Cria uma [textura](texture-class.md) objeto usando os parâmetros especificados.

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

*value_type*<br/>
O tipo dos elementos na textura.

*_Rank*<br/>
A classificação da textura.

*_Av*<br/>
Uma exibição do acelerador D3D em que a textura deverá ser criado.

*_D3D_texture*<br/>
Ponteiro de interface IUnknown de textura para criar a textura do D3D.

*_View_format*<br/>
O formato DXGI a ser usado para visualizações criadas a partir dessa textura. Passe DXGI_FORMAT_UNKNOWN (o padrão) para derivar o formato do formato subjacente de _D3D_texture e o value_type desse modelo. O formato fornecido deve ser compatível com o formato subjacente de _D3D_texture.

### <a name="return-value"></a>Valor de retorno

Uma textura usando a textura D3D fornecida.

##  <a name="msad4"></a>  msad4

Compara um valor de referência de 4 bytes e um valor de origem de 8 bytes e acumula um vetor de 4 somas. Cada soma corresponde à soma mascarada das diferenças absolutas de alinhamentos diferentes de bytes entre o valor de referência e o valor de origem.

```
inline uint4 msad4(
    uint _Reference,
    uint2 _Source,
    uint4 _Accum) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*Referência*<br/>
A matriz de referência de 4 bytes em um valor de uint

*_Source*<br/>
A matriz de origem de 8 bytes em um vetor de dois valores de uint.

*_Accum*<br/>
Um vetor de 4 valores a serem adicionados à soma mascarada das diferenças absolutas de alinhamentos diferentes de bytes entre o valor de referência e o valor de origem.

### <a name="return-value"></a>Valor de retorno

Retorna um vetor de 4 somas. Cada soma corresponde à soma mascarada das diferenças absolutas de alinhamentos diferentes de bytes entre o valor de referência e o valor de origem.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amp_graphics. h

**Namespace:** Concurrency::graphics::direct3d

## <a name="see-also"></a>Consulte também

[Namespace Concurrency::graphics::direct3d](concurrency-graphics-direct3d-namespace.md)
