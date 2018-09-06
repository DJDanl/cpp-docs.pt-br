---
title: Classe CAxWindow | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- CAxWindow class
- ATL, hosting ActiveX controls
ms.assetid: 85e79261-43e4-4770-bde0-1ff87f222b0f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0eda5fc385f094bd7a18bff521250453ebb66c84
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43757930"
---
# <a name="caxwindow-class"></a>Classe CAxWindow

Essa classe fornece métodos para manipular uma janela de hospedando um controle ActiveX.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CAxWindow : public CWindow
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[AttachControl](#attachcontrol)|Anexa um controle ActiveX existente para o `CAxWindow` objeto.|
|[CAxWindow](#caxwindow)|Constrói um objeto `CAxWindow`.|
|[CreateControl](#createcontrol)|Cria um controle ActiveX, inicializa-o e hospeda-o no `CAxWindow` janela.|
|[CreateControlEx](#createcontrolex)|Cria um controle ActiveX e recupera um ponteiro de interface (ou ponteiros) do controle.|
|[GetWndClassName](#getwndclassname)|(Estático) Recupera o nome de classe predefinida do `CAxWindow` objeto.|
|[QueryControl](#querycontrol)|Recupera o `IUnknown` do controle ActiveX hospedado.|
|[QueryHost](#queryhost)|Recupera o `IUnknown` ponteiro do `CAxWindow` objeto.|
|[SetExternalDispatch](#setexternaldispatch)|Define a interface de expedição externa usada pelo `CAxWindow` objeto.|
|[SetExternalUIHandler](#setexternaluihandler)|Define o externo `IDocHostUIHandler` interface usada pelo `CAxWindow` objeto.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operador =](#operator_eq)|Atribui um HWND um existente `CAxWindow` objeto.|

## <a name="remarks"></a>Comentários

Essa classe fornece métodos para manipular uma janela que hospeda um controle ActiveX. A hospedagem é fornecida por " **AtlAxWin80"**, que é encapsulado por `CAxWindow`.

Classe `CAxWindow` é implementado como uma especialização do `CAxWindowT` classe. Essa especialização é declarada como:

`typedef CAxWindowT<CWindow> CAxWindow;`

Se você precisar alterar a classe base, você pode usar `CAxWindowT` e especifique a nova classe base como um argumento de modelo.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="attachcontrol"></a>  CAxWindow::AttachControl

Cria um novo objeto de host, caso ainda não estiver presente e anexa o controle especificado para o host.

```
HRESULT AttachControl(
    IUnknown* pControl,
    IUnknown** ppUnkContainer);
```

### <a name="parameters"></a>Parâmetros

*pControl*  
[in] Um ponteiro para o `IUnknown` do controle.

*ppUnkContainer*  
[out] Um ponteiro para o `IUnknown` do host (a `AxWin` objeto).

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

O objeto de controle que está sendo anexado deve ser inicializado corretamente antes de chamar `AttachControl`.

##  <a name="caxwindow"></a>  CAxWindow::CAxWindow

Constrói um `CAxWindow` usando um identificador de objeto de janela existente do objeto.

```
CAxWindow(HWND hWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*hWnd*  
Um identificador para um objeto de janela existente.

##  <a name="createcontrol"></a>  CAxWindow::CreateControl

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

*lpszName*  
Um ponteiro para uma cadeia de caracteres para criar o controle. Deve ser formatado em uma das seguintes maneiras:

- Um ProgID, como "MSCAL. Calendar.7 "

- Um CLSID, como "{8E27C92B-1264-101C-8A2F-040224009C02}"

- Uma URL, como "http://www.microsoft.com"

- Uma referência a um documento ativo, como "file://\\\Documents\MyDoc.doc"

- Um fragmento de HTML, como "MSHTML:\<HTML >\<corpo > Esta é uma linha de texto\</BODY >\</HTML mais externas >"

   > [!NOTE]
   > "MSHTML:" deve preceder o fragmento HTML para que ela é designada como sendo um fluxo de MSHTML. Somente o ProgID e CLSID têm suporte em plataformas Windows Mobile. Plataformas incorporadas do Windows CE, que não seja o Windows Mobile com o suporte para o suporte do IE CE todos os tipos, incluindo ProgID, CLSID, URL, de referência para o documento ativo e o fragmento de HTML.

*pStream*  
[in] Um ponteiro para um fluxo que é usado para inicializar as propriedades do controle. Pode ser NULL.

*ppUnkContainer*  
[out] O endereço de um ponteiro que receberá o `IUnknown` do contêiner. Pode ser NULL.

*dwResID*  
A ID de recurso de um recurso HTML. O controle WebBrowser será criado e carregado com o recurso especificado.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Se a segunda versão desse método é usada, um controle HTML é criado e associado ao recurso identificado pelo *dwResID*.

Esse método oferece o mesmo resultado de chamada:

[!code-cpp[NVC_ATL_Windowing#42](../../atl/codesnippet/cpp/caxwindow-class_1.cpp)]

Ver [CAxWindow2T::CreateControlLic](../../atl/reference/caxwindow2t-class.md#createcontrollic) para criar, inicializar e hospedar um controle ActiveX licenciado.

### <a name="example"></a>Exemplo

Ver [hospedagem de AXHost de ATL usando do ActiveX controles](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo que usa `CreateControl`.

##  <a name="createcontrolex"></a>  CAxWindow::CreateControlEx

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

*lpszName*  
Um ponteiro para uma cadeia de caracteres para criar o controle. Deve ser formatado em uma das seguintes maneiras:

- Um ProgID, como "MSCAL. Calendar.7 "

- Um CLSID, como "{8E27C92B-1264-101C-8A2F-040224009C02}"

- Uma URL, como "http://www.microsoft.com"

- Uma referência a um documento ativo, como "file://\\\Documents\MyDoc.doc"

- Um fragmento de HTML, como "MSHTML:\<HTML >\<corpo > Esta é uma linha de texto\</BODY >\</HTML mais externas >"

   > [!NOTE]
   > "MSHTML:" deve preceder o fragmento HTML para que ela é designada como sendo um fluxo de MSHTML. Somente o ProgID e CLSID têm suporte em plataformas Windows Mobile. Plataformas incorporadas do Windows CE, que não seja o Windows Mobile com o suporte para o suporte do IE CE todos os tipos, incluindo ProgID, CLSID, URL, de referência para o documento ativo e o fragmento de HTML.

*pStream*  
[in] Um ponteiro para um fluxo que é usado para inicializar as propriedades do controle. Pode ser NULL.

*ppUnkContainer*  
[out] O endereço de um ponteiro que receberá o `IUnknown` do contêiner. Pode ser NULL.

*ppUnkControl*  
[out] O endereço de um ponteiro que receberá o `IUnknown` do controle. Pode ser NULL.

*iidSink*  
[in] O identificador de interface de uma interface de saída o objeto contido. Pode ser IID_NULL.

*punkSink*  
[in] Um ponteiro para o `IUnknown` interface do objeto coletor a ser conectado ao ponto de conexão no objeto independente especificado pelo *iidSink*.

*dwResID*  
[in] A ID de recurso de um recurso HTML. O controle WebBrowser será criado e carregado com o recurso especificado.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Esse método é semelhante à [CAxWindow::CreateControl](#createcontrol), mas ao contrário desse método, `CreateControlEx` também permite que você receber um ponteiro de interface para o controle criado recentemente e configurar um coletor de eventos para receber eventos acionados pelo controle.

Ver [CAxWindow2T::CreateControlLicEx](../../atl/reference/caxwindow2t-class.md#createcontrollicex) para criar, inicializar e hospedar um controle ActiveX licenciado.

### <a name="example"></a>Exemplo

Ver [hospedagem de AXHost de ATL usando do ActiveX controles](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo que usa `CreateControlEx`.

##  <a name="getwndclassname"></a>  CAxWindow::GetWndClassName

Recupera o nome da classe de janela.

```
static LPCTSTR GetWndClassName();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para uma cadeia de caracteres que contém o nome da classe de janela que pode hospedar controles do ActiveX nonlicensed.

##  <a name="operator_eq"></a>  CAxWindow::operator =

Atribui um HWND um existente `CAxWindow` objeto.

```
CAxWindow<TBase>& operator=(HWND hWnd);
```

### <a name="parameters"></a>Parâmetros

*hWnd*  
Um identificador para uma janela existente.

### <a name="return-value"></a>Valor de retorno

Retorna uma referência ao atual `CAxWindow` objeto.

##  <a name="querycontrol"></a>  CAxWindow::QueryControl

Recupera a interface especificada do controle hospedado.

```
HRESULT QueryControl(REFIID iid, void** ppUnk);
template <class  Q>
HRESULT QueryControl(Q** ppUnk);
```

### <a name="parameters"></a>Parâmetros

*IID*  
[in] Especifica o IID da interface do controle.

*ppUnk*  
[out] Um ponteiro para a interface do controle. Na versão do modelo desse método, não é necessário para uma ID de referência como uma interface digitada com um UUID associado é passada.

*Q*  
[in] A interface que está sendo consultada para.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

##  <a name="queryhost"></a>  CAxWindow::QueryHost

Retorna a interface especificada do host.

```
HRESULT QueryHost(REFIID iid, void** ppUnk);
template <class  Q>
HRESULT QueryHost(Q** ppUnk);
```

### <a name="parameters"></a>Parâmetros

*IID*  
[in] Especifica o IID da interface do controle.

*ppUnk*  
[out] Um ponteiro para a interface no host. Na versão do modelo desse método, não é necessário para uma ID de referência como uma interface digitada com um UUID associado é passada.

*Q*  
[in] A interface que está sendo consultada para.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

A interface do host permite que o acesso à funcionalidade subjacente do código de hospedagem de janela, implementado pelo `AxWin`.

##  <a name="setexternaldispatch"></a>  CAxWindow::SetExternalDispatch

Define a interface de expedição externo para o `CAxWindow` objeto.

```
HRESULT SetExternalDispatch(IDispatch* pDisp);
```

### <a name="parameters"></a>Parâmetros

*pDisp*  
[in] Um ponteiro para um `IDispatch` interface.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

##  <a name="setexternaluihandler"></a>  CAxWindow::SetExternalUIHandler

Define o externo [IDocHostUIHandlerDispatch](../../atl/reference/idochostuihandlerdispatch-interface.md) interface para o `CAxWindow` objeto.

```
HRESULT SetExternalUIHandler(IDocHostUIHandlerDispatch* pUIHandler);
```

### <a name="parameters"></a>Parâmetros

*pUIHandler*  
[in] Um ponteiro para um `IDocHostUIHandlerDispatch` interface.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

O external `IDocHostUIHandlerDispatch` interface é usada por controles que consultar o site do host para o `IDocHostUIHandlerDispatch` interface. O controle WebBrowser é um controle que faz isso.

## <a name="see-also"></a>Consulte também

[Exemplo ATLCON](../../visual-cpp-samples.md)   
[Classe CWindow](../../atl/reference/cwindow-class.md)   
[Fundamentos do controle composto](../../atl/atl-composite-control-fundamentals.md)   
[Visão geral da classe](../../atl/atl-class-overview.md)   
[Perguntas frequentes sobre contenção de controle](../../atl/atl-control-containment-faq.md)

