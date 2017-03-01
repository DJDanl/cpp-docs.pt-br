---
title: Classe texture_view | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 6ec2e289-1626-4727-9592-07981cf1d27d
caps.latest.revision: 11
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: fc190feb08d9b221cd1cc21a9c91ad567c86c848
ms.openlocfilehash: 7d3206aea6a6f1e3033e157b3b99a6b3486cb2ac
ms.lasthandoff: 02/25/2017

---
# <a name="textureview-class"></a>Classe texture_view
Fornece acesso de leitura e gravação para uma textura. `texture_view`só pode ser usada para ler texturas cujo tipo de valor é `int`, `unsigned int`, ou `float` com bpse de 32 bits padrão. Para ler os outros formatos de textura, use `texture_view<const value_type, _Rank>`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <
    typename value_type,  
    int _Rank  
>  
class texture_view;  
 
template <
    typename value_type,  
    int _Rank  
>  
class texture_view : public details::_Texture_base<value_type, _Rank>;  
 
template <
    typename value_type,  
    int _Rank  
>  
class texture_view<const value_type, _Rank> : public details::_Texture_base<value_type, _Rank>;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `value_type`  
 O tipo dos elementos a agregação de textura.  
  
 `_Rank`  
 A classificação do `texture_view`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`value_type`|O tipo dos elementos em agregações de textura.|  
