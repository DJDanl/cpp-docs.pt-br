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
ms.openlocfilehash: 57ea8f3a1dbbce4fcfa350bd99e4ee628e9675c8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375680"
---
# <a name="cdhtmldialog-class"></a>Classe CDHtmlDialog

É usado para criar caixas de diálogo que usam HTML em vez de recursos de diálogo para implementar sua interface de usuário.

## <a name="syntax"></a>Sintaxe

```
class CDHtmlDialog : public CDialog, public CDHtmlEventSink
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[cdhtmldialog::Cdhtmldialog](#cdhtmldialog)|Constrói um objeto CDHtmlDialog.|
|[cdhtmldialog::~cdhtmldialog](#_dtorcdhtmldialog)|Destrói um objeto CDHtmlDialog.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[cdhtmldialog::canaccessexternal](#canaccessexternal)|Superridable que é chamado como uma verificação de acesso para ver se objetos de script na página carregada podem acessar o despacho externo do site de controle. Verifica se o despacho é seguro para scripts ou a região atual permite objetos que não são seguros para scripts.|
|[cdhtmldialog::CreateControlSite](#createcontrolsite)|Superridable usado para criar uma instância de site de controle para hospedar o controle do WebBrowser na caixa de diálogo.|
|[cdhtmlDiálogo::DDx_Dhtml_AxControl](#ddx_dhtml_axcontrol)|Troca dados entre uma variável de membro e o valor de propriedade de um controle ActiveX em uma página HTML.|
|[cdhtmldiálogo::Ddx_dhtml_checkbox](#ddx_dhtml_checkbox)|Troca dados entre uma variável de membro e uma caixa de seleção em uma página HTML.|
|[cdhtmlDiálogo::Ddx_dhtml_elementText](#ddx_dhtml_elementtext)|Troca dados entre uma variável de membro e qualquer propriedade de elemento HTML em uma página HTML.|
|[cdhtmldiálogo::Ddx_dhtml_radio](#ddx_dhtml_radio)|Troca dados entre uma variável de membro e um botão de rádio em uma página HTML.|
|[cdhtmldiálogo::Ddx_dhtml_selectindex](#ddx_dhtml_selectindex)|Obtém ou define o índice de uma caixa de lista em uma página HTML.|
|[cdhtmlDiálogo::Ddx_dhtml_selectstring](#ddx_dhtml_selectstring)|Obtém ou define o texto de exibição de uma entrada de caixa de lista (com base no índice atual) em uma página HTML.|
|[cdhtmlDiálogo::Ddx_dhtml_selectValue](#ddx_dhtml_selectvalue)|Obtém ou define o valor de uma entrada de caixa de lista (com base no índice atual) em uma página HTML.|
|[CDHtmlDiálogo::DestroyModeless](#destroymodeless)|Destrói uma caixa de diálogo modeless.|
|[cdhtmlDiálogo::Habilitarmodeless](#enablemodeless)|Habilita caixas de diálogo modeless.|
|[cdhtmldiálogo::filterdataobject](#filterdataobject)|Permite que a caixa de diálogo filtre objetos de dados de área de transferência criados pelo navegador hospedado.|
|[cdhtmldialog::GetcontrolDispatch](#getcontroldispatch)|Recupera a `IDispatch` interface em um controle ActiveX incorporado no documento HTML.|
|[cdhtmldialog::getcontrolProperty](#getcontrolproperty)|Recupera a propriedade solicitada do controle ActiveX especificado.|
|[cdhtmldialog::getCurrenturl](#getcurrenturl)|Recupera o URL (Uniform Resource Locator, localizador de recursos uniforme) associado ao documento atual.|
|[cdhtmldialog::getdhtmldocument](#getdhtmldocument)|Recupera a interface IHTMLDocument2 no documento HTML carregado no momento.|
|[cdhtmldialog::getDroptarget](#getdroptarget)|Chamado pelo controle webbrowser contido quando ele está sendo usado como um alvo de queda para permitir que a caixa de diálogo forneça um [IDropTarget](/windows/win32/api/oleidl/nn-oleidl-idroptarget)alternativo .|
|[cdhtmldialog::getelement](#getelement)|Obtém uma interface em um elemento HTML.|
|[cdhtmldialog::getelementhtml](#getelementhtml)|Recupera a `innerHTML` propriedade de um elemento HTML.|
|[cdhtmldialog::getelementinterface](#getelementinterface)|Recupera o ponteiro de interface solicitado de um elemento HTML.|
|[cdhtmldialog::getelementproperty](#getelementproperty)|Recupera o valor da propriedade de um elemento HTML.|
|[cdhtmldialog::getelementtext](#getelementtext)|Recupera a `innerText` propriedade de um elemento HTML.|
|[cdhtmldialog::getevent](#getevent)|Obtém `IHTMLEventObj` o ponteiro para o objeto de evento atual.|
|[cdhtmldialog::getexternal](#getexternal)|Obtém a `IDispatch` interface do anfitrião.|
|[cdhtmldialog::gethostinfo](#gethostinfo)|Recupera os recursos de IA do host.|
|[cdhtmldialog::getoptionkeypath](#getoptionkeypath)|Recupera a chave de registro sob a qual as preferências do usuário são armazenadas.|
|[cdhtmldialog::hideui](#hideui)|Esconde a ui do anfitrião.|
|[cdhtmldialog::isexternalDispatchsafe](#isexternaldispatchsafe)|Indica se a `IDispatch` interface do host é segura para scripts.|
|[cdhtmldialog::loadFromresource](#loadfromresource)|Carrega o recurso especificado no controle do WebBrowser.|
|[cdhtmldialog::navegar](#navigate)|Navega para a URL especificada.|
|[cdhtmldialog::OnbeforeNavigate](#onbeforenavigate)|Chamado pela estrutura antes de um evento de navegação ser acionado.|
|[cdhtmldialog::OnDocumentComplete](#ondocumentcomplete)|Chamado pelo framework para notificar um aplicativo quando um documento chegou ao estado READYSTATE_COMPLETE.|
|[cdhtmlDiálogo::OnDocWindowActivate](#ondocwindowactivate)|Chamado pela estrutura quando a janela do documento é ativada ou desativada.|
|[cdhtmldialog::onFrameWindowactivate](#onframewindowactivate)|Chamado pela estrutura quando a janela do quadro é ativada ou desativada.|
|[cdhtmlDiálogo::OnInitDialog](#oninitdialog)|Chamado em resposta à mensagem WM_INITDIALOG.|
|[cdhtmldialog::OnNavigateComplete](#onnavigatecomplete)|Chamado pela estrutura após um evento de navegação ser concluído.|
|[cdhtmlDiálogo::RedimensionarBorder](#resizeborder)|Alerta o objeto de que ele precisa para redimensionar seu espaço de fronteira.|
|[cdhtmldialog::setcontrolProperty](#setcontrolproperty)|Define a propriedade de um controle ActiveX como um novo valor.|
|[cdhtmldialog::setelementhtml](#setelementhtml)|Define `innerHTML` a propriedade de um elemento HTML.|
|[cdhtmldialog::setelementproperty](#setelementproperty)|Define uma propriedade de um elemento HTML.|
|[cdhtmldialog::setelementtext](#setelementtext)|Define `innerText` a propriedade de um elemento HTML.|
|[cdhtmldialog::setexternalDispatch](#setexternaldispatch)|Define a interface `IDispatch` do host.|
|[cdhtmldialog::setHostflags](#sethostflags)|Define as bandeiras de ui do anfitrião.|
|[cdhtmldialog::showcontextmenu](#showcontextmenu)|Chamado quando um menu de contexto está prestes a ser exibido.|
|[cdhtmldialog::showui](#showui)|Mostra a ui do anfitrião.|
|[cdhtmlDialog::TranslateAccelerator](#translateaccelerator)|Chamado para processar mensagens de chave do acelerador do menu.|
|[cdhtmldialog::translateurl](#translateurl)|Chamado para modificar a URL a ser carregada.|
|[cdhtmldialog::updateui](#updateui)|Chamado para notificar o anfitrião que o estado de comando mudou.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[cdhtmlDiálogo::m_bUseHtmlTitle](#m_busehtmltitle)|Indica se deve usar o título do documento HTML como legenda de diálogo.|
|[cdhtmlDiálogo::m_nHtmlResID](#m_nhtmlresid)|ID de recurso de recurso HTML a ser exibido.|
|[cdhtmlDiálogo::m_pBrowserApp](#m_pbrowserapp)|Um ponteiro para um aplicativo do navegador da Web.|
|[cdhtmlDiálogo::m_spHtmlDoc](#m_sphtmldoc)|Um ponteiro para um documento HTML.|
|[cdhtmldiálogo::m_strCurrentUrl](#m_strcurrenturl)|A URL atual.|
|[cdhtmlDiálogo::m_szHtmlResID](#m_szhtmlresid)|Versão string do ID de recurso HTML.|

## <a name="remarks"></a>Comentários

`CDHtmlDialog`pode carregar o HTML para ser exibido a partir de um recurso HTML ou de uma URL.

`CDHtmlDialog`também pode fazer troca de dados com controles HTML e lidar com eventos de controles HTML, como cliques de botão.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CDHtmlSinkHandlerBase2`

