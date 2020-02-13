---
title: Classe array
ms.date: 11/04/2016
f1_keywords:
- array
- AMP/array
- AMP/Concurrency::array::array
- AMP/Concurrency::array::copy_to
- AMP/Concurrency::array::data
- AMP/Concurrency::array::get_accelerator_view
- AMP/Concurrency::array::get_associated_accelerator_view
- AMP/Concurrency::array::get_cpu_access_type
- AMP/Concurrency::array::get_extent
- AMP/Concurrency::array::reinterpret_as
- AMP/Concurrency::array::section
- AMP/Concurrency::array::view_as
- AMP/Concurrency::array::rank
- AMP/Concurrency::array::accelerator_view
- AMP/Concurrency::array::associated_accelerator_view
- AMP/Concurrency::array::cpu_access_type
- AMP/Concurrency::array::extent
helpviewer_keywords:
- array class
ms.assetid: 0832b6c1-40f0-421d-9104-6b1baa0c63a7
ms.openlocfilehash: efea8dabb69a48e69d68a86110fdf9bc7664948b
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77127106"
---
# <a name="array-class"></a>Classe array

Representa um contêiner de dados usado para mover dados para um acelerador.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename value_type, int _Rank>
friend class array;
```

### <a name="parameters"></a>Parâmetros

*value_type*<br/>
O tipo de elemento dos dados.

*_Rank*<br/>
A classificação da matriz.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Construtor de matriz](#ctor)|Inicializa uma nova instância da classe `array`.|
|[~ Destruidor de matriz](#dtor)|Destrói o objeto `array`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[copy_to](#copy_to)|Copia o conteúdo da matriz para outra matriz.|
|[data](#data)|Retorna um ponteiro para os dados brutos da matriz.|
|[get_accelerator_view](#get_accelerator_view)|Retorna o objeto [accelerator_view](accelerator-view-class.md) que representa o local onde a matriz está alocada. Essa propriedade pode ser acessada somente na CPU.|
|[get_associated_accelerator_view](#get_associated_accelerator_view)|Obtém o segundo objeto [accelerator_view](accelerator-view-class.md) que é passado como um parâmetro quando um construtor de preparo é chamado para instanciar o objeto `array`.|
|[get_cpu_access_type](#get_cpu_access_type)|Retorna o [access_type](concurrency-namespace-enums-amp.md#access_type) da matriz. Esse método pode ser acessado somente na CPU.|
|[get_extent](#get_extent)|Retorna o objeto de [extensão](extent-class.md) da matriz.|
|[reinterpret_as](#reinterpret_as)|Retorna uma matriz unidimensional que contém todos os elementos no objeto `array`.|
|[seção](#section)|Retorna uma subseção do objeto `array` que está na origem especificada e, opcionalmente, que tem a extensão especificada.|
|[view_as](#view_as)|Retorna um objeto [array_view](array-view-class.md) que é construído a partir do objeto `array`.|

### <a name="public-operators"></a>Operadores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[operador std:: vector&lt;value_type&gt;](#operator_vec)|Usa `copy(*this, vector)` para converter implicitamente a matriz em um objeto std::[vector](../../../standard-library/vector-class.md) .|
|[operator()](#operator_call)|Retorna o valor do elemento que é especificado pelos parâmetros.|
|[operator\[\]](#operator_at)|Retorna o elemento que está no índice especificado.|
|[operator=](#operator_eq)|Copia o conteúdo do objeto `array` especificado para este.|

### <a name="public-constants"></a>Constantes Públicas

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Constante de classificação](#rank)|Armazena a classificação da matriz.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[accelerator_view](#accelerator_view)|Obtém o objeto [accelerator_view](accelerator-view-class.md) que representa o local onde a matriz está alocada. Essa propriedade pode ser acessada somente na CPU.|
|[associated_accelerator_view](#associated_accelerator_view)|Obtém o segundo objeto [accelerator_view](accelerator-view-class.md) que é passado como um parâmetro quando um construtor de preparo é chamado para instanciar o objeto `array`.|
|[cpu_access_type](#cpu_access_type)|Obtém o [access_type](concurrency-namespace-enums-amp.md#access_type) que representa como a CPU pode acessar o armazenamento da matriz.|
|[extent](#extent)|Obtém a extensão que define a forma da matriz.|

## <a name="remarks"></a>Comentários

O tipo `array<T,N>` representa uma matriz *N*-dimensional densa e regular (não denteada) que está localizada em um local específico, como um acelerador ou a CPU. O tipo de dados dos elementos na matriz é `T`, que deve ser de um tipo compatível com o acelerador de destino. Embora a classificação, `N`, (da matriz seja determinada de forma estática e seja parte do tipo, a extensão da matriz é determinada pelo tempo de execução e é expressa usando `extent<N>`de classe.

Uma matriz pode ter qualquer número de dimensões, embora algumas funcionalidades sejam especializadas para `array` objetos com a classificação um, dois e três. Se você omitir o argumento de dimensão, o padrão será 1.

Os dados da matriz são dispostos de forma contígua na memória. Elementos que diferem em um na dimensão menos significativa são adjacentes na memória.

As matrizes são logicamente consideradas como tipos de valor, porque quando uma matriz é copiada para outra matriz, uma cópia profunda é executada. Duas matrizes nunca apontam para os mesmos dados.

O tipo de `array<T,N>` é usado em vários cenários:

- Como um contêiner de dados que pode ser usado em cálculos em um acelerador.

- Como um contêiner de dados para manter a memória na CPU do host (que pode ser usada para copiar de e para outras matrizes).

- Como um objeto de preparação para atuar como um intermediário rápido em cópias de host para dispositivo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`array`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** amp. h

**Namespace:** Simultaneidade

## <a name="dtor"></a>~ matriz

Destrói o objeto `array`.

```cpp
~array() restrict(cpu);
```

## <a name="accelerator_view"></a>accelerator_view

Obtém o objeto [accelerator_view](accelerator-view-class.md) que representa o local onde a matriz está alocada. Essa propriedade pode ser acessada somente na CPU.

```cpp
__declspec(property(get= get_accelerator_view)) Concurrency::accelerator_view accelerator_view;
```

## <a name="ctor"></a>variedade

Inicializa uma nova instância da [classe de matriz](array-class.md). Não há construtor padrão para `array<T,N>`. Todos os construtores são executados somente na CPU. Eles não podem ser executados em um destino Direct3D.

```cpp
explicit array(
    const Concurrency::extent<_Rank>& _Extent) restrict(cpu);

