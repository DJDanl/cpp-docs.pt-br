---
title: Classe Array | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
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
dev_langs:
- C++
helpviewer_keywords:
- array class
ms.assetid: 0832b6c1-40f0-421d-9104-6b1baa0c63a7
caps.latest.revision: 31
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: 470918d62357a8dd463db35b4d929e7ec5c2f251
ms.contentlocale: pt-br
ms.lasthandoff: 03/17/2017

---
# <a name="array-class"></a>Classe array
Representa um contêiner de dados usado para mover dados para um acelerador.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <typename value_type, int _Rank>  
friend class array;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `value_type`  
 O tipo de elemento de dados.  
  
 `_Rank`  
 A classificação da matriz.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor de matriz](#ctor)|Inicializa uma nova instância da classe `array`.|  
|[~ Destruidor de matriz](#dtor)|Destrói o `array` objeto.|  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[copy_to](#copy_to)|Copia o conteúdo da matriz a outra matriz.|  
|[data](#data)|Retorna um ponteiro para os dados brutos da matriz.|  
|[get_accelerator_view](#get_accelerator_view)|Retorna o [accelerator_view](accelerator-view-class.md) objeto que representa o local onde a matriz é alocada. Essa propriedade pode ser acessada apenas na CPU.|  
|[get_associated_accelerator_view](#get_associated_accelerator_view)|Obtém a segunda [accelerator_view](accelerator-view-class.md) objeto passado como um parâmetro quando um construtor de preparo é chamado para instanciar o `array` objeto.|  
|[get_cpu_access_type](#get_cpu_access_type)|Retorna o [access_type](concurrency-namespace-enums-amp.md#access_type) da matriz. Esse método pode ser acessado apenas na CPU.|  
|[get_extent](#get_extent)|Retorna o [extensão](extent-class.md) objeto da matriz.|  
|[reinterpret_as](#reinterpret_as)|Retorna uma matriz unidimensional que contém todos os elementos de `array` objeto.|  
|[seção](#section)|Retorna uma subseção de `array` objeto que é a origem especificada e, opcionalmente, que tem a extensão especificada.|  
|[view_as](#view_as)|Retorna um [array_view](array-view-class.md) objeto é construído a partir de `array` objeto.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operador std:: Vector&lt;value_type&gt;](#operator_vec)|Usa `copy(*this, vector)` para converter implicitamente a matriz em um std::[vetor](../../../standard-library/vector-class.md) objeto.|  
|[Operator)](#operator_call)|Retorna o valor do elemento especificado pelos parâmetros.|  
|[operador]](#operator_at)|Retorna o elemento no índice especificado.|  
|[operator=](#operator_eq)|Copia o conteúdo especificado `array` deste objeto.|  
  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Constante Rank](#rank)|Armazena a classificação da matriz.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[accelerator_view](#accelerator_view)|Obtém o [accelerator_view](accelerator-view-class.md) objeto que representa o local onde a matriz é alocada. Essa propriedade pode ser acessada apenas na CPU.|  
|[associated_accelerator_view](#associated_accelerator_view)|Obtém a segunda [accelerator_view](accelerator-view-class.md) objeto passado como um parâmetro quando um construtor de preparo é chamado para instanciar o `array` objeto.|  
|[cpu_access_type](#cpu_access_type)|Obtém o [access_type](concurrency-namespace-enums-amp.md#access_type) que representa como a CPU pode acessar o armazenamento da matriz.|  
|[extent](#extent)|Obtém a extensão que define a forma da matriz.|  
  
## <a name="remarks"></a>Comentários  
 O tipo `array<T,N>` representa um densa e regulares (não denteadas) *N*-matriz dimensional que está localizado em um local específico, como um acelerador ou a CPU. O tipo de dados dos elementos na matriz é `T`, que deve ser de um tipo que é compatível com o Acelerador de destino. Embora a classificação, `N`, (de matriz é determinada estaticamente e faz parte do tipo, a extensão da matriz é determinada pelo tempo de execução e é expresso usando a classe `extent<N>`.  
  
 Uma matriz pode ter qualquer número de dimensões, embora alguma funcionalidade é especializada para `array` objetos com uma classificação, dois e três. Se você omitir o argumento de dimensão, o padrão é 1.  
  
 Dados da matriz é apresentados contiguamente na memória. Elementos que diferem por um na dimensão menos significativa são adjacentes na memória.  
  
 Matrizes são logicamente consideradas tipos de valor, porque quando uma matriz é copiada para outra matriz, uma cópia em profundidade é executada. Duas matrizes nunca apontam para os mesmos dados.  
  
 O `array<T,N>` tipo é usado em vários cenários:  
  
-   Como um contêiner de dados que pode ser usado em cálculos de um acelerador.  
  
-   Como um contêiner de dados para manter a memória no host da CPU (que pode ser usada para copiar para e de outras matrizes).  
  
-   Como um objeto temporário para atuar como um intermediário rápido em cópias do host para o dispositivo.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `array`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp.h  
  
 **Namespace:** Simultaneidade  
  
##  <a name="dtor"></a>~ array 

 Destrói o `array` objeto.  
  
```  
~array() restrict(cpu);
```  
  
##  <a name="accelerator_view"></a>accelerator_view 

 Obtém o [accelerator_view](accelerator-view-class.md) objeto que representa o local onde a matriz é alocada. Essa propriedade pode ser acessada apenas na CPU.  
  
```  
__declspec(property(get= get_accelerator_view)) Concurrency::accelerator_view accelerator_view;  
```  
  
##  <a name="ctor"></a>matriz 

 Inicializa uma nova instância de [classe array](array-class.md). Não há nenhum construtor padrão para `array<T,N>`. Todos os construtores são executados em apenas a CPU. Elas não podem ser executadas em um destino do Direct3D.  
  
```  
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
 `_Associated_Av`  
 Um accelerator_view que especifica o local de destino preferencial da matriz.  
  
 `_Av`  
 Um [accelerator_view](accelerator-view-class.md) objeto que especifica o local da matriz.  
  
 `_Cpu_access_type`  
 O [access_type](concurrency-namespace-enums-amp.md#access_type) para a matriz na CPU. Esse parâmetro tem um valor padrão de `access_type_auto` liberando a CPU `access_type` determinação no tempo de execução. A CPU real `access_type` para a matriz pode ser consultada usando o `get_cpu_access_type` método.  
  
 `_Extent`  
 A extensão em cada dimensão da matriz.  
  
 `_E0`  
 O fator mais significativo da extensão desta seção.  
  
 `_E1`  
 O componente Avançar-para-mais significativo da extensão desta seção.  
  
 `_E2`  
 O componente menos significativo da extensão desta seção.  
  
 `_InputIterator`  
 O tipo de interator de entrada.  
  
 `_Src`  
 Para copiar o objeto.  
  
 `_Src_first`  
 Um iterador de início para o contêiner de origem.  
  
 `_Src_last`  
 Um iterador final no contêiner de origem.  
  
 `_Other`  
 Outra fonte de dados.  
  
 `_Rank`  
 A classificação da seção.  
  
 `value_type`  
 O tipo de dados dos elementos que são copiados.  
  
##  <a name="associated_accelerator_view"></a>associated_accelerator_view 

 Obtém a segunda [accelerator_view](accelerator-view-class.md) objeto passado como um parâmetro quando um construtor de preparo é chamado para instanciar o `array` objeto.  
  
```  
__declspec(property(get= get_associated_accelerator_view)) Concurrency::accelerator_view associated_accelerator_view;  
```  
  
##  <a name="copy_to"></a>copy_to 

 Copia o conteúdo da `array` para outro `array`.  
  
```  
void copy_to(
    array<value_type, _Rank>& _Dest) const ;  
 
void copy_to(
    array_view<value_type, _Rank>& _Dest) const ;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Dest`  
 O [array_view](array-view-class.md) objeto para copiar.  
  
##  <a name="cpu_access_type"></a>cpu_access_type 

 Obtém o access_type CPU permitidos para essa matriz.  
  
```  
__declspec(property(get= get_cpu_access_type)) access_type cpu_access_type;  
```  
  
##  <a name="data"></a>dados 

 Retorna um ponteiro para os dados brutos do `array`.  
  
```  
value_type* data() restrict(amp, cpu);
  
const value_type* data() const restrict(amp, cpu);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para os dados brutos da matriz.  
  
##  <a name="extent"></a>extensão 

 Obtém o [extensão](extent-class.md) que define a forma do objeto de `array`.  
  
```  
__declspec(property(get= get_extent)) Concurrency::extent<_Rank> extent;  
```  
  
##  <a name="get_accelerator_view"></a>get_accelerator_view 

 Retorna o [accelerator_view](accelerator-view-class.md) objeto que representa o local onde o `array` objeto é alocado. Essa propriedade pode ser acessada apenas na CPU.  
  
```  
Concurrency::accelerator_view get_accelerator_view() const;  
```    
  
### <a name="return-value"></a>Valor de retorno  
 O `accelerator_view` objeto que representa o local onde o `array` objeto é alocado.  
  
##  <a name="get_associated_accelerator_view"></a>get_associated_accelerator_view 

 Obtém a segunda [accelerator_view](accelerator-view-class.md) objeto passado como um parâmetro quando um construtor de preparo é chamado para instanciar o `array` objeto.  
  
```  
Concurrency::accelerator_view get_associated_accelerator_view() const ;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A segunda [accelerator_view](accelerator-view-class.md) objeto passado para o construtor de preparo.  
  
##  <a name="get_cpu_access_type"></a>get_cpu_access_type 

 Retorna o access_type de CPU que é permitido para essa matriz.  
  
```  
access_type get_cpu_access_type() const restrict(cpu);
```  
  
### <a name="return-value"></a>Valor de retorno  
  
##  <a name="get_extent"></a>get_extent 

 Retorna o [extensão](extent-class.md) objeto o `array`.  
  
```  
Concurrency::extent<_Rank> get_extent() const restrict(amp,cpu);
```  
  
### <a name="return-value"></a>Valor de retorno  
 O `extent` objeto o `array`.  
  
##  <a name="operator_vec"></a>operador std:: Vector&lt;value_type&gt; 

 Usa `copy(*this, vector)` para converter implicitamente a matriz a um objeto std:: Vector.  
  
```  
operator std::vector<value_type>() const restrict(cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `value_type`  
 O tipo de dados dos elementos do vetor.  
  
### <a name="return-value"></a>Valor de retorno  
 Um objeto do tipo `vector<T>` que contém uma cópia dos dados que estão contidos na matriz.  
  
##  <a name="operator_call"></a>Operator) 

 Retorna o valor do elemento especificado pelos parâmetros.  
  
```  
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
 `_Index`  
 O local do elemento.  
  
 `_I0`  
 O fator mais significativo da origem desta seção.  
  
 `_I1`  
 O componente Avançar-para-mais significativo da origem desta seção.  
  
 `_I2`  
 O componente menos significativo da origem desta seção.  
  
 `_I`  
 O local do elemento.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor do elemento especificado pelos parâmetros.  
  
##  <a name="operator_at"></a>operador] 

 Retorna o elemento no índice especificado.  
  
```  
value_type& operator[](const index<_Rank>& _Index) restrict(amp,cpu);  
  
const value_type& operator[]  
    (const index<_Rank>& _Index) const restrict(amp,cpu);  
  
typename details::_Projection_result_type<value_type,_Rank>::_Result_type operator[](int _i) restrict(amp,cpu);
  
typename details::_Projection_result_type<value_type,_Rank>::_Const_result_type operator[](int _i) const restrict(amp,cpu);
```  
    
### <a name="parameters"></a>Parâmetros  
 `_Index`  
 O índice.  
  
 `_I`  
 O índice.  
  
### <a name="return-value"></a>Valor de retorno  
 O elemento no índice especificado.  
  
##  <a name="operator_eq"></a>operador = 

 Copia o conteúdo especificado `array` objeto.  
  
```  
array& operator= (const array& _Other) restrict(cpu);  
   
array& operator= (array&& _Other) restrict(cpu);  
 
array& operator= (  
    const array_view<const value_type, _Rank>& _Src) restrict(cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `array` objeto copiar de.  
  
 `_Src`  
 O `array` objeto copiar de.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a esta `array` objeto.  
  
##  <a name="rank"></a>classificação 

 Armazena a classificação do `array`.  
  
```  
static const int rank = _Rank;  
```  
## <a name="reinterpret_as"></a>reinterpret_as 

Reinterprets array por meio de um array_view unidimensional, que, opcionalmente, pode ter um tipo de valor diferente do que a matriz de origem.

### <a name="syntax"></a>Sintaxe
``` 
template <typename _Value_type2>  
array_view<_Value_type2,1> reinterpret_as() restrict(amp,cpu);  
  
template <typename _Value_type2>  
array_view<const _Value_type2, 1> reinterpret_as() const restrict(amp,cpu);  
``` 
  
### <a name="parameters"></a>Parâmetros  
`_Value_type2`O tipo de dados dos dados retornados.

### <a name="return-value"></a>Valor de retorno
Um array_view ou const objeto array_view com base no conjunto, com o tipo de elemento reinterpretado de T ElementType e a classificação reduzido de N a 1.

### <a name="remarks"></a>Comentários
Às vezes é conveniente exibir uma matriz multidimensional como se fosse uma matriz unidimensional, linear, possivelmente com um tipo de valor diferente do que a matriz de origem. Você pode usar esse método para fazer isso.
**Cuidado** Reinterpretação um objeto de matriz usando um tipo de valor diferente é uma operação potencialmente não segura. É recomendável que você use essa funcionalidade com cuidado. 

O código a seguir fornece um exemplo.

```cpp  
struct RGB { float r; float g; float b; };

array<RGB,3>  a = ...; 
array_view<float,1> v = a.reinterpret_as<float>(); 

assert(v.extent == 3*a.extent);
```  
  
##  <a name="section"></a>seção 

 Retorna uma subseção de `array` objeto que é a origem especificada e, opcionalmente, que tem a extensão especificada.  
  
```  
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
 `_E0`  
 O fator mais significativo da extensão desta seção.  
  
 `_E1`  
 O componente Avançar-para-mais significativo da extensão desta seção.  
  
 `_E2`  
 O componente menos significativo da extensão desta seção.  
  
 `_Ext`  
 O [extensão](extent-class.md) objeto que especifica a extensão da seção. A origem é 0.  
  
 `_Idx`  
 O [índice](index-class.md) objeto que especifica o local da origem. A subseção é o restante da extensão.  
  
 `_I0`  
 O fator mais significativo da origem desta seção.  
  
 `_I1`  
 O componente Avançar-para-mais significativo da origem desta seção.  
  
 `_I2`  
 O componente menos significativo da origem desta seção.  
  
 `_Rank`  
 A classificação da seção.  
  
 `_Section_extent`  
 O [extensão](extent-class.md) objeto que especifica a extensão da seção.  
  
 `_Section_origin`  
 O [índice](index-class.md) objeto que especifica o local da origem.  
  
 `value_type`  
 O tipo de dados dos elementos que são copiados.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma subseção de `array` objeto que é a origem especificada e, opcionalmente, que tem a extensão especificada. Quando apenas o `index` objeto for especificado, a subseção contém todos os elementos na grade associada que têm índices maiores que os índices dos elementos de `index` objeto.  
  
##  <a name="view_as"></a>view_as 

 Reinterprets essa matriz como uma [array_view](array-view-class.md) de uma posição diferente.  
  
```  
template <int _New_rank>  
array_view<value_type,_New_rank> view_as(
    const Concurrency::extent<_New_rank>& _View_extent) restrict(amp,cpu);

 
template <int _New_rank>  
array_view<const value_type,_New_rank> view_as(
    const Concurrency::extent<_New_rank>& _View_extent) const restrict(amp,cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_New_rank`  
 A classificação do `extent` objeto passado como um parâmetro.  
  
 `_View_extent`  
 A extensão que é usada para criar o novo [array_view](array-view-class.md) objeto.  
  
 `value_type`  
 O tipo de dados dos elementos no original `array` retornado e objeto `array_view` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 O [array_view](array-view-class.md) objeto que é construído.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)

