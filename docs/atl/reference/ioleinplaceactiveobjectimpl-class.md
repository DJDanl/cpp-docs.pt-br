---
title: Classe IOleInPlaceActiveObjectImpl
ms.date: 11/04/2016
f1_keywords:
- IOleInPlaceActiveObjectImpl
- ATLCTL/ATL::IOleInPlaceActiveObjectImpl
- ATLCTL/ATL::IOleInPlaceActiveObjectImpl::ContextSensitiveHelp
- ATLCTL/ATL::IOleInPlaceActiveObjectImpl::EnableModeless
- ATLCTL/ATL::IOleInPlaceActiveObjectImpl::GetWindow
- ATLCTL/ATL::IOleInPlaceActiveObjectImpl::OnDocWindowActivate
- ATLCTL/ATL::IOleInPlaceActiveObjectImpl::OnFrameWindowActivate
- ATLCTL/ATL::IOleInPlaceActiveObjectImpl::ResizeBorder
- ATLCTL/ATL::IOleInPlaceActiveObjectImpl::TranslateAccelerator
helpviewer_keywords:
- IOleInPlaceActiveObjectImpl class
- ActiveX controls [C++], communication between container and control
- IOleInPlaceActiveObject, ATL implementation
ms.assetid: 44e6cc6d-a2dc-4187-98e3-73cf0320dea9
ms.openlocfilehash: b39ba2845a5483444dac53d1616654e902969c77
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326595"
---
# <a name="ioleinplaceactiveobjectimpl-class"></a>Classe IOleInPlaceActiveObjectImpl

Esta classe fornece métodos para auxiliar a comunicação entre um controle no local e seu contêiner.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<class T>
class IOleInPlaceActiveObjectImpl
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IOleInPlaceActiveObjectImpl`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IOleInPlaceActiveObjectImpl::ContextSensitiveHelp](#contextsensitivehelp)|Permite ajuda sensível ao contexto. A implementação da ATL retorna E_NOTIMPL.|
|[IOleInPlaceActiveObjectImpl::EnableModeless](#enablemodeless)|Habilita caixas de diálogo modeless. A implementação da ATL retorna S_OK.|
|[IOleInPlaceActiveObjectImpl::GetWindow](#getwindow)|Pega uma alça da janela.|
|[IOleInPlaceActiveObjectImpl::OnDocWindowActivate](#ondocwindowactivate)|Notifica o controle quando a janela do documento do contêiner é ativada ou desativada. A implementação da ATL retorna S_OK.|
|[IOleInPlaceActiveObjectImpl::OnFrameWindowActivate](#onframewindowactivate)|Notifica o controle quando a janela de quadro de nível superior do contêiner é ativada ou desativada. A implementação atl retorna|
|[IOleInPlaceActiveObjectImpl::Redimensionborder](#resizeborder)|Informa o controle que precisa para redimensionar suas fronteiras. A implementação da ATL retorna S_OK.|
|[IOleInPlaceActiveObjectImpl::TranslateAccelerator](#translateaccelerator)|Processa as mensagens-chave do acelerador do menu do contêiner. A implementação da ATL retorna E_NOTIMPL.|

## <a name="remarks"></a>Comentários

A interface [IOleInPlaceActiveObject](/windows/win32/api/oleidl/nn-oleidl-ioleinplaceactiveobject) auxilia a comunicação entre um controle no local e seu contêiner; por exemplo, comunicar o estado ativo do controle e do recipiente, e informar o controle que ele precisa para se redimensionar. A `IOleInPlaceActiveObjectImpl` classe fornece `IOleInPlaceActiveObject` uma implementação padrão e suporta `IUnknown` enviando informações para o dispositivo de despejo em compilações de depuração.

**Artigos relacionados** [ATL Tutorial](../../atl/active-template-library-atl-tutorial.md), Criando um Projeto [ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IOleInPlaceActiveObject`

`IOleInPlaceActiveObjectImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

## <a name="ioleinplaceactiveobjectimplcontextsensitivehelp"></a><a name="contextsensitivehelp"></a>IOleInPlaceActiveObjectImpl::ContextSensitiveHelp

Permite ajuda sensível ao contexto.

```
HRESULT ContextSensitiveHelp(BOOL fEnterMode);
```

### <a name="return-value"></a>Valor retornado

Volta E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [IOleWindow::ContextSensitiveHelp](/windows/win32/api/oleidl/nf-oleidl-iolewindow-contextsensitivehelp) no Windows SDK.

## <a name="ioleinplaceactiveobjectimplenablemodeless"></a><a name="enablemodeless"></a>IOleInPlaceActiveObjectImpl::EnableModeless

Habilita caixas de diálogo modeless.

```
HRESULT EnableModeless(BOOL fEnable);
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Consulte [IOleInPlaceActiveObject::EnableModeless](/windows/win32/api/oleidl/nf-oleidl-ioleinplaceactiveobject-enablemodeless) no Windows SDK.

## <a name="ioleinplaceactiveobjectimplgetwindow"></a><a name="getwindow"></a>IOleInPlaceActiveObjectImpl::GetWindow

O contêiner chama esta função para obter a alça da janela do controle.

```
HRESULT GetWindow(HWND* phwnd);
```

### <a name="remarks"></a>Comentários

Alguns contêineres não funcionarão com um controle que tenha sido sem janelas, mesmo que esteja atualmente em janelas. Na implementação da ATL, se o membro de `CComControl::m_bWasOnceWindowless` dados for TRUE, a função retorna E_FAIL. Caso contrário, \* se *phwnd* `GetWindow` não for NULL, atribua *phwnd* ao membro `m_hWnd` de dados da classe de controle e retorna S_OK.

Consulte [IOleWindow::GetWindow](/windows/win32/api/oleidl/nf-oleidl-iolewindow-getwindow) no Windows SDK.

## <a name="ioleinplaceactiveobjectimplondocwindowactivate"></a><a name="ondocwindowactivate"></a>IOleInPlaceActiveObjectImpl::OnDocWindowActivate

Notifica o controle quando a janela do documento do contêiner é ativada ou desativada.

```
HRESULT OnDocWindowActivate(BOOL fActivate);
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Consulte [IOleInPlaceActiveObject::OnDocWindowActivate](/windows/win32/api/oleidl/nf-oleidl-ioleinplaceactiveobject-ondocwindowactivate) no Windows SDK.

## <a name="ioleinplaceactiveobjectimplonframewindowactivate"></a><a name="onframewindowactivate"></a>IOleInPlaceActiveObjectImpl::OnFrameWindowActivate

Notifica o controle quando a janela de quadro de nível superior do contêiner é ativada ou desativada.

```
HRESULT OnFrameWindowActivate(BOOL fActivate);
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Consulte [IOleInPlaceActiveObject::OnFrameWindowActivate](/windows/win32/api/oleidl/nf-oleidl-ioleinplaceactiveobject-onframewindowactivate) in the Windows SDK.

## <a name="ioleinplaceactiveobjectimplresizeborder"></a><a name="resizeborder"></a>IOleInPlaceActiveObjectImpl::Redimensionborder

Informa o controle que precisa para redimensionar suas fronteiras.

```
HRESULT ResizeBorder(
    LPRECT prcBorder,
    IOleInPlaceUIWindow* pUIWindow,
    BOOL fFrameWindow);
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Consulte [IOleInPlaceActiveObject::Redimensionarborder](/windows/win32/api/oleidl/nf-oleidl-ioleinplaceactiveobject-resizeborder) no Windows SDK.

## <a name="ioleinplaceactiveobjectimpltranslateaccelerator"></a><a name="translateaccelerator"></a>IOleInPlaceActiveObjectImpl::TranslateAccelerator

Processa as mensagens-chave do acelerador do menu do contêiner.

```
HRESULT TranslateAccelerator(LPMSG lpmsg);
```

### <a name="return-value"></a>Valor retornado

Este método suporta os seguintes valores de retorno:

S_OK se a mensagem foi traduzida com sucesso.

S_FALSE se a mensagem não foi traduzida.

### <a name="remarks"></a>Comentários

Consulte [IOleInPlaceActiveObject::TranslateAccelerator](/windows/win32/api/oleidl/nf-oleidl-ioleinplaceactiveobject-translateaccelerator) no Windows SDK.

## <a name="see-also"></a>Confira também

[Classe CComControl](../../atl/reference/ccomcontrol-class.md)<br/>
[Interfaces de controles ActiveX](/windows/win32/com/activex-controls-interfaces)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