`CDHtmlSinkHandlerBase1`

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

`CDHtmlSinkHandler`

[CWnd](../../mfc/reference/cwnd-class.md)

`CDHtmlEventSink`

[Cdialog](../../mfc/reference/cdialog-class.md)

`CDHtmlDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdhtml.h

## <a name="ddx_dhtml-helper-macros"></a><a name="ddx_dhtml_helper_macros"></a>DDX_DHtml Helper Macros

As macros auxiliares DDX_DHtml permitem acesso fácil às propriedades comumente usadas dos controles em uma página HTML.

### <a name="data-exchange-macros"></a>Macros de troca de dados

|||
|-|-|
|[DDX_DHtml_ElementValue](../../mfc/reference/ddx-dhtml-helper-macros.md#ddx_dhtml_elementvalue)|Define ou recupera a propriedade Valor do controle selecionado.|
|[DDX_DHtml_ElementInnerText](../../mfc/reference/ddx-dhtml-helper-macros.md#ddx_dhtml_elementinnertext)|Define ou recupera o texto entre as tags inicial e final do elemento atual.|
|[DDX_DHtml_ElementInnerHtml](../../mfc/reference/ddx-dhtml-helper-macros.md#ddx_dhtml_elementinnerhtml)|Define ou recupera o HTML entre as tags inicial e final do elemento atual.|
|[DDX_DHtml_Anchor_Href](../../mfc/reference/ddx-dhtml-helper-macros.md#ddx_dhtml_anchor_href)|Define ou recupera a URL de destino ou ponto de ancoragem.|
|[DDX_DHtml_Anchor_Target](../../mfc/reference/ddx-dhtml-helper-macros.md#ddx_dhtml_anchor_target)|Define ou recupera a janela de destino ou o quadro.|
|[DDX_DHtml_Img_Src](../../mfc/reference/ddx-dhtml-helper-macros.md#ddx_dhtml_img_src)|Define ou recupera o nome de uma imagem ou um clipe de vídeo no documento.|
|[DDX_DHtml_Frame_Src](../../mfc/reference/ddx-dhtml-helper-macros.md#ddx_dhtml_frame_src)|Define ou recupera a URL do quadro associado.|
|[DDX_DHtml_IFrame_Src](../../mfc/reference/ddx-dhtml-helper-macros.md#ddx_dhtml_iframe_src)|Define ou recupera a URL do quadro associado.|

## <a name="cdhtmldialogcanaccessexternal"></a><a name="canaccessexternal"></a>cdhtmldialog::canaccessexternal

Superridable que é chamado como uma verificação de acesso para ver se objetos de script na página carregada podem acessar o despacho externo do site de controle. Verifica se o despacho é seguro para scripts ou a região atual permite objetos que não são seguros para scripts.

```
virtual BOOL CanAccessExternal();
```

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

## <a name="cdhtmldialogcdhtmldialog"></a><a name="cdhtmldialog"></a>cdhtmldialog::Cdhtmldialog

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

### <a name="parameters"></a>Parâmetros

*lpszTemplateName*<br/>
A seqüência de seqüência de nulidade sumida é o nome de um recurso de modelo de caixa de diálogo.

*szHtmlResID*<br/>
A seqüência de terminadas nula que é o nome de um recurso HTML.

*Pparentwnd*<br/>
Um ponteiro para o objeto da janela pai ou proprietário (do tipo [CWnd)](../../mfc/reference/cwnd-class.md)ao qual o objeto de diálogo pertence. Se for NULL, a janela pai do objeto de diálogo será definida na janela principal do aplicativo.

*Nidtemplate*<br/>
Contém o número de ID de um recurso de modelo de caixa de diálogo.

*nHtmlResID*<br/>
Contém o número de ID de um recurso HTML.

### <a name="remarks"></a>Comentários

A segunda forma do construtor fornece acesso ao recurso de diálogo através do nome do modelo. A terceira forma do construtor fornece acesso ao recurso de diálogo através do ID do modelo de recurso. Normalmente, o ID começa com o prefixo **IDD_.**

## <a name="cdhtmldialogcdhtmldialog"></a><a name="_dtorcdhtmldialog"></a>cdhtmldialog::~cdhtmldialog

Destrói um objeto CDHtmlDialog.

```
virtual ~CDHtmlDialog();
```

### <a name="remarks"></a>Comentários

A função [cwnd::DestroyWindow](../../mfc/reference/cwnd-class.md#destroywindow) membro deve ser usada para destruir caixas de diálogo modeless que são criadas por [CDialog::Create](../../mfc/reference/cdialog-class.md#create).

## <a name="cdhtmldialogcreatecontrolsite"></a><a name="createcontrolsite"></a>cdhtmldialog::CreateControlSite

Superridable usado para criar uma instância de site de controle para hospedar o controle do WebBrowser na caixa de diálogo.

```
virtual BOOL CreateControlSite(
    COleControlContainer* pContainer,
    COleControlSite** ppSite,
    UINT /* nID */,
    REFCLSID /* clsid */);
