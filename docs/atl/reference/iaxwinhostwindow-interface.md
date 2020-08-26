---
title: Interface IAxWinHostWindow
ms.date: 11/04/2016
f1_keywords:
- IAxWinHostWindow
- ATLIFACE/ATL::IAxWinHostWindow
- ATLIFACE/ATL::AttachControl
- ATLIFACE/ATL::CreateControl
- ATLIFACE/ATL::CreateControlEx
- ATLIFACE/ATL::QueryControl
- ATLIFACE/ATL::SetExternalDispatch
- ATLIFACE/ATL::SetExternalUIHandler
helpviewer_keywords:
- IAxWinHostWindow interface
ms.assetid: 9821c035-cd52-4c46-b58a-9278064f09b4
ms.openlocfilehash: 44681b94e0bd1dfd757ebfa19f83074785dd95f5
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88833368"
---
# <a name="iaxwinhostwindow-interface"></a>Interface IAxWinHostWindow

Essa interface fornece métodos para manipular um controle e seu objeto de host.

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
interface IAxWinHostWindow : IUnknown
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|Nome|Descrição|
|-|-|
|[AttachControl](#attachcontrol)|Anexa um controle existente ao objeto de host.|
|[CreateControl](#createcontrol)|Cria um controle e o anexa ao objeto de host.|
|[CreateControlEx](#createcontrolex)|Cria um controle, anexa-o ao objeto de host e, opcionalmente, configura um manipulador de eventos.|
|[QueryControl](#querycontrol)|Retorna um ponteiro de interface para o controle hospedado.|
|[SetExternalDispatch](#setexternaldispatch)|Define a `IDispatch` interface externa.|
|[SetExternalUIHandler](#setexternaluihandler)|Define a `IDocHostUIHandlerDispatch` interface externa.|

## <a name="remarks"></a>Comentários

Essa interface é exposta pelos objetos de hospedagem do controle ActiveX da ATL. Chame os métodos nessa interface para criar e/ou anexar um controle ao objeto de host, para obter uma interface de um controle hospedado ou para definir a dispinterface externa ou o manipulador de interface do usuário para usar ao hospedar o navegador da Web.

## <a name="requirements"></a>Requisitos

A definição dessa interface está disponível como IDL ou C++, conforme mostrado abaixo.

|Tipo de definição|Arquivo|
|---------------------|----------|
|INSERI|ATLIFace. idl|
|C++|ATLIFace. h (também incluído em ATLBase. h)|

## <a name="iaxwinhostwindowattachcontrol"></a><a name="attachcontrol"></a> IAxWinHostWindow::AttachControl

Anexa um controle existente (e inicializado anteriormente) ao objeto de host usando a janela identificada por *HWND*.

```
STDMETHOD(AttachControl)(IUnknown* pUnkControl, HWND hWnd);
```

### <a name="parameters"></a>parâmetros

*pUnkControl*<br/>
no Um ponteiro para a `IUnknown` interface do controle a ser anexado ao objeto de host.

*hWnd*<br/>
no Um identificador para a janela a ser usada para hospedagem.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

## <a name="iaxwinhostwindowcreatecontrol"></a><a name="createcontrol"></a> IAxWinHostWindow:: CreateControl

Cria um controle, inicializa-o e o hospeda na janela identificada por *HWND*.

```
STDMETHOD(CreateControl)(
    LPCOLESTR lpTricsData,
    HWND hWnd,
    IStream* pStream);
```

### <a name="parameters"></a>parâmetros

*lpTricsData*<br/>
no Uma cadeia de caracteres que identifica o controle a ser criado. Pode ser um CLSID (deve incluir chaves), ProgID, URL ou HTML bruto (prefixado por **Mshtml:**).

*hWnd*<br/>
no Um identificador para a janela a ser usada para hospedagem.

*pStream*<br/>
no Um ponteiro de interface para um fluxo que contém dados de inicialização para o controle. Pode ser NULL.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Essa janela será subclasseda pelo objeto de host expondo essa interface para que as mensagens possam ser refletidas no controle e outros recursos do contêiner funcionarão.

Chamar esse método é equivalente a chamar [IAxWinHostWindow:: CreateControlEx](#createcontrolex).

Para criar um controle ActiveX licenciado, consulte [IAxWinHostWindowLic:: CreateControlLic](../../atl/reference/iaxwinhostwindowlic-interface.md#createcontrollicex).

## <a name="iaxwinhostwindowcreatecontrolex"></a><a name="createcontrolex"></a> IAxWinHostWindow::CreateControlEx

Cria um controle ActiveX, inicializa-o e o hospeda na janela especificada, semelhante a [IAxWinHostWindow:: CreateControl](#createcontrol).

```
STDMETHOD(CreateControlEx)(
    LPCOLESTR lpszTricsData,
    HWND hWnd,
    IStream* pStream,
    IUnknown** ppUnk,
    REFIID riidAdvise,
    IUnknown* punkAdvise);
```

### <a name="parameters"></a>parâmetros

*lpTricsData*<br/>
no Uma cadeia de caracteres que identifica o controle a ser criado. Pode ser um CLSID (deve incluir chaves), ProgID, URL ou HTML bruto (prefixado com **Mshtml:**).

*hWnd*<br/>
no Um identificador para a janela a ser usada para hospedagem.

*pStream*<br/>
no Um ponteiro de interface para um fluxo que contém dados de inicialização para o controle. Pode ser NULL.

*ppUnk*<br/>
fora O endereço de um ponteiro que receberá a `IUnknown` interface do controle criado. Pode ser NULL.

*riidAdvise*<br/>
no O identificador de interface de uma interface de saída no objeto contido. Pode ser IID_NULL.

*punkAdvise*<br/>
no Um ponteiro para a `IUnknown` interface do objeto de coletor a ser conectado ao ponto de conexão no objeto contido especificado por `iidSink` .

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Ao contrário do `CreateControl` método, `CreateControlEx` também permite que você receba um ponteiro de interface para o controle recém-criado e configure um coletor de eventos para receber eventos acionados pelo controle.

Para criar um controle ActiveX licenciado, consulte [IAxWinHostWindowLic:: CreateControlLicEx](../../atl/reference/iaxwinhostwindowlic-interface.md#createcontrollicex).

## <a name="iaxwinhostwindowquerycontrol"></a><a name="querycontrol"></a> IAxWinHostWindow::QueryControl

Retorna o ponteiro de interface especificado fornecido pelo controle hospedado.

```
STDMETHOD(QueryControl)(
    REFIID riid,
    void** ppvObject);
```

### <a name="parameters"></a>parâmetros

*riid*<br/>
no A ID de uma interface no controle que está sendo solicitado.

*ppvObject*<br/>
fora O endereço de um ponteiro que receberá a interface especificada do controle criado.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

## <a name="iaxwinhostwindowsetexternaldispatch"></a><a name="setexternaldispatch"></a> IAxWinHostWindow::SetExternalDispatch

Define o dispinterface externo, que está disponível para controles contidos por meio do método [IDocHostUIHandlerDispatch:: GetExternal](../../atl/reference/idochostuihandlerdispatch-interface.md) .

```
STDMETHOD(SetExternalDispatch)(IDispatch* pDisp);
```

### <a name="parameters"></a>parâmetros

*pDisp*<br/>
no Um ponteiro para uma `IDispatch` interface.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

## <a name="iaxwinhostwindowsetexternaluihandler"></a><a name="setexternaluihandler"></a> IAxWinHostWindow::SetExternalUIHandler

Chame essa função para definir a interface [IDocHostUIHandlerDispatch](../../atl/reference/idochostuihandlerdispatch-interface.md) externa para o `CAxWindow` objeto.

```
STDMETHOD(SetExternalUIHandler)(IDocHostUIHandlerDispatch* pDisp);
```

### <a name="parameters"></a>parâmetros

*pDisp*<br/>
no Um ponteiro para uma `IDocHostUIHandlerDispatch` interface.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Essa função é usada por controles (como o controle de navegador da Web) que consultam o site do host para a `IDocHostUIHandlerDispatch` interface.

## <a name="see-also"></a>Confira também

[Interface IAxWinAmbientDispatch](../../atl/reference/iaxwinambientdispatch-interface.md)<br/>
[CAxWindow::QueryHost](../../atl/reference/caxwindow-class.md#queryhost)<br/>
[AtlAxGetHost](composite-control-global-functions.md#atlaxgethost)
