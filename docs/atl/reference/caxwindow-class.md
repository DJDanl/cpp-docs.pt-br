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
ms.openlocfilehash: 6f5c178090a970906209e41da9298be61a61c639
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78864709"
---
# <a name="caxwindow-class"></a>Classe CAxWindow

Essa classe fornece métodos para manipular uma janela que hospeda um controle ActiveX.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
class CAxWindow : public CWindow
```

## <a name="members"></a>Membros

### <a name="methods"></a>{1&gt;Métodos&lt;1}

|||
|-|-|
|[AttachControl](#attachcontrol)|Anexa um controle ActiveX existente ao objeto `CAxWindow`.|
|[CAxWindow](#caxwindow)|Constrói um objeto `CAxWindow`.|
|[Control](#createcontrol)|Cria um controle ActiveX, inicializa-o e o hospeda na janela `CAxWindow`.|
|[CreateControlEx](#createcontrolex)|Cria um controle ActiveX e recupera um ponteiro de interface (ou ponteiros) do controle.|
|[GetWndClassName](#getwndclassname)|Auto-estática Recupera o nome de classe predefinido do objeto `CAxWindow`.|
|[QueryControl](#querycontrol)|Recupera o `IUnknown` do controle ActiveX hospedado.|
|[QueryHost](#queryhost)|Recupera o ponteiro de `IUnknown` do objeto `CAxWindow`.|
|[SetExternalDispatch](#setexternaldispatch)|Define a interface de expedição externa usada pelo objeto `CAxWindow`.|
|[SetExternalUIHandler](#setexternaluihandler)|Define a interface de `IDocHostUIHandler` externa usada pelo objeto `CAxWindow`.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operador =](#operator_eq)|Atribui um HWND a um objeto de `CAxWindow` existente.|

## <a name="remarks"></a>Comentários

Essa classe fornece métodos para manipular uma janela que hospeda um controle ActiveX. A hospedagem é fornecida por " **AtlAxWin80"** , que é encapsulado por `CAxWindow`.

A classe `CAxWindow` é implementada como uma especialização da classe `CAxWindowT`. Essa especialização é declarada como:

`typedef CAxWindowT<CWindow> CAxWindow;`

Se você precisar alterar a classe base, poderá usar `CAxWindowT` e especificar a nova classe base como um argumento de modelo.

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** atlwin. h

##  <a name="attachcontrol"></a>CAxWindow::AttachControl

Cria um novo objeto de host se um já não estiver presente e anexa o controle especificado ao host.

```
HRESULT AttachControl(
    IUnknown* pControl,
    IUnknown** ppUnkContainer);
