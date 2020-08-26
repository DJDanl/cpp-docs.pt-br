---
title: Classe CDHtmlDialog
ms.date: 03/27/2019
f1_keywords:
- CDHtmlDialog
- AFXDHTML/CDHtmlDialog
- AFXDHTML/CDHtmlDialog::CDHtmlDialog
- AFXDHTML/CDHtmlDialog::CanAccessExternal
- AFXDHTML/CDHtmlDialog::CreateControlSite
- AFXDHTML/CDHtmlDialog::DDX_DHtml_AxControl
- AFXDHTML/CDHtmlDialog::DDX_DHtml_CheckBox
- AFXDHTML/CDHtmlDialog::DDX_DHtml_ElementText
- AFXDHTML/CDHtmlDialog::DDX_DHtml_Radio
- AFXDHTML/CDHtmlDialog::DDX_DHtml_SelectIndex
- AFXDHTML/CDHtmlDialog::DDX_DHtml_SelectString
- AFXDHTML/CDHtmlDialog::DDX_DHtml_SelectValue
- AFXDHTML/CDHtmlDialog::DestroyModeless
- AFXDHTML/CDHtmlDialog::EnableModeless
- AFXDHTML/CDHtmlDialog::FilterDataObject
- AFXDHTML/CDHtmlDialog::GetControlDispatch
- AFXDHTML/CDHtmlDialog::GetControlProperty
- AFXDHTML/CDHtmlDialog::GetCurrentUrl
- AFXDHTML/CDHtmlDialog::GetDHtmlDocument
- AFXDHTML/CDHtmlDialog::GetDropTarget
- AFXDHTML/CDHtmlDialog::GetElement
- AFXDHTML/CDHtmlDialog::GetElementHtml
- AFXDHTML/CDHtmlDialog::GetElementInterface
- AFXDHTML/CDHtmlDialog::GetElementProperty
- AFXDHTML/CDHtmlDialog::GetElementText
- AFXDHTML/CDHtmlDialog::GetEvent
- AFXDHTML/CDHtmlDialog::GetExternal
- AFXDHTML/CDHtmlDialog::GetHostInfo
- AFXDHTML/CDHtmlDialog::GetOptionKeyPath
- AFXDHTML/CDHtmlDialog::HideUI
- AFXDHTML/CDHtmlDialog::IsExternalDispatchSafe
- AFXDHTML/CDHtmlDialog::LoadFromResource
- AFXDHTML/CDHtmlDialog::Navigate
- AFXDHTML/CDHtmlDialog::OnBeforeNavigate
- AFXDHTML/CDHtmlDialog::OnDocumentComplete
- AFXDHTML/CDHtmlDialog::OnDocWindowActivate
- AFXDHTML/CDHtmlDialog::OnFrameWindowActivate
- AFXDHTML/CDHtmlDialog::OnInitDialog
- AFXDHTML/CDHtmlDialog::OnNavigateComplete
- AFXDHTML/CDHtmlDialog::ResizeBorder
- AFXDHTML/CDHtmlDialog::SetControlProperty
- AFXDHTML/CDHtmlDialog::SetElementHtml
- AFXDHTML/CDHtmlDialog::SetElementProperty
- AFXDHTML/CDHtmlDialog::SetElementText
- AFXDHTML/CDHtmlDialog::SetExternalDispatch
- AFXDHTML/CDHtmlDialog::SetHostFlags
- AFXDHTML/CDHtmlDialog::ShowContextMenu
- AFXDHTML/CDHtmlDialog::ShowUI
- AFXDHTML/CDHtmlDialog::TranslateAccelerator
- AFXDHTML/CDHtmlDialog::TranslateUrl
- AFXDHTML/CDHtmlDialog::UpdateUI
- AFXDHTML/CDHtmlDialog::m_bUseHtmlTitle
- AFXDHTML/CDHtmlDialog::m_nHtmlResID
- AFXDHTML/CDHtmlDialog::m_pBrowserApp
- AFXDHTML/CDHtmlDialog::m_spHtmlDoc
- AFXDHTML/CDHtmlDialog::m_strCurrentUrl
- AFXDHTML/CDHtmlDialog::m_szHtmlResID
helpviewer_keywords:
- CDHtmlDialog [MFC], CDHtmlDialog
- CDHtmlDialog [MFC], CanAccessExternal
- CDHtmlDialog [MFC], CreateControlSite
- CDHtmlDialog [MFC], DDX_DHtml_AxControl
- CDHtmlDialog [MFC], DDX_DHtml_CheckBox
- CDHtmlDialog [MFC], DDX_DHtml_ElementText
- CDHtmlDialog [MFC], DDX_DHtml_Radio
- CDHtmlDialog [MFC], DDX_DHtml_SelectIndex
- CDHtmlDialog [MFC], DDX_DHtml_SelectString
- CDHtmlDialog [MFC], DDX_DHtml_SelectValue
- CDHtmlDialog [MFC], DestroyModeless
- CDHtmlDialog [MFC], EnableModeless
- CDHtmlDialog [MFC], FilterDataObject
- CDHtmlDialog [MFC], GetControlDispatch
- CDHtmlDialog [MFC], GetControlProperty
- CDHtmlDialog [MFC], GetCurrentUrl
- CDHtmlDialog [MFC], GetDHtmlDocument
- CDHtmlDialog [MFC], GetDropTarget
- CDHtmlDialog [MFC], GetElement
- CDHtmlDialog [MFC], GetElementHtml
- CDHtmlDialog [MFC], GetElementInterface
- CDHtmlDialog [MFC], GetElementProperty
- CDHtmlDialog [MFC], GetElementText
- CDHtmlDialog [MFC], GetEvent
- CDHtmlDialog [MFC], GetExternal
- CDHtmlDialog [MFC], GetHostInfo
- CDHtmlDialog [MFC], GetOptionKeyPath
- CDHtmlDialog [MFC], HideUI
- CDHtmlDialog [MFC], IsExternalDispatchSafe
- CDHtmlDialog [MFC], LoadFromResource
- CDHtmlDialog [MFC], Navigate
- CDHtmlDialog [MFC], OnBeforeNavigate
- CDHtmlDialog [MFC], OnDocumentComplete
- CDHtmlDialog [MFC], OnDocWindowActivate
- CDHtmlDialog [MFC], OnFrameWindowActivate
- CDHtmlDialog [MFC], OnInitDialog
- CDHtmlDialog [MFC], OnNavigateComplete
- CDHtmlDialog [MFC], ResizeBorder
- CDHtmlDialog [MFC], SetControlProperty
- CDHtmlDialog [MFC], SetElementHtml
- CDHtmlDialog [MFC], SetElementProperty
- CDHtmlDialog [MFC], SetElementText
- CDHtmlDialog [MFC], SetExternalDispatch
- CDHtmlDialog [MFC], SetHostFlags
- CDHtmlDialog [MFC], ShowContextMenu
- CDHtmlDialog [MFC], ShowUI
- CDHtmlDialog [MFC], TranslateAccelerator
- CDHtmlDialog [MFC], TranslateUrl
- CDHtmlDialog [MFC], UpdateUI
- CDHtmlDialog [MFC], m_bUseHtmlTitle
- CDHtmlDialog [MFC], m_nHtmlResID
- CDHtmlDialog [MFC], m_pBrowserApp
- CDHtmlDialog [MFC], m_spHtmlDoc
- CDHtmlDialog [MFC], m_strCurrentUrl
- CDHtmlDialog [MFC], m_szHtmlResID
ms.assetid: 3f941c85-87e1-4f0f-9cc5-ffee8498b312
ms.openlocfilehash: 9cc01c94357d7aac7fa6fa98127628a60746e1e8
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88842878"
---
# <a name="cdhtmldialog-class"></a>Classe CDHtmlDialog

É usado para criar caixas de diálogo que usam HTML em vez de recursos de caixa de diálogo para implementar a interface do usuário.

