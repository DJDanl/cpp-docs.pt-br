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
ms.openlocfilehash: 779e143094760c7bd868ad33f590f7fd8f004762
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329730"
---
# <a name="idispeventsimpleimpl-class"></a>Classe IDispEventSimpleImpl

Esta classe fornece implementações dos `IDispatch` métodos, sem obter informações de tipo de uma biblioteca de tipos.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <UINT nID, class T, const IID* pdiid>
class ATL_NO_VTABLE IDispEventSimpleImpl : public _IDispEventLocator<nID, pdiid>
```

#### <a name="parameters"></a>Parâmetros

*nID*<br/>
Um identificador único para o objeto de origem. Quando `IDispEventSimpleImpl` for a classe base para um controle composto, use o ID de recurso do controle contido desejado para este parâmetro. Em outros casos, use um inteiro positivo arbitrário.

*T*<br/>
A classe do usuário, que `IDispEventSimpleImpl`é derivada de .

*Pdiid*<br/>
O ponteiro para o IID da disinterface de evento implementado por esta classe.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IDispEventSimpleImpl::Aconselhar](#advise)|Estabelece uma conexão com a fonte de evento padrão.|
|[IDispEventSimpleImpl::DispEventAdvise](#dispeventadvise)|Estabelece uma conexão com a fonte do evento.|
|[IDispEventSimpleImpl::DispEventUnadvise](#dispeventunadvise)|Quebra a conexão com a fonte do evento.|
|[IDispEventSimpleImpl::GetIDsOfNames](#getidsofnames)|Volta E_NOTIMPL.|
|[IDispEventSimpleImpl::GetTypeInfo](#gettypeinfo)|Volta E_NOTIMPL.|
|[IDispEventSimpleImpl::GetTypeInfoCount](#gettypeinfocount)|Volta E_NOTIMPL.|
|[IDispEventSimpleImpl::Invocar](#invoke)|Chama os manipuladores de eventos listados no mapa do dissipador de eventos.|
|[IDispEventSimpleImpl::Unadvise](#unadvise)|Quebra a conexão com a fonte de evento padrão.|

## <a name="remarks"></a>Comentários

`IDispEventSimpleImpl`fornece uma maneira de implementar uma dispinterface de evento sem exigir que você forneça código de implementação para cada método/evento nessa interface. `IDispEventSimpleImpl`fornece implementações `IDispatch` dos métodos. Você só precisa fornecer implementações para os eventos que você está interessado em lidar.

`IDispEventSimpleImpl`trabalha em conjunto com o mapa do dissipador de eventos em sua classe para encaminhar eventos para a função de manipulador apropriado. Para usar esta classe:

- Adicione uma [SINK_ENTRY_INFO](composite-control-macros.md#sink_entry_info) macro ao mapa do dissipador de eventos para cada evento em cada objeto que você deseja manusear.

- Fornecer informações do tipo para cada evento passando um ponteiro para uma estrutura [_ATL_FUNC_INFO](../../atl/reference/atl-func-info-structure.md) como parâmetro para cada entrada. Na plataforma x86, `_ATL_FUNC_INFO.cc` o valor deve ser CC_CDECL com o método de chamada da função de retorno de __stdcall.

- Ligue para [o DispEventAdvise](#dispeventadvise) para estabelecer a conexão entre o objeto de origem e a classe base.

- Ligue para [o DispEventUnadvise](#dispeventunadvise) para interromper a conexão.

Você deve `IDispEventSimpleImpl` derivar de (usando um valor único para *nID*) para cada objeto para o qual você precisa lidar com eventos. Você pode reutilizar a classe base desaconselhando contra um objeto de origem e aconselhando contra um objeto de origem diferente, mas o `IDispEventSimpleImpl` número máximo de objetos de origem que podem ser manuseados por um único objeto de uma só vez é limitado pelo número de classes base.

`IDispEventSimplImpl`fornece a mesma funcionalidade que [o IDispEventImpl,](../../atl/reference/idispeventimpl-class.md)exceto que não obtenha informações de tipo sobre a interface de uma biblioteca de tipos. Os assistentes geram código `IDispEventImpl`baseado apenas em `IDispEventSimpleImpl` , mas você pode usar adicionando o código manualmente. Use `IDispEventSimpleImpl` quando você não tiver uma biblioteca de tipos descrevendo a interface do evento ou quiser evitar a sobrecarga associada ao uso da biblioteca do tipo.

> [!NOTE]
> `IDispEventImpl`e `IDispEventSimpleImpl` fornecer sua `IUnknown::QueryInterface` própria implementação de permitir que cada `IDispEventImpl` ou `IDispEventSimpleImpl` classe base atue como uma identidade COM separada, ao mesmo tempo em que permite acesso direto aos membros da classe em seu objeto COM principal.

A implementação do evento ACTIVEX no CE ATL só suporta valores de retorno do tipo HRESULT ou vazios de seus métodos de manipulador de eventos; qualquer outro valor de retorno não é suportado e seu comportamento é indefinido.

Para obter mais informações, consulte [Suporte IDispEventImpl](../../atl/supporting-idispeventimpl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`_IDispEvent`

`_IDispEventLocator`

`IDispEventSimpleImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="idispeventsimpleimpladvise"></a><a name="advise"></a>IDispEventSimpleImpl::Aconselhar

