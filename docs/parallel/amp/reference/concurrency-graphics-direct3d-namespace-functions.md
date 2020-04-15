---
title: Funções do namespace Concurrency::graphics::direct3d
ms.date: 11/04/2016
f1_keywords:
- amp_graphics/Concurrency::graphics::direct3d::get_sampler
- amp_graphics/Concurrency::graphics::direct3d::make_sampler
- amp_graphics/Concurrency::graphics::direct3d::make_texture
ms.assetid: 11ee1d42-333e-4ae9-95ac-4cf68c06d13d
ms.openlocfilehash: 330c1aa94b1d122901fc23576686032400249d31
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376385"
---
# <a name="concurrencygraphicsdirect3d-namespace-functions"></a>Funções do namespace Concurrency::graphics::direct3d

||||
|-|-|-|
|[get_sampler](#get_sampler)|[get_texture](#get_texture)|[make_sampler](#make_sampler)|
|[make_texture](#make_texture)|[msad4](#msad4)|

## <a name="get_sampler"></a><a name="get_sampler"></a>get_sampler

Obtenha a interface de estado do sampler D3D na exibição do acelerador que representa o objeto amostrador especificado.

```cpp
IUnknown* get_sampler(
    const Concurrency::accelerator_view& _Av,
    const sampler& _Sampler) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Av*<br/>
Uma visão do acelerador D3D na qual o estado do sampler D3D deve ser criado.

*_Sampler*<br/>
Um objeto amostrador para o qual a interface de estado do sampler D3D subjacente é criada.

### <a name="return-value"></a>Valor retornado

O ponteiro de interface IUnknown correspondente ao estado do sampler D3D que representa o sampler dado.

## <a name="get_texture"></a><a name="get_texture"></a>get_texture

Obtém a interface de textura Direct3D subjacente ao objeto de [textura](texture-class.md) especificado.

```cpp
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

*Value_type*<br/>
O tipo de elemento da textura.

*_Rank*<br/>
A posição da textura.

*_Texture*<br/>
Uma visão de textura ou textura associada à accelerator_view para a qual a interface de textura Direct3D subjacente é devolvida.

### <a name="return-value"></a>Valor retornado

O ponteiro de interface IUnknown correspondente à textura Direct3D subjacente à textura.

## <a name="make_sampler"></a><a name="make_sampler"></a>make_sampler

Crie um sampler a partir de um ponteiro de interface de estado de sampler D3D.

```cpp
sampler make_sampler(_In_ IUnknown* _D3D_sampler) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_D3D_sampler*<br/>
Ponteiro de interface IUnknown do estado do sampler D3D para criar o sampler de.

### <a name="return-value"></a>Valor retornado

Um sampler representa o estado do amostrador D3D fornecido.

## <a name="make_texture"></a><a name="make_texture"></a>make_texture

Cria um objeto [de textura](texture-class.md) usando os parâmetros especificados.

```cpp
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

*Value_type*<br/>
O tipo de elementos na textura.

*_Rank*<br/>
A posição da textura.

*_Av*<br/>
Uma visão do acelerador D3D na qual a textura deve ser criada.

*_D3D_texture*<br/>
Ponteiro de interface IUnknown da textura D3D para criar a textura a partir de.

*_View_format*<br/>
O formato DXGI para usar para visualizações criadas a partir desta textura. Passe DXGI_FORMAT_UNKNOWN (o padrão) para derivar o formato do formato subjacente de _D3D_texture e o value_type deste modelo. O formato fornecido deve ser compatível com o formato subjacente de _D3D_texture.

### <a name="return-value"></a>Valor retornado

Uma textura usando a textura D3D fornecida.

## <a name="msad4"></a><a name="msad4"></a>msad4

Compara um valor de referência de 4 bytes e um valor de origem de 8 bytes e acumula um vetor de 4 somas. Cada soma corresponde à soma mascarada de diferenças absolutas de diferentes alinhamentos de bytes entre o valor de referência e o valor de origem.

```cpp
inline uint4 msad4(
    uint _Reference,
    uint2 _Source,
    uint4 _Accum) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Reference*<br/>
A matriz de referência de 4 bytes em um valor uint

*_Source*<br/>
A matriz de origem de 8 bytes em um vetor de dois valores uint.

*_Accum*<br/>
Um vetor de 4 valores a serem adicionados à soma mascarada das diferenças absolutas dos diferentes alinhamentos de bytes entre o valor de referência e o valor de origem.

### <a name="return-value"></a>Valor retornado

Retorna um vetor de 4 somas. Cada soma corresponde à soma mascarada de diferenças absolutas de diferentes alinhamentos de bytes entre o valor de referência e o valor de origem.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amp_graphics.h

**Espaço de nome:** Concorrência::gráficos::direct3d

## <a name="see-also"></a>Confira também

[Namespace Concurrency::graphics::direct3d](concurrency-graphics-direct3d-namespace.md)
