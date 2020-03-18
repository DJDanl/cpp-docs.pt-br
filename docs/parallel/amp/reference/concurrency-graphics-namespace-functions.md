---
title: Funções do namespace Concurrency::graphics
ms.date: 11/04/2016
f1_keywords:
- amp_graphics/Concurrency::fast_math::copy_async
- amp_graphics/Concurrency::fast_math::copy
ms.assetid: ace01cd5-29d3-4356-930e-c81a61c5f934
ms.openlocfilehash: 46b8a171acd3b125749b4e2c519909b82c76dc39
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79419276"
---
# <a name="concurrencygraphics-namespace-functions"></a>Funções do namespace Concurrency::graphics

|||
|-|-|
|[copy](#copy)|[copy_async](#copy_async)|

## <a name="copy"></a>Função de cópia (namespace Concurrency:: Graphics)

Copia uma textura de origem em um buffer de destino ou copia um buffer de origem em um buffer de destino. A forma geral dessa função é `copy(src, dest)`.

```cpp
template <
    typename _Src_type,
    typename = typename std::enable_if<details::texture_traits<_Src_type>::is_texture, void>::type>
>
void copy (
    const _Src_type& _Src,
    _Out_ void* _Dst,
    unsigned int _Dst_byte_size);

template <
    typename _Src_type,
    typename = typename std::enable_if<details::texture_traits<_Src_type>::is_texture, void>::type
>
void copy(
    const _Src_type& _Src,
    const index<_Src_type::rank>& _Src_offset,
    const extent<_Src_type::rank>& _Copy_extent,
    _Out_ void* _Dst,
    unsigned int _Dst_byte_size);

template <
    typename _Dst_type,
    typename = typename std::enable_if<details::texture_traits<_Dst_type>::is_texture, void>::type
>
void copy(
    const void* _Src,
    unsigned int _Src_byte_size, _Dst_type& _Dst);

template <
    typename _Dst_type,
    typename = typename std::enable_if<details::texture_traits<_Dst_type>::is_texture, void>::type
>
void copy(
    const void* _Src,
    unsigned int _Src_byte_size,
    _Dst_type& _Dst,
    const index<_Dst_type::rank>& _Dst_offset,
    const extent<_Dst_type::rank>& _Copy_extent);

template <
    typename InputIterator,
    typename _Dst_type,
    typename = typename std::enable_if<details::texture_traits<_Dst_type>::is_texture, void>::type
>
void copy(InputIterator first, InputIterator last, _Dst_type& _Dst);

template <
    typename InputIterator,
    typename _Dst_type,
    typename = typename std::enable_if<details::texture_traits<_Dst_type>::is_texture, void>::type
>void copy(InputIterator first, InputIterator last, _Dst_type& _Dst,
    const index<_Dst_type::rank>& _Dst_offset,
    const extent<_Dst_type::rank>& _Copy_extent);

template <
    typename _Src_type,
    typename OutputIterator,
    typename = typename std::enable_if<details::texture_traits<_Src_type>::is_texture&& !details::texture_traits<OutputIterator>::is_texture, void>::type
>
void copy(
    const _Src_type& _Src, OutputIterator _Dst);

template <
    typename _Src_type,
    typename OutputIterator,
    typename = typename std::enable_if<details::texture_traits<_Src_type>::is_texture&& !details::texture_traits<OutputIterator>::is_texture, void>::type
>
void copy (
    const _Src_type& _Src,
    const index<_Src_type::rank>& _Src_offset,
    const extent<_Src_type::rank>& _Copy_extent, OutputIterator _Dst);

template <
    typename _Src_type,
    typename _Dst_type,
    typename = typename std::enable_if<details::texture_traits<_Src_type>::is_texture&& details::texture_traits<_Dst_type>::is_texture, void>::type
>
void copy (
    const _Src_type& _Src, _Dst_type& _Dst);

template <
    typename _Src_type,
    typename _Dst_type,
    typename = typename std::enable_if<details::texture_traits<_Src_type>::is_texture&& details::texture_traits<_Dst_type>::is_texture,
    void>::type
>
void copy (
    const _Src_type& _Src,
    const index<_Src_type::rank>& _Src_offset, _Dst_type& _Dst,
    const index<_Dst_type::rank>& _Dst_offset,
    const extent<_Src_type::rank>& _Copy_extent);
```

### <a name="parameters"></a>parâmetros

*_Copy_extent*<br/>
A extensão da seção de textura a ser copiada.

*_Dst*<br/>
O objeto para o qual copiar.

*_Dst_byte_size*<br/>
O número de bytes no destino.

*_Dst_type*<br/>
O tipo do objeto de destino.

*_Dst_offset*<br/>
O deslocamento para o destino no qual começar a copiar.

*InputIterator*<br/>
O tipo do iterador de entrada.

*OutputIterator*<br/>
O tipo do iterador de saída.

*_Src*<br/>
Para o objeto a ser copiado.

*_Src_byte_size*<br/>
O número de bytes na origem.

*_Src_type*<br/>
O tipo do objeto de origem.

*_Src_offset*<br/>
O deslocamento na origem a partir da qual começar a copiar.

*first*<br/>
Um iterador inicial no contêiner de origem.

*last*<br/>
Um iterador final no contêiner de origem.

## <a name="copy_async"></a>copy_async função (Concurrency:: Graphics namespace)

Copia de forma assíncrona uma textura de origem em um buffer de destino ou copia um buffer de origem em um buffer de destino e, em seguida, retorna um objeto de [completion_future](completion-future-class.md) que pode ser aguardado. Os dados não podem ser copiados quando o código está sendo executado em um acelerador. A forma geral dessa função é `copy(src, dest)`.

```cpp
template<
    typename _Src_type,
    typename = typename std::enable_if<details::texture_traits<_Src_type>::is_texture, void>::type
>
concurrency::completion_future copy_async(
    const _Src_type& _Src,
    _Out_ void* _Dst,
    unsigned int _Dst_byte_size);

template<
    typename _Src_type,
    typename = typename std::enable_if<details::texture_traits<_Src_type>::is_texture, void>::type
>
concurrency::completion_future copy_async(
    const _Src_type& _Src,
    const index<_Src_type::rank>& _Src_offset,
    const extent<_Src_type::rank>& _Copy_extent,
    _Out_ void* _Dst,
    unsigned int _Dst_byte_size);

template <
    typename _Dst_type,
    typename = typename std::enable_if<details::texture_traits<_Dst_type>::is_texture, void>::type
>
concurrency::completion_future copy_async(
    const void* _Src,
    unsigned int _Src_byte_size, _Dst_type& _Dst);

template <
    typename _Dst_type,
    typename = typename std::enable_if<details::texture_traits<_Dst_type>::is_texture, void>::type
>
concurrency::completion_future copy_async(
    const void* _Src,
    unsigned int _Src_byte_size, _Dst_type& _Dst,
    const index<_Dst_type::rank>& _Dst_offset,
    const extent<_Dst_type::rank>& _Copy_extent);

template <
    typename InputIterator,
    typename _Dst_type,
    typename = typename std::enable_if<details::texture_traits<_Dst_type>::is_texture, void>::type
>
concurrency::completion_future copy_async(InputIterator first, InputIterator last, _Dst_type& _Dst);

template <
    typename InputIterator,
    typename _Dst_type,
    typename = typename std::enable_if<details::texture_traits<_Dst_type>::is_texture, void>::type
>
concurrency::completion_future copy_async(InputIterator first, InputIterator last, _Dst_type& _Dst,
    const index<_Dst_type::rank>& _Dst_offset,
    const extent<_Dst_type::rank>& _Copy_extent);

template <
    typename _Src_type,
    typename OutputIterator,
    typename = typename std::enable_if<details::texture_traits<_Src_type>::is_texture&& !details::texture_traits<OutputIterator>::is_texture, void>::type
>
concurrency::completion_future copy_async(_Src_type& _Src, OutputIterator _Dst);

template <
    typename _Src_type,
    typename OutputIterator,
    typename = typename std::enable_if<details::texture_traits<_Src_type>::is_texture&& !details::texture_traits<OutputIterator>::is_texture, void>::type
>
concurrency::completion_future copy_async(_Src_type& _Src,
    const index<_Src_type::rank>& _Src_offset,
    const extent<_Src_type::rank>& _Copy_extent,
    OutputIterator _Dst);

template <
    typename _Src_type,
    typename _Dst_type,
    typename = typename std::enable_if<details::texture_traits<_Src_type>::is_texture&& details::texture_traits<_Dst_type>::is_texture, void>::type
>
concurrency::completion_future copy_async(_Src_type& _Src, _Dst_type& _Dst);

template <
    typename _Src_type,
    typename _Dst_type,
    typename = typename std::enable_if<details::texture_traits<_Src_type>::is_texture&& details::texture_traits<_Dst_type>::is_texture, void>::type
>
concurrency::completion_future copy_async(_Src_type& _Src,
    const index<_Src_type::rank>& _Src_offset, _Dst_type &_Dst,
    const index<_Dst_type::rank>& _Dst_offset,
    const extent<_Src_type::rank>& _Copy_extent);
```

### <a name="parameters"></a>parâmetros

*_Copy_extent*<br/>
A extensão da seção de textura a ser copiada.

*_Dst*<br/>
O objeto para o qual copiar.

*_Dst_byte_size*<br/>
O número de bytes no destino.

*_Dst_type*<br/>
O tipo do objeto de destino.

*_Dst_offset*<br/>
O deslocamento para o destino no qual começar a copiar.

*InputIterator*<br/>
O tipo do iterador de entrada.

*OutputIterator*<br/>
O tipo do iterador de saída.

*_Src*<br/>
Para o objeto a ser copiado.

*_Src_byte_size*<br/>
O número de bytes na origem.

*_Src_type*<br/>
O tipo do objeto de origem.

*_Src_offset*<br/>
O deslocamento na origem a partir da qual começar a copiar.

*first*<br/>
Um iterador inicial no contêiner de origem.

*last*<br/>
Um iterador final no contêiner de origem.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amp_graphics. h

**Namespace:** Simultaneidade:: Graphics

## <a name="see-also"></a>Confira também

[Namespace Concurrency::graphics](concurrency-graphics-namespace.md)
