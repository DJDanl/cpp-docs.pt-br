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
ms.openlocfilehash: 0f2b627afa216f03592fe913afece1a80f5bd5a6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62351515"
---
# <a name="textureview-class"></a>Classe texture_view

Fornece acesso de leitura e gravação para uma textura. `texture_view` só pode ser usado para ler texturas cujo tipo de valor é `int`, `unsigned int`, ou `float` que têm o bpse de 32 bits do padrão. Para ler outros formatos de textura, use `texture_view<const value_type, _Rank>`.

## <a name="syntax"></a>Sintaxe

```
template<typename value_type,int _Rank>
class texture_view;

template<typename value_type, int _Rank>
class texture_view
   : public details::_Texture_base<value_type, _Rank>;

template<typename value_type, int _Rank>
class texture_view<const value_type, _Rank>
   : public details::_Texture_base<value_type, _Rank>;
```

#### <a name="parameters"></a>Parâmetros

*value_type*<br/>
O tipo dos elementos na textura de agrega.

*_Rank*<br/>
A classificação do `texture_view`.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`value_type`|O tipo dos elementos na textura agrega.|
|`coordinates_type`|O tipo de coordenada usada para especificar um texel na `texture_view`— ou seja, uma `short_vector` que tem a mesma classificação que a textura associada que tem um tipo de valor de `float`.|
|`gather_return_type`|O tipo de retorno usado para coletar operações — ou seja, uma classificação 4 `short_vector` que mantém os quatro componentes de cor homogêneos obtidos os quatro valores de Texel testados.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor de texture_view](#ctor)|Sobrecarregado. Constrói um `texture_view` instância.|
|[~ texture_view destruidor](#ctor)|Destrói o `texture_view` instância.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[gather_alpha](#gather_alpha)|Sobrecarregado. Prova a textura nas coordenadas especificadas usando a configuração de amostragem especificada e retorna os componentes alfa (w) dos quatro texels provados.|
|[gather_blue](#gather_blue)|Sobrecarregado. Prova a textura nas coordenadas especificadas usando a configuração de amostragem especificada e retorna os componentes de azul (z) dos quatro texels provados.|
|[gather_green](#gather_green)|Sobrecarregado. Prova a textura nas coordenadas especificadas usando a configuração de amostragem especificada e retorna os componentes de verde (y) dos quatro texels provados.|
|[gather_red](#gather_red)|Sobrecarregado. Prova a textura nas coordenadas especificadas usando a configuração de amostragem especificada e retorna os componentes vermelho (x) dos quatro texels provados.|
|[get](#get)|Sobrecarregado. Obtém o valor do elemento por índice.|
|[sample](#sample)|Sobrecarregado. Prova a textura nas coordenadas especificadas e do nível de detalhes usando a configuração de amostragem especificada.|
|[set](#set)|Define o valor de um elemento por índice.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operator()](#operator_call)|Sobrecarregado. Obtém o valor do elemento por índice.|
|[operator\[\]](#operator_at)|Sobrecarregado. Obtém o valor do elemento por índice.|
|[operator=](#operator_eq)|Sobrecarregado. Operador de atribuição.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[value_type](#value_type)|O tipo de valor dos elementos do `texture_view`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`_Texture_base`

`texture_view`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amp_graphics. h

**Namespace:** Concurrency:: Graphics

##  <a name="dtor"></a> ~texture_view

Destrói o `texture_view` instância.

```
~texture_view() restrict(amp, cpu);
```

##  <a name="ctor"></a> texture_view

Constrói um `texture_view` instância.

```
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
[1, 2] Construtor de `texture` no qual o gravável `texture_view` é criado.

[3, 4] Construtor de `texture` em que o não gravável `texture_view` é criado.

*_Other*<br/>
[5] o construtor de cópia o código-fonte gravável `texture_view`.

[6, 7] O código-fonte não gravável do construtor de cópia `texture_view`.

*_Mipmap_level*<br/>
O nível de mipmap específico na fonte de `texture` gravável ou nesse `texture_view` está associado. O valor padrão é 0, que representa o nível de mip (mais detalhado) de nível superior.

*_Most_detailed_mip*<br/>
Nível de mip (mais detalhado) de nível para o modo de exibição, relativo ao especificado superior `texture_view` objeto.

*_Mip_levels*<br/>
O número de níveis de mipmap acessíveis por meio de `texture_view`.

##  <a name="gather_red"></a> gather_red

Prova a textura nas coordenadas especificadas usando a configuração de amostragem especificada e retorna os componentes vermelho (x) dos quatro texels provados.

```
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
O modo de endereço para usar a amostra a `texture_view`. O modo de endereço é o mesmo para todas as dimensões.

*_Sampler*<br/>
A configuração de amostra para usar a amostra a `texture_view`.

*_Coord*<br/>
As coordenadas de exemplo do. Valores de coordenadas fracionários são usados para interpolar entre exemplos texels.

### <a name="return-value"></a>Valor de retorno

Um vetor curto de classificação 4 que contém o componente vermelho (x) de 4 valores de texel provados.

##  <a name="gather_green"></a> gather_green

Prova a textura nas coordenadas especificadas usando a configuração de amostragem especificada e retorna os componentes de verde (y) dos quatro texels provados.

```
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
O modo de endereço para usar a amostra a `texture_view`. O modo de endereço é o mesmo para todas as dimensões.

*_Sampler*<br/>
A configuração de amostra para usar a amostra a `texture_view`.

*_Coord*<br/>
As coordenadas de exemplo do. Valores de coordenadas fracionários são usados para interpolar entre exemplos texels.

### <a name="return-value"></a>Valor de retorno

Um vetor curto de classificação 4 que contém o componente verde (y) de 4 valores de texel provados.

##  <a name="gather_blue"></a> gather_blue

Prova a textura nas coordenadas especificadas usando a configuração de amostragem especificada e retorna os componentes de azul (z) dos quatro texels provados.

```
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
O modo de endereço para usar a amostra a `texture_view`. O modo de endereço é o mesmo para todas as dimensões.

*_Sampler*<br/>
A configuração de amostra para usar a amostra a `texture_view`.

*_Coord*<br/>
As coordenadas de exemplo do. Valores de coordenadas fracionários são usados para interpolar entre exemplos texels.

### <a name="return-value"></a>Valor de retorno

Um vetor curto de classificação 4 que contém o componente vermelho (x) de 4 valores de texel provados.

##  <a name="gather_alpha"></a> gather_alpha

Prova a textura nas coordenadas especificadas usando a configuração de amostragem especificada e retorna os componentes alfa (w) dos quatro texels provados.

```
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
O modo de endereço para usar a amostra a `texture_view`. O modo de endereço é o mesmo para todas as dimensões.

*_Sampler*<br/>
A configuração de amostra para usar a amostra a `texture_view`.

*_Coord*<br/>
As coordenadas de exemplo do. Valores de coordenadas fracionários são usados para interpolar entre exemplos texels.

### <a name="return-value"></a>Valor de retorno

Uma classificação 4 curto de vetor que contém o alfa (w) valores de texel provados do componente de 4.

##  <a name="get"></a> Obter

Obtém o valor do elemento no índice especificado.

```
const value_type get(
    const index<_Rank>& _Index) const restrict(amp);

value_type get(
    const index<_Rank>& _Index,
    unsigned int _Mip_level = 0) const restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Index*<br/>
O índice do elemento a ser obtido, possivelmente, multidimensional.

*_Mip_level*<br/>
O nível de mipmap do qual devemos obter o valor. O valor padrão 0 representa o nível de mipmap mais detalhado.

### <a name="return-value"></a>Valor de retorno

O valor do elemento.

##  <a name="operator_eq"></a> operator=

Atribui um modo de exibição da mesma textura conforme o especificado `texture_view` a este `texture_view` instância.

```
texture_view<value_type, _Rank>& operator= (// [1] copy constructor
    const texture_view<value_type, _Rank>& _Other) restrict(amp, cpu);

texture_view<const value_type, _Rank>& operator= (// [2] copy constructor
    const texture_view<value_type, _Rank>& _Other) restrict(cpu);

texture_view<const value_type, _Rank>& operator= (// [3] copy constructor
    const texture_view<const value_type, _Rank>& _Other) restrict(amp, cpu);
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
[1, 2] Construtor de cópia A gravável `texture_view` objeto.

[3] construtor de cópia um não gravável `texture_view` objeto.

### <a name="return-value"></a>Valor de retorno

Uma referência a este `texture_view` instância.

##  <a name="operator_at"></a> operator[]

Retorna o valor do elemento por índice.

```
const value_type operator[] (const index<_Rank>& _Index) const restrict(amp);

const value_type operator[] (int _I0) const restrict(amp);

value_type operator[] (const index<_Rank>& _Index) const restrict(amp);

value_type operator[] (int _I0) const restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Index*<br/>
O índice, possivelmente, multidimensional.

*_I0*<br/>
O índice unidimensional.

### <a name="return-value"></a>Valor de retorno

O valor do elemento indexado por `_Index`.

##  <a name="operator_call"></a> operator()

Retorna o valor do elemento por índice.

```
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
O índice, possivelmente, multidimensional.

*_I0*<br/>
O componente mais significativo do índice.

*_I1*<br/>
O componente next-para-mais significativo do índice.

*_I2*<br/>
O componente menos significativo do índice.

### <a name="return-value"></a>Valor de retorno

O valor do elemento indexado por `_Index`.

##  <a name="sample"></a> Exemplo

Prova a textura nas coordenadas especificadas e do nível de detalhes usando a configuração de amostragem especificada.

```
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
O modo de filtro a ser usado para a amostra do texture_view. O modo de filtro é o mesmo para os filtros de minimização, maximização e mipmap.

*_Address_mode*<br/>
O modo de endereço a ser usado para a amostra do texture_view. O modo de endereço é o mesmo para todas as dimensões.

*_Sampler*<br/>
A configuração de amostra a ser usada para a amostra do texture_view.

*_Coord*<br/>
As coordenadas de exemplo do. Valores de coordenadas fracionários são usados para interpolar entre valores texel.

*_Level_of_detail*<br/>
O valor Especifica o nível de mipmap para obter um exemplo. Os valores fracionários são usados para interpolar entre dois níveis de mipmap. O nível de detalhes padrão é 0, que representa o nível de mip mais detalhado.

### <a name="return-value"></a>Valor de retorno

O valor interpolado de exemplo.

##  <a name="set"></a> set

Define o valor do elemento no índice especificado para o valor especificado.

```
void set(
    const index<_Rank>& _Index,
    const value_type& value) const restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Index*<br/>
O índice do elemento a ser definido, possivelmente, multidimensional.

*value*<br/>
O valor para definir o elemento.

##  <a name="value_type"></a> value_type

O tipo de valor dos elementos da texture_view.

```
typedef typename const value_type value_type;
```

## <a name="see-also"></a>Consulte também

[Namespace Concurrency::graphics](concurrency-graphics-namespace.md)
