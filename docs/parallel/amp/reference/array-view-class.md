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
ms.openlocfilehash: e73639ffd11e08edb2fdb03471f2c6c88730f02d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62405554"
---
# <a name="arrayview-class"></a>Classe array_view

Representa uma exibição de N-dimensional sobre os dados mantidos em outro contêiner.

## <a name="syntax"></a>Sintaxe

```
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

#### <a name="parameters"></a>Parâmetros

*value_type*<br/>
O tipo de dados dos elementos no `array_view` objeto.

*_Rank*<br/>
A classificação do `array_view` objeto.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor de array_view](#ctor)|Inicializa uma nova instância da classe `array_view`. Não há nenhum construtor padrão para `array<T,N>`. Todos os construtores são restritos a serem executados somente na CPU e não podem ser executados em um destino Direct3D.|
|[~ array_view destruidor](#ctor)|Destrói o `array_view` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[copy_to](#copy_to)|Copia o conteúdo a `array_view` objeto para o destino especificado chamando `copy(*this, dest)`.|
|[data](#data)|Retorna um ponteiro para os dados brutos do `array_view`.|
|[discard_data](#discard_data)|Descarta os dados atuais subjacentes nessa exibição.|
|[get_extent](#get_extent)|Retorna o objeto de extensão do objeto array_view.|
|[get_ref](#get_ref)|Retorna uma referência ao elemento indexado.|
|[get_source_accelerator_view](#get_source_accelerator_view)|Retorna o [accelerator_view](accelerator-view-class.md) onde a fonte de dados do `array_view` está localizado.|
|[refresh](#refresh)|Notifica o `array_view` objeto que sua memória associada foi modificada fora do `array_view` interface. Uma chamada para este método processa todas as informações armazenadas em cache obsoleto.|
|[reinterpret_as](#reinterpret_as)|Retorna uma matriz unidimensional que contém todos os elementos de `array_view` objeto.|
|[seção](#section)|Retorna uma subseção do `array_view` objeto que está na origem especificada e, opcionalmente, que tem a extensão especificada.|
|[synchronize](#synchronize)|Sincroniza qualquer modificação feita para o `array_view` objeto para seus dados de origem.|
|[synchronize_async](#synchronize_async)|Sincroniza qualquer modificação feita de forma assíncrona o `array_view` objeto para seus dados de origem.|
|[synchronize_to](#synchronize_to)|Sincroniza qualquer modificação feita para o `array_view` o objeto especificado [accelerator_view](accelerator-view-class.md).|
|[synchronize_to_async](#synchronize_to_async)|Sincroniza qualquer modificação feita de forma assíncrona o `array_view` o objeto especificado [accelerator_view](accelerator-view-class.md).|
|[view_as](#view_as)|Produz um `array_view` objeto de uma classificação diferente usando este `array_view` dados do objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operator()](#operator_call)|Retorna o valor do elemento que é especificado pelo parâmetro ou parâmetros.|
|[operator\[\]](#operator_at)|Retorna o elemento que é especificado pelos parâmetros.|
|[operator=](#operator_eq)|Copia o conteúdo especificado `array_view` esse objeto.|

### <a name="public-constants"></a>Constantes públicas

|Nome|Descrição|
|----------|-----------------|
|[Constante de classificação](#rank)|Armazena a classificação do `array_view` objeto.|

### <a name="data-members"></a>Membros de Dados

|Nome|Descrição|
|----------|-----------------|
|[extent](#extent)|Obtém o `extent` objeto que define a forma do `array_view` objeto.|
|[source_accelerator_view](#source_accelerator_view)|Obtém o [accelerator_view](accelerator-view-class.md) onde a fonte de dados do `array_view` está localizado|
|[value_type](#value_type)|O tipo de valor a `array_view` e a matriz associada.|

## <a name="remarks"></a>Comentários

O `array_view` classe representa uma exibição dos dados que estão contidos em um [matriz](array-class.md) objeto ou uma subseção de um `array` objeto.

Você pode acessar o `array_view` do objeto em que os dados de origem estão localizados (localmente) ou em um acelerador diferente ou em um domínio de coerência (remotamente). Quando você acessa o objeto remotamente, modos de exibição são copiados e armazenados em cache conforme necessário. Exceto para os efeitos de cache automático, `array_view` objetos têm um perfil de desempenho semelhante do `array` objetos. Há uma pequena penalidade de desempenho ao acessar os dados por meio de exibições.

Há três cenários de uso remoto:

- Um modo de exibição para um ponteiro de memória do sistema é passado por meio de um [parallel_for_each](../../../parallel/concrt/reference/concurrency-namespace-functions.md#parallel_for_each) chamar um acelerador e acessada no acelerador.

- Um modo de exibição para uma matriz localizada em um acelerador é passado por meio de um `parallel_for_each` chamada para outro acelerador e acessada lá.

- Um modo de exibição para uma matriz localizada em um acelerador é acessado na CPU.

Em qualquer um desses cenários, as visualizações de referência são copiadas pelo tempo de execução para o local remoto e, se modificadas por chamadas para o `array_view` de objeto, são copiados de volta para a localização local. O tempo de execução pode otimizar o processo de copiar as alterações de volta, pode copiar apenas os elementos alterados ou pode copiar partes inalteradas também. Sobreposição de `array_view` objetos em uma fonte de dados não são garantidos para manter a integridade referencial em um local remoto.

Você deve sincronizar qualquer acesso multissegmentado à mesma fonte de dados.

O tempo de execução faz as seguintes garantias sobre o armazenamento em cache de dados em `array_view` objetos:

- Todos os acessos bem sincronizados a um `array` objeto e um `array_view` objeto na ordem do programa obedecem a uma série acontece-antes de relação.

- Todos os acessos bem sincronizados a sobreposição `array_view` objetos no mesmo acelerador em uma única `array` objeto são feitos pelo `array` objeto. Eles induzem um total ocorre-antes de relação que obedece a ordem do programa. Não há nenhum cache. Se o `array_view` objetos estão em execução em aceleradores diferentes, a ordem de acesso é indefinida, criando uma condição de corrida.

Quando você cria um `array_view` do objeto usando um ponteiro na memória do sistema, você deve alterar o modo de exibição `array_view` somente por meio do objeto a `array_view` ponteiro. Como alternativa, você deve chamar `refresh()` em um dos `array_view` objetos que estão anexados ao ponteiro do sistema, se a memória nativa subjacente é modificada diretamente, em vez de através de `array_view` objeto.

Qualquer ação notifica o `array_view` de objeto que a memória nativa subjacente é alterada e que quaisquer cópias que estão localizadas em um acelerador estão desatualizadas. Se você seguir essas diretrizes, os modos de exibição baseada em ponteiro são idênticos àquelas fornecidas para as exibições de matrizes de dados paralelos.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`_Array_view_shape`

`_Array_view_base`

`array_view`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amp. h

**Namespace:** Concorrência

##  <a name="dtor"></a> ~array_view

Destrói o `array_view` objeto.

```
~array_view()restrict(amp,cpu);
```

##  <a name="ctor"></a> array_view

Inicializa uma nova instância da classe `array_view`.

```
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
O tipo de elemento de uma matriz C-style do qual os dados são fornecidos.

