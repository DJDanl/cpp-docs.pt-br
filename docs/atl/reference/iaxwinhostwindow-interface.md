---
title: IAxWinHostWindow Interface
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
ms.openlocfilehash: ebecc611660a788ce59bb11beb95bd60eacaf01b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329994"
---
# <a name="iaxwinhostwindow-interface"></a>IAxWinHostWindow Interface

Esta interface fornece métodos para manipular um controle e seu objeto hospedeiro.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
interface IAxWinHostWindow : IUnknown
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[Attachcontrol](#attachcontrol)|Anexa um controle existente ao objeto host.|
|[CreateControl](#createcontrol)|Cria um controle e o anexa ao objeto host.|
|[Createcontrolex](#createcontrolex)|Cria um controle, anexa-o ao objeto host e, opcionalmente, configura um manipulador de eventos.|
|[QueryControl](#querycontrol)|Retorna um ponteiro de interface para o controle hospedado.|
|[SetExternalDispatch](#setexternaldispatch)|Define a `IDispatch` interface externa.|
|[SetExternalUIhandler](#setexternaluihandler)|Define a `IDocHostUIHandlerDispatch` interface externa.|

## <a name="remarks"></a>Comentários

Esta interface é exposta pelos objetos de hospedagem de controle ActiveX da ATL. Chame os métodos nesta interface para criar e/ou anexar um controle ao objeto host, para obter uma interface a partir de um controle hospedado ou para definir o manipulador externo de dispinterface ou Interface de Interface para uso ao hospedar o navegador da Web.

## <a name="requirements"></a>Requisitos

A definição desta interface está disponível como IDL ou C++, como mostrado abaixo.

|Tipo de definição|Arquivo|
|---------------------|----------|
|Idl|ATLIFace.idl|
|C++|ATLIFace.h (também incluído no ATLBase.h)|

## <a name="iaxwinhostwindowattachcontrol"></a><a name="attachcontrol"></a>IAxWinHostWindow::AttachControl

Anexa um controle existente (e previamente inicializado) ao objeto host usando a janela identificada por *hWnd*.

```
STDMETHOD(AttachControl)(IUnknown* pUnkControl, HWND hWnd);
```

### <a name="parameters"></a>Parâmetros

*pUnkControl*<br/>
[em] Um ponteiro `IUnknown` para a interface do controle a ser anexado ao objeto host.

*hWnd*<br/>
[em] Uma alça para a janela a ser usada para hospedagem.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="iaxwinhostwindowcreatecontrol"></a><a name="createcontrol"></a>IAxWinHostWindow::CreateControl

Cria um controle, inicializa-o e hospeda-o na janela identificada por *hWnd*.

```
STDMETHOD(CreateControl)(
    LPCOLESTR lpTricsData,
    HWND hWnd,
    IStream* pStream);
```

### <a name="parameters"></a>Parâmetros

*lpTricsData*<br/>
[em] Uma seqüência identificando o controle para criar. Pode ser um CLSID (deve incluir os aparelhos), ProgID, URL ou HTML bruto (prefixado por **MSHTML:**).

*hWnd*<br/>
[em] Uma alça para a janela a ser usada para hospedagem.

*pStream*<br/>
[em] Um ponteiro de interface para um fluxo contendo dados de inicialização para o controle. Pode ser NULL.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Esta janela será subclassificada pelo objeto host expondo esta interface para que as mensagens possam ser refletidas no controle e outros recursos do contêiner funcionarão.

Chamar esse método é equivalente a chamar [IAxWinHostWindow::CreateControlEx](#createcontrolex).

Para criar um controle ActiveX licenciado, consulte [IAxWinHostWindowLic::CreateControlLic](../../atl/reference/iaxwinhostwindowlic-interface.md#createcontrollicex).

## <a name="iaxwinhostwindowcreatecontrolex"></a><a name="createcontrolex"></a>IAxWinHostWindow::CreateControlEx

Cria um controle ActiveX, inicializa-o e hospeda-o na janela especificada, semelhante ao [IAxWinHostWindow::CreateControl](#createcontrol).

```
STDMETHOD(CreateControlEx)(
    LPCOLESTR lpszTricsData,
    HWND hWnd,
    IStream* pStream,
    IUnknown** ppUnk,
    REFIID riidAdvise,
    IUnknown* punkAdvise);
```

### <a name="parameters"></a>Parâmetros

*lpTricsData*<br/>
[em] Uma seqüência identificando o controle para criar. Pode ser um CLSID (deve incluir os aparelhos), ProgID, URL ou HTML bruto (prefixado com **MSHTML:**).

*hWnd*<br/>
[em] Uma alça para a janela a ser usada para hospedagem.

*pStream*<br/>
[em] Um ponteiro de interface para um fluxo contendo dados de inicialização para o controle. Pode ser NULL.

*ppUnk*<br/>
[fora] O endereço de um ponteiro `IUnknown` que receberá a interface do controle criado. Pode ser NULL.

*riidAdvise*<br/>
[em] O identificador de interface de uma interface de saída no objeto contido. Pode ser IID_NULL.

*punkAdvise*<br/>
[em] Um ponteiro `IUnknown` para a interface do objeto da pia a ser conectado `iidSink`ao ponto de conexão no objeto contido especificado por .

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Ao `CreateControl` contrário `CreateControlEx` do método, também permite que você receba um ponteiro de interface para o controle recém-criado e configure um dissipador de eventos para receber eventos disparados pelo controle.

Para criar um controle ActiveX licenciado, consulte [IAxWinHostWindowLic::CreateControlLicEx](../../atl/reference/iaxwinhostwindowlic-interface.md#createcontrollicex).

## <a name="iaxwinhostwindowquerycontrol"></a><a name="querycontrol"></a>IAxWinHostWindow::QueryControl

Retorna o ponteiro de interface especificado fornecido pelo controle hospedado.

```
STDMETHOD(QueryControl)(
    REFIID riid,
    void** ppvObject);
```

### <a name="parameters"></a>Parâmetros

*riid*<br/>
[em] O ID de uma interface no controle que está sendo solicitado.

*Ppvobject*<br/>
[fora] O endereço de um ponteiro que receberá a interface especificada do controle criado.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="iaxwinhostwindowsetexternaldispatch"></a><a name="setexternaldispatch"></a>IAxWinHostWindow::SetExternalDispatch

Define a dispinterface externa, disponível para controles contidos através do [método IDocHostUIHandlerDispatch::GetExternal.](../../atl/reference/idochostuihandlerdispatch-interface.md)

```
STDMETHOD(SetExternalDispatch)(IDispatch* pDisp);
```

### <a name="parameters"></a>Parâmetros

*pDisp*<br/>
[em] Um ponteiro `IDispatch` para uma interface.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="iaxwinhostwindowsetexternaluihandler"></a><a name="setexternaluihandler"></a>IAxWinHostWindow::SetExternalUIHandler

Chame esta função para definir a interface externa [IDocHostUIHandlerDispatch](../../atl/reference/idochostuihandlerdispatch-interface.md) para o `CAxWindow` objeto.

```
STDMETHOD(SetExternalUIHandler)(IDocHostUIHandlerDispatch* pDisp);
```

### <a name="parameters"></a>Parâmetros

*pDisp*<br/>
[em] Um ponteiro `IDocHostUIHandlerDispatch` para uma interface.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Esta função é usada por controles (como o controle do navegador da `IDocHostUIHandlerDispatch` Web) que consultam o site do host para a interface.

## <a name="see-also"></a>Confira também

[IAxWinAmbientDispatch Interface](../../atl/reference/iaxwinambientdispatch-interface.md)<br/>
[CAxWindow::ConsultaHost](../../atl/reference/caxwindow-class.md#queryhost)<br/>
[AtlAxGetHost](composite-control-global-functions.md#atlaxgethost)
