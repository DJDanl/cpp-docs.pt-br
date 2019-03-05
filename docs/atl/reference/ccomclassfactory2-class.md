---
title: Classe CComClassFactory2
ms.date: 11/04/2016
f1_keywords:
- CComClassFactory2
- ATLCOM/ATL::CComClassFactory2
- ATLCOM/ATL::CComClassFactory2::CreateInstance
- ATLCOM/ATL::CComClassFactory2::CreateInstanceLic
- ATLCOM/ATL::CComClassFactory2::GetLicInfo
- ATLCOM/ATL::CComClassFactory2::LockServer
- ATLCOM/ATL::CComClassFactory2::RequestLicKey
helpviewer_keywords:
- CComClassFactory2 class
ms.assetid: 19b66fd6-b9ed-47a0-822c-8132184f5a3e
ms.openlocfilehash: b3b14fa59765aa72a1142e0eef41aa84abea35de
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57301838"
---
# <a name="ccomclassfactory2-class"></a>Classe CComClassFactory2

Essa classe implementa a [IClassFactory2](/windows/desktop/api/ocidl/nn-ocidl-iclassfactory2) interface.

## <a name="syntax"></a>Sintaxe

```
template <class license>
class CComClassFactory2 : public IClassFactory2,
    public CComObjectRootEx<CComGlobalsThreadModel>,
    public license
```

#### <a name="parameters"></a>Parâmetros

*license*<br/>
Uma classe que implementa as funções estáticas a seguir:

- `static BOOL VerifyLicenseKey( BSTR bstr );`

- `static BOOL GetLicenseKey( DWORD dwReserved, BSTR * pBstr );`