*_Container*<br/>
Um argumento de modelo que deve especificar um contêiner linear que dá suporte a `data()` e `size()` membros.

*_E0*<br/>
O componente mais significativo da extensão dessa seção.

*_E1*<br/>
O componente next-para-mais significativo da extensão dessa seção.

*_E2*<br/>
O componente menos significativo da extensão dessa seção.

*_Extent*<br/>
A extensão em cada dimensão deste `array_view`.

*_Other*<br/>
Um objeto do tipo `array_view<T,N>` da qual inicializar a nova `array_view`.

*_Size*<br/>
O tamanho de uma matriz C-style do qual os dados são fornecidos.

*_Src*<br/>
Um ponteiro para os dados de origem serão copiados para a nova matriz.

##  <a name="copy_to"></a> copy_to

Copia o conteúdo a `array_view` objeto para o objeto de destino especificado chamando `copy(*this, dest)`.

```
void copy_to(
    array<value_type, _Rank>& _Dest) const;

void copy_to(
    array_view<value_type, _Rank>& _Dest) const;
```

### <a name="parameters"></a>Parâmetros

*_Dest*<br/>
O objeto para copiar para.

##  <a name="data"></a> Dados

Retorna um ponteiro para os dados brutos do `array_view`.

```
value_type* data() const restrict(amp,
    cpu);

const value_type* data() const restrict(amp,
    cpu);
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para os dados brutos do `array_view`.

##  <a name="discard_data"></a> discard_data

Descarta os dados atuais subjacentes nessa exibição. Isso é uma dica de otimização para o tempo de execução usado para evitar copiar o conteúdo atual do modo de exibição para um destino `accelerator_view` que ele é acessado no, e seu uso é recomendado se o conteúdo existente não for necessária. Esse método é no-op quando usado em um contexto de Restrict (amp)

```
void discard_data() const restrict(cpu);
```

##  <a name="extent"></a> extent

Obtém o `extent` objeto que define a forma do `array_view` objeto.

```
__declspec(property(get= get_extent)) Concurrency::extent<_Rank> extent;
```

##  <a name="get_extent"></a> get_extent

Retorna o [extent](extent-class.md) objeto do `array_view` objeto.

```
Concurrency::extent<_Rank> get_extent() const restrict(cpu, amp);
```

### <a name="return-value"></a>Valor de retorno

O `extent` objeto do `array_view` objeto

##  <a name="get_ref"></a> get_ref

Obtenha uma referência ao elemento indexado por index. Ao contrário de outros operadores de indexação para acessar array_view na CPU, esse método não sincroniza implicitamente o conteúdo de array_view à CPU. Depois de acessar o array_view em um local remoto ou executando uma operação de cópia que envolve este array_view, os usuários são responsáveis por sincronizar explicitamente o array_view à CPU antes de chamar esse método. Falha ao fazer isso resultará em um comportamento indefinido.

```
value_type& get_ref(
    const index<_Rank>& _Index) const restrict(amp, cpu);
