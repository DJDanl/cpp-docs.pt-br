---
title: Classe texture_view
ms.date: 11/04/2016
f1_keywords:
- texture_view
- AMP_GRAPHICS/texture_view
- AMP_GRAPHICS/Concurrency::graphics::texture_view::texture_view
- AMP_GRAPHICS/Concurrency::graphics::texture_view::gather_alpha
- AMP_GRAPHICS/Concurrency::graphics::texture_view::gather_blue
- AMP_GRAPHICS/Concurrency::graphics::texture_view::gather_green
- AMP_GRAPHICS/Concurrency::graphics::texture_view::gather_red
- AMP_GRAPHICS/Concurrency::graphics::texture_view::get
- AMP_GRAPHICS/Concurrency::graphics::texture_view::sample
- AMP_GRAPHICS/Concurrency::graphics::texture_view::set
- AMP_GRAPHICS/Concurrency::graphics::texture_view::value_type
ms.assetid: 6ec2e289-1626-4727-9592-07981cf1d27d
ms.openlocfilehash: 6bf4b9666d746199cea92fa2bd52b691c67e4a5b
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77126338"
---
# <a name="texture_view-class"></a>Classe texture_view

Fornece acesso de leitura e acesso de gravação a uma textura. `texture_view` só pode ser usada para ler texturas cujo tipo de valor é `int`, `unsigned int`ou `float` que têm bpse padrão de 32 bits. Para ler outros formatos de textura, use `texture_view<const value_type, _Rank>`.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename value_type,int _Rank>
class texture_view;

template<typename value_type, int _Rank>
class texture_view
   : public details::_Texture_base<value_type, _Rank>;

template<typename value_type, int _Rank>
class texture_view<const value_type, _Rank>
   : public details::_Texture_base<value_type, _Rank>;
```

### <a name="parameters"></a>Parâmetros

*value_type*<br/>
O tipo dos elementos na agregação de textura.

*_Rank*<br/>
A classificação da `texture_view`.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|`value_type`|O tipo dos elementos na textura é agregado.|
|`coordinates_type`|O tipo da coordenada usada para especificar um Texel no `texture_view`— ou seja, uma `short_vector` que tem a mesma classificação que a textura associada que tem um tipo de valor de `float`.|
|`gather_return_type`|O tipo de retorno usado para reunir operações – ou seja, uma `short_vector` de classificação 4 que contém os quatro componentes de cores homogêneos coletados dos quatro valores de Texel amostrados.|

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Construtor de texture_view](#ctor)|Sobrecarregado. Constrói uma instância de `texture_view`.|
|[~ texture_view destruidor](#ctor)|Destrói a instância de `texture_view`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[gather_alpha](#gather_alpha)|Sobrecarregado. Amostra a textura nas coordenadas especificadas usando a configuração de amostragem especificada e retorna os componentes alfa (w) dos quatro exemplos de texels.|
|[gather_blue](#gather_blue)|Sobrecarregado. Amostra a textura nas coordenadas especificadas usando a configuração de amostragem especificada e retorna os componentes azuis (z) dos quatro texels de amostra.|
|[gather_green](#gather_green)|Sobrecarregado. Amostra a textura nas coordenadas especificadas usando a configuração de amostragem especificada e retorna os componentes verdes (y) dos quatro exemplos de texels.|
|[gather_red](#gather_red)|Sobrecarregado. Amostra a textura nas coordenadas especificadas usando a configuração de amostragem especificada e retorna os componentes vermelhos (x) dos quatro texels de amostra.|
|[get](#get)|Sobrecarregado. Obtém o valor do elemento por índice.|
|[sample](#sample)|Sobrecarregado. Amostra a textura nas coordenadas especificadas e o nível de detalhes usando a configuração de amostragem especificada.|
|[set](#set)|Define o valor de um elemento por índice.|

### <a name="public-operators"></a>Operadores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[operator()](#operator_call)|Sobrecarregado. Obtém o valor do elemento por índice.|
|[operator\[\]](#operator_at)|Sobrecarregado. Obtém o valor do elemento por índice.|
|[operator=](#operator_eq)|Sobrecarregado. Operador de atribuição.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[value_type](#value_type)|O tipo de valor dos elementos do `texture_view`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`_Texture_base`

`texture_view`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** amp_graphics. h

**Namespace:** simultaneidade:: Graphics

## <a name="dtor"></a>~ texture_view

Destrói a instância de `texture_view`.

```cpp
~texture_view() restrict(amp, cpu);
```

## <a name="ctor"></a>texture_view

Constrói uma instância de `texture_view`.

```cpp
texture_view(// [1] constructor
    texture<value_type, _Rank>& _Src) restrict(amp);