explicit array(
    int _E0) restrict(cpu);

explicit array(
    int _E0,
    int _E1) restrict(cpu);

explicit array(
    int _E0,
    int _E1,
    int _E2) restrict(cpu);

array(
    const Concurrency::extent<_Rank>& _Extent,
    Concurrency::accelerator_view _Av
    access_type _Cpu_access_type = access_type_auto) restrict(cpu);

array(
    int _E0,
    Concurrency::accelerator_view _Av
    access_type _Cpu_access_type = access_type_auto) restrict(cpu);

array(
    int _E0,
    int _E1,
    Concurrency::accelerator_view _Av
    access_type _Cpu_access_type = access_type_auto) restrict(cpu);

array(
    int _E0,
    int _E1,
    int _E2,
    Concurrency::accelerator_view _Av
    access_type _Cpu_access_type = access_type_auto) restrict(cpu);

array(
    const Concurrency::extent<_Rank>& _Extent,
    Concurrency::accelerator_view _Av,
    Concurrency::accelerator_view _Associated_Av) restrict(cpu);

array(
    int _E0,
    accelerator_view _Av,
    Concurrency::accelerator_view _Associated_Av) restrict(cpu);

array(
    int _E0,
    int _E1,
    Concurrency::accelerator_view _Av,
    Concurrency::accelerator_view _Associated_Av) restrict(cpu);

array(
    int _E0,
    int _E1,
    int _E2,
    Concurrency::accelerator_view _Av,
    Concurrency::accelerator_view _Associated_Av) restrict(cpu);

template <typename _InputIterator>
array(
    const Concurrency::extent<_Rank>& _Extent,
    _InputIterator _Src_first,
    _InputIterator _Src_last) restrict(cpu);

template <typename _InputIterator>
array(
    const Concurrency::extent<_Rank>& _Extent,
    _InputIterator _Src_first) restrict(cpu);

template <typename _InputIterator>
array(
    int _E0,
    _InputIterator _Src_first,
    _InputIterator _Src_last) restrict(cpu);

template <typename _InputIterator>
array(
    int _E0,
    _InputIterator _Src_first) restrict(cpu);

template <typename _InputIterator>
array(
    int _E0,
    int _E1,
    _InputIterator _Src_first,
    _InputIterator _Src_last) restrict(cpu);

