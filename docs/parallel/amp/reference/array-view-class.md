---
title: Classe array_view
ms.date: 11/04/2016
f1_keywords:
- array_view
- AMP/array_view
- AMP/Concurrency::array_view::array_view
- AMP/Concurrency::array_view::copy_to
- AMP/Concurrency::array_view::data
- AMP/Concurrency::array_view::discard_data
- AMP/Concurrency::array_view::get_extent
- AMP/Concurrency::array_view::get_ref
- AMP/Concurrency::array_view::get_source_accelerator_view
- AMP/Concurrency::array_view::refresh
- AMP/Concurrency::array_view::reinterpret_as
- AMP/Concurrency::array_view::section
- AMP/Concurrency::array_view::synchronize
- AMP/Concurrency::array_view::synchronize_async
- AMP/Concurrency::array_view::synchronize_to
- AMP/Concurrency::array_view::synchronize_to_async
- AMP/Concurrency::array_view::view_as
- AMP/Concurrency::array_view::rank
- AMP/Concurrency::array_view::extent
- AMP/Concurrency::array_view::source_accelerator_view
- AMP/Concurrency::array_view::value_type
helpviewer_keywords:
- array_view class
ms.assetid: 7e7ec9bc-05a2-4372-b05d-752b50006c5a
ms.openlocfilehash: 2aef75eedcde2a2064fe12815d9afd21fee2c293
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77127131"
---
# <a name="array_view-class"></a>Classe array_view

Representa uma exibição N-dimensional sobre os dados mantidos em outro contêiner.

## <a name="syntax"></a>Sintaxe

```cpp
template <
    typename value_type,
    int _Rank = 1
>
class array_view : public _Array_view_base<_Rank, sizeof(value_type)/sizeof(int)>;

template <
    typename value_type,
    int _Rank
>
class array_view<const value_type, _Rank> : public _Array_view_base<_Rank, sizeof(value_type)/sizeof(int)>;
```

### <a name="parameters"></a>Parâmetros

*value_type*<br/>
O tipo de dados dos elementos no objeto `array_view`.