texture_view(// [2] constructor
    texture<value_type, _Rank>& _Src,
    unsigned int _Mipmap_level = 0) restrict(cpu);

texture_view(// [3] constructor
    const texture<value_type, _Rank>& _Src) restrict(amp);

texture_view(// [4] constructor
    const texture<value_type, _Rank>& _Src,
    unsigned int _Most_detailed_mip,
    unsigned int _Mip_levels) restrict(cpu);

texture_view(// [5] copy constructor
    const texture_view<value_type, _Rank>& _Other) restrict(amp, cpu);

texture_view(// [6] copy constructor
    const texture_view<const value_type, _Rank>& _Other) restrict(amp, cpu);

texture_view(// [7] copy constructor
    const texture_view<const value_type, _Rank>& _Other,
    unsigned int _Most_detailed_mip,
    unsigned int _Mip_levels) restrict(cpu);
```

### <a name="parameters"></a>Parâmetros

*_Src*<br/>
[1, 2] Construtor o `texture` no qual o `texture_view` gravável é criado.

[3, 4] Construtor o `texture` no qual o `texture_view` não gravável é criado.

*_Other*<br/>
[5] Construtor de cópia o `texture_view`gravável de origem.

[6, 7] Copiar construtor a `texture_view`de origem não gravável.

*_Mipmap_level*<br/>
O nível de mipmap específico no `texture` de origem ao qual este `texture_view` gravável é associado. O valor padrão é 0, que representa o nível de MIP de nível superior (mais detalhado).

*_Most_detailed_mip*<br/>
Nível de MIP de nível superior (mais detalhado) para a exibição, relativo ao objeto de `texture_view` especificado.

*_Mip_levels*<br/>
O número de níveis de mipmap acessíveis por meio do `texture_view`.

## <a name="gather_red"></a>gather_red

Amostra a textura nas coordenadas especificadas usando a configuração de amostragem especificada e retorna os componentes vermelhos (x) dos quatro texels de amostra.

```cpp
const gather_return_type gather_red(
    const sampler& _Sampler,
    const coordinates_type& _Coord) const restrict(amp);

template<
    address_mode _Address_mode = address_clamp
>
const gather_return_type gather_red(
    const coordinates_type& _Coord) const restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Address_mode*<br/>
O modo de endereço a ser usado para exemplificar o `texture_view`. O modo de endereço é o mesmo para todas as dimensões.

*_Sampler*<br/>
A configuração de amostra a ser usada para exemplificar o `texture_view`.

*_Coord*<br/>
As coordenadas das quais obter o exemplo. Os valores de coordenadas fracionárias são usados para fazer a interpolação entre texels de exemplo.

### <a name="return-value"></a>Valor retornado

Um vetor curto de classificação 4 que contém o componente vermelho (x) dos 4 valores de Texel amostrados.

## <a name="gather_green"></a>gather_green

Amostra a textura nas coordenadas especificadas usando a configuração de amostragem especificada e retorna os componentes verdes (y) dos quatro exemplos de texels.

