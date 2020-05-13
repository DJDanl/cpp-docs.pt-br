---
title: Classe CAxWindow
ms.date: 11/04/2016
f1_keywords:
- CAxWindow
- ATLWIN/ATL::CAxWindow
- ATLWIN/ATL::AttachControl
- ATLWIN/ATL::CreateControl
- ATLWIN/ATL::CreateControlEx
- ATLWIN/ATL::GetWndClassName
- ATLWIN/ATL::QueryControl
- ATLWIN/ATL::QueryHost
- ATLWIN/ATL::SetExternalDispatch
- ATLWIN/ATL::SetExternalUIHandler
helpviewer_keywords:
- CAxWindow class
- ATL, hosting ActiveX controls
ms.assetid: 85e79261-43e4-4770-bde0-1ff87f222b0f
ms.openlocfilehash: 6f5629370bc1f821dac0a08cc76b5df1450f7a5b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81318728"
---
# <a name="caxwindow-class"></a>Classe CAxWindow

Esta classe fornece métodos para manipular uma janela hospedando um controle ActiveX.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CAxWindow : public CWindow
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[Attachcontrol](#attachcontrol)|Anexa um controle ActiveX existente `CAxWindow` ao objeto.|
|[Caxwindow](#caxwindow)|Constrói um objeto `CAxWindow`.|
|[CreateControl](#createcontrol)|Cria um controle ActiveX, inicializa-o e `CAxWindow` hospeda-o na janela.|
|[Createcontrolex](#createcontrolex)|Cria um controle ActiveX e recupera um ponteiro de interface (ou ponteiros) do controle.|
|[GetWndClassName](#getwndclassname)|(Estática) Recupera o nome de classe `CAxWindow` predefinido do objeto.|
|[QueryControl](#querycontrol)|Recupera o `IUnknown` controle ActiveX hospedado.|
|[Queryhost](#queryhost)|Recupera o `IUnknown` ponteiro `CAxWindow` do objeto.|
|[SetExternalDispatch](#setexternaldispatch)|Define a interface de `CAxWindow` despacho externa usada pelo objeto.|
|[SetExternalUIhandler](#setexternaluihandler)|Define a `IDocHostUIHandler` interface externa `CAxWindow` usada pelo objeto.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operador =](#operator_eq)|Atribui um HWND a `CAxWindow` um objeto existente.|

## <a name="remarks"></a>Comentários

Esta classe fornece métodos para manipular uma janela que hospeda um controle ActiveX. A hospedagem é fornecida por " **AtlAxWin80",** que é embrulhado por `CAxWindow`.

A `CAxWindow` classe é implementada como `CAxWindowT` uma especialização da classe. Esta especialização é declarada como:

`typedef CAxWindowT<CWindow> CAxWindow;`

Se você precisar alterar a classe `CAxWindowT` base, você pode usar e especificar a nova classe base como um argumento de modelo.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="caxwindowattachcontrol"></a><a name="attachcontrol"></a>CAxWindow::AttachControl

Cria um novo objeto host se um já não estiver presente e anexa o controle especificado ao host.

```
HRESULT AttachControl(
    IUnknown* pControl,
    IUnknown** ppUnkContainer);
```

### <a name="parameters"></a>Parâmetros

*pControl*<br/>
[em] Um ponteiro `IUnknown` para o controle.

*ppUnkContainer*<br/>
[fora] Um ponteiro `IUnknown` para o do `AxWin` host (o objeto).

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

O objeto de controle que está sendo `AttachControl`anexado deve ser corretamente inicializado antes de chamar .

## <a name="caxwindowcaxwindow"></a><a name="caxwindow"></a>CAxWindow::CAxWindow

Constrói um `CAxWindow` objeto usando uma alça de objeto de janela existente.

```
CAxWindow(HWND hWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
Uma alça para um objeto de janela existente.

## <a name="caxwindowcreatecontrol"></a><a name="createcontrol"></a>CAxWindow::CreateControl

Cria um controle ActiveX, inicializa-o e hospeda-o na janela especificada.

```
HRESULT CreateControl(
    LPCOLESTR lpszName,
    IStream* pStream = NULL,
    IUnknown** ppUnkContainer = NULL);

HRESULT CreateControl(
    DWORD dwResID,
    IStream* pStream = NULL,
    IUnknown** ppUnkContainer = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
Um ponteiro para uma seqüência para criar o controle. Deve ser formatado de uma das seguintes maneiras:

- Um ProgID como`"MSCAL.Calendar.7"`

- Um CLSID como`"{8E27C92B-1264-101C-8A2F-040224009C02}"`

- Uma URL como`"<https://www.microsoft.com>"`

- Uma referência a um documento ativo, como`"file://\\\Documents\MyDoc.doc"`

- Um fragmento de HTML, como`"MSHTML:\<HTML>\<BODY>This is a line of text\</BODY>\</HTML>"`

   > [!NOTE]
   > `"MSHTML:"`deve preceder o fragmento HTML para que ele seja designado como sendo um fluxo MSHTML. Apenas o ProgID e o CLSID são suportados em plataformas Windows Mobile. Plataformas incorporadas do Windows CE, além do Windows Mobile com suporte para CE IE suportam todos os tipos, incluindo ProgID, CLSID, URL, referência a documento ativo e fragmento de HTML.

*pStream*<br/>
[em] Um ponteiro para um fluxo que é usado para inicializar as propriedades do controle. Pode ser NULL.

*ppUnkContainer*<br/>
[fora] O endereço de um ponteiro `IUnknown` que receberá o do recipiente. Pode ser NULL.

*dwResID*<br/>
O ID de recurso de um recurso HTML. O controle do WebBrowser será criado e carregado com o recurso especificado.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Se a segunda versão deste método for usada, um controle HTML será criado e vinculado ao recurso identificado pelo *dwResID*.

Este método dá-lhe o mesmo resultado que chamar:

[!code-cpp[NVC_ATL_Windowing#42](../../atl/codesnippet/cpp/caxwindow-class_1.cpp)]

Consulte [CAxWindow2T:CreateControlLic](../../atl/reference/caxwindow2t-class.md#createcontrollic) para criar, inicializar e hospedar um controle ActiveX licenciado.

### <a name="example"></a>Exemplo

Consulte [Host ActiveX Controls Usando ATL AXHost](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter uma amostra que usa `CreateControl`.

## <a name="caxwindowcreatecontrolex"></a><a name="createcontrolex"></a>CAxWindow::CreateControlEx

Cria um controle ActiveX, inicializa-o e hospeda-o na janela especificada.

```
HRESULT CreateControlEx(
    LPCOLESTR lpszName,
    IStream* pStream = NULL,
    IUnknown** ppUnkContainer = NULL,
    IUnknown** ppUnkControl = NULL,
    REFIID iidSink = IID_NULL,
    IUnknown* punkSink = NULL);

HRESULT CreateControlEx(
    DWORD dwResID,
    IStream* pStream = NULL,
    IUnknown** ppUnkContainer = NULL,
    IUnknown** ppUnkControl = NULL,
    REFIID iidSink = IID_NULL,
    IUnknown* punkSink = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
Um ponteiro para uma seqüência para criar o controle. Deve ser formatado de uma das seguintes maneiras:

- Um ProgID como`"MSCAL.Calendar.7"`

- Um CLSID como`"{8E27C92B-1264-101C-8A2F-040224009C02}"`

- Uma URL como`"<https://www.microsoft.com>"`

- Uma referência a um documento ativo, como`"file://\\\Documents\MyDoc.doc"`

- Um fragmento de HTML, como`"MSHTML:\<HTML>\<BODY>This is a line of text\</BODY>\</HTML>"`

   > [!NOTE]
   > `"MSHTML:"`deve preceder o fragmento HTML para que ele seja designado como sendo um fluxo MSHTML. Apenas o ProgID e o CLSID são suportados em plataformas Windows Mobile. Plataformas incorporadas do Windows CE, além do Windows Mobile com suporte para CE IE suportam todos os tipos, incluindo ProgID, CLSID, URL, referência a documento ativo e fragmento de HTML.

*pStream*<br/>
[em] Um ponteiro para um fluxo que é usado para inicializar as propriedades do controle. Pode ser NULL.

*ppUnkContainer*<br/>
[fora] O endereço de um ponteiro `IUnknown` que receberá o do recipiente. Pode ser NULL.

*ppUnkControl*<br/>
[fora] O endereço de um ponteiro `IUnknown` que receberá o do controle. Pode ser NULL.

*Iidsink*<br/>
[em] O identificador de interface de uma interface de saída no objeto contido. Pode ser IID_NULL.

*Punksink*<br/>
[em] Um ponteiro `IUnknown` para a interface do objeto do dissipador a ser conectado ao ponto de conexão no objeto contido especificado pelo *iidSink*.

*dwResID*<br/>
[em] O ID de recurso de um recurso HTML. O controle do WebBrowser será criado e carregado com o recurso especificado.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Este método é semelhante ao [CAxWindow::CreateControl](#createcontrol) `CreateControlEx` , mas ao contrário desse método, também permite que você receba um ponteiro de interface para o controle recém-criado e configure um dissipador de eventos para receber eventos disparados pelo controle.

Consulte [CAxWindow2T:CreateControlLicEx](../../atl/reference/caxwindow2t-class.md#createcontrollicex) para criar, inicializar e hospedar um controle ActiveX licenciado.

### <a name="example"></a>Exemplo

Consulte [Host ActiveX Controls Usando ATL AXHost](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter uma amostra que usa `CreateControlEx`.

## <a name="caxwindowgetwndclassname"></a><a name="getwndclassname"></a>CAxWindow::GetWndClassName

Recupera o nome da classe da janela.

```
static LPCTSTR GetWndClassName();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma seqüência contendo o nome da classe de janela que pode hospedar controles ActiveX não licenciados.

## <a name="caxwindowoperator-"></a><a name="operator_eq"></a>CAxWindow::operador =

Atribui um HWND a `CAxWindow` um objeto existente.

```
CAxWindow<TBase>& operator=(HWND hWnd);
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
Uma alça para uma janela existente.

### <a name="return-value"></a>Valor retornado

Retorna uma referência `CAxWindow` ao objeto atual.

## <a name="caxwindowquerycontrol"></a><a name="querycontrol"></a>CAxWindow::QueryControl

Recupera a interface especificada do controle hospedado.

```
HRESULT QueryControl(REFIID iid, void** ppUnk);
template <class  Q>
HRESULT QueryControl(Q** ppUnk);
```

### <a name="parameters"></a>Parâmetros

*Iid*<br/>
[em] Especifica o IID da interface do controle.

*ppUnk*<br/>
[fora] Um ponteiro para a interface do controle. Na versão de modelo deste método, não há necessidade de um ID de referência, desde que uma interface digitada com um UUID associado seja aprovada.

*Q*<br/>
[em] A interface que está sendo consultada.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="caxwindowqueryhost"></a><a name="queryhost"></a>CAxWindow::ConsultaHost

Retorna a interface especificada do host.

```
HRESULT QueryHost(REFIID iid, void** ppUnk);
template <class  Q>
HRESULT QueryHost(Q** ppUnk);
```

### <a name="parameters"></a>Parâmetros

*Iid*<br/>
[em] Especifica o IID da interface do controle.

*ppUnk*<br/>
[fora] Um ponteiro para a interface no host. Na versão de modelo deste método, não há necessidade de um ID de referência, desde que uma interface digitada com um UUID associado seja aprovada.

*Q*<br/>
[em] A interface que está sendo consultada.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A interface do host permite o acesso à funcionalidade subjacente do `AxWin`código de hospedagem de janelas, implementado por .

## <a name="caxwindowsetexternaldispatch"></a><a name="setexternaldispatch"></a>CAxWindow::SetExternalDispatch

Define a interface de `CAxWindow` despacho externo para o objeto.

```
HRESULT SetExternalDispatch(IDispatch* pDisp);
```

### <a name="parameters"></a>Parâmetros

*pDisp*<br/>
[em] Um ponteiro `IDispatch` para uma interface.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="caxwindowsetexternaluihandler"></a><a name="setexternaluihandler"></a>CAxWindow::SetExternalUIHandler

Define a interface [externa IDocHostUIHandlerDispatch](../../atl/reference/idochostuihandlerdispatch-interface.md) para o `CAxWindow` objeto.

```
HRESULT SetExternalUIHandler(IDocHostUIHandlerDispatch* pUIHandler);
```

### <a name="parameters"></a>Parâmetros

*pUIHandler*<br/>
[em] Um ponteiro `IDocHostUIHandlerDispatch` para uma interface.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A `IDocHostUIHandlerDispatch` interface externa é usada por controles que consultam `IDocHostUIHandlerDispatch` o site do host para a interface. O controle do WebBrowser é um controle que faz isso.

## <a name="see-also"></a>Confira também

[Amostra ATLCON](../../overview/visual-cpp-samples.md)<br/>
[Classe CWindow](../../atl/reference/cwindow-class.md)<br/>
[Fundamentos do controle composto](../../atl/atl-composite-control-fundamentals.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Perguntas frequentes sobre contenção de controle](../../atl/atl-control-containment-faq.md)