```

### <a name="parameters"></a>Parâmetros

*_Index*<br/>
O índice.

### <a name="return-value"></a>Valor de retorno

Referência ao elemento indexado por index

##  <a name="get_source_accelerator_view"></a> get_source_accelerator_view

Retorna o accelerator_view onde a fonte de dados de array_view está localizada. Se o array_view não tiver uma fonte de dados, essa API lançará uma runtime_exception

```
accelerator_view get_source_accelerator_view() const;
```

### <a name="return-value"></a>Valor de retorno

##  <a name="operator_call"></a> operator()

Retorna o valor do elemento que é especificado pelo parâmetro ou parâmetros.

```
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
O índice da primeira dimensão.

*_I1*<br/>
O índice na segunda dimensão.

*_I2*<br/>
O índice na terceira dimensão.

*_I*<br/>
O local do elemento.

### <a name="return-value"></a>Valor de retorno

O valor do elemento que é especificado pelo parâmetro ou parâmetros.

##  <a name="operator_at"></a> operator[]

Retorna o elemento que é especificado pelos parâmetros.

```
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

### <a name="return-value"></a>Valor de retorno

O valor do elemento no índice, ou um `array_view` projetados para a dimensão mais significativa.

##  <a name="operator_eq"></a> operator=

Copia o conteúdo especificado `array_view` objeto para esse outro.

```
array_view& operator= (
    const array_view& _Other) restrict(amp,cpu);

array_view& operator= (
    const array_view<value_type, _Rank>& _Other) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
O `array_view` objeto do qual copiar.

### <a name="return-value"></a>Valor de retorno

Uma referência a este `array_view` objeto.

##  <a name="rank"></a> classificação

Armazena a classificação do `array_view` objeto.

```
static const int rank = _Rank;
```

##  <a name="refresh"></a> refresh

Notifica o `array_view` objeto que sua memória associada foi modificada fora do `array_view` interface. Uma chamada para este método processa todas as informações armazenadas em cache obsoleto.

```
void refresh() const restrict(cpu);
```

## <a name="reinterpret_as"></a> reinterpret_as

Reinterpreta o array_view por meio de array_view unidimensional, que pode ter um tipo de valor diferente do array_view de origem como uma opção.

### <a name="syntax"></a>Sintaxe

```
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
O tipo de dados do novo `array_view` objeto.

### <a name="return-value"></a>Valor de retorno

Uma `array_view` objeto ou const `array_view` objeto que é baseado neste `array_view`, com o tipo de elemento convertido de `T` para `_Value_type2`, e a classificação reduzida de *N* como 1.

### <a name="remarks"></a>Comentários

Às vezes é conveniente exibir uma matriz multidimensional como uma matriz linear unidimensional, que pode ter um tipo de valor diferente da matriz de origem. Você pode obter isso em um `array_view` usando esse método.

**Aviso** Reinterpretar um objeto array_view usando um tipo de valor diferente é uma operação potencialmente não segura. Essa funcionalidade deve ser usada com cuidado.

Veja um exemplo:

```cpp
struct RGB { float r; float g; float b; };

array<RGB,3>  a = ...;
array_view<float,1> v = a.reinterpret_as<float>();

assert(v.extent == 3*a.extent);
```

##  <a name="section"></a> Seção

Retorna uma subseção do `array_view` objeto que está na origem especificada e, opcionalmente, que tem a extensão especificada.

```
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
O componente mais significativo da extensão dessa seção.

*_E1*<br/>
O componente next-para-mais significativo da extensão dessa seção.

*_E2*<br/>
O componente menos significativo da extensão dessa seção.

