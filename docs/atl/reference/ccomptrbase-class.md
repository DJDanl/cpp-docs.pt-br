---
title: Classe CComPtrBase | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c7abcfcfe6aec722fa3540ad974017ab47e6cf71
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37885445"
---
# <a name="ccomptrbase-class"></a>Classe CComPtrBase
Essa classe fornece uma base para classes de ponteiro inteligente usando memória COM base em rotinas.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>  
class CComPtrBase
```  
  
#### <a name="parameters"></a>Parâmetros  
 *T*  
 O tipo de objeto a ser referenciado pelo ponteiro inteligente.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComPtrBase:: ~ CComPtrBase](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComPtrBase::Advise](#advise)|Chame esse método para criar uma conexão entre o `CComPtrBase`do ponto de conexão e o coletor de um cliente.|  
|[CComPtrBase::Attach](#attach)|Chame esse método para apropriar-se de um ponteiro existente.|  
|[CComPtrBase::CoCreateInstance](#cocreateinstance)|Chame esse método para criar um objeto da classe associada com uma ID de classe especificada ou a ID do programa.|  
|[CComPtrBase::CopyTo](#copyto)|Chame esse método para copiar o `CComPtrBase` ponteiro a outra variável de ponteiro.|  
|[CComPtrBase::Detach](#detach)|Chame esse método para liberar a propriedade de um ponteiro.|  
|[CComPtrBase::IsEqualObject](#isequalobject)|Chame esse método para verificar se o especificado `IUnknown` aponta para o mesmo objeto associado com o `CComPtrBase` objeto.|  
|[CComPtrBase::QueryInterface](#queryinterface)|Chame esse método para retornar um ponteiro para uma interface especificada.|  
|[CComPtrBase::Release](#release)|Chame esse método para liberar a interface.|  
|[CComPtrBase::SetSite](#setsite)|Chame esse método para definir o site da `CComPtrBase` do objeto para o `IUnknown` do objeto pai.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComPtrBase::operator T *](#operator_t_star)|O operador cast.|  
|[CComPtrBase::operator!](#operator_not)|O operador NOT.|  
|[CComPtrBase::operator &](#operator_amp)|A & operador.|  
|[CComPtrBase::operator *](#operator_star)|O * operador.|  
|[CComPtrBase::operator <](#ccomptrbase__operator lt)|O menor-que o operador.|  
|[CComPtrBase::operator = =](#operator_eq_eq)|O operador de igualdade.|  
|[CComPtrBase::operator ->](#operator_ptr)|O operador de membros do ponteiro.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComPtrBase::p](#p)|A variável de membro de dados de ponteiro.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe fornece a base para outros ponteiros inteligentes que usam as rotinas de gerenciamento de memória COM, como [CComQIPtr](../../atl/reference/ccomqiptr-class.md) e [CComPtr](../../atl/reference/ccomptr-class.md). As classes derivadas adicionar seus próprios operadores e construtores, mas contar com os métodos fornecidos pelo `CComPtrBase`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcomcli. h  
  
##  <a name="advise"></a>  CComPtrBase::Advise  
 Chame esse método para criar uma conexão entre o `CComPtrBase`do ponto de conexão e o coletor de um cliente.  
  
```
HRESULT Advise(
    IUnknown* pUnk,
    const IID& iid,
    LPDWORD pdw) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *pUnk*  
 Um ponteiro para o cliente `IUnknown`.  
  
 *IID*  
 O GUID do ponto de conexão. Normalmente, isso é o mesmo que a interface de saída gerenciada pelo ponto de conexão.  
  
 *PDW*  
 Um ponteiro para o cookie que identifica exclusivamente a conexão.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK no êxito ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Ver [AtlAdvise](connection-point-global-functions.md#atladvise) para obter mais informações.  
  
##  <a name="attach"></a>  CComPtrBase::Attach  
 Chame esse método para apropriar-se de um ponteiro existente.  
  
```
void Attach(T* p2) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *P2*  
 O `CComPtrBase` objeto assumirá a propriedade do ponteiro this.  
  
### <a name="remarks"></a>Comentários  
 `Attach` chamadas [CComPtrBase::Release](#release) existente [CComPtrBase::p](#p) variável de membro e, em seguida, atribui *p2* para `CComPtrBase::p`. Quando um `CComPtrBase` objeto assume a propriedade de um ponteiro, ele chamará automaticamente `Release` no ponteiro que excluirá o ponteiro e qualquer alocado dados se a contagem de referência no objeto chega a 0.  
  
##  <a name="dtor"></a>  CComPtrBase:: ~ CComPtrBase  
 O destruidor.  
  
```
~CComPtrBase() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Libera a interface apontada pelo `CComPtrBase`.  
  
##  <a name="cocreateinstance"></a>  CComPtrBase::CoCreateInstance  
 Chame esse método para criar um objeto da classe associada com uma ID de classe especificada ou a ID do programa.  
  
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
 *szProgID*  
 Ponteiro para um ProgID, usado para recuperar o CLSID.  
  
 *pUnkOuter*  
 Se for NULL, indica que o objeto não está sendo criado como parte de uma agregação. Se não-nulo, é um ponteiro para o objeto agregado `IUnknown` interface (o controlando `IUnknown`).  
  
 *dwClsContext*  
 Contexto no qual o código que gerencia o objeto recém-criado será executado.  
  
 *rclsid*  
 CLSID associado a dados e o código que será usado para criar o objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará S_OK no êxito, ou REGDB_E_CLASSNOTREG, CLASS_E_NOAGGREGATION, CO_E_CLASSSTRING ou E_NOINTERFACE em caso de falha. Ver [CoCreateClassInstance](http://msdn.microsoft.com/library/windows/desktop/ms686615) e [CLSIDFromProgID](http://msdn.microsoft.com/library/windows/desktop/ms688386) para obter uma descrição desses erros.  
  
### <a name="remarks"></a>Comentários  
 Se o primeiro formulário do método for chamado, [CLSIDFromProgID](http://msdn.microsoft.com/library/windows/desktop/ms688386) é usada para recuperar o CLSID. Em seguida, chame ambos os formatos [CoCreateClassInstance](http://msdn.microsoft.com/library/windows/desktop/ms686615).  
  
 Em compilações de depuração, um erro de asserção ocorrerá se [CComPtrBase::p](#p) não é igual a NULL.  
  
##  <a name="copyto"></a>  CComPtrBase::CopyTo  
 Chame esse método para copiar o `CComPtrBase` ponteiro a outra variável de ponteiro.  
  
```
HRESULT CopyTo(T** ppT) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *ppT*  
 Endereço da variável que receberá o `CComPtrBase` ponteiro.  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará S_OK no êxito, E_POINTER em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Copia o `CComPtrBase` ponteiro para *ppT*. A contagem de referência as [CComPtrBase::p](#p) variável de membro é incrementado.  
  
 Um erro HRESULT será retornado se *ppT* é igual a NULL. Em compilações de depuração, um erro de asserção ocorrerá se *ppT* é igual a NULL.  
  
##  <a name="detach"></a>  CComPtrBase::Detach  
 Chame esse método para liberar a propriedade de um ponteiro.  
  
```
T* Detach() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma cópia do ponteiro.  
  
### <a name="remarks"></a>Comentários  
 Libera a propriedade de um ponteiro, define o [CComPtrBase::p](#p) variável de membro de dados como NULL e retorna uma cópia do ponteiro.  
  
##  <a name="isequalobject"></a>  CComPtrBase::IsEqualObject  
 Chame esse método para verificar se o especificado `IUnknown` aponta para o mesmo objeto associado com o `CComPtrBase` objeto.  
  
```
bool IsEqualObject(IUnknown* pOther) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *pOther*  
 O `IUnknown *` de comparação.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se os objetos forem idênticos, false caso contrário.  
  
##  <a name="operator_not"></a>  CComPtrBase::operator!  
 O operador NOT.  
  
```
bool operator!() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará true se o `CComHeapPtr` ponteiro é igual a NULL, false caso contrário.  
  
##  <a name="operator_amp"></a>  CComPtrBase::operator &amp;  
 A & operador.  
  
```
T** operator&() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o endereço do objeto apontado pelo `CComPtrBase` objeto.  
  
##  <a name="operator_star"></a>  CComPtrBase::operator *  
 O * operador.  
  
```
T& operator*() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor de [CComPtrBase::p](#p); ou seja, um ponteiro para o objeto referenciado pelo `CComPtrBase` objeto.  
  
 Se as compilações de depuração, um erro de asserção ocorrerá se [CComPtrBase::p](#p) não é igual a NULL.  
  
##  <a name="operator_eq_eq"></a>  CComPtrBase::operator = =  
 O operador de igualdade.  
  
```
bool operator== (T* pT) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *pT*  
 Um ponteiro para um objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará true se `CComPtrBase` e *pT* apontam para o mesmo objeto, false caso contrário.  
  
##  <a name="operator_ptr"></a>  CComPtrBase::operator-&gt;  

 O operador de ponteiro para membro.  
  
```
_NoAddRefReleaseOnCComPtr<T>* operator->() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor da [CComPtrBase::p](#p) variável de membro de dados.  
  
### <a name="remarks"></a>Comentários  
 Use este operador para chamar um método em uma classe apontada pelo `CComPtrBase` objeto. Em compilações de depuração, uma falha de asserção ocorrerá se o `CComPtrBase` membro de dados aponta para NULL.  
  
##  <a name="operator_lt"></a>  CComPtrBase::operator &lt;  
 O menor-que o operador.  
  
```
bool operator<(T* pT) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *pT*  
 Um ponteiro para um objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se o ponteiro gerenciado pelo objeto atual é menor que o ponteiro para o qual está sendo comparado.  
  
##  <a name="operator_t_star"></a>  CComPtrBase::operator T *  
 O operador cast.  
  
```  
operator T*() const throw();
```  
  
### <a name="remarks"></a>Comentários  
 Retorna um ponteiro para o tipo de dados de objeto definido no modelo de classe.  
  
##  <a name="p"></a>  CComPtrBase::p  
 A variável de membro de dados de ponteiro.  
  
```
T* p;
```  
  
### <a name="remarks"></a>Comentários  
 Essa variável de membro contém as informações de ponteiro.  
  
##  <a name="queryinterface"></a>  CComPtrBase::QueryInterface  
 Chame esse método para retornar um ponteiro para uma interface especificada.  
  
```
template <class Q> HRESULT QueryInterface(Q
** pp) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *Q*  
 O tipo de objeto cujo ponteiro de interface é necessário.  
  
 *PP*  
 Endereço da variável de saída que recebe o ponteiro de interface solicitado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará S_OK no êxito ou E_NOINTERFACE em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Este método chama [IUnknown:: QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521).  
  
 Em compilações de depuração, um erro de asserção ocorrerá se *pp* não é igual a NULL.  
  
##  <a name="release"></a>  CComPtrBase::Release  
 Chame esse método para liberar a interface.  
  
```
void Release() throw();
```  
  
### <a name="remarks"></a>Comentários  
 A interface é liberada, e [CComPtrBase::p](#p) é definido como NULL.  
  
##  <a name="setsite"></a>  CComPtrBase::SetSite  
 Chame esse método para definir o site da `CComPtrBase` do objeto para o `IUnknown` do objeto pai.  
  
```
HRESULT SetSite(IUnknown* punkParent) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *punkParent*  
 Um ponteiro para o `IUnknown` interface do pai.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK no êxito ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Este método chama [AtlSetChildSite](composite-control-global-functions.md#atlsetchildsite).  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
