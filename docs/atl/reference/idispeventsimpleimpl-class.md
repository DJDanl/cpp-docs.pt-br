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
ms.openlocfilehash: 3ceb436e4f20a17ecd086fb68f9c1cfdcbe0be3e
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79417645"
---
# <a name="idispeventsimpleimpl-class"></a>Classe IDispEventSimpleImpl

Essa classe fornece implementações dos métodos `IDispatch`, sem obter informações de tipo de uma biblioteca de tipos.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template <UINT nID, class T, const IID* pdiid>
class ATL_NO_VTABLE IDispEventSimpleImpl : public _IDispEventLocator<nID, pdiid>
```

#### <a name="parameters"></a>parâmetros

*nID*<br/>
Um identificador exclusivo para o objeto de origem. Quando `IDispEventSimpleImpl` é a classe base para um controle composto, use a ID de recurso do controle contido desejado para esse parâmetro. Em outros casos, use um número inteiro positivo arbitrário.

*T*<br/>
A classe do usuário, que é derivada de `IDispEventSimpleImpl`.

*pdiid*<br/>
O ponteiro para a IID da dispinterface do evento implementada por essa classe.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[IDispEventSimpleImpl:: Advise](#advise)|Estabelece uma conexão com a origem do evento padrão.|
|[IDispEventSimpleImpl::D ispEventAdvise](#dispeventadvise)|Estabelece uma conexão com a origem do evento.|
|[IDispEventSimpleImpl::D ispEventUnadvise](#dispeventunadvise)|Interrompe a conexão com a origem do evento.|
|[IDispEventSimpleImpl:: GetIDsOfNames](#getidsofnames)|Retorna E_NOTIMPL.|
|[IDispEventSimpleImpl:: GetTypeInfo](#gettypeinfo)|Retorna E_NOTIMPL.|
|[IDispEventSimpleImpl::GetTypeInfoCount](#gettypeinfocount)|Retorna E_NOTIMPL.|
|[IDispEventSimpleImpl:: Invoke](#invoke)|Chama os manipuladores de eventos listados no mapa do coletor de eventos.|
|[IDispEventSimpleImpl:: Unadvise](#unadvise)|Interrompe a conexão com a origem do evento padrão.|

## <a name="remarks"></a>Comentários

`IDispEventSimpleImpl` fornece uma maneira de implementar um dispinterface de evento sem exigir que você forneça o código de implementação para cada método/evento nessa interface. `IDispEventSimpleImpl` fornece implementações dos métodos `IDispatch`. Você só precisa fornecer implementações para os eventos que você está interessado em manipular.

`IDispEventSimpleImpl` trabalha em conjunto com o mapa do coletor de eventos em sua classe para rotear eventos para a função de manipulador apropriada. Para usar esta classe:

- Adicione uma macro [SINK_ENTRY_INFO](composite-control-macros.md#sink_entry_info) ao mapa do coletor de eventos para cada evento em cada objeto que você deseja manipular.

- Forneça informações de tipo para cada evento passando um ponteiro para uma estrutura de [_ATL_FUNC_INFO](../../atl/reference/atl-func-info-structure.md) como um parâmetro para cada entrada. Na plataforma x86, o valor de `_ATL_FUNC_INFO.cc` deve ser CC_CDECL com a função de retorno de chamada método de __stdcall.

- Chame [DispEventAdvise](#dispeventadvise) para estabelecer a conexão entre o objeto de origem e a classe base.

- Chame [DispEventUnadvise](#dispeventunadvise) para interromper a conexão.

Você deve derivar de `IDispEventSimpleImpl` (usando um valor exclusivo para *NID*) para cada objeto para o qual você precisa manipular eventos. Você pode reutilizar a classe base ao se desaconselhar em um objeto de origem, aconselhando em um objeto de origem diferente, mas o número máximo de objetos de origem que podem ser manipulados por um único objeto ao mesmo tempo é limitado pelo número de `IDispEventSimpleImpl` classes base.

`IDispEventSimplImpl` fornece a mesma funcionalidade que [IDispEventImpl](../../atl/reference/idispeventimpl-class.md), exceto pelo fato de não obter informações de tipo sobre a interface de uma biblioteca de tipos. Os assistentes geram código com base apenas em `IDispEventImpl`, mas você pode usar `IDispEventSimpleImpl` adicionando o código manualmente. Use `IDispEventSimpleImpl` quando você não tem uma biblioteca de tipos que descreve a interface de evento ou deseja evitar a sobrecarga associada ao uso da biblioteca de tipos.

> [!NOTE]
> `IDispEventImpl` e `IDispEventSimpleImpl` fornecem sua própria implementação de `IUnknown::QueryInterface` habilitando cada `IDispEventImpl` ou `IDispEventSimpleImpl` classe base para atuar como uma identidade COM separada e, ao mesmo tempo, permitir acesso direto a membros de classe em seu objeto COM principal.

A implementação da ATL CE dos coletores de eventos ActiveX dá suporte apenas a valores de retorno do tipo HRESULT ou void dos métodos do manipulador de eventos; qualquer outro valor de retorno não tem suporte e seu comportamento é indefinido.

Para obter mais informações, consulte [Supporting IDispEventImpl](../../atl/supporting-idispeventimpl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`_IDispEvent`

`_IDispEventLocator`

`IDispEventSimpleImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="advise"></a>IDispEventSimpleImpl:: Advise

