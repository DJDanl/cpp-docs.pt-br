---
title: Interface IAxWinHostWindow | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- IAxWinHostWindow
- ATLIFACE/ATL::IAxWinHostWindow
- ATLIFACE/ATL::AttachControl
- ATLIFACE/ATL::CreateControl
- ATLIFACE/ATL::CreateControlEx
- ATLIFACE/ATL::QueryControl
- ATLIFACE/ATL::SetExternalDispatch
- ATLIFACE/ATL::SetExternalUIHandler
dev_langs:
- C++
helpviewer_keywords:
- IAxWinHostWindow interface
ms.assetid: 9821c035-cd52-4c46-b58a-9278064f09b4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bee312cd5e7a88dd0798778d5f8385df265d78a1
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46099750"
---
# <a name="iaxwinhostwindow-interface"></a>Interface IAxWinHostWindow

Essa interface fornece métodos para manipular um controle e seu objeto de host.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
interface IAxWinHostWindow : IUnknown
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[AttachControl](#attachcontrol)|Anexa um controle existente ao objeto de host.|
|[CreateControl](#createcontrol)|Cria um controle e a anexa ao objeto de host.|
|[CreateControlEx](#createcontrolex)|Cria um controle, anexa-o ao objeto de host e, opcionalmente, define um manipulador de eventos.|
|[QueryControl](#querycontrol)|Retorna um ponteiro de interface para o controle hospedado.|
|[SetExternalDispatch](#setexternaldispatch)|Define o externo `IDispatch` interface.|
|[SetExternalUIHandler](#setexternaluihandler)|Define o externo `IDocHostUIHandlerDispatch` interface.|

## <a name="remarks"></a>Comentários

Essa interface é exposta pelo controle ActiveX do ATL que objetos de hospedagem. Chame os métodos nesta interface para criar e/ou anexar um controle para o objeto de host, para obter uma interface de um controle hospedado, ou para definir o dispinterface externo ou um manipulador de interface do usuário para uso quando o navegador da Web de hospedagem.

## <a name="requirements"></a>Requisitos

A definição desta interface está disponível como IDL ou C++, conforme mostrado abaixo.

|Tipo de definição|Arquivo|
|---------------------|----------|
|IDL|ATLIFace.idl|
|C++|Atliface (também é incluído em atlbase. H)|

##  <a name="attachcontrol"></a>  IAxWinHostWindow::AttachControl

Anexa um controle existente (e inicializado anteriormente) para o objeto de host usando a janela identificada pelo *hWnd*.

```
STDMETHOD(AttachControl)(IUnknown* pUnkControl, HWND hWnd);
```

### <a name="parameters"></a>Parâmetros

*pUnkControl*<br/>
[in] Um ponteiro para o `IUnknown` interface do controle a ser anexado ao objeto de host.

*hWnd*<br/>
[in] Um identificador para a janela a ser usado para a hospedagem.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

##  <a name="createcontrol"></a>  IAxWinHostWindow::CreateControl

Cria um controle, inicializa-o e hospeda-o na janela identificada pelo *hWnd*.

```
STDMETHOD(CreateControl)(
    LPCOLESTR lpTricsData,
    HWND hWnd,
    IStream* pStream);
```

### <a name="parameters"></a>Parâmetros

*lpTricsData*<br/>
[in] Uma cadeia de caracteres que identifica o controle para criar. Pode ser um (deve incluir as chaves) de CLSID, ProgID, URL ou HTML bruto (antecedidos **MSHTML:**).

*hWnd*<br/>
[in] Um identificador para a janela a ser usado para a hospedagem.

*pStream*<br/>
[in] Um ponteiro de interface para um fluxo que contém dados de inicialização para o controle. Pode ser NULL.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Esta janela será ser uma subclasse pelo objeto de host expondo essa interface para que as mensagens podem ser refletidas ao controle e outros recursos de contêiner funcionará.

Chamar esse método é equivalente a chamar [IAxWinHostWindow::CreateControlEx](#createcontrolex).

Para criar um controle ActiveX licenciado, consulte [IAxWinHostWindowLic::CreateControlLic](../../atl/reference/iaxwinhostwindowlic-interface.md#createcontrollicex).

##  <a name="createcontrolex"></a>  IAxWinHostWindow::CreateControlEx

Cria um controle ActiveX, inicializa-o e hospeda-o na janela especificada, semelhante à [IAxWinHostWindow::CreateControl](#createcontrol).

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
[in] Uma cadeia de caracteres que identifica o controle para criar. Pode ser um (deve incluir as chaves) de CLSID, ProgID, URL ou HTML bruto (prefixados com **MSHTML:**).

*hWnd*<br/>
[in] Um identificador para a janela a ser usado para a hospedagem.

*pStream*<br/>
[in] Um ponteiro de interface para um fluxo que contém dados de inicialização para o controle. Pode ser NULL.

*ppUnk*<br/>
[out] O endereço de um ponteiro que receberá o `IUnknown` interface do controle criado. Pode ser NULL.

*riidAdvise*<br/>
[in] O identificador de interface de uma interface de saída o objeto contido. Pode ser IID_NULL.

*punkAdvise*<br/>
[in] Um ponteiro para o `IUnknown` interface do objeto coletor a ser conectado ao ponto de conexão no objeto independente especificado pelo `iidSink`.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Ao contrário do `CreateControl` método, `CreateControlEx` também permite que você receber um ponteiro de interface para o controle criado recentemente e configurar um coletor de eventos para receber eventos acionados pelo controle.

Para criar um controle ActiveX licenciado, consulte [IAxWinHostWindowLic::CreateControlLicEx](../../atl/reference/iaxwinhostwindowlic-interface.md#createcontrollicex).

##  <a name="querycontrol"></a>  IAxWinHostWindow::QueryControl

Retorna o ponteiro de interface especificado fornecido pelo controle hospedado.

```
STDMETHOD(QueryControl)(
    REFIID riid,
    void** ppvObject);
```

### <a name="parameters"></a>Parâmetros

*riid*<br/>
[in] A ID de uma interface no controle que está sendo solicitado.

*ppvObject*<br/>
[out] O endereço de um ponteiro que receberá a interface especificada do controle criado.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

##  <a name="setexternaldispatch"></a>  IAxWinHostWindow::SetExternalDispatch

Define a dispinterface externa, que está disponível para os controles contidos por meio de [IDocHostUIHandlerDispatch::GetExternal](../../atl/reference/idochostuihandlerdispatch-interface.md) método.

```
STDMETHOD(SetExternalDispatch)(IDispatch* pDisp);
```

### <a name="parameters"></a>Parâmetros

*pDisp*<br/>
[in] Um ponteiro para um `IDispatch` interface.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

##  <a name="setexternaluihandler"></a>  IAxWinHostWindow::SetExternalUIHandler

Chame essa função para definir o externo [IDocHostUIHandlerDispatch](../../atl/reference/idochostuihandlerdispatch-interface.md) interface para o `CAxWindow` objeto.

```
STDMETHOD(SetExternalUIHandler)(IDocHostUIHandlerDispatch* pDisp);
```

### <a name="parameters"></a>Parâmetros

*pDisp*<br/>
[in] Um ponteiro para um `IDocHostUIHandlerDispatch` interface.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Essa função é usada por controles (como o controle de navegador da Web) que consultar o site do host para o `IDocHostUIHandlerDispatch` interface.

## <a name="see-also"></a>Consulte também

[Interface IAxWinAmbientDispatch](../../atl/reference/iaxwinambientdispatch-interface.md)<br/>
[CAxWindow::QueryHost](../../atl/reference/caxwindow-class.md#queryhost)<br/>
[AtlAxGetHost](composite-control-global-functions.md#atlaxgethost)

