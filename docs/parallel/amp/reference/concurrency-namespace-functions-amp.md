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
ms.openlocfilehash: 1187b745a6d8c903c22958185be8d98a6e3d0204
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376349"
---
# <a name="concurrency-namespace-functions-amp"></a>Funções do namespace de simultaneidade (AMP)

||||
|-|-|-|
|[all_memory_fence](#all_memory_fence)|[amp_uninitialize](#amp_uninitialize)|[atomic_compare_exchange](#atomic_compare_exchange)|
|[Função atomic_exchange (C++ AMP)](#atomic_exchange)|[Função atomic_fetch_add (C++ AMP)](#atomic_fetch_add)|[Função atomic_fetch_and (C++ AMP)](#atomic_fetch_and)|
|[atomic_fetch_dec](#atomic_fetch_dec)|[atomic_fetch_inc](#atomic_fetch_inc)|[atomic_fetch_max](#atomic_fetch_max)|
|[atomic_fetch_min](#atomic_fetch_min)|[Função atomic_fetch_or (C++ AMP)](#atomic_fetch_or)|[função atomic_fetch_sub (C++ AMP)](#atomic_fetch_sub)|
|[Função atomic_fetch_xor (C++ AMP)](#atomic_fetch_xor)|[Cópia](#copy)|[copy_async](#copy_async)|
|[direct3d_abort](#direct3d_abort)|[direct3d_errorf](#direct3d_errorf)|[direct3d_printf](#direct3d_printf)|
|[global_memory_fence](#global_memory_fence)|[Função parallel_for_each (C++ AMP)](#parallel_for_each)|[tile_static_memory_fence](#tile_static_memory_fence)|

## <a name="all_memory_fence"></a><a name="all_memory_fence"></a>all_memory_fence

Bloqueia a execução de todos os segmentos em um ladrilho até que todos os acessos de memória tenham sido concluídos. Isso garante que todos os acessos de memória sejam visíveis para outros segmentos no bloco de segmentos e sejam executados em ordem de programa.

```cpp
inline void all_memory_fence(const tile_barrier& _Barrier) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Barrier*<br/>
Um objeto `tile_barrier` .

## <a name="amp_uninitialize"></a><a name="amp_uninitialize"></a>amp_uninitialize

Desinicializa o tempo de execução c++ AMP. É legal chamar essa função várias vezes durante uma vida útil de aplicativos. Chamar qualquer API C++ AMP depois de chamar essa função reinicializará o tempo de execução do C++ AMP. Observe que é ilegal usar objetos C++ AMP através de chamadas para esta função e fazê-lo resultará em comportamento indefinido. Além disso, chamar simultaneamente essa função e quaisquer outras APIs AMP é ilegal e resultaria em comportamento indefinido.

```cpp
void __cdecl amp_uninitialize();
```

## <a name="atomic_compare_exchange"></a><a name="atomic_compare_exchange"></a>atomic_compare_exchange

Atomicamente compara o valor armazenado em um local de memória especificado no primeiro argumento para igualdade com o valor do segundo argumento especificado, e se os valores forem os mesmos, o valor no local de memória será alterado para o do terceiro argumento especificado.

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
O local a partir do qual um dos valores a serem comparados é lido, e para o qual o novo valor, se houver, deve ser armazenado.

*_Expected_value*<br/>
O local a partir do qual o segundo valor a ser comparado é lido.

*value*<br/>
O valor a ser armazenado no local `_Dest` `_Dest` de memória `_Expected_value`especificado por se é igual a .

### <a name="return-value"></a>Valor retornado

**verdade** se a operação for bem sucedida; caso contrário, **falso**.

## <a name="atomic_exchange-function-c-amp"></a><a name="atomic_exchange"></a>atomic_exchange (C++ AMP)

Define o valor da localização do destino como uma operação atômica.

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

## <a name="atomic_fetch_add-function-c-amp"></a><a name="atomic_fetch_add"></a>função atomic_fetch_add (C++ AMP)

Adicionar atomicamente um valor ao valor de um local de memória.

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

## <a name="atomic_fetch_and-function-c-amp"></a><a name="atomic_fetch_and"></a>função atomic_fetch_and (C++ AMP)

Atomicamente executa um pouco e operação de um valor e o valor de um local de memória.

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
O valor a ser usado no bitwise E cálculo.

### <a name="return-value"></a>Valor retornado

O valor original do local da memória.

## <a name="atomic_fetch_dec"></a><a name="atomic_fetch_dec"></a>atomic_fetch_dec

Decretaatomicamente o valor armazenado no local de memória especificado.

```cpp
inline int atomic_fetch_dec(_Inout_ int* _Dest
    ) restrict(amp)

inline unsigned int atomic_fetch_dec(_Inout_ unsigned int* _Dest) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Dest*<br/>
A localização em memória do valor a ser decretado.

### <a name="return-value"></a>Valor retornado

O valor original armazenado no local da memória.

## <a name="atomic_fetch_inc"></a><a name="atomic_fetch_inc"></a>atomic_fetch_inc

Incrementa atomicamente o valor armazenado no local de memória especificado.

```cpp
inline int atomic_fetch_inc(_Inout_ int* _Dest) restrict(amp);

inline unsigned int atomic_fetch_inc(_Inout_ unsigned int* _Dest) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Dest*<br/>
A localização em memória do valor a ser incrementado.

### <a name="return-value"></a>Valor retornado

O valor original armazenado no local da memória.

## <a name="atomic_fetch_max"></a><a name="atomic_fetch_max"></a>atomic_fetch_max

Computa atomicamente o valor máximo entre o valor armazenado no local de memória especificado no primeiro argumento e o valor especificado no segundo argumento, e armazena-o no mesmo local de memória.

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
O local a partir do qual um dos valores a serem comparados é lido, e para o qual o máximo dos dois valores deve ser armazenado.

*value*<br/>
O valor a ser comparado com o valor no local especificado.

### <a name="return-value"></a>Valor retornado

O valor original armazenado no local especificado.

## <a name="atomic_fetch_min"></a><a name="atomic_fetch_min"></a>atomic_fetch_min

Computa atomicamente o valor mínimo entre o valor armazenado no local de memória especificado no primeiro argumento e o valor especificado no segundo argumento, e armazena-o no mesmo local de memória.

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
O local a partir do qual um dos valores a serem comparados é lido, e para o qual o mínimo dos dois valores deve ser armazenado.

*value*<br/>
O valor a ser comparado com o valor no local especificado.

### <a name="return-value"></a>Valor retornado

O valor original armazenado no local especificado.

## <a name="atomic_fetch_or-function-c-amp"></a><a name="atomic_fetch_or"></a>atomic_fetch_or (C++ AMP)

Atomicamente realiza uma operação ou bitwise com um valor e o valor de um local de memória.

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
O valor a ser usado no cálculo bitwise OR.

### <a name="return-value"></a>Valor retornado

O valor original do local da memória.

## <a name="atomic_fetch_sub-function-c-amp"></a><a name="atomic_fetch_sub"></a>função atomic_fetch_sub (C++ AMP)

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

## <a name="atomic_fetch_xor-function-c-amp"></a><a name="atomic_fetch_xor"></a>atomic_fetch_xor (C++ AMP)

Atomicamente realiza uma operação XOR bitwise de um valor e um local de memória.

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
O valor a ser usado no cálculo XOR.

### <a name="return-value"></a>Valor retornado

O valor original do local da memória.

## <a name="copy"></a><a name="copy"></a>Cópia

Copia um objeto C++ AMP. Todos os requisitos de transferência de dados síncronos são atendidos. Você não pode copiar dados ao executar código em um acelerador. A forma geral desta `copy(src, dest)`função é.

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
Um ativador de saída para a posição inicial no destino.

*Inseriterador*<br/>
O tipo do iterador de entrada.

*Iterator de saída*<br/>
O tipo do ativador de saída.

*_Rank*<br/>
A classificação do objeto a ser copiado ou o objeto a ser copiado.

*_Src*<br/>
Para se opor a copiar.

*_SrcFirst*<br/>
Um ativador inicial no recipiente de origem.

*_SrcLast*<br/>
Um ativador final no recipiente de origem.

*Value_type*<br/>
O tipo de dados dos elementos copiados.

## <a name="copy_async"></a><a name="copy_async"></a>copy_async

Copia um objeto C++ AMP e retorna um objeto [completion_future](completion-future-class.md) que pode ser aguardado. Você não pode copiar dados ao executar código em um acelerador.  A forma geral desta `copy(src, dest)`função é.

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
Um ativador de saída para a posição inicial no destino.

*Inseriterador*<br/>
O tipo do iterador de entrada.

*Iterator de saída*<br/>
O tipo do ativador de saída.

*_Rank*<br/>
A classificação do objeto a ser copiado ou o objeto a ser copiado.

*_Src*<br/>
Para se opor a copiar.

*_SrcFirst*<br/>
Um ativador inicial no recipiente de origem.

*_SrcLast*<br/>
Um ativador final no recipiente de origem.

*Value_type*<br/>
O tipo de dados dos elementos copiados.

### <a name="return-value"></a>Valor retornado

Um `future<void>` que pode ser esperado.

## <a name="direct3d_abort"></a><a name="direct3d_abort"></a>direct3d_abort

Aborta a execução de `restrict(amp)` uma função com a cláusula de restrição. Quando o tempo de execução AMP detecta a chamada, ele levanta uma [runtime_exception](runtime-exception-class.md) exceção com a mensagem de erro "Rasterizador de referência: shader abort instrução hit".

```cpp
void direct3d_abort() restrict(amp);
```

## <a name="direct3d_errorf"></a><a name="direct3d_errorf"></a>direct3d_errorf

Imprime uma seqüência formatada na janela de saída do Visual Studio. É chamado de uma `restrict(amp)` função com a cláusula de restrição. Quando o tempo de execução AMP detecta a chamada, ele levanta uma [exceção runtime_exception](runtime-exception-class.md) com a mesma seqüência de formatação.

```cpp
void direct3d_errorf(
    const char *,
...) restrict(amp);
```

## <a name="direct3d_printf"></a><a name="direct3d_printf"></a>direct3d_printf

Imprime uma seqüência formatada na janela de saída do Visual Studio. É chamado de uma `restrict(amp)` função com a cláusula de restrição.

```cpp
void direct3d_printf(
    const char *,
...) restrict(amp);
```

## <a name="global_memory_fence"></a><a name="global_memory_fence"></a>global_memory_fence

Bloqueia a execução de todos os segmentos em um ladrilho até que todos os acessos de memória global tenham sido concluídos. Isso garante que os acessos de memória globais sejam visíveis a outros segmentos no bloco de segmentos e sejam executados em ordem de programa.

```cpp
inline void global_memory_fence(const tile_barrier& _Barrier) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Barrier*<br/>
Um objeto tile_barrier

## <a name="parallel_for_each-function-c-amp"></a><a name="parallel_for_each"></a>função parallel_for_each (C++ AMP)

Executa uma função em todo o domínio da computação. Para obter mais informações, consulte [C++ AMP Overview](../../../parallel/amp/cpp-amp-overview.md).

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
O `accelerator_view` objeto para executar a computação paralela.

*_Compute_domain*<br/>
Um `extent` objeto que contém os dados para a computação.

*_Dim0*<br/>
A dimensão `tiled_extent` do objeto.

*_Dim1*<br/>
A dimensão `tiled_extent` do objeto.

*_Dim2*<br/>
A dimensão `tiled_extent` do objeto.

*_Kernel*<br/>
Um objeto lambda ou função que pega\<um argumento do tipo "índice _Rank>" e executa a computação paralela.

*_Kernel_type*<br/>
Uma lambda ou functor.

*_Rank*<br/>
A classificação da extensão.

## <a name="tile_static_memory_fence"></a><a name="tile_static_memory_fence"></a>tile_static_memory_fence

Bloqueia a execução de todos os `tile_static` segmentos em um ladrilho até que todos os acessos de memória pendentes tenham sido concluídos. Isso garante `tile_static` que os acessos de memória sejam visíveis para outros segmentos no bloco de segmentos e que os acessos sejam executados em ordem de programa.

```cpp
inline void tile_static_memory_fence(const tile_barrier& _Barrier) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Barrier*<br/>
Um objeto tile_barrier.

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