```

### <a name="parameters"></a>Parâmetros

*pContainer*<br/>
Um ponteiro para o objeto [COleControlContainer](../../mfc/reference/colecontrolcontainer-class.md)

*ppSite*<br/>
Um ponteiro para um ponteiro para um [COleControlSite](../../mfc/reference/colecontrolsite-class.md).

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você pode substituir essa função de membro para retornar uma instância de sua própria classe de site de controle.

## <a name="cdhtmldialogddx_dhtml_axcontrol"></a><a name="ddx_dhtml_axcontrol"></a>cdhtmlDiálogo::DDx_Dhtml_AxControl

Troca dados entre uma variável de membro e o valor de propriedade de um controle ActiveX em uma página HTML.

```
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

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md)

*Szid*<br/>
O valor do parâmetro ID da tag objeto na fonte HTML para o controle ActiveX.

*Dispid*<br/>
O ID de despacho da propriedade com a qual você deseja trocar dados.

*szPropName*<br/>
O nome da propriedade.

*Var*<br/>
O membro de dados, do tipo VARIANT, [COleVariant](../../mfc/reference/colevariant-class.md), ou [CComVariant,](../../atl/reference/ccomvariant-class.md)que detém o valor trocado com a propriedade de controle ActiveX.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCHtmlHttp#1](../../mfc/reference/codesnippet/cpp/cdhtmldialog-class_1.cpp)]

## <a name="cdhtmldialogddx_dhtml_checkbox"></a><a name="ddx_dhtml_checkbox"></a>cdhtmldiálogo::Ddx_dhtml_checkbox

Troca dados entre uma variável de membro e uma caixa de seleção em uma página HTML.

```
void DDX_DHtml_CheckBox(
    CDataExchange* pDX,
    LPCTSTR szId,
    int& value);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md)

*Szid*<br/>
O valor especificado para o parâmetro ID do controle HTML.

*value*<br/>
O valor que está sendo trocado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCHtmlHttp#2](../../mfc/reference/codesnippet/cpp/cdhtmldialog-class_2.cpp)]

## <a name="cdhtmldialogddx_dhtml_elementtext"></a><a name="ddx_dhtml_elementtext"></a>cdhtmlDiálogo::Ddx_dhtml_elementText

Troca dados entre uma variável de membro e qualquer propriedade de elemento HTML em uma página HTML.

```
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

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md)

*Szid*<br/>
O valor especificado para o parâmetro ID do controle HTML.

*Dispid*<br/>
O ID de despacho do elemento HTML com o qual você deseja trocar dados.

*value*<br/>
O valor que está sendo trocado.

## <a name="cdhtmldialogddx_dhtml_radio"></a><a name="ddx_dhtml_radio"></a>cdhtmldiálogo::Ddx_dhtml_radio

Troca dados entre uma variável de membro e um botão de rádio em uma página HTML.

```
void DDX_DHtml_Radio(
    CDataExchange* pDX,
    LPCTSTR szId,
    long& value);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md)

*Szid*<br/>
O valor especificado para o parâmetro ID do controle HTML.

*value*<br/>
O valor que está sendo trocado.

## <a name="cdhtmldialogddx_dhtml_selectindex"></a><a name="ddx_dhtml_selectindex"></a>cdhtmldiálogo::Ddx_dhtml_selectindex

Obtém ou define o índice de uma caixa de lista em uma página HTML.

```
void DDX_DHtml_SelectIndex(
    CDataExchange* pDX,
    LPCTSTR szId,
    long& value);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md)

*Szid*<br/>
O valor especificado para o parâmetro `id` do controle HTML.

*value*<br/>
O valor que está sendo trocado.

## <a name="cdhtmldialogddx_dhtml_selectstring"></a><a name="ddx_dhtml_selectstring"></a>cdhtmlDiálogo::Ddx_dhtml_selectstring

Obtém ou define o texto de exibição de uma entrada de caixa de lista (com base no índice atual) em uma página HTML.

```
void DDX_DHtml_SelectString(
    CDataExchange* pDX,
    LPCTSTR szId,
    CString& value);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md)

*Szid*<br/>
O valor especificado para o parâmetro ID do controle HTML.

*value*<br/>
O valor que está sendo trocado.

## <a name="cdhtmldialogddx_dhtml_selectvalue"></a><a name="ddx_dhtml_selectvalue"></a>cdhtmlDiálogo::Ddx_dhtml_selectValue

Obtém ou define o valor de uma entrada de caixa de lista (com base no índice atual) em uma página HTML.

```
void DDX_DHtml_SelectValue(
    CDataExchange* pDX,
    LPCTSTR szId,
    CString& value);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md)

*Szid*<br/>
O valor especificado para o parâmetro ID do controle HTML.

*value*<br/>
O valor que está sendo trocado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCHtmlHttp#3](../../mfc/reference/codesnippet/cpp/cdhtmldialog-class_3.cpp)]

## <a name="cdhtmldialogdestroymodeless"></a><a name="destroymodeless"></a>CDHtmlDiálogo::DestroyModeless

Destaca uma caixa de diálogo modeless do `CDHtmlDialog` objeto e destrói o objeto.