template <typename _InputIterator>
array(
    int _E0,
    int _E1,
    _InputIterator _Src_first) restrict(cpu);

template <typename _InputIterator>
array(
    int _E0,
    int _E1,
    int _E2,
    _InputIterator _Src_first,
    _InputIterator _Src_last) restrict(cpu);

template <typename _InputIterator>
array(
    int _E0,
    int _E1,
    int _E2,
    _InputIterator _Src_first) restrict(cpu);

template <typename _InputIterator>
array(
    const Concurrency::extent<_Rank>& _Extent,
    _InputIterator _Src_first,
    _InputIterator _Src_last,
    Concurrency::accelerator_view _Av
    access_type _Cpu_access_type = access_type_auto) restrict(cpu);

template <typename _InputIterator>
array(
    const Concurrency::extent<_Rank>& _Extent,
    _InputIterator _Src_first,
    Concurrency::accelerator_view _Av
    access_type _Cpu_access_type = access_type_auto) restrict(cpu);

template <typename _InputIterator>
array(
    int _E0,
    _InputIterator _Src_first,
    _InputIterator _Src_last,
    Concurrency::accelerator_view _Av
    access_type _Cpu_access_type = access_type_auto) restrict(cpu);

template <typename _InputIterator>
array(
    int _E0,
    _InputIterator _Src_first,
    Concurrency::accelerator_view _Av
    access_type _Cpu_access_type = access_type_auto) restrict(cpu);

template <typename _InputIterator>
array(
    int _E0,
    int _E1,
    _InputIterator _Src_first,
    _InputIterator _Src_last,
    Concurrency::accelerator_view _Av
    access_type _Cpu_access_type = access_type_auto) restrict(cpu);

template <typename _InputIterator>
array(
    int _E0,
    int _E1,
    _InputIterator _Src_first,
    Concurrency::accelerator_view _Av
    access_type _Cpu_access_type = access_type_auto) restrict(cpu);

template <typename _InputIterator>
array(
    int _E0,
    int _E1,
    int _E2,
    _InputIterator _Src_first,
    _InputIterator _Src_last,
    Concurrency::accelerator_view _Av,
    access_type _Cpu_access_type = access_type_auto) restrict(cpu);

template <typename _InputIterator>
array(
    int _E0,
    int _E1,
    int _E2,
    _InputIterator _Src_first,
    Concurrency::accelerator_view _Av
    access_type _Cpu_access_type = access_type_auto) restrict(cpu);

template <typename _InputIterator>
array(
    const Concurrency::extent<_Rank>& _Extent,
    _InputIterator _Src_first,
    _InputIterator _Src_last,
    Concurrency::accelerator_view _Av,
    Concurrency::accelerator_view _Associated_Av) restrict(cpu);

template <typename _InputIterator>
array(
    const Concurrency::extent<_Rank>& _Extent,
    _InputIterator _Src_first,
    Concurrency::accelerator_view _Av,
    Concurrency::accelerator_view _Associated_Av) restrict(cpu);

template <typename _InputIterator>
array(
    int _E0,
    _InputIterator _Src_first,
    _InputIterator _Src_last,
    Concurrency::accelerator_view _Av,
    Concurrency::accelerator_view _Associated_Av) restrict(cpu);

template <typename _InputIterator>
array(
    int _E0, _InputIterator _Src_first,
    Concurrency::accelerator_view _Av,
    Concurrency::accelerator_view _Associated_Av) restrict(cpu);

template <typename _InputIterator>
array(
    int _E0,
    int _E1, _InputIterator _Src_first, _InputIterator _Src_last,
    Concurrency::accelerator_view _Av,
    Concurrency::accelerator_view _Associated_Av) restrict(cpu);

template <typename _InputIterator>
array(
    int _E0,
    int _E1, _InputIterator _Src_first,
    Concurrency::accelerator_view _Av,
    Concurrency::accelerator_view _Associated_Av) restrict(cpu);

template <typename _InputIterator>
array(
    int _E0,
    int _E1,
    int _E2, _InputIterator _Src_first, _InputIterator _Src_last,
    Concurrency::accelerator_view _Av,
    Concurrency::accelerator_view _Associated_Av) restrict(cpu);

template <typename _InputIterator>
array(
    int _E0,
    int _E1,
    int _E2, _InputIterator _Src_first,
    Concurrency::accelerator_view _Av,
    Concurrency::accelerator_view _Associated_Av) restrict(cpu);

