---
title: Classe CComClassFactory2 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComClassFactory2
- ATLCOM/ATL::CComClassFactory2
- ATLCOM/ATL::CComClassFactory2::CreateInstance
- ATLCOM/ATL::CComClassFactory2::CreateInstanceLic
- ATLCOM/ATL::CComClassFactory2::GetLicInfo
- ATLCOM/ATL::CComClassFactory2::LockServer
- ATLCOM/ATL::CComClassFactory2::RequestLicKey
dev_langs:
- C++
helpviewer_keywords:
- CComClassFactory2 class
ms.assetid: 19b66fd6-b9ed-47a0-822c-8132184f5a3e
caps.latest.revision: 20
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
ms.openlocfilehash: 3787214d5479e1cd57295c9c25335e87651a16bb
ms.lasthandoff: 02/25/2017

---
# <a name="ccomclassfactory2-class"></a>Classe CComClassFactory2
Essa classe implementa o [IClassFactory2](http://msdn.microsoft.com/library/windows/desktop/ms692720) interface.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class license>  
class CComClassFactory2 : public IClassFactory2,
    public CComObjectRootEx<CComGlobalsThreadModel>,
    public license
```  
  
#### <a name="parameters"></a>Parâmetros  
 *licença*  
 Uma classe que implementa as seguintes funções estáticas:  
  
- **estático VerifyLicenseKey BOOL (BSTR** `bstr` **);**  
  
- **estático GetLicenseKey BOOL (DWORD** `dwReserved` **, BSTR\* ** `pBstr` **);**  
  
- **estático (de IsLicenseValid BOOL);**  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComClassFactory2::CreateInstance](#createinstance)|Cria um objeto do CLSID especificado.|  
|[CComClassFactory2::CreateInstanceLic](#createinstancelic)|Dada uma chave de licença, cria um objeto do CLSID especificado.|  
|[CComClassFactory2::GetLicInfo](#getlicinfo)|Recupera informações que descrevem os recursos de licenciamento da fábrica de classe.|  
|[CComClassFactory2::LockServer](#lockserver)|Bloqueia a fábrica de classes na memória.|  
|[CComClassFactory2::RequestLicKey](#requestlickey)|Cria e retorna uma chave de licença.|  
  
## <a name="remarks"></a>Comentários  
 `CComClassFactory2`implementa o [IClassFactory2](http://msdn.microsoft.com/library/windows/desktop/ms692720) interface, que é uma extensão de [IClassFactory](http://msdn.microsoft.com/library/windows/desktop/ms694364). **IClassFactory2** controles por meio de uma licença a criação do objeto. Uma classe factory executando em uma máquina licenciada pode fornecer uma chave de licença de tempo de execução. Essa chave de licença permite que um aplicativo instanciar objetos quando uma licença completa do computador não existe.  
  
 Objetos ATL normalmente adquirem uma fábrica de classes, derivando de [CComCoClass](../../atl/reference/ccomcoclass-class.md). Essa classe inclui a macro [DECLARE_CLASSFACTORY](http://msdn.microsoft.com/library/51a6b925-07c0-4d3a-9174-0b8c808975e4), que declara [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) como a fábrica de classes padrão. Usar `CComClassFactory2`, especifique o [DECLARE_CLASSFACTORY2](http://msdn.microsoft.com/library/38a6c969-7297-4bb1-9ba6-1fe2d355b285) macro na definição de classe do objeto. Por exemplo:  
  
 [!code-cpp[NVC_ATL_COM N º&2;](../../atl/codesnippet/cpp/ccomclassfactory2-class_1.h)]  
  
 **CMyLicense**, o parâmetro de modelo `CComClassFactory2`, deve implementar as funções estáticas `VerifyLicenseKey`, `GetLicenseKey`, e `IsLicenseValid`. Este é um exemplo de uma classe simples de licença:  
  
 [!code-cpp[NVC_ATL_COM N º&3;](../../atl/codesnippet/cpp/ccomclassfactory2-class_2.h)]  
  
 `CComClassFactory2`deriva de ambos **CComClassFactory2Base** e *licença*. **CComClassFactory2Base**, por sua vez, deriva de **IClassFactory2** e **CComObjectRootEx\< CComGlobalsThreadModel >**.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CComObjectRootBase`  
  
 `license`  
  
 [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)  
  
 `IClassFactory2`  
  
 `CComClassFactory2`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="createinstance"></a>CComClassFactory2::CreateInstance  
 Cria um objeto do CLSID especificado e recupera um ponteiro de interface para esse objeto.  
  
```
STDMETHOD(CreateInstance)(LPUNKNOWN pUnkOuter, REFIID riid, void** ppvObj);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pUnkOuter`  
 [in] Se o objeto está sendo criado como parte de uma agregação, em seguida, `pUnkOuter` deve ser o externo desconhecido. Caso contrário, `pUnkOuter` deve ser **nulo**.  
  
 `riid`  
 [in] O IID da interface solicitada. Se `pUnkOuter` não **nulo**, `riid` deve ser **IID_IUnknown**.  
  
 `ppvObj`  
 [out] Um ponteiro para o ponteiro de interface identificado pelo `riid`. Se o objeto não oferece suporte a essa interface, `ppvObj` é definido como **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Requer que a máquina seja totalmente licenciado. Se não existir uma licença completa de máquina, chame [CreateInstanceLic](#createinstancelic).  
  
##  <a name="createinstancelic"></a>CComClassFactory2::CreateInstanceLic  
 Semelhante ao [CreateInstance](#createinstance), exceto que `CreateInstanceLic` requer uma chave de licença.  
  
```
STDMETHOD(CreateInstanceLic)(
    IUnknown* pUnkOuter,
    IUnknown* /* pUnkReserved
 */,
    REFIID riid,
    BSTR bstrKey,
    void** ppvObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pUnkOuter`  
 [in] Se o objeto está sendo criado como parte de uma agregação, em seguida, `pUnkOuter` deve ser o externo desconhecido. Caso contrário, `pUnkOuter` deve ser **nulo**.  
  
 *pUnkReserved*  
 [in] Não usado. Deve ser **nulo**.  
  
 `riid`  
 [in] O IID da interface solicitada. Se `pUnkOuter` não **nulo**, `riid` deve ser **IID_IUnknown**.  
  
 `bstrKey`  
 [in] A chave de licença de tempo de execução obtido anteriormente de uma chamada para `RequestLicKey`. Essa chave é necessária para criar o objeto.  
  
 `ppvObject`  
 [out] Um ponteiro para o ponteiro de interface especificado por `riid`. Se o objeto não oferece suporte a essa interface, `ppvObject` é definido como **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Você pode obter uma chave de licença usando [RequestLicKey](#requestlickey). Para criar um objeto em uma máquina sem licença, você deve chamar `CreateInstanceLic`.  
  
##  <a name="getlicinfo"></a>CComClassFactory2::GetLicInfo  
 Preenche um [LICINFO](http://msdn.microsoft.com/library/windows/desktop/ms690590) recursos de licença da estrutura com informações que descrevem a fábrica de classes.  
  
```
STDMETHOD(GetLicInfo)(LICINFO* pLicInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pLicInfo*  
 [out] Ponteiro para uma **LICINFO** estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 O `fRuntimeKeyAvail` membro dessa estrutura indica se, dada uma chave de licença, a fábrica de classes permite que objetos a serem criados em uma máquina sem licença. O *fLicVerified* membro indica se existe uma licença completa do computador.  
  
##  <a name="lockserver"></a>CComClassFactory2::LockServer  
 Incrementa e decrementa o bloqueio de módulo contar chamando **_Module::Lock** e **_Module::Unlock**, respectivamente.  
  
```
STDMETHOD(LockServer)(BOOL fLock);
```  
  
### <a name="parameters"></a>Parâmetros  
 `fLock`  
 [in] Se **TRUE**, a contagem de bloqueio é incrementado; caso contrário, a contagem de bloqueio é diminuída.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 **_Module** refere-se à instância global do [CComModule](../../atl/reference/ccommodule-class.md) ou uma classe derivada.  
  
 Chamando `LockServer` permite que um cliente mantenha uma fábrica de classes para que vários objetos podem ser criados rapidamente.  
  
##  <a name="requestlickey"></a>CComClassFactory2::RequestLicKey  
 Cria e retorna uma chave de licença, desde que o `fRuntimeKeyAvail` membro do [LICINFO](http://msdn.microsoft.com/library/windows/desktop/ms690590) estrutura é **TRUE**.  
  
```
STDMETHOD(RequestLicKey)(DWORD dwReserved, BSTR* pbstrKey);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwReserved`  
 [in] Não usado. Deve ser zero.  
  
 `pbstrKey`  
 [out] Ponteiro para a chave de licença.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Uma chave de licença é necessária para chamar [CreateInstanceLic](#createinstancelic) para criar um objeto em uma máquina sem licença. Se `fRuntimeKeyAvail` é **FALSE**, e objetos só podem ser criados em uma máquina totalmente licenciada.  
  
 Chamar [GetLicInfo](#getlicinfo) para recuperar o valor de `fRuntimeKeyAvail`.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md)   
 [Classe CComClassFactorySingleton](../../atl/reference/ccomclassfactorysingleton-class.md)   
 [Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)   
 [CComGlobalsThreadModel](atl-typedefs.md#ccomglobalsthreadmodel)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