- `static BOOL IsLicenseValid( );`

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComClassFactory2::CreateInstance](#createinstance)|Cria um objeto do CLSID especificado.|
|[CComClassFactory2::CreateInstanceLic](#createinstancelic)|Dada uma chave de licença, cria um objeto do CLSID especificado.|
|[CComClassFactory2::GetLicInfo](#getlicinfo)|Recupera as informações que descrevem os recursos de licenciamento da fábrica de classes.|
|[CComClassFactory2::LockServer](#lockserver)|Bloqueia a fábrica de classes na memória.|
|[CComClassFactory2::RequestLicKey](#requestlickey)|Cria e retorna uma chave de licença.|

## <a name="remarks"></a>Comentários

`CComClassFactory2` implementa o [IClassFactory2](/windows/desktop/api/ocidl/nn-ocidl-iclassfactory2) interface, que é uma extensão de [IClassFactory](/windows/desktop/api/unknwnbase/nn-unknwnbase-iclassfactory). `IClassFactory2` criação do objeto de controles por meio de uma licença. Uma classe factory executando em um computador licenciado pode fornecer uma chave de licença de tempo de execução. Essa chave de licença permite que um aplicativo instanciar objetos quando não existe uma licença completa de máquina.

Objetos ATL normalmente adquirem uma fábrica de classes derivando [CComCoClass](../../atl/reference/ccomcoclass-class.md). Essa classe inclui a macro [DECLARE_CLASSFACTORY](aggregation-and-class-factory-macros.md#declare_classfactory), que declara [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) porque a fábrica de classe padrão. Para usar `CComClassFactory2`, especifique o [DECLARE_CLASSFACTORY2](aggregation-and-class-factory-macros.md#declare_classfactory2) macro na definição de classe do objeto. Por exemplo:

[!code-cpp[NVC_ATL_COM#2](../../atl/codesnippet/cpp/ccomclassfactory2-class_1.h)]

`CMyLicense`, o parâmetro de modelo `CComClassFactory2`, deve implementar as funções estáticas `VerifyLicenseKey`, `GetLicenseKey`, e `IsLicenseValid`. Este é um exemplo de uma classe simples de licença:

[!code-cpp[NVC_ATL_COM#3](../../atl/codesnippet/cpp/ccomclassfactory2-class_2.h)]

`CComClassFactory2` deriva de ambos `CComClassFactory2Base` e *licença*. `CComClassFactory2Base`, por sua vez, deriva `IClassFactory2` e `CComObjectRootEx< CComGlobalsThreadModel >`.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CComObjectRootBase`

`license`

[CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)

`IClassFactory2`

`CComClassFactory2`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="createinstance"></a>  CComClassFactory2::CreateInstance

Cria um objeto do CLSID especificado e recupera um ponteiro de interface para esse objeto.

```
STDMETHOD(CreateInstance)(LPUNKNOWN pUnkOuter, REFIID riid, void** ppvObj);
```

### <a name="parameters"></a>Parâmetros

*pUnkOuter*<br/>
[in] Se o objeto está sendo criado como parte de uma agregação, em seguida *pUnkOuter* deve ser o externo desconhecido. Caso contrário, *pUnkOuter* deve ser NULL.

*riid*<br/>
[in] O IID da interface solicitada. Se *pUnkOuter* não for nulo, *riid* deve ser `IID_IUnknown`.

*ppvObj*<br/>
[out] Um ponteiro para o ponteiro de interface identificado pelo *riid*. Se o objeto não dá suporte a essa interface, *ppvObj* é definido como NULL.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Requer que o computador estar totalmente licenciados. Se uma licença de máquina completa não existir, chamar [CreateInstanceLic](#createinstancelic).

##  <a name="createinstancelic"></a>  CComClassFactory2::CreateInstanceLic

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

*pUnkOuter*<br/>
[in] Se o objeto está sendo criado como parte de uma agregação, em seguida *pUnkOuter* deve ser o externo desconhecido. Caso contrário, *pUnkOuter* deve ser NULL.

*pUnkReserved*<br/>
[in] Não usado. Precisa ser NULL.

*riid*<br/>
[in] O IID da interface solicitada. Se *pUnkOuter* não for nulo, *riid* deve ser `IID_IUnknown`.

*bstrKey*<br/>
[in] A chave de licença de tempo de execução obtido anteriormente de uma chamada para `RequestLicKey`. Essa chave é necessária para criar o objeto.

*ppvObject*<br/>
[out] Um ponteiro para o ponteiro de interface especificado por *riid*. Se o objeto não dá suporte a essa interface, *ppvObject* é definido como NULL.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Você pode obter uma chave de licença usando [RequestLicKey](#requestlickey). Para criar um objeto em um computador sem licença, você deve chamar `CreateInstanceLic`.

##  <a name="getlicinfo"></a>  CComClassFactory2::GetLicInfo

Preenche um [LICINFO](/windows/desktop/api/ocidl/ns-ocidl-taglicinfo) recursos de licença da estrutura com informações que descrevem a fábrica de classes.

```
STDMETHOD(GetLicInfo)(LICINFO* pLicInfo);
```

### <a name="parameters"></a>Parâmetros

*pLicInfo*<br/>
[out] Ponteiro para um `LICINFO` estrutura.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

O `fRuntimeKeyAvail` membro dessa estrutura indica se, dada uma chave de licença, a fábrica de classes permite que objetos a serem criados em uma máquina não licenciada. O *fLicVerified* membro indica se uma licença de máquina completo existe.

##  <a name="lockserver"></a>  CComClassFactory2::LockServer

Incrementa e decrementa a módulo contagem de bloqueio, chamando `_Module::Lock` e `_Module::Unlock`, respectivamente.

```
STDMETHOD(LockServer)(BOOL fLock);
```

### <a name="parameters"></a>Parâmetros

*fLock*<br/>
[in] Se for TRUE, a contagem de bloqueio é aumentada. Caso contrário, a contagem de bloqueio é reduzida.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

`_Module` refere-se à instância global do [CComModule](../../atl/reference/ccommodule-class.md) ou a uma classe derivada.

Chamar `LockServer` permite que um cliente retenham uma fábrica de classes para que vários objetos podem ser criados rapidamente.

##  <a name="requestlickey"></a>  CComClassFactory2::RequestLicKey

Cria e retorna uma chave de licença, desde que o `fRuntimeKeyAvail` membro a [LICINFO](/windows/desktop/api/ocidl/ns-ocidl-taglicinfo) estrutura é TRUE.

```
STDMETHOD(RequestLicKey)(DWORD dwReserved, BSTR* pbstrKey);
```

### <a name="parameters"></a>Parâmetros

*dwReserved*<br/>
[in] Não usado. Deve ser zero.

*pbstrKey*<br/>
[out] Ponteiro para a chave de licença.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Uma chave de licença é necessária para chamar [CreateInstanceLic](#createinstancelic) para criar um objeto em uma máquina não licenciada. Se `fRuntimeKeyAvail` for FALSE, em seguida, os objetos podem ser criados somente em um computador totalmente licenciado.

Chame [GetLicInfo](#getlicinfo) para recuperar o valor de `fRuntimeKeyAvail`.

## <a name="see-also"></a>Consulte também

[Classe CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md)<br/>
[Classe CComClassFactorySingleton](../../atl/reference/ccomclassfactorysingleton-class.md)<br/>
[Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)<br/>
[CComGlobalsThreadModel](atl-typedefs.md#ccomglobalsthreadmodel)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
