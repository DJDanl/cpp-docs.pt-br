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
ms.openlocfilehash: d53d3afb464b9dcfa32ab3cf4ee51446f8313a92
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58771819"
---
# <a name="cdhtmldialog-class"></a>Classe CDHtmlDialog

É usado para criar caixas de diálogo que usam HTML em vez de recursos de caixa de diálogo para implementar sua interface do usuário.

## <a name="syntax"></a>Sintaxe

```
class CDHtmlDialog : public CDialog, public CDHtmlEventSink
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDHtmlDialog::CDHtmlDialog](#cdhtmldialog)|Constrói um objeto CDHtmlDialog.|
|[CDHtmlDialog::~CDHtmlDialog](#_dtorcdhtmldialog)|Destrói um objeto CDHtmlDialog.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDHtmlDialog::CanAccessExternal](#canaccessexternal)|Substituível que é chamado como uma verificação para ver se os objetos de script na página carregada podem acessar o envio externo do site de controle de acesso. Verifica se que o envio for permite que o seguros para scripts ou zona atual para objetos que não são seguros para script.|
|[CDHtmlDialog::CreateControlSite](#createcontrolsite)|Overridable usado para criar uma instância de controle de site para hospedar o controle WebBrowser na caixa de diálogo.|
|[CDHtmlDialog::DDX_DHtml_AxControl](#ddx_dhtml_axcontrol)|Troca dados entre uma variável de membro e o valor da propriedade de um controle ActiveX em uma página HTML.|
|[CDHtmlDialog::DDX_DHtml_CheckBox](#ddx_dhtml_checkbox)|Troca dados entre uma variável de membro e uma caixa de seleção em uma página HTML.|
|[CDHtmlDialog::DDX_DHtml_ElementText](#ddx_dhtml_elementtext)|Troca dados entre uma variável de membro e qualquer propriedade do elemento HTML em uma página HTML.|
|[CDHtmlDialog::DDX_DHtml_Radio](#ddx_dhtml_radio)|Troca dados entre uma variável de membro e um botão de opção em uma página HTML.|
|[CDHtmlDialog::DDX_DHtml_SelectIndex](#ddx_dhtml_selectindex)|Obtém ou define o índice de uma caixa de listagem em uma página HTML.|
|[CDHtmlDialog::DDX_DHtml_SelectString](#ddx_dhtml_selectstring)|Obtém ou define o texto de exibição de uma entrada de caixa de lista (com base no índice atual) em uma página HTML.|
|[CDHtmlDialog::DDX_DHtml_SelectValue](#ddx_dhtml_selectvalue)|Obtém ou define o valor de uma entrada de caixa de lista (com base no índice atual) em uma página HTML.|
|[CDHtmlDialog::DestroyModeless](#destroymodeless)|Destrói uma caixa de diálogo sem janela restrita.|
|[CDHtmlDialog::EnableModeless](#enablemodeless)|Habilita as caixas de diálogo sem janela restrita.|
|[CDHtmlDialog::FilterDataObject](#filterdataobject)|Permite que a caixa de diálogo Filtrar os objetos de dados de área de transferência criados pelo navegador hospedado.|
|[CDHtmlDialog::GetControlDispatch](#getcontroldispatch)|Recupera o `IDispatch` interface em um controle ActiveX é inserida no documento HTML.|
|[CDHtmlDialog::GetControlProperty](#getcontrolproperty)|Recupera a propriedade solicitada do controle ActiveX especificado.|
|[CDHtmlDialog::GetCurrentUrl](#getcurrenturl)|Recupera o localizador de URL (Uniform Resource) associada ao documento atual.|
|[CDHtmlDialog::GetDHtmlDocument](#getdhtmldocument)|Recupera a interface IHTMLDocument2 no documento HTML carregado atualmente.|
|[CDHtmlDialog::GetDropTarget](#getdroptarget)|Chamado pelo controle WebBrowser independente quando ele está sendo usado como um destino de soltar para permitir que a caixa de diálogo fornecer uma alternativa [IDropTarget](/windows/desktop/api/oleidl/nn-oleidl-idroptarget).|
|[CDHtmlDialog::GetElement](#getelement)|Obtém uma interface em um elemento HTML.|
|[CDHtmlDialog::GetElementHtml](#getelementhtml)|Recupera o `innerHTML` propriedade de um elemento HTML.|
|[CDHtmlDialog::GetElementInterface](#getelementinterface)|Recupera o ponteiro de interface solicitado de um elemento HTML.|
|[CDHtmlDialog::GetElementProperty](#getelementproperty)|Recupera o valor da propriedade do elemento HTML.|
|[CDHtmlDialog::GetElementText](#getelementtext)|Recupera o `innerText` propriedade de um elemento HTML.|
|[CDHtmlDialog::GetEvent](#getevent)|Obtém o `IHTMLEventObj` ponteiro para o objeto de evento atual.|
|[CDHtmlDialog::GetExternal](#getexternal)|Obtém o host `IDispatch` interface.|
|[CDHtmlDialog::GetHostInfo](#gethostinfo)|Recupera os recursos de interface do usuário do host.|
|[CDHtmlDialog::GetOptionKeyPath](#getoptionkeypath)|Recupera a chave do registro sob a qual as preferências do usuário são armazenadas.|
|[CDHtmlDialog::HideUI](#hideui)|Oculta a interface de usuário do host.|
|[CDHtmlDialog::IsExternalDispatchSafe](#isexternaldispatchsafe)|Indica se o host `IDispatch` interface é seguro para script.|
|[CDHtmlDialog::LoadFromResource](#loadfromresource)|Carrega o recurso especificado no controle WebBrowser.|
|[CDHtmlDialog::Navigate](#navigate)|Navega para a URL especificada.|
|[CDHtmlDialog::OnBeforeNavigate](#onbeforenavigate)|Chamado pelo framework antes que um evento de navegação seja acionado.|
|[CDHtmlDialog::OnDocumentComplete](#ondocumentcomplete)|Chamado pelo framework para notificar um aplicativo quando um documento tiver atingido o estado READYSTATE_COMPLETE.|
|[CDHtmlDialog::OnDocWindowActivate](#ondocwindowactivate)|Chamado pelo framework quando a janela do documento é ativada ou desativada.|
|[CDHtmlDialog::OnFrameWindowActivate](#onframewindowactivate)|Chamado pelo framework quando a janela do quadro é ativada ou desativada.|
|[CDHtmlDialog::OnInitDialog](#oninitdialog)|Chamado em resposta à mensagem WM_INITDIALOG.|
|[CDHtmlDialog::OnNavigateComplete](#onnavigatecomplete)|Chamado pelo framework depois que um evento de navegação for concluído.|
|[CDHtmlDialog::ResizeBorder](#resizeborder)|O objeto que ele precisa para redimensionar o seu espaço de borda de alertas.|
|[CDHtmlDialog::SetControlProperty](#setcontrolproperty)|Define a propriedade de um controle ActiveX para um novo valor.|
|[CDHtmlDialog::SetElementHtml](#setelementhtml)|Conjuntos de `innerHTML` propriedade de um elemento HTML.|
|[CDHtmlDialog::SetElementProperty](#setelementproperty)|Define uma propriedade de um elemento HTML.|
|[CDHtmlDialog::SetElementText](#setelementtext)|Conjuntos de `innerText` propriedade de um elemento HTML.|
|[CDHtmlDialog::SetExternalDispatch](#setexternaldispatch)|Define o host `IDispatch` interface.|
|[CDHtmlDialog::SetHostFlags](#sethostflags)|Define os sinalizadores de interface do usuário do host.|
|[CDHtmlDialog::ShowContextMenu](#showcontextmenu)|Chamado quando um menu de contexto está prestes a ser exibido.|
|[CDHtmlDialog::ShowUI](#showui)|Mostra da interface do usuário o nome do host.|
|[CDHtmlDialog::TranslateAccelerator](#translateaccelerator)|Chamado para processar as mensagens de tecla de atalho do menu.|
|[CDHtmlDialog::TranslateUrl](#translateurl)|Chamado para modificar a URL a ser carregado.|
|[CDHtmlDialog::UpdateUI](#updateui)|Chamado para notificar o host que o estado do comando foi alterado.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDHtmlDialog::m_bUseHtmlTitle](#m_busehtmltitle)|Indica se deve usar o título do documento HTML como a legenda da caixa de diálogo.|
|[CDHtmlDialog::m_nHtmlResID](#m_nhtmlresid)|Recurso de ID de HTML do recurso a ser exibido.|
|[CDHtmlDialog::m_pBrowserApp](#m_pbrowserapp)|Um ponteiro para um aplicativo de navegador da Web.|
|[CDHtmlDialog::m_spHtmlDoc](#m_sphtmldoc)|Um ponteiro para um documento HTML.|
|[CDHtmlDialog::m_strCurrentUrl](#m_strcurrenturl)|A URL atual.|
|[CDHtmlDialog::m_szHtmlResID](#m_szhtmlresid)|Versão de cadeia de caracteres da ID de recurso do HTML.|

## <a name="remarks"></a>Comentários

`CDHtmlDialog` pode carregar o HTML a ser exibida de um recurso HTML ou uma URL.

`CDHtmlDialog` podem também dados do exchange com controles HTML e manipular eventos de controles HTML, como cliques de botão.

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

**Cabeçalho:** afxdhtml.h

##  <a name="ddx_dhtml_helper_macros"></a>  Macros auxiliares DDX_DHtml

As macros auxiliares DDX_DHtml permitem o fácil acesso às propriedades de controles em uma página HTML comumente usadas.

### <a name="data-exchange-macros"></a>Macros de troca de dados

|||
|-|-|
|[DDX_DHtml_ElementValue](../../mfc/reference/ddx-dhtml-helper-macros.md#ddx_dhtml_elementvalue)|Define ou recupera a propriedade Value do controle selecionado.|
|[DDX_DHtml_ElementInnerText](../../mfc/reference/ddx-dhtml-helper-macros.md#ddx_dhtml_elementinnertext)|Define ou recupera o texto entre as marcas de início e término do elemento atual.|
|[DDX_DHtml_ElementInnerHtml](../../mfc/reference/ddx-dhtml-helper-macros.md#ddx_dhtml_elementinnerhtml)|Define ou recupera o HTML entre as marcas de início e término do elemento atual.|
|[DDX_DHtml_Anchor_Href](../../mfc/reference/ddx-dhtml-helper-macros.md#ddx_dhtml_anchor_href)|Define ou recupera o destino URL ou ponto de ancoragem.|
|[DDX_DHtml_Anchor_Target](../../mfc/reference/ddx-dhtml-helper-macros.md#ddx_dhtml_anchor_target)|Define ou recupera a janela de destino ou quadro.|
|[DDX_DHtml_Img_Src](../../mfc/reference/ddx-dhtml-helper-macros.md#ddx_dhtml_img_src)|Define ou recupera o nome de uma imagem ou um clipe de vídeo no documento.|
|[DDX_DHtml_Frame_Src](../../mfc/reference/ddx-dhtml-helper-macros.md#ddx_dhtml_frame_src)|Define ou recupera a URL do quadro associado.|
|[DDX_DHtml_IFrame_Src](../../mfc/reference/ddx-dhtml-helper-macros.md#ddx_dhtml_iframe_src)|Define ou recupera a URL do quadro associado.|

##  <a name="canaccessexternal"></a>  CDHtmlDialog::CanAccessExternal

Substituível que é chamado como uma verificação para ver se os objetos de script na página carregada podem acessar o envio externo do site de controle de acesso. Verifica se que o envio for permite que o seguros para scripts ou zona atual para objetos que não são seguros para script.

```
virtual BOOL CanAccessExternal();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