```
void DestroyModeless();
```

## <a name="cdhtmldialogenablemodeless"></a><a name="enablemodeless"></a>cdhtmlDiálogo::Habilitarmodeless

Habilita caixas de diálogo modeless.

```
STDMETHOD(EnableModeless)(BOOL fEnable);
```

### <a name="parameters"></a>Parâmetros

*fEnable*<br/>
Consulte *fEnable* no [IDocHostUIHandler::EnableModeless](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753253\(v=vs.85\)) no Windows SDK.

### <a name="return-value"></a>Valor retornado

Volta E_NOTIMPL.

### <a name="remarks"></a>Comentários

Esta função de membro é a implementação do [IDocHostUIHandler do CDHtmlDialog::EnableModeless](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753253\(v=vs.85\)), conforme descrito no SDK do Windows.

## <a name="cdhtmldialogfilterdataobject"></a><a name="filterdataobject"></a>cdhtmldiálogo::filterdataobject

Permite que a caixa de diálogo filtre objetos de dados de área de transferência criados pelo navegador hospedado.

```
STDMETHOD(FilterDataObject)(
    IDataObject* pDO,
    IDataObject** ppDORet);
```

### <a name="parameters"></a>Parâmetros

*Dop*<br/>
Consulte *pDO* em [IDocHostUIHandler::FilterDataObject](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753254\(v=vs.85\)) no Windows SDK.

*ppDORet*<br/>
Consulte *ppDORet* `IDocHostUIHandler::FilterDataObject` no SDK do Windows.

### <a name="return-value"></a>Valor retornado

Retorna S_FALSE.

### <a name="remarks"></a>Comentários

Esta função de membro é a implementação do [IDocHostUIHandler do IDocHostUIHandler::FilterDataObject](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753254\(v=vs.85\)), conforme descrito no SDK do Windows.

## <a name="cdhtmldialoggetcontroldispatch"></a><a name="getcontroldispatch"></a>cdhtmldialog::GetcontrolDispatch

Recupera a `IDispatch` interface em um controle ActiveX incorporado no documento HTML retornado pelo [GetDHtmlDocument](#getdhtmldocument).

```
HRESULT GetControlDispatch(
    LPCTSTR szId,
    IDispatch** ppdisp);
```

### <a name="parameters"></a>Parâmetros

*Szid*<br/>
O ID HTML de um controle ActiveX.

*Ppdisp*<br/>
A `IDispatch` interface do controle se encontrado na página da Web.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="cdhtmldialoggetcontrolproperty"></a><a name="getcontrolproperty"></a>cdhtmldialog::getcontrolProperty

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

### <a name="parameters"></a>Parâmetros

*Szid*<br/>
O ID HTML de um controle ActiveX.

*szPropName*<br/>
O nome de uma propriedade na localização padrão do usuário atual.

*pdispControl*<br/>
O `IDispatch` ponteiro de um controle ActiveX.

*Dispid*<br/>
A impropriedade de uma propriedade.

### <a name="return-value"></a>Valor retornado

Uma variante contendo a propriedade solicitada ou uma variante vazia se o controle ou propriedade não puder ser encontrado.

### <a name="remarks"></a>Comentários

As sobrecargas são listadas de menos eficientes na parte superior para mais eficientes na parte inferior.

## <a name="cdhtmldialoggetcurrenturl"></a><a name="getcurrenturl"></a>cdhtmldialog::getCurrenturl

Recupera o URL (Uniform Resource Locator, localizador de recursos uniforme) associado ao documento atual.

```
void GetCurrentUrl(CString& szUrl);
```

### <a name="parameters"></a>Parâmetros

*Szurl*<br/>
Um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) contendo a URL para recuperar.

## <a name="cdhtmldialoggetdhtmldocument"></a><a name="getdhtmldocument"></a>cdhtmldialog::getdhtmldocument

Recupera a interface [IHTMLDocument2](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa752574\(v=vs.85\)) no documento HTML carregado no momento.

```
HRESULT GetDHtmlDocument(IHTMLDocument2 **pphtmlDoc);
```

### <a name="parameters"></a>Parâmetros

* \* \** Um ponteiro para um ponteiro para um documento HTML.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão. Retorna S_OK se for bem sucedido.

## <a name="cdhtmldialoggetdroptarget"></a><a name="getdroptarget"></a>cdhtmldialog::getDroptarget

Chamado pelo controle webbrowser contido quando ele está sendo usado como um alvo de queda para permitir que a caixa de diálogo forneça um [IDropTarget](/windows/win32/api/oleidl/nn-oleidl-idroptarget)alternativo .

```
STDMETHOD(GetDropTarget)(
    IDropTarget* pDropTarget,
    IDropTarget** ppDropTarget);
```

### <a name="parameters"></a>Parâmetros

*pDropTarget*<br/>
Consulte *pDropTarget* em [IDocHostUIHandler::GetDropTarget](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753255\(v=vs.85\)) no Windows SDK.

*ppDropTarget*<br/>
Consulte *ppDropTarget* `IDocHostUIHandler::GetDropTarget` no SDK do Windows.

### <a name="return-value"></a>Valor retornado

Volta E_NOTIMPL.

### <a name="remarks"></a>Comentários

Esta função de membro é a implementação do [IDocHostUIHandler do CDHtmlDialog::GetDropTarget](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753255\(v=vs.85\)), conforme descrito no SDK do Windows.

## <a name="cdhtmldialoggetelement"></a><a name="getelement"></a>cdhtmldialog::getelement

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

### <a name="parameters"></a>Parâmetros

*Szelementid*<br/>
O ID de um elemento HTML.

*Ppdisp*<br/>
Um `IDispatch` ponteiro para o elemento solicitado ou coleção de elementos.

*pbCollection*<br/>
Um BOOL indicando se o objeto representado pelo *ppdisp* é um único elemento ou uma coleção de elementos.

*pphtmlElement*<br/>
Um `IHTMLElement` ponteiro para o elemento solicitado.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Use a primeira sobrecarga se precisar lidar com condições nas quais possa haver mais de um elemento com o ID especificado. Você pode usar o último parâmetro para descobrir se o ponteiro de interface retornado é para uma coleção ou um único item. Se o ponteiro de interface estiver em uma `IHTMLElementCollection` coleção, `item` você pode consultar a propriedade e usar sua propriedade para se referir aos elementos por posição ordinal.

A segunda sobrecarga falhará se houver mais de um elemento com o mesmo ID na página.