```

### <a name="parameters"></a>Parâmetros

*pControl*<br/>
no Um ponteiro para a `IUnknown` do controle.

*ppUnkContainer*<br/>
fora Um ponteiro para a `IUnknown` do host (o objeto `AxWin`).

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

O objeto de controle que está sendo anexado deve ser inicializado corretamente antes de chamar `AttachControl`.

##  <a name="caxwindow"></a>CAxWindow::CAxWindow

Constrói um objeto `CAxWindow` usando um identificador de objeto de janela existente.

```
CAxWindow(HWND hWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
Um identificador para um objeto de janela existente.

##  <a name="createcontrol"></a>CAxWindow:: CreateControl

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
Um ponteiro para uma cadeia de caracteres para criar o controle. Deve ser formatada de uma das seguintes maneiras:

- Um ProgID como `"MSCAL.Calendar.7"`

- Um CLSID, como `"{8E27C92B-1264-101C-8A2F-040224009C02}"`

- Uma URL como `"<https://www.microsoft.com>"`

- Uma referência a um documento ativo, como `"file://\\\Documents\MyDoc.doc"`

- Um fragmento de HTML, como `"MSHTML:\<HTML>\<BODY>This is a line of text\</BODY>\</HTML>"`

   > [!NOTE]
   > `"MSHTML:"` deve preceder o fragmento HTML para que ele seja designado como sendo um fluxo MSHTML. Somente o ProgID e o CLSID têm suporte em plataformas Windows Mobile. Windows CE plataformas incorporadas, além do Windows Mobile com suporte para CE IE, oferecem suporte a todos os tipos, incluindo ProgID, CLSID, URL, referência ao documento ativo e fragmento de HTML.

*pStream*<br/>
no Um ponteiro para um fluxo que é usado para inicializar as propriedades do controle. Pode ser NULO.

*ppUnkContainer*<br/>
fora O endereço de um ponteiro que receberá a `IUnknown` do contêiner. Pode ser NULO.

*dwResID*<br/>
A ID de recurso de um recurso HTML. O controle WebBrowser será criado e carregado com o recurso especificado.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Se a segunda versão desse método for usada, um controle HTML será criado e vinculado ao recurso identificado por *dwResID*.

Esse método fornece o mesmo resultado que chamar:

[!code-cpp[NVC_ATL_Windowing#42](../../atl/codesnippet/cpp/caxwindow-class_1.cpp)]

Consulte [CAxWindow2T:: CreateControlLic](../../atl/reference/caxwindow2t-class.md#createcontrollic) para criar, inicializar e hospedar um controle ActiveX licenciado.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Consulte [hospedando controles ActiveX usando o ATL AxHost](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo que usa `CreateControl`.

##  <a name="createcontrolex"></a>CAxWindow::CreateControlEx

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
Um ponteiro para uma cadeia de caracteres para criar o controle. Deve ser formatada de uma das seguintes maneiras:

- Um ProgID como `"MSCAL.Calendar.7"`

- Um CLSID, como `"{8E27C92B-1264-101C-8A2F-040224009C02}"`

- Uma URL como `"<https://www.microsoft.com>"`

- Uma referência a um documento ativo, como `"file://\\\Documents\MyDoc.doc"`

- Um fragmento de HTML, como `"MSHTML:\<HTML>\<BODY>This is a line of text\</BODY>\</HTML>"`

   > [!NOTE]
   > `"MSHTML:"` deve preceder o fragmento HTML para que ele seja designado como sendo um fluxo MSHTML. Somente o ProgID e o CLSID têm suporte em plataformas Windows Mobile. Windows CE plataformas incorporadas, além do Windows Mobile com suporte para CE IE, oferecem suporte a todos os tipos, incluindo ProgID, CLSID, URL, referência ao documento ativo e fragmento de HTML.

*pStream*<br/>
no Um ponteiro para um fluxo que é usado para inicializar as propriedades do controle. Pode ser NULO.

*ppUnkContainer*<br/>
fora O endereço de um ponteiro que receberá a `IUnknown` do contêiner. Pode ser NULO.

*ppUnkControl*<br/>
fora O endereço de um ponteiro que receberá a `IUnknown` do controle. Pode ser NULO.

*iidSink*<br/>
no O identificador de interface de uma interface de saída no objeto contido. Pode ser IID_NULL.

*punkSink*<br/>
no Um ponteiro para a interface de `IUnknown` do objeto de coletor a ser conectado ao ponto de conexão no objeto contido especificado por *iidSink*.

*dwResID*<br/>
no A ID de recurso de um recurso HTML. O controle WebBrowser será criado e carregado com o recurso especificado.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Esse método é semelhante a [CAxWindow:: CreateControl](#createcontrol), mas ao contrário desse método, `CreateControlEx` também permite que você receba um ponteiro de interface para o controle recém-criado e configure um coletor de eventos para receber eventos acionados pelo controle.

Consulte [CAxWindow2T:: CreateControlLicEx](../../atl/reference/caxwindow2t-class.md#createcontrollicex) para criar, inicializar e hospedar um controle ActiveX licenciado.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Consulte [hospedando controles ActiveX usando o ATL AxHost](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo que usa `CreateControlEx`.

##  <a name="getwndclassname"></a>CAxWindow::GetWndClassName

Recupera o nome da classe de janela.

```
static LPCTSTR GetWndClassName();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma cadeia de caracteres que contém o nome da classe de janela que pode hospedar controles ActiveX não licenciados.

##  <a name="operator_eq"></a>CAxWindow:: Operator =

Atribui um HWND a um objeto de `CAxWindow` existente.

```
CAxWindow<TBase>& operator=(HWND hWnd);
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
Um identificador para uma janela existente.

### <a name="return-value"></a>Valor retornado

Retorna uma referência ao objeto de `CAxWindow` atual.

##  <a name="querycontrol"></a>CAxWindow::QueryControl

Recupera a interface especificada do controle hospedado.

```
HRESULT QueryControl(REFIID iid, void** ppUnk);
template <class  Q>
HRESULT QueryControl(Q** ppUnk);
```

### <a name="parameters"></a>Parâmetros

*IID*<br/>
no Especifica o IID da interface do controle.

*ppUnk*<br/>
fora Um ponteiro para a interface do controle. Na versão de modelo deste método, não há necessidade de uma ID de referência, desde que uma interface tipada com um UUID associado seja passada.

*Q*<br/>
no A interface que está sendo consultada.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

##  <a name="queryhost"></a>CAxWindow::QueryHost

Retorna a interface especificada do host.

```
HRESULT QueryHost(REFIID iid, void** ppUnk);
template <class  Q>
HRESULT QueryHost(Q** ppUnk);
```

### <a name="parameters"></a>Parâmetros

*IID*<br/>
no Especifica o IID da interface do controle.

*ppUnk*<br/>
fora Um ponteiro para a interface no host. Na versão de modelo deste método, não há necessidade de uma ID de referência, desde que uma interface tipada com um UUID associado seja passada.

*Q*<br/>
no A interface que está sendo consultada.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A interface do host permite acesso à funcionalidade subjacente do código de Hospedagem de janela, implementada por `AxWin`.

##  <a name="setexternaldispatch"></a>CAxWindow::SetExternalDispatch

Define a interface de expedição externa para o objeto `CAxWindow`.

```
HRESULT SetExternalDispatch(IDispatch* pDisp);
```

### <a name="parameters"></a>Parâmetros

*pDisp*<br/>
no Um ponteiro para uma interface `IDispatch`.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

##  <a name="setexternaluihandler"></a>CAxWindow::SetExternalUIHandler

Define a interface [IDocHostUIHandlerDispatch](../../atl/reference/idochostuihandlerdispatch-interface.md) externa para o objeto `CAxWindow`.

```
HRESULT SetExternalUIHandler(IDocHostUIHandlerDispatch* pUIHandler);
```

### <a name="parameters"></a>Parâmetros

*pUIHandler*<br/>
no Um ponteiro para uma interface `IDocHostUIHandlerDispatch`.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A interface de `IDocHostUIHandlerDispatch` externa é usada pelos controles que consultam o site do host para a interface `IDocHostUIHandlerDispatch`. O controle WebBrowser é um controle que faz isso.

## <a name="see-also"></a>Consulte também

[Exemplo de ATLCON](../../overview/visual-cpp-samples.md)<br/>
[Classe CWindow](../../atl/reference/cwindow-class.md)<br/>
[Fundamentos do controle composto](../../atl/atl-composite-control-fundamentals.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Perguntas frequentes sobre confinamento de controle](../../atl/atl-control-containment-faq.md)
