---
title: Classe IOleControlImpl
ms.date: 11/04/2016
f1_keywords:
- IOleControlImpl
- ATLCTL/ATL::IOleControlImpl
- ATLCTL/ATL::IOleControlImpl::FreezeEvents
- ATLCTL/ATL::IOleControlImpl::GetControlInfo
- ATLCTL/ATL::IOleControlImpl::OnAmbientPropertyChange
- ATLCTL/ATL::IOleControlImpl::OnMnemonic
helpviewer_keywords:
- IOleControlImpl class
ms.assetid: 5a4255ad-ede4-49ca-ba9a-07c2e919fa85
ms.openlocfilehash: 3bdb501d8210c98ce982719358564c4937991e12
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78864939"
---
# <a name="iolecontrolimpl-class"></a>Classe IOleControlImpl

Essa classe fornece uma implementação padrão da interface `IOleControl` e implementa `IUnknown`.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template<class T>
class IOleControlImpl
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IOleControlImpl`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[IOleControlImpl:: FreezeEvents](#freezeevents)|Indica se o contêiner ignora ou não os eventos do controle.|
|[IOleControlImpl::GetControlInfo](#getcontrolinfo)|Preenche informações sobre o comportamento do teclado do controle. A implementação da ATL retorna E_NOTIMPL.|
|[IOleControlImpl::OnAmbientPropertyChange](#onambientpropertychange)|Informa um controle de que uma ou mais das propriedades de ambiente do contêiner foram alteradas. A implementação da ATL retorna S_OK.|
|[IOleControlImpl:: onmnemônico](#onmnemonic)|Informa ao controle que um usuário pressionou um pressionamento de tecla especificada. A implementação da ATL retorna E_NOTIMPL.|

## <a name="remarks"></a>Comentários

A classe `IOleControlImpl` fornece uma implementação padrão da interface [IOleControl](/windows/win32/api/ocidl/nn-ocidl-iolecontrol) e implementa `IUnknown` enviando informações para o dispositivo de despejo em compilações de depuração.

**Artigos relacionados** - [tutorial do ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto do ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IOleControl`

`IOleControlImpl`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** atlctl. h

##  <a name="freezeevents"></a>IOleControlImpl:: FreezeEvents

Na implementação da ATL, `FreezeEvents` incrementa o membro de dados `m_nFreezeEvents` da classe de controle se `bFreeze` for TRUE e decrementará `m_nFreezeEvents` se `bFreeze` for FALSE.

```
HRESULT FreezeEvents(BOOL bFreeze);
```

### <a name="remarks"></a>Comentários

`FreezeEvents`, em seguida, retorna S_OK.

Consulte [IOleControl:: FreezeEvents](/windows/win32/api/ocidl/nf-ocidl-iolecontrol-freezeevents) na SDK do Windows.

##  <a name="getcontrolinfo"></a>IOleControlImpl::GetControlInfo

Preenche informações sobre o comportamento do teclado do controle.

```
HRESULT GetControlInfo(LPCONTROLINFO pCI);
```

### <a name="remarks"></a>Comentários

Consulte [IOleControl: GetControlInfo](/windows/win32/api/ocidl/nf-ocidl-iolecontrol-getcontrolinfo) no SDK do Windows.

### <a name="return-value"></a>Valor retornado

Retorna E_NOTIMPL.

##  <a name="onambientpropertychange"></a>IOleControlImpl::OnAmbientPropertyChange

Informa um controle de que uma ou mais das propriedades de ambiente do contêiner foram alteradas.

```
HRESULT OnAmbientPropertyChange(DISPID dispid);
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Consulte [IOleControl:: OnAmbientPropertyChange](/windows/win32/api/ocidl/nf-ocidl-iolecontrol-onambientpropertychange) na SDK do Windows.

##  <a name="onmnemonic"></a>IOleControlImpl:: onmnemônico

Informa ao controle que um usuário pressionou um pressionamento de tecla especificada.

```
HRESULT OnMnemonic(LPMSG pMsg);
```

### <a name="return-value"></a>Valor retornado

Retorna E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [IOleControl:: onmnemônico](/windows/win32/api/ocidl/nf-ocidl-iolecontrol-onmnemonic) na SDK do Windows.

## <a name="see-also"></a>Consulte também

[Classe IOleObjectImpl](../../atl/reference/ioleobjectimpl-class.md)<br/>
[Interfaces de controles ActiveX](/windows/win32/com/activex-controls-interfaces)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
