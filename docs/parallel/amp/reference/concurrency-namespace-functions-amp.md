---
title: "Funções de namespace de simultaneidade (AMP) | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 22ba62ab8b3b4f9d14953dbab3edd8228ea85193
ms.openlocfilehash: a976cc06b49b10d5bb8dcecb10e114efdd89faa8
ms.lasthandoff: 02/25/2017

---
# <a name="concurrency-namespace-functions-amp"></a>Funções de namespace de simultaneidade (AMP)
||||  
|-|-|-|  
|[all_memory_fence](#all_memory_fence)|[amp_uninitialize](#amp_uninitialize)|[atomic_compare_exchange](#atomic_compare_exchange)|  
|[Função atomic_exchange (C++ AMP)](#atomic_exchange)|[Função atomic_fetch_add (C++ AMP)](#atomic_fetch_add)|[Função atomic_fetch_and (C++ AMP)](#atomic_fetch_and)|  
|[atomic_fetch_dec](#atomic_fetch_dec)|[atomic_fetch_inc](#atomic_fetch_inc)|[atomic_fetch_max](#atomic_fetch_max)|  
|[atomic_fetch_min](#atomic_fetch_min)|[Função atomic_fetch_or (C++ AMP)](#atomic_fetch_or)|[Função atomic_fetch_sub (C++ AMP)](#atomic_fetch_sub)|  
|[Função atomic_fetch_xor (C++ AMP)](#atomic_fetch_xor)|[copy](#copy)|[copy_async](#copy_async)|  
|[direct3d_abort](#direct3d_abort)|[direct3d_errorf](#direct3d_errorf)|[direct3d_printf](#direct3d_printf)|  
|[global_memory_fence](#global_memory_fence)|[Função parallel_for_each (C++ AMP)](#parallel_for_each)|[tile_static_memory_fence](#tile_static_memory_fence)|  
  
##  <a name="all_memory_fence"></a>all_memory_fence  
 Bloqueia a execução de todos os threads em um bloco até que todos os acessos de memória foram concluídos. Isso garante que todos os acessos de memória são visíveis a outros threads no bloco de thread e são executados em ordem de programa.  
  
```  
inline void all_memory_fence(const tile_barrier& _Barrier) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Barrier`  
 Um objeto `tile_barrier`.  
  
##  <a name="amp_uninitialize"></a>amp_uninitialize  
 O tempo de execução C++ AMP cancela a inicialização. É legal para chamar essa função várias vezes durante um ciclo de vida de aplicativos. Chamar qualquer depois de API do C++ AMP chamar essa função, o tempo de execução C++ AMP será reinicializado. Observe que não é possível usar objetos C++ AMP em chamadas a essa função e fazer isso irá resultar em um comportamento indefinido. Além disso, simultaneamente, chamar essa função e quaisquer outras APIs AMP é ilegal e resultaria em um comportamento indefinido.  
  
```  
void __cdecl amp_uninitialize();
```  
  
##  <a name="atomic_compare_exchange"></a>atomic_compare_exchange  
 Atomicamente compara o valor armazenado em um local de memória especificado no primeiro argumento para igualdade com o valor do segundo argumento especificado e se os valores forem iguais, o valor no local de memória é alterado para que, da terceira especificado argumento.  
  
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
 `_Dest`  
 O local do qual um dos valores a ser comparada é lido e ao qual o novo valor, se houver, está a ser armazenado.  
  
 `_Expected_value`  
 O local do qual o segundo valor a ser comparado é lido.  
  
 `value`  
 O valor a ser armazenado no local de memória especificado por `_Dest` se `_Dest` é igual a `_Expected_value`.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se a operação for bem-sucedida; caso contrário, `false`.  
  

##  <a name="atomic_exchange"></a>Função atomic_exchange (C++ AMP)  
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
 `_Dest`  
 Ponteiro para o local de destino.  
  
 `value`  
 O novo valor.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor original do local de destino.  
  

##  <a name="atomic_fetch_add"></a>Função atomic_fetch_add (C++ AMP)  
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
 `_Dest`  
 Ponteiro para o local da memória.  
  
 `value`  
 O valor a ser adicionado.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor original do local da memória.  
  
##  <a name="atomic_fetch_and"></a>Função atomic_fetch_and (C++ AMP)  
 Atomicamente realiza uma operação AND bit a bit de um valor e o valor de um local de memória.  
  
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
 `_Dest`  
 Ponteiro para o local da memória.  
  
 `value`  
 O valor a ser usado no cálculo AND bit a bit.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor original do local da memória.  
  
##  <a name="atomic_fetch_dec"></a>atomic_fetch_dec  
 Atomicamente diminui o valor armazenado no local de memória especificado.  
  
```  
inline int atomic_fetch_dec(_Inout_ int* _Dest  
    ) restrict(amp)

 
inline unsigned int atomic_fetch_dec(_Inout_ unsigned int* _Dest) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Dest`  
 O local na memória do valor a ser diminuída.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor original armazenado no local de memória.  
  
##  <a name="atomic_fetch_inc"></a>atomic_fetch_inc  
 Atomicamente incrementa o valor armazenado no local de memória especificado.  
  
```  
inline int atomic_fetch_inc(_Inout_ int* _Dest) restrict(amp);

 
inline unsigned int atomic_fetch_inc(_Inout_ unsigned int* _Dest) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Dest`  
 O local na memória do valor a ser incrementado.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor original armazenado no local de memória.  
  
##  <a name="atomic_fetch_max"></a>atomic_fetch_max  
 Atomicamente calcula o valor máximo entre o valor armazenado no local de memória especificado no primeiro argumento e o valor especificado no segundo argumento e o armazena no mesmo local da memória.  
  
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
 `_Dest`  
 O local do qual um dos valores a ser comparada é lido e ao qual o máximo de dois valores é a ser armazenado.  
  
 `value`  
 O valor a ser comparado com o valor no local especificado.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor original armazenado no local do local especificado.  
  
##  <a name="atomic_fetch_min"></a>atomic_fetch_min  
 Atomicamente calcula o valor mínimo entre o valor armazenado no local de memória especificado no primeiro argumento e o valor especificado no segundo argumento e o armazena no mesmo local da memória.  
  
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
 `_Dest`  
 O local do qual um dos valores a ser comparada é lido e ao qual o mínimo dos dois valores é a ser armazenado.  
  
 `value`  
 O valor a ser comparado com o valor no local especificado.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor original armazenado no local do local especificado.  
  
##  <a name="atomic_fetch_or"></a>Função atomic_fetch_or (C++ AMP)  
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
 `_Dest`  
 Ponteiro para o local da memória.  
  
 `value`  
 O valor a ser usado no cálculo OR bit a bit.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor original do local da memória.  
  
##  <a name="atomic_fetch_sub"></a>Função atomic_fetch_sub (C++ AMP)  
 Atomicamente subtrai um valor de um local de memória.  
  
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
 `_Dest`  
 Ponteiro para o local de destino.  
  
 `value`  
 O valor a ser subtraído.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor original do local da memória.  
  
##  <a name="atomic_fetch_xor"></a>Função atomic_fetch_xor (C++ AMP)  
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
 `_Dest`  
 Ponteiro para o local da memória.  
  
 `value`  
 O valor a ser usado no cálculo XOR.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor original do local da memória.  
  
##  <a name="copy"></a>  copy  
 Copia um objeto C++ AMP. Todos os requisitos de transferência de dados síncrona são atendidos. Não é possível copiar dados durante a execução de código em um acelerador. A forma geral dessa função é `copy(src, dest)`.  
  
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
 `_Dest`  
 O objeto para copiar.  
  
 `_DestIter`  
 Um iterador de saída para a posição de início no destino.  
  
 `InputIterator`  
 O tipo de interator de entrada.  
  
 `OutputIterator`  
 O tipo de iterador de saída.  
  
 `_Rank`  
 A classificação de objeto a ser copiado de ou para copiar para o objeto.  
  
 `_Src`  
 Para copiar o objeto.  
  
 `_SrcFirst`  
 Um iterador de início para o contêiner de origem.  
  
 `_SrcLast`  
 Um iterador final no contêiner de origem.  
  
 `value_type`  
 O tipo de dados dos elementos que são copiados.  
  
##  <a name="copy_async"></a>copy_async  
 Copia um objeto C++ AMP e retorna um [completion_future](completion-future-class.md) objeto que pode ser aguardado. Não é possível copiar dados durante a execução de código em um acelerador.  A forma geral dessa função é `copy(src, dest)`.  
  
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
 `_Dest`  
 O objeto para copiar.  
  
 `_DestIter`  
 Um iterador de saída para a posição de início no destino.  
  
 `InputIterator`  
 O tipo de interator de entrada.  
  
 `OutputIterator`  
 O tipo de iterador de saída.  
  
 `_Rank`  
 A classificação de objeto a ser copiado de ou para copiar para o objeto.  
  
 `_Src`  
 Para copiar o objeto.  
  
 `_SrcFirst`  
 Um iterador de início para o contêiner de origem.  
  
 `_SrcLast`  
 Um iterador final no contêiner de origem.  
  
 `value_type`  
 O tipo de dados dos elementos que são copiados.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `future<void>` que pode ser aguardado.  
  
##  <a name="direct3d_abort"></a>direct3d_abort  
 Anula a execução de uma função com o `restrict(amp)` cláusula de restrição. Quando o tempo de execução AMP detecta a chamada, ele gera uma [runtime_exception](runtime-exception-class.md) exceção com a mensagem de erro "rasterizador de referência: sombreador anular acessos da instrução".  
  
```  
void direct3d_abort() restrict(amp);
```  
  
##  <a name="direct3d_errorf"></a>direct3d_errorf  
 Imprime uma cadeia de caracteres formatada para a janela de saída do Visual Studio. Ele é chamado de uma função com o `restrict(amp)` cláusula de restrição. Quando o tempo de execução AMP detecta a chamada, ele gera uma [runtime_exception](runtime-exception-class.md) exceção com a mesma cadeia de caracteres de formatação.  
  
```  
void direct3d_errorf(
    const char *,  
 ...) restrict(amp);
```  
  
##  <a name="direct3d_printf"></a>direct3d_printf  
 Imprime uma cadeia de caracteres formatada para a janela de saída do Visual Studio. Ele é chamado de uma função com o `restrict(amp)` cláusula de restrição.  
  
```  
void direct3d_printf(
    const char *,  
 ...) restrict(amp);
```  
  
##  <a name="global_memory_fence"></a>global_memory_fence  
 Bloqueia a execução de todos os threads em um bloco até que toda a memória global acessa foram concluídas. Isso garante que os acessos de memória global são visíveis a outros threads no bloco de thread e são executados na ordem do programa.  
  
```  
inline void global_memory_fence(const tile_barrier& _Barrier) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Barrier`  
 Um objeto tile_barrier  
  
##  <a name="parallel_for_each"></a>Função parallel_for_each (C++ AMP)  
 Executa uma função em todo o domínio de computação. Para obter mais informações, consulte [visão geral do C++ AMP](../../../parallel/amp/cpp-amp-overview.md).  
  
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
 `_Accl_view`  
 O `accelerator_view` objeto para executar a computação paralela em.  
  
 `_Compute_domain`  
 Um `extent` objeto que contém os dados para o cálculo.  
  
 `_Dim0`  
 A dimensão do `tiled_extent` objeto.  
  
 `_Dim1`  
 A dimensão do `tiled_extent` objeto.  
  
 `_Dim2`  
 A dimensão do `tiled_extent` objeto.  
  
 `_Kernel`  
 Um objeto de lambda ou função que usa um argumento do tipo "índice\<_Rank >" e executa a computação paralela.  
  
 `_Kernel_type`  
 Um lambda ou functor.  
  
 `_Rank`  
 A classificação da extensão.  
  
##  <a name="tile_static_memory_fence"></a>tile_static_memory_fence  
 Bloqueia a execução de todos os threads em um bloco até que todos os excelentes `tile_static` acessos de memória foram concluídos. Isso garante que `tile_static` acessos de memória são visíveis a outros threads no bloco de thread e acessos são executados em ordem de programa.  
  
```  
inline void tile_static_memory_fence(const tile_barrier& _Barrier) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Barrier`  
 Um objeto tile_barrier.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)

