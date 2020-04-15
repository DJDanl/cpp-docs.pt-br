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
ms.openlocfilehash: 0cb2064cfaea6317c4522ff917f3963fca2219b8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81321008"
---
# <a name="ccomclassfactory2-class"></a>Classe CComClassFactory2

Esta classe implementa a interface [IClassFactory2.](/windows/win32/api/ocidl/nn-ocidl-iclassfactory2)

## <a name="syntax"></a>Sintaxe

```
template <class license>
class CComClassFactory2 : public IClassFactory2,
    public CComObjectRootEx<CComGlobalsThreadModel>,
    public license
```

#### <a name="parameters"></a>Parâmetros

*Licença*<br/>
Uma classe que implementa as seguintes funções estáticas:

- `static BOOL VerifyLicenseKey( BSTR bstr );`

- `static BOOL GetLicenseKey( DWORD dwReserved, BSTR * pBstr );`

- `static BOOL IsLicenseValid( );`

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComClassFactory2::CreateInstance](#createinstance)|Cria um objeto do CLSID especificado.|
|[CComClassFactory2::CreateInstanceLic](#createinstancelic)|Dada uma chave de licença, cria um objeto do CLSID especificado.|
|[CComClassFactory2::GetlicInfo](#getlicinfo)|Recupera informações descrevendo os recursos de licenciamento da fábrica de classes.|
|[CComClassFactory2::LockServer](#lockserver)|Bloqueia a fábrica de classe na memória.|
|[CComClassFactory2::Requestlickey](#requestlickey)|Cria e devolve uma chave de licença.|

## <a name="remarks"></a>Comentários

`CComClassFactory2`implementa a interface [IClassFactory2,](/windows/win32/api/ocidl/nn-ocidl-iclassfactory2) que é uma extensão do [IClassFactory](/windows/win32/api/unknwnbase/nn-unknwnbase-iclassfactory). `IClassFactory2`controla a criação de objetos através de uma licença. Uma fábrica de classe executando em uma máquina licenciada pode fornecer uma chave de licença em tempo de execução. Esta chave de licença permite que um aplicativo instancia objetos quando uma licença de máquina completa não existe.

Os objetos ATL normalmente adquirem uma fábrica de classe derivando do [CComCoClass](../../atl/reference/ccomcoclass-class.md). Esta classe inclui o [DECLARE_CLASSFACTORY](aggregation-and-class-factory-macros.md#declare_classfactory)de macro , que declara [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) como a fábrica de classe padrão. Para `CComClassFactory2`usar, especifique a [DECLARE_CLASSFACTORY2](aggregation-and-class-factory-macros.md#declare_classfactory2) macro na definição de classe do objeto. Por exemplo:

[!code-cpp[NVC_ATL_COM#2](../../atl/codesnippet/cpp/ccomclassfactory2-class_1.h)]

`CMyLicense`, o parâmetro `CComClassFactory2`de modelo para , `VerifyLicenseKey` `GetLicenseKey`deve `IsLicenseValid`implementar as funções estáticas, e . A seguir, um exemplo de uma classe de licença simples:

[!code-cpp[NVC_ATL_COM#3](../../atl/codesnippet/cpp/ccomclassfactory2-class_2.h)]

`CComClassFactory2`deriva de `CComClassFactory2Base` ambos e *licença*. `CComClassFactory2Base`, por sua vez, deriva de `IClassFactory2` e `CComObjectRootEx< CComGlobalsThreadModel >`.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CComObjectRootBase`

`license`

[Ccomobjectrootex](../../atl/reference/ccomobjectrootex-class.md)

`IClassFactory2`

`CComClassFactory2`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="ccomclassfactory2createinstance"></a><a name="createinstance"></a>CComClassFactory2::CreateInstance

Cria um objeto do CLSID especificado e recupera um ponteiro de interface para este objeto.

```
STDMETHOD(CreateInstance)(LPUNKNOWN pUnkOuter, REFIID riid, void** ppvObj);
```

### <a name="parameters"></a>Parâmetros

*Punkouter*<br/>
[em] Se o objeto está sendo criado como parte de um agregado, então *pUnkOuter* deve ser o desconhecido externo. Caso contrário, *pUnkOuter* deve ser NULO.

*riid*<br/>
[em] O IID da interface solicitada. Se *pUnkOuter* não for NULA, `IID_IUnknown` *riid* deve ser .

*Ppvobj*<br/>
[fora] Um ponteiro para o ponteiro de interface identificado por *riid*. Se o objeto não suportar essa interface, *ppvObj* será definido como NULL.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Requer que a máquina seja totalmente licenciada. Se uma licença completa da máquina não existir, chame [CreateInstanceLic](#createinstancelic).

## <a name="ccomclassfactory2createinstancelic"></a><a name="createinstancelic"></a>CComClassFactory2::CreateInstanceLic

Semelhante ao [CreateInstance,](#createinstance)exceto que `CreateInstanceLic` requer uma chave de licença.

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

*Punkouter*<br/>
[em] Se o objeto está sendo criado como parte de um agregado, então *pUnkOuter* deve ser o desconhecido externo. Caso contrário, *pUnkOuter* deve ser NULO.

*pUnkReserved*<br/>
[em] Não usado. Precisa ser NULL.

*riid*<br/>
[em] O IID da interface solicitada. Se *pUnkOuter* não for NULA, `IID_IUnknown` *riid* deve ser .

*bstrKey*<br/>
[em] A chave de licença de tempo de `RequestLicKey`execução obtida anteriormente a partir de uma chamada para . Esta chave é necessária para criar o objeto.

*Ppvobject*<br/>
[fora] Um ponteiro para o ponteiro de interface especificado por *riid*. Se o objeto não suportar essa interface, *ppvObject* será definido como NULL.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Você pode obter uma chave de licença usando [RequestLicKey](#requestlickey). Para criar um objeto em uma máquina não `CreateInstanceLic`licenciada, você deve ligar .

## <a name="ccomclassfactory2getlicinfo"></a><a name="getlicinfo"></a>CComClassFactory2::GetlicInfo

Preenche uma estrutura [LICINFO](/windows/win32/api/ocidl/ns-ocidl-licinfo) com informações que descrevem os recursos de licenciamento da fábrica de classe.

```
STDMETHOD(GetLicInfo)(LICINFO* pLicInfo);
```

### <a name="parameters"></a>Parâmetros

*pLicInfo*<br/>
[fora] Ponteiro para `LICINFO` uma estrutura.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

O `fRuntimeKeyAvail` membro desta estrutura indica se, dada uma chave de licença, a fábrica de classe permite que objetos sejam criados em uma máquina não licenciada. O membro *fLicVerified* indica se existe uma licença completa da máquina.

## <a name="ccomclassfactory2lockserver"></a><a name="lockserver"></a>CComClassFactory2::LockServer

Incrementa e diminui a contagem de `_Module::Lock` `_Module::Unlock`bloqueio do módulo por chamada e, respectivamente.

```
STDMETHOD(LockServer)(BOOL fLock);
```

### <a name="parameters"></a>Parâmetros

*Rebanho*<br/>
[em] Se TRUE, a contagem de bloqueios é incrementada; caso contrário, a contagem de bloqueios é decrementada.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

`_Module`refere-se à instância global do [CComModule](../../atl/reference/ccommodule-class.md) ou de uma classe derivada dele.

A `LockServer` chamada permite que um cliente se mantenha em uma fábrica de classes para que vários objetos possam ser criados rapidamente.

## <a name="ccomclassfactory2requestlickey"></a><a name="requestlickey"></a>CComClassFactory2::Requestlickey

Cria e devolve uma chave de `fRuntimeKeyAvail` licença, desde que o membro da estrutura [LICINFO](/windows/win32/api/ocidl/ns-ocidl-licinfo) seja VERDADEIRO.

```
STDMETHOD(RequestLicKey)(DWORD dwReserved, BSTR* pbstrKey);
```

### <a name="parameters"></a>Parâmetros

*dwReservado*<br/>
[em] Não usado. Deve ser zero.

*pbstrKey*<br/>
[fora] Ponteiro para a chave de licença.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Uma chave de licença é necessária para chamar [CreateInstanceLic](#createinstancelic) para criar um objeto em uma máquina não licenciada. Se `fRuntimeKeyAvail` for FALSO, então os objetos só podem ser criados em uma máquina totalmente licenciada.

Ligue para [o GetLicInfo](#getlicinfo) para recuperar o valor de `fRuntimeKeyAvail`.

## <a name="see-also"></a>Confira também

[Classe CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md)<br/>
[Classe CComClassFactorySingleton](../../atl/reference/ccomclassfactorysingleton-class.md)<br/>
[Classe CcomObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)<br/>
[Ccomglobalsthreadmodel](atl-typedefs.md#ccomglobalsthreadmodel)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