## <a name="syntax"></a>Sintaxe

```
class CDHtmlDialog : public CDialog, public CDHtmlEventSink
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDHtmlDialog:: CDHtmlDialog](#cdhtmldialog)|Constrói um objeto CDHtmlDialog.|
|[CDHtmlDialog:: ~ CDHtmlDialog](#_dtorcdhtmldialog)|Destrói um objeto CDHtmlDialog.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDHtmlDialog:: CanAccessExternal](#canaccessexternal)|Substituível que é chamado como uma verificação de acesso para ver se os objetos de script na página carregada podem acessar o despacho externo do site de controle. Verifica se o despacho é seguro para scripts ou se a zona atual permite objetos que não são seguros para scripts.|
|[CDHtmlDialog:: CreateControlSite](#createcontrolsite)|Substituível usado para criar uma instância de site de controle para hospedar o controle WebBrowser na caixa de diálogo.|
|[CDHtmlDialog::D DX_DHtml_AxControl](#ddx_dhtml_axcontrol)|Troca dados entre uma variável de membro e o valor da propriedade de um controle ActiveX em uma página HTML.|
|[CDHtmlDialog::D DX_DHtml_CheckBox](#ddx_dhtml_checkbox)|Troca dados entre uma variável de membro e uma caixa de seleção em uma página HTML.|
|[CDHtmlDialog::D DX_DHtml_ElementText](#ddx_dhtml_elementtext)|Troca dados entre uma variável de membro e qualquer propriedade de elemento HTML em uma página HTML.|
|[CDHtmlDialog::D DX_DHtml_Radio](#ddx_dhtml_radio)|Troca dados entre uma variável de membro e um botão de opção em uma página HTML.|
|[CDHtmlDialog::D DX_DHtml_SelectIndex](#ddx_dhtml_selectindex)|Obtém ou define o índice de uma caixa de listagem em uma página HTML.|
|[CDHtmlDialog::D DX_DHtml_SelectString](#ddx_dhtml_selectstring)|Obtém ou define o texto de exibição de uma entrada da caixa de listagem (com base no índice atual) em uma página HTML.|
|[CDHtmlDialog::D DX_DHtml_SelectValue](#ddx_dhtml_selectvalue)|Obtém ou define o valor de uma entrada da caixa de listagem (com base no índice atual) em uma página HTML.|
|[CDHtmlDialog::D estroyModeless](#destroymodeless)|Destrói uma caixa de diálogo sem janela restrita.|
|[CDHtmlDialog:: EnableModeless](#enablemodeless)|Habilita caixas de diálogo sem janela restrita.|
|[CDHtmlDialog:: FilterDataObject](#filterdataobject)|Permite que a caixa de diálogo filtre objetos de dados da área de transferência criados pelo navegador hospedado.|
|[CDHtmlDialog:: GetControlDispatch](#getcontroldispatch)|Recupera a `IDispatch` interface em um controle ActiveX inserido no documento HTML.|
|[CDHtmlDialog:: getcontrolproperty](#getcontrolproperty)|Recupera a propriedade solicitada do controle ActiveX especificado.|
|[CDHtmlDialog:: GetCurrentUrl](#getcurrenturl)|Recupera o Uniform Resource Locator (URL) associado ao documento atual.|
|[CDHtmlDialog:: GetDHtmlDocument](#getdhtmldocument)|Recupera a interface IHTMLDocument2 no documento HTML carregado no momento.|
|[CDHtmlDialog:: GetDropTarget](#getdroptarget)|Chamado pelo controle WebBrowser contido quando ele está sendo usado como um destino de soltar para permitir que a caixa de diálogo forneça um [IDropTarget](/windows/win32/api/oleidl/nn-oleidl-idroptarget)alternativo.|
|[CDHtmlDialog:: GetElement](#getelement)|Obtém uma interface em um elemento HTML.|
|[CDHtmlDialog:: GetElementHtml](#getelementhtml)|Recupera a `innerHTML` propriedade de um elemento HTML.|
|[CDHtmlDialog:: GetElementInterface](#getelementinterface)|Recupera o ponteiro de interface solicitado de um elemento HTML.|
|[CDHtmlDialog:: getelementproperty](#getelementproperty)|Recupera o valor da propriedade de um elemento HTML.|
|[CDHtmlDialog:: GetElementText](#getelementtext)|Recupera a `innerText` propriedade de um elemento HTML.|
|[CDHtmlDialog:: GetEvent](#getevent)|Obtém o `IHTMLEventObj` ponteiro para o objeto de evento atual.|
|[CDHtmlDialog:: GetExternal](#getexternal)|Obtém a interface do host `IDispatch` .|
|[CDHtmlDialog:: GetHostInfo](#gethostinfo)|Recupera os recursos da interface do usuário do host.|
|[CDHtmlDialog:: GetOptionKeyPath](#getoptionkeypath)|Recupera a chave do registro sob a qual as preferências do usuário são armazenadas.|
|[CDHtmlDialog:: HideUI](#hideui)|Oculta a interface do usuário do host.|
|[CDHtmlDialog:: IsExternalDispatchSafe](#isexternaldispatchsafe)|Indica se a interface do host `IDispatch` é segura para scripts.|
|[CDHtmlDialog:: LoadFromResource](#loadfromresource)|Carrega o recurso especificado no controle WebBrowser.|
|[CDHtmlDialog:: navegar](#navigate)|Navega para a URL especificada.|
|[CDHtmlDialog:: OnBeforeNavigate](#onbeforenavigate)|Chamado pelo Framework antes de um evento de navegação ser acionado.|
|[CDHtmlDialog:: OnDocumentComplete](#ondocumentcomplete)|Chamado pelo Framework para notificar um aplicativo quando um documento atingir o estado de READYSTATE_COMPLETE.|
|[CDHtmlDialog:: OnDocWindowActivate](#ondocwindowactivate)|Chamado pelo Framework quando a janela do documento é ativada ou desativada.|
|[CDHtmlDialog:: OnFrameWindowActivate](#onframewindowactivate)|Chamado pelo Framework quando a janela do quadro é ativada ou desativada.|
|[CDHtmlDialog:: OnInitDialog](#oninitdialog)|Chamado em resposta à mensagem de WM_INITDIALOG.|
|[CDHtmlDialog:: OnNavigateComplete](#onnavigatecomplete)|Chamado pelo Framework após a conclusão de um evento de navegação.|
|[CDHtmlDialog:: ResizeBorder](#resizeborder)|Alerta o objeto de que precisa para redimensionar seu espaço de borda.|
|[CDHtmlDialog:: setcontrolproperty](#setcontrolproperty)|Define a propriedade de um controle ActiveX para um novo valor.|
|[CDHtmlDialog:: SetElementHtml](#setelementhtml)|Define a `innerHTML` propriedade de um elemento HTML.|
|[CDHtmlDialog:: setelementproperty](#setelementproperty)|Define uma propriedade de um elemento HTML.|
|[CDHtmlDialog:: SetElementText](#setelementtext)|Define a `innerText` propriedade de um elemento HTML.|
|[CDHtmlDialog:: SetExternalDispatch](#setexternaldispatch)|Define a interface do host `IDispatch` .|
|[CDHtmlDialog:: SetHostFlags](#sethostflags)|Define os sinalizadores da interface do usuário do host.|
|[CDHtmlDialog:: addcontextmenu](#showcontextmenu)|Chamado quando um menu de contexto está prestes a ser exibido.|
|[CDHtmlDialog:: ShowUI](#showui)|Mostra a interface do usuário do host.|
|[CDHtmlDialog:: TranslateAccelerator](#translateaccelerator)|Chamado para processar mensagens de chave do acelerador de menu.|
|[CDHtmlDialog:: TranslateUrl](#translateurl)|Chamado para modificar a URL a ser carregada.|
|[CDHtmlDialog:: UpdateUI](#updateui)|Chamado para notificar o host que o estado do comando foi alterado.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDHtmlDialog:: m_bUseHtmlTitle](#m_busehtmltitle)|Indica se o título do documento HTML deve ser usado como a legenda da caixa de diálogo.|
|[CDHtmlDialog:: m_nHtmlResID](#m_nhtmlresid)|ID de recurso do recurso HTML a ser exibido.|
|[CDHtmlDialog:: m_pBrowserApp](#m_pbrowserapp)|Um ponteiro para um aplicativo de navegador da Web.|
|[CDHtmlDialog:: m_spHtmlDoc](#m_sphtmldoc)|Um ponteiro para um documento HTML.|
|[CDHtmlDialog:: m_strCurrentUrl](#m_strcurrenturl)|A URL atual.|
|[CDHtmlDialog:: m_szHtmlResID](#m_szhtmlresid)|Versão da cadeia de caracteres da ID do recurso HTML.|

## <a name="remarks"></a>Comentários

`CDHtmlDialog` pode carregar o HTML a ser exibido por meio de um recurso HTML ou de uma URL.

`CDHtmlDialog` também pode fazer troca de dados com controles HTML e manipular eventos de controles HTML, como cliques de botão.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CDHtmlSinkHandlerBase2`