##  <a name="cdhtmldialog"></a>  CDHtmlDialog::CDHtmlDialog

Constrói uma caixa de diálogo baseada em recursos dinâmica HTML.

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
A cadeia terminada em nulo que é o nome de um recurso de modelo de caixa de diálogo.

*szHtmlResID*<br/>
A cadeia terminada em nulo que é o nome de um recurso HTML.

*pParentWnd*<br/>
Um ponteiro para o objeto de janela pai ou o proprietário (do tipo [CWnd](../../mfc/reference/cwnd-class.md)) ao qual pertence o objeto de caixa de diálogo. Se for NULL, a janela do pai do objeto de caixa de diálogo é definida como a janela principal do aplicativo.

*nIDTemplate*<br/>
Contém o número de identificação de um recurso de modelo de caixa de diálogo.

*nHtmlResID*<br/>
Contém o número de identificação de um recurso HTML.

### <a name="remarks"></a>Comentários

O segundo formulário do construtor fornece acesso ao recurso de caixa de diálogo por meio do nome do modelo. O terceiro formulário do construtor fornece acesso ao recurso de caixa de diálogo por meio da ID do modelo de recurso. Geralmente, a ID começa com o **IDD _** prefixo.

##  <a name="_dtorcdhtmldialog"></a>  CDHtmlDialog:: ~ CDHtmlDialog

