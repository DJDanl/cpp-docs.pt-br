---
title: Classe CComPtrBase | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComPtrBase
- ATLCOMCLI/ATL::CComPtrBase
- ATLCOMCLI/ATL::CComPtrBase::Advise
- ATLCOMCLI/ATL::CComPtrBase::Attach
- ATLCOMCLI/ATL::CComPtrBase::CoCreateInstance
- ATLCOMCLI/ATL::CComPtrBase::CopyTo
- ATLCOMCLI/ATL::CComPtrBase::Detach
- ATLCOMCLI/ATL::CComPtrBase::IsEqualObject
- ATLCOMCLI/ATL::CComPtrBase::QueryInterface
- ATLCOMCLI/ATL::CComPtrBase::Release
- ATLCOMCLI/ATL::CComPtrBase::SetSite
- ATLCOMCLI/ATL::CComPtrBase::p
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: d2d39abf526a58b8442107b5ee816f316ae841f5
ms.openlocfilehash: 65541d9e6f15bcc56811fa6a5d9d168737131108
ms.contentlocale: pt-br
ms.lasthandoff: 03/31/2017

---
# <a name="ccomptrbase-class"></a>Classe CComPtrBase
Essa classe fornece uma base para classes de ponteiro inteligente usando memória COM base em rotinas.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>  
class CComPtrBase
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de objeto a ser referenciada pelo ponteiro inteligente.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComPtrBase:: ~ CComPtrBase](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComPtrBase::Advise](#advise)|Chame esse método para criar uma conexão entre o `CComPtrBase`do coletor do cliente e ponto de conexão.|  
|[CComPtrBase::Attach](#attach)|Chame esse método para assumir a propriedade de um ponteiro existente.|  
|[CComPtrBase::CoCreateInstance](#cocreateinstance)|Chame esse método para criar um objeto da classe associada com um ID de classe ou ID de programa especificado|  
|[CComPtrBase::CopyTo](#copyto)|Chame este método para copiar o `CComPtrBase` ponteiro a outra variável de ponteiro.|  
|[CComPtrBase::Detach](#detach)|Chame este método para liberar a propriedade de um ponteiro.|  
|[CComPtrBase::IsEqualObject](#isequalobject)|Chame este método para verificar se o especificado **IUnknown** aponta para o mesmo objeto associado a `CComPtrBase` objeto.|  
|[CComPtrBase::QueryInterface](#queryinterface)|Chame este método para retornar um ponteiro para uma interface especificada.|  
|[CComPtrBase::Release](#release)|Chame este método para liberar a interface.|  
|[CComPtrBase::SetSite](#setsite)|Chame este método para definir o site do `CComPtrBase` o objeto para o **IUnknown** do objeto pai.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComPtrBase::operator T *](#operator_t_star)|O operador cast.|  
|[CComPtrBase::operator!](#operator_not)|O operador NOT.|  
|[CComPtrBase::operator &](#operator_amp)|O & operador.|  
|[CComPtrBase::operator *](#operator_star)|O * operador.|  
|[CComPtrBase::operator](#ccomptrbase__operator lt)|O menor-que o operador.|  
|[CComPtrBase::operator = =](#operator_eq_eq)|O operador de igualdade.|  
|[CComPtrBase::operator->](#operator_ptr)|O operador de ponteiro para membros.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComPtrBase::p](#p)|A variável de membro de dados de ponteiro.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe fornece a base para outros ponteiros inteligentes que usam rotinas de gerenciamento de memória COM, como [CComQIPtr](../../atl/reference/ccomqiptr-class.md) e [CComPtr](../../atl/reference/ccomptr-class.md). As classes derivadas adicionar seus próprios operadores e construtores, mas contam com os métodos fornecidos pelo `CComPtrBase`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcomcli.h  
  
##  <a name="advise"></a>CComPtrBase::Advise  
 Chame esse método para criar uma conexão entre o `CComPtrBase`do coletor do cliente e ponto de conexão.  
  
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
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Consulte [AtlAdvise](connection-point-global-functions.md#atladvise) para obter mais informações.  
  
##  <a name="attach"></a>CComPtrBase::Attach  
 Chame esse método para assumir a propriedade de um ponteiro existente.  
  
```
void Attach(T* p2) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p2`  
 O `CComPtrBase` objeto será assumir a propriedade deste ponteiro.  
  
### <a name="remarks"></a>Comentários  
 **Anexar** chamadas [CComPtrBase::Release](#release) existente [CComPtrBase::p](#p) variável de membro e, em seguida, atribui `p2` para `CComPtrBase::p`. Quando um `CComPtrBase` objeto assume a propriedade de um ponteiro, ele será automaticamente chamar `Release` no ponteiro que excluirá o ponteiro e qualquer alocada dados se a contagem de referência no objeto chegar a 0.  
  
##  <a name="dtor"></a>CComPtrBase:: ~ CComPtrBase  
 O destruidor.  
  
```
~CComPtrBase() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Libera a interface apontada pelo `CComPtrBase`.  
  
##  <a name="cocreateinstance"></a>CComPtrBase::CoCreateInstance  
 Chame esse método para criar um objeto da classe associada com um ID de classe ou ID de programa especificado  
  
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
 Se **nulo**, indica que o objeto não está sendo criado como parte de uma agregação. Se não **nulo**, é um ponteiro para o objeto de agregação **IUnknown** interface (o controlador **IUnknown**).  
  
 `dwClsContext`  
 Contexto no qual o código que gerencia o objeto recém-criado será executado.  
  
 `rclsid`  
 CLSID associado a dados e o código que será usado para criar o objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou REGDB_E_CLASSNOTREG, CLASS_E_NOAGGREGATION, CO_E_CLASSSTRING ou E_NOINTERFACE em caso de falha. Consulte [CoCreateClassInstance](http://msdn.microsoft.com/library/windows/desktop/ms686615) e [CLSIDFromProgID](http://msdn.microsoft.com/library/windows/desktop/ms688386) para obter uma descrição desses erros.  
  
### <a name="remarks"></a>Comentários  
 Se o primeiro formulário do método for chamado, [CLSIDFromProgID](http://msdn.microsoft.com/library/windows/desktop/ms688386) é usada para recuperar o CLSID. Ambas as formas, em seguida, chamar [CoCreateClassInstance](http://msdn.microsoft.com/library/windows/desktop/ms686615).  
  
 Em compilações de depuração, um erro de asserção ocorrerá se [CComPtrBase::p](#p) não é igual a NULL.  
  
##  <a name="copyto"></a>CComPtrBase::CopyTo  
 Chame este método para copiar o `CComPtrBase` ponteiro a outra variável de ponteiro.  
  
```
HRESULT CopyTo(T** ppT) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *ppT*  
 Endereço da variável que receberá o `CComPtrBase` ponteiro.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, E_POINTER em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Copia o `CComPtrBase` ponteiro para *ppT*. A contagem de referência o [CComPtrBase::p](#p) variável de membro é incrementada.  
  
 Um erro HRESULT será retornado se *ppT* é igual a NULL. Em compilações de depuração, um erro de asserção ocorrerá se *ppT* é igual a NULL.  
  
##  <a name="detach"></a>CComPtrBase::Detach  
 Chame este método para liberar a propriedade de um ponteiro.  
  
```
T* Detach() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma cópia do ponteiro.  
  
### <a name="remarks"></a>Comentários  
 Libera a propriedade de um ponteiro, define o [CComPtrBase::p](#p) variável de membro de dados como NULL e retorna uma cópia do ponteiro.  
  
##  <a name="isequalobject"></a>CComPtrBase::IsEqualObject  
 Chame este método para verificar se o especificado **IUnknown** aponta para o mesmo objeto associado a `CComPtrBase` objeto.  
  
```
bool IsEqualObject(IUnknown* pOther) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pOther`  
 O **IUnknown \*** para comparar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true se os objetos são idênticos, FALSO caso contrário.  
  
##  <a name="operator_not"></a>CComPtrBase::operator!  
 O operador NOT.  
  
```
bool operator!() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará true se o `CComHeapPtr` ponteiro é igual a NULL, FALSO caso contrário.  
  
##  <a name="operator_amp"></a>CComPtrBase::operator&amp;  
 O & operador.  
  
```
T** operator&() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o endereço do objeto que aponta para o `CComPtrBase` objeto.  
  
##  <a name="operator_star"></a>CComPtrBase::operator *  
 O * operador.  
  
```
T& operator*() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor de [CComPtrBase::p](#p); ou seja, um ponteiro para o objeto referenciado pelo `CComPtrBase` objeto.  
  
 Se as compilações de depuração, um erro de asserção ocorrerá se [CComPtrBase::p](#p) não é igual a NULL.  
  
##  <a name="operator_eq_eq"></a>CComPtrBase::operator = =  
 O operador de igualdade.  
  
```
bool operator== (T* pT) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *pT*  
 Um ponteiro para um objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará true se `CComPtrBase` e *pT* apontam para o mesmo objeto, FALSO caso contrário.  
  
##  <a name="operator_ptr"></a>CComPtrBase::operator-&gt;  

 O operador de ponteiro-para-membro.  
  
```
_NoAddRefReleaseOnCComPtr<T>* operator->() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor da [CComPtrBase::p](#p) variável de membro de dados.  
  
### <a name="remarks"></a>Comentários  
 Use este operador para chamar um método em uma classe que aponta para o `CComPtrBase` objeto. Em compilações de depuração, uma falha de asserção ocorrerá se o `CComPtrBase` membro de dados aponta para NULL.  
  
##  <a name="operator_lt"></a>CComPtrBase::operator&lt;  
 O menor-que o operador.  
  
```
bool operator<(T* pT) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *pT*  
 Um ponteiro para um objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se o ponteiro gerenciado pelo objeto atual é menor que o ponteiro para o qual está sendo comparado.  
  
##  <a name="operator_t_star"></a>CComPtrBase::operator T *  
 O operador cast.  
  
```  
operator T*() const throw();
```  
  
### <a name="remarks"></a>Comentários  
 Retorna um ponteiro para o tipo de dados do objeto definido no modelo de classe.  
  
##  <a name="p"></a>CComPtrBase::p  
 A variável de membro de dados de ponteiro.  
  
```
T* p;
```  
  
### <a name="remarks"></a>Comentários  
 Essa variável de membro contém as informações do ponteiro.  
  
##  <a name="queryinterface"></a>CComPtrBase::QueryInterface  
 Chame este método para retornar um ponteiro para uma interface especificada.  
  
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
 Retorna S_OK em caso de sucesso ou E_NOINTERFACE em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Este método chama [IUnknown:: QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521).  
  
 Em compilações de depuração, um erro de asserção ocorrerá se *pp* não é igual a NULL.  
  
##  <a name="release"></a>CComPtrBase::Release  
 Chame este método para liberar a interface.  
  
```
void Release() throw();
```  
  
### <a name="remarks"></a>Comentários  
 A interface é liberada, e [CComPtrBase::p](#p) é definido como NULL.  
  
##  <a name="setsite"></a>CComPtrBase::SetSite  
 Chame este método para definir o site do `CComPtrBase` o objeto para o **IUnknown** do objeto pai.  
  
```
HRESULT SetSite(IUnknown* punkParent) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `punkParent`  
 Um ponteiro para o **IUnknown** interface do pai.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Este método chama [AtlSetChildSite](composite-control-global-functions.md#atlsetchildsite).  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)