`CDHtmlSinkHandlerBase1`

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

`CDHtmlSinkHandler`

[CWnd](../../mfc/reference/cwnd-class.md)

`CDHtmlEventSink`

[CDialog](../../mfc/reference/cdialog-class.md)

`CDHtmlDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdhtml. h

## <a name="ddx_dhtml-helper-macros"></a><a name="ddx_dhtml_helper_macros"></a> DDX_DHtml macros auxiliares

As macros auxiliares DDX_DHtml permitem acesso fácil às propriedades de controles geralmente usadas em uma página HTML.

### <a name="data-exchange-macros"></a>Macros de troca de dados

|Nome|Descrição|
|-|-|
|[DDX_DHtml_ElementValue](../../mfc/reference/ddx-dhtml-helper-macros.md#ddx_dhtml_elementvalue)|Define ou recupera a propriedade Value do controle selecionado.|
|[DDX_DHtml_ElementInnerText](../../mfc/reference/ddx-dhtml-helper-macros.md#ddx_dhtml_elementinnertext)|Define ou recupera o texto entre as marcas de início e de fim do elemento atual.|
|[DDX_DHtml_ElementInnerHtml](../../mfc/reference/ddx-dhtml-helper-macros.md#ddx_dhtml_elementinnerhtml)|Define ou recupera o HTML entre as marcas de início e de fim do elemento atual.|
|[DDX_DHtml_Anchor_Href](../../mfc/reference/ddx-dhtml-helper-macros.md#ddx_dhtml_anchor_href)|Define ou recupera a URL de destino ou o ponto de ancoragem.|
|[DDX_DHtml_Anchor_Target](../../mfc/reference/ddx-dhtml-helper-macros.md#ddx_dhtml_anchor_target)|Define ou recupera a janela ou o quadro de destino.|
|[DDX_DHtml_Img_Src](../../mfc/reference/ddx-dhtml-helper-macros.md#ddx_dhtml_img_src)|Define ou recupera o nome de uma imagem ou um clipe de vídeo no documento.|
|[DDX_DHtml_Frame_Src](../../mfc/reference/ddx-dhtml-helper-macros.md#ddx_dhtml_frame_src)|Define ou recupera a URL do quadro associado.|
|[DDX_DHtml_IFrame_Src](../../mfc/reference/ddx-dhtml-helper-macros.md#ddx_dhtml_iframe_src)|Define ou recupera a URL do quadro associado.|

## <a name="cdhtmldialogcanaccessexternal"></a><a name="canaccessexternal"></a> CDHtmlDialog:: CanAccessExternal

Substituível que é chamado como uma verificação de acesso para ver se os objetos de script na página carregada podem acessar o despacho externo do site de controle. Verifica se o despacho é seguro para scripts ou se a zona atual permite objetos que não são seguros para scripts.

```
virtual BOOL CanAccessExternal();
```

### <a name="return-value"></a>Valor Retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

## <a name="cdhtmldialogcdhtmldialog"></a><a name="cdhtmldialog"></a> CDHtmlDialog:: CDHtmlDialog

Constrói uma caixa de diálogo HTML dinâmica baseada em recursos.

```
CDHtmlDialog();

CDHtmlDialog(
    LPCTSTR lpszTemplateName,
    LPCTSTR szHtmlResID,
    CWnd *pParentWnd = NULL);

CDHtmlDialog(
    UINT nIDTemplate,
    UINT nHtmlResID = 0,
    CWnd *pParentWnd = NULL);
```

### <a name="parameters"></a>parâmetros

*lpszTemplateName*<br/>
A cadeia de caracteres terminada em nulo que é o nome de um recurso de modelo de caixa de diálogo.

*szHtmlResID*<br/>
A cadeia de caracteres terminada em nulo que é o nome de um recurso HTML.

*pParentWnd*<br/>
Um ponteiro para o objeto de janela pai ou proprietário (do tipo [CWnd](../../mfc/reference/cwnd-class.md)) ao qual o objeto de caixa de diálogo pertence. Se for NULL, a janela pai do objeto de caixa de diálogo será definida como a janela principal do aplicativo.

*nIDTemplate*<br/>
Contém o número de ID de um recurso de modelo de caixa de diálogo.

*nHtmlResID*<br/>
Contém o número de ID de um recurso HTML.

### <a name="remarks"></a>Comentários

A segunda forma do construtor fornece acesso ao recurso de caixa de diálogo por meio do nome do modelo. A terceira forma do construtor fornece acesso ao recurso de caixa de diálogo por meio da ID do modelo de recurso. Normalmente, a ID começa com o prefixo de **IDD_** .

## <a name="cdhtmldialogcdhtmldialog"></a><a name="_dtorcdhtmldialog"></a> CDHtmlDialog:: ~ CDHtmlDialog

Destrói um objeto CDHtmlDialog.

```
virtual ~CDHtmlDialog();
```

### <a name="remarks"></a>Comentários

A função de membro [CWnd::D estroywindow](../../mfc/reference/cwnd-class.md#destroywindow) deve ser usada para destruir caixas de diálogo sem janela restrita que são criadas por [CDialog:: Create](../../mfc/reference/cdialog-class.md#create).

## <a name="cdhtmldialogcreatecontrolsite"></a><a name="createcontrolsite"></a> CDHtmlDialog:: CreateControlSite

Substituível usado para criar uma instância de site de controle para hospedar o controle WebBrowser na caixa de diálogo.

```
virtual BOOL CreateControlSite(
    COleControlContainer* pContainer,
    COleControlSite** ppSite,
    UINT /* nID */,
    REFCLSID /* clsid */);
```

### <a name="parameters"></a>parâmetros

*pContainer*<br/>
Um ponteiro para o objeto [COleControlContainer](../../mfc/reference/colecontrolcontainer-class.md)

*ppSite*<br/>
Um ponteiro para um ponteiro para um [COleControlSite](../../mfc/reference/colecontrolsite-class.md).

### <a name="return-value"></a>Valor Retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você pode substituir essa função de membro para retornar uma instância de sua própria classe de site de controle.

## <a name="cdhtmldialogddx_dhtml_axcontrol"></a><a name="ddx_dhtml_axcontrol"></a> CDHtmlDialog::D DX_DHtml_AxControl

Troca dados entre uma variável de membro e o valor da propriedade de um controle ActiveX em uma página HTML.

```cpp
void DDX_DHtml_AxControl(
    CDataExchange* pDX,
    LPCTSTR szId,
    DISPID dispId,
    VARIANT& var);

void DDX_DHtml_AxControl(
    CDataExchange* pDX,
    LPCTSTR szId,
    LPCTSTR szPropName,
    VARIANT& var);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) .

