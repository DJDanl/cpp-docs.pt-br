---
title: Funções do namespace de simultaneidade (AMP) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
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
dev_langs:
- C++
ms.assetid: 2bef0985-cb90-4ece-90b9-66529aec73c9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5bfb25ffeedaa11c6e610978c2d0a15cc3106d79
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50079448"
---
# <a name="concurrency-namespace-functions-amp"></a>Funções do namespace de simultaneidade (AMP)

||||
|-|-|-|
|[all_memory_fence](#all_memory_fence)|[amp_uninitialize](#amp_uninitialize)|[atomic_compare_exchange](#atomic_compare_exchange)|
|[Função (C++ AMP) atomic_exchange](#atomic_exchange)|[Função (C++ AMP) atomic_fetch_add](#atomic_fetch_add)|[Função (C++ AMP) atomic_fetch_and](#atomic_fetch_and)|
|[atomic_fetch_dec](#atomic_fetch_dec)|[atomic_fetch_inc](#atomic_fetch_inc)|[atomic_fetch_max](#atomic_fetch_max)|
|[atomic_fetch_min](#atomic_fetch_min)|[Função (C++ AMP) atomic_fetch_or](#atomic_fetch_or)|[Função (C++ AMP) atomic_fetch_sub](#atomic_fetch_sub)|
|[Função (C++ AMP) atomic_fetch_xor](#atomic_fetch_xor)|[copy](#copy)|[copy_async](#copy_async)|
|[direct3d_abort](#direct3d_abort)|[direct3d_errorf](#direct3d_errorf)|[direct3d_printf](#direct3d_printf)|
|[global_memory_fence](#global_memory_fence)|[Função (C++ AMP) parallel_for_each](#parallel_for_each)|[tile_static_memory_fence](#tile_static_memory_fence)|

##  <a name="all_memory_fence"></a>  all_memory_fence

Impede a execução de todos os threads em um bloco até que todos os acessos de memória sejam concluídos. Isso garante que todos os acessos de memória sejam visíveis para outros threads no quadro de threads e são executados na ordem do programa.

```
inline void all_memory_fence(const tile_barrier& _Barrier) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Barrier*<br/>
Um objeto `tile_barrier`.

##  <a name="amp_uninitialize"></a>  amp_uninitialize

Encerra o tempo de execução C++ AMP. É legal para chamar essa função várias vezes durante um tempo de vida de aplicativos. Chamar qualquer reinicializará do C++ AMP chamar essa função será reinicializado o tempo de execução C++ AMP. Observe que é ilegal usar objetos de C++ AMP entre chamadas para essa função e fazer isso resultará em um comportamento indefinido. Além disso, ao mesmo tempo chamar essa função e quaisquer outras APIs de AMP é ilegal e resultaria em um comportamento indefinido.

```
void __cdecl amp_uninitialize();
```

##  <a name="atomic_compare_exchange"></a>  atomic_compare_exchange

Atomicamente compara o valor armazenado em um local de memória especificado no primeiro argumento para igualdade com o valor do segundo argumento especificado, e se os valores forem iguais, o valor no local da memória é alterado para que do terceiro argumento especificado.

```
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
O local de onde um dos valores a serem comparados é lido e ao qual o novo valor, se houver, deve ser armazenado.

*_Expected_value*<br/>
O local do qual o segundo valor a ser comparado é lido.

*value*<br/>
O valor a ser armazenado para o local de memória especificado por `_Dest` se `_Dest` é igual a `_Expected_value`.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se a operação for bem-sucedida; caso contrário, **falso**.

##  <a name="atomic_exchange"></a>  Função (C++ AMP) atomic_exchange

Define o valor do local de destino como uma operação atômica.

```
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

### <a name="return-value"></a>Valor de retorno

O valor original do local de destino.

##  <a name="atomic_fetch_add"></a>  Função (C++ AMP) atomic_fetch_add

Adicione atomicamente um valor para o valor de um local de memória.

```
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

### <a name="return-value"></a>Valor de retorno

O valor original do local da memória.

##  <a name="atomic_fetch_and"></a>  Função (C++ AMP) atomic_fetch_and

Atomicamente executa uma operação AND bit a bit de um valor e o valor de um local de memória.

```
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
O valor a ser usado no cálculo de AND bit a bit.

### <a name="return-value"></a>Valor de retorno

O valor original do local da memória.

##  <a name="atomic_fetch_dec"></a>  atomic_fetch_dec

Atomicamente diminui o valor armazenado no local da memória especificado.

```
inline int atomic_fetch_dec(_Inout_ int* _Dest
    ) restrict(amp)

inline unsigned int atomic_fetch_dec(_Inout_ unsigned int* _Dest) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Dest*<br/>
O local na memória do valor a ser decrementado.

### <a name="return-value"></a>Valor de retorno

O valor original armazenado no local da memória.

##  <a name="atomic_fetch_inc"></a>  atomic_fetch_inc

Aumenta atomicamente o valor armazenado no local da memória especificado.

```
inline int atomic_fetch_inc(_Inout_ int* _Dest) restrict(amp);

inline unsigned int atomic_fetch_inc(_Inout_ unsigned int* _Dest) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Dest*<br/>
O local na memória do valor a ser incrementado.

### <a name="return-value"></a>Valor de retorno

O valor original armazenado no local da memória.

##  <a name="atomic_fetch_max"></a>  atomic_fetch_max

Atomicamente calcula o valor máximo entre o valor armazenado no local da memória especificado no primeiro argumento e o valor especificado no segundo argumento e armazena-o no mesmo local da memória.

```
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
O local de onde um dos valores a serem comparados é lido e ao qual o número máximo de dois valores deve ser armazenado.

*value*<br/>
O valor a ser comparado com o valor no local especificado.

### <a name="return-value"></a>Valor de retorno

O valor original armazenado no local especificado.

##  <a name="atomic_fetch_min"></a>  atomic_fetch_min

Atomicamente calcula o valor mínimo entre o valor armazenado no local da memória especificado no primeiro argumento e o valor especificado no segundo argumento e armazena-o no mesmo local da memória.

```
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
O local de onde um dos valores a serem comparados é lido e ao qual o mínimo dos dois valores deve ser armazenado.

*value*<br/>
O valor a ser comparado com o valor no local especificado.

### <a name="return-value"></a>Valor de retorno

O valor original armazenado no local especificado.

##  <a name="atomic_fetch_or"></a>  Função (C++ AMP) atomic_fetch_or

Atomicamente executa uma operação OR bit a bit com um valor e o valor de um local de memória.

```
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
O valor a ser usado no cálculo de OR bit a bit.

### <a name="return-value"></a>Valor de retorno

O valor original do local da memória.

##  <a name="atomic_fetch_sub"></a>  Função (C++ AMP) atomic_fetch_sub

Subtrai atomicamente um valor de um local de memória.

```
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

### <a name="return-value"></a>Valor de retorno

O valor original do local da memória.

##  <a name="atomic_fetch_xor"></a>  Função (C++ AMP) atomic_fetch_xor

Peforms atomicamente uma operação XOR bit a bit de um valor e um local de memória.

```
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

### <a name="return-value"></a>Valor de retorno

O valor original do local da memória.

##  <a name="copy"></a>  copy

Copia um objeto C++ AMP. Todos os requisitos de transferência de dados síncronos são atendidos. Você não pode copiar dados ao executar o código em um acelerador. A forma geral dessa função é `copy(src, dest)`.

```
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
O objeto para copiar para.

*_DestIter*<br/>
Um iterador de saída para a posição inicial no destino.

*InputIterator*<br/>
O tipo de iterador de entrada.

*OutputIterator*<br/>
O tipo de iterador de saída.

*_Rank*<br/>
A classificação do objeto para copiar de ou para copiar para o objeto.

*_Src*<br/>
Para o objeto a ser copiado.

*_SrcFirst*<br/>
Um iterador inicial no contêiner de origem.

*_SrcLast*<br/>
Um iterador final no contêiner de origem.

*value_type*<br/>
O tipo de dados dos elementos que são copiados.

##  <a name="copy_async"></a>  copy_async

Copia um objeto C++ AMP e retorna um [completion_future](completion-future-class.md) objeto que pode ser esperado. Você não pode copiar dados ao executar o código em um acelerador.  A forma geral dessa função é `copy(src, dest)`.

```
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
O objeto para copiar para.

*_DestIter*<br/>
Um iterador de saída para a posição inicial no destino.

*InputIterator*<br/>
O tipo de iterador de entrada.

*OutputIterator*<br/>
O tipo de iterador de saída.

*_Rank*<br/>
A classificação do objeto para copiar de ou para copiar para o objeto.

*_Src*<br/>
Para o objeto a ser copiado.

*_SrcFirst*<br/>
Um iterador inicial no contêiner de origem.

*_SrcLast*<br/>
Um iterador final no contêiner de origem.

*value_type*<br/>
O tipo de dados dos elementos que são copiados.

### <a name="return-value"></a>Valor de retorno

Um `future<void>` que pode ser esperado.

##  <a name="direct3d_abort"></a>  direct3d_abort

Anula a execução de uma função com o `restrict(amp)` cláusula de restrição. Quando o tempo de execução de AMP detecta a chamada, ele gera uma [runtime_exception](runtime-exception-class.md) exceção com a mensagem de erro "o rasterizador de referência: sombreador anular a ocorrência de instrução".

```
void direct3d_abort() restrict(amp);
```

##  <a name="direct3d_errorf"></a>  direct3d_errorf

Imprime uma cadeia de caracteres formatada na janela de saída do Visual Studio. Ele é chamado de uma função com o `restrict(amp)` cláusula de restrição. Quando o tempo de execução de AMP detecta a chamada, ele gera uma [runtime_exception](runtime-exception-class.md) exceção com a mesma cadeia de caracteres de formatação.

```
void direct3d_errorf(
    const char *,
...) restrict(amp);
```

##  <a name="direct3d_printf"></a>  direct3d_printf

Imprime uma cadeia de caracteres formatada na janela de saída do Visual Studio. Ele é chamado de uma função com o `restrict(amp)` cláusula de restrição.

```
void direct3d_printf(
    const char *,
...) restrict(amp);
```

##  <a name="global_memory_fence"></a>  global_memory_fence

Impede a execução de todos os threads em um bloco até que toda a memória global acessa tenha sido concluído. Isso garante que os acessos de memória global sejam visíveis para outros threads no quadro de threads e são executados na ordem do programa.

```
inline void global_memory_fence(const tile_barrier& _Barrier) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Barrier*<br/>
Um objeto tile_barrier

##  <a name="parallel_for_each"></a>  Função (C++ AMP) parallel_for_each

Executa uma função entre o domínio de cálculo. Para obter mais informações, consulte [visão geral do C++ AMP](../../../parallel/amp/cpp-amp-overview.md).

```
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
Um `extent` objeto que contém os dados para o cálculo.

*_Dim0*<br/>
A dimensão do `tiled_extent` objeto.

*_Dim1*<br/>
A dimensão do `tiled_extent` objeto.

*_Dim2*<br/>
A dimensão do `tiled_extent` objeto.

*_Kernel*<br/>
Um objeto lambda ou função que usa um argumento do tipo "índice\<_Rank >" e executa a computação paralela.

*_Kernel_type*<br/>
Um lambda ou functor.

*_Rank*<br/>
A classificação da extensão.

##  <a name="tile_static_memory_fence"></a>  tile_static_memory_fence

Impede a execução de todos os threads em um bloco até que todos os pendentes `tile_static` acessos de memória sejam concluídos. Isso garante que `tile_static` acessos de memória sejam visíveis para outros threads no quadro de threads e que os acessos sejam executados na ordem do programa.

```
inline void tile_static_memory_fence(const tile_barrier& _Barrier) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Barrier*<br/>
Um objeto tile_barrier.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