```cpp
const gather_return_type gather_green(
    const sampler& _Sampler,
    const coordinates_type& _Coord) const restrict(amp);

template<
    address_mode _Address_mode = address_clamp
>
const gather_return_type gather_green(
    const coordinates_type& _Coord) const restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Address_mode*<br/>
O modo de endereço a ser usado para exemplificar o `texture_view`. O modo de endereço é o mesmo para todas as dimensões.

*_Sampler*<br/>
A configuração de amostra a ser usada para exemplificar o `texture_view`.

*_Coord*<br/>
As coordenadas das quais obter o exemplo. Os valores de coordenadas fracionárias são usados para fazer a interpolação entre texels de exemplo.

### <a name="return-value"></a>Valor retornado

Um vetor curto de classificação 4 que contém o componente verde (y) dos 4 valores de Texel amostrados.

## <a name="gather_blue"></a>gather_blue

Amostra a textura nas coordenadas especificadas usando a configuração de amostragem especificada e retorna os componentes azuis (z) dos quatro texels de amostra.

```cpp
const gather_return_type gather_blue(
    const sampler& _Sampler,
    const coordinates_type& _Coord) const restrict(amp);

template<
    address_mode _Address_mode = address_clamp
>
const gather_return_type gather_blue(
    const coordinates_type& _Coord) const restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Address_mode*<br/>
O modo de endereço a ser usado para exemplificar o `texture_view`. O modo de endereço é o mesmo para todas as dimensões.

*_Sampler*<br/>
A configuração de amostra a ser usada para exemplificar o `texture_view`.

*_Coord*<br/>
As coordenadas das quais obter o exemplo. Os valores de coordenadas fracionárias são usados para fazer a interpolação entre texels de exemplo.

### <a name="return-value"></a>Valor retornado

Um vetor curto de classificação 4 que contém o componente vermelho (x) dos 4 valores de Texel amostrados.

## <a name="gather_alpha"></a>gather_alpha

Amostra a textura nas coordenadas especificadas usando a configuração de amostragem especificada e retorna os componentes alfa (w) dos quatro exemplos de texels.

```cpp
const gather_return_type gather_alpha(
    const sampler& _Sampler,
    const coordinates_type& _Coord) const restrict(amp);

template<
    address_mode _Address_mode = address_clamp
>
const gather_return_type gather_alpha(
    const coordinates_type& _Coord) const restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Address_mode*<br/>
O modo de endereço a ser usado para exemplificar o `texture_view`. O modo de endereço é o mesmo para todas as dimensões.

*_Sampler*<br/>
A configuração de amostra a ser usada para exemplificar o `texture_view`.

*_Coord*<br/>
As coordenadas das quais obter o exemplo. Os valores de coordenadas fracionárias são usados para fazer a interpolação entre texels de exemplo.

### <a name="return-value"></a>Valor retornado

Um vetor curto de classificação 4 que contém o componente alfa (w) dos 4 valores de Texel amostrados.

## <a name="get"></a>Obter

Obtém o valor do elemento no índice especificado.

```cpp
const value_type get(
    const index<_Rank>& _Index) const restrict(amp);

value_type get(
    const index<_Rank>& _Index,
    unsigned int _Mip_level = 0) const restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Index*<br/>
O índice do elemento a ser obtido, possivelmente multidimensional.

*_Mip_level*<br/>
O nível de mipmap do qual devemos obter o valor. O valor padrão 0 representa o nível de mipmap mais detalhado.

### <a name="return-value"></a>Valor retornado

O valor do elemento.

## <a name="operator_eq"></a>operador =

Atribui uma exibição da mesma textura que a `texture_view` especificada para essa instância de `texture_view`.