*szId*<br/>
O valor do parâmetro de ID da marca do objeto no código-fonte HTML do controle ActiveX.

*dispId*<br/>
A ID de expedição da propriedade com a qual você deseja trocar dados.

*szPropName*<br/>
O nome da propriedade.

*var*<br/>
O membro de dados, do tipo VARIANT, [COleVariant](../../mfc/reference/colevariant-class.md)ou [CComVariant](../../atl/reference/ccomvariant-class.md), que contém o valor trocado com a propriedade de controle ActiveX.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCHtmlHttp#1](../../mfc/reference/codesnippet/cpp/cdhtmldialog-class_1.cpp)]

## <a name="cdhtmldialogddx_dhtml_checkbox"></a><a name="ddx_dhtml_checkbox"></a> CDHtmlDialog::D DX_DHtml_CheckBox

Troca dados entre uma variável de membro e uma caixa de seleção em uma página HTML.

```cpp
void DDX_DHtml_CheckBox(
    CDataExchange* pDX,
    LPCTSTR szId,
    int& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) .

*szId*<br/>
O valor que você especificou para o parâmetro ID do controle HTML.

*value*<br/>
O valor que está sendo trocado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCHtmlHttp#2](../../mfc/reference/codesnippet/cpp/cdhtmldialog-class_2.cpp)]

## <a name="cdhtmldialogddx_dhtml_elementtext"></a><a name="ddx_dhtml_elementtext"></a> CDHtmlDialog::D DX_DHtml_ElementText

Troca dados entre uma variável de membro e qualquer propriedade de elemento HTML em uma página HTML.

```cpp
void DDX_DHtml_ElementText(
    CDataExchange* pDX,
    LPCTSTR szId,
    DISPID dispId,
    CString& value);

void DDX_DHtml_ElementText(
    CDataExchange* pDX,
    LPCTSTR szId,
    DISPID dispId,
    short& value);

void DDX_DHtml_ElementText(
    CDataExchange* pDX,
    LPCTSTR szId,
    DISPID dispId,
    int& value);

void DDX_DHtml_ElementText(
    CDataExchange* pDX,
    LPCTSTR szId,
    DISPID dispId,
    long& value);

void DDX_DHtml_ElementText(
    CDataExchange* pDX,
    LPCTSTR szId,
    DISPID dispId,
    DWORD& value);

void DDX_DHtml_ElementText(
    CDataExchange* pDX,
    LPCTSTR szId,
    DISPID dispId,
    float& value);

void DDX_DHtml_ElementText(
    CDataExchange* pDX,
    LPCTSTR szId,
    DISPID dispId,
    double& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) .

*szId*<br/>
O valor que você especificou para o parâmetro ID do controle HTML.

*dispId*<br/>
A ID de expedição do elemento HTML com o qual você deseja trocar dados.

*value*<br/>
O valor que está sendo trocado.

## <a name="cdhtmldialogddx_dhtml_radio"></a><a name="ddx_dhtml_radio"></a> CDHtmlDialog::D DX_DHtml_Radio

Troca dados entre uma variável de membro e um botão de opção em uma página HTML.

```cpp
void DDX_DHtml_Radio(
    CDataExchange* pDX,
    LPCTSTR szId,
    long& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) .

*szId*<br/>
O valor que você especificou para o parâmetro ID do controle HTML.

*value*<br/>
O valor que está sendo trocado.

## <a name="cdhtmldialogddx_dhtml_selectindex"></a><a name="ddx_dhtml_selectindex"></a> CDHtmlDialog::D DX_DHtml_SelectIndex

Obtém ou define o índice de uma caixa de listagem em uma página HTML.

```cpp
void DDX_DHtml_SelectIndex(
    CDataExchange* pDX,
    LPCTSTR szId,
    long& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) .

*szId*<br/>
O valor que você especificou para o parâmetro do controle HTML `id` .

*value*<br/>
O valor que está sendo trocado.

## <a name="cdhtmldialogddx_dhtml_selectstring"></a><a name="ddx_dhtml_selectstring"></a> CDHtmlDialog::D DX_DHtml_SelectString

Obtém ou define o texto de exibição de uma entrada da caixa de listagem (com base no índice atual) em uma página HTML.

```cpp
void DDX_DHtml_SelectString(
    CDataExchange* pDX,
    LPCTSTR szId,
    CString& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) .

*szId*<br/>
O valor que você especificou para o parâmetro ID do controle HTML.

*value*<br/>
O valor que está sendo trocado.

## <a name="cdhtmldialogddx_dhtml_selectvalue"></a><a name="ddx_dhtml_selectvalue"></a> CDHtmlDialog::D DX_DHtml_SelectValue

Obtém ou define o valor de uma entrada da caixa de listagem (com base no índice atual) em uma página HTML.

```cpp
void DDX_DHtml_SelectValue(
    CDataExchange* pDX,
    LPCTSTR szId,
    CString& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) .

*szId*<br/>
O valor que você especificou para o parâmetro ID do controle HTML.

*value*<br/>
O valor que está sendo trocado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCHtmlHttp#3](../../mfc/reference/codesnippet/cpp/cdhtmldialog-class_3.cpp)]

## <a name="cdhtmldialogdestroymodeless"></a><a name="destroymodeless"></a> CDHtmlDialog::D estroyModeless

Desanexa uma caixa de diálogo sem janela restrita do `CDHtmlDialog` objeto e destrói o objeto.

```cpp
void DestroyModeless();
```

## <a name="cdhtmldialogenablemodeless"></a><a name="enablemodeless"></a> CDHtmlDialog:: EnableModeless

Habilita caixas de diálogo sem janela restrita.

```
STDMETHOD(EnableModeless)(BOOL fEnable);
```

### <a name="parameters"></a>parâmetros

*fEnable*<br/>
Consulte *fEnable* em [IDocHostUIHandler:: EnableModeless](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753253\(v=vs.85\)) no SDK do Windows.

### <a name="return-value"></a>Valor Retornado

Retorna E_NOTIMPL.

### <a name="remarks"></a>Comentários

Essa função de membro é a implementação de CDHtmlDialog de [IDocHostUIHandler:: EnableModeless](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753253\(v=vs.85\)), conforme descrito na SDK do Windows.

## <a name="cdhtmldialogfilterdataobject"></a><a name="filterdataobject"></a> CDHtmlDialog:: FilterDataObject

Permite que a caixa de diálogo filtre objetos de dados da área de transferência criados pelo navegador hospedado.

```
STDMETHOD(FilterDataObject)(
    IDataObject* pDO,
    IDataObject** ppDORet);
```

### <a name="parameters"></a>parâmetros

*pDO*<br/>
Consulte *pDO* em [IDocHostUIHandler:: FilterDataObject](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753254\(v=vs.85\)) na SDK do Windows.

*ppDORet*<br/>
Consulte *ppDORet* no `IDocHostUIHandler::FilterDataObject` SDK do Windows.

### <a name="return-value"></a>Valor Retornado

Retorna S_FALSE.

### <a name="remarks"></a>Comentários

Essa função de membro é a implementação de CDHtmlDialog de [IDocHostUIHandler:: FilterDataObject](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753254\(v=vs.85\)), conforme descrito na SDK do Windows.

## <a name="cdhtmldialoggetcontroldispatch"></a><a name="getcontroldispatch"></a> CDHtmlDialog:: GetControlDispatch

