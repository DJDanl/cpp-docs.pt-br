---
title: "Classe array | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "amp/Concurrency::array"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe Array"
ms.assetid: 0832b6c1-40f0-421d-9104-6b1baa0c63a7
caps.latest.revision: 31
caps.handback.revision: 31
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe array
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Representa um contêiner de dados usado para mover dados para um acelerador.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <
    typename value_type,  
    int _Rank  
>  
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
|[array:: array construtor](#array__array_constructor)|Inicializa uma nova instância da classe `array`.|  
|[array:: ~ destruidor de matriz](#array___dtorarray_destructor)|Destrói o `array` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método Array:: copy_to](#array__copy_to_method)|Copia o conteúdo da matriz a outra matriz.|  
|[Método Array:: data](#array__data_method)|Retorna um ponteiro para os dados brutos da matriz.|  
|[Método Array:: get_accelerator_view](#array__get_accelerator_view_method)|Retorna o [accelerator_view](../Topic/accelerator_view%20Class.md) objeto que representa o local onde a matriz é alocada. Essa propriedade pode ser acessada apenas na CPU.|  
|[Método Array:: get_associated_accelerator_view](#array__get_associated_accelerator_view_method)|Obtém a segunda [accelerator_view](../Topic/accelerator_view%20Class.md) objeto passado como um parâmetro quando um construtor de preparo é chamado para instanciar o [matriz](../../../parallel/amp/reference/array-class.md) objeto.|  
|[Método Array:: get_cpu_access_type](#array__get_cpu_access_type_method)|Retorna o [access_type](access_type%20Enumeration.md) da matriz. Esse método pode ser acessado apenas na CPU.|  
|[Método Array:: get_extent](#array__get_extent_method)|Retorna o [extensão](../Topic/extent%20Class%20\(C++%20AMP\).md) objeto da matriz.|  
|[Método Array:: reinterpret_as](#array__reinterpret_as_method)|Retorna uma matriz unidimensional que contém todos os elementos de `array` objeto.|  
|[Método Array:: Section](#array__section_method)|Retorna uma subseção de [matriz](../../../parallel/amp/reference/array-class.md) objeto que é a origem especificada e, opcionalmente, que tem a extensão especificada.|  
|[Método Array:: view_as](#array__view_as_method)|Retorna um [array_view](../../../parallel/amp/reference/array-view-class.md) objeto é construído a partir de `array` objeto.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[array:: Operator std:: Vector&lt;value_type&gt; operador](#array__operator_std__vector_lt__value_type_gt__operator)|Usa `copy(*this, vector)` para converter implicitamente a matriz em um std::[vetor](../../../standard-library/vector-class.md) objeto.|  
|[Operador Operator array::)](#array__operator___operator)|Retorna o valor do elemento especificado pelos parâmetros.|  
|[array:: Operator operador]](#array__operator_at_operator)|Retorna o elemento no índice especificado.|  
|[array:: Operator operador =](#array__operator_eq_operator)|Copia o conteúdo especificado `array` deste objeto.|  
  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[array:: Rank constante](#array__rank_constant)|Armazena a classificação da matriz.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[array:: accelerator_view membro de dados](#array__accelerator_view_data_member)|Obtém o [accelerator_view](../Topic/accelerator_view%20Class.md) objeto que representa o local onde a matriz é alocada. Essa propriedade pode ser acessada apenas na CPU.|  
|[array:: associated_accelerator_view membro de dados](#array__associated_accelerator_view_data_member)|Obtém a segunda [accelerator_view](../Topic/accelerator_view%20Class.md) objeto passado como um parâmetro quando um construtor de preparo é chamado para instanciar o [matriz](../../../parallel/amp/reference/array-class.md) objeto.|  
|[array:: cpu_access_type membro de dados](#array__cpu_access_type_data_member)|Obtém o [access_type](access_type%20Enumeration.md) que representa como a CPU pode acessar o armazenamento da matriz.|  
|[array:: Extent membro de dados](#array__extent_data_member)|Obtém a extensão que define a forma da matriz.|  
  
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
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namearraydtorarraydestructora-arrayarray-destructor"></a><a name="array___dtorarray_destructor"></a>  array:: ~ destruidor de matriz  
 Destrói o `array` objeto.  
  
```  
~array() restrict(cpu);
```  
  
##  <a name="a-namearrayacceleratorviewdatamembera-arrayacceleratorview-data-member"></a><a name="array__accelerator_view_data_member"></a>  array:: accelerator_view membro de dados  
 Obtém o [accelerator_view](../Topic/accelerator_view%20Class.md) objeto que representa o local onde a matriz é alocada. Essa propriedade pode ser acessada apenas na CPU.  
  
```  
__declspec(property(get= get_accelerator_view)) Concurrency::accelerator_view accelerator_view;  
```  
  
##  <a name="a-namearrayarrayconstructora-arrayarray-constructor"></a><a name="array__array_constructor"></a>  array:: array construtor  
 Inicializa uma nova instância de [classe array](../../../parallel/amp/reference/array-class.md). Não há nenhum construtor padrão para `array<T,N>`. Todos os construtores são executados em apenas a CPU. Elas não podem ser executadas em um destino do Direct3D.  
  
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

 
template <
    typename _InputIterator  
>  
array(
    const Concurrency::extent<_Rank>& _Extent, _InputIterator _Src_first, _InputIterator _Src_last) restrict(cpu);

 
template <
    typename _InputIterator  
>  
array(
    const Concurrency::extent<_Rank>& _Extent, _InputIterator _Src_first) restrict(cpu);

 
template <
    typename _InputIterator  
>  
array(
    int _E0, _InputIterator _Src_first, _InputIterator _Src_last) restrict(cpu);

 
template <
    typename _InputIterator  
>  
array(
    int _E0, _InputIterator _Src_first) restrict(cpu);

 
template <
    typename _InputIterator  
>  
array(
    int _E0,  
    int _E1, _InputIterator _Src_first, _InputIterator _Src_last) restrict(cpu);

 
template <
    typename _InputIterator  
>  
array(
    int _E0,  
    int _E1, _InputIterator _Src_first) restrict(cpu);

 
template <
    typename _InputIterator  
>  
array(
    int _E0,  
    int _E1,  
    int _E2, _InputIterator _Src_first, _InputIterator _Src_last) restrict(cpu);

 
template <
    typename _InputIterator  
>  
array(
    int _E0,  
    int _E1,  
    int _E2, _InputIterator _Src_first) restrict(cpu);

 
template <
    typename _InputIterator  
>  
array(
    const Concurrency::extent<_Rank>& _Extent, _InputIterator _Src_first, _InputIterator _Src_last,  
    Concurrency::accelerator_view _Av  
    access_type _Cpu_access_type = access_type_auto) restrict(cpu);

 
template <
    typename _InputIterator  
>  
array(
    const Concurrency::extent<_Rank>& _Extent, _InputIterator _Src_first,  
    Concurrency::accelerator_view _Av  
    access_type _Cpu_access_type = access_type_auto) restrict(cpu);

 
template <
    typename _InputIterator  
>  
array(
    int _E0, _InputIterator _Src_first, _InputIterator _Src_last,  
    Concurrency::accelerator_view _Av  
    access_type _Cpu_access_type = access_type_auto) restrict(cpu);

 
template <
    typename _InputIterator  
>  
array(
    int _E0, _InputIterator _Src_first,  
    Concurrency::accelerator_view _Av  
    access_type _Cpu_access_type = access_type_auto) restrict(cpu);

 
template <
    typename _InputIterator  
>  
array(
    int _E0,  
    int _E1, _InputIterator _Src_first, _InputIterator _Src_last,  
    Concurrency::accelerator_view _Av  
    access_type _Cpu_access_type = access_type_auto) restrict(cpu);

 
template <
    typename _InputIterator  
>  
array(
    int _E0,  
    int _E1, _InputIterator _Src_first,  
    Concurrency::accelerator_view _Av  
    access_type _Cpu_access_type = access_type_auto) restrict(cpu);

 
template <
    typename _InputIterator  
>  
array(
    int _E0,  
    int _E1,  
    int _E2, _InputIterator _Src_first, _InputIterator _Src_last,  
    Concurrency::accelerator_view _Av,  
    access_type _Cpu_access_type = access_type_auto) restrict(cpu);

 
template <
    typename _InputIterator  
>  
array(
    int _E0,  
    int _E1,  
    int _E2, _InputIterator _Src_first,  
    Concurrency::accelerator_view _Av  
    access_type _Cpu_access_type = access_type_auto) restrict(cpu);

 
template <
    typename _InputIterator  
>  
array(
    const Concurrency::extent<_Rank>& _Extent, _InputIterator _Src_first, _InputIterator _Src_last,  
    Concurrency::accelerator_view _Av,  
    Concurrency::accelerator_view _Associated_Av) restrict(cpu);

 
template <
    typename _InputIterator  
>  
array(
    const Concurrency::extent<_Rank>& _Extent, _InputIterator _Src_first,  
    Concurrency::accelerator_view _Av,  
    Concurrency::accelerator_view _Associated_Av) restrict(cpu);

 
template <
    typename _InputIterator  
>  
array(
    int _E0, _InputIterator _Src_first, _InputIterator _Src_last,  
    Concurrency::accelerator_view _Av,  
    Concurrency::accelerator_view _Associated_Av) restrict(cpu);

 
template <
    typename _InputIterator  
>  
array(
    int _E0, _InputIterator _Src_first,  
    Concurrency::accelerator_view _Av,  
    Concurrency::accelerator_view _Associated_Av) restrict(cpu);

 
template <
    typename _InputIterator  
>  
array(
    int _E0,  
    int _E1, _InputIterator _Src_first, _InputIterator _Src_last,  
    Concurrency::accelerator_view _Av,  
    Concurrency::accelerator_view _Associated_Av) restrict(cpu);

 
template <
    typename _InputIterator  
>  
array(
    int _E0,  
    int _E1, _InputIterator _Src_first,  
    Concurrency::accelerator_view _Av,  
    Concurrency::accelerator_view _Associated_Av) restrict(cpu);

 
template <
    typename _InputIterator  
>  
array(
    int _E0,  
    int _E1,  
    int _E2, _InputIterator _Src_first, _InputIterator _Src_last,  
    Concurrency::accelerator_view _Av,  
    Concurrency::accelerator_view _Associated_Av) restrict(cpu);

 
template <
    typename _InputIterator  
>  
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

 
array(
    const array& _Other) restrict(cpu);

 
array(
    array&& _Other) restrict(cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Associated_Av`  
 Um accelerator_view que especifica o local de destino preferencial da matriz.  
  
 `_Av`  
 Um [accelerator_view](../Topic/accelerator_view%20Class.md) objeto que especifica o local da matriz.  
  
 `_Cpu_access_type`  
 O [access_type](access_type%20Enumeration.md)  para a matriz na CPU. Esse parâmetro tem um valor padrão de `access_type_auto` liberando a CPU `access_type` determinação no tempo de execução. A CPU real `access_type` para a matriz pode ser consultada usando o `get_cpu_access_type` método.  
  
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
  
##  <a name="a-namearrayassociatedacceleratorviewdatamembera-arrayassociatedacceleratorview-data-member"></a><a name="array__associated_accelerator_view_data_member"></a>  array:: associated_accelerator_view membro de dados  
 Obtém a segunda [accelerator_view](../Topic/accelerator_view%20Class.md) objeto passado como um parâmetro quando um construtor de preparo é chamado para instanciar o [matriz](../../../parallel/amp/reference/array-class.md) objeto.  
  
```  
__declspec(property(get= get_associated_accelerator_view)) Concurrency::accelerator_view associated_accelerator_view;  
```  
  
##  <a name="a-namearraycopytomethoda-arraycopyto-method"></a><a name="array__copy_to_method"></a>  Método Array:: copy_to  
 Copia o conteúdo da [matriz](../../../parallel/amp/reference/array-class.md) para outro `array`.  
  
```  
void copy_to(
    array<value_type, _Rank>& _Dest) const ;  
 
void copy_to(
    array_view<value_type, _Rank>& _Dest) const ;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Dest`  
 O [array_view](../../../parallel/amp/reference/array-view-class.md) objeto para copiar.  
  
##  <a name="a-namearraycpuaccesstypedatamembera-arraycpuaccesstype-data-member"></a><a name="array__cpu_access_type_data_member"></a>  array:: cpu_access_type membro de dados  
 Obtém o access_type CPU permitidos para essa matriz.  
  
```  
__declspec(property(get= get_cpu_access_type)) access_type cpu_access_type;  
```  
  
##  <a name="a-namearraydatamethoda-arraydata-method"></a><a name="array__data_method"></a>  Método Array:: data  
 Retorna um ponteiro para os dados brutos da [matriz](../../../parallel/amp/reference/array-class.md).  
  
```  
value_type* data() restrict(amp,
    cpu);

 
const value_type* data() const restrict(amp,
    cpu);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para os dados brutos da matriz.  
  
##  <a name="a-namearrayextentdatamembera-arrayextent-data-member"></a><a name="array__extent_data_member"></a>  array:: Extent membro de dados  
 Obtém o [extensão](../Topic/extent%20Class%20\(C++%20AMP\).md) que define a forma do objeto de [matriz](../../../parallel/amp/reference/array-class.md).  
  
```  
__declspec(property(get= get_extent)) Concurrency::extent<_Rank> extent;  
```  
  
##  <a name="a-namearraygetacceleratorviewmethoda-arraygetacceleratorview-method"></a><a name="array__get_accelerator_view_method"></a>  Método Array:: get_accelerator_view  
 Retorna o [accelerator_view](../Topic/accelerator_view%20Class.md) objeto que representa o local onde o [matriz](../../../parallel/amp/reference/array-class.md) objeto é alocado. Essa propriedade pode ser acessada apenas na CPU.  
  
```  
Concurrency::accelerator_view get_accelerator_view() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 O `accelerator_view` objeto que representa o local onde o [matriz](../../../parallel/amp/reference/array-class.md) objeto é alocado.  
  
##  <a name="a-namearraygetassociatedacceleratorviewmethoda-arraygetassociatedacceleratorview-method"></a><a name="array__get_associated_accelerator_view_method"></a>  Método Array:: get_associated_accelerator_view  
 Obtém a segunda [accelerator_view](../Topic/accelerator_view%20Class.md) objeto passado como um parâmetro quando um construtor de preparo é chamado para instanciar o [matriz](../../../parallel/amp/reference/array-class.md) objeto.  
  
```  
Concurrency::accelerator_view get_associated_accelerator_view() const ;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A segunda [accelerator_view](../Topic/accelerator_view%20Class.md) objeto passado para o construtor de preparo.  
  
##  <a name="a-namearraygetcpuaccesstypemethoda-arraygetcpuaccesstype-method"></a><a name="array__get_cpu_access_type_method"></a>  Método Array:: get_cpu_access_type  
 Retorna o access_type de CPU que é permitido para essa matriz.  
  
```  
access_type get_cpu_access_type() const restrict(cpu);
```  
  
### <a name="return-value"></a>Valor de retorno  
  
##  <a name="a-namearraygetextentmethoda-arraygetextent-method"></a><a name="array__get_extent_method"></a>  Método Array:: get_extent  
 Retorna o [extensão](../Topic/extent%20Class%20\(C++%20AMP\).md) objeto o [matriz](../../../parallel/amp/reference/array-class.md).  
  
```  
Concurrency::extent<_Rank> get_extent() const restrict(amp,cpu);
```  
  
### <a name="return-value"></a>Valor de retorno  
 O `extent` objeto o [matriz](../../../parallel/amp/reference/array-class.md).  
  
##  <a name="a-namearrayoperatorstdvectorltvaluetypegtoperatora-arrayoperator-stdvectorltvaluetypegt-operator"></a><a name="array__operator_std__vector_lt__value_type_gt__operator"></a>  array:: Operator std:: Vector&lt;value_type&gt; operador  
 Usa `copy(*this, vector)` para converter implicitamente a matriz a um objeto std:: Vector.  
  
' ' operador std:: Vector \< value_type > () const Restrict (CPU);
```  
  
### Parameters  
 `value_type`  
 The data type of the elements of the vector.  
  
### Return Value  
 An object of type `vector<T>` that contains a copy of the data that is contained in the array.  
  
##  <a name="array__operator___operator"></a>  array::operator() Operator  
 Returns the element value that is specified by the parameters.  
  
```  
value_type & Operator () (índice const \< _Rank > & index) restrict(amp,cpu);

 
Const value_type & Operator () (índice const \< _Rank > & index) const restrict(amp,cpu);

 
value_type & restrict(amp,cpu) Operator () (_I0 int, int _I1);

 
Const value_type & restrict(amp,cpu) const Operator () (_I0 int, int _I1);

 
value_type & restrict(amp,cpu) Operator () (int _I0, _I1 int, int _I2);

 
Const value_type & restrict(amp,cpu) const Operator () (int _I0, _I1 int, int _I2);

 
TypeName details::_Projection_result_type \< value_type, _Rank >:: _Result_type Operator () (int i) restrict(amp,cpu);

 
TypeName details::_Projection_result_type \< value_type, _Rank >:: restrict(amp,cpu) const do _Const_result_type Operator () (int i);
```  
  
### Parameters  
 `_Index`  
 The location of the element.  
  
 `_I0`  
 The most significant component of the origin of this section.  
  
 `_I1`  
 The next-to-most-significant component of the origin of this section.  
  
 `_I2`  
 The least significant component of the origin of this section.  
  
 `_I`  
 The location of the element.  
  
### Return Value  
 The element value specified by the parameters.  
  
##  <a name="array__operator_at_operator"></a>  array::operator[] Operator  
 Returns the element that is at the specified index.  
  
```  
[] value_type & operador (índice const \< _Rank > & index) restrict(amp,cpu);

 
[] de operador & value_type const (const index \< _Rank > & index) const restrict(amp,cpu);

 
TypeName details::_Projection_result_type \< value_type, _Rank >:: operador _Result_type[](int _I) restrict(amp,cpu);

 
TypeName details::_Projection_result_type \< value_type, _Rank >:: operador _Const_result_type[](int _I) restrict(amp,cpu) const;
```  
  
### Parameters  
 `_Index`  
 The index.  
  
 `_I`  
 The index.  
  
### Return Value  
 The element that is at the specified index.  
  
##  <a name="array__operator_eq_operator"></a>  array::operator= Operator  
 Copies the contents of the specified [array](../../../parallel/amp/reference/array-class.md) object.  
  
```  
operador & matriz = (matriz const & _Other) Restrict (CPU);

 
operador & matriz = (matriz & & _Other) Restrict (CPU);

 
operador & matriz = (const array_view \< value_type const, _Rank > & _Src) Restrict (CPU);
```  
  
### Parameters  
 `_Other`  
 The `array` object to copy from.  
  
 `_Src`  
 The `array` object to copy from.  
  
### Return Value  
 A reference to this `array` object.  
  
##  <a name="array__rank_constant"></a>  array::rank Constant  
 Stores the rank of the [array](../../../parallel/amp/reference/array-class.md).  
  
```  
estático classificação int const = _Rank;  
```  
  
##  <a name="array__section_method"></a>  array::section Method  
 Returns a subsection of the [array](../../../parallel/amp/reference/array-class.md) object that is at the specified origin and, optionally, that has the specified extent.  
  
```  
array_view \< value_type, _Rank > seção (const Concurrency::index \< _Rank > & _Section_origin,  
    Const Concurrency::extent \< _Rank > & _Section_extent) restrict(amp,cpu);

 
array_view \< value_type const, _Rank > seção (const Concurrency::index \< _Rank > & _Section_origin,  
    Const Concurrency::extent \< _Rank > & _Section_extent) restrict(amp,cpu) const;

 
array_view \< value_type, _Rank > seção (const Concurrency::extent \< _Rank > & _Ext) restrict(amp,cpu);

 
array_view \< value_type const, _Rank > seção (const Concurrency::extent \< _Rank > & _Ext) restrict(amp,cpu) const;

 
array_view \< value_type, _Rank > seção (const index \< _Rank > & idx) restrict(amp,cpu);

 
array_view \< value_type const, _Rank > seção (índice const \< _Rank > & idx) const restrict(amp,cpu);

 
array_view \< value_type, 1 > seção (int _I0,  
    restrict(amp,cpu) _E0 int);

 
array_view \< value_type const, 1 > seção (int _I0,  
    restrict(amp,cpu) const int _E0);

 
array_view \< value_type, 2 > seção (int _I0,  
    int _I1,  
    int _E0,  
    restrict(amp,cpu) _E1 int);

 
array_view \< value_type const, 2 > seção (int _I0,  
    int _I1,  
    int _E0,  
    restrict(amp,cpu) const int _E1);

 
array_view \< value_type, 3 > seção (int _I0,  
    int _I1,  
    int _I2,  
    int _E0,  
    int _E1,  
    restrict(amp,cpu) _E2 int);

 
array_view \< value_type const, 3 > seção (int _I0,  
    int _I1,  
    int _I2,  
    int _E0,  
    int _E1,  
    restrict(amp,cpu) const int _E2);
```  
  
### Parameters  
 `_E0`  
 The most significant component of the extent of this section.  
  
 `_E1`  
 The next-to-most-significant component of the extent of this section.  
  
 `_E2`  
 The least significant component of the extent of this section.  
  
 `_Ext`  
 The [extent](../Topic/extent%20Class%20\(C++%20AMP\).md) object that specifies the extent of the section. The origin is 0.  
  
 `_Idx`  
 The [index](../../../parallel/amp/reference/index-class.md) object that specifies the location of the origin. The subsection is the rest of the extent.  
  
 `_I0`  
 The most significant component of the origin of this section.  
  
 `_I1`  
 The next-to-most-significant component of the origin of this section.  
  
 `_I2`  
 The least significant component of the origin of this section.  
  
 `_Rank`  
 The rank of the section.  
  
 `_Section_extent`  
 The [extent](../Topic/extent%20Class%20\(C++%20AMP\).md) object that specifies the extent of the section.  
  
 `_Section_origin`  
 The [index](../../../parallel/amp/reference/index-class.md) object that specifies the location of the origin.  
  
 `value_type`  
 The data type of the elements that are copied.  
  
### Return Value  
 Returns a subsection of the `array` object that is at the specified origin and, optionally, that has the specified extent. When only the `index` object is specified, the subsection contains all elements in the associated grid that have indexes that are larger than the indexes of the elements in the `index` object.  
  
##  <a name="array__view_as_method"></a>  array::view_as Method  
 Reinterprets this array as an [array_view](../../../parallel/amp/reference/array-view-class.md) of a different rank.  
  
```  
modelo \< int _New_rank  
>  
view_as array_view \< value_type, _New_rank > (const Concurrency::extent \< _New_rank > & _View_extent) restrict(amp,cpu);

 
modelo \< int _New_rank  
>  
array_view \< value_type const, _New_rank > view_as (const Concurrency::extent \< _New_rank > & _View_extent) restrict(amp,cpu) const;
```  
  
### Parameters  
 `_New_rank`  
 The rank of the `extent` object passed as a parameter.  
  
 `_View_extent`  
 The extent that is used to construct the new [array_view](../../../parallel/amp/reference/array-view-class.md) object.  
  
 `value_type`  
 The data type of the elements in both the original [array](../../../parallel/amp/reference/array-class.md) object and the returned `array_view` object.  
  
### Return Value  
 The [array_view](../../../parallel/amp/reference/array-view-class.md) object that is constructed.  
  
## See Also  
 [Concurrency Namespace (C++ AMP)](../../../parallel/amp/reference/concurrency-namespace-cpp-amp.md)
