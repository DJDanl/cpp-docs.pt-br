---
title: Funções do namespace de simultaneidade (AMP)
ms.date: 11/04/2016
f1_keywords:
- amp/Concurrency::all_memory_fence
- amp/Concurrency::atomic_compare_exchange
- amp/Concurrency::atomic_fetch_dec
- amp/Concurrency::atomic_fetch_max
- amp/Concurrency::atomic_fetch_min
- amp/Concurrency::copy
- amp/Concurrency::direct3d_abort
- amp/Concurrency::direct3d_printf
- amp/Concurrency::global_memory_fence
- amp/Concurrency::tile_static_memory_fence
ms.assetid: 2bef0985-cb90-4ece-90b9-66529aec73c9
ms.openlocfilehash: 90a23ce111f7307610de3f0ad4bcec05d8de27df
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77126885"
---
# <a name="concurrency-namespace-functions-amp"></a>Funções do namespace de simultaneidade (AMP)

||||
|-|-|-|
|[all_memory_fence](#all_memory_fence)|[amp_uninitialize](#amp_uninitialize)|[atomic_compare_exchange](#atomic_compare_exchange)|
|[Função atomic_exchange (C++ amp)](#atomic_exchange)|[Função atomic_fetch_add (C++ amp)](#atomic_fetch_add)|[Função atomic_fetch_and (C++ amp)](#atomic_fetch_and)|
|[atomic_fetch_dec](#atomic_fetch_dec)|[atomic_fetch_inc](#atomic_fetch_inc)|[atomic_fetch_max](#atomic_fetch_max)|
|[atomic_fetch_min](#atomic_fetch_min)|[Função atomic_fetch_or (C++ amp)](#atomic_fetch_or)|[Função atomic_fetch_sub (C++ amp)](#atomic_fetch_sub)|
|[Função atomic_fetch_xor (C++ amp)](#atomic_fetch_xor)|[copy](#copy)|[copy_async](#copy_async)|
|[direct3d_abort](#direct3d_abort)|[direct3d_errorf](#direct3d_errorf)|[direct3d_printf](#direct3d_printf)|
|[global_memory_fence](#global_memory_fence)|[Função parallel_for_each (C++ amp)](#parallel_for_each)|[tile_static_memory_fence](#tile_static_memory_fence)|

## <a name="all_memory_fence"></a>all_memory_fence

Bloqueia a execução de todos os threads em um bloco até que todos os acessos à memória tenham sido concluídos. Isso garante que todos os acessos à memória sejam visíveis para outros threads no bloco thread e sejam executados na ordem do programa.

```cpp
inline void all_memory_fence(const tile_barrier& _Barrier) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Barrier*<br/>
Um objeto `tile_barrier`.

## <a name="amp_uninitialize"></a>amp_uninitialize

Desinicializa o C++ tempo de execução de amp. É legal chamar essa função várias vezes durante um tempo de vida dos aplicativos. Chamar qualquer C++ API de amp depois de chamar essa função reinicializará C++ o tempo de execução do amp. Observe que é ilegal usar C++ objetos amp em chamadas para essa função e fazer isso resultará em um comportamento indefinido. Além disso, chamar essa função simultaneamente e quaisquer outras APIs de AMP é ilegal e resultaria em um comportamento indefinido.

```cpp
void __cdecl amp_uninitialize();
```

## <a name="atomic_compare_exchange"></a>atomic_compare_exchange

Compara atomicamente o valor armazenado em um local de memória especificado no primeiro argumento para igualdade com o valor do segundo argumento especificado e, se os valores forem iguais, o valor no local da memória será alterado para o do terceiro argumento especificado.

```cpp
inline bool atomic_compare_exchange(
    _Inout_ int* _Dest,
    _Inout_ int* _Expected_value,
    int value
    ) restrict(amp)

inline bool atomic_compare_exchange(
    _Inout_ unsigned int* _Dest,
    _Inout_ unsigned int* _Expected_value,
    unsigned int value
    ) restrict(amp)
```

### <a name="parameters"></a>Parâmetros

*_Dest*<br/>
O local do qual um dos valores a serem comparados é lido e para o qual o novo valor, se houver, deve ser armazenado.

*_Expected_value*<br/>
O local do qual o segundo valor a ser comparado é lido.

*value*<br/>
O valor a ser armazenado no local da memória especificado em por `_Dest` se `_Dest` for igual a `_Expected_value`.

### <a name="return-value"></a>Valor retornado

**true** se a operação for bem-sucedida; caso contrário, **false**.

## <a name="atomic_exchange"></a>Função atomic_exchange (C++ amp)

Define o valor do local de destino como uma operação atômica.

```cpp
inline int atomic_exchange(
    _Inout_ int* _Dest,
    int value
    ) restrict(amp)

inline unsigned int atomic_exchange(
    _Inout_ unsigned int* _Dest,
    unsigned int value
    ) restrict(amp)

inline float atomic_exchange(
    _Inout_ float* _Dest,
    float value
    ) restrict(amp)
```

### <a name="parameters"></a>Parâmetros

*_Dest*<br/>
Ponteiro para o local de destino.

*value*<br/>
O novo valor.

### <a name="return-value"></a>Valor retornado

O valor original do local de destino.

## <a name="atomic_fetch_add"></a>Função atomic_fetch_add (C++ amp)

Adicione atomicamente um valor ao valor de um local de memória.

```cpp
inline int atomic_fetch_add(
    _Inout_ int* _Dest,
    int value
    ) restrict(amp)

inline unsigned int atomic_fetch_add(
    _Inout_ unsigned int* _Dest,
    unsigned int value
    ) restrict(amp)
```

### <a name="parameters"></a>Parâmetros

*_Dest*<br/>
Ponteiro para o local da memória.

*value*<br/>
O valor a ser adicionado.

### <a name="return-value"></a>Valor retornado

O valor original do local da memória.

## <a name="atomic_fetch_and"></a>Função atomic_fetch_and (C++ amp)

Executa atomicamente uma operação e bit a ponto de um valor e o valor de um local de memória.

```cpp
inline int atomic_fetch_and(
    _Inout_ int* _Dest,
    int value
    ) restrict(amp)

inline unsigned int atomic_fetch_and(
    _Inout_ unsigned int* _Dest,
    unsigned int value
    ) restrict(amp)
```

### <a name="parameters"></a>Parâmetros

*_Dest*<br/>
Ponteiro para o local da memória.

*value*<br/>
O valor a ser usado no bit e no de cálculo.

### <a name="return-value"></a>Valor retornado

O valor original do local da memória.

## <a name="atomic_fetch_dec"></a>atomic_fetch_dec

Reduz atomicamente o valor armazenado no local de memória especificado.

```cpp
inline int atomic_fetch_dec(_Inout_ int* _Dest
    ) restrict(amp)

inline unsigned int atomic_fetch_dec(_Inout_ unsigned int* _Dest) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Dest*<br/>
O local na memória do valor a ser decrementado.

### <a name="return-value"></a>Valor retornado

O valor original armazenado no local da memória.

## <a name="atomic_fetch_inc"></a>atomic_fetch_inc

Aumenta atomicamente o valor armazenado no local de memória especificado.

```cpp
inline int atomic_fetch_inc(_Inout_ int* _Dest) restrict(amp);

inline unsigned int atomic_fetch_inc(_Inout_ unsigned int* _Dest) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Dest*<br/>
O local na memória do valor a ser incrementado.

### <a name="return-value"></a>Valor retornado

O valor original armazenado no local da memória.

## <a name="atomic_fetch_max"></a>atomic_fetch_max

Computa atomicamente o valor máximo entre o valor armazenado no local da memória especificado no primeiro argumento e o valor especificado no segundo argumento e o armazena no mesmo local da memória.

```cpp
inline int atomic_fetch_max(
    _Inout_ int* _Dest,
    int value
    ) restrict(amp)

inline unsigned int atomic_fetch_max(
    _Inout_ unsigned int* _Dest,
    unsigned int value
    ) restrict(amp)
```

### <a name="parameters"></a>Parâmetros

*_Dest*<br/>
O local do qual um dos valores a serem comparados é lido e para o qual o máximo dos dois valores deve ser armazenado.

*value*<br/>
O valor a ser comparado com o valor no local especificado.

### <a name="return-value"></a>Valor retornado

O valor original armazenado no local do local especificado.

## <a name="atomic_fetch_min"></a>atomic_fetch_min

Computa atomicamente o valor mínimo entre o valor armazenado no local da memória especificado no primeiro argumento e o valor especificado no segundo argumento e o armazena no mesmo local da memória.

```cpp
inline int atomic_fetch_min(
    _Inout_ int* _Dest,
    int value
    ) restrict(amp)

inline unsigned int atomic_fetch_min(
    _Inout_ unsigned int* _Dest,
    unsigned int value
    ) restrict(amp)
```

### <a name="parameters"></a>Parâmetros

*_Dest*<br/>
O local do qual um dos valores a serem comparados é lido e para o qual o mínimo dos dois valores deve ser armazenado.

*value*<br/>
O valor a ser comparado com o valor no local especificado.

### <a name="return-value"></a>Valor retornado

O valor original armazenado no local do local especificado.

## <a name="atomic_fetch_or"></a>Função atomic_fetch_or (C++ amp)

Executa atomicamente uma operação OR bit a ponto com um valor e o valor de um local de memória.

```cpp
inline int atomic_fetch_or(
    _Inout_ int* _Dest,
    int value
    ) restrict(amp)

inline unsigned int atomic_fetch_or(
    _Inout_ unsigned int* _Dest,
    unsigned int value
    ) restrict(amp)
```

### <a name="parameters"></a>Parâmetros

*_Dest*<br/>
Ponteiro para o local da memória.

*value*<br/>
O valor a ser usado no bit ou no cálculo.

### <a name="return-value"></a>Valor retornado

O valor original do local da memória.

## <a name="atomic_fetch_sub"></a>Função atomic_fetch_sub (C++ amp)

Subtrai atomicamente um valor de um local de memória.

```cpp
inline int atomic_fetch_sub(
    _Inout_ int* _Dest,
    int value
    ) restrict(amp)

inline unsigned int atomic_fetch_sub(
    _Inout_ unsigned int* _Dest,
    unsigned int value
    ) restrict(amp)
```

### <a name="parameters"></a>Parâmetros

*_Dest*<br/>
Ponteiro para o local de destino.

*value*<br/>
O valor a ser subtraído.

### <a name="return-value"></a>Valor retornado

O valor original do local da memória.

## <a name="atomic_fetch_xor"></a>Função atomic_fetch_xor (C++ amp)

Executa atomicamente uma operação de XOR bit a ponto de um valor e de uma localização de memória.

```cpp
inline int atomic_fetch_xor(
    _Inout_ int* _Dest,
    int value
    ) restrict(amp)

inline unsigned int atomic_fetch_xor(
    _Inout_ unsigned int* _Dest,
    unsigned int value
    ) restrict(amp)
```

### <a name="parameters"></a>Parâmetros

*_Dest*<br/>
Ponteiro para o local da memória.

*value*<br/>
O valor a ser usado no cálculo de XOR.

### <a name="return-value"></a>Valor retornado

O valor original do local da memória.

## <a name="copy"></a>  copy

Copia um C++ objeto amp. Todos os requisitos de transferência de dados síncronas são atendidos. Você não pode copiar dados ao executar código em um acelerador. A forma geral dessa função é `copy(src, dest)`.

```cpp
template <typename value_type, int _Rank>
void copy(
    const array<value_type, _Rank>& _Src,
    array<value_type, _Rank>& _Dest);

template <typename InputIterator, typename value_type, int _Rank>
void copy(
    InputIterator _SrcFirst,
    InputIterator _SrcLast,
    array<value_type, _Rank>& _Dest);

template <typename InputIterator, typename value_type, int _Rank>
void copy(
    InputIterator _SrcFirst,
    array<value_type, _Rank>& _Dest);

template <typename OutputIterator, typename value_type, int _Rank>
void copy(
    const array<value_type, _Rank>& _Src,
   OutputIterator _DestIter);

template <typename value_type, int _Rank>
void copy(
    const array<value_type, _Rank>& _Src,
    array_view<value_type, _Rank>& _Dest);

template <typename value_type, int _Rank>
void copy(
    const array_view<const value_type, _Rank>& _Src,
    array<value_type, _Rank>& _Dest);

template <typename value_type, int _Rank>
void copy(
    const array_view<value_type, _Rank>& _Src,
    array<value_type, _Rank>& _Dest);

template <typename value_type, int _Rank>
void copy(
    const array_view<const value_type, _Rank>& _Src,
    array_view<value_type, _Rank>& _Dest);

template <typename value_type, int _Rank>
void copy(
    const array_view<value_type, _Rank>& _Src,
    array_view<value_type, _Rank>& _Dest);

template <typename InputIterator, typename value_type, int _Rank>
void copy(
    InputIterator _SrcFirst,
    InputIterator _SrcLast,
    array_view<value_type, _Rank>& _Dest);

template <typename InputIterator, typename value_type, int _Rank>
void copy(
    InputIterator _SrcFirst,
    array_view<value_type, _Rank>& _Dest);

template <typename OutputIterator, typename value_type, int _Rank>
void copy(
    const array_view<value_type, _Rank>& _Src,
    OutputIterator _DestIter);
```

### <a name="parameters"></a>Parâmetros

*_Dest*<br/>
O objeto para o qual copiar.

*_DestIter*<br/>
Um iterador de saída para a posição inicial no destino.

*InputIterator*<br/>
O tipo do iterador de entrada.

*OutputIterator*<br/>
O tipo do iterador de saída.

*_Rank*<br/>
A classificação do objeto a ser copiado ou o objeto a ser copiado.

*_Src*<br/>
Para o objeto a ser copiado.

*_SrcFirst*<br/>
Um iterador inicial no contêiner de origem.

*_SrcLast*<br/>
Um iterador final no contêiner de origem.

*value_type*<br/>
O tipo de dados dos elementos que são copiados.

## <a name="copy_async"></a>copy_async

Copia um C++ objeto amp e retorna um objeto [completion_future](completion-future-class.md) que pode ser aguardado. Você não pode copiar dados ao executar código em um acelerador.  A forma geral dessa função é `copy(src, dest)`.

```cpp
template <typename value_type, int _Rank>
concurrency::completion_future copy_async(
    const array<value_type, _Rank>& _Src,
    array<value_type, _Rank>& _Dest);

template <typename InputIterator, typename value_type, int _Rank>
concurrency::completion_future copy_async(InputIterator _SrcFirst, InputIterator _SrcLast,
    array<value_type, _Rank>& _Dest);

template <typename InputIterator, typename value_type, int _Rank>
concurrency::completion_future copy_async(InputIterator _SrcFirst,
    array<value_type, _Rank>& _Dest);

template <typename OutputIterator, typename value_type, int _Rank>
concurrency::completion_future copy_async(
    const array<value_type, _Rank>& _Src, OutputIterator _DestIter);

template <typename value_type, int _Rank>
concurrency::completion_future copy_async(
    const array<value_type, _Rank>& _Src,
    array_view<value_type, _Rank>& _Dest);

template <typename value_type, int _Rank>
concurrency::completion_future copy_async(
    const array_view<const value_type, _Rank>& _Src,
    array<value_type, _Rank>& _Dest);

template <typename value_type, int _Rank>
concurrency::completion_future copy_async(
    const array_view<value_type, _Rank>& _Src,
    array<value_type, _Rank>& _Dest);

template <typename value_type, int _Rank>
concurrency::completion_future copy_async(
    const array_view<const value_type, _Rank>& _Src,
    array_view<value_type, _Rank>& _Dest);

template <typename value_type, int _Rank>
concurrency::completion_future copy_async(
    const array_view<value_type, _Rank>& _Src,
    array_view<value_type, _Rank>& _Dest);

template <typename InputIterator, typename value_type, int _Rank>
concurrency::completion_future copy_async(InputIterator _SrcFirst, InputIterator _SrcLast,
    array_view<value_type, _Rank>& _Dest);

template <typename InputIterator, typename value_type, int _Rank>
concurrency::completion_future copy_async(InputIterator _SrcFirst,
    array_view<value_type, _Rank>& _Dest);

template <typename OutputIterator, typename value_type, int _Rank>
concurrency::completion_future copy_async(
    const array_view<value_type, _Rank>& _Src, OutputIterator _DestIter);
```

### <a name="parameters"></a>Parâmetros

*_Dest*<br/>
O objeto para o qual copiar.

*_DestIter*<br/>
Um iterador de saída para a posição inicial no destino.

*InputIterator*<br/>
O tipo do iterador de entrada.

*OutputIterator*<br/>
O tipo do iterador de saída.

*_Rank*<br/>
A classificação do objeto a ser copiado ou o objeto a ser copiado.

*_Src*<br/>
Para o objeto a ser copiado.

*_SrcFirst*<br/>
Um iterador inicial no contêiner de origem.

*_SrcLast*<br/>
Um iterador final no contêiner de origem.

*value_type*<br/>
O tipo de dados dos elementos que são copiados.

### <a name="return-value"></a>Valor retornado

Um `future<void>` que pode ser aguardado.

## <a name="direct3d_abort"></a>direct3d_abort

Anula a execução de uma função com a cláusula de restrição `restrict(amp)`. Quando o tempo de execução do AMP detecta a chamada, ele gera uma exceção [runtime_exception](runtime-exception-class.md) com a mensagem de erro "rasterizador de referência: a instrução de anulação de sombreador".

```cpp
void direct3d_abort() restrict(amp);
```

## <a name="direct3d_errorf"></a>direct3d_errorf

Imprime uma cadeia de caracteres formatada na janela de saída do Visual Studio. Ele é chamado de uma função com a cláusula de restrição `restrict(amp)`. Quando o tempo de execução do AMP detecta a chamada, ele gera uma exceção de [runtime_exception](runtime-exception-class.md) com a mesma cadeia de caracteres de formatação.

```cpp
void direct3d_errorf(
    const char *,
...) restrict(amp);
```

## <a name="direct3d_printf"></a>direct3d_printf

Imprime uma cadeia de caracteres formatada na janela de saída do Visual Studio. Ele é chamado de uma função com a cláusula de restrição `restrict(amp)`.

```cpp
void direct3d_printf(
    const char *,
...) restrict(amp);
```

## <a name="global_memory_fence"></a>global_memory_fence

Bloqueia a execução de todos os threads em um bloco até que todos os acessos de memória global tenham sido concluídos. Isso garante que os acessos de memória global fiquem visíveis para outros threads no bloco de threads e sejam executados na ordem do programa.

```cpp
inline void global_memory_fence(const tile_barrier& _Barrier) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Barrier*<br/>
Um objeto tile_barrier

## <a name="parallel_for_each"></a>Função parallel_for_each (C++ amp)

Executa uma função no domínio de computação. Para obter mais informações, consulte [ C++ amp Overview](../../../parallel/amp/cpp-amp-overview.md).

```cpp
template <int _Rank, typename _Kernel_type>
void parallel_for_each(
    const extent<_Rank>& _Compute_domain,
    const _Kernel_type& _Kernel);

template <int _Dim0, int _Dim1, int _Dim2, typename _Kernel_type>
void parallel_for_each(
    const tiled_extent<_Dim0, _Dim1, _Dim2>& _Compute_domain,
   const _Kernel_type& _Kernel);

template <int _Dim0, int _Dim1, typename _Kernel_type>
void parallel_for_each(
    const tiled_extent<_Dim0, _Dim1>& _Compute_domain,
    const _Kernel_type& _Kernel);

template <int _Dim0, typename _Kernel_type>
void parallel_for_each(
    const tiled_extent<_Dim0>& _Compute_domain,
    const _Kernel_type& _Kernel);

template <int _Rank, typename _Kernel_type>
void parallel_for_each(
    const accelerator_view& _Accl_view,
    const extent<_Rank>& _Compute_domain,
    const _Kernel_type& _Kernel);

template <int _Dim0, int _Dim1, int _Dim2, typename _Kernel_type>
void parallel_for_each(
    const accelerator_view& _Accl_view,
    const tiled_extent<_Dim0, _Dim1, _Dim2>& _Compute_domain,
    const _Kernel_type& _Kernel);

template <int _Dim0, int _Dim1, typename _Kernel_type>
void parallel_for_each(
    const accelerator_view& _Accl_view,
    const tiled_extent<_Dim0, _Dim1>& _Compute_domain,
    const _Kernel_type& _Kernel);

template <int _Dim0, typename _Kernel_type>
void parallel_for_each(
    const accelerator_view& _Accl_view,
    const tiled_extent<_Dim0>& _Compute_domain,
    const _Kernel_type& _Kernel);
```

### <a name="parameters"></a>Parâmetros

*_Accl_view*<br/>
O objeto `accelerator_view` no qual executar a computação paralela.

*_Compute_domain*<br/>
Um objeto `extent` que contém os dados para a computação.

*_Dim0*<br/>
A dimensão do objeto `tiled_extent`.

*_Dim1*<br/>
A dimensão do objeto `tiled_extent`.

*_Dim2*<br/>
A dimensão do objeto `tiled_extent`.

*_Kernel*<br/>
Um objeto lambda ou Function que usa um argumento do tipo "index\<_Rank >" e executa a computação paralela.

*_Kernel_type*<br/>
Um lambda ou functor.

*_Rank*<br/>
A classificação da extensão.

## <a name="tile_static_memory_fence"></a>tile_static_memory_fence

Bloqueia a execução de todos os threads em um bloco até que todos os `tile_static` de acessos de memória pendentes tenham sido concluídos. Isso garante que `tile_static` acessos de memória sejam visíveis para outros threads no bloco de threads e que os acessos sejam executados na ordem do programa.

```cpp
inline void tile_static_memory_fence(const tile_barrier& _Barrier) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Barrier*<br/>
Um objeto tile_barrier.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