Recupera a `IDispatch` interface em um controle ActiveX inserido no documento HTML retornado por [GetDHtmlDocument](#getdhtmldocument).

```
HRESULT GetControlDispatch(
    LPCTSTR szId,
    IDispatch** ppdisp);
```

### <a name="parameters"></a>parâmetros

*szId*<br/>
A ID HTML de um controle ActiveX.

*ppdisp*<br/>
A `IDispatch` interface do controle, se encontrada na página da Web.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

## <a name="cdhtmldialoggetcontrolproperty"></a><a name="getcontrolproperty"></a> CDHtmlDialog:: getcontrolproperty

Recupera a propriedade solicitada do controle ActiveX especificado.

```
VARIANT GetControlProperty(
    LPCTSTR szId,
    LPCTSTR szPropName);

VARIANT GetControlProperty(
    LPCTSTR szId,
    DISPID dispId);

VARIANT GetControlProperty(
    IDispatch* pdispControl,
    DISPID dispId);
```

### <a name="parameters"></a>parâmetros

*szId*<br/>
A ID HTML de um controle ActiveX.

*szPropName*<br/>
O nome de uma propriedade na localidade padrão do usuário atual.

*pdispControl*<br/>
O `IDispatch` ponteiro de um controle ActiveX.

*dispId*<br/>
A ID de expedição de uma propriedade.

### <a name="return-value"></a>Valor Retornado

Uma variante que contém a propriedade solicitada ou uma variante vazia se o controle ou propriedade não foi encontrado.

### <a name="remarks"></a>Comentários

As sobrecargas são listadas do menos eficiente na parte superior para a mais eficiente na parte inferior.

## <a name="cdhtmldialoggetcurrenturl"></a><a name="getcurrenturl"></a> CDHtmlDialog:: GetCurrentUrl

Recupera o Uniform Resource Locator (URL) associado ao documento atual.

```cpp
void GetCurrentUrl(CString& szUrl);
```

### <a name="parameters"></a>parâmetros

*szUrl*<br/>
Um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) que contém a URL a ser recuperada.

## <a name="cdhtmldialoggetdhtmldocument"></a><a name="getdhtmldocument"></a> CDHtmlDialog:: GetDHtmlDocument

Recupera a interface [IHTMLDocument2](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa752574\(v=vs.85\)) no documento HTML carregado no momento.

```
HRESULT GetDHtmlDocument(IHTMLDocument2 **pphtmlDoc);
```

### <a name="parameters"></a>parâmetros

* \* \* pphtmlDoc* um ponteiro para um ponteiro para um documento HTML.

### <a name="return-value"></a>Valor Retornado

Um HRESULT padrão. Retorna S_OK se obtiver êxito.

## <a name="cdhtmldialoggetdroptarget"></a><a name="getdroptarget"></a> CDHtmlDialog:: GetDropTarget

Chamado pelo controle WebBrowser contido quando ele está sendo usado como um destino de soltar para permitir que a caixa de diálogo forneça um [IDropTarget](/windows/win32/api/oleidl/nn-oleidl-idroptarget)alternativo.

```
STDMETHOD(GetDropTarget)(
    IDropTarget* pDropTarget,
    IDropTarget** ppDropTarget);
```

### <a name="parameters"></a>parâmetros

*pDropTarget*<br/>
Consulte *pDropTarget* em [IDocHostUIHandler:: GetDropTarget](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753255\(v=vs.85\)) no SDK do Windows.

*ppDropTarget*<br/>
Consulte *ppDropTarget* no `IDocHostUIHandler::GetDropTarget` SDK do Windows.

### <a name="return-value"></a>Valor Retornado

Retorna E_NOTIMPL.

### <a name="remarks"></a>Comentários

Essa função de membro é a implementação de CDHtmlDialog de [IDocHostUIHandler:: GetDropTarget](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753255\(v=vs.85\)), conforme descrito na SDK do Windows.

## <a name="cdhtmldialoggetelement"></a><a name="getelement"></a> CDHtmlDialog:: GetElement

Retorna uma interface no elemento HTML especificado por *szElementId*.

```
HRESULT GetElement(
    LPCTSTR szElementId,
    IDispatch** ppdisp,
    BOOL* pbCollection = NULL);

HRESULT GetElement(
    LPCTSTR szElementId,
    IHTMLElement** pphtmlElement);
```

### <a name="parameters"></a>parâmetros

*szElementId*<br/>
A ID de um elemento HTML.

*ppdisp*<br/>
Um `IDispatch` ponteiro para o elemento solicitado ou a coleção de elementos.

*pbCollection*<br/>
Um BOOL que indica se o objeto representado por *ppDisp* é um único elemento ou uma coleção de elementos.

*pphtmlElement*<br/>
Um `IHTMLElement` ponteiro para o elemento solicitado.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Use a primeira sobrecarga se você precisar manipular condições em que pode haver mais de um elemento com a ID especificada. Você pode usar o último parâmetro para descobrir se o ponteiro de interface retornado é para uma coleção ou um único item. Se o ponteiro de interface estiver em uma coleção, você poderá consultar `IHTMLElementCollection` e usar sua `item` propriedade para se referir aos elementos por posição ordinal.

A segunda sobrecarga falhará se houver mais de um elemento com a mesma ID na página.

## <a name="cdhtmldialoggetelementhtml"></a><a name="getelementhtml"></a> CDHtmlDialog:: GetElementHtml

Recupera a `innerHTML` Propriedade do elemento HTML identificada por *szElementId*.

```
BSTR GetElementHtml(LPCTSTR szElementId);
```

### <a name="parameters"></a>parâmetros

*szElementId*<br/>
A ID de um elemento HTML.

### <a name="return-value"></a>Valor Retornado

A `innerHTML` Propriedade do elemento HTML identificado por *SZELEMENTID* ou NULL se o elemento não foi encontrado.

## <a name="cdhtmldialoggetelementinterface"></a><a name="getelementinterface"></a> CDHtmlDialog:: GetElementInterface

Recupera o ponteiro de interface solicitado do elemento HTML identificado por *szElementId*.

```
template <class Q> HRESULT GetElementInterface(
    LPCTSTR szElementId,
    Q** ppvObj);

HRESULT GetElementInterface(
    LPCTSTR szElementId,
    REFIID refiid,
    void** ppvObj);
```

### <a name="parameters"></a>parâmetros

*szElementId*<br/>
A ID de um elemento HTML.

*ppvObj*<br/>
Endereço de um ponteiro que será preenchido com o ponteiro de interface solicitado se o elemento for encontrado e a consulta for realizada com sucesso.

*refiid*<br/>
A ID da interface (IID) da interface solicitada.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCHtmlHttp#4](../../mfc/reference/codesnippet/cpp/cdhtmldialog-class_4.cpp)]

## <a name="cdhtmldialoggetelementproperty"></a><a name="getelementproperty"></a> CDHtmlDialog:: getelementproperty

Recupera o valor da propriedade identificada por *dispId* a partir do elemento HTML identificado por *szElementId*.

```
VARIANT GetElementProperty(
    LPCTSTR szElementId,
    DISPID dispId);
```

### <a name="parameters"></a>parâmetros

*szElementId*<br/>
A ID de um elemento HTML.

*dispId*<br/>
A ID de expedição de uma propriedade.

### <a name="return-value"></a>Valor Retornado

O valor da propriedade ou uma variante vazia se a propriedade ou o elemento não foi encontrado.

## <a name="cdhtmldialoggetelementtext"></a><a name="getelementtext"></a> CDHtmlDialog:: GetElementText

Recupera a `innerText` Propriedade do elemento HTML identificada por *szElementId*.

```
BSTR GetElementText(LPCTSTR szElementId);
```

### <a name="parameters"></a>parâmetros

*szElementId*<br/>
A ID de um elemento HTML.

### <a name="return-value"></a>Valor Retornado

A `innerText` Propriedade do elemento HTML identificado por *SZELEMENTID* ou NULL se a propriedade ou o elemento não foi encontrado.

## <a name="cdhtmldialoggetevent"></a><a name="getevent"></a> CDHtmlDialog:: GetEvent

Retorna o `IHTMLEventObj` ponteiro para o objeto de evento atual.

```
HRESULT GetEvent(IHTMLEventObj** ppEventObj);
```

### <a name="parameters"></a>parâmetros

