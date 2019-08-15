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
ms.openlocfilehash: e34ebffc937c3e4ef1272fdf13ddcde7513d28e4
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69497466"
---
# <a name="ccomclassfactory2-class"></a>Classe CComClassFactory2

Essa classe implementa a interface [IClassFactory2](/windows/win32/api/ocidl/nn-ocidl-iclassfactory2) .

## <a name="syntax"></a>Sintaxe

```
template <class license>
class CComClassFactory2 : public IClassFactory2,
    public CComObjectRootEx<CComGlobalsThreadModel>,
    public license
```

#### <a name="parameters"></a>Parâmetros

*license*<br/>
Uma classe que implementa as seguintes funções estáticas:

- `static BOOL VerifyLicenseKey( BSTR bstr );`

- `static BOOL GetLicenseKey( DWORD dwReserved, BSTR * pBstr );`

- `static BOOL IsLicenseValid( );`

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComClassFactory2::CreateInstance](#createinstance)|Cria um objeto do CLSID especificado.|
|[CComClassFactory2::CreateInstanceLic](#createinstancelic)|Dada uma chave de licença, cria um objeto do CLSID especificado.|
|[CComClassFactory2::GetLicInfo](#getlicinfo)|Recupera informações que descrevem os recursos de licenciamento da fábrica de classes.|
|[CComClassFactory2::LockServer](#lockserver)|Bloqueia a fábrica de classes na memória.|
|[CComClassFactory2::RequestLicKey](#requestlickey)|Cria e retorna uma chave de licença.|

## <a name="remarks"></a>Comentários

`CComClassFactory2`implementa a interface [IClassFactory2](/windows/win32/api/ocidl/nn-ocidl-iclassfactory2) , que é uma extensão de [IClassFactory](/windows/win32/api/unknwnbase/nn-unknwnbase-iclassfactory). `IClassFactory2`controla a criação de objetos por meio de uma licença. Uma fábrica de classes em execução em uma máquina licenciada pode fornecer uma chave de licença em tempo de execução. Essa chave de licença permite que um aplicativo crie uma instância de objetos quando uma licença de computador completa não existir.

Os objetos ATL normalmente adquirem uma fábrica de classes derivando de [CComCoClass](../../atl/reference/ccomcoclass-class.md). Essa classe inclui a macro [DECLARE_CLASSFACTORY](aggregation-and-class-factory-macros.md#declare_classfactory), que declara [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) como a fábrica de classes padrão. Para usar `CComClassFactory2`, especifique a macro [DECLARE_CLASSFACTORY2](aggregation-and-class-factory-macros.md#declare_classfactory2) na definição de classe do seu objeto. Por exemplo:

[!code-cpp[NVC_ATL_COM#2](../../atl/codesnippet/cpp/ccomclassfactory2-class_1.h)]

`CMyLicense`, o parâmetro de modelo `CComClassFactory2`para, deve implementar as funções `VerifyLicenseKey`estáticas, `IsLicenseValid` `GetLicenseKey`e. Veja a seguir um exemplo de uma classe de licença simples:

[!code-cpp[NVC_ATL_COM#3](../../atl/codesnippet/cpp/ccomclassfactory2-class_2.h)]

`CComClassFactory2`deriva de ambas as `CComClassFactory2Base` *licenças*e. `CComClassFactory2Base`, por sua vez, deriva de `IClassFactory2` e `CComObjectRootEx< CComGlobalsThreadModel >`.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CComObjectRootBase`

`license`

[CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)

`IClassFactory2`

`CComClassFactory2`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="createinstance"></a>  CComClassFactory2::CreateInstance

Cria um objeto do CLSID especificado e recupera um ponteiro de interface para esse objeto.

```
STDMETHOD(CreateInstance)(LPUNKNOWN pUnkOuter, REFIID riid, void** ppvObj);
```

### <a name="parameters"></a>Parâmetros

*pUnkOuter*<br/>
no Se o objeto estiver sendo criado como parte de uma agregação, *pUnkOuter* deverá ser o desconhecido como externo. Caso contrário, *pUnkOuter* deverá ser nulo.

*riid*<br/>
no O IID da interface solicitada. Se *pUnkOuter* for não nulo, *riid* deverá ser `IID_IUnknown`.

*ppvObj*<br/>
fora Um ponteiro para o ponteiro de interface identificado por *riid*. Se o objeto não oferecer suporte a essa interface, *ppvObj* será definido como NULL.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Exige que o computador seja totalmente licenciado. Se uma licença de computador completa não existir, chame [CreateInstanceLic](#createinstancelic).

##  <a name="createinstancelic"></a>  CComClassFactory2::CreateInstanceLic

Semelhante a [CreateInstance](#createinstance), exceto que `CreateInstanceLic` requer uma chave de licença.

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
no Se o objeto estiver sendo criado como parte de uma agregação, *pUnkOuter* deverá ser o desconhecido como externo. Caso contrário, *pUnkOuter* deverá ser nulo.

*pUnkReserved*<br/>
no Não usado. Precisa ser NULL.

*riid*<br/>
no O IID da interface solicitada. Se *pUnkOuter* for não nulo, *riid* deverá ser `IID_IUnknown`.

*bstrKey*<br/>
no A chave de licença de tempo de execução obtida anteriormente de uma `RequestLicKey`chamada para. Essa chave é necessária para criar o objeto.

*ppvObject*<br/>
fora Um ponteiro para o ponteiro de interface especificado por *riid*. Se o objeto não oferecer suporte a essa interface, *ppvObject* será definido como NULL.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Você pode obter uma chave de licença usando [RequestLicKey](#requestlickey). Para criar um objeto em um computador sem licença, você deve chamar `CreateInstanceLic`.

##  <a name="getlicinfo"></a>  CComClassFactory2::GetLicInfo

Preenche uma estrutura [LICINFO](/windows/win32/api/ocidl/ns-ocidl-licinfo) com informações que descrevem os recursos de licenciamento de fábrica de classes.

```
STDMETHOD(GetLicInfo)(LICINFO* pLicInfo);
```

### <a name="parameters"></a>Parâmetros

*pLicInfo*<br/>
fora Ponteiro para uma `LICINFO` estrutura.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

O `fRuntimeKeyAvail` membro dessa estrutura indica se, dada uma chave de licença, a fábrica de classes permite que os objetos sejam criados em um computador não licenciado. O membro *fLicVerified* indica se existe uma licença de computador completa.

##  <a name="lockserver"></a>  CComClassFactory2::LockServer

Incrementa e decrementa a contagem de bloqueios de módulo chamando `_Module::Lock` e `_Module::Unlock`, respectivamente.

```
STDMETHOD(LockServer)(BOOL fLock);
```

### <a name="parameters"></a>Parâmetros

*fLock*<br/>
no Se for TRUE, a contagem de bloqueios será incrementada; caso contrário, a contagem de bloqueios será diminuída.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

`_Module`refere-se à instância global de [CComModule](../../atl/reference/ccommodule-class.md) ou a uma classe derivada dela.

A `LockServer` chamada permite que um cliente mantenha em uma fábrica de classes para que vários objetos possam ser criados rapidamente.

##  <a name="requestlickey"></a>  CComClassFactory2::RequestLicKey

Cria e retorna uma chave de licença, desde que `fRuntimeKeyAvail` o membro da estrutura [LICINFO](/windows/win32/api/ocidl/ns-ocidl-licinfo) seja verdadeiro.

```
STDMETHOD(RequestLicKey)(DWORD dwReserved, BSTR* pbstrKey);
```

### <a name="parameters"></a>Parâmetros

*dwReserved*<br/>
no Não usado. Deve ser zero.

*pbstrKey*<br/>
fora Ponteiro para a chave de licença.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Uma chave de licença é necessária para chamar [CreateInstanceLic](#createinstancelic) para criar um objeto em um computador sem licença. Se `fRuntimeKeyAvail` for false, os objetos só poderão ser criados em um computador totalmente licenciado.

Chame [GetLicInfo](#getlicinfo) para recuperar o valor de `fRuntimeKeyAvail`.

## <a name="see-also"></a>Consulte também

[Classe CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md)<br/>
[Classe CComClassFactorySingleton](../../atl/reference/ccomclassfactorysingleton-class.md)<br/>
[Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)<br/>
[CComGlobalsThreadModel](atl-typedefs.md#ccomglobalsthreadmodel)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