explicit array(
    const array_view<const value_type, _Rank>& _Src) restrict(cpu);

array(
    const array_view<const value_type, _Rank>& _Src,
    accelerator_view _Av
    access_type _Cpu_access_type = access_type_auto) restrict(cpu);

array(
    const array_view<const value_type, _Rank>& _Src,
    accelerator_view _Av,
    accelerator_view _Associated_Av) restrict(cpu);

array(const array& _Other) restrict(cpu);

array(array&& _Other) restrict(cpu);
```

### <a name="parameters"></a>Parâmetros

*_Associated_Av*<br/>
Um accelerator_view que especifica o local de destino preferencial da matriz.

*_Av*<br/>
Um objeto [accelerator_view](accelerator-view-class.md) que especifica o local da matriz.

*_Cpu_access_type*<br/>
O [access_type](concurrency-namespace-enums-amp.md#access_type) desejado para a matriz na CPU. Esse parâmetro tem um valor padrão de `access_type_auto` deixar a CPU `access_type` determinação para o tempo de execução. O `access_type` de CPU real para a matriz pode ser consultado usando o método `get_cpu_access_type`.

*_Extent*<br/>
A extensão em cada dimensão da matriz.

*_E0*<br/>
O componente mais significativo da extensão desta seção.

*_E1*<br/>
O componente do próximo a mais significativo da extensão desta seção.

*_E2*<br/>
O componente menos significativo da extensão desta seção.

*_InputIterator*<br/>
O tipo do iterador de entrada.

*_Src*<br/>
Para o objeto a ser copiado.

*_Src_first*<br/>
Um iterador inicial no contêiner de origem.

*_Src_last*<br/>
Um iterador final no contêiner de origem.

*_Other*<br/>
Outra fonte de dados.

*_Rank*<br/>
A classificação da seção.

*value_type*<br/>
O tipo de dados dos elementos que são copiados.

## <a name="associated_accelerator_view"></a>associated_accelerator_view

Obtém o segundo objeto [accelerator_view](accelerator-view-class.md) que é passado como um parâmetro quando um construtor de preparo é chamado para instanciar o objeto `array`.

```cpp
__declspec(property(get= get_associated_accelerator_view)) Concurrency::accelerator_view associated_accelerator_view;
```

## <a name="copy_to"></a>copy_to

Copia o conteúdo do `array` para outro `array`.

```cpp
void copy_to(
    array<value_type, _Rank>& _Dest) const ;

void copy_to(
    array_view<value_type, _Rank>& _Dest) const ;
```

### <a name="parameters"></a>Parâmetros

*_Dest*<br/>
O objeto de [array_view](array-view-class.md) para o qual copiar.

## <a name="cpu_access_type"></a>cpu_access_type

Obtém a access_type de CPU permitida para esta matriz.

```cpp
__declspec(property(get= get_cpu_access_type)) access_type cpu_access_type;
```

## <a name="data"></a>dado

Retorna um ponteiro para os dados brutos da `array`.

```cpp
value_type* data() restrict(amp, cpu);

const value_type* data() const restrict(amp, cpu);
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para os dados brutos da matriz.

## <a name="extent"></a>tention

Obtém o objeto de [extensão](extent-class.md) que define a forma do `array`.

```cpp
__declspec(property(get= get_extent)) Concurrency::extent<_Rank> extent;
```

## <a name="get_accelerator_view"></a>get_accelerator_view

Retorna o objeto [accelerator_view](accelerator-view-class.md) que representa o local onde o objeto `array` está alocado. Essa propriedade pode ser acessada somente na CPU.

```cpp
Concurrency::accelerator_view get_accelerator_view() const;
```

### <a name="return-value"></a>Valor retornado

O objeto `accelerator_view` que representa o local onde o objeto `array` está alocado.

## <a name="get_associated_accelerator_view"></a>get_associated_accelerator_view

Obtém o segundo objeto [accelerator_view](accelerator-view-class.md) que é passado como um parâmetro quando um construtor de preparo é chamado para instanciar o objeto `array`.

```cpp
Concurrency::accelerator_view get_associated_accelerator_view() const ;
```

### <a name="return-value"></a>Valor retornado

O segundo objeto [accelerator_view](accelerator-view-class.md) passado para o construtor de preparo.

## <a name="get_cpu_access_type"></a>get_cpu_access_type

Retorna o access_type de CPU permitido para esta matriz.

```cpp
access_type get_cpu_access_type() const restrict(cpu);
```