*ppEventObj*<br/>
Endereço de um ponteiro que será preenchido com o `IHTMLEventObj` ponteiro de interface.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Essa função só deve ser chamada de dentro de um manipulador de eventos DHTML.

## <a name="cdhtmldialoggetexternal"></a><a name="getexternal"></a> CDHtmlDialog:: GetExternal

Obtém a interface do host `IDispatch` .

```
STDMETHOD(GetExternal)(IDispatch** ppDispatch);
```

### <a name="parameters"></a>parâmetros

*ppDispatch*<br/>
Consulte *ppDispatch* em [IDocHostUIHandler:: getexternal](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753256\(v=vs.85\)) no SDK do Windows.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou E_NOTIMPL em caso de falha.

### <a name="remarks"></a>Comentários

Essa função de membro é a implementação de CDHtmlDialog de [IDocHostUIHandler:: GetExternal](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753256\(v=vs.85\)), conforme descrito na SDK do Windows.

## <a name="cdhtmldialoggethostinfo"></a><a name="gethostinfo"></a> CDHtmlDialog:: GetHostInfo

Recupera os recursos da interface do usuário do host.

```
STDMETHOD(GetHostInfo)(DOCHOSTUIINFO* pInfo);
```

### <a name="parameters"></a>parâmetros

*pInfo*<br/>
Consulte *pInfo* em [IDocHostUIHandler:: GetHostInfo](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753257\(v=vs.85\)) no SDK do Windows.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Essa função de membro é a implementação de CDHtmlDialog de [IDocHostUIHandler:: GetHostInfo](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753257\(v=vs.85\)), conforme descrito na SDK do Windows.

## <a name="cdhtmldialoggetoptionkeypath"></a><a name="getoptionkeypath"></a> CDHtmlDialog:: GetOptionKeyPath

Recupera a chave do registro sob a qual as preferências do usuário são armazenadas.

```
STDMETHOD(GetOptionKeyPath)(
    LPOLESTR* pchKey,
    DWORD dw);
```

### <a name="parameters"></a>parâmetros

*pchKey*<br/>
Consulte *pchKey* em [IDocHostUIHandler:: GetOptionKeyPath](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753258\(v=vs.85\)) no SDK do Windows.

*dw*<br/>
Consulte *DW* in `IDocHostUIHandler::GetOptionKeyPath` na SDK do Windows.

### <a name="return-value"></a>Valor Retornado

Retorna E_NOTIMPL.

### <a name="remarks"></a>Comentários

Essa função de membro é a implementação de CDHtmlDialog de [IDocHostUIHandler:: GetOptionKeyPath](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753258\(v=vs.85\)), conforme descrito na SDK do Windows.

## <a name="cdhtmldialoghideui"></a><a name="hideui"></a> CDHtmlDialog:: HideUI

Oculta a interface do usuário do host.

```
STDMETHOD(HideUI)(void);
```

### <a name="return-value"></a>Valor Retornado

Retorna E_NOTIMPL.

### <a name="remarks"></a>Comentários

Essa função de membro é a implementação de CDHtmlDialog de [IDocHostUIHandler:: HideUI](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753259\(v=vs.85\)), conforme descrito na SDK do Windows.

## <a name="cdhtmldialogisexternaldispatchsafe"></a><a name="isexternaldispatchsafe"></a> CDHtmlDialog:: IsExternalDispatchSafe

Indica se a interface do host `IDispatch` é segura para scripts.

```
virtual BOOL IsExternalDispatchSafe();
```

### <a name="return-value"></a>Valor Retornado

Retorna FALSE.

## <a name="cdhtmldialogloadfromresource"></a><a name="loadfromresource"></a> CDHtmlDialog:: LoadFromResource

Carrega o recurso especificado no controle WebBrowser na caixa de diálogo DHTML.

```
BOOL LoadFromResource(LPCTSTR lpszResource);
BOOL LoadFromResource(UINT nRes);
```

### <a name="parameters"></a>parâmetros

*lpszResource*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do recurso a ser carregado.

*nRes*<br/>
ID do pool de recursos a carregar.

### <a name="return-value"></a>Valor Retornado

Verdadeiro se for bem-sucedido; caso contrário, FALSE.

## <a name="cdhtmldialogm_busehtmltitle"></a><a name="m_busehtmltitle"></a> CDHtmlDialog:: m_bUseHtmlTitle

Indica se o título do documento HTML deve ser usado como a legenda da caixa de diálogo.

```
BOOL m_bUseHtmlTitle;
```

### <a name="remarks"></a>Comentários

Se **m**_ **bUseHtmlTitle** for true, a legenda da caixa de diálogo será definida igual ao título do documento HTML; caso contrário, a legenda no recurso de caixa de diálogo será usada.

## <a name="cdhtmldialogm_nhtmlresid"></a><a name="m_nhtmlresid"></a> CDHtmlDialog:: m_nHtmlResID

ID de recurso do recurso HTML a ser exibido.

```
UINT m_nHtmlResID;
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCHtmlHttp#5](../../mfc/reference/codesnippet/cpp/cdhtmldialog-class_5.cpp)]

## <a name="cdhtmldialogm_pbrowserapp"></a><a name="m_pbrowserapp"></a> CDHtmlDialog:: m_pBrowserApp

Um ponteiro para um aplicativo de navegador da Web.

```
CComPtr <IWebBrowser2> m_pBrowserApp;
```

## <a name="cdhtmldialogm_sphtmldoc"></a><a name="m_sphtmldoc"></a> CDHtmlDialog:: m_spHtmlDoc

Um ponteiro para um documento HTML.

```
CComPtr<IHTMLDocument2> m_spHtmlDoc;
```

## <a name="cdhtmldialogm_strcurrenturl"></a><a name="m_strcurrenturl"></a> CDHtmlDialog:: m_strCurrentUrl

A URL atual.

```
CString m_strCurrentUrl;
```

## <a name="cdhtmldialogm_szhtmlresid"></a><a name="m_szhtmlresid"></a> CDHtmlDialog:: m_szHtmlResID

Versão da cadeia de caracteres da ID do recurso HTML.

```
LPTSTR m_szHtmlResID;
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCHtmlHttp#6](../../mfc/reference/codesnippet/cpp/cdhtmldialog-class_6.cpp)]

## <a name="cdhtmldialognavigate"></a><a name="navigate"></a> CDHtmlDialog:: navegar

Navega até o recurso identificado pela URL especificada por *lpszUrl*.

```cpp
void Navigate(
    LPCTSTR lpszURL,
    DWORD dwFlags = 0,
    LPCTSTR lpszTargetFrameName = NULL,
    LPCTSTR lpszHeaders = NULL,
    LPVOID lpvPostData = NULL,
    DWORD dwPostDataLen = 0);
```

### <a name="parameters"></a>parâmetros

*lpszURL*<br/>
Um ponteiro para uma cadeia de caracteres que contém a URL a ser direcionada.

*dwFlags*<br/>
Os sinalizadores de uma variável que especifica se o recurso deve ser adicionado à lista de histórico, se deve ser lido ou gravado no cache e se o recurso deve ser exibido em uma nova janela. A variável pode ser uma combinação dos valores definidos pela enumeração [BrowserNavConstants](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768360\(v=vs.85\)) .

*lpszTargetFrameName*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do quadro no qual exibir o recurso.

*lpszHeaders*<br/>
Um ponteiro para um valor que especifica os cabeçalhos HTTP a serem enviados ao servidor. Esses cabeçalhos são adicionados aos cabeçalhos padrão do Internet Explorer. Os cabeçalhos podem especificar informações como a ação necessária do servidor, o tipo de dados que está sendo passado para o servidor ou um código de status. Esse parâmetro será ignorado se a URL não for uma URL HTTP.

*lpvPostData*<br/>
Um ponteiro para os dados a serem enviados com a transação HTTP POST. Por exemplo, a transação POST é usada para enviar dados coletados por um formulário HTML. Se esse parâmetro não especificar nenhum dado post, o `Navigate` emitirá uma transação HTTP Get. Esse parâmetro será ignorado se a URL não for uma URL HTTP.

