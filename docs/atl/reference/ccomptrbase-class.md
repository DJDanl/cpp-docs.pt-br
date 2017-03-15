---
title: Classe CComPtrBase | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL.CComPtrBase
- ATL::CComPtrBase<T>
- ATL.CComPtrBase<T>
- ATL::CComPtrBase
- CComPtrBase
dev_langs:
- C++
helpviewer_keywords:
- CComPtrBase class
ms.assetid: 6dbe9543-dee8-4a97-b02f-dd3a25f4a1a0
caps.latest.revision: 19
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
ms.sourcegitcommit: 5a0c6a1062330f952bb8fa52bc934f6754465513
ms.openlocfilehash: 28207e483b0bf56b9e3e98f487d174b8ae47e9e7
ms.lasthandoff: 02/25/2017

---
# <a name="ccomptrbase-class"></a>Classe CComPtrBase
Essa classe fornece uma base para classes de ponteiro inteligente usando rotinas COM base em memória.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>  
class CComPtrBase
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de objeto a ser referenciado pelo ponteiro inteligente.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComPtrBase:: ~ CComPtrBase](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComPtrBase::Advise](#advise)|Chame esse método para criar uma conexão entre o `CComPtrBase`do ponto de conexão e o coletor do cliente.|  
|[CComPtrBase::Attach](#attach)|Chame esse método para apropriar-se de um ponteiro existente.|  
|[CComPtrBase::CoCreateInstance](#cocreateinstance)|Chame esse método para criar um objeto da classe associado com um ID de classe especificado ou a ID do programa.|  
|[CComPtrBase::CopyTo](#copyto)|Chamar esse método para copiar o `CComPtrBase` ponteiro a outra variável de ponteiro.|  
|[CComPtrBase::Detach](#detach)|Chame esse método para liberar a propriedade de um ponteiro.|  
|[CComPtrBase::IsEqualObject](#isequalobject)|Chamar esse método para verificar se o especificado **IUnknown** aponta para o mesmo objeto associado a `CComPtrBase` objeto.|  
|[CComPtrBase::QueryInterface](#queryinterface)|Chame esse método para retornar um ponteiro para uma interface especificada.|  
|[CComPtrBase::Release](#release)|Chame esse método para liberar a interface.|  
|[CComPtrBase::SetSite](#setsite)|Chame esse método para definir o site da `CComPtrBase` o objeto para o **IUnknown** do objeto pai.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComPtrBase::operator T *](#operator_t_star)|O operador cast.|  
|[CComPtrBase::operator!](#operator_not)|O operador NOT.|  
|[CComPtrBase::operator < /](#operator_amp)|O < / operador.|  
|[CComPtrBase::operator *](#operator_star)|O * operador.|  
|[CComPtrBase::operator](#ccomptrbase__operator lt)|O menor-que o operador.|  
|[CComPtrBase::operator = =](#operator_eq_eq)|O operador de igualdade.|  
|[CComPtrBase::operator->](#operator_ptr)|O operador de membros do ponteiro.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComPtrBase::p](#p)|A variável de membro de dados do ponteiro.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe fornece a base para outros ponteiros inteligentes que usam as rotinas de gerenciamento de memória COM, como [CComQIPtr](../../atl/reference/ccomqiptr-class.md) e [CComPtr](../../atl/reference/ccomptr-class.md). As classes derivadas adicionar seus próprios operadores e construtores, mas dependem de métodos fornecidos pelo `CComPtrBase`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcomcli. h  
  
##  <a name="a-nameadvisea--ccomptrbaseadvise"></a><a name="advise"></a>CComPtrBase::Advise  
 Chame esse método para criar uma conexão entre o `CComPtrBase`do ponto de conexão e o coletor do cliente.  
  
```
HRESULT Advise(
    IUnknown* pUnk,
    const IID& iid,
    LPDWORD pdw) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *pUnk*  
 Um ponteiro para o cliente **IUnknown**.  
  
 `iid`  
 O GUID do ponto de conexão. Normalmente, isso é o mesmo que a interface gerenciada pelo ponto de conexão de saída.  
  
 `pdw`  
 Um ponteiro para o cookie que identifica exclusivamente a conexão.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Consulte [AtlAdvise](http://msdn.microsoft.com/library/625a2f03-6b7f-4761-be5d-d2871d1d3254) para obter mais informações.  
  
##  <a name="a-nameattacha--ccomptrbaseattach"></a><a name="attach"></a>CComPtrBase::Attach  
 Chame esse método para apropriar-se de um ponteiro existente.  
  
```
void Attach(T* p2) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p2`  
 O `CComPtrBase` objeto será assumir a propriedade deste ponteiro.  
  
### <a name="remarks"></a>Comentários  
 **Anexar** chamadas [CComPtrBase::Release](#release) em existente [CComPtrBase::p](#p) variável de membro e, em seguida, atribui `p2` para `CComPtrBase::p`. Quando um `CComPtrBase` objeto se apropria de um ponteiro, ele chamará automaticamente `Release` no ponteiro que excluirá o ponteiro e qualquer alocado dados se a contagem de referência no objeto chega a 0.  
  
##  <a name="a-namedtora--ccomptrbaseccomptrbase"></a><a name="dtor"></a>CComPtrBase:: ~ CComPtrBase  
 O destruidor.  
  
```
~CComPtrBase() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Libera a interface apontada por `CComPtrBase`.  
  
##  <a name="a-namecocreateinstancea--ccomptrbasecocreateinstance"></a><a name="cocreateinstance"></a>CComPtrBase::CoCreateInstance  
 Chame esse método para criar um objeto da classe associado com um ID de classe especificado ou a ID do programa.  
  
```
HRESULT CoCreateInstance(  
    LPCOLESTR szProgID,
    LPUNKNOWN pUnkOuter = NULL,
    DWORD dwClsContext = CLSCTX_ALL) throw();

HRESULT CoCreateInstance(  
    REFCLSID rclsid,
    LPUNKNOWN pUnkOuter = NULL,
    DWORD dwClsContext = CLSCTX_ALL) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `szProgID`  
 Ponteiro para um ProgID, usado para recuperar o CLSID.  
  
 `pUnkOuter`  
 Se **nulo**, indica que o objeto não está sendo criado como parte de uma agregação. Se não **nulo**, é um ponteiro para o objeto de agregação **IUnknown** interface (controla **IUnknown**).  
  
 `dwClsContext`  
 Contexto no qual o código que gerencia o objeto recém-criado será executado.  
  
 `rclsid`  
 CLSID associado a dados e o código que será usado para criar o objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou REGDB_E_CLASSNOTREG, CLASS_E_NOAGGREGATION, CO_E_CLASSSTRING ou E_NOINTERFACE em caso de falha. Consulte [CoCreateClassInstance](http://msdn.microsoft.com/library/windows/desktop/ms686615) e [CLSIDFromProgID](http://msdn.microsoft.com/library/windows/desktop/ms688386) para obter uma descrição desses erros.  
  
### <a name="remarks"></a>Comentários  
 Se a primeira forma do método é chamada, [CLSIDFromProgID](http://msdn.microsoft.com/library/windows/desktop/ms688386) é usado para recuperar o CLSID. Ambas as formas, em seguida, chame [CoCreateClassInstance](http://msdn.microsoft.com/library/windows/desktop/ms686615).  
  
 Em compilações de depuração, um erro de asserção ocorrerá se [CComPtrBase::p](#p) não é igual a nulo.  
  
##  <a name="a-namecopytoa--ccomptrbasecopyto"></a><a name="copyto"></a>CComPtrBase::CopyTo  
 Chamar esse método para copiar o `CComPtrBase` ponteiro a outra variável de ponteiro.  
  
```
HRESULT CopyTo(T** ppT) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *ppT*  
 Endereço da variável que receberá o `CComPtrBase` ponteiro.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, E_POINTER em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Copia o `CComPtrBase` ponteiro para *ppT*. A contagem de referência o [CComPtrBase::p](#p) variável de membro é incrementado.  
  
 Um erro HRESULT será retornado se *ppT* é igual a nulo. Em compilações de depuração, um erro de asserção ocorrerá se *ppT* é igual a nulo.  
  
##  <a name="a-namedetacha--ccomptrbasedetach"></a><a name="detach"></a>CComPtrBase::Detach  
 Chame esse método para liberar a propriedade de um ponteiro.  
  
```
T* Detach() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma cópia do ponteiro.  
  
### <a name="remarks"></a>Comentários  
 Libera a propriedade de um ponteiro, define o [CComPtrBase::p](#p) variável de membro de dados como NULL e retorna uma cópia do ponteiro.  
  
##  <a name="a-nameisequalobjecta--ccomptrbaseisequalobject"></a><a name="isequalobject"></a>CComPtrBase::IsEqualObject  
 Chamar esse método para verificar se o especificado **IUnknown** aponta para o mesmo objeto associado a `CComPtrBase` objeto.  
  
```
bool IsEqualObject(IUnknown* pOther) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pOther`  
 O **IUnknown \* ** para comparar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true se os objetos são idênticos, FALSO caso contrário.  
  
##  <a name="a-nameoperatornota--ccomptrbaseoperator-"></a><a name="operator_not"></a>CComPtrBase::operator!  
 O operador NOT.  
  
```
bool operator!() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará true se o `CComHeapPtr` ponteiro é igual a nulo, FALSO caso contrário.  
  
##  <a name="a-nameoperatorampa--ccomptrbaseoperator-amp"></a><a name="operator_amp"></a>CComPtrBase::operator&amp;  
 O < / operador.  
  
```
T** operator&() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o endereço do objeto apontado pelo `CComPtrBase` objeto.  
  
##  <a name="a-nameoperatorstara--ccomptrbaseoperator-"></a><a name="operator_star"></a>CComPtrBase::operator *  
 O * operador.  
  
```
T& operator*() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor de [CComPtrBase::p](#p); ou seja, um ponteiro para o objeto referenciado pelo `CComPtrBase` objeto.  
  
 Se as compilações de depuração, um erro de asserção ocorrerá se [CComPtrBase::p](#p) não é igual a nulo.  
  
##  <a name="a-nameoperatoreqeqa--ccomptrbaseoperator-"></a><a name="operator_eq_eq"></a>CComPtrBase::operator = =  
 O operador de igualdade.  
  
```
bool operator== (T* pT) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *pT*  
 Um ponteiro para um objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará true se `CComPtrBase` e *pT* apontam para o mesmo objeto, FALSO caso contrário.  
  
##  <a name="a-nameoperatorptra--ccomptrbaseoperator--gt"></a><a name="operator_ptr"></a>CComPtrBase::operator-&gt;  

 O operador de ponteiro para membro.  
  
```
_NoAddRefReleaseOnCComPtr<T>* operator->() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor da [CComPtrBase::p](#p) variável de membro de dados.  
  
### <a name="remarks"></a>Comentários  
 Usar esse operador para chamar um método em uma classe apontada para o `CComPtrBase` objeto. Em compilações de depuração, uma falha de asserção ocorrerá se o `CComPtrBase` membro de dados aponta para NULL.  
  
##  <a name="a-nameoperatorlta--ccomptrbaseoperator-lt"></a><a name="operator_lt"></a>CComPtrBase::operator&lt;  
 O menor-que o operador.  
  
```
bool operator<(T* pT) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *pT*  
 Um ponteiro para um objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se o ponteiro gerenciado pelo objeto atual é menor que o ponteiro para o qual estão sendo comparado.  
  
##  <a name="a-nameoperatortstara--ccomptrbaseoperator-t"></a><a name="operator_t_star"></a>CComPtrBase::operator T *  
 O operador cast.  
  
```  
operator T*() const throw();
```  
  
### <a name="remarks"></a>Comentários  
 Retorna um ponteiro para o tipo de dados do objeto definido no modelo de classe.  
  
##  <a name="a-namepa--ccomptrbasep"></a><a name="p"></a>CComPtrBase::p  
 A variável de membro de dados do ponteiro.  
  
```
T* p;
```  
  
### <a name="remarks"></a>Comentários  
 Essa variável de membro contém as informações do ponteiro.  
  
##  <a name="a-namequeryinterfacea--ccomptrbasequeryinterface"></a><a name="queryinterface"></a>CComPtrBase::QueryInterface  
 Chame esse método para retornar um ponteiro para uma interface especificada.  
  
```
template <class Q> HRESULT QueryInterface(Q
** pp) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `Q`  
 O tipo de objeto cujo ponteiro de interface é necessário.  
  
 `pp`  
 Endereço da variável de saída que recebe o ponteiro de interface solicitada.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK no sucesso ou E_NOINTERFACE em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Esse método chama [IUnknown:: QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521).  
  
 Em compilações de depuração, um erro de asserção ocorrerá se *pp* não é igual a nulo.  
  
##  <a name="a-namereleasea--ccomptrbaserelease"></a><a name="release"></a>CComPtrBase::Release  
 Chame esse método para liberar a interface.  
  
```
void Release() throw();
```  
  
### <a name="remarks"></a>Comentários  
 A interface é liberada, e [CComPtrBase::p](#p) é definido como NULL.  
  
##  <a name="a-namesetsitea--ccomptrbasesetsite"></a><a name="setsite"></a>CComPtrBase::SetSite  
 Chame esse método para definir o site da `CComPtrBase` o objeto para o **IUnknown** do objeto pai.  
  
```
HRESULT SetSite(IUnknown* punkParent) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `punkParent`  
 Um ponteiro para o **IUnknown** interface do pai.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Esse método chama [AtlSetChildSite](http://msdn.microsoft.com/library/2a8ece19-6bfd-4e89-9d1d-e5a78f95e2df).  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)