*_Ext*<br/>
O [extensão](extent-class.md) objeto que especifica a extensão da seção. A origem é 0.

*_Idx*<br/>
O [índice](index-class.md) objeto que especifica o local de origem. A subseção é o resto da extensão.

*_I0*<br/>
O componente mais significativo da origem desta seção.

*_I1*<br/>
O componente next-para-mais significativo da origem desta seção.

*_I2*<br/>
O componente menos significativo da origem desta seção.

*_Rank*<br/>
A classificação da seção.

*_Section_extent*<br/>
O [extensão](extent-class.md) objeto que especifica a extensão da seção.

*_Section_origin*<br/>
O [índice](index-class.md) objeto que especifica o local de origem.

### <a name="return-value"></a>Valor de retorno

Uma subseção do `array_view` objeto que está na origem especificada e, opcionalmente, que tem a extensão especificada. Quando somente o `index` objeto for especificado, a subseção contém todos os elementos na extensão associada que tem os índices que são maiores do que os índices dos elementos no `index` objeto.

##  <a name="source_accelerator_view"></a> source_accelerator_view

Obtém o accelerator_view de origem que esta array_view está associada.

```
__declspec(property(get= get_source_accelerator_view)) accelerator_view source_accelerator_view;
```

##  <a name="synchronize"></a> Sincronizar

Sincroniza qualquer modificação feita para o `array_view` objeto para seus dados de origem.

```
void synchronize(access_type _Access_type = access_type_read) const restrict(cpu);

void synchronize() const restrict(cpu);
```

### <a name="parameters"></a>Parâmetros

*_Access_type*<br/>
Pretendido [access_type](concurrency-namespace-enums-amp.md#access_type) no destino [accelerator_view](accelerator-view-class.md). Este parâmetro tem um valor padrão de `access_type_read`.

##  <a name="synchronize_async"></a> synchronize_async

Sincroniza qualquer modificação feita de forma assíncrona o `array_view` objeto para seus dados de origem.

```
concurrency::completion_future synchronize_async(access_type _Access_type = access_type_read) const restrict(cpu);

concurrency::completion_future synchronize_async() const restrict(cpu);
```

### <a name="parameters"></a>Parâmetros

*_Access_type*<br/>
Pretendido [access_type](concurrency-namespace-enums-amp.md#access_type) no destino [accelerator_view](accelerator-view-class.md). Este parâmetro tem um valor padrão de `access_type_read`.

### <a name="return-value"></a>Valor de retorno

Um futuro no qual aguardar a conclusão da operação.

##  <a name="synchronize_to"></a> synchronize_to

Sincroniza qualquer modificação feita nesta array_view para a accelerator_view especificada.

```
void synchronize_to(
    const accelerator_view& _Accl_view,
    access_type _Access_type = access_type_read) const restrict(cpu);

void synchronize_to(
    const accelerator_view& _Accl_view) const restrict(cpu);
```

### <a name="parameters"></a>Parâmetros

*_Accl_view*<br/>
O accelerator_view de destino para sincronizar com.

*_Access_type*<br/>
O access_type desejado em accelerator_view de destino. Esse parâmetro tem um valor padrão de access_type_read.

##  <a name="synchronize_to_async"></a> synchronize_to_async

Sincroniza de forma assíncrona qualquer modificação feita nesta array_view para a accelerator_view especificada.

```
concurrency::completion_future synchronize_to_async(
    const accelerator_view& _Accl_view,
    access_type _Access_type = access_type_read) const restrict(cpu);

concurrency::completion_future synchronize_to_async(
    const accelerator_view& _Accl_view) const restrict(cpu);
```

### <a name="parameters"></a>Parâmetros

*_Accl_view*<br/>
O accelerator_view de destino para sincronizar com.

*_Access_type*<br/>
O access_type desejado em accelerator_view de destino. Esse parâmetro tem um valor padrão de access_type_read.

### <a name="return-value"></a>Valor de retorno

Um futuro no qual aguardar a conclusão da operação.

##  <a name="value_type"></a> value_type

O tipo de valor da array_view e da matriz associada.

```
typedef typenamevalue_type value_type;
```

##  <a name="view_as"></a> view_as

Reinterpreta esse `array_view` como um `array_view` de uma classificação diferente.

```
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
A classificação do novo `array_view` objeto.

*_View_extent*<br/>
A remodelagem `extent`.

*value_type*<br/>
O tipo de dados dos elementos no original [array](array-class.md) objeto e retornado `array_view` objeto.

### <a name="return-value"></a>Valor de retorno

O `array_view` objeto que é construído.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