*dwPostDataLen*<br/>
Dados a serem enviados com a transação HTTP POST. Por exemplo, a transação POST é usada para enviar dados coletados por um formulário HTML. Se esse parâmetro não especificar nenhum dado post, o `Navigate` emitirá uma transação HTTP Get. Esse parâmetro será ignorado se a URL não for uma URL HTTP.

## <a name="cdhtmldialogonbeforenavigate"></a><a name="onbeforenavigate"></a> CDHtmlDialog:: OnBeforeNavigate

Chamado pelo Framework para fazer com que um evento seja acionado antes que ocorra uma navegação.

```
virtual void OnBeforeNavigate(
    LPDISPATCH pDisp,
    LPCTSTR szUrl);
```

### <a name="parameters"></a>parâmetros

*pDisp*<br/>
Um ponteiro para um objeto `IDispatch`.

*szUrl*<br/>
Um ponteiro para uma cadeia de caracteres que contém a URL para a qual navegar.

## <a name="cdhtmldialogondocumentcomplete"></a><a name="ondocumentcomplete"></a> CDHtmlDialog:: OnDocumentComplete

Chamado pelo Framework para notificar um aplicativo quando um documento atingir o estado de READYSTATE_COMPLETE.

```
virtual void OnDocumentComplete(
    LPDISPATCH pDisp,
    LPCTSTR szUrl);
```

### <a name="parameters"></a>parâmetros

*pDisp*<br/>
Um ponteiro para um objeto `IDispatch`.

*szUrl*<br/>
Um ponteiro para uma cadeia de caracteres que contém a URL à qual foi navegada.

## <a name="cdhtmldialogondocwindowactivate"></a><a name="ondocwindowactivate"></a> CDHtmlDialog:: OnDocWindowActivate

Chamado pelo Framework quando a janela do documento é ativada ou desativada.

```
STDMETHOD(OnDocWindowActivate)(BOOL fActivate);
```

### <a name="parameters"></a>parâmetros

*fActivate*<br/>
Consulte *fActivate* em [IDocHostUIHandler:: OnDocWindowActivate](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753261\(v=vs.85\)) no SDK do Windows.

### <a name="return-value"></a>Valor Retornado

Retorna E_NOTIMPL.

### <a name="remarks"></a>Comentários

Essa função de membro é a implementação de CDHtmlDialog de [IDocHostUIHandler:: OnDocWindowActivate](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753261\(v=vs.85\)), conforme descrito na SDK do Windows.

## <a name="cdhtmldialogonframewindowactivate"></a><a name="onframewindowactivate"></a> CDHtmlDialog:: OnFrameWindowActivate

Chamado pelo Framework quando a janela do quadro é ativada ou desativada.

```
STDMETHOD(OnFrameWindowActivate)(BOOL fActivate);
```

### <a name="parameters"></a>parâmetros

*fActivate*<br/>
Consulte *fActivate* em [IDocHostUIHandler:: OnFrameWindowActivate](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753262\(v=vs.85\)) no SDK do Windows.

### <a name="return-value"></a>Valor Retornado

Retorna E_NOTIMPL.

### <a name="remarks"></a>Comentários

Essa função de membro é a implementação de CDHtmlDialog de [IDocHostUIHandler:: OnFrameWindowActivate](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753262\(v=vs.85\)), conforme descrito na SDK do Windows.

## <a name="cdhtmldialogoninitdialog"></a><a name="oninitdialog"></a> CDHtmlDialog:: OnInitDialog

Chamado em resposta à mensagem de WM_INITDIALOG.

```
virtual BOOL OnInitDialog();
```

### <a name="return-value"></a>Valor Retornado

A implementação padrão retorna TRUE.

### <a name="remarks"></a>Comentários

Essa mensagem é enviada para a caixa de diálogo durante `Create` as `CreateIndirect` chamadas, ou `DoModal` , que ocorrem imediatamente antes que a caixa de diálogo seja exibida.

Substitua essa função de membro se você precisar executar processamento especial quando a caixa de diálogo for inicializada. Na versão substituída, primeiro chame a classe base, `OnInitDialog` mas desconsidere seu valor de retorno. Normalmente, você retornará TRUE da sua função de membro substituída.

O Windows chama a `OnInitDialog` função por meio do procedimento de caixa de diálogo global padrão comum a todas as caixas de diálogo de biblioteca MFC, em vez de por meio de seu mapa de mensagens, portanto, você não precisa de uma entrada de mapa de mensagem para essa função de membro.

## <a name="cdhtmldialogonnavigatecomplete"></a><a name="onnavigatecomplete"></a> CDHtmlDialog:: OnNavigateComplete

Chamado pelo Framework após a navegação até a URL especificada ser concluída.

```
virtual void OnNavigateComplete(
    LPDISPATCH pDisp,
    LPCTSTR szUrl);
```

### <a name="parameters"></a>parâmetros

*pDisp*<br/>
Um ponteiro para um objeto `IDispatch`.

*szUrl*<br/>
Um ponteiro para uma cadeia de caracteres que contém a URL à qual foi navegada.

## <a name="cdhtmldialogresizeborder"></a><a name="resizeborder"></a> CDHtmlDialog:: ResizeBorder

Alerta o objeto de que precisa para redimensionar seu espaço de borda.

```
STDMETHOD(ResizeBorder)(
    LPCRECT prcBorder,
    IOleInPlaceUIWindow* pUIWindow,
    BOOL fRameWindow);
```

### <a name="parameters"></a>parâmetros

*prcBorder*<br/>
Consulte *prcBorder* em [IDocHostUIHandler:: ResizeBorder](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753263\(v=vs.85\)) no SDK do Windows.

*pUIWindow*<br/>
Consulte *pUIWindow* no `IDocHostUIHandler::ResizeBorder` SDK do Windows.

*fFrameWindow*<br/>
Consulte *fFrameWindow* no `IDocHostUIHandler::ResizeBorder` SDK do Windows.

### <a name="return-value"></a>Valor Retornado

Retorna E_NOTIMPL.

## <a name="cdhtmldialogsetcontrolproperty"></a><a name="setcontrolproperty"></a> CDHtmlDialog:: setcontrolproperty

Define a propriedade de um controle ActiveX para um novo valor.

```cpp
void SetControlProperty(
    LPCTSTR szElementId,
    DISPID dispId,
    VARIANT* pVar);

void SetControlProperty(
    IDispatch* pdispControl,
    DISPID dispId,
    VARIANT* pVar);

void SetControlProperty(
    LPCTSTR szElementId,
    LPCTSTR szPropName,
    VARIANT* pVar);
```

### <a name="parameters"></a>parâmetros

*szElementId*<br/>
A ID HTML de um controle ActiveX.

*dispId*<br/>
A ID de expedição da propriedade a ser definida.

*pVar*<br/>
Ponteiro para uma variante que contém o novo valor da propriedade.

*pdispControl*<br/>
Ponteiro para uma interface de controle ActiveX `IDispatch` .

*szPropName*<br/>
Cadeia de caracteres que contém o nome da propriedade a ser definida.

## <a name="cdhtmldialogsetelementhtml"></a><a name="setelementhtml"></a> CDHtmlDialog:: SetElementHtml

Define a `innerHTML` propriedade de um elemento HTML.

```cpp
void SetElementHtml(
    LPCTSTR szElementId,
    BSTR bstrText);

void SetElementHtml(
    IUnknown* punkElem,
    BSTR bstrText);
```

### <a name="parameters"></a>parâmetros

*szElementId*<br/>
A ID de um elemento HTML.

*bstrText*<br/>
O novo valor da propriedade `innerHTML`.

*punkElem*<br/>
O `IUnknown` ponteiro de um elemento HTML.

