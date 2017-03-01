---
title: Classe array_view | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- amp/Concurrency::array_view
dev_langs:
- C++
helpviewer_keywords:
- array_view class
ms.assetid: 7e7ec9bc-05a2-4372-b05d-752b50006c5a
caps.latest.revision: 21
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
ms.openlocfilehash: ec096dbcd485b9360d07d1b56511b13c13d1b4cf
ms.lasthandoff: 02/25/2017

---
# <a name="arrayview-class"></a>Classe array_view
Representa uma exibição N-dimensional sobre os dados mantidos em outro contêiner.  
  
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
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor array_view](#ctor)|Inicializa uma nova instância da classe `array_view`. Não há nenhum construtor padrão para `array<T,N>`. Todos os construtores são restritos para ser executado na CPU apenas e não podem ser executados em um destino do Direct3D.|  
|[~ array_view destruidor](#ctor)|Destrói o `array_view` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método copy_to](#copy_to)|Copia o conteúdo da `array_view` objeto para o destino especificado chamando `copy(*this, dest)`.|  
|[Método de dados](#data)|Retorna um ponteiro para os dados brutos do `array_view`.|  
|[Método discard_data](#discard_data)|Descarta os dados atuais subjacentes nessa exibição.|  
|[Método get_extent](#get_extent)|Retorna o objeto de extensão do objeto array_view.|  
|[Método get_ref](#get_ref)|Retorna uma referência ao elemento indexado.|  
|[Método get_source_accelerator_view](#get_source_accelerator_view)|Retorna o [accelerator_view](accelerator-view-class.md) onde a fonte de dados do `array_view` está localizado.|  
|[Método Refresh](#refresh)|Notifica o `array_view` objeto sua memória associada foi modificada fora do `array_view` interface. Uma chamada para esse método processa todas as informações armazenadas em cache obsoletos.|  
|[Método reinterpret_as](#reinterpret_as)|Retorna uma matriz unidimensional que contém todos os elementos de `array_view` objeto.|  
|[seção método](#section)|Retorna uma subseção de `array_view` objeto que é a origem especificada e, opcionalmente, que tem a extensão especificada.|  
|[Método Synchronize](#synchronize)|Sincroniza as modificações feitas a `array_view` objeto para sua fonte de dados.|  
|[Método synchronize_async](#synchronize_async)|Sincroniza assincronamente quaisquer modificações feitas a `array_view` objeto para sua fonte de dados.|  
|[Método synchronize_to](#synchronize_to)|Sincroniza as modificações feitas a `array_view` o objeto especificado [accelerator_view](accelerator-view-class.md).|  
|[Método synchronize_to_async](#synchronize_to_async)|Sincroniza assincronamente quaisquer modificações feitas a `array_view` o objeto especificado [accelerator_view](accelerator-view-class.md).|  
|[Método view_as](#view_as)|Produz uma `array_view` o objeto de uma posição diferente usando este `array_view` dados do objeto.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Operador Operator)](#operator_call)|Retorna o valor do elemento que é especificado pelo parâmetro ou parâmetros.|  
|[Operador do operador]](#operator_at)|Retorna o elemento especificado pelos parâmetros.|  
|[operador Operator =](#operator_eq)|Copia o conteúdo especificado `array_view` deste objeto.|  
  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Constante Rank](#rank)|Armazena a classificação do `array_view` objeto.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados de extensão](#extent)|Obtém o `extent` que define a forma do objeto de `array_view` objeto.|  
|[Membro de dados source_accelerator_view](#source_accelerator_view)|Obtém o [accelerator_view](accelerator-view-class.md) onde a fonte de dados do `array_view` está localizado|  
|[Membro de dados value_type](#value_type)|O tipo de valor de `array_view` e a matriz associada.|  
  
## <a name="remarks"></a>Comentários  
 O `array_view` classe representa uma exibição dos dados contidos em uma [matriz](array-class.md) objeto ou uma subseção de um `array` objeto.  
  
 Você pode acessar o `array_view` onde os dados de origem estão localizados (local) ou em um acelerador diferente ou um domínio de coerência do objeto (remotamente). Quando você acessa o objeto remotamente, modos de exibição são copiados e armazenados em cache conforme necessário. Exceto para os efeitos de cache automático, `array_view` objetos têm um perfil de desempenho semelhante do `array` objetos. Há uma penalidade de desempenho pequeno quando você acessa os dados por meio de exibições.  
  
 Há três cenários de uso remoto:  
  
-   Um modo de exibição para um ponteiro de memória do sistema é transmitido por meio de um [parallel_for_each](../../../parallel/concrt/reference/concurrency-namespace-functions.md#parallel_for_each) chamar um acelerador e acessados do Accelerator.  
  
-   Um modo de exibição para uma matriz localizado em um acelerador é transmitido por meio de um `parallel_for_each` chamar outro accelerator e é acessado lá.  
  
-   Um modo de exibição para uma matriz localizado em um acelerador é acessado na CPU.  
  
 Em qualquer um desses cenários, os modos de exibição referenciados são copiados pelo tempo de execução para o local remoto e, se modificado por chamadas para o `array_view` de objeto, são copiados para o local. O tempo de execução pode otimizar o processo de copiar as alterações de volta, pode copiar somente os elementos alterados ou pode copiar partes inalterados também. Sobreposição de `array_view` objetos em uma fonte de dados não são garantidos para manter a integridade referencial em um local remoto.  
  
 Você deve sincronizar qualquer multithread acessem a mesma fonte de dados.  
  
 O tempo de execução faz as seguintes garantias sobre o cache de dados em `array_view` objetos:  
  
-   Todos os acessos bem sincronizados para um `array` objeto e um `array_view` objeto na ordem do programa obedecem serial acontece-antes de relação.  
  
-   Todos os acessos bem sincronizados a sobreposição `array_view` objetos do Accelerator mesmo em um único `array` objeto tenha sido efetuado alias por meio de `array` objeto. Eles induzem um total ocorre-antes de relação que obedeça a ordem de programa. Não há nenhum cache. Se o `array_view` objetos estão em execução em diferentes aceleradores, a ordem de acesso é indefinida, criando uma condição de corrida.  
  
 Quando você cria um `array_view` objeto usando um ponteiro na memória do sistema, você deve alterar o modo de exibição `array_view` somente por meio do objeto de `array_view` ponteiro. Como alternativa, você deve chamar `refresh()` em um do `array_view` objetos que estão anexados ao ponteiro do sistema, se a memória nativa subjacente for alterada diretamente, em vez de por meio de `array_view` objeto.  
  
 Qualquer ação notifica o `array_view` do objeto que a memória nativa subjacente é alterada e que quaisquer cópias que estão localizadas em um acelerador estão desatualizadas. Se você seguir essas diretrizes, os modos de exibição baseada em ponteiro são idênticos àquelas fornecidas para modos de exibição de conjuntos de dados paralela.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `_Array_view_shape`  
  
 `_Array_view_base`  
  
 `array_view`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp.h  
  
 **Namespace:** Simultaneidade  
  
##  <a name="a-namedtora-arrayview"></a><a name="dtor"></a>~ array_view 

 Destrói o `array_view` objeto.  
  
```  
~array_view()restrict(amp,cpu);
```  
  
##  <a name="a-namectora-arrayview"></a><a name="ctor"></a>array_view 

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
 O tipo de elemento de uma matriz de estilo C do qual os dados são fornecidos.  
  
 `_Container`  
 Um argumento de modelo que deve especificar um contêiner linear que oferece suporte a `data()` e `size()` membros.  
  
 `_E0`  
 O fator mais significativo da extensão desta seção.  
  
 `_E1`  
 O componente Avançar-para-mais significativo da extensão desta seção.  
  
 `_E2`  
 O componente menos significativo da extensão desta seção.  
  
 `_Extent`  
 A extensão em cada dimensão isso `array_view`.  
  
 `_Other`  
 Um objeto do tipo `array_view<T,N>` da qual inicializar o novo `array_view`.  
  
 `_Size`  
 O tamanho de uma matriz de estilo C do qual os dados são fornecidos.  
  
 `_Src`  
 Um ponteiro para os dados de origem que serão copiados para a nova matriz.  
  
##  <a name="a-namecopytoa-copyto"></a><a name="copy_to"></a>copy_to 

 Copia o conteúdo da `array_view` objeto para o objeto de destino especificado chamando `copy(*this, dest)`.  
  
```  
void copy_to(
    array<value_type, _Rank>& _Dest) const;

 
 
void copy_to(
    array_view<value_type, _Rank>& _Dest) const;

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Dest`  
 O objeto para copiar.  
  
##  <a name="a-namedataa-data"></a><a name="data"></a>dados 

 Retorna um ponteiro para os dados brutos do `array_view`.  
  
```  
value_type* data() const restrict(amp,
    cpu);

 
const value_type* data() const restrict(amp,
    cpu);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para os dados brutos do `array_view`.  
  
##  <a name="a-namediscarddataa-discarddata"></a><a name="discard_data"></a>discard_data 

 Descarta os dados atuais subjacentes nessa exibição. Isso é uma dica de otimização no tempo de execução usada para evitar copiar o conteúdo atual do modo de exibição para um destino `accelerator_view` que ele é acessado no e seu uso é recomendado se o conteúdo existente não é necessária. Esse método é no-op quando usados em um contexto de Restrict (amp)  
  
```  
void discard_data() const restrict(cpu);
```  
  
##  <a name="a-nameextenta-extent"></a><a name="extent"></a>extensão 

 Obtém o `extent` que define a forma do objeto de `array_view` objeto.  
  
```  
__declspec(property(get= get_extent)) Concurrency::extent<_Rank> extent;  
```  
  
##  <a name="a-namegetextenta-getextent"></a><a name="get_extent"></a>get_extent 

 Retorna o [extensão](extent-class.md) objeto o `array_view` objeto.  
  
```  
Concurrency::extent<_Rank> get_extent() const restrict(cpu, amp);
```  
  
### <a name="return-value"></a>Valor de retorno  
 O `extent` objeto o `array_view` objeto  
  
##  <a name="a-namegetrefa-getref"></a><a name="get_ref"></a>get_ref 

 Obtenha uma referência ao elemento indexado por index. Ao contrário de outros operadores de indexação para acessar o array_view na CPU, esse método não sincroniza implicitamente o conteúdo desse array_view para a CPU. Depois de acessar array_view em um local remoto ou executar uma operação de cópia que envolvem essa array_view usuários são responsáveis explicitamente sincronizar array_view à CPU antes de chamar esse método. Falha ao fazer isso resulta em um comportamento indefinido.  
  
```  
value_type& get_ref(
    const index<_Rank>& _Index) const restrict(amp, cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Index`  
 O índice.  
  
### <a name="return-value"></a>Valor de retorno  
 Referência ao elemento indexado por index  
  
##  <a name="a-namegetsourceacceleratorviewa-getsourceacceleratorview"></a><a name="get_source_accelerator_view"></a>get_source_accelerator_view 

 Retorna o accelerator_view onde a fonte de dados do array_view está localizado. Se o array_view não tem uma fonte de dados, essa API lança um runtime_exception  
  
```  
accelerator_view get_source_accelerator_view() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
  
##  <a name="a-nameoperatorcalla-operator"></a><a name="operator_call"></a>Operator) 

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
  
##  <a name="a-nameoperatorata-operator"></a><a name="operator_at"></a>operador] 

 Retorna o elemento especificado pelos parâmetros.  
  
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
 O valor do elemento no índice, ou um `array_view` projetado na dimensão mais significativo.  
  
##  <a name="a-nameoperatoreqa-operator"></a><a name="operator_eq"></a>operador = 

 Copia o conteúdo especificado `array_view` objeto a este.  
  
```  
array_view& operator= (
    const array_view& _Other) restrict(amp,cpu);

 
array_view& operator= (
    const array_view<value_type, _Rank>& _Other) restrict(amp,cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `array_view` objeto copiar de.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a esta `array_view` objeto.  
  
##  <a name="a-nameranka-rank"></a><a name="rank"></a>classificação 

 Armazena a classificação do `array_view` objeto.  
  
```  
static const int rank = _Rank;  
```  
  
##  <a name="a-namerefresha-refresh"></a><a name="refresh"></a>Atualizar 

 Notifica o `array_view` objeto sua memória associada foi modificada fora do `array_view` interface. Uma chamada para esse método processa todas as informações armazenadas em cache obsoletos.  
  
```  
void refresh() const restrict(cpu);
```  
## <a name="a-namereinterpretasa-reinterpretas"></a><a name="reinterpret_as"></a>reinterpret_as 

Reinterprets array_view por meio de um array_view unidimensional, que pode ter um tipo de valor diferente que a fonte array_view como uma opção.  
  
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
 Um `array_view` objeto ou const `array_view` objeto baseado nessa `array_view`, com o tipo de elemento convertido de `T` para `_Value_type2`, e a classificação reduzido de *N* como 1.  
  
### <a name="remarks"></a>Comentários  
 Às vezes é conveniente exibir uma matriz multidimensional como uma matriz unidimensional, linear, que pode ter um tipo de valor diferente do que a matriz de origem. Você pode fazer isso em um `array_view` usando esse método.  
  
**Aviso** Reinterpeting um objeto array_view usando um tipo de valor diferente é uma operação potencialmente não segura. Essa funcionalidade deve ser usada com cuidado.  
  
 Veja um exemplo:  
  
```cpp  
struct RGB { float r; float g; float b; };  
  
array<RGB,3>  a = ...;   
array_view<float,1> v = a.reinterpret_as<float>();   
  
assert(v.extent == 3*a.extent);  
```  
    
##  <a name="a-namesectiona-section"></a><a name="section"></a>seção 

 Retorna uma subseção de `array_view` objeto que é a origem especificada e, opcionalmente, que tem a extensão especificada.  
  
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
  
### <a name="return-value"></a>Valor de retorno  
 Uma subseção de `array_view` objeto que é a origem especificada e, opcionalmente, que tem a extensão especificada. Quando apenas o `index` objeto for especificado, a subseção contém todos os elementos na extensão associada que têm índices maiores que os índices dos elementos de `index` objeto.  
  
##  <a name="a-namesourceacceleratorviewa-sourceacceleratorview"></a><a name="source_accelerator_view"></a>source_accelerator_view 

 Obtém a fonte accelerator_view este array_view associado.  
  
```  
__declspec(property(get= get_source_accelerator_view)) accelerator_view source_accelerator_view;  
```  
  
##  <a name="a-namesynchronizea-synchronize"></a><a name="synchronize"></a>sincronizar 

 Sincroniza as modificações feitas a `array_view` objeto para sua fonte de dados.  
  
```  
void synchronize(access_type _Access_type = access_type_read) const restrict(cpu);

 
void synchronize() const restrict(cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Access_type`  
 O pretendido [access_type](concurrency-namespace-enums-amp.md#access_type) no destino [accelerator_view](accelerator-view-class.md). Esse parâmetro tem um valor padrão de `access_type_read`.  
  
##  <a name="a-namesynchronizeasynca-synchronizeasync"></a><a name="synchronize_async"></a>synchronize_async 

 Sincroniza assincronamente quaisquer modificações feitas a `array_view` objeto para sua fonte de dados.  
  
```  
concurrency::completion_future synchronize_async(access_type _Access_type = access_type_read) const restrict(cpu);

 
concurrency::completion_future synchronize_async() const restrict(cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Access_type`  
 O pretendido [access_type](concurrency-namespace-enums-amp.md#access_type) no destino [accelerator_view](accelerator-view-class.md). Esse parâmetro tem um valor padrão de `access_type_read`.  
  
### <a name="return-value"></a>Valor de retorno  
 Um futuro no qual aguardar a conclusão da operação.  
  
##  <a name="a-namesynchronizetoa-synchronizeto"></a><a name="synchronize_to"></a>synchronize_to 

 Sincroniza as modificações feitas neste array_view para o accelerator_view especificado.  
  
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
  
##  <a name="a-namesynchronizetoasynca-synchronizetoasync"></a><a name="synchronize_to_async"></a>synchronize_to_async 

 Sincroniza assincronamente quaisquer modificações feitas neste array_view para o accelerator_view especificado.  
  
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
  
##  <a name="a-namevaluetypea-valuetype"></a><a name="value_type"></a>value_type 

 O tipo de valor da array_view e a matriz associada.  
  
```  
typedef typenamevalue_type value_type;  
```  
  
##  <a name="a-nameviewasa-viewas"></a><a name="view_as"></a>view_as 

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
 A remodelagem `extent`.  
  
 `value_type`  
 O tipo de dados dos elementos no original [matriz](array-class.md) retornado e objeto `array_view` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 O `array_view` objeto que é construído.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)