*_Rank*<br/>
A classificação do objeto de `array_view`.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Construtor de array_view](#ctor)|Inicializa uma nova instância da classe `array_view`. Não há construtor padrão para `array<T,N>`. Todos os construtores são restritos para execução somente na CPU e não podem ser executados em um destino Direct3D.|
|[~ array_view destruidor](#ctor)|Destrói o objeto `array_view`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[copy_to](#copy_to)|Copia o conteúdo do objeto `array_view` para o destino especificado chamando `copy(*this, dest)`.|
|[data](#data)|Retorna um ponteiro para os dados brutos da `array_view`.|
|[discard_data](#discard_data)|Descarta os dados atuais subjacentes a esta exibição.|
|[get_extent](#get_extent)|Retorna o objeto de extensão do objeto de array_view.|
|[get_ref](#get_ref)|Retorna uma referência ao elemento indexado.|
|[get_source_accelerator_view](#get_source_accelerator_view)|Retorna o [accelerator_view](accelerator-view-class.md) onde a fonte de dados do `array_view` está localizada.|
|[Nova](#refresh)|Notifica o objeto `array_view` que sua memória associada foi modificada fora da interface `array_view`. Uma chamada para esse método renderiza todas as informações em cache obsoletas.|
|[reinterpret_as](#reinterpret_as)|Retorna uma matriz unidimensional que contém todos os elementos no objeto `array_view`.|
|[seção](#section)|Retorna uma subseção do objeto `array_view` que está na origem especificada e, opcionalmente, que tem a extensão especificada.|
|[synchronize](#synchronize)|Sincroniza quaisquer modificações feitas ao objeto `array_view` de volta para seus dados de origem.|
|[synchronize_async](#synchronize_async)|O sincroniza de forma assíncrona quaisquer modificações feitas ao objeto de `array_view` de volta para seus dados de origem.|
|[synchronize_to](#synchronize_to)|Sincroniza as modificações feitas ao objeto `array_view` para o [accelerator_view](accelerator-view-class.md)especificado.|
|[synchronize_to_async](#synchronize_to_async)|O sincroniza de forma assíncrona quaisquer modificações feitas ao objeto de `array_view` para o [accelerator_view](accelerator-view-class.md)especificado.|
|[view_as](#view_as)|Produz um objeto `array_view` de uma classificação diferente usando dados do objeto `array_view`.|

### <a name="public-operators"></a>Operadores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[operator()](#operator_call)|Retorna o valor do elemento que é especificado pelo parâmetro ou parâmetros.|
|[operator\[\]](#operator_at)|Retorna o elemento que é especificado pelos parâmetros.|
|[operator=](#operator_eq)|Copia o conteúdo do objeto `array_view` especificado para este.|

### <a name="public-constants"></a>Constantes Públicas

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Constante de classificação](#rank)|Armazena a classificação do objeto `array_view`.|

### <a name="data-members"></a>Membros de dados

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[extent](#extent)|Obtém o objeto `extent` que define a forma do objeto `array_view`.|
|[source_accelerator_view](#source_accelerator_view)|Obtém a [accelerator_view](accelerator-view-class.md) onde a fonte de dados do `array_view` está localizada|
|[value_type](#value_type)|O tipo de valor do `array_view` e a matriz associada.|

## <a name="remarks"></a>Comentários

A classe `array_view` representa uma exibição dos dados contidos em um objeto de [matriz](array-class.md) ou uma subseção de um objeto `array`.

Você pode acessar o objeto `array_view` onde os dados de origem estão localizados (localmente) ou em um acelerador diferente ou em um domínio coerência (remotamente). Quando você acessa o objeto remotamente, as exibições são copiadas e armazenadas em cache conforme necessário. Exceto pelos efeitos do cache automático, os objetos `array_view` têm um perfil de desempenho semelhante ao dos objetos `array`. Há uma pequena penalidade de desempenho quando você acessa os dados por meio de exibições.

Há três cenários de uso remoto:

- Uma exibição para um ponteiro de memória do sistema é passada por meio de uma chamada [parallel_for_each](../../../parallel/concrt/reference/concurrency-namespace-functions.md#parallel_for_each) para um acelerador e acessada no acelerador.

- Uma exibição para uma matriz localizada em um acelerador é passada por meio de uma `parallel_for_each` chamada para outro acelerador e é acessada lá.

- Uma exibição para uma matriz localizada em um acelerador é acessada na CPU.

Em qualquer um desses cenários, as exibições referenciadas são copiadas pelo tempo de execução para o local remoto e, se modificadas pelas chamadas para o objeto `array_view`, são copiadas de volta para o local local. O tempo de execução pode otimizar o processo de cópia das alterações, podendo copiar apenas os elementos alterados ou também pode copiar partes inalteradas. A sobreposição de objetos `array_view` em uma fonte de dados não tem garantia de manter a integridade referencial em um local remoto.

Você deve sincronizar qualquer acesso multithread para a mesma fonte de dados.

O tempo de execução faz as seguintes garantias em relação ao cache de dados em objetos `array_view`:

- Todos os acessos bem sincronizados a um objeto de `array` e um objeto de `array_view` sobre ele na ordem de programa obedecem a uma relação de ocorrências de uma série de ocorre.

- Todos os acessos bem sincronizados para sobreposição de objetos `array_view` no mesmo acelerador em um único objeto de `array` são alias por meio do objeto `array`. Eles induzim um total de ocorre-antes do relacionamento que obedece à ordem do programa. Não há cache. Se os objetos `array_view` estiverem sendo executados em aceleradores diferentes, a ordem de acesso será indefinida, criando uma condição de corrida.

Ao criar um objeto de `array_view` usando um ponteiro na memória do sistema, você deve alterar a exibição `array_view` objeto somente por meio do ponteiro de `array_view`. Como alternativa, você deve chamar `refresh()` em um dos objetos `array_view` anexados ao ponteiro do sistema, se a memória nativa subjacente for alterada diretamente, em vez de pelo objeto `array_view`.

Qualquer uma das ações notifica o objeto `array_view` que a memória nativa subjacente foi alterada e que todas as cópias que estão localizadas em um acelerador estão desatualizadas. Se você seguir essas diretrizes, as exibições baseadas em ponteiro são idênticas àquelas fornecidas para exibições de matrizes de dados paralelos.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`_Array_view_shape`

`_Array_view_base`

`array_view`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** amp. h

**Namespace:** Simultaneidade

## <a name="dtor"></a>~ array_view

Destrói o objeto `array_view`.

```cpp
~array_view()restrict(amp,cpu);
```

## <a name="ctor"></a>array_view

Inicializa uma nova instância da classe `array_view`.

```cpp
array_view(
    array<value_type, _Rank>& _Src)restrict(amp,cpu);

array_view(
    const array_view& _Other)restrict(amp,cpu);

explicit array_view(
    const Concurrency::extent<_Rank>& _Extent) restrict(cpu);

template <
    typename _Container
>
array_view(
    const Concurrency::extent<_Rank>& _Extent,
    _Container& _Src) restrict(cpu);

array_view(
    const Concurrency::extent<_Rank>& _Extent,
    value_type* _Src)restrict(amp,cpu);

explicit array_view(
    int _E0) restrict(cpu);

template <
    typename _Container
>
explicit array_view(
    _Container& _Src,
    typename std::enable_if<details::_Is_container<_Container>::type::value, void **>::type = 0) restrict(cpu);

template <
    typename _Container
>
explicit array_view(
    int _E0,
    _Container& _Src) restrict(cpu);

explicit array_view(
    int _E0,
    int _E1) __CPU_ONLY;

template <
    typename _Container
>
explicit array_view(
    int _E0,
    int _E1,
    _Container& _Src) restrict(cpu);

explicit array_view(
    int _E0,
    int _E1,
    int _E2) __CPU_ONLY;

template <
    typename _Container
>
explicit array_view(
    int _E0,
    int _E1,
    int _E2,
    _Container& _Src);

explicit array_view(
    int _E0,
    _In_ value_type* _Src)restrict(amp,cpu);

template <
    typename _Arr_type,
    int _Size
>
explicit array_view(
    _In_ _Arr_type (& _Src) [_Size]) restrict(amp,cpu);

explicit array_view(
    int _E0,
    int _E1,
    _In_ value_type* _Src)restrict(amp,cpu);

explicit array_view(
    int _E0,
    int _E1,
    int _E2,
    _In_ value_type* _Src)restrict(amp,cpu);

array_view(
    const array<value_type, _Rank>& _Src)restrict(amp,cpu);

array_view(
    const array_view<value_type, _Rank>& _Src)restrict(amp,cpu);

array_view(
    const array_view<const value_type, _Rank>& _Src)restrict(amp,cpu);

template <
    typename _Container
>
array_view(
    const Concurrency::extent<_Rank>& _Extent,
    const _Container& _Src) restrict(cpu);

template <
    typename _Container
>
explicit array_view(
    const _Container& _Src,
    typename std::enable_if<details::_Is_container<_Container>::type::value, void **>::type = 0) restrict(cpu);

array_view(
    const Concurrency::extent<_Rank>& _Extent,
    const value_type* _Src)restrict(amp,cpu);

template <
    typename _Arr_type,
    int _Size
>
explicit array_view(
    const _In_ _Arr_type (& _Src) [_Size]) restrict(amp,cpu);

template <
    typename _Container
>
array_view(
    int _E0,
    const _Container& _Src);

template <
    typename _Container
>
array_view(
    int _E0,
    int _E1,
    const _Container& _Src);

template <
    typename _Container
>
array_view(
    int _E0,
    int _E1,
    int _E2,
    const _Container& _Src);

array_view(
    int _E0,
    const value_type* _Src)restrict(amp,cpu);

array_view(
    int _E0,
    int _E1,
    const value_type* _Src) restrict(amp,cpu);

array_view(
    int _E0,
    int _E1,
    int _E2,
    const value_type* _Src) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Arr_type*<br/>
O tipo de elemento de uma matriz de estilo C da qual os dados são fornecidos.

*_Container*<br/>
Um argumento de modelo que deve especificar um contêiner linear que dá suporte a membros `data()` e `size()`.

*_E0*<br/>
O componente mais significativo da extensão desta seção.

*_E1*<br/>
O componente do próximo a mais significativo da extensão desta seção.

*_E2*<br/>
O componente menos significativo da extensão desta seção.

*_Extent*<br/>
A extensão em cada dimensão dessa `array_view`.

*_Other*<br/>
Um objeto do tipo `array_view<T,N>` do qual inicializar o novo `array_view`.

*_Size*<br/>
O tamanho de uma matriz de estilo C da qual os dados são fornecidos.

*_Src*<br/>
Um ponteiro para os dados de origem que serão copiados para a nova matriz.

## <a name="copy_to"></a>copy_to

Copia o conteúdo do objeto `array_view` para o objeto de destino especificado chamando `copy(*this, dest)`.

```cpp
void copy_to(
    array<value_type, _Rank>& _Dest) const;

void copy_to(
    array_view<value_type, _Rank>& _Dest) const;
```

### <a name="parameters"></a>Parâmetros

*_Dest*<br/>
O objeto para o qual copiar.

## <a name="data"></a>dado

Retorna um ponteiro para os dados brutos da `array_view`.

```cpp
value_type* data() const restrict(amp,
    cpu);

const value_type* data() const restrict(amp,
    cpu);
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para os dados brutos da `array_view`.

## <a name="discard_data"></a>discard_data

Descarta os dados atuais subjacentes a esta exibição. Essa é uma dica de otimização para o tempo de execução usado para evitar copiar o conteúdo atual da exibição para um destino `accelerator_view` em que ele é acessado, e seu uso será recomendado se o conteúdo existente não for necessário. Esse método é não op quando usado em um contexto de restrição (amp)

```cpp
void discard_data() const restrict(cpu);
```

## <a name="extent"></a>tention

Obtém o objeto `extent` que define a forma do objeto `array_view`.

```cpp
__declspec(property(get= get_extent)) Concurrency::extent<_Rank> extent;
```

## <a name="get_extent"></a>get_extent

Retorna o objeto de [extensão](extent-class.md) do objeto de `array_view`.

```cpp
Concurrency::extent<_Rank> get_extent() const restrict(cpu, amp);
```

### <a name="return-value"></a>Valor retornado

O objeto `extent` do objeto `array_view`

## <a name="get_ref"></a>get_ref

Obtenha uma referência para o elemento indexado por _Index. Ao contrário dos outros operadores de indexação para acessar o array_view na CPU, esse método não sincroniza implicitamente o conteúdo desse array_view com a CPU. Depois de acessar o array_view em um local remoto ou executar uma operação de cópia que envolva essa array_view os usuários são responsáveis por sincronizar explicitamente o array_view com a CPU antes de chamar esse método. A falha em fazer isso resulta em um comportamento indefinido.

```cpp
value_type& get_ref(
    const index<_Rank>& _Index) const restrict(amp, cpu);
```

### <a name="parameters"></a>Parâmetros

*_Index*<br/>
O índice.

### <a name="return-value"></a>Valor retornado

Referência ao elemento indexado por _Index

## <a name="get_source_accelerator_view"></a>get_source_accelerator_view

Retorna o accelerator_view onde a fonte de dados do array_view está localizada. Se o array_view não tiver uma fonte de dados, essa API lançará uma runtime_exception

```cpp
accelerator_view get_source_accelerator_view() const;
```

### <a name="return-value"></a>Valor retornado

## <a name="operator_call"></a>operador ()

Retorna o valor do elemento que é especificado pelo parâmetro ou parâmetros.

```cpp
value_type& operator() (
    const index<_Rank>& _Index) const restrict(amp,cpu);

typename details::_Projection_result_type<value_type,_Rank>::_Result_type operator() (
    int _I) const restrict(amp,cpu);

value_type& operator() (
    int _I0,
    int _I1) const restrict(amp,cpu);

value_type& operator() (
    int _I0,
    int _I1,
    int _I2) const restrict(amp,cpu);

typename details::_Projection_result_type<value_type,_Rank>::_Const_result_type operator() (
    int _I) const restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Index*<br/>
O local do elemento.

*_I0*<br/>
O índice na primeira dimensão.

*_I1*<br/>
O índice na segunda dimensão.

*_I2*<br/>
O índice na terceira dimensão.

*_I*<br/>
O local do elemento.

### <a name="return-value"></a>Valor retornado

O valor do elemento que é especificado pelo parâmetro ou parâmetros.

## <a name="operator_at"></a>operador []

Retorna o elemento que é especificado pelos parâmetros.

```cpp
typename details::_Projection_result_type<value_type,_Rank>::_Const_result_type operator[] (
    int _I) const restrict(amp,cpu);

value_type& operator[] (
    const index<_Rank>& _Index) const restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Index*<br/>
O índice.

*_I*<br/>
O índice.

### <a name="return-value"></a>Valor retornado

O valor do elemento no índice ou um `array_view` projetado na dimensão mais significativa.

## <a name="operator_eq"></a>operador =

Copia o conteúdo do objeto de `array_view` especificado para este.

```cpp
array_view& operator= (
    const array_view& _Other) restrict(amp,cpu);

array_view& operator= (
    const array_view<value_type, _Rank>& _Other) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
O objeto `array_view` do qual copiar.

### <a name="return-value"></a>Valor retornado

Uma referência a este objeto de `array_view`.

## <a name="rank"></a>Fique

Armazena a classificação do objeto `array_view`.

```cpp
static const int rank = _Rank;
```

## <a name="refresh"></a>Nova

Notifica o objeto `array_view` que sua memória associada foi modificada fora da interface `array_view`. Uma chamada para esse método renderiza todas as informações em cache obsoletas.

```cpp
void refresh() const restrict(cpu);
```

## <a name="reinterpret_as"></a>reinterpret_as

Reinterpreta a array_view por meio de um array_view unidimensional, que como uma opção pode ter um tipo de valor diferente do array_view de origem.

### <a name="syntax"></a>Sintaxe

```cpp
template <
    typename _Value_type2
>
array_view< _Value_type2, _Rank> reinterpret_as() const restrict(amp,cpu);

template <
    typename _Value_type2
>
array_view<const _Value_type2, _Rank> reinterpret_as() const restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Value_type2*<br/>
O tipo de dados do novo objeto `array_view`.

### <a name="return-value"></a>Valor retornado

Um objeto `array_view` ou um objeto const `array_view` com base nessa `array_view`, com o tipo de elemento convertido de `T` para `_Value_type2`e a classificação reduzida de *N* para 1.

### <a name="remarks"></a>Comentários

Às vezes, é conveniente exibir uma matriz multidimensional como uma matriz linear, unidimensional, que pode ter um tipo de valor diferente da matriz de origem. Você pode conseguir isso em um `array_view` usando esse método.

**Aviso** A reinterpretação de um objeto de array_view usando um tipo de valor diferente é uma operação potencialmente não segura. Essa funcionalidade deve ser usada com cuidado.

Aqui está um exemplo:

```cpp
struct RGB { float r; float g; float b; };

array<RGB,3>  a = ...;
array_view<float,1> v = a.reinterpret_as<float>();

assert(v.extent == 3*a.extent);
```

## <a name="section"></a>Section

Retorna uma subseção do objeto `array_view` que está na origem especificada e, opcionalmente, que tem a extensão especificada.

```cpp
array_view section(
    const Concurrency::index<_Rank>& _Section_origin,
    const Concurrency::extent<_Rank>& _Section_extent) const restrict(amp,cpu);

array_view section(
    const Concurrency::index<_Rank>& _Idx) const restrict(amp,cpu);

array_view section(
    const Concurrency::extent<_Rank>& _Ext) const restrict(amp,cpu);

array_view section(
    int _I0,
    int _E0) const restrict(amp,cpu);

array_view section(
    int _I0,
    int _I1,
    int _E0,
    int _E1) const restrict(amp,cpu);

array_view section(
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

### <a name="return-value"></a>Valor retornado

Uma subseção do objeto `array_view` que está na origem especificada e, opcionalmente, que tem a extensão especificada. Quando apenas o objeto `index` é especificado, a subseção contém todos os elementos na extensão associada que têm índices maiores do que os índices dos elementos no objeto `index`.

## <a name="source_accelerator_view"></a>source_accelerator_view

Obtém o accelerator_view de origem ao qual este array_view está associado.

```cpp
__declspec(property(get= get_source_accelerator_view)) accelerator_view source_accelerator_view;
```

## <a name="synchronize"></a>novamente

Sincroniza quaisquer modificações feitas ao objeto `array_view` de volta para seus dados de origem.

```cpp
void synchronize(access_type _Access_type = access_type_read) const restrict(cpu);

void synchronize() const restrict(cpu);
```

### <a name="parameters"></a>Parâmetros

*_Access_type*<br/>
O [access_type](concurrency-namespace-enums-amp.md#access_type) pretendido no [accelerator_view](accelerator-view-class.md)de destino. Esse parâmetro tem um valor padrão de `access_type_read`.

## <a name="synchronize_async"></a>synchronize_async

O sincroniza de forma assíncrona quaisquer modificações feitas ao objeto de `array_view` de volta para seus dados de origem.

```cpp
concurrency::completion_future synchronize_async(access_type _Access_type = access_type_read) const restrict(cpu);

concurrency::completion_future synchronize_async() const restrict(cpu);
```

### <a name="parameters"></a>Parâmetros

*_Access_type*<br/>
O [access_type](concurrency-namespace-enums-amp.md#access_type) pretendido no [accelerator_view](accelerator-view-class.md)de destino. Esse parâmetro tem um valor padrão de `access_type_read`.

### <a name="return-value"></a>Valor retornado

Um futuro no qual aguardar a conclusão da operação.

## <a name="synchronize_to"></a>synchronize_to

Sincroniza todas as modificações feitas a esse array_view para o accelerator_view especificado.

```cpp
void synchronize_to(
    const accelerator_view& _Accl_view,
    access_type _Access_type = access_type_read) const restrict(cpu);

void synchronize_to(
    const accelerator_view& _Accl_view) const restrict(cpu);
```

### <a name="parameters"></a>Parâmetros

*_Accl_view*<br/>
O accelerator_view de destino para sincronizar.

*_Access_type*<br/>
O access_type desejado no accelerator_view de destino. Esse parâmetro tem um valor padrão de access_type_read.

## <a name="synchronize_to_async"></a>synchronize_to_async

O sincroniza de forma assíncrona quaisquer modificações feitas a esse array_view para o accelerator_view especificado.

```cpp
concurrency::completion_future synchronize_to_async(
    const accelerator_view& _Accl_view,
    access_type _Access_type = access_type_read) const restrict(cpu);

concurrency::completion_future synchronize_to_async(
    const accelerator_view& _Accl_view) const restrict(cpu);
```

### <a name="parameters"></a>Parâmetros

*_Accl_view*<br/>
O accelerator_view de destino para sincronizar.

*_Access_type*<br/>
O access_type desejado no accelerator_view de destino. Esse parâmetro tem um valor padrão de access_type_read.

### <a name="return-value"></a>Valor retornado

Um futuro no qual aguardar a conclusão da operação.

## <a name="value_type"></a>value_type

O tipo de valor do array_view e a matriz associada.

```cpp
typedef typenamevalue_type value_type;
```

## <a name="view_as"></a>view_as

Reinterpreta essa `array_view` como uma `array_view` de uma classificação diferente.

```cpp
template <
    int _New_rank
>
array_view<value_type,_New_rank> view_as(
    const Concurrency::extent<_New_rank>& _View_extent) const restrict(amp,cpu);

template <
    int _New_rank
>
array_view<const value_type,_New_rank> view_as(
    const Concurrency::extent<_New_rank> _View_extent) const restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_New_rank*<br/>
A classificação do novo objeto de `array_view`.

*_View_extent*<br/>
O `extent`de remodelagem.

*value_type*<br/>
O tipo de dados dos elementos no objeto de [matriz](array-class.md) original e no objeto de `array_view` retornado.

### <a name="return-value"></a>Valor retornado

O objeto `array_view` que é construído.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
