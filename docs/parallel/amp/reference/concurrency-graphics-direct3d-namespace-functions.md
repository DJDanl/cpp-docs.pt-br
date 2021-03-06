---
title: Funções do namespace Concurrency::graphics::direct3d
ms.date: 11/04/2016
f1_keywords:
- amp_graphics/Concurrency::graphics::direct3d::get_sampler
- amp_graphics/Concurrency::graphics::direct3d::make_sampler
- amp_graphics/Concurrency::graphics::direct3d::make_texture
ms.assetid: 11ee1d42-333e-4ae9-95ac-4cf68c06d13d
ms.openlocfilehash: 66db1d348c6c58a9226322b51662ef7a4ef75b3d
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88841287"
---
# <a name="concurrencygraphicsdirect3d-namespace-functions"></a>Funções do namespace Concurrency::graphics::direct3d

:::row:::
   :::column span="":::
      [`get_sampler`](#get_sampler)\
      [`get_texture`](#get_texture)
   :::column-end:::
   :::column span="":::
      [`make_sampler`](#make_sampler)
   :::column-end:::
   :::column span="":::
      [`make_texture`](#make_texture)
   :::column-end:::
   :::column span="":::
      [`msad4`](#msad4)
   :::column-end:::
:::row-end:::

## <a name="get_sampler"></a><a name="get_sampler"></a> get_sampler

Obtenha a interface de estado de amostra do D3D no modo de exibição de acelerador fornecido que representa o objeto de amostra especificado.

```cpp
IUnknown* get_sampler(
    const Concurrency::accelerator_view& _Av,
    const sampler& _Sampler) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_Av*<br/>
Uma exibição do acelerador D3D na qual o estado de amostra do D3D deve ser criado.

*_Sampler*<br/>
Um objeto de amostra para o qual a interface de estado de amostra D3D subjacente é criada.

### <a name="return-value"></a>Valor Retornado

O ponteiro de interface IUnknown correspondente ao estado de amostra do D3D que representa a amostra fornecida.

## <a name="get_texture"></a><a name="get_texture"></a> get_texture

Obtém a interface de textura do Direct3D subjacente ao objeto de [textura](texture-class.md) especificado.

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

### <a name="parameters"></a>parâmetros

*value_type*<br/>
O tipo de elemento da textura.

*_Rank*<br/>
A classificação da textura.

*_Texture*<br/>
Uma exibição de textura ou textura associada ao accelerator_view para o qual a interface de textura do Direct3D subjacente é retornada.

### <a name="return-value"></a>Valor Retornado

O ponteiro de interface IUnknown que corresponde à textura do Direct3D subjacente à textura.

## <a name="make_sampler"></a><a name="make_sampler"></a> make_sampler

Crie uma amostra de um ponteiro de interface de estado de amostra do D3D.

```cpp
sampler make_sampler(_In_ IUnknown* _D3D_sampler) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_D3D_sampler*<br/>
Ponteiro de interface IUnknown do estado de amostra de D3D do qual criar a amostra.

### <a name="return-value"></a>Valor Retornado

Um amostra representa o estado de amostra do D3D fornecido.

## <a name="make_texture"></a><a name="make_texture"></a> make_texture

Cria um objeto de [textura](texture-class.md) usando os parâmetros especificados.

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

### <a name="parameters"></a>parâmetros

*value_type*<br/>
O tipo dos elementos na textura.

*_Rank*<br/>
A classificação da textura.

*_Av*<br/>
Uma exibição de acelerador de D3D na qual a textura deve ser criada.

*_D3D_texture*<br/>
Ponteiro de interface IUnknown da textura D3D da qual criar a textura.

*_View_format*<br/>
O formato DXGI a ser usado para exibições criadas com base nessa textura. Passe DXGI_FORMAT_UNKNOWN (o padrão) para derivar o formato do formato subjacente de _D3D_texture e o value_type deste modelo. O formato fornecido deve ser compatível com o formato subjacente de _D3D_texture.

### <a name="return-value"></a>Valor Retornado

Uma textura que usa a textura D3D fornecida.

## <a name="msad4"></a><a name="msad4"></a> msad4

Compara um valor de referência de 4 bytes e um valor de origem de 8 bytes e acumula um vetor de quatro somas. Cada soma corresponde à soma mascarada de diferenças absolutas de diferentes alinhamentos de bytes entre o valor de referência e o valor de origem.

```cpp
inline uint4 msad4(
    uint _Reference,
    uint2 _Source,
    uint4 _Accum) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_Reference*<br/>
A matriz de referência de 4 bytes em um valor UINT

*_Source*<br/>
A matriz de origem de 8 bytes em um vetor de dois valores uint.

*_Accum*<br/>
Um vetor de quatro valores a ser adicionado à soma mascarada de diferenças absolutas dos diferentes alinhamentos de bytes entre o valor de referência e o valor de origem.

### <a name="return-value"></a>Valor Retornado

Retorna um vetor de quatro somas. Cada soma corresponde à soma mascarada de diferenças absolutas de diferentes alinhamentos de bytes entre o valor de referência e o valor de origem.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amp_graphics. h

**Namespace:** Concurrency:: Graphics::d irect3d

## <a name="see-also"></a>Confira também

[Concurrency:: Graphics::d namespace irect3d](concurrency-graphics-direct3d-namespace.md)