## <a name="cdhtmldialogsetelementproperty"></a><a name="setelementproperty"></a> CDHtmlDialog:: setelementproperty

Define uma propriedade de um elemento HTML.

```cpp
void SetElementProperty(
    LPCTSTR szElementId,
    DISPID dispId,
    VARIANT* pVar);
```

### <a name="parameters"></a>parâmetros

*szElementId*<br/>
A ID de um elemento HTML.

*dispId*<br/>
A ID de expedição da propriedade a ser definida.

*pVar*<br/>
O novo valor da propriedade.

## <a name="cdhtmldialogsetelementtext"></a><a name="setelementtext"></a> CDHtmlDialog:: SetElementText

Define a `innerText` propriedade de um elemento HTML.

```cpp
void SetElementText(
    LPCTSTR szElementId,
    BSTR bstrText);

void SetElementText(
    IUnknown* punkElem,
    BSTR bstrText);
```

### <a name="parameters"></a>parâmetros

*szElementId*<br/>
A ID de um elemento HTML.

*bstrText*<br/>
O novo valor da propriedade `innerText`.

*punkElem*<br/>
O `IUnknown` ponteiro de um elemento HTML.

## <a name="cdhtmldialogsetexternaldispatch"></a><a name="setexternaldispatch"></a> CDHtmlDialog:: SetExternalDispatch

Define a interface do host `IDispatch` .

```cpp
void SetExternalDispatch(IDispatch* pdispExternal);
```

### <a name="parameters"></a>parâmetros

*pdispExternal*<br/>
A nova `IDispatch` interface.

## <a name="cdhtmldialogsethostflags"></a><a name="sethostflags"></a> CDHtmlDialog:: SetHostFlags

Define os sinalizadores de interface do usuário do host.

```cpp
void SetHostFlags(DWORD dwFlags);
```

### <a name="parameters"></a>parâmetros

*dwFlags*<br/>
Para obter os valores possíveis, consulte [DOCHOSTUIFLAG](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753277\(v=vs.85\)) no SDK do Windows.

## <a name="cdhtmldialogshowcontextmenu"></a><a name="showcontextmenu"></a> CDHtmlDialog:: addcontextmenu

Chamado quando um menu de contexto está prestes a ser exibido.

```
STDMETHOD(ShowContextMenu)(
    DWORD dwID,
    POINT* ppt,
    IUnknown* pcmdtReserved,
    IDispatch* pdispReserved);
```

### <a name="parameters"></a>parâmetros

*dwID*<br/>
Confira *dwID* em [IDocHostUIHandler:: createcontextmenu](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753264\(v=vs.85\)) no SDK do Windows.

*apresentação*<br/>
Consulte o *ppt* no `IDocHostUIHandler::ShowContextMenu` na SDK do Windows.

*pcmdtReserved*<br/>
Consulte *pcmdtReserved* no `IDocHostUIHandler::ShowContextMenu` SDK do Windows.

*pdispReserved*<br/>
Consulte *pdispReserved* no `IDocHostUIHandler::ShowContextMenu` SDK do Windows.

### <a name="return-value"></a>Valor Retornado

Retorna S_FALSE.

### <a name="remarks"></a>Comentários

Essa função de membro é a implementação de CDHtmlDialog de [IDocHostUIHandler:: addcontextmenu](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753264\(v=vs.85\)), conforme descrito na SDK do Windows.

## <a name="cdhtmldialogshowui"></a><a name="showui"></a> CDHtmlDialog:: ShowUI

Mostra a interface do usuário do host.

```
STDMETHOD(ShowUI)(
    DWORD dwID,
    IOleInPlaceActiveObject* pActiveObject,
    IOleCommandTarget* pCommandTarget,
    IOleInPlaceFrame* pFrame,
    IOleInPlaceUIWindow* pDoc);
```

### <a name="parameters"></a>parâmetros

*dwID*<br/>
Consulte *dwID* em [IDocHostUIHandler:: ShowUI](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753265\(v=vs.85\)) no SDK do Windows.

*pActiveObject*<br/>
Consulte *d pActiveObject* no `IDocHostUIHandler::ShowUI` SDK do Windows.

*pCommandTarget*<br/>
Consulte *pCommandTarget* no `IDocHostUIHandler::ShowUI` SDK do Windows.

*pFrame*<br/>
Consulte *pFrame* no `IDocHostUIHandler::ShowUI` SDK do Windows.

*pDoc*<br/>
Consulte *pDoc* no `IDocHostUIHandler::ShowUI` SDK do Windows.

### <a name="return-value"></a>Valor Retornado

Retorna S_FALSE.

### <a name="remarks"></a>Comentários

Essa função de membro é a implementação de CDHtmlDialog de [IDocHostUIHandler:: ShowUI](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753265\(v=vs.85\)), conforme descrito na SDK do Windows.

## <a name="cdhtmldialogtranslateaccelerator"></a><a name="translateaccelerator"></a> CDHtmlDialog:: TranslateAccelerator

Chamado para processar mensagens de chave do acelerador de menu.

```
STDMETHOD(TranslateAccelerator)(
    LPMSG lpMsg,
    const GUID* pguidCmdGroup,
    DWORD nCmdID);
```

### <a name="parameters"></a>parâmetros

*lpMsg*<br/>
Consulte *lpMsg* em [IDocHostUIHandler:: TranslateAccelerator](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753266\(v=vs.85\)) na SDK do Windows.

*pguidCmdGroup*<br/>
Consulte *pguidCmdGroup* no `IDocHostUIHandler::TranslateAccelerator` SDK do Windows.

*nCmdID*<br/>
Consulte *nCmdID* no `IDocHostUIHandler::TranslateAccelerator` SDK do Windows.

### <a name="return-value"></a>Valor Retornado

Retorna S_FALSE.

### <a name="remarks"></a>Comentários

Essa função de membro é a implementação de CDHtmlDialog de [IDocHostUIHandler:: TranslateAccelerator](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753266\(v=vs.85\)), conforme descrito na SDK do Windows.

## <a name="cdhtmldialogtranslateurl"></a><a name="translateurl"></a> CDHtmlDialog:: TranslateUrl

Chamado para modificar a URL a ser carregada.

```
STDMETHOD(TranslateUrl)(
    DWORD dwTranslate,
    OLECHAR* pchURLIn,
    OLECHAR** ppchURLOut);
```

### <a name="parameters"></a>parâmetros

*dwTranslate*<br/>
Consulte *dwTranslate* em [IDocHostUIHandler:: TranslateUrl](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753267\(v=vs.85\)) no SDK do Windows.

*pchURLIn*<br/>
Consulte *pchURLIn* no `IDocHostUIHandler::TranslateUrl` SDK do Windows.

*ppchURLOut*<br/>
Consulte *ppchURLOut* no `IDocHostUIHandler::TranslateUrl` SDK do Windows.

### <a name="return-value"></a>Valor Retornado

Retorna S_FALSE.

### <a name="remarks"></a>Comentários

Essa função de membro é a implementação de CDHtmlDialog de [IDocHostUIHandler:: TranslateUrl](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753267\(v=vs.85\)), conforme descrito na SDK do Windows.

## <a name="cdhtmldialogupdateui"></a><a name="updateui"></a> CDHtmlDialog:: UpdateUI

Chamado para notificar o host que o estado do comando foi alterado.

```
STDMETHOD(UpdateUI)(void);
```

### <a name="return-value"></a>Valor Retornado

Retorna E_NOTIMPL.

### <a name="remarks"></a>Comentários

Essa função de membro é a implementação de CDHtmlDialog de [IDocHostUIHandler:: UpdateUI](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753268\(v=vs.85\)), conforme descrito na SDK do Windows.

## <a name="see-also"></a>Confira também

[Exemplo de DHtmlExplore do MFC](../../overview/visual-cpp-samples.md)<br/>
[DDX_DHtml macros auxiliares](#ddx_dhtml_helper_macros)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)