## <a name="cdhtmldialoggetelementhtml"></a><a name="getelementhtml"></a>cdhtmldialog::getelementhtml

Recupera a `innerHTML` propriedade do elemento HTML identificado por *szElementId*.

```
BSTR GetElementHtml(LPCTSTR szElementId);
```

### <a name="parameters"></a>Parâmetros

*Szelementid*<br/>
O ID de um elemento HTML.

### <a name="return-value"></a>Valor retornado

A `innerHTML` propriedade do elemento HTML identificada por *szElementId* ou NULL se o elemento não pudesse ser encontrado.

## <a name="cdhtmldialoggetelementinterface"></a><a name="getelementinterface"></a>cdhtmldialog::getelementinterface

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

### <a name="parameters"></a>Parâmetros

*Szelementid*<br/>
O ID de um elemento HTML.

*Ppvobj*<br/>
Endereço de um ponteiro que será preenchido com o ponteiro de interface solicitado se o elemento for encontrado e a consulta for bem sucedida.

*Refiid*<br/>
O ID de interface (IID) da interface solicitada.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCHtmlHttp#4](../../mfc/reference/codesnippet/cpp/cdhtmldialog-class_4.cpp)]

## <a name="cdhtmldialoggetelementproperty"></a><a name="getelementproperty"></a>cdhtmldialog::getelementproperty

Recupera o valor da propriedade identificada por *dspId* a partir do elemento HTML identificado por *szElementId*.

```
VARIANT GetElementProperty(
    LPCTSTR szElementId,
    DISPID dispId);
```

### <a name="parameters"></a>Parâmetros

*Szelementid*<br/>
O ID de um elemento HTML.

*Dispid*<br/>
A impropriedade de uma propriedade.

### <a name="return-value"></a>Valor retornado

O valor da propriedade ou uma variante vazia se a propriedade ou elemento não pudesse ser encontrado.

## <a name="cdhtmldialoggetelementtext"></a><a name="getelementtext"></a>cdhtmldialog::getelementtext

Recupera a `innerText` propriedade do elemento HTML identificado por *szElementId*.

```
BSTR GetElementText(LPCTSTR szElementId);
```

### <a name="parameters"></a>Parâmetros

*Szelementid*<br/>
O ID de um elemento HTML.

### <a name="return-value"></a>Valor retornado

A `innerText` propriedade do elemento HTML identificada por *szElementId* ou NULL se a propriedade ou elemento não pudesse ser encontrado.

## <a name="cdhtmldialoggetevent"></a><a name="getevent"></a>cdhtmldialog::getevent

Retorna `IHTMLEventObj` o ponteiro para o objeto de evento atual.

```
HRESULT GetEvent(IHTMLEventObj** ppEventObj);
```

### <a name="parameters"></a>Parâmetros

*ppEventObj*<br/>
Endereço de um ponteiro que será `IHTMLEventObj` preenchido com o ponteiro de interface.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Esta função só deve ser chamada de dentro de um manipulador de eventos DHTML.

## <a name="cdhtmldialoggetexternal"></a><a name="getexternal"></a>cdhtmldialog::getexternal

Obtém a `IDispatch` interface do anfitrião.

```
STDMETHOD(GetExternal)(IDispatch** ppDispatch);
```

### <a name="parameters"></a>Parâmetros

*ppDispatch*<br/>
Consulte *ppDispatch* em [IDocHostUIHandler::GetExternal](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753256\(v=vs.85\)) no Windows SDK.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso ou E_NOTIMPL no fracasso.

### <a name="remarks"></a>Comentários

Esta função de membro é a implementação do [IDocHostUIHandler do CDHtmlDialog::GetExternal](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753256\(v=vs.85\)), conforme descrito no Windows SDK.

## <a name="cdhtmldialoggethostinfo"></a><a name="gethostinfo"></a>cdhtmldialog::gethostinfo

Recupera os recursos de IA do host.

```
STDMETHOD(GetHostInfo)(DOCHOSTUIINFO* pInfo);
```

### <a name="parameters"></a>Parâmetros

*Pinfo*<br/>
Consulte *pInfo* em [IDocHostUIHandler::GetHostInfo](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753257\(v=vs.85\)) no Windows SDK.

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Esta função de membro é a implementação do [IDocHostUIHandler do CDHtmlDialog::GetHostInfo](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753257\(v=vs.85\)), conforme descrito no SDK do Windows.

## <a name="cdhtmldialoggetoptionkeypath"></a><a name="getoptionkeypath"></a>cdhtmldialog::getoptionkeypath

Recupera a chave de registro sob a qual as preferências do usuário são armazenadas.

```
STDMETHOD(GetOptionKeyPath)(
    LPOLESTR* pchKey,
    DWORD dw);
```

### <a name="parameters"></a>Parâmetros

*pchkey*<br/>
Consulte *pchKey* em [IDocHostUIHandler::GetOptionKeyPath](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753258\(v=vs.85\)) no Windows SDK.

*dw*<br/>
Veja *dw* in `IDocHostUIHandler::GetOptionKeyPath` no Windows SDK.

### <a name="return-value"></a>Valor retornado

Volta E_NOTIMPL.

### <a name="remarks"></a>Comentários

Esta função de membro é a implementação do [IDocHostUIHandler do CDHtmlDialog::GetOptionKeyPath](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753258\(v=vs.85\)), conforme descrito no SDK do Windows.

## <a name="cdhtmldialoghideui"></a><a name="hideui"></a>cdhtmldialog::hideui

Esconde a ui do anfitrião.

```
STDMETHOD(HideUI)(void);
```

### <a name="return-value"></a>Valor retornado

Volta E_NOTIMPL.

### <a name="remarks"></a>Comentários

Esta função de membro é a implementação do [IDocHostUIHandler do IDocHostUIHandler:::HideUI](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753259\(v=vs.85\)), conforme descrito no SDK do Windows.

## <a name="cdhtmldialogisexternaldispatchsafe"></a><a name="isexternaldispatchsafe"></a>cdhtmldialog::isexternalDispatchsafe

Indica se a `IDispatch` interface do host é segura para scripts.

```
virtual BOOL IsExternalDispatchSafe();
```

### <a name="return-value"></a>Valor retornado

Retorna FALSO.

## <a name="cdhtmldialogloadfromresource"></a><a name="loadfromresource"></a>cdhtmldialog::loadFromresource

Carrega o recurso especificado no controle do WebBrowser na caixa de diálogo DHTML.