Chame esse método para estabelecer uma conexão com a origem do evento representada por *punk*.

```
HRESULT Advise(IUnknown* pUnk);
```

### <a name="parameters"></a>parâmetros

*pUnk*<br/>
no Um ponteiro para a interface de `IUnknown` do objeto de origem do evento.

### <a name="return-value"></a>Valor retornado

S_OK ou qualquer valor HRESULT de falha.

### <a name="remarks"></a>Comentários

Depois que a conexão é estabelecida, os eventos disparados de *punk* serão roteados para os manipuladores em sua classe por meio do mapa do coletor de eventos.

> [!NOTE]
>  Se sua classe derivar de várias classes `IDispEventSimpleImpl`, você precisará remover a ambiguidade de chamadas para esse método, definindo o escopo da chamada com a classe base específica em que você está interessado.

`Advise` estabelece uma conexão com a origem do evento padrão, ela obtém a IID da origem do evento padrão do objeto, conforme determinado pelo [AtlGetObjectSourceInterface](composite-control-global-functions.md#atlgetobjectsourceinterface).

##  <a name="dispeventadvise"></a>IDispEventSimpleImpl::D ispEventAdvise

Chame esse método para estabelecer uma conexão com a origem do evento representada por *punk*.

```
HRESULT DispEventAdvise(IUnknown* pUnk  const IID* piid);
```

### <a name="parameters"></a>parâmetros

*pUnk*<br/>
no Um ponteiro para a interface de `IUnknown` do objeto de origem do evento.

*piid*<br/>
Um ponteiro para o IID do objeto de origem do evento.

### <a name="return-value"></a>Valor retornado

S_OK ou qualquer valor HRESULT de falha.

### <a name="remarks"></a>Comentários

Subsequentemente, os eventos disparados de *punk* serão roteados para os manipuladores em sua classe por meio do mapa do coletor de eventos.

> [!NOTE]
>  Se sua classe derivar de várias classes `IDispEventSimpleImpl`, você precisará remover a ambiguidade de chamadas para esse método, definindo o escopo da chamada com a classe base específica em que você está interessado.

`DispEventAdvise` estabelece uma conexão com a origem do evento especificada em `pdiid`.

##  <a name="dispeventunadvise"></a>IDispEventSimpleImpl::D ispEventUnadvise

Interrompe a conexão com a origem do evento representada por *punk*.

```
HRESULT DispEventUnadvise(IUnknown* pUnk  const IID* piid);
```

### <a name="parameters"></a>parâmetros

*pUnk*<br/>
no Um ponteiro para a interface de `IUnknown` do objeto de origem do evento.

*piid*<br/>
Um ponteiro para o IID do objeto de origem do evento.

### <a name="return-value"></a>Valor retornado

S_OK ou qualquer valor HRESULT de falha.

### <a name="remarks"></a>Comentários

Depois que a conexão for interrompida, os eventos não serão mais roteados para as funções de manipulador listadas no mapa do coletor de eventos.

> [!NOTE]
>  Se sua classe derivar de várias classes `IDispEventSimpleImpl`, você precisará remover a ambiguidade de chamadas para esse método, definindo o escopo da chamada com a classe base específica em que você está interessado.

`DispEventAdvise` interrompe uma conexão que foi estabelecida com a origem do evento especificada em `pdiid`.

##  <a name="getidsofnames"></a>IDispEventSimpleImpl:: GetIDsOfNames

Essa implementação de `IDispatch::GetIDsOfNames` retorna E_NOTIMPL.

```
STDMETHOD(GetIDsOfNames)(
    REFIID /* riid */,
    LPOLESTR* /* rgszNames */,
    UINT /* cNames */,
    LCID /* lcid */,
    DISPID* /* rgdispid */);
```

### <a name="remarks"></a>Comentários

Consulte [IDispatch:: GetIDsOfNames](/windows/win32/api/oaidl/nf-oaidl-idispatch-getidsofnames) na SDK do Windows.

##  <a name="gettypeinfo"></a>IDispEventSimpleImpl:: GetTypeInfo

Essa implementação de `IDispatch::GetTypeInfo` retorna E_NOTIMPL.

```
STDMETHOD(GetTypeInfo)(
    UINT /* itinfo */,
    LCID /* lcid */,
    ITypeInfo** /* pptinfo */);
```

### <a name="remarks"></a>Comentários

Consulte [IDispatch:: GetTypeInfo](/windows/win32/api/oaidl/nf-oaidl-idispatch-gettypeinfo) no SDK do Windows.

##  <a name="gettypeinfocount"></a>IDispEventSimpleImpl::GetTypeInfoCount

Essa implementação de `IDispatch::GetTypeInfoCount` retorna E_NOTIMPL.

```
STDMETHOD(GetTypeInfoCount)(UINT* /* pctinfo */);
```

### <a name="remarks"></a>Comentários

Consulte [IDispatch:: GetTypeInfoCount](/windows/win32/api/oaidl/nf-oaidl-idispatch-gettypeinfocount) na SDK do Windows.

##  <a name="invoke"></a>IDispEventSimpleImpl:: Invoke

Essa implementação de `IDispatch::Invoke` chama os manipuladores de eventos listados no mapa do coletor de eventos.

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

Consulte [IDispatch:: Invoke](/windows/win32/api/oaidl/nf-oaidl-idispatch-invoke).

##  <a name="unadvise"></a>IDispEventSimpleImpl:: Unadvise

Interrompe a conexão com a origem do evento representada por *punk*.

```
HRESULT Unadvise(IUnknown* pUnk);
```

### <a name="parameters"></a>parâmetros

*pUnk*<br/>
no Um ponteiro para a interface de `IUnknown` do objeto de origem do evento.

### <a name="return-value"></a>Valor retornado

S_OK ou qualquer valor HRESULT de falha.

### <a name="remarks"></a>Comentários

Depois que a conexão for interrompida, os eventos não serão mais roteados para as funções de manipulador listadas no mapa do coletor de eventos.

> [!NOTE]
>  Se sua classe derivar de várias classes `IDispEventSimpleImpl`, você precisará remover a ambiguidade de chamadas para esse método, definindo o escopo da chamada com a classe base específica em que você está interessado.

`Unadvise` interrompe uma conexão que foi estabelecida com a origem do evento padrão especificada em `pdiid`.

`Unavise` interrompe uma conexão com a origem do evento padrão, ela obtém a IID da origem do evento padrão do objeto, conforme determinado por [AtlGetObjectSourceInterface](composite-control-global-functions.md#atlgetobjectsourceinterface).

## <a name="see-also"></a>Confira também

[Estrutura _ATL_FUNC_INFO](../../atl/reference/atl-func-info-structure.md)<br/>
[Classe IDispatchImpl](../../atl/reference/idispatchimpl-class.md)<br/>
[Classe IDispEventImpl](../../atl/reference/idispeventimpl-class.md)<br/>
[SINK_ENTRY_INFO](composite-control-macros.md#sink_entry_info)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