Chame este método para estabelecer uma conexão com a fonte de evento representada pelo *pUnk*.

```
HRESULT Advise(IUnknown* pUnk);
```

### <a name="parameters"></a>Parâmetros

*Punk*<br/>
[em] Um ponteiro `IUnknown` para a interface do objeto de origem do evento.

### <a name="return-value"></a>Valor retornado

S_OK ou qualquer falha no valor do HRESULT.

### <a name="remarks"></a>Comentários

Uma vez que a conexão seja estabelecida, os eventos disparados do *pUnk* serão encaminhados para os manipuladores da sua classe por meio do mapa do dissipador de eventos.

> [!NOTE]
> Se sua classe deriva `IDispEventSimpleImpl` de várias classes, você precisará desambiguar chamadas para este método, examinando a chamada com a classe base específica em que você está interessado.

`Advise`estabelece uma conexão com a fonte de evento padrão, obtém o IID da fonte de evento padrão do objeto, conforme determinado por [AtlGetObjectSourceInterface](composite-control-global-functions.md#atlgetobjectsourceinterface).

## <a name="idispeventsimpleimpldispeventadvise"></a><a name="dispeventadvise"></a>IDispEventSimpleImpl::DispEventAdvise

Chame este método para estabelecer uma conexão com a fonte de evento representada pelo *pUnk*.

```
HRESULT DispEventAdvise(IUnknown* pUnk  const IID* piid);
```

### <a name="parameters"></a>Parâmetros

*Punk*<br/>
[em] Um ponteiro `IUnknown` para a interface do objeto de origem do evento.

*Piid*<br/>
Um ponteiro para o IID do objeto de origem do evento.

### <a name="return-value"></a>Valor retornado

S_OK ou qualquer falha no valor do HRESULT.

### <a name="remarks"></a>Comentários

Posteriormente, os eventos disparados do *pUnk* serão encaminhados para manipuladores em sua classe por meio do mapa do dissipador de eventos.

> [!NOTE]
> Se sua classe deriva `IDispEventSimpleImpl` de várias classes, você precisará desambiguar chamadas para este método, examinando a chamada com a classe base específica em que você está interessado.

`DispEventAdvise`estabelece uma conexão com a `pdiid`fonte de evento especificada em .

## <a name="idispeventsimpleimpldispeventunadvise"></a><a name="dispeventunadvise"></a>IDispEventSimpleImpl::DispEventUnadvise

Quebra a conexão com a fonte de evento representada pelo *pUnk*.

```
HRESULT DispEventUnadvise(IUnknown* pUnk  const IID* piid);
```

### <a name="parameters"></a>Parâmetros

*Punk*<br/>
[em] Um ponteiro `IUnknown` para a interface do objeto de origem do evento.

*Piid*<br/>
Um ponteiro para o IID do objeto de origem do evento.

### <a name="return-value"></a>Valor retornado

S_OK ou qualquer falha no valor do HRESULT.

### <a name="remarks"></a>Comentários

Uma vez que a conexão seja quebrada, os eventos não serão mais encaminhados para as funções do manipulador listadas no mapa do dissipador de eventos.

> [!NOTE]
> Se sua classe deriva `IDispEventSimpleImpl` de várias classes, você precisará desambiguar chamadas para este método, examinando a chamada com a classe base específica em que você está interessado.

`DispEventAdvise`quebra uma conexão que foi estabelecida com `pdiid`a fonte de evento especificada em .

## <a name="idispeventsimpleimplgetidsofnames"></a><a name="getidsofnames"></a>IDispEventSimpleImpl::GetIDsOfNames

Essa implementação de `IDispatch::GetIDsOfNames` retornos E_NOTIMPL.

```
STDMETHOD(GetIDsOfNames)(
    REFIID /* riid */,
    LPOLESTR* /* rgszNames */,
    UINT /* cNames */,
    LCID /* lcid */,
    DISPID* /* rgdispid */);
```

### <a name="remarks"></a>Comentários

Consulte [IDispatch::GetIDsOfNames](/windows/win32/api/oaidl/nf-oaidl-idispatch-getidsofnames) no Windows SDK.

## <a name="idispeventsimpleimplgettypeinfo"></a><a name="gettypeinfo"></a>IDispEventSimpleImpl::GetTypeInfo

Essa implementação de `IDispatch::GetTypeInfo` retornos E_NOTIMPL.

```
STDMETHOD(GetTypeInfo)(
    UINT /* itinfo */,
    LCID /* lcid */,
    ITypeInfo** /* pptinfo */);
```

### <a name="remarks"></a>Comentários

Consulte [IDispatch::GetTypeInfo](/windows/win32/api/oaidl/nf-oaidl-idispatch-gettypeinfo) no Windows SDK.

## <a name="idispeventsimpleimplgettypeinfocount"></a><a name="gettypeinfocount"></a>IDispEventSimpleImpl::GetTypeInfoCount

Essa implementação de `IDispatch::GetTypeInfoCount` retornos E_NOTIMPL.

```
STDMETHOD(GetTypeInfoCount)(UINT* /* pctinfo */);
```

### <a name="remarks"></a>Comentários

Consulte [IDispatch::GetTypeInfoCount](/windows/win32/api/oaidl/nf-oaidl-idispatch-gettypeinfocount) no Windows SDK.

## <a name="idispeventsimpleimplinvoke"></a><a name="invoke"></a>IDispEventSimpleImpl::Invocar

Esta implementação de `IDispatch::Invoke` chamadas os manipuladores de eventos listados no mapa do dissipador de eventos.

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

Consulte [IDispatch::Invoke](/windows/win32/api/oaidl/nf-oaidl-idispatch-invoke).

## <a name="idispeventsimpleimplunadvise"></a><a name="unadvise"></a>IDispEventSimpleImpl::Unadvise

Quebra a conexão com a fonte de evento representada pelo *pUnk*.

```
HRESULT Unadvise(IUnknown* pUnk);
```

### <a name="parameters"></a>Parâmetros

*Punk*<br/>
[em] Um ponteiro `IUnknown` para a interface do objeto de origem do evento.

### <a name="return-value"></a>Valor retornado

S_OK ou qualquer falha no valor do HRESULT.

### <a name="remarks"></a>Comentários

Uma vez que a conexão seja quebrada, os eventos não serão mais encaminhados para as funções do manipulador listadas no mapa do dissipador de eventos.

> [!NOTE]
> Se sua classe deriva `IDispEventSimpleImpl` de várias classes, você precisará desambiguar chamadas para este método, examinando a chamada com a classe base específica em que você está interessado.

`Unadvise`quebra uma conexão que foi estabelecida com `pdiid`a fonte de evento padrão especificada em .

`Unavise`quebra uma conexão com a fonte de evento padrão, obtém o IID da fonte de evento padrão do objeto, conforme determinado por [AtlGetObjectSourceInterface](composite-control-global-functions.md#atlgetobjectsourceinterface).

## <a name="see-also"></a>Confira também

[Estrutura _ATL_FUNC_INFO](../../atl/reference/atl-func-info-structure.md)<br/>
[Classe IDispatchImpl](../../atl/reference/idispatchimpl-class.md)<br/>
[Classe IDispEventImpl](../../atl/reference/idispeventimpl-class.md)<br/>
[Sink_entry_info](composite-control-macros.md#sink_entry_info)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