```
BOOL LoadFromResource(LPCTSTR lpszResource);
BOOL LoadFromResource(UINT nRes);
```

### <a name="parameters"></a>Parâmetros

*lpszResource*<br/>
Um ponteiro para uma seqüência contendo o nome do recurso a carregar.

*nRes*<br/>
ID do pool de recursos a carregar.

### <a name="return-value"></a>Valor retornado

VERDADE se bem sucedido; caso contrário, FALSO.

## <a name="cdhtmldialogm_busehtmltitle"></a><a name="m_busehtmltitle"></a>cdhtmlDiálogo::m_bUseHtmlTitle

Indica se deve usar o título do documento HTML como legenda de diálogo.

```
BOOL m_bUseHtmlTitle;
```

### <a name="remarks"></a>Comentários

Se **m**_ **bUseHtmlTitle** for TRUE, a legenda de diálogo será definida igual ao título do documento HTML; caso contrário, a legenda no recurso de diálogo é usada.

## <a name="cdhtmldialogm_nhtmlresid"></a><a name="m_nhtmlresid"></a>cdhtmlDiálogo::m_nHtmlResID

ID de recurso de recurso HTML a ser exibido.

```
UINT m_nHtmlResID;
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCHtmlHttp#5](../../mfc/reference/codesnippet/cpp/cdhtmldialog-class_5.cpp)]

## <a name="cdhtmldialogm_pbrowserapp"></a><a name="m_pbrowserapp"></a>cdhtmlDiálogo::m_pBrowserApp

Um ponteiro para um aplicativo do navegador da Web.

```
CComPtr <IWebBrowser2> m_pBrowserApp;
```

## <a name="cdhtmldialogm_sphtmldoc"></a><a name="m_sphtmldoc"></a>cdhtmlDiálogo::m_spHtmlDoc

Um ponteiro para um documento HTML.

```
CComPtr<IHTMLDocument2> m_spHtmlDoc;
```

## <a name="cdhtmldialogm_strcurrenturl"></a><a name="m_strcurrenturl"></a>cdhtmldiálogo::m_strCurrentUrl

A URL atual.

```
CString m_strCurrentUrl;
```

## <a name="cdhtmldialogm_szhtmlresid"></a><a name="m_szhtmlresid"></a>cdhtmlDiálogo::m_szHtmlResID

Versão string do ID de recurso HTML.

```
LPTSTR m_szHtmlResID;
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCHtmlHttp#6](../../mfc/reference/codesnippet/cpp/cdhtmldialog-class_6.cpp)]

## <a name="cdhtmldialognavigate"></a><a name="navigate"></a>cdhtmldialog::navegar

Navega até o recurso identificado pela URL especificada pelo *lpszURL*.

```
void Navigate(
    LPCTSTR lpszURL,
    DWORD dwFlags = 0,
    LPCTSTR lpszTargetFrameName = NULL,
    LPCTSTR lpszHeaders = NULL,
    LPVOID lpvPostData = NULL,
    DWORD dwPostDataLen = 0);
```

### <a name="parameters"></a>Parâmetros

*Lpszurl*<br/>
Um ponteiro para uma seqüência contendo a URL a ser direcionada.

*dwFlags*<br/>
Os sinalizadores de uma variável que especifica se deve adicionar o recurso à lista de históricos, se ler para o cache ou gravar no cache e se exibir o recurso em uma nova janela. A variável pode ser uma combinação dos valores definidos pela enumeração [BrowserNavConstants.](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768360\(v=vs.85\))

*lpszTargetFrameNome*<br/>
Um ponteiro para uma seqüência que contém o nome do quadro no qual exibir o recurso.

*lpszHeaders*<br/>
Um ponteiro para um valor que especifica os cabeçalhos HTTP para enviar ao servidor. Esses cabeçalhos são adicionados aos cabeçalhos padrão do Internet Explorer. Os cabeçalhos podem especificar informações como a ação necessária do servidor, o tipo de dados que estão sendo passados para o servidor ou um código de status. Esse parâmetro é ignorado se a URL não for uma URL HTTP.

*lpvPostData*<br/>
Um ponteiro para os dados a serem enviados com a transação HTTP POST. Por exemplo, a transação POST é usada para enviar dados coletados por um formulário HTML. Se este parâmetro não especificar `Navigate` nenhum dado de postagem, emita uma transação HTTP GET. Esse parâmetro é ignorado se a URL não for uma URL HTTP.

*dwPostDataLen*<br/>
Dados a serem enviados com a transação HTTP POST. Por exemplo, a transação POST é usada para enviar dados coletados por um formulário HTML. Se este parâmetro não especificar `Navigate` nenhum dado de postagem, emita uma transação HTTP GET. Esse parâmetro é ignorado se a URL não for uma URL HTTP.

## <a name="cdhtmldialogonbeforenavigate"></a><a name="onbeforenavigate"></a>cdhtmldialog::OnbeforeNavigate

Chamado pela estrutura para causar um incêndio antes que uma navegação ocorra.

```
virtual void OnBeforeNavigate(
    LPDISPATCH pDisp,
    LPCTSTR szUrl);
```

### <a name="parameters"></a>Parâmetros

*pDisp*<br/>
Um ponteiro para um objeto `IDispatch`.

*Szurl*<br/>
Um ponteiro para uma seqüência contendo a URL para navegar.

## <a name="cdhtmldialogondocumentcomplete"></a><a name="ondocumentcomplete"></a>cdhtmldialog::OnDocumentComplete

Chamado pelo quadro para notificar um aplicativo quando um documento tiver alcançado o estado READYSTATE_COMPLETE.

```
virtual void OnDocumentComplete(
    LPDISPATCH pDisp,
    LPCTSTR szUrl);
```

### <a name="parameters"></a>Parâmetros

*pDisp*<br/>
Um ponteiro para um objeto `IDispatch`.

*Szurl*<br/>
Um ponteiro para uma seqüência contendo a URL que foi navegada.

## <a name="cdhtmldialogondocwindowactivate"></a><a name="ondocwindowactivate"></a>cdhtmlDiálogo::OnDocWindowActivate

Chamado pela estrutura quando a janela do documento é ativada ou desativada.

```
STDMETHOD(OnDocWindowActivate)(BOOL fActivate);
```

### <a name="parameters"></a>Parâmetros

*fActivate*<br/>
Consulte *fActivate* no [IDocHostUIHandler::OnDocWindowActivate](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753261\(v=vs.85\)) no Windows SDK.

### <a name="return-value"></a>Valor retornado