### <a name="return-value"></a>Valor retornado

## <a name="get_extent"></a>get_extent

Retorna o objeto de [extensão](extent-class.md) do `array`.

```cpp
Concurrency::extent<_Rank> get_extent() const restrict(amp,cpu);
```

### <a name="return-value"></a>Valor retornado

O objeto `extent` do objeto `array`.

## <a name="operator_vec"></a>operador std:: vector&lt;value_type&gt;

Usa `copy(*this, vector)` para converter implicitamente a matriz em um objeto std:: vector.

```cpp
operator std::vector<value_type>() const restrict(cpu);
```

### <a name="parameters"></a>Parâmetros

*value_type*<br/>
O tipo de dados dos elementos do vetor.

### <a name="return-value"></a>Valor retornado

Um objeto do tipo `vector<T>` que contém uma cópia dos dados contidos na matriz.

## <a name="operator_call"></a>operador ()

Retorna o valor do elemento que é especificado pelos parâmetros.

```cpp
value_type& operator() (const index<_Rank>& _Index) restrict(amp,cpu);

const value_type& operator() (const index<_Rank>& _Index) cons  t restrict(amp,cpu);

value_type& operator() (int _I0, int _I1) restrict(amp,cpu);

const value_type& operator() (int _I0, int _I1) const restrict(amp,cpu)  ;

value_type& operator() (int _I0, int _I1, int _I2) restrict(amp,cpu);

const value_type& operator() (int _I0, int _I1, int _I2) const restrict(amp,cpu);

typename details::_Projection_result_type<value_type,_Rank>::_Result_type operator()(int _I) restrict(amp,cpu);

typename details::_Projection_result_type<value_type,_Rank>::_Const_result_type operator()(int _I) const restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Index*<br/>
O local do elemento.

*_I0*<br/>
O componente mais significativo da origem desta seção.

*_I1*<br/>
O componente do próximo a mais significativo da origem desta seção.

*_I2*<br/>
O componente menos significativo da origem desta seção.

*_I*<br/>
O local do elemento.

### <a name="return-value"></a>Valor retornado

O valor do elemento especificado pelos parâmetros.

## <a name="operator_at"></a>operador []

Retorna o elemento que está no índice especificado.

```cpp
value_type& operator[](const index<_Rank>& _Index) restrict(amp,cpu);

const value_type& operator[]
    (const index<_Rank>& _Index) const restrict(amp,cpu);

typename details::_Projection_result_type<value_type,_Rank>::_Result_type operator[](int _i) restrict(amp,cpu);

typename details::_Projection_result_type<value_type,_Rank>::_Const_result_type operator[](int _i) const restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Index*<br/>
O índice.

*_I*<br/>
O índice.

### <a name="return-value"></a>Valor retornado

O elemento que está no índice especificado.

## <a name="operator_eq"></a>operador =

Copia o conteúdo do objeto de `array` especificado.

```cpp
array& operator= (const array& _Other) restrict(cpu);

array& operator= (array&& _Other) restrict(cpu);

array& operator= (
    const array_view<const value_type, _Rank>& _Src) restrict(cpu);
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
O objeto `array` do qual copiar.

*_Src*<br/>
O objeto `array` do qual copiar.

### <a name="return-value"></a>Valor retornado

Uma referência a este objeto de `array`.

## <a name="rank"></a>Fique

Armazena a classificação da `array`.

```cpp
static const int rank = _Rank;
```

## <a name="reinterpret_as"></a>reinterpret_as

Reinterpreta a matriz por meio de um array_view unidimensional, que opcionalmente pode ter um tipo de valor diferente da matriz de origem.

### <a name="syntax"></a>Sintaxe

```cpp
template <typename _Value_type2>
array_view<_Value_type2,1> reinterpret_as() restrict(amp,cpu);

template <typename _Value_type2>
array_view<const _Value_type2, 1> reinterpret_as() const restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Value_type2*<br/>
O tipo de dados dos dados retornados.

### <a name="return-value"></a>Valor retornado

Um objeto array_view ou const array_view que se baseia na matriz, com o tipo de elemento reinterpreta de T para ElementType e a classificação reduzida de N para 1.

### <a name="remarks"></a>Comentários

Às vezes, é conveniente exibir uma matriz multidimensional como se fosse uma matriz linear e unidimensional, possivelmente com um tipo de valor diferente da matriz de origem. Você pode usar esse método para conseguir isso.
**Cuidado** A reinterpretação de um objeto de matriz usando um tipo de valor diferente é uma operação potencialmente não segura. Recomendamos que você use essa funcionalidade com cuidado.