```cpp
texture_view<value_type, _Rank>& operator= (// [1] copy constructor
    const texture_view<value_type, _Rank>& _Other) restrict(amp, cpu);

texture_view<const value_type, _Rank>& operator= (// [2] copy constructor
    const texture_view<value_type, _Rank>& _Other) restrict(cpu);

texture_view<const value_type, _Rank>& operator= (// [3] copy constructor
    const texture_view<const value_type, _Rank>& _Other) restrict(amp, cpu);
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
[1, 2] Copiar construtor um objeto de `texture_view` gravável.

[3] Construtor de cópia um objeto de `texture_view` não gravável.

### <a name="return-value"></a>Valor retornado

Uma referência a esta instância de `texture_view`.

## <a name="operator_at"></a>operador []

Retorna o valor do elemento por índice.

```cpp
const value_type operator[] (const index<_Rank>& _Index) const restrict(amp);

const value_type operator[] (int _I0) const restrict(amp);

value_type operator[] (const index<_Rank>& _Index) const restrict(amp);

value_type operator[] (int _I0) const restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Index*<br/>
O índice, possivelmente multidimensional.

*_I0*<br/>
O índice unidimensional.

### <a name="return-value"></a>Valor retornado

O valor do elemento indexado por `_Index`.

## <a name="operator_call"></a>operador ()

Retorna o valor do elemento por índice.

```cpp
const value_type operator() (
    const index<_Rank>& _Index) const restrict(amp);

const value_type operator() (
    int _I0) const restrict(amp);

const value_type operator() (
    int _I0,   int _I1) const restrict(amp);

const value_type operator() (
    int _I0,
    int _I1,
    int _I2) const restrict(amp);

value_type operator() (
    const index<_Rank>& _Index) const restrict(amp);

value_type operator() (
    int _I0) const restrict(amp);

value_type operator() (
    int _I0,
    int _I1) const restrict(amp);

value_type operator() (
    int _I0,
    int _I1,
    int _I2) const restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Index*<br/>
O índice, possivelmente multidimensional.

*_I0*<br/>
O componente mais significativo do índice.

*_I1*<br/>
O componente de próximo a mais significativo do índice.

*_I2*<br/>
O componente menos significativo do índice.

### <a name="return-value"></a>Valor retornado

O valor do elemento indexado por `_Index`.

## <a name="sample"></a>Nova

Amostra a textura nas coordenadas especificadas e o nível de detalhes usando a configuração de amostragem especificada.

```cpp
value_type sample(
    const sampler& _Sampler,
    const coordinates_type& _Coord,
    float _Level_of_detail = 0.0f) const restrict(amp);

template<
    filter_mode _Filter_mode = filter_linear,
    address_mode _Address_mode = address_clamp
>
value_type sample(
    const coordinates_type& _Coord,
    float _Level_of_detail = 0.0f) const restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Filter_mode*<br/>
O modo de filtro a ser usado para exemplificar o texture_view. O modo de filtro é o mesmo para os filtros de minimização, maximização e mipmap.

*_Address_mode*<br/>
O modo de endereço a ser usado para exemplificar o texture_view. O modo de endereço é o mesmo para todas as dimensões.

*_Sampler*<br/>
A configuração de amostra a ser usada para exemplificar o texture_view.

*_Coord*<br/>
As coordenadas das quais obter o exemplo. Os valores de coordenadas fracionárias são usados para fazer a interpolação entre os valores de Texel.

*_Level_of_detail*<br/>
O valor especifica o nível de mipmap para a amostra. Os valores fracionários são usados para interpolar entre dois níveis de mipmap. O nível padrão de detalhe é 0, que representa o nível de MIP mais detalhado.

### <a name="return-value"></a>Valor retornado

O valor de amostra interpolado.

## <a name="set"></a>Definição

Define o valor do elemento no índice especificado como o valor especificado.

```cpp
void set(
    const index<_Rank>& _Index,
    const value_type& value) const restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Index*<br/>
O índice do elemento a ser definido, possivelmente multidimensional.

*value*<br/>
O valor com o qual o elemento será definido.

## <a name="value_type"></a>value_type

O tipo de valor dos elementos do texture_view.

```cpp
typedef typename const value_type value_type;
```

## <a name="see-also"></a>Consulte também

[Namespace Concurrency::graphics](concurrency-graphics-namespace.md)