Volta E_NOTIMPL.

### <a name="remarks"></a>Comentários

Esta função de membro é a implementação do [IDocHostUIHandler do IDocHostUIHandler::OnDocWindowActivate](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753261\(v=vs.85\)), conforme descrito no Windows SDK.

## <a name="cdhtmldialogonframewindowactivate"></a><a name="onframewindowactivate"></a>cdhtmldialog::onFrameWindowactivate

Chamado pela estrutura quando a janela do quadro é ativada ou desativada.

```
STDMETHOD(OnFrameWindowActivate)(BOOL fActivate);
```

### <a name="parameters"></a>Parâmetros

*fActivate*<br/>
Consulte *fActivate* no [IDocHostUIHandler::OnFrameWindowActivate](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753262\(v=vs.85\)) in the Windows SDK.

### <a name="return-value"></a>Valor retornado

Volta E_NOTIMPL.

### <a name="remarks"></a>Comentários

Esta função de membro é a implementação do [IDocHostUIHandler do IDocHostUIHandler::OnFrameWindowActivate](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753262\(v=vs.85\)), conforme descrito no SDK do Windows.

## <a name="cdhtmldialogoninitdialog"></a><a name="oninitdialog"></a>cdhtmlDiálogo::OnInitDialog

Chamado em resposta à mensagem WM_INITDIALOG.

```
virtual BOOL OnInitDialog();
```

### <a name="return-value"></a>Valor retornado

A implementação padrão retorna TRUE.

### <a name="remarks"></a>Comentários

Esta mensagem é enviada para `Create` `CreateIndirect`a `DoModal` caixa de diálogo durante as chamadas, que ocorrem imediatamente antes da caixa de diálogo ser exibida.

Anular essa função de membro se você precisar executar um processamento especial quando a caixa de diálogo for inicializada. Na versão substituída, primeiro chame a `OnInitDialog` classe base, mas desconsidere seu valor de retorno. Você normalmente retornará TRUE de sua função de membro substituído.

O Windows `OnInitDialog` chama a função através do procedimento padrão de caixa de diálogo global comum a todas as caixas de diálogo da Microsoft Foundation Class Library, em vez de através do mapa de mensagens, para que você não precise de uma entrada de mapa de mensagem para esta função de membro.

## <a name="cdhtmldialogonnavigatecomplete"></a><a name="onnavigatecomplete"></a>cdhtmldialog::OnNavigateComplete

Chamado pela estrutura após a navegação para a URL especificada é concluído.

```
virtual void OnNavigateComplete(
    LPDISPATCH pDisp,
    LPCTSTR szUrl);
```

### <a name="parameters"></a>Parâmetros

*pDisp*<br/>
Um ponteiro para um objeto `IDispatch`.

*Szurl*<br/>
Um ponteiro para uma seqüência contendo a URL que foi navegada.

## <a name="cdhtmldialogresizeborder"></a><a name="resizeborder"></a>cdhtmlDiálogo::RedimensionarBorder

Alerta o objeto de que ele precisa para redimensionar seu espaço de fronteira.

```
STDMETHOD(ResizeBorder)(
    LPCRECT prcBorder,
    IOleInPlaceUIWindow* pUIWindow,
    BOOL fRameWindow);
```

### <a name="parameters"></a>Parâmetros

*prcBorder*<br/>
Consulte *prcBorder* em [IDocHostUIHandler::Redimensionborder](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753263\(v=vs.85\)) no Windows SDK.

*pUIWindow*<br/>
Consulte *pUIWindow* no `IDocHostUIHandler::ResizeBorder` Windows SDK.

*fFrameWindow*<br/>
Consulte *fFrameWindow* no `IDocHostUIHandler::ResizeBorder` SDK do Windows.

### <a name="return-value"></a>Valor retornado

Volta E_NOTIMPL.

## <a name="cdhtmldialogsetcontrolproperty"></a><a name="setcontrolproperty"></a>cdhtmldialog::setcontrolProperty

Define a propriedade de um controle ActiveX como um novo valor.

```
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

### <a name="parameters"></a>Parâmetros

*Szelementid*<br/>
O ID HTML de um controle ActiveX.

*Dispid*<br/>
A impropriedade de despacho da propriedade para definir.

*Pvar*<br/>
Ponteiro para uma VARIANT contendo o novo valor de propriedade.

*pdispControl*<br/>
Ponteiro para a interface `IDispatch` de um controle ActiveX.

*szPropName*<br/>
String contendo o nome da propriedade a definir.

## <a name="cdhtmldialogsetelementhtml"></a><a name="setelementhtml"></a>cdhtmldialog::setelementhtml

Define `innerHTML` a propriedade de um elemento HTML.

```
void SetElementHtml(
    LPCTSTR szElementId,
    BSTR bstrText);

void SetElementHtml(
    IUnknown* punkElem,
    BSTR bstrText);
```

### <a name="parameters"></a>Parâmetros

*Szelementid*<br/>
O ID de um elemento HTML.

*bstrText*<br/>
O novo valor da propriedade `innerHTML`.

*punkElem*<br/>
O `IUnknown` ponteiro de um elemento HTML.

## <a name="cdhtmldialogsetelementproperty"></a><a name="setelementproperty"></a>cdhtmldialog::setelementproperty

Define uma propriedade de um elemento HTML.

```
void SetElementProperty(
    LPCTSTR szElementId,
    DISPID dispId,
    VARIANT* pVar);
```

### <a name="parameters"></a>Parâmetros

*Szelementid*<br/>
O ID de um elemento HTML.

*Dispid*<br/>
A impropriedade de despacho da propriedade para definir.

*Pvar*<br/>
O novo valor da propriedade.

## <a name="cdhtmldialogsetelementtext"></a><a name="setelementtext"></a>cdhtmldialog::setelementtext

Define `innerText` a propriedade de um elemento HTML.

```
void SetElementText(
    LPCTSTR szElementId,
    BSTR bstrText);

void SetElementText(
    IUnknown* punkElem,
    BSTR bstrText);