O código a seguir fornece um exemplo.

```cpp
struct RGB { float r; float g; float b; };

array<RGB,3>  a = ...;
array_view<float,1> v = a.reinterpret_as<float>();

assert(v.extent == 3*a.extent);
```

## <a name="section"></a>Section

Retorna uma subseção do objeto `array` que está na origem especificada e, opcionalmente, que tem a extensão especificada.

```cpp
array_view<value_type,_Rank> section(
    const Concurrency::index<_Rank>& _Section_origin,
    const Concurrency::extent<_Rank>& _Section_extent) restrict(amp,cpu);

array_view<const value_type,_Rank> section(
    const Concurrency::index<_Rank>& _Section_origin,
    const Concurrency::extent<_Rank>& _Section_extent) const restrict(amp,cpu);

array_view<value_type,_Rank> section(
    const Concurrency::extent<_Rank>& _Ext) restrict(amp,cpu);

array_view<const value_type,_Rank> section(
    const Concurrency::extent<_Rank>& _Ext) const restrict(amp,cpu);

array_view<value_type,_Rank> section(
    const index<_Rank>& _Idx) restrict(amp,cpu);

array_view<const value_type,_Rank> section(
    const index<_Rank>& _Idx) const restrict(amp,cpu);

array_view<value_type,1> section(
    int _I0,
    int _E0) restrict(amp,cpu);

array_view<const value_type,1> section(
    int _I0,
    int _E0) const restrict(amp,cpu);

array_view<value_type,2> section(
    int _I0,
    int _I1,
    int _E0,
    int _E1) restrict(amp,cpu);

array_view<const value_type,2> section(
    int _I0,
    int _I1,
    int _E0,
    int _E1) const restrict(amp,cpu);

array_view<value_type,3> section(
    int _I0,
    int _I1,
    int _I2,
    int _E0,
    int _E1,
    int _E2) restrict(amp,cpu);

array_view<const value_type,3> section(
    int _I0,
    int _I1,
    int _I2,
    int _E0,
    int _E1,
    int _E2) const restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_E0*<br/>
O componente mais significativo da extensão desta seção.

*_E1*<br/>
O componente do próximo a mais significativo da extensão desta seção.

*_E2*<br/>
O componente menos significativo da extensão desta seção.

*_Ext*<br/>
O objeto de [extensão](extent-class.md) que especifica a extensão da seção. A origem é 0.

*_Idx*<br/>
O objeto de [índice](index-class.md) que especifica o local da origem. A subseção é o restante da extensão.

*_I0*<br/>
O componente mais significativo da origem desta seção.

*_I1*<br/>
O componente do próximo a mais significativo da origem desta seção.

*_I2*<br/>
O componente menos significativo da origem desta seção.

*_Rank*<br/>
A classificação da seção.

*_Section_extent*<br/>
O objeto de [extensão](extent-class.md) que especifica a extensão da seção.

*_Section_origin*<br/>
O objeto de [índice](index-class.md) que especifica o local da origem.

*value_type*<br/>
O tipo de dados dos elementos que são copiados.

### <a name="return-value"></a>Valor retornado

Retorna uma subseção do objeto `array` que está na origem especificada e, opcionalmente, que tem a extensão especificada. Quando apenas o objeto `index` é especificado, a subseção contém todos os elementos na grade associada que têm índices maiores do que os índices dos elementos no objeto `index`.

## <a name="view_as"></a>view_as

Reinterpreta essa matriz como uma [array_view](array-view-class.md) de uma classificação diferente.

```cpp
template <int _New_rank>
array_view<value_type,_New_rank> view_as(
    const Concurrency::extent<_New_rank>& _View_extent) restrict(amp,cpu);

template <int _New_rank>
array_view<const value_type,_New_rank> view_as(
    const Concurrency::extent<_New_rank>& _View_extent) const restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_New_rank*<br/>
A classificação do objeto de `extent` passado como um parâmetro.

*_View_extent*<br/>
A extensão usada para construir o novo objeto [array_view](array-view-class.md) .

*value_type*<br/>
O tipo de dados dos elementos no objeto de `array` original e no objeto de `array_view` retornado.

### <a name="return-value"></a>Valor retornado

O objeto [array_view](array-view-class.md) que é construído.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
