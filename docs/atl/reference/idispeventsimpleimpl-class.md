---
title: Classe IDispEventSimpleImpl
ms.date: 11/04/2016
f1_keywords:
- IDispEventSimpleImpl
- ATLCOM/ATL::IDispEventSimpleImpl
- ATLCOM/ATL::IDispEventSimpleImpl::Advise
- ATLCOM/ATL::IDispEventSimpleImpl::DispEventAdvise
- ATLCOM/ATL::IDispEventSimpleImpl::DispEventUnadvise
- ATLCOM/ATL::IDispEventSimpleImpl::GetIDsOfNames
- ATLCOM/ATL::IDispEventSimpleImpl::GetTypeInfo
- ATLCOM/ATL::IDispEventSimpleImpl::GetTypeInfoCount
- ATLCOM/ATL::IDispEventSimpleImpl::Invoke
- ATLCOM/ATL::IDispEventSimpleImpl::Unadvise
helpviewer_keywords:
- IDispEventSimpleImpl class
ms.assetid: 971d82b7-a921-47fa-a4d8-909bed377ab0
ms.openlocfilehash: a0be64cca6725c0ad0852752e6c6c440377c9e7a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50447899"
---
# <a name="idispeventsimpleimpl-class"></a>Classe IDispEventSimpleImpl

Essa classe fornece implementações do `IDispatch` métodos sem obter informações de tipo de uma biblioteca de tipos.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <UINT nID, class T, const IID* pdiid>
class ATL_NO_VTABLE IDispEventSimpleImpl : public _IDispEventLocator<nID, pdiid>
```

#### <a name="parameters"></a>Parâmetros

*nID*<br/>
Um identificador exclusivo para o objeto de origem. Quando `IDispEventSimpleImpl` é a classe base para um controle de composição, use a ID de recurso do controle independente desejado para esse parâmetro. Em outros casos, use um inteiro positivo arbitrário.

*T*<br/>
A classe do usuário, que é derivada de `IDispEventSimpleImpl`.

*pdiid*<br/>
O ponteiro para o IID da dispinterface de eventos implementada por esta classe.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[IDispEventSimpleImpl::Advise](#advise)|Estabelece uma conexão com a origem do evento padrão.|
|[IDispEventSimpleImpl::DispEventAdvise](#dispeventadvise)|Estabelece uma conexão com a origem do evento.|
|[IDispEventSimpleImpl::DispEventUnadvise](#dispeventunadvise)|Interrompe a conexão com a origem do evento.|
|[IDispEventSimpleImpl::GetIDsOfNames](#getidsofnames)|Retornará E_NOTIMPL.|
|[IDispEventSimpleImpl::GetTypeInfo](#gettypeinfo)|Retornará E_NOTIMPL.|
|[IDispEventSimpleImpl::GetTypeInfoCount](#gettypeinfocount)|Retornará E_NOTIMPL.|
|[IDispEventSimpleImpl::Invoke](#invoke)|Chama os manipuladores de eventos no evento listado mapa coletor.|
|[IDispEventSimpleImpl::Unadvise](#unadvise)|Interrompe a conexão com a origem do evento padrão.|

## <a name="remarks"></a>Comentários

`IDispEventSimpleImpl` Fornece uma maneira de implementar um dispinterface de eventos sem exigir que você forneça o código de implementação para cada método/evento nessa interface. `IDispEventSimpleImpl` fornece implementações do `IDispatch` métodos. Você só precisa fornecer implementações para os eventos que você está interessado na manipulação de.

`IDispEventSimpleImpl` funciona em conjunto com o mapa de coletor de eventos em sua classe para eventos de rota para a função de manipulador apropriado. Para usar essa classe:

- Adicionar um [SINK_ENTRY_INFO](composite-control-macros.md#sink_entry_info) macro para o mapa do coletor de evento para cada evento em cada objeto que você deseja manipular.

- Fornecer informações de tipo para cada evento, passando um ponteiro para um [atl_func_info](../../atl/reference/atl-func-info-structure.md) estrutura como um parâmetro para cada entrada. Em x86 plataforma, o `_ATL_FUNC_INFO.cc` valor deve ser CC_CDECL com a função de retorno de chamada chamando o método de stdcall.

- Chame [DispEventAdvise](#dispeventadvise) para estabelecer a conexão entre o objeto de origem e a classe base.

- Chame [DispEventUnadvise](#dispeventunadvise) para interromper a conexão.

Você deve derivar de `IDispEventSimpleImpl` (usando um valor exclusivo para *nID*) para cada objeto para o qual você precisa manipular eventos. Você pode reutilizar a classe base, unadvising no objeto de uma fonte informando, em seguida, em relação a um objeto de fonte diferente, mas o número máximo de objetos de fonte que pode ser tratado por um único objeto simultaneamente é limitado pelo número de `IDispEventSimpleImpl` classes base.

`IDispEventSimplImpl` fornece a mesma funcionalidade que [IDispEventImpl](../../atl/reference/idispeventimpl-class.md), exceto que ele não obtém informações sobre a interface do tipo de uma biblioteca de tipos. Os assistentes de geram código com base apenas no `IDispEventImpl`, mas você pode usar `IDispEventSimpleImpl` adicionando o código manualmente. Use `IDispEventSimpleImpl` quando não tiver uma biblioteca de tipos que descreve a interface de eventos ou para evitar a sobrecarga associada usando a biblioteca de tipos.

> [!NOTE]
> `IDispEventImpl` e `IDispEventSimpleImpl` fornecer sua própria implementação de `IUnknown::QueryInterface` habilitando cada `IDispEventImpl` ou `IDispEventSimpleImpl` classe para agir como uma identidade COM separada e ainda permitir acesso direto aos membros de classe no objeto principal COM base.

Implementação de ATL CE do ActiveX evento coletores somente dá suporte a valores de retorno do tipo HRESULT ou void de seus métodos de manipulador de eventos; Não há suporte para qualquer outro valor de retorno e seu comportamento é indefinido.

Para obter mais informações, consulte [que dão suporte a IDispEventImpl](../../atl/supporting-idispeventimpl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`_IDispEvent`

`_IDispEventLocator`

`IDispEventSimpleImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="advise"></a>  IDispEventSimpleImpl::Advise