```

### <a name="parameters"></a>Parâmetros

*Szelementid*<br/>
O ID de um elemento HTML.

*bstrText*<br/>
O novo valor da propriedade `innerText`.

*punkElem*<br/>
O `IUnknown` ponteiro de um elemento HTML.

## <a name="cdhtmldialogsetexternaldispatch"></a><a name="setexternaldispatch"></a>cdhtmldialog::setexternalDispatch

Define a interface `IDispatch` do host.

```
void SetExternalDispatch(IDispatch* pdispExternal);
```

### <a name="parameters"></a>Parâmetros

*pdispExterno*<br/>
A `IDispatch` nova interface.

## <a name="cdhtmldialogsethostflags"></a><a name="sethostflags"></a>cdhtmldialog::setHostflags

Define as bandeiras de ida e qualquer outra.

```
void SetHostFlags(DWORD dwFlags);
```

### <a name="parameters"></a>Parâmetros

*dwFlags*<br/>
Para obter valores possíveis, consulte [DOCHOSTUIFLAG](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753277\(v=vs.85\)) no Windows SDK.

## <a name="cdhtmldialogshowcontextmenu"></a><a name="showcontextmenu"></a>cdhtmldialog::showcontextmenu

Chamado quando um menu de contexto está prestes a ser exibido.

```
STDMETHOD(ShowContextMenu)(
    DWORD dwID,
    POINT* ppt,
    IUnknown* pcmdtReserved,
    IDispatch* pdispReserved);
```

### <a name="parameters"></a>Parâmetros

*Dwid*<br/>
Consulte *dwID* em [IDocHostUIHandler::ShowContextMenu](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753264\(v=vs.85\)) no Windows SDK.

*Ppt*<br/>
Veja *ppt* no `IDocHostUIHandler::ShowContextMenu` Windows SDK.

*pcmdtReservado*<br/>
Consulte *pcmdtReservado* `IDocHostUIHandler::ShowContextMenu` no SDK do Windows.

*pdispReservado*<br/>
Consulte *pdispReservado* `IDocHostUIHandler::ShowContextMenu` no Windows SDK.

### <a name="return-value"></a>Valor retornado

Retorna S_FALSE.

### <a name="remarks"></a>Comentários

Esta função de membro é a implementação do [IDocHostUIHandler do IDocHostUIHandler::ShowContextMenu](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753264\(v=vs.85\)), conforme descrito no Windows SDK.

## <a name="cdhtmldialogshowui"></a><a name="showui"></a>cdhtmldialog::showui

Mostra a ui do anfitrião.

```
STDMETHOD(ShowUI)(
    DWORD dwID,
    IOleInPlaceActiveObject* pActiveObject,
    IOleCommandTarget* pCommandTarget,
    IOleInPlaceFrame* pFrame,
    IOleInPlaceUIWindow* pDoc);
```

### <a name="parameters"></a>Parâmetros

*Dwid*<br/>
Consulte *dwID* em [IDocHostUIHandler::ShowUI](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753265\(v=vs.85\)) no Windows SDK.

*pActiveObject*<br/>
Consulte *d pActiveObject* no `IDocHostUIHandler::ShowUI` SDK do Windows.

*pCommandTarget*<br/>
Consulte *pCommandTarget* no `IDocHostUIHandler::ShowUI` SDK do Windows.

*pFrame*<br/>
Consulte *pFrame* in `IDocHostUIHandler::ShowUI` no Windows SDK.

*pDoc*<br/>
Consulte *o pDoc* `IDocHostUIHandler::ShowUI` no Windows SDK.

### <a name="return-value"></a>Valor retornado

Retorna S_FALSE.

### <a name="remarks"></a>Comentários

Esta função de membro é a implementação do [IDocHostUIHandler do IDocHostUIHandler::ShowUI](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753265\(v=vs.85\)), conforme descrito no Windows SDK.

## <a name="cdhtmldialogtranslateaccelerator"></a><a name="translateaccelerator"></a>cdhtmlDialog::TranslateAccelerator

Chamado para processar mensagens de chave do acelerador do menu.

```
STDMETHOD(TranslateAccelerator)(
    LPMSG lpMsg,
    const GUID* pguidCmdGroup,
    DWORD nCmdID);
```

### <a name="parameters"></a>Parâmetros

*Lpmsg*<br/>
Consulte *lpMsg* em [IDocHostUIHandler::TranslateAccelerator](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753266\(v=vs.85\)) no Windows SDK.

*Pguidcmdgroup*<br/>
Consulte *pguidCmdGroup* no `IDocHostUIHandler::TranslateAccelerator` Windows SDK.

*Ncmdid*<br/>
Consulte *nCmdID* `IDocHostUIHandler::TranslateAccelerator` no SDK do Windows.

### <a name="return-value"></a>Valor retornado

Retorna S_FALSE.

### <a name="remarks"></a>Comentários

Esta função de membro é a implementação do [IDocHostUIHandler do IDocHostUIHandler::TranslateAccelerator](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753266\(v=vs.85\)), conforme descrito no Windows SDK.

## <a name="cdhtmldialogtranslateurl"></a><a name="translateurl"></a>cdhtmldialog::translateurl

Chamado para modificar a URL a ser carregada.

```
STDMETHOD(TranslateUrl)(
    DWORD dwTranslate,
    OLECHAR* pchURLIn,
    OLECHAR** ppchURLOut);
```

### <a name="parameters"></a>Parâmetros

*dwTranslate*<br/>
Consulte *dwTranslate* em [IDocHostUIHandler::TranslateUrl](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753267\(v=vs.85\)) no Windows SDK.

*pchURLIn*<br/>
Consulte *pchURLIn* no `IDocHostUIHandler::TranslateUrl` Windows SDK.

*ppchURLOut*<br/>
Consulte *ppchURLOut* `IDocHostUIHandler::TranslateUrl` no SDK do Windows.

### <a name="return-value"></a>Valor retornado

Retorna S_FALSE.

### <a name="remarks"></a>Comentários

Esta função de membro é a implementação do [IDocHostUIHandler do IDocHostUIHandler::TranslateUrl](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753267\(v=vs.85\)), conforme descrito no SDK do Windows.

## <a name="cdhtmldialogupdateui"></a><a name="updateui"></a>cdhtmldialog::updateui

Chamado para notificar o anfitrião que o estado de comando mudou.

```
STDMETHOD(UpdateUI)(void);
```

### <a name="return-value"></a>Valor retornado

Volta E_NOTIMPL.

### <a name="remarks"></a>Comentários

Esta função de membro é a implementação do [IDocHostUIHandler do IDocHostUIHandler::UpdateUI](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753268\(v=vs.85\)), conforme descrito no Windows SDK.

## <a name="see-also"></a>Confira também

[Amostra de MFC Dhtmlexplore](../../overview/visual-cpp-samples.md)<br/>
[Macros auxiliares DDX_DHtml](#ddx_dhtml_helper_macros)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
