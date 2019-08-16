---
title: Classe IOleInPlaceObjectWindowlessImpl
ms.date: 11/04/2016
f1_keywords:
- IOleInPlaceObjectWindowlessImpl
- ATLCTL/ATL::IOleInPlaceObjectWindowlessImpl
- ATLCTL/ATL::IOleInPlaceObjectWindowlessImpl::ContextSensitiveHelp
- ATLCTL/ATL::IOleInPlaceObjectWindowlessImpl::GetDropTarget
- ATLCTL/ATL::IOleInPlaceObjectWindowlessImpl::GetWindow
- ATLCTL/ATL::IOleInPlaceObjectWindowlessImpl::InPlaceDeactivate
- ATLCTL/ATL::IOleInPlaceObjectWindowlessImpl::OnWindowMessage
- ATLCTL/ATL::IOleInPlaceObjectWindowlessImpl::ReactivateAndUndo
- ATLCTL/ATL::IOleInPlaceObjectWindowlessImpl::SetObjectRects
- ATLCTL/ATL::IOleInPlaceObjectWindowlessImpl::UIDeactivate
helpviewer_keywords:
- IOleInPlaceObjectWindowless, ATL implementation
- activation [C++], ATL
- IOleInPlaceObjectWindowlessImpl class
- ActiveX controls [C++], communication between container and control
- controls [ATL], windowless
- deactivating ATL
ms.assetid: a2e0feb4-bc59-4adf-aab2-105457bbdbb4
ms.openlocfilehash: fdd660daae109ac2a656519131dd9869ceaeaf4e
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69495742"
---
# <a name="ioleinplaceobjectwindowlessimpl-class"></a>Classe IOleInPlaceObjectWindowlessImpl

Essa classe implementa `IUnknown` e fornece métodos que permitem que um controle sem janela receba mensagens de janela e participe de operações de arrastar e soltar.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template<class T>
class IOleInPlaceObjectWindowlessImpl
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IOleInPlaceObjectWindowlessImpl`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[IOleInPlaceObjectWindowlessImpl::ContextSensitiveHelp](#contextsensitivehelp)|Habilita a ajuda contextual. A implementação da ATL retorna E_NOTIMPL.|
|[IOleInPlaceObjectWindowlessImpl::GetDropTarget](#getdroptarget)|Fornece a `IDropTarget` interface para um objeto ativo e sem janela no local que dá suporte a arrastar e soltar. A implementação da ATL retorna E_NOTIMPL.|
|[IOleInPlaceObjectWindowlessImpl::GetWindow](#getwindow)|Obtém um identificador de janela.|
|[IOleInPlaceObjectWindowlessImpl::InPlaceDeactivate](#inplacedeactivate)|Desativa um controle in-loco ativo.|
|[IOleInPlaceObjectWindowlessImpl::OnWindowMessage](#onwindowmessage)|Despacha uma mensagem do contêiner para um controle sem janela que está ativo no local.|
|[IOleInPlaceObjectWindowlessImpl::ReactivateAndUndo](#reactivateandundo)|Reativa um controle anteriormente desativado. A implementação da ATL retorna E_NOTIMPL.|
|[IOleInPlaceObjectWindowlessImpl::SetObjectRects](#setobjectrects)|Indica que parte do controle in-loco está visível.|
|[IOleInPlaceObjectWindowlessImpl::UIDeactivate](#uideactivate)|Desativa e remove a interface do usuário que dá suporte à ativação in-loco.|

## <a name="remarks"></a>Comentários

A interface [IOleInPlaceObject](/windows/win32/api/oleidl/nn-oleidl-ioleinplaceobject) gerencia a reativação e a desativação de controles in-loco e determina a quantidade de controle que deve ser visível. A interface [IOleInPlaceObjectWindowless](/windows/win32/api/ocidl/nn-ocidl-ioleinplaceobjectwindowless) permite que um controle sem janela receba mensagens de janela e participe de operações de arrastar e soltar. Fornece uma implementação padrão de `IOleInPlaceObject` e `IOleInPlaceObjectWindowless` e implementa `IUnknown` enviando informações para o dispositivo de despejo em compilações de depuração. `IOleInPlaceObjectWindowlessImpl`

**Artigos relacionados** [Tutorial do ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IOleInPlaceObjectWindowless`

`IOleInPlaceObjectWindowlessImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl. h

##  <a name="contextsensitivehelp"></a>  IOleInPlaceObjectWindowlessImpl::ContextSensitiveHelp

Retorna E_NOTIMPL.

```
HRESULT ContextSensitiveHelp(BOOL fEnterMode);
```

### <a name="remarks"></a>Comentários

Consulte [IOleWindow:: ContextSensitiveHelp](/windows/win32/api/oleidl/nf-oleidl-iolewindow-contextsensitivehelp) na SDK do Windows.

##  <a name="getdroptarget"></a>  IOleInPlaceObjectWindowlessImpl::GetDropTarget

Retorna E_NOTIMPL.

```
HRESULT GetDropTarget(IDropTarget** ppDropTarget);
```

### <a name="remarks"></a>Comentários

Consulte [IOleInPlaceObjectWindowless:: GetDropTarget](/windows/win32/api/ocidl/nf-ocidl-ioleinplaceobjectwindowless-getdroptarget) na SDK do Windows.

##  <a name="getwindow"></a>  IOleInPlaceObjectWindowlessImpl::GetWindow

O contêiner chama essa função para obter o identificador de janela do controle.

```
HRESULT GetWindow(HWND* phwnd);
```

### <a name="remarks"></a>Comentários

Alguns contêineres não funcionarão com um controle que tenha sido sem janela, mesmo que esteja em janela no momento. Na implementação da ATL, se o membro `m_bWasOnceWindowless` de dados da classe de controle for true, a função retornará E_FAIL. Caso contrário, se *phwnd* não for nulo `GetWindow` , \* o definirá *phwnd* para o membro `m_hWnd` de dados da classe de controle e retornará S_OK.

Consulte [IOleWindow:: GetWindow](/windows/win32/api/oleidl/nf-oleidl-iolewindow-getwindow) no SDK do Windows.

##  <a name="inplacedeactivate"></a>  IOleInPlaceObjectWindowlessImpl::InPlaceDeactivate

Chamado pelo contêiner para desativar um controle ativo in-loco.

```
HRESULT InPlaceDeactivate(HWND* phwnd);
```

### <a name="remarks"></a>Comentários

Esse método executa uma desativação completa ou parcial dependendo do estado do controle. Se necessário, a interface do usuário do controle é desativada e a janela do controle, se houver, é destruída. O contêiner é notificado de que o controle não está mais ativo no lugar. A `IOleInPlaceUIWindow` interface usada pelo contêiner para negociar menus e espaço de borda é liberada.

Consulte [IOleInPlaceObject:: InPlaceDeactivate](/windows/win32/api/oleidl/nf-oleidl-ioleinplaceobject-inplacedeactivate) na SDK do Windows.

##  <a name="onwindowmessage"></a>  IOleInPlaceObjectWindowlessImpl::OnWindowMessage

Despacha uma mensagem de um contêiner para um controle sem janela que está ativo no local.

```
HRESULT OnWindowMessage(
    UINT msg,
    WPARAM WParam,
    LPARAM LParam,
    LRESULT plResultParam);
```

### <a name="remarks"></a>Comentários

Consulte [IOleInPlaceObjectWindowless:: OnWindowMessage](/windows/win32/api/ocidl/nf-ocidl-ioleinplaceobjectwindowless-onwindowmessage) na SDK do Windows.

##  <a name="reactivateandundo"></a>  IOleInPlaceObjectWindowlessImpl::ReactivateAndUndo

Retorna E_NOTIMPL.

```
HRESULT ReactivateAndUndo();
```

### <a name="remarks"></a>Comentários

Consulte [IOleInPlaceObject:: ReactivateAndUndo](/windows/win32/api/oleidl/nf-oleidl-ioleinplaceobject-reactivateandundo) na SDK do Windows.

##  <a name="setobjectrects"></a>  IOleInPlaceObjectWindowlessImpl::SetObjectRects

Chamado pelo contêiner para informar o controle de que seu tamanho e/ou posição foi alterado.

```
HRESULT SetObjectRects(LPCRECT prcPos, LPCRECT prcClip);
```

### <a name="remarks"></a>Comentários

Atualiza o membro de `m_rcPos` dados do controle e a exibição do controle. Somente a parte do controle que cruza a região do clipe é exibida. Se a exibição de um controle tiver sido recortada anteriormente, mas o recorte tiver sido removido, essa função poderá ser chamada para redesenhar uma exibição completa do controle.

Consulte [IOleInPlaceObject:: SetObjectRects](/windows/win32/api/oleidl/nf-oleidl-ioleinplaceobject-setobjectrects) na SDK do Windows.

##  <a name="uideactivate"></a>  IOleInPlaceObjectWindowlessImpl::UIDeactivate

Desativa e remove a interface do usuário do controle que dá suporte à ativação in-loco.

```
HRESULT UIDeactivate();
```

### <a name="remarks"></a>Comentários

Define o membro `m_bUIActive` de dados da classe de controle como false. A implementação da ATL dessa função sempre retorna S_OK.

Consulte [IOleInPlaceObject:: UIDeactivate](/windows/win32/api/oleidl/nf-oleidl-ioleinplaceobject-uideactivate) na SDK do Windows.

## <a name="see-also"></a>Consulte também

[Classe CComControl](../../atl/reference/ccomcontrol-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