Destrói um objeto CDHtmlDialog.

```
virtual ~CDHtmlDialog();
```

### <a name="remarks"></a>Comentários

O [CWnd::DestroyWindow](../../mfc/reference/cwnd-class.md#destroywindow) função de membro deve ser usada para destruir as caixas de diálogo sem janela restrita que são criadas por [CDialog::Create](../../mfc/reference/cdialog-class.md#create).

##  <a name="createcontrolsite"></a>  CDHtmlDialog::CreateControlSite

Overridable usado para criar uma instância de controle de site para hospedar o controle WebBrowser na caixa de diálogo.

```
virtual BOOL CreateControlSite(
    COleControlContainer* pContainer,
    COleControlSite** ppSite,
    UINT /* nID */,
    REFCLSID /* clsid */);
```

### <a name="parameters"></a>Parâmetros

*pContainer*<br/>
Um ponteiro para o [COleControlContainer](../../mfc/reference/colecontrolcontainer-class.md) objeto

*ppSite*<br/>
Um ponteiro para um ponteiro para um [COleControlSite](../../mfc/reference/colecontrolsite-class.md).

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Você pode substituir essa função de membro para retornar uma instância de sua própria classe de site do controle.

##  <a name="ddx_dhtml_axcontrol"></a>  CDHtmlDialog::DDX_DHtml_AxControl

Troca dados entre uma variável de membro e o valor da propriedade de um controle ActiveX em uma página HTML.

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
Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto.

*szId*<br/>
O valor do parâmetro de ID da marca de objeto na fonte de HTML para o controle ActiveX.

*dispId*<br/>
A ID de expedição da propriedade com o qual você deseja a troca de dados.

*szPropName*<br/>
O nome da propriedade.

*var*<br/>
O membro de dados, do tipo VARIANT, [COleVariant](../../mfc/reference/colevariant-class.md), ou [CComVariant](../../atl/reference/ccomvariant-class.md), que contém o valor trocado com a propriedade do controle ActiveX.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCHtmlHttp#1](../../mfc/reference/codesnippet/cpp/cdhtmldialog-class_1.cpp)]

##  <a name="ddx_dhtml_checkbox"></a>  CDHtmlDialog::DDX_DHtml_CheckBox

Troca dados entre uma variável de membro e uma caixa de seleção em uma página HTML.

```
void DDX_DHtml_CheckBox(
    CDataExchange* pDX,
    LPCTSTR szId,
    int& value);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto.

*szId*<br/>
O valor especificado para o parâmetro de ID do controle HTML.

*value*<br/>
O valor sendo trocado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCHtmlHttp#2](../../mfc/reference/codesnippet/cpp/cdhtmldialog-class_2.cpp)]

##  <a name="ddx_dhtml_elementtext"></a>  CDHtmlDialog::DDX_DHtml_ElementText

Troca dados entre uma variável de membro e qualquer propriedade do elemento HTML em uma página HTML.

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
Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto.

*szId*<br/>
O valor especificado para o parâmetro de ID do controle HTML.

*dispId*<br/>
A ID de expedição do elemento HTML com o qual você deseja a troca de dados.

*value*<br/>
O valor sendo trocado.

##  <a name="ddx_dhtml_radio"></a>  CDHtmlDialog::DDX_DHtml_Radio

Troca dados entre uma variável de membro e um botão de opção em uma página HTML.

```
void DDX_DHtml_Radio(
    CDataExchange* pDX,
    LPCTSTR szId,
    long& value);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto.

*szId*<br/>
O valor especificado para o parâmetro de ID do controle HTML.

*value*<br/>
O valor sendo trocado.

##  <a name="ddx_dhtml_selectindex"></a>  CDHtmlDialog::DDX_DHtml_SelectIndex

Obtém ou define o índice de uma caixa de listagem em uma página HTML.

```
void DDX_DHtml_SelectIndex(
    CDataExchange* pDX,
    LPCTSTR szId,
    long& value);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto.

*szId*<br/>
O valor especificado para o controle HTML `id` parâmetro.

*value*<br/>
O valor sendo trocado.

##  <a name="ddx_dhtml_selectstring"></a>  CDHtmlDialog::DDX_DHtml_SelectString

Obtém ou define o texto de exibição de uma entrada de caixa de lista (com base no índice atual) em uma página HTML.

```
void DDX_DHtml_SelectString(
    CDataExchange* pDX,
    LPCTSTR szId,
    CString& value);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto.

*szId*<br/>
O valor especificado para o parâmetro de ID do controle HTML.

*value*<br/>
O valor sendo trocado.

##  <a name="ddx_dhtml_selectvalue"></a>  CDHtmlDialog::DDX_DHtml_SelectValue

Obtém ou define o valor de uma entrada de caixa de lista (com base no índice atual) em uma página HTML.

```
void DDX_DHtml_SelectValue(
    CDataExchange* pDX,
    LPCTSTR szId,
    CString& value);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto.

*szId*<br/>
O valor especificado para o parâmetro de ID do controle HTML.

*value*<br/>
O valor sendo trocado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCHtmlHttp#3](../../mfc/reference/codesnippet/cpp/cdhtmldialog-class_3.cpp)]

##  <a name="destroymodeless"></a>  CDHtmlDialog::DestroyModeless

Desanexa a uma caixa de diálogo sem janela restrita a `CDHtmlDialog` do objeto e destrói o objeto.

```
void DestroyModeless();
```

##  <a name="enablemodeless"></a>  CDHtmlDialog::EnableModeless

Habilita as caixas de diálogo sem janela restrita.

```
STDMETHOD(EnableModeless)(BOOL fEnable);
```

### <a name="parameters"></a>Parâmetros

*fEnable*<br/>
Ver *fEnable* na [IDocHostUIHandler::EnableModeless](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753253\(v=vs.85\)) no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Returns E_NOTIMPL.

### <a name="remarks"></a>Comentários

Essa função membro é a implementação do CDHtmlDialog da [IDocHostUIHandler::EnableModeless](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753253\(v=vs.85\)), conforme descrito no SDK do Windows.

##  <a name="filterdataobject"></a>  CDHtmlDialog::FilterDataObject

Permite que a caixa de diálogo Filtrar os objetos de dados de área de transferência criados pelo navegador hospedado.

```
STDMETHOD(FilterDataObject)(
    IDataObject* pDO,
    IDataObject** ppDORet);
```

### <a name="parameters"></a>Parâmetros

*pDO*<br/>
Ver *pDO* na [IDocHostUIHandler::FilterDataObject](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753254\(v=vs.85\)) no SDK do Windows.

*ppDORet*<br/>
Ver *ppDORet* em `IDocHostUIHandler::FilterDataObject` no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Retorna S_FALSE.

### <a name="remarks"></a>Comentários

Essa função membro é a implementação do CDHtmlDialog da [IDocHostUIHandler::FilterDataObject](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753254\(v=vs.85\)), conforme descrito no SDK do Windows.

##  <a name="getcontroldispatch"></a>  CDHtmlDialog::GetControlDispatch

Recupera o `IDispatch` interface em um controle ActiveX é inserida no documento HTML retornado por [GetDHtmlDocument](#getdhtmldocument).

```
HRESULT GetControlDispatch(
    LPCTSTR szId,
    IDispatch** ppdisp);
```

### <a name="parameters"></a>Parâmetros

*szId*<br/>
A ID de HTML de um controle ActiveX.

*ppdisp*<br/>
O `IDispatch` interface do controle se encontrado na página da Web.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

##  <a name="getcontrolproperty"></a>  CDHtmlDialog::GetControlProperty

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

*szId*<br/>
A ID de HTML de um controle ActiveX.

*szPropName*<br/>
O nome de uma propriedade em que a localidade padrão do usuário atual.

*pdispControl*<br/>
O `IDispatch` ponteiro de um controle ActiveX.

*dispId*<br/>
A ID de expedição de uma propriedade.

### <a name="return-value"></a>Valor de retorno

Uma variante que contém a propriedade solicitada ou uma variante vazia se a propriedade ou não pôde ser encontrada.

### <a name="remarks"></a>Comentários

As sobrecargas são listadas de menos eficientes na parte superior para o mais eficiente na parte inferior.

##  <a name="getcurrenturl"></a>  CDHtmlDialog::GetCurrentUrl

Recupera o localizador de URL (Uniform Resource) associada ao documento atual.

```
void GetCurrentUrl(CString& szUrl);
```

### <a name="parameters"></a>Parâmetros

*szUrl*<br/>
Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que contém a URL para recuperar.

##  <a name="getdhtmldocument"></a>  CDHtmlDialog::GetDHtmlDocument

Recupera o [IHTMLDocument2](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa752574\(v=vs.85\)) interface no documento HTML carregado atualmente.

```
HRESULT GetDHtmlDocument(IHTMLDocument2 **pphtmlDoc);
```

### <a name="parameters"></a>Parâmetros

*\*\*pphtmlDoc* um ponteiro para um ponteiro para um documento HTML.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão. Se for bem-sucedido, retornará S_OK.

##  <a name="getdroptarget"></a>  CDHtmlDialog::GetDropTarget

Chamado pelo controle WebBrowser independente quando ele está sendo usado como um destino de soltar para permitir que a caixa de diálogo fornecer uma alternativa [IDropTarget](/windows/desktop/api/oleidl/nn-oleidl-idroptarget).

```
STDMETHOD(GetDropTarget)(
    IDropTarget* pDropTarget,
    IDropTarget** ppDropTarget);
```

### <a name="parameters"></a>Parâmetros

*pDropTarget*<br/>
Ver *pDropTarget* na [IDocHostUIHandler::GetDropTarget](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753255\(v=vs.85\)) no SDK do Windows.

*ppDropTarget*<br/>
Ver *ppDropTarget* em `IDocHostUIHandler::GetDropTarget` no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Returns E_NOTIMPL.

### <a name="remarks"></a>Comentários

Essa função membro é a implementação do CDHtmlDialog da [IDocHostUIHandler::GetDropTarget](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753255\(v=vs.85\)), conforme descrito no SDK do Windows.

##  <a name="getelement"></a>  CDHtmlDialog::GetElement

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

*szElementId*<br/>
A ID de um elemento HTML.

*ppdisp*<br/>
Um `IDispatch` ponteiro para o elemento solicitado ou uma coleção de elementos.

*pbCollection*<br/>
Um BOOLIANO que indica se o objeto representado pelo *ppdisp* é um único elemento ou uma coleção de elementos.

*pphtmlElement*<br/>
Um `IHTMLElement` ponteiro para o elemento solicitado.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Use a primeira sobrecarga se você precisar lidar com condições em que pode haver mais de um elemento com a ID especificada. Você pode usar o último parâmetro para descobrir se o ponteiro de interface retornada é uma coleção ou um único item. Se o ponteiro de interface está em uma coleção, você pode consultar a `IHTMLElementCollection` e use seu `item` propriedade para se referir a elementos pela posição ordinal.

A segunda sobrecarga falhará se não houver mais de um elemento com a mesma ID na página.

##  <a name="getelementhtml"></a>  CDHtmlDialog::GetElementHtml

Recupera o `innerHTML` propriedade do elemento HTML identificado por *szElementId*.

```
BSTR GetElementHtml(LPCTSTR szElementId);
```

### <a name="parameters"></a>Parâmetros

*szElementId*<br/>
A ID de um elemento HTML.

### <a name="return-value"></a>Valor de retorno

O `innerHTML` propriedade do elemento HTML identificado por *szElementId* ou nulo se o elemento não pôde ser encontrado.

##  <a name="getelementinterface"></a>  CDHtmlDialog::GetElementInterface

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

*szElementId*<br/>
A ID de um elemento HTML.

*ppvObj*<br/>
Endereço de um ponteiro que será preenchido com o ponteiro de interface solicitado se o elemento for encontrado e a consulta for bem-sucedida.

*refiid*<br/>
A interface IID (ID) da interface solicitada.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCHtmlHttp#4](../../mfc/reference/codesnippet/cpp/cdhtmldialog-class_4.cpp)]

##  <a name="getelementproperty"></a>  CDHtmlDialog::GetElementProperty

Recupera o valor da propriedade identificado pelo *dispId* do elemento HTML identificado por *szElementId*.

```
VARIANT GetElementProperty(
    LPCTSTR szElementId,
    DISPID dispId);
```

### <a name="parameters"></a>Parâmetros

*szElementId*<br/>
A ID de um elemento HTML.

*dispId*<br/>
A ID de expedição de uma propriedade.

### <a name="return-value"></a>Valor de retorno

O valor da propriedade ou uma variante vazia se a propriedade ou o elemento não pôde ser encontrado.

##  <a name="getelementtext"></a>  CDHtmlDialog::GetElementText

Recupera o `innerText` propriedade do elemento HTML identificado por *szElementId*.

```
BSTR GetElementText(LPCTSTR szElementId);
```

### <a name="parameters"></a>Parâmetros

*szElementId*<br/>
A ID de um elemento HTML.

### <a name="return-value"></a>Valor de retorno

O `innerText` propriedade do elemento HTML identificado por *szElementId* ou nulo se a propriedade ou o elemento não pôde ser encontrado.

##  <a name="getevent"></a>  CDHtmlDialog::GetEvent

Retorna o `IHTMLEventObj` ponteiro para o objeto de evento atual.

```
HRESULT GetEvent(IHTMLEventObj** ppEventObj);
```

### <a name="parameters"></a>Parâmetros

*ppEventObj*<br/>
Endereço de um ponteiro que será preenchido com o `IHTMLEventObj` ponteiro de interface.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Essa função só deve ser chamada de dentro de um manipulador de eventos DHTML.

##  <a name="getexternal"></a>  CDHtmlDialog::GetExternal

Obtém o host `IDispatch` interface.

```
STDMETHOD(GetExternal)(IDispatch** ppDispatch);
```

### <a name="parameters"></a>Parâmetros

*ppDispatch*<br/>
Ver *ppDispatch* na [IDocHostUIHandler::GetExternal](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753256\(v=vs.85\)) no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Retornará S_OK no êxito ou E_NOTIMPL em caso de falha.

### <a name="remarks"></a>Comentários

Essa função membro é a implementação do CDHtmlDialog da [IDocHostUIHandler::GetExternal](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753256\(v=vs.85\)), conforme descrito no SDK do Windows.

##  <a name="gethostinfo"></a>  CDHtmlDialog::GetHostInfo

Recupera os recursos de interface do usuário do host.

```
STDMETHOD(GetHostInfo)(DOCHOSTUIINFO* pInfo);
```

### <a name="parameters"></a>Parâmetros

*pInfo*<br/>
Ver *pInfo* na [IDocHostUIHandler::GetHostInfo](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753257\(v=vs.85\)) no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

### <a name="remarks"></a>Comentários

Essa função membro é a implementação do CDHtmlDialog da [IDocHostUIHandler::GetHostInfo](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753257\(v=vs.85\)), conforme descrito no SDK do Windows.

##  <a name="getoptionkeypath"></a>  CDHtmlDialog::GetOptionKeyPath

Recupera a chave do registro sob a qual as preferências do usuário são armazenadas.

```
STDMETHOD(GetOptionKeyPath)(
    LPOLESTR* pchKey,
    DWORD dw);
```

### <a name="parameters"></a>Parâmetros

*pchKey*<br/>
Ver *pchKey* na [IDocHostUIHandler::GetOptionKeyPath](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753258\(v=vs.85\)) no SDK do Windows.

*dw*<br/>
Ver *dw* em `IDocHostUIHandler::GetOptionKeyPath` no Windows SDK.

### <a name="return-value"></a>Valor de retorno

Returns E_NOTIMPL.

### <a name="remarks"></a>Comentários

Essa função membro é a implementação do CDHtmlDialog da [IDocHostUIHandler::GetOptionKeyPath](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753258\(v=vs.85\)), conforme descrito no SDK do Windows.

##  <a name="hideui"></a>  CDHtmlDialog::HideUI

Oculta a interface de usuário do host.

```
STDMETHOD(HideUI)(void);
```

### <a name="return-value"></a>Valor de retorno

Returns E_NOTIMPL.

### <a name="remarks"></a>Comentários

Essa função membro é a implementação do CDHtmlDialog da [IDocHostUIHandler::HideUI](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753259\(v=vs.85\)), conforme descrito no SDK do Windows.

##  <a name="isexternaldispatchsafe"></a>  CDHtmlDialog::IsExternalDispatchSafe

Indica se o host `IDispatch` interface é seguro para script.

```
virtual BOOL IsExternalDispatchSafe();
```

### <a name="return-value"></a>Valor de retorno

Retorna FALSE.

##  <a name="loadfromresource"></a>  CDHtmlDialog::LoadFromResource

Carrega o recurso especificado no controle WebBrowser na caixa de diálogo DHTML.

```
BOOL LoadFromResource(LPCTSTR lpszResource);
BOOL LoadFromResource(UINT nRes);
```

### <a name="parameters"></a>Parâmetros

*lpszResource*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do recurso a carregar.

*nRes*<br/>
A ID do recurso para carregar.

### <a name="return-value"></a>Valor de retorno

VERDADEIRO se bem-sucedido; Caso contrário, FALSE.

##  <a name="m_busehtmltitle"></a>  CDHtmlDialog::m_bUseHtmlTitle

Indica se deve usar o título do documento HTML como a legenda da caixa de diálogo.

```
BOOL m_bUseHtmlTitle;
```

### <a name="remarks"></a>Comentários

Se **m**_ **bUseHtmlTitle** for TRUE, a legenda da caixa de diálogo será definida como igual ao título do documento HTML; caso contrário, a legenda no recurso da caixa de diálogo é usada.

##  <a name="m_nhtmlresid"></a>  CDHtmlDialog::m_nHtmlResID

Recurso de ID de HTML do recurso a ser exibido.

```
UINT m_nHtmlResID;
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCHtmlHttp#5](../../mfc/reference/codesnippet/cpp/cdhtmldialog-class_5.cpp)]

##  <a name="m_pbrowserapp"></a>  CDHtmlDialog::m_pBrowserApp

Um ponteiro para um aplicativo de navegador da Web.

```
CComPtr <IWebBrowser2> m_pBrowserApp;
```

##  <a name="m_sphtmldoc"></a>  CDHtmlDialog::m_spHtmlDoc

Um ponteiro para um documento HTML.

```
CComPtr<IHTMLDocument2> m_spHtmlDoc;
```

##  <a name="m_strcurrenturl"></a>  CDHtmlDialog::m_strCurrentUrl

A URL atual.

```
CString m_strCurrentUrl;
```

##  <a name="m_szhtmlresid"></a>  CDHtmlDialog::m_szHtmlResID

Versão de cadeia de caracteres da ID de recurso do HTML.

```
LPTSTR m_szHtmlResID;
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCHtmlHttp#6](../../mfc/reference/codesnippet/cpp/cdhtmldialog-class_6.cpp)]

##  <a name="navigate"></a>  CDHtmlDialog::Navigate

Navega para o recurso identificado por URL que é especificado pelo *lpszURL*.

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

*lpszURL*<br/>
Um ponteiro para uma cadeia de caracteres que contém a URL a ser direcionada.

*dwFlags*<br/>
Os sinalizadores de uma variável que especifica se deve adicionar o recurso à lista do histórico, se deve ao cache de leitura ou gravação do cache e se deseja exibir o recurso em uma nova janela. A variável pode ser uma combinação dos valores definidos pela [BrowserNavConstants](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768360\(v=vs.85\)) enumeração.

*lpszTargetFrameName*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do quadro no qual exibir o recurso.

*lpszHeaders*<br/>
Um ponteiro para um valor que especifica os cabeçalhos HTTP para enviar para o servidor. Esses cabeçalhos são adicionados aos cabeçalhos padrão do Internet Explorer. Os cabeçalhos podem especificar essas informações como a ação necessária do servidor, o tipo de dados que está sendo passados para o servidor ou um código de status. Esse parâmetro será ignorado se a URL não é uma URL HTTP.

*lpvPostData*<br/>
Um ponteiro para os dados a serem enviados com a transação de HTTP POST. Por exemplo, a transação de POST é usada para enviar os dados coletados por um formulário HTML. Se esse parâmetro não especifica quaisquer dados de postagem, `Navigate` emite uma transação HTTP GET. Esse parâmetro será ignorado se a URL não é uma URL HTTP.

*dwPostDataLen*<br/>
Dados a serem enviados com a transação de HTTP POST. Por exemplo, a transação de POST é usada para enviar os dados coletados por um formulário HTML. Se esse parâmetro não especifica quaisquer dados de postagem, `Navigate` emite uma transação HTTP GET. Esse parâmetro será ignorado se a URL não é uma URL HTTP.

##  <a name="onbeforenavigate"></a>  CDHtmlDialog::OnBeforeNavigate

Chamado pelo framework para fazer com que um evento seja acionado antes que ocorra uma navegação.

```
virtual void OnBeforeNavigate(
    LPDISPATCH pDisp,
    LPCTSTR szUrl);
```

### <a name="parameters"></a>Parâmetros

*pDisp*<br/>
Um ponteiro para um objeto `IDispatch`.

*szUrl*<br/>
Um ponteiro para uma cadeia de caracteres que contém a URL para navegar para.

##  <a name="ondocumentcomplete"></a>  CDHtmlDialog::OnDocumentComplete

Chamado pelo framework para notificar um aplicativo quando o estado READYSTATE_COMPLETE obtido em um documento.

```
virtual void OnDocumentComplete(
    LPDISPATCH pDisp,
    LPCTSTR szUrl);
```

### <a name="parameters"></a>Parâmetros

*pDisp*<br/>
Um ponteiro para um objeto `IDispatch`.

*szUrl*<br/>
Um ponteiro para uma cadeia de caracteres que contém a URL que foi acessada.

##  <a name="ondocwindowactivate"></a>  CDHtmlDialog::OnDocWindowActivate

Chamado pelo framework quando a janela do documento é ativada ou desativada.

```
STDMETHOD(OnDocWindowActivate)(BOOL fActivate);
```

### <a name="parameters"></a>Parâmetros

*fActivate*<br/>
Ver *fActivate* na [IDocHostUIHandler::OnDocWindowActivate](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753261\(v=vs.85\)) no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Returns E_NOTIMPL.

### <a name="remarks"></a>Comentários

Essa função membro é a implementação do CDHtmlDialog da [IDocHostUIHandler::OnDocWindowActivate](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753261\(v=vs.85\)), conforme descrito no SDK do Windows.

##  <a name="onframewindowactivate"></a>  CDHtmlDialog::OnFrameWindowActivate

Chamado pelo framework quando a janela do quadro é ativada ou desativada.

```
STDMETHOD(OnFrameWindowActivate)(BOOL fActivate);
```

### <a name="parameters"></a>Parâmetros

*fActivate*<br/>
Ver *fActivate* na [IDocHostUIHandler::OnFrameWindowActivate](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753262\(v=vs.85\)) no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Returns E_NOTIMPL.

### <a name="remarks"></a>Comentários

Essa função membro é a implementação do CDHtmlDialog da [IDocHostUIHandler::OnFrameWindowActivate](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753262\(v=vs.85\)), conforme descrito no SDK do Windows.

##  <a name="oninitdialog"></a>  CDHtmlDialog::OnInitDialog

Chamado em resposta à mensagem WM_INITDIALOG.

```
virtual BOOL OnInitDialog();
```

### <a name="return-value"></a>Valor de retorno

A implementação padrão retorna TRUE.

### <a name="remarks"></a>Comentários

Esta mensagem é enviada para a caixa de diálogo durante o `Create`, `CreateIndirect`, ou `DoModal` chamadas, o que ocorrerem imediatamente antes da caixa de diálogo é exibida.

Substitua essa função membro, se você precisar realizar processamento especial quando a caixa de diálogo é inicializada. A versão substituída, chame a classe base `OnInitDialog` mas desconsiderar seu valor de retorno. Normalmente, você retornará TRUE da sua função de membro substituído.

Chamadas de Windows o `OnInitDialog` funcionar por meio do procedimento de caixa de diálogo globais padrão comuns a todas as caixas de diálogo de biblioteca Microsoft Foundation Class, em vez de por meio de seu mapa de mensagem, portanto, não é necessário uma entrada de mapa de mensagem para essa função de membro.

##  <a name="onnavigatecomplete"></a>  CDHtmlDialog::OnNavigateComplete

Chamado pelo framework após a navegação para a URL especificada.

```
virtual void OnNavigateComplete(
    LPDISPATCH pDisp,
    LPCTSTR szUrl);
```

### <a name="parameters"></a>Parâmetros

*pDisp*<br/>
Um ponteiro para um objeto `IDispatch`.

*szUrl*<br/>
Um ponteiro para uma cadeia de caracteres que contém a URL que foi acessada.

##  <a name="resizeborder"></a>  CDHtmlDialog::ResizeBorder

O objeto que ele precisa para redimensionar o seu espaço de borda de alertas.

```
STDMETHOD(ResizeBorder)(
    LPCRECT prcBorder,
    IOleInPlaceUIWindow* pUIWindow,
    BOOL fRameWindow);
```

### <a name="parameters"></a>Parâmetros

*prcBorder*<br/>
Ver *prcBorder* na [IDocHostUIHandler::ResizeBorder](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753263\(v=vs.85\)) no SDK do Windows.

*pUIWindow*<br/>
Ver *pUIWindow* em `IDocHostUIHandler::ResizeBorder` no SDK do Windows.

*fFrameWindow*<br/>
Ver *fFrameWindow* em `IDocHostUIHandler::ResizeBorder` no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Returns E_NOTIMPL.

##  <a name="setcontrolproperty"></a>  CDHtmlDialog::SetControlProperty

Define a propriedade de um controle ActiveX para um novo valor.

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

*szElementId*<br/>
A ID de HTML de um controle ActiveX.

*dispId*<br/>
A ID de expedição da propriedade a ser definida.

*pVar*<br/>
Ponteiro para um tipo VARIANT que contém o novo valor da propriedade.

*pdispControl*<br/>
Ponteiro para um controle de ActiveX `IDispatch` interface.

*szPropName*<br/>
Cadeia de caracteres que contém o nome da propriedade a ser definido.

##  <a name="setelementhtml"></a>  CDHtmlDialog::SetElementHtml

Conjuntos de `innerHTML` propriedade de um elemento HTML.

```
void SetElementHtml(
    LPCTSTR szElementId,
    BSTR bstrText);

void SetElementHtml(
    IUnknown* punkElem,
    BSTR bstrText);
```

### <a name="parameters"></a>Parâmetros

*szElementId*<br/>
A ID de um elemento HTML.

*bstrText*<br/>
O novo valor da propriedade `innerHTML`.

*punkElem*<br/>
O `IUnknown` ponteiro de um elemento HTML.

##  <a name="setelementproperty"></a>  CDHtmlDialog::SetElementProperty

Define uma propriedade de um elemento HTML.

```
void SetElementProperty(
    LPCTSTR szElementId,
    DISPID dispId,
    VARIANT* pVar);
```

### <a name="parameters"></a>Parâmetros

*szElementId*<br/>
A ID de um elemento HTML.

*dispId*<br/>
A ID de expedição da propriedade a ser definida.

*pVar*<br/>
O novo valor da propriedade.

##  <a name="setelementtext"></a>  CDHtmlDialog::SetElementText

Conjuntos de `innerText` propriedade de um elemento HTML.

```
void SetElementText(
    LPCTSTR szElementId,
    BSTR bstrText);

void SetElementText(
    IUnknown* punkElem,
    BSTR bstrText);
```

### <a name="parameters"></a>Parâmetros

*szElementId*<br/>
A ID de um elemento HTML.

*bstrText*<br/>
O novo valor da propriedade `innerText`.

*punkElem*<br/>
O `IUnknown` ponteiro de um elemento HTML.

##  <a name="setexternaldispatch"></a>  CDHtmlDialog::SetExternalDispatch

Define o host `IDispatch` interface.

```
void SetExternalDispatch(IDispatch* pdispExternal);
```

### <a name="parameters"></a>Parâmetros

*pdispExternal*<br/>
O novo `IDispatch` interface.

##  <a name="sethostflags"></a>  CDHtmlDialog::SetHostFlags

Define o host de sinalizadores de interface do usuário.

```
void SetHostFlags(DWORD dwFlags);
```

### <a name="parameters"></a>Parâmetros

*dwFlags*<br/>
Para os valores possíveis, consulte [DOCHOSTUIFLAG](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753277\(v=vs.85\)) no SDK do Windows.

##  <a name="showcontextmenu"></a>  CDHtmlDialog::ShowContextMenu

Chamado quando um menu de contexto está prestes a ser exibido.

```
STDMETHOD(ShowContextMenu)(
    DWORD dwID,
    POINT* ppt,
    IUnknown* pcmdtReserved,
    IDispatch* pdispReserved);
```

### <a name="parameters"></a>Parâmetros

*dwID*<br/>
Ver *dwID* na [IDocHostUIHandler::ShowContextMenu](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753264\(v=vs.85\)) no SDK do Windows.

*ppt*<br/>
Ver *ppt* em `IDocHostUIHandler::ShowContextMenu` no Windows SDK.

*pcmdtReserved*<br/>
Ver *pcmdtReserved* em `IDocHostUIHandler::ShowContextMenu` no SDK do Windows.

*pdispReserved*<br/>
Ver *pdispReserved* em `IDocHostUIHandler::ShowContextMenu` no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Retorna S_FALSE.

### <a name="remarks"></a>Comentários

Essa função membro é a implementação do CDHtmlDialog da [IDocHostUIHandler::ShowContextMenu](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753264\(v=vs.85\)), conforme descrito no SDK do Windows.

##  <a name="showui"></a>  CDHtmlDialog::ShowUI

Mostra da interface do usuário o nome do host.

```
STDMETHOD(ShowUI)(
    DWORD dwID,
    IOleInPlaceActiveObject* pActiveObject,
    IOleCommandTarget* pCommandTarget,
    IOleInPlaceFrame* pFrame,
    IOleInPlaceUIWindow* pDoc);
```

### <a name="parameters"></a>Parâmetros

*dwID*<br/>
Ver *dwID* na [IDocHostUIHandler::ShowUI](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753265\(v=vs.85\)) no SDK do Windows.

*pActiveObject*<br/>
Ver *d pActiveObject* em `IDocHostUIHandler::ShowUI` no SDK do Windows.

*pCommandTarget*<br/>
Ver *pCommandTarget* em `IDocHostUIHandler::ShowUI` no SDK do Windows.

*pFrame*<br/>
Ver *pFrame* em `IDocHostUIHandler::ShowUI` no SDK do Windows.

*pDoc*<br/>
Ver *pDoc* em `IDocHostUIHandler::ShowUI` no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Retorna S_FALSE.

### <a name="remarks"></a>Comentários

Essa função membro é a implementação do CDHtmlDialog da [IDocHostUIHandler::ShowUI](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753265\(v=vs.85\)), conforme descrito no SDK do Windows.

##  <a name="translateaccelerator"></a>  CDHtmlDialog::TranslateAccelerator

Chamado para processar as mensagens de tecla de atalho do menu.

```
STDMETHOD(TranslateAccelerator)(
    LPMSG lpMsg,
    const GUID* pguidCmdGroup,
    DWORD nCmdID);
```

### <a name="parameters"></a>Parâmetros

*lpMsg*<br/>
Ver *lpMsg* na [IDocHostUIHandler::TranslateAccelerator](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753266\(v=vs.85\)) no SDK do Windows.

*pguidCmdGroup*<br/>
Ver *pguidCmdGroup* em `IDocHostUIHandler::TranslateAccelerator` no SDK do Windows.

*nCmdID*<br/>
Ver *nCmdID* em `IDocHostUIHandler::TranslateAccelerator` no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Retorna S_FALSE.

### <a name="remarks"></a>Comentários

Essa função membro é a implementação do CDHtmlDialog da [IDocHostUIHandler::TranslateAccelerator](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753266\(v=vs.85\)), conforme descrito no SDK do Windows.

##  <a name="translateurl"></a>  CDHtmlDialog::TranslateUrl

Chamado para modificar a URL a ser carregado.

```
STDMETHOD(TranslateUrl)(
    DWORD dwTranslate,
    OLECHAR* pchURLIn,
    OLECHAR** ppchURLOut);
```

### <a name="parameters"></a>Parâmetros

*dwTranslate*<br/>
Ver *dwTranslate* na [IDocHostUIHandler::TranslateUrl](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753267\(v=vs.85\)) no SDK do Windows.

*pchURLIn*<br/>
Ver *pchURLIn* em `IDocHostUIHandler::TranslateUrl` no SDK do Windows.

*ppchURLOut*<br/>
Ver *ppchURLOut* em `IDocHostUIHandler::TranslateUrl` no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Retorna S_FALSE.

### <a name="remarks"></a>Comentários

Essa função membro é a implementação do CDHtmlDialog da [IDocHostUIHandler::TranslateUrl](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753267\(v=vs.85\)), conforme descrito no SDK do Windows.

##  <a name="updateui"></a>  CDHtmlDialog::UpdateUI

Chamado para notificar o host que o estado do comando foi alterado.

```
STDMETHOD(UpdateUI)(void);
```

### <a name="return-value"></a>Valor de retorno

Returns E_NOTIMPL.

### <a name="remarks"></a>Comentários

Essa função membro é a implementação do CDHtmlDialog da [IDocHostUIHandler::UpdateUI](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa753268\(v=vs.85\)), conforme descrito no SDK do Windows.

## <a name="see-also"></a>Consulte também

[DHtmlExplore de exemplo do MFC](../../overview/visual-cpp-samples.md)<br/>
[Macros auxiliares DDX_DHtml](#ddx_dhtml_helper_macros)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
