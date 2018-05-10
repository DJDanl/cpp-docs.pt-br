---
title: Classe array_view | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-amp
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- array_view class
ms.assetid: 7e7ec9bc-05a2-4372-b05d-752b50006c5a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2e53b4927b102fc64a32f73ca5be78e71954b45f
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
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
 `value_type`  
 O tipo de dados dos elementos de `array_view` objeto.  
  
 `_Rank`  
 A classificação do `array_view` objeto.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor de array_view](#ctor)|Inicializa uma nova instância da classe `array_view`. Não há nenhum construtor padrão para `array<T,N>`. Todos os construtores são restritos para executar na CPU apenas e não podem ser executados em um destino de Direct3D.|  
|[~ array_view destruidor](#ctor)|Destrói a `array_view` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[copy_to](#copy_to)|Copia o conteúdo do `array_view` objeto para o destino especificado chamando `copy(*this, dest)`.|  
|[data](#data)|Retorna um ponteiro para os dados brutos do `array_view`.|  
|[discard_data](#discard_data)|Descarta os dados atuais subjacentes nessa exibição.|  
|[get_extent](#get_extent)|Retorna o objeto de extensão do objeto array_view.|  
|[get_ref](#get_ref)|Retorna uma referência ao elemento indexada.|  
|[get_source_accelerator_view](#get_source_accelerator_view)|Retorna o [accelerator_view](accelerator-view-class.md) onde a fonte de dados do `array_view` está localizado.|  
|[Atualização](#refresh)|Notifica o `array_view` objeto sua memória associada foi modificada fora do `array_view` interface. Uma chamada para este método processa todas as informações armazenadas em cache obsoleto.|  
|[reinterpret_as](#reinterpret_as)|Retorna uma matriz unidimensional que contém todos os elementos de `array_view` objeto.|  
|[seção](#section)|Retorna a subseção do `array_view` objeto que é a origem especificada e, opcionalmente, que tem a extensão especificada.|  
|[synchronize](#synchronize)|Sincroniza todas as modificações feitas para o `array_view` objeto para seus dados de origem.|  
|[synchronize_async](#synchronize_async)|Assincronamente sincroniza todas as modificações feitas para o `array_view` objeto para seus dados de origem.|  
|[synchronize_to](#synchronize_to)|Sincroniza todas as modificações feitas para o `array_view` objeto especificado [accelerator_view](accelerator-view-class.md).|  
|[synchronize_to_async](#synchronize_to_async)|Assincronamente sincroniza todas as modificações feitas para o `array_view` objeto especificado [accelerator_view](accelerator-view-class.md).|  
|[view_as](#view_as)|Produz um `array_view` o objeto de uma posição diferente usando esse `array_view` dados do objeto.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operator()](#operator_call)|Retorna o valor do elemento que é especificado pelo parâmetro ou parâmetros.|  
|[operator[]](#operator_at)|Retorna o elemento que é especificado pelos parâmetros.|  
|[operator=](#operator_eq)|Copia o conteúdo de especificado `array_view` deste objeto.|  
  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Constante de classificação](#rank)|Armazena a classificação do `array_view` objeto.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[extent](#extent)|Obtém o `extent` que define a forma do objeto de `array_view` objeto.|  
|[source_accelerator_view](#source_accelerator_view)|Obtém o [accelerator_view](accelerator-view-class.md) onde a fonte de dados do `array_view` está localizado|  
|[value_type](#value_type)|O tipo de valor de `array_view` e a matriz associada.|  
  
## <a name="remarks"></a>Comentários  
 O `array_view` classe representa uma exibição dos dados contidos em um [matriz](array-class.md) objeto ou uma subseção de um `array` objeto.  
  
 Você pode acessar o `array_view` onde os dados de origem estão localizados (local) ou em um acelerador de diferente ou em um domínio de coerência de objeto (remotamente). Quando você acessa o objeto remotamente, modos de exibição são copiados e armazenados em cache conforme necessário. Exceto para os efeitos de cache automático, `array_view` objetos têm um perfil de desempenho semelhante do `array` objetos. Há uma penalidade de desempenho pequeno quando você acessa os dados por meio de exibições.  
  
 Há três cenários de uso remoto:  
  
-   Um modo de exibição para um ponteiro de memória do sistema é passado por meio de um [parallel_for_each](../../../parallel/concrt/reference/concurrency-namespace-functions.md#parallel_for_each) chamar um acelerador e acessados no acelerador.  
  
-   Um modo de exibição para uma matriz localizado em um acelerador é passado por meio de um `parallel_for_each` chamar outro accelerator e é acessada existe.  
  
-   Um modo de exibição para uma matriz localizado em um acelerador é acessado na CPU.  
  
 Em qualquer um desses cenários, os modos de exibição referenciados são copiados pelo tempo de execução ao local remoto e, se modificada por chamadas para o `array_view` de objeto, são copiados para o local. O tempo de execução pode otimizar o processo de copiar alterações de volta, pode copiar somente os elementos alterados ou também pode copiar partes inalteradas. Sobreposição de `array_view` não há garantia de objetos em uma fonte de dados para manter a integridade referencial em um local remoto.  
  
 Você deve sincronizar qualquer acesso multithread a mesma fonte de dados.  
  
 O tempo de execução garante o seguinte sobre o cache de dados em `array_view` objetos:  
  
-   Todos os acessos bem sincronizados a um `array` objeto e um `array_view` objeto na ordem de programa obedece a uma série acontece-antes de relação.  
  
-   Todos os acessos bem sincronizados a sobreposição `array_view` objetos do mesmo Accelerator em um único `array` objeto forem aliases por meio de `array` objeto. Eles induzem um total ocorre-antes de relação que obedeça a ordem de programa. Não há nenhum cache. Se o `array_view` objetos estão em execução no aceleradores diferentes, a ordem de acesso é indefinida, a criação de uma condição de corrida.  
  
 Quando você cria um `array_view` objeto usando um ponteiro na memória do sistema, você deve alterar o modo de exibição `array_view` somente por meio do objeto de `array_view` ponteiro. Como alternativa, você deve chamar `refresh()` em um do `array_view` objetos que estão anexados ao ponteiro do sistema, se a memória nativa subjacente for alterada diretamente, em vez de por meio de `array_view` objeto.  
  
 Qualquer ação notifica o `array_view` do objeto que é alterada, a memória nativa subjacente e que quaisquer cópias que estão localizadas em um acelerador estão desatualizadas. Se você seguir essas diretrizes, os modos de exibição baseada em ponteiro são idênticos àquelas fornecidas para modos de exibição de conjuntos de dados paralelo.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `_Array_view_shape`  
  
 `_Array_view_base`  
  
 `array_view`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp.h  
  
 **Namespace:** Simultaneidade  
  
##  <a name="dtor"></a> ~ array_view 

 Destrói a `array_view` objeto.  
  
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
 `_Arr_type`  
 O tipo de elemento de uma matriz C-style do qual os dados são fornecidos.  
  
 `_Container`  
 Um argumento de modelo que deve especificar um contêiner linear que dá suporte a `data()` e `size()` membros.  
  
 `_E0`  
 O fator mais significativo da extensão desta seção.  
  
 `_E1`  
 O componente Avançar-para-mais significativo da extensão desta seção.  
  
 `_E2`  
 O componente menos significativo de extensão desta seção.  
  
 `_Extent`  
 A extensão em cada dimensão deste `array_view`.  
  
 `_Other`  
 Um objeto do tipo `array_view<T,N>` do qual inicializar a nova `array_view`.  
  
 `_Size`  
 O tamanho de uma matriz de estilo C do qual os dados são fornecidos.  
  
 `_Src`  
 Um ponteiro para os dados de origem que serão copiados para a nova matriz.  
  
##  <a name="copy_to"></a> copy_to 

 Copia o conteúdo do `array_view` objeto para o objeto de destino especificado chamando `copy(*this, dest)`.  
  
```  
void copy_to(
    array<value_type, _Rank>& _Dest) const;

 
 
void copy_to(
    array_view<value_type, _Rank>& _Dest) const;

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Dest`  
 O objeto a ser copiado para.  
  
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

 Descarta os dados atuais subjacentes nessa exibição. Isso é uma dica de otimização para o tempo de execução usado para evitar a copiar o conteúdo atual da exibição para um destino `accelerator_view` que ele é acessado no, e seu uso é recomendado se o conteúdo existente não é necessária. Esse método é não operacional quando usada em um contexto de restrict(amp)  
  
```  
void discard_data() const restrict(cpu);
```  
  
##  <a name="extent"></a> extensão 

 Obtém o `extent` que define a forma do objeto de `array_view` objeto.  
  
```  
__declspec(property(get= get_extent)) Concurrency::extent<_Rank> extent;  
```  
  
##  <a name="get_extent"></a> get_extent 

 Retorna o [extensão](extent-class.md) objeto o `array_view` objeto.  
  
```  
Concurrency::extent<_Rank> get_extent() const restrict(cpu, amp);
```  
  
### <a name="return-value"></a>Valor de retorno  
 O `extent` objeto o `array_view` objeto  
  
##  <a name="get_ref"></a> get_ref 

 Obter uma referência ao elemento indexado por index. Ao contrário de outros operadores de indexação para acessar o array_view na CPU, esse método não implicitamente sincronizar o conteúdo deste array_view à CPU. Depois de acessar o array_view em um local remoto ou executar uma operação de cópia que envolvem essa array_view usuários serão responsáveis por sincronizar explicitamente array_view à CPU antes de chamar esse método. Falha ao fazer isso resulta em um comportamento indefinido.  
  
```  
value_type& get_ref(
    const index<_Rank>& _Index) const restrict(amp, cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Index`  
 O índice.  
  
### <a name="return-value"></a>Valor de retorno  
 Referência ao elemento indexado por index  
  
##  <a name="get_source_accelerator_view"></a> get_source_accelerator_view 

 Retorna o accelerator_view onde a fonte de dados do array_view está localizada. Se o array_view não tem uma fonte de dados, essa API lança um runtime_exception  
  
```  
accelerator_view get_source_accelerator_view() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
  
##  <a name="operator_call"></a> Operator) 

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
 `_Index`  
 O local do elemento.  
  
 `_I0`  
 O índice na primeira dimensão.  
  
 `_I1`  
 O índice na segunda dimensão.  
  
 `_I2`  
 O índice na terceira dimensão.  
  
 `_I`  
 O local do elemento.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor do elemento que é especificado pelo parâmetro ou parâmetros.  
  
##  <a name="operator_at"></a> operador] 

 Retorna o elemento que é especificado pelos parâmetros.  
  
```  
typename details::_Projection_result_type<value_type,_Rank>::_Const_result_type operator[] (
    int _I) const restrict(amp,cpu);

 
value_type& operator[] (
    const index<_Rank>& _Index) const restrict(amp,cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Index`  
 O índice.  
  
 `_I`  
 O índice.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor do elemento no índice, ou um `array_view` projetada na dimensão mais significativo.  
  
##  <a name="operator_eq"></a> operador = 

 Copia o conteúdo de especificado `array_view` deste objeto.  
  
```  
array_view& operator= (
    const array_view& _Other) restrict(amp,cpu);

 
array_view& operator= (
    const array_view<value_type, _Rank>& _Other) restrict(amp,cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `array_view` objeto do qual copiar.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a este `array_view` objeto.  
  
##  <a name="rank"></a> Classificação 

 Armazena a classificação do `array_view` objeto.  
  
```  
static const int rank = _Rank;  
```  
  
##  <a name="refresh"></a> Atualização 

 Notifica o `array_view` objeto sua memória associada foi modificada fora do `array_view` interface. Uma chamada para este método processa todas as informações armazenadas em cache obsoleto.  
  
```  
void refresh() const restrict(cpu);
```  
## <a name="reinterpret_as"></a> reinterpret_as 

Reinterprets array_view por meio de um array_view unidimensional, que pode ter um tipo de valor diferente de array_view de origem como uma opção.  
  
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
 `_Value_type2`  
 O tipo de dados do novo `array_view` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `array_view` objeto ou const `array_view` objeto baseado neste `array_view`, com o tipo de elemento convertido de `T` para `_Value_type2`, e a classificação é reduzido de *N* como 1.  
  
### <a name="remarks"></a>Comentários  
 Às vezes, é conveniente exibir uma matriz multidimensional como uma matriz unidimensional, linear, que pode ter um tipo de valor diferente que a matriz de origem. Você pode fazer isso em um `array_view` usando esse método.  
  
**Aviso** Reinterpeting um objeto array_view usando um tipo de valor diferente é uma operação potencialmente não segura. Essa funcionalidade deve ser usada com cuidado.  
  
 Veja um exemplo:  
  
```cpp  
struct RGB { float r; float g; float b; };  
  
array<RGB,3>  a = ...;   
array_view<float,1> v = a.reinterpret_as<float>();   
  
assert(v.extent == 3*a.extent);  
```  
    
##  <a name="section"></a> Seção 

 Retorna a subseção do `array_view` objeto que é a origem especificada e, opcionalmente, que tem a extensão especificada.  
  
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
 `_E0`  
 O fator mais significativo da extensão desta seção.  
  
 `_E1`  
 O componente Avançar-para-mais significativo da extensão desta seção.  
  
 `_E2`  
 O componente menos significativo de extensão desta seção.  
  
 `_Ext`  
 O [extensão](extent-class.md) objeto que especifica a extensão da seção. A origem é 0.  
  
 `_Idx`  
 O [índice](index-class.md) objeto que especifica o local da origem. A subseção é o restante da extensão.  
  
 `_I0`  
 O fator mais significativo da origem desta seção.  
  
 `_I1`  
 O componente Avançar-para-mais significativo da origem desta seção.  
  
 `_I2`  
 O componente menos significativo de origem desta seção.  
  
 `_Rank`  
 A classificação da seção.  
  
 `_Section_extent`  
 O [extensão](extent-class.md) objeto que especifica a extensão da seção.  
  
 `_Section_origin`  
 O [índice](index-class.md) objeto que especifica o local da origem.  
  
### <a name="return-value"></a>Valor de retorno  
 A subseção do `array_view` objeto que é a origem especificada e, opcionalmente, que tem a extensão especificada. Quando apenas o `index` objeto for especificado, a subseção contém todos os elementos na extensão associado que têm índices que são maiores do que os índices dos elementos a `index` objeto.  
  
##  <a name="source_accelerator_view"></a> source_accelerator_view 

 Obtém a fonte accelerator_view este array_view associado.  
  
```  
__declspec(property(get= get_source_accelerator_view)) accelerator_view source_accelerator_view;  
```  
  
##  <a name="synchronize"></a> Sincronizar 

 Sincroniza todas as modificações feitas para o `array_view` objeto para seus dados de origem.  
  
```  
void synchronize(access_type _Access_type = access_type_read) const restrict(cpu);

 
void synchronize() const restrict(cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Access_type`  
 O pretendido [access_type](concurrency-namespace-enums-amp.md#access_type) no destino [accelerator_view](accelerator-view-class.md). Esse parâmetro tem um valor padrão de `access_type_read`.  
  
##  <a name="synchronize_async"></a> synchronize_async 

 Assincronamente sincroniza todas as modificações feitas para o `array_view` objeto para seus dados de origem.  
  
```  
concurrency::completion_future synchronize_async(access_type _Access_type = access_type_read) const restrict(cpu);

 
concurrency::completion_future synchronize_async() const restrict(cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Access_type`  
 O pretendido [access_type](concurrency-namespace-enums-amp.md#access_type) no destino [accelerator_view](accelerator-view-class.md). Esse parâmetro tem um valor padrão de `access_type_read`.  
  
### <a name="return-value"></a>Valor de retorno  
 Um futuro no qual aguardar a conclusão da operação.  
  
##  <a name="synchronize_to"></a> synchronize_to 

 Sincroniza todas as modificações feitas para este array_view para o accelerator_view especificado.  
  
```  
void synchronize_to(
    const accelerator_view& _Accl_view,  
    access_type _Access_type = access_type_read) const restrict(cpu);

 
void synchronize_to(
    const accelerator_view& _Accl_view) const restrict(cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Accl_view`  
 O accelerator_view de destino para sincronizar.  
  
 `_Access_type`  
 O access_type desejado no accelerator_view destino. Esse parâmetro tem um valor padrão de access_type_read.  
  
##  <a name="synchronize_to_async"></a> synchronize_to_async 

 Assincronamente sincroniza todas as modificações feitas para este array_view para o accelerator_view especificado.  
  
```  
concurrency::completion_future synchronize_to_async(
    const accelerator_view& _Accl_view,  
    access_type _Access_type = access_type_read) const restrict(cpu);

 
concurrency::completion_future synchronize_to_async(
    const accelerator_view& _Accl_view) const restrict(cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Accl_view`  
 O accelerator_view de destino para sincronizar.  
  
 `_Access_type`  
 O access_type desejado no accelerator_view destino. Esse parâmetro tem um valor padrão de access_type_read.  
  
### <a name="return-value"></a>Valor de retorno  
 Um futuro no qual aguardar a conclusão da operação.  
  
##  <a name="value_type"></a> value_type 

 O tipo de valor da array_view e a matriz associada.  
  
```  
typedef typenamevalue_type value_type;  
```  
  
##  <a name="view_as"></a> view_as 

 Reinterprets isso `array_view` como um `array_view` de uma posição diferente.  
  
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
 `_New_rank`  
 A classificação do novo `array_view` objeto.  
  
 `_View_extent`  
 A reformulação das `extent`.  
  
 `value_type`  
 O tipo de dados dos elementos no original [matriz](array-class.md) objeto e retornado `array_view` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 O `array_view` objeto que é construído.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