|`coordinates_type`|O tipo da coordenada usado para especificar uma conhecida como texel no `texture_view`— ou seja, um `short_vector` que tem a mesma classificação como textura associada com um tipo de valor de `float`.|  
|`gather_return_type`|O tipo de retorno usado para coletar as operações — ou seja, uma classificação 4 `short_vector` que mantém os quatro componentes de cor homogêneo obtidas os quatro valores conhecida como texel de amostra.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor texture_view](#ctor)|Sobrecarregado. Constrói um `texture_view` instância.|  
|[~ texture_view destruidor](#ctor)|Destrói a `texture_view` instância.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método gather_alpha](#gather_alpha)|Sobrecarregado. Amostras de textura em coordenadas especificadas usando a configuração de amostragem especificada e retorna os componentes alfa (w) de quatro texels de amostras.|  
|[Método gather_blue](#gather_blue)|Sobrecarregado. Amostras de textura em coordenadas especificadas usando a configuração de amostragem especificada e retorna os componentes azul (z) as quatro texels de amostras.|  
|[Método gather_green](#gather_green)|Sobrecarregado. Amostras de textura em coordenadas especificadas usando a configuração de amostragem especificada e retorna os componentes verde (y) de quatro texels de amostras.|  
|[Método gather_red](#gather_red)|Sobrecarregado. Amostras de textura em coordenadas especificadas usando a configuração de amostragem especificada e retorna os componentes (x) vermelho as quatro texels de amostras.|  
|[Método Get](#get)|Sobrecarregado. Obtém o valor do elemento por índice.|  
|[exemplo de método](#sample)|Sobrecarregado. Amostras de textura em nível de detalhe de coordenadas especificadas e com a configuração de amostragem especificado.|  
|[Método Set](#set)|Define o valor de um elemento por índice.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Operador Operator)](#operator__)|Sobrecarregado. Obtém o valor do elemento por índice.|  
|[Operador do operador]](#operator_at)|Sobrecarregado. Obtém o valor do elemento por índice.|  
|[operador Operator =](#operator_eq)|Sobrecarregado. Operador de atribuição.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados value_type](#value_type)|O tipo de valor dos elementos do `texture_view`.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `_Texture_base`  
  
 `texture_view`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp_graphics.h  
  
 **Namespace:** Concurrency:: Graphics  
  
##  <a name="a-namedtora-textureview"></a><a name="dtor"></a>~ texture_view 

 Destrói a `texture_view` instância.  
  
```  
~texture_view() restrict(amp, cpu);
```  
  
##  <a name="a-namectora-textureview"></a><a name="ctor"></a>texture_view 

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
 `_Src`  
 [1, 2] Construtor  
 O `texture` no qual o gravável `texture_view` é criado.  
  
 [3, 4] Construtor  
 O `texture` no qual a não ser graváveis `texture_view` é criado.  
  
 `_Other`  
 [5] construtor de cópia  
 A origem gravável `texture_view`.  
  
 [6, 7] Construtor de cópia  
 A fonte não graváveis `texture_view`.  
  
 `_Mipmap_level`  
 O nível de mipmap específicos na fonte de `texture` gravável ou neste `texture_view` associa a. O valor padrão é 0, que representa o nível de mip de nível superior (mais detalhada).  
  
 `_Most_detailed_mip`  
 Principais de nível de mip nível (mais detalhada) para o modo de exibição, relativo especificado `texture_view` objeto.  
  
 `_Mip_levels`  
 O número de níveis de mipmap acessíveis por meio de `texture_view`.  
  
##  <a name="a-namegatherreda-gatherred"></a><a name="gather_red"></a>gather_red 

 Amostras de textura em coordenadas especificadas usando a configuração de amostragem especificada e retorna os componentes (x) vermelho as quatro texels de amostras.  
  
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
 `_Address_mode`  
 O modo de endereço para usar a amostra de `texture_view`. O modo de endereço é o mesmo para todas as dimensões.  
  
 `_Sampler`  
 A configuração de amostra para usar a amostra de `texture_view`.  
  
 `_Coord`  
 As coordenadas para executar o exemplo do. Valores de coordenada fracionários são usados a interpolação entre texels de exemplo.  
  
### <a name="return-value"></a>Valor de retorno  
 Um vetor de classificação 4 curto que contém o componente vermelho (x) do 4 amostrados valores conhecida como texel.  
  
##  <a name="a-namegathergreena-gathergreen"></a><a name="gather_green"></a>gather_green 

 Amostras de textura em coordenadas especificadas usando a configuração de amostragem especificada e retorna os componentes verde (y) de quatro texels de amostras.  
  
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
 `_Address_mode`  
 O modo de endereço para usar a amostra de `texture_view`. O modo de endereço é o mesmo para todas as dimensões.  
  
 `_Sampler`  
 A configuração de amostra para usar a amostra de `texture_view`.  
  
 `_Coord`  
 As coordenadas para executar o exemplo do. Valores de coordenada fracionários são usados a interpolação entre texels de exemplo.  
  
### <a name="return-value"></a>Valor de retorno  
 Um vetor de classificação 4 curto que contém o componente verde (y) do 4 amostrados valores conhecida como texel.  
  
##  <a name="a-namegatherbluea-gatherblue"></a><a name="gather_blue"></a>gather_blue 

 Amostras de textura em coordenadas especificadas usando a configuração de amostragem especificada e retorna os componentes azul (z) as quatro texels de amostras.  
  
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
 `_Address_mode`  
 O modo de endereço para usar a amostra de `texture_view`. O modo de endereço é o mesmo para todas as dimensões.  
  
 `_Sampler`  
 A configuração de amostra para usar a amostra de `texture_view`.  
  
 `_Coord`  
 As coordenadas para executar o exemplo do. Valores de coordenada fracionários são usados a interpolação entre texels de exemplo.  
  
### <a name="return-value"></a>Valor de retorno  
 Um vetor de classificação 4 curto que contém o componente vermelho (x) do 4 amostrados valores conhecida como texel.  
  
##  <a name="a-namegatheralphaa-gatheralpha"></a><a name="gather_alpha"></a>gather_alpha 

 Amostras de textura em coordenadas especificadas usando a configuração de amostragem especificada e retorna os componentes alfa (w) de quatro texels de amostras.  
  
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
 `_Address_mode`  
 O modo de endereço para usar a amostra de `texture_view`. O modo de endereço é o mesmo para todas as dimensões.  
  
 `_Sampler`  
 A configuração de amostra para usar a amostra de `texture_view`.  
  
 `_Coord`  
 As coordenadas para executar o exemplo do. Valores de coordenada fracionários são usados a interpolação entre texels de exemplo.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma classificação 4 curto de vetor que contém o alfa (w) valores conhecida como texel de amostra de componente do 4.  
  
##  <a name="a-namegeta-get"></a><a name="get"></a>Obter 

 Obtém o valor do elemento no índice especificado.  
  
```  
const value_type get(
    const index<_Rank>& _Index) const restrict(amp);

 
value_type get(
    const index<_Rank>& _Index,  
    unsigned int _Mip_level = 0) const restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Index`  
 O índice do elemento a ser obtido, possivelmente multidimensionais.  
  
 `_Mip_level`  
 O nível de mipmap do qual devemos obter o valor. O valor padrão 0 representa o nível mais detalhado de mipmap.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor do elemento.  
  
##  <a name="a-nameoperatoreqa-operator"></a><a name="operator_eq"></a>operador = 

 Atribui uma exibição da textura mesmo conforme o especificado `texture_view` a esta `texture_view` instância.  
  
```  
texture_view<value_type, _Rank>& operator= (// [1] copy constructor  
    const texture_view<value_type, _Rank>& _Other) restrict(amp, cpu);

 
texture_view<const value_type, _Rank>& operator= (// [2] copy constructor  
    const texture_view<value_type, _Rank>& _Other) restrict(cpu);

 
texture_view<const value_type, _Rank>& operator= (// [3] copy constructor  
    const texture_view<const value_type, _Rank>& _Other) restrict(amp, cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 [1, 2] Construtor de cópia  
 Um objeto `texture_view` gravável.  
  
 [3] construtor de cópia  
 Um não graváveis `texture_view` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a esta `texture_view` instância.  
  
##  <a name="a-nameoperatorata-operator"></a><a name="operator_at"></a>operador] 

 Retorna o valor do elemento por índice.  
  
```  
const value_type operator[] (const index<_Rank>& _Index) const restrict(amp);

 
const value_type operator[] (int _I0) const restrict(amp);

 
value_type operator[] (const index<_Rank>& _Index) const restrict(amp);

 
value_type operator[] (int _I0) const restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Index`  
 O índice, possivelmente multidimensional.  
  
 `_I0`  
 O índice unidimensional.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor do elemento indexado por `_Index`.  
  
##  <a name="a-nameoperatora-operator"></a><a name="operator__"></a>Operator) 

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
 `_Index`  
 O índice, possivelmente multidimensional.  
  
 `_I0`  
 O componente mais significativo do índice.  
  
 `_I1`  
 O componente Avançar-para-mais significativo do índice.  
  
 `_I2`  
 O componente menos significativo do índice.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor do elemento indexado por `_Index`.  
  
##  <a name="a-namesamplea-sample"></a><a name="sample"></a>exemplo 

 Amostras de textura em nível de detalhe de coordenadas especificadas e com a configuração de amostragem especificado.  
  
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
 `_Filter_mode`  
 O modo de filtro para usar para o texture_view de exemplo. O modo de filtro é o mesmo para filtros de mipmap, minimização e maximização.  
  
 `_Address_mode`  
 O modo de endereço para usar para o texture_view de exemplo. O modo de endereço é o mesmo para todas as dimensões.  
  
 `_Sampler`  
 A configuração de amostra para usar para o texture_view de exemplo.  
  
 `_Coord`  
 As coordenadas para executar o exemplo do. Valores de coordenada fracionários são usados a interpolação entre valores conhecida como texel.  
  
 `_Level_of_detail`  
 O valor Especifica o nível de mipmap a partir de exemplo. Os valores fracionários são usados para a interpolação entre dois níveis de mipmap. O nível de detalhe padrão é 0, que representa o nível mais detalhado de mip.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de amostra interpolados.  
  
##  <a name="a-nameseta-set"></a><a name="set"></a>definir 

 Define o valor do elemento no índice especificado para o valor especificado.  
  
```  
void set(
    const index<_Rank>& _Index,  
    const value_type& value) const restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Index`  
 O índice do elemento a ser definido, possivelmente multidimensionais.  
  
 `value`  
 O valor para definir o elemento.  
  
##  <a name="a-namevaluetypea-valuetype"></a><a name="value_type"></a>value_type 

 O tipo de valor dos elementos do texture_view.  
  
```  
typedef typename const value_type value_type;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Concurrency:: Graphics](concurrency-graphics-namespace.md)