Chame esse método para estabelecer uma conexão com a origem do evento representada por *pUnk*.

```
HRESULT Advise(IUnknown* pUnk);
```

### <a name="parameters"></a>Parâmetros

*pUnk*<br/>
[in] Um ponteiro para o `IUnknown` interface do objeto de origem de evento.

### <a name="return-value"></a>Valor de retorno

S_OK ou qualquer valor HRESULT de falha.

### <a name="remarks"></a>Comentários

Quando a conexão é estabelecida, os eventos disparados de *pUnk* serão roteadas para manipuladores em sua classe por meio do mapa de coletor do evento.

> [!NOTE]
>  Se sua classe derivada de vários `IDispEventSimpleImpl` classes, você precisará resolver a ambiguidade de chamadas para esse método defina o escopo a chamada com a classe base específica que você está interessado.

`Advise` estabelece uma conexão com a origem do evento padrão, ele obtém a IID da origem do evento padrão do objeto, conforme determinado pela [AtlGetObjectSourceInterface](composite-control-global-functions.md#atlgetobjectsourceinterface).

##  <a name="dispeventadvise"></a>  IDispEventSimpleImpl::DispEventAdvise

Chame esse método para estabelecer uma conexão com a origem do evento representada por *pUnk*.

```
HRESULT DispEventAdvise(IUnknown* pUnk  const IID* piid);
```

### <a name="parameters"></a>Parâmetros

*pUnk*<br/>
[in] Um ponteiro para o `IUnknown` interface do objeto de origem de evento.

*piid*<br/>
Um ponteiro para o IID do objeto de origem de evento.

### <a name="return-value"></a>Valor de retorno

S_OK ou qualquer valor HRESULT de falha.

### <a name="remarks"></a>Comentários

Subsequentemente, os eventos são disparados na *pUnk* serão roteadas para manipuladores em sua classe por meio do mapa de coletor do evento.

> [!NOTE]
>  Se sua classe derivada de vários `IDispEventSimpleImpl` classes, você precisará resolver a ambiguidade de chamadas para esse método defina o escopo a chamada com a classe base específica que você está interessado.

`DispEventAdvise` estabelece uma conexão com a origem do evento especificada no `pdiid`.

##  <a name="dispeventunadvise"></a>  IDispEventSimpleImpl::DispEventUnadvise

Interrompe a conexão com a origem do evento representada por *pUnk*.

```
HRESULT DispEventUnadvise(IUnknown* pUnk  const IID* piid);
```

### <a name="parameters"></a>Parâmetros

*pUnk*<br/>
[in] Um ponteiro para o `IUnknown` interface do objeto de origem de evento.

*piid*<br/>
Um ponteiro para o IID do objeto de origem de evento.

### <a name="return-value"></a>Valor de retorno

S_OK ou qualquer valor HRESULT de falha.

### <a name="remarks"></a>Comentários

Depois que a conexão for interrompida, eventos não serão roteados para as funções do manipulador listadas no mapa de coletor do evento.

> [!NOTE]
>  Se sua classe derivada de vários `IDispEventSimpleImpl` classes, você precisará resolver a ambiguidade de chamadas para esse método defina o escopo a chamada com a classe base específica que você está interessado.

`DispEventAdvise` interrompe uma conexão que foi estabelecida com a origem do evento especificada no `pdiid`.

##  <a name="getidsofnames"></a>  IDispEventSimpleImpl::GetIDsOfNames

Essa implementação do `IDispatch::GetIDsOfNames` retornará E_NOTIMPL.

```
STDMETHOD(GetIDsOfNames)(
    REFIID /* riid */,
    LPOLESTR* /* rgszNames */,
    UINT /* cNames */,
    LCID /* lcid */,
    DISPID* /* rgdispid */);
```

### <a name="remarks"></a>Comentários

Ver [IDispatch::GetIDsOfNames](/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-getidsofnames) no Windows SDK.

##  <a name="gettypeinfo"></a>  IDispEventSimpleImpl::GetTypeInfo

Essa implementação do `IDispatch::GetTypeInfo` retornará E_NOTIMPL.

```
STDMETHOD(GetTypeInfo)(
    UINT /* itinfo */,
    LCID /* lcid */,
    ITypeInfo** /* pptinfo */);
```

### <a name="remarks"></a>Comentários

Ver [IDispatch:: GetTypeInfo](/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-gettypeinfo) no Windows SDK.

##  <a name="gettypeinfocount"></a>  IDispEventSimpleImpl::GetTypeInfoCount

Essa implementação do `IDispatch::GetTypeInfoCount` retornará E_NOTIMPL.

```
STDMETHOD(GetTypeInfoCount)(UINT* /* pctinfo */);
```

### <a name="remarks"></a>Comentários

Ver [IDispatch::GetTypeInfoCount](/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-gettypeinfocount) no Windows SDK.

##  <a name="invoke"></a>  IDispEventSimpleImpl::Invoke

Essa implementação do `IDispatch::Invoke` chamadas os manipuladores de eventos no evento listado mapa coletor.

```
STDMETHOD(Invoke)(
    DISPID dispidMember,
    REFIID /* riid */,
    LCID lcid,
    WORD /* wFlags */,
    DISPPARMS* pdispparams,
    VARIANT* pvarResult,
    EXCEPINFO* /* pexcepinfo */,
    UINT* /* puArgErr */);
```

### <a name="remarks"></a>Comentários

Ver [IDispatch:: Invoke](/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke).

##  <a name="unadvise"></a>  IDispEventSimpleImpl::Unadvise

Interrompe a conexão com a origem do evento representada por *pUnk*.

```
HRESULT Unadvise(IUnknown* pUnk);
```

### <a name="parameters"></a>Parâmetros

*pUnk*<br/>
[in] Um ponteiro para o `IUnknown` interface do objeto de origem de evento.

### <a name="return-value"></a>Valor de retorno

S_OK ou qualquer valor HRESULT de falha.

### <a name="remarks"></a>Comentários

Depois que a conexão for interrompida, eventos não serão roteados para as funções do manipulador listadas no mapa de coletor do evento.

> [!NOTE]
>  Se sua classe derivada de vários `IDispEventSimpleImpl` classes, você precisará resolver a ambiguidade de chamadas para esse método defina o escopo a chamada com a classe base específica que você está interessado.

`Unadvise` interrompe uma conexão que foi estabelecida com a origem do evento padrão especificada no `pdiid`.

`Unavise` divide uma conexão com a origem do evento padrão, ele obtém a IID da origem do evento padrão do objeto, conforme determinado pela [AtlGetObjectSourceInterface](composite-control-global-functions.md#atlgetobjectsourceinterface).

## <a name="see-also"></a>Consulte também

[Estrutura _ATL_FUNC_INFO](../../atl/reference/atl-func-info-structure.md)<br/>
[Classe IDispatchImpl](../../atl/reference/idispatchimpl-class.md)<br/>
[Classe IDispEventImpl](../../atl/reference/idispeventimpl-class.md)<br/>
[SINK_ENTRY_INFO](composite-control-macros.md#sink_entry_info)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
