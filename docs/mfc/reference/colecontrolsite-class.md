---
title: Classe COleControlSite
ms.date: 11/04/2016
f1_keywords:
- COleControlSite
- AFXOCC/COleControlSite
- AFXOCC/COleControlSite::COleControlSite
- AFXOCC/COleControlSite::BindDefaultProperty
- AFXOCC/COleControlSite::BindProperty
- AFXOCC/COleControlSite::CreateControl
- AFXOCC/COleControlSite::DestroyControl
- AFXOCC/COleControlSite::DoVerb
- AFXOCC/COleControlSite::EnableDSC
- AFXOCC/COleControlSite::EnableWindow
- AFXOCC/COleControlSite::FreezeEvents
- AFXOCC/COleControlSite::GetDefBtnCode
- AFXOCC/COleControlSite::GetDlgCtrlID
- AFXOCC/COleControlSite::GetEventIID
- AFXOCC/COleControlSite::GetExStyle
- AFXOCC/COleControlSite::GetProperty
- AFXOCC/COleControlSite::GetStyle
- AFXOCC/COleControlSite::GetWindowText
- AFXOCC/COleControlSite::InvokeHelper
- AFXOCC/COleControlSite::InvokeHelperV
- AFXOCC/COleControlSite::IsDefaultButton
- AFXOCC/COleControlSite::IsWindowEnabled
- AFXOCC/COleControlSite::ModifyStyle
- AFXOCC/COleControlSite::ModifyStyleEx
- AFXOCC/COleControlSite::MoveWindow
- AFXOCC/COleControlSite::QuickActivate
- AFXOCC/COleControlSite::SafeSetProperty
- AFXOCC/COleControlSite::SetDefaultButton
- AFXOCC/COleControlSite::SetDlgCtrlID
- AFXOCC/COleControlSite::SetFocus
- AFXOCC/COleControlSite::SetProperty
- AFXOCC/COleControlSite::SetPropertyV
- AFXOCC/COleControlSite::SetWindowPos
- AFXOCC/COleControlSite::SetWindowText
- AFXOCC/COleControlSite::ShowWindow
- AFXOCC/COleControlSite::GetControlInfo
- AFXOCC/COleControlSite::m_bIsWindowless
- AFXOCC/COleControlSite::m_ctlInfo
- AFXOCC/COleControlSite::m_dwEventSink
- AFXOCC/COleControlSite::m_dwMiscStatus
- AFXOCC/COleControlSite::m_dwPropNotifySink
- AFXOCC/COleControlSite::m_dwStyle
- AFXOCC/COleControlSite::m_hWnd
- AFXOCC/COleControlSite::m_iidEvents
- AFXOCC/COleControlSite::m_nID
- AFXOCC/COleControlSite::m_pActiveObject
- AFXOCC/COleControlSite::m_pCtrlCont
- AFXOCC/COleControlSite::m_pInPlaceObject
- AFXOCC/COleControlSite::m_pObject
- AFXOCC/COleControlSite::m_pWindowlessObject
- AFXOCC/COleControlSite::m_pWndCtrl
- AFXOCC/COleControlSite::m_rect
helpviewer_keywords:
- COleControlSite [MFC], COleControlSite
- COleControlSite [MFC], BindDefaultProperty
- COleControlSite [MFC], BindProperty
- COleControlSite [MFC], CreateControl
- COleControlSite [MFC], DestroyControl
- COleControlSite [MFC], DoVerb
- COleControlSite [MFC], EnableDSC
- COleControlSite [MFC], EnableWindow
- COleControlSite [MFC], FreezeEvents
- COleControlSite [MFC], GetDefBtnCode
- COleControlSite [MFC], GetDlgCtrlID
- COleControlSite [MFC], GetEventIID
- COleControlSite [MFC], GetExStyle
- COleControlSite [MFC], GetProperty
- COleControlSite [MFC], GetStyle
- COleControlSite [MFC], GetWindowText
- COleControlSite [MFC], InvokeHelper
- COleControlSite [MFC], InvokeHelperV
- COleControlSite [MFC], IsDefaultButton
- COleControlSite [MFC], IsWindowEnabled
- COleControlSite [MFC], ModifyStyle
- COleControlSite [MFC], ModifyStyleEx
- COleControlSite [MFC], MoveWindow
- COleControlSite [MFC], QuickActivate
- COleControlSite [MFC], SafeSetProperty
- COleControlSite [MFC], SetDefaultButton
- COleControlSite [MFC], SetDlgCtrlID
- COleControlSite [MFC], SetFocus
- COleControlSite [MFC], SetProperty
- COleControlSite [MFC], SetPropertyV
- COleControlSite [MFC], SetWindowPos
- COleControlSite [MFC], SetWindowText
- COleControlSite [MFC], ShowWindow
- COleControlSite [MFC], GetControlInfo
- COleControlSite [MFC], m_bIsWindowless
- COleControlSite [MFC], m_ctlInfo
- COleControlSite [MFC], m_dwEventSink
- COleControlSite [MFC], m_dwMiscStatus
- COleControlSite [MFC], m_dwPropNotifySink
- COleControlSite [MFC], m_dwStyle
- COleControlSite [MFC], m_hWnd
- COleControlSite [MFC], m_iidEvents
- COleControlSite [MFC], m_nID
- COleControlSite [MFC], m_pActiveObject
- COleControlSite [MFC], m_pCtrlCont
- COleControlSite [MFC], m_pInPlaceObject
- COleControlSite [MFC], m_pObject
- COleControlSite [MFC], m_pWindowlessObject
- COleControlSite [MFC], m_pWndCtrl
- COleControlSite [MFC], m_rect
ms.assetid: 43970644-5eab-434a-8ba6-56d144ff1e3f
ms.openlocfilehash: 26d0f5e875c4f3982705a2cf571b15cd5bfac985
ms.sourcegitcommit: 975098222db3e8b297607cecaa1f504570a11799
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2018
ms.locfileid: "53178909"
---
# <a name="colecontrolsite-class"></a>Classe COleControlSite

Fornece suporte para interfaces de controle personalizado do lado do cliente.

## <a name="syntax"></a>Sintaxe

```
class COleControlSite : public CCmdTarget
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleControlSite::COleControlSite](#colecontrolsite)|Constrói um objeto `COleControlSite`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleControlSite::BindDefaultProperty](#binddefaultproperty)|Associa a propriedade padrão do controle hospedado para uma fonte de dados.|
|[COleControlSite::BindProperty](#bindproperty)|Associa uma propriedade do controle hospedado para uma fonte de dados.|
|[COleControlSite::CreateControl](#createcontrol)|Cria um controle ActiveX hospedado.|
|[COleControlSite::DestroyControl](#destroycontrol)|Destrói o controle hospedado.|
|[COleControlSite::DoVerb](#doverb)|Executa um verbo específico do controle hospedado.|
|[COleControlSite::EnableDSC](#enabledsc)|Permite o fornecimento de um site de controle de dados.|
|[COleControlSite::EnableWindow](#enablewindow)|Permite que o site do controle.|
|[COleControlSite::FreezeEvents](#freezeevents)|Especifica se o site do controle está aceitando os eventos.|
|[COleControlSite::GetDefBtnCode](#getdefbtncode)|Recupera o código do botão padrão para o controle hospedado.|
|[COleControlSite::GetDlgCtrlID](#getdlgctrlid)|Recupera o identificador do controle.|
|[COleControlSite::GetEventIID](#geteventiid)|Recupera a ID de uma interface de eventos para um controle hospedado.|
|[COleControlSite::GetExStyle](#getexstyle)|Recupera os estilos estendidos do site do controle.|
|[COleControlSite::GetProperty](#getproperty)|Recupera uma propriedade específica do controle hospedado.|
|[COleControlSite::GetStyle](#getstyle)|Recupera os estilos do site do controle.|
|[COleControlSite::GetWindowText](#getwindowtext)|Recupera o texto do controle hospedado.|
|[COleControlSite::InvokeHelper](#invokehelper)|Invocar um método específico do controle hospedado.|
|[COleControlSite::InvokeHelperV](#invokehelperv)|Invocar um método específico do controle hospedado com uma lista de argumentos de variável.|
|[COleControlSite::IsDefaultButton](#isdefaultbutton)|Determina se o controle é o botão padrão na janela.|
|[COleControlSite::IsWindowEnabled](#iswindowenabled)|Verifica o estado visível do site de controle.|
|[COleControlSite::ModifyStyle](#modifystyle)|Modifica o atual estendido estilos do site do controle.|
|[COleControlSite::ModifyStyleEx](#modifystyleex)|Modifica os estilos atuais do site do controle.|
|[COleControlSite::MoveWindow](#movewindow)|Altera a posição do site do controle.|
|[COleControlSite::QuickActivate](#quickactivate)|Rápido ativa o controle hospedado.|
|[COleControlSite::SafeSetProperty](#safesetproperty)|Define uma propriedade ou método do controle sem possibilidade de gerar uma exceção.|
|[COleControlSite::SetDefaultButton](#setdefaultbutton)|Define o botão padrão da janela.|
|[COleControlSite::SetDlgCtrlID](#setdlgctrlid)|Recupera o identificador do controle.|
|[COleControlSite::SetFocus](#setfocus)|Define o foco para o site do controle.|
|[COleControlSite::SetProperty](#setproperty)|Define uma propriedade específica do controle hospedado.|
|[COleControlSite::SetPropertyV](#setpropertyv)|Define uma propriedade específica do controle hospedado com uma lista de argumentos de variável.|
|[COleControlSite::SetWindowPos](#setwindowpos)|Define a posição do site do controle.|
|[COleControlSite::SetWindowText](#setwindowtext)|Define o texto do controle hospedado.|
|[COleControlSite::ShowWindow](#showwindow)|Mostra ou oculta o site do controle.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[COleControlSite::GetControlInfo](#getcontrolinfo)|Recupera informações sobre o teclado e mnemônicos para o controle hospedado.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleControlSite::m_bIsWindowless](#m_biswindowless)|Determina se o controle hospedado é um controle sem janelas.|
|[COleControlSite::m_ctlInfo](#m_ctlinfo)|Contém informações sobre de teclado para o controle.|
|[COleControlSite::m_dwEventSink](#m_dweventsink)|O cookie de ponto de conexão do controle.|
|[COleControlSite::m_dwMiscStatus](#m_dwmiscstatus)|Os diversos estados para o controle hospedado.|
|[COleControlSite::m_dwPropNotifySink](#m_dwpropnotifysink)|O `IPropertyNotifySink` cookie do controle.|
|[COleControlSite::m_dwStyle](#m_dwstyle)|Os estilos do controle hospedado.|
|[COleControlSite::m_hWnd](#m_hwnd)|O identificador do site de controle.|
|[COleControlSite::m_iidEvents](#m_iidevents)|A ID da interface do evento para o controle hospedado.|
|[COleControlSite::m_nID](#m_nid)|A ID do controle hospedado.|
|[COleControlSite::m_pActiveObject](#m_pactiveobject)|Um ponteiro para o `IOleInPlaceActiveObject` objeto do controle hospedado.|
|[COleControlSite::m_pCtrlCont](#m_pctrlcont)|O contêiner do controle hospedado.|
|[COleControlSite::m_pInPlaceObject](#m_pinplaceobject)|Um ponteiro para o `IOleInPlaceObject` objeto do controle hospedado.|
|[COleControlSite::m_pObject](#m_pobject)|Um ponteiro para o `IOleObjectInterface` interface do controle.|
|[COleControlSite::m_pWindowlessObject](#m_pwindowlessobject)|Um ponteiro para o `IOleInPlaceObjectWindowless` interface do controle.|
|[COleControlSite::m_pWndCtrl](#m_pwndctrl)|Um ponteiro para o objeto de janela para o controle hospedado.|
|[COleControlSite::m_rect](#m_rect)|As dimensões do site do controle.|

## <a name="remarks"></a>Comentários

Esse suporte é o principal meio pelo qual um controle ActiveX incorporado obtém informações sobre a localização e a extensão do seu site de exibição, seu identificador de origem, sua interface do usuário, suas propriedades de ambientes e outros recursos fornecidos por seu contêiner. `COleControlSite` implementa totalmente a [IOleControlSite](/windows/desktop/api/ocidl/nn-ocidl-iolecontrolsite), [IOleInPlaceSite](/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite), [IOleClientSite](/windows/desktop/api/oleidl/nn-oleidl-ioleclientsite), [IPropertyNotifySink](/windows/desktop/api/ocidl/nn-ocidl-ipropertynotifysink), `IBoundObjectSite`, `INotifyDBEvents`, [IRowSetNotify](../../data/oledb/irowsetnotifyimpl-class.md) interfaces. Além disso, a interface IDispatch (fornecendo suporte para propriedades de ambiente e Coletores de eventos) também é implementada.

Para criar um site de controle ActiveX usando `COleControlSite`, derive uma classe de `COleControlSite`. No seu `CWnd`-uma classe derivada para o contêiner (por exemplo, sua caixa de diálogo) substituir o `CWnd::CreateControlSite` função.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

`COleControlSite`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxocc.h

##  <a name="binddefaultproperty"></a>  COleControlSite::BindDefaultProperty

Associa a chamada propriedade do objeto padrão simples associadas, como marcada na biblioteca de tipos, até o cursor subjacente que é definido pelas propriedades do controle de fonte de dados SQL, nome de usuário, senha e fonte de dados.

```
virtual void BindDefaultProperty(
    DISPID dwDispID,
    VARTYPE vtProp,
    LPCTSTR szFieldName,
    CWnd* pDSCWnd);
```

### <a name="parameters"></a>Parâmetros

*dwDispID*<br/>
Especifica o DISPID de uma propriedade em um controle de associação de dados que deve ser associado a um controle de fonte de dados.

*vtProp*<br/>
Especifica o tipo da propriedade a ser associado — por exemplo, VT_BSTR, VT_VARIANT e assim por diante.

*szFieldName*<br/>
Especifica o nome da coluna, no cursor fornecido pelo controle de fonte de dados, à qual a propriedade será associada.

*pDSCWnd*<br/>
Um ponteiro para o `CWnd`-objeto derivado que hospeda o controle de fonte de dados ao qual a propriedade será associada.

### <a name="remarks"></a>Comentários

O `CWnd` objeto no qual você pode chamar essa função deve ser um controle associado a dados.

##  <a name="bindproperty"></a>  COleControlSite::BindProperty

Associa a chamada propriedade do objeto simples associadas, como marcada na biblioteca de tipos, até o cursor subjacente que é definido pelas propriedades do controle de fonte de dados SQL, nome de usuário, senha e fonte de dados.

```
virtual void BindProperty(
    DISPID dwDispId,
    CWnd* pWndDSC);
```

### <a name="parameters"></a>Parâmetros

*dwDispId*<br/>
Especifica o DISPID de uma propriedade em um controle de associação de dados que deve ser associado a um controle de fonte de dados.

*pWndDSC*<br/>
Um ponteiro para o `CWnd`-objeto derivado que hospeda o controle de fonte de dados ao qual a propriedade será associada.

### <a name="remarks"></a>Comentários

O `CWnd` objeto no qual você pode chamar essa função deve ser um controle associado a dados.

##  <a name="colecontrolsite"></a>  COleControlSite::COleControlSite

Constrói um novo objeto `COleControlSite`.

```
explicit COleControlSite(COleControlContainer* pCtrlCont);
```

### <a name="parameters"></a>Parâmetros

*pCtrlCont*<br/>
Um ponteiro para o contêiner do controle (que representa a janela que hospeda o controle ActiveX).

### <a name="remarks"></a>Comentários

Essa função é chamada o [COccManager::CreateContainer](../../mfc/reference/coccmanager-class.md#createcontainer) função. Para obter mais informações sobre como personalizar a criação de contêineres, consulte [COccManager::CreateSite](../../mfc/reference/coccmanager-class.md#createsite).

##  <a name="createcontrol"></a>  COleControlSite::CreateControl

Cria um controle ActiveX, hospedado pelo `COleControlSite` objeto.

```
virtual HRESULT CreateControl(
    CWnd* pWndCtrl,
    REFCLSID clsid,
    LPCTSTR lpszWindowName,
    DWORD dwStyle,
    const RECT& rect,
    UINT nID,
    CFile* pPersist = NULL,
    BOOL bStorage = FALSE,
    BSTR bstrLicKey = NULL);

virtual HRESULT CreateControl(
    CWnd* pWndCtrl,
    REFCLSID clsid,
    LPCTSTR lpszWindowName,
    DWORD dwStyle,
    const POINT* ppt,
    const SIZE* psize,
    UINT nID,
    CFile* pPersist = NULL,
    BOOL bStorage = FALSE,
    BSTR bstrLicKey = NULL);
```

### <a name="parameters"></a>Parâmetros

*pWndCtrl*<br/>
Um ponteiro para o objeto window representando o controle.

*clsid*<br/>
A ID exclusiva de classe do controle.

*lpszWindowName*<br/>
Um ponteiro para o texto a ser exibido no controle. Define o valor da propriedade de legenda ou o texto do winodw (se houver).

*dwStyle*<br/>
Estilos do Windows. Os estilos disponíveis são listados sob o **comentários** seção.

*Rect*<br/>
Especifica o tamanho e a posição do controle. Ela pode ser um `CRect` objeto ou um `RECT` estrutura.

*nID*<br/>
Especifica a ID de janela filho do controle

*pPersist*<br/>
Um ponteiro para um `CFile` que contém o estado persistente do controle. O valor padrão é NULL, indicando que o controle iniciado sozinho sem restaurar seu estado de qualquer armazenamento persistente. Se não for NULL, ele deve ser um ponteiro para um `CFile`-derivados do objeto que contém os dados do controle persistente, na forma de um fluxo ou um armazenamento. Esses dados poderiam foram salvas em uma ativação anterior do cliente. O `CFile` pode conter outros dados, mas deve ter seu ponteiro de leitura / gravação definido como o primeiro byte de dados persistentes no momento da chamada para `CreateControl`.

*bStorage*<br/>
Indica se os dados no *pPersist* devem ser interpretadas como `IStorage` ou `IStream` dados. Se os dados no *pPersist* é um armazenamento *bStorage* deve ser verdadeiro. Se os dados no *pPersist* é um fluxo *bStorage* deve ser FALSE. O valor padrão é FALSE.

*bstrLicKey*<br/>
Dados opcionais de chave de licença. Esses dados é necessária apenas para a criação de controles que exigem uma chave de licença de tempo de execução. Se o controle dá suporte ao licenciamento, você deve fornecer uma chave de licença para a criação do controle seja bem-sucedida. O valor padrão é NULL.

*ppt*<br/>
Um ponteiro para um `POINT` estrutura que contém o canto superior esquerdo do controle. O tamanho do controle é determinado pelo valor de *psize*. O *ppt* e *psize* valores são um método opcional de especificar o tamanho e posição opf o controle.

*psize*<br/>
Um ponteiro para um `SIZE` estrutura que contém o tamanho do controle. O canto superior esquerdo é determinado pelo valor de *ppt*. O *ppt* e *psize* valores são um método opcional de especificar o tamanho e posição opf o controle.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Apenas um subconjunto do Windows *dwStyle* sinalizadores são compatíveis com `CreateControl`:

- WS_VISIBLE cria uma janela que é visível inicialmente. Necessário se você deseja que o controle esteja visível imediatamente, como janelas comuns.

- WS_DISABLED cria uma janela que é inicialmente desabilitada. Uma janela desabilitada não pode receber entrada do usuário. Pode ser definido se o controle tem uma propriedade Enabled.

- WS_BORDER cria uma janela com uma borda de linha fina. Pode ser definido se o controle tem uma propriedade BorderStyle.

- WS_GROUP Especifica o primeiro controle de um grupo de controles. O usuário pode alterar o foco do teclado de um controle no grupo para a próxima usando as teclas de direção. Todos os controles definidos com o estilo WS_GROUP após o primeiro controle pertencem ao mesmo grupo. O próximo controle com o estilo WS_GROUP termina o grupo e inicia o próximo grupo.

- WS_TABSTOP Especifica um controle que pode receber o foco do teclado quando o usuário pressiona a tecla TAB. Pressionar a tecla TAB altera o foco do teclado para o próximo controle do estilo WS_TABSTOP.

Use a segunda sobrecarga para criar controles de tamanho padrão.

##  <a name="destroycontrol"></a>  COleControlSite::DestroyControl

Destrói o `COleControlSite` objeto.

```
virtual BOOL DestroyControl();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se for bem-sucedido, caso contrário, 0.

### <a name="remarks"></a>Comentários

Depois de concluído, o objeto é liberado da memória e todos os ponteiros para o objeto não são mais válidos.

##  <a name="doverb"></a>  COleControlSite::DoVerb

Executa o verbo especificado.

```
virtual HRESULT DoVerb(
    LONG nVerb,
    LPMSG lpMsg = NULL);
```

### <a name="parameters"></a>Parâmetros

*nVerb*<br/>
Especifica o verbo a ser executado. Ele pode incluir um dos seguintes:

|Valor|Significado|Símbolo|
|-----------|-------------|------------|
|0|Verbo primário|OLEIVERB_PRIMARY|
|-1|Verbo secundário|(Nenhum)|
|1|Exibe o objeto para edição.|OLEIVERB_SHOW|
|-2|Edita o item em uma janela separada.|OLEIVERB_OPEN|
|-3|Oculta o objeto.|OLEIVERB_HIDE|
|-4|Ativa um controle no local.|OLEIVERB_UIACTIVATE|
|-5|Ativa um controle no local, sem elementos de interface do usuário adicionais.|OLEIVERB_INPLACEACTIVATE|
|-7|Exiba as propriedades do controle.|OLEIVERB_PROPERTIES|

*lpMsg*<br/>
Ponteiro para a mensagem que causou o item a ser ativado.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Essa função chama diretamente por meio do controle `IOleObject` interface para executar o verbo especificado. Se uma exceção é gerada como resultado dessa chamada de função, um código de erro HRESULT será retornado.

Para obter mais informações, consulte [IOleObject:: DoVerb](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-doverb) no SDK do Windows.

##  <a name="enabledsc"></a>  COleControlSite::EnableDSC

Permite o fornecimento para o site de controle de dados.

```
virtual void EnableDSC();
```

### <a name="remarks"></a>Comentários

Chamado pelo framework para ativar e inicializar para o site de controle de fornecimento de dados. Substitua essa função para fornecer um comportamento personalizado.

##  <a name="enablewindow"></a>  COleControlSite::EnableWindow

Habilita ou desabilita o mouse e teclado de entrada para o site do controle.

```
virtual BOOL EnableWindow(BOOL bEnable);
```

### <a name="parameters"></a>Parâmetros

*bAtivar*<br/>
Especifica se é habilitar ou desabilitar a janela: TRUE se a entrada da janela deve ser habilitado, caso contrário, FALSE.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a janela tiver sido desabilitada anteriormente, caso contrário, 0.

##  <a name="freezeevents"></a>  COleControlSite::FreezeEvents

Especifica se o site do controle irá tratar ou ignorar os eventos disparados a partir de um controle.

```
void FreezeEvents(BOOL bFreeze);
```

### <a name="parameters"></a>Parâmetros

*bFreeze*<br/>
Especifica se o site do controle deseja parar de aceitar eventos. Diferente de zero se o controle não está aceitando eventos; Caso contrário, zero.

### <a name="remarks"></a>Comentários

Se *bFreeze* for TRUE, o controle para interromper eventos Traga as solicitações de site de controle. Se *bFreeze* é FALSE, o site do controle solicita o controle para continuar acionando eventos.

> [!NOTE]
>  O controle não é necessário para interromper eventos acionados se solicitado pelo site de controle. Ele pode continuar acionando, mas todos os eventos subsequentes serão ignorados pelo site do controle.

##  <a name="getcontrolinfo"></a>  COleControlSite::GetControlInfo

Recupera informações sobre um controle mnemônicos de teclado e comportamento do teclado.

```
void GetControlInfo();
```

### <a name="remarks"></a>Comentários

As informações são armazenadas no [COleControlSite::m_ctlInfo](#m_ctlinfo).

##  <a name="getdefbtncode"></a>  COleControlSite::GetDefBtnCode

Determina se o controle é um botão de ação padrão.

```
DWORD GetDefBtnCode();
```

### <a name="return-value"></a>Valor de retorno

pode ser um dos seguintes valores:

- Controle de DLGC_DEFPUSHBUTTON é o botão padrão na caixa de diálogo.

- Controle de DLGC_UNDEFPUSHBUTTON não é o botão padrão na caixa de diálogo.

- **0** controle não é um botão.

##  <a name="getdlgctrlid"></a>  COleControlSite::GetDlgCtrlID

Recupera o identificador do controle.

```
virtual int GetDlgCtrlID() const;
```

### <a name="return-value"></a>Valor de retorno

O identificador do item de caixa de diálogo do controle.

##  <a name="geteventiid"></a>  COleControlSite::GetEventIID

Recupera um ponteiro para a interface de eventos padrão do controle.

```
BOOL GetEventIID(IID* piid);
```

### <a name="parameters"></a>Parâmetros

*piid*<br/>
Um ponteiro para uma ID de interface.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se for bem-sucedido, caso contrário, 0. Se for bem-sucedido, *piid* contém a ID de interface para a interface de eventos padrão do controle.

##  <a name="getexstyle"></a>  COleControlSite::GetExStyle

Recupera os estilos estendidos da janela.

```
virtual DWORD GetExStyle() const;
```

### <a name="return-value"></a>Valor de retorno

A janela de controle do estilos estendidos.

### <a name="remarks"></a>Comentários

Para recuperar os estilos regulares, chame [COleControlSite::GetStyle](#getstyle).

##  <a name="getproperty"></a>  COleControlSite::GetProperty

Obtém a propriedade do controle especificada pelo *dwDispID*.

```
virtual void GetProperty(
    DISPID dwDispID,
    VARTYPE vtProp,
    void* pvProp) const;
```

### <a name="parameters"></a>Parâmetros

*dwDispID*<br/>
Identifica a ID de expedição da propriedade, encontrada no padrão do controle `IDispatch` interface a ser recuperado.

*vtProp*<br/>
Especifica o tipo da propriedade a ser recuperado. Para os valores possíveis, consulte a seção comentários para [COleDispatchDriver::InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).

*pvProp*<br/>
Endereço da variável que receberá o valor da propriedade. Ele deve corresponder ao tipo especificado pelo *vtProp*.

### <a name="remarks"></a>Comentários

O valor é retornado pelo *pvProp*.

##  <a name="getstyle"></a>  COleControlSite::GetStyle

Recupera os estilos do site do controle.

```
virtual DWORD GetStyle() const;
```

### <a name="return-value"></a>Valor de retorno

Estilos da janela.

### <a name="remarks"></a>Comentários

Para obter uma lista de valores possíveis, consulte [estilos Windows](../../mfc/reference/styles-used-by-mfc.md#window-styles). Para recuperar os estilos estendidos de site de controle, chame [COleControlSite::GetExStyle](#getexstyle).

##  <a name="getwindowtext"></a>  COleControlSite::GetWindowText

Recupera o texto atual do controle.

```
virtual void GetWindowText(CString& str) const;
```

### <a name="parameters"></a>Parâmetros

*str*<br/>
Uma referência a um `CString` objeto que contém o texto atual do controle.

### <a name="remarks"></a>Comentários

Se o controle suporta a propriedade de estoque de legenda, esse valor é retornado. Se não há suporte para a propriedade de estoque de legenda, o valor da propriedade Text será retornado.

##  <a name="invokehelper"></a>  COleControlSite::InvokeHelper

Invoca o método ou propriedade especificada por *dwDispID*, no contexto especificado por *wFlags*.

```
virtual void AFX_CDECL InvokeHelper(
    DISPID dwDispID,
    WORD wFlags,
    VARTYPE vtRet,
    void* pvRet,
    const BYTE* pbParamInfo, ...);
```

### <a name="parameters"></a>Parâmetros

*dwDispID*<br/>
Identifica a ID de expedição da propriedade ou método, encontrado na propriedade do controle `IDispatch` interface a ser invocado.

*wFlags*<br/>
Sinalizadores que descrevem o contexto da chamada para IDispatch:: Invoke. Para possíveis *wFlags* valores, consulte `IDispatch::Invoke` no SDK do Windows.

*vtRet*<br/>
Especifica o tipo do valor de retorno. Para os valores possíveis, consulte a seção comentários para [COleDispatchDriver::InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).

*pvRet*<br/>
Endereço da variável que receberá o valor da propriedade ou valor de retorno. Ele deve corresponder ao tipo especificado pelo *vtRet*.

*pbParamInfo*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo de bytes que especifica os tipos dos parâmetros a seguir *pbParamInfo*. Para os valores possíveis, consulte a seção comentários para [COleDispatchDriver::InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).

*...*<br/>
A lista de variáveis de parâmetros de tipos especificados em *pbParamInfo*.

### <a name="remarks"></a>Comentários

O *pbParamInfo* parâmetro especifica os tipos dos parâmetros passados para o método ou propriedade. A lista de argumentos de variáveis é representada por... na declaração de sintaxe.

Esta função converte os parâmetros para valores VARIANTARG, em seguida, invoca o `IDispatch::Invoke` método no controle. Se a chamada para `IDispatch::Invoke` falhar, essa função gerará uma exceção. Se o código de status retornado pela `IDispatch::Invoke` está `DISP_E_EXCEPTION`, essa função gera uma `COleDispatchException` objeto, caso contrário, ele gera um `COleException`.

##  <a name="invokehelperv"></a>  COleControlSite::InvokeHelperV

Invoca o método ou propriedade especificada por *dwDispID*, no contexto especificado por *wFlags*.

```
virtual void InvokeHelperV(
    DISPID dwDispID,
    WORD wFlags,
    VARTYPE vtRet,
    void* pvRet,
    const BYTE* pbParamInfo,
    va_list argList);
```

### <a name="parameters"></a>Parâmetros

*dwDispID*<br/>
Identifica a ID de expedição da propriedade ou método, encontrado na propriedade do controle `IDispatch` interface a ser invocado.

*wFlags*<br/>
Sinalizadores que descrevem o contexto da chamada para IDispatch:: Invoke.

*vtRet*<br/>
Especifica o tipo do valor de retorno. Para os valores possíveis, consulte a seção comentários para [COleDispatchDriver::InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).

*pvRet*<br/>
Endereço da variável que receberá o valor da propriedade ou valor de retorno. Ele deve corresponder ao tipo especificado pelo *vtRet*.

*pbParamInfo*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo de bytes que especifica os tipos dos parâmetros a seguir *pbParamInfo*. Para os valores possíveis, consulte a seção comentários para [COleDispatchDriver::InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).

*argList*<br/>
Ponteiro para uma lista de argumentos variável.

### <a name="remarks"></a>Comentários

O *pbParamInfo* parâmetro especifica os tipos dos parâmetros passados para o método ou propriedade. Parâmetros extras para o método ou propriedade que está sendo invocado podem ser passados usando o *va_list* parâmetro.

Normalmente, essa função é chamada pelo `COleControlSite::InvokeHelper`.

##  <a name="isdefaultbutton"></a>  COleControlSite::IsDefaultButton

Determina se o controle é o botão padrão.

```
BOOL IsDefaultButton();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o controle é o botão padrão na janela, caso contrário, zero.

##  <a name="iswindowenabled"></a>  COleControlSite::IsWindowEnabled

Determina se o site do controle está habilitado.

```
virtual BOOL IsWindowEnabled() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o controle está habilitado, caso contrário, zero.

### <a name="remarks"></a>Comentários

O valor é recuperado da propriedade de estoque de ativado do controle.

##  <a name="m_biswindowless"></a>  COleControlSite::m_bIsWindowless

Determina se o objeto for um controle sem janelas.

```
BOOL m_bIsWindowless;
```

### <a name="remarks"></a>Comentários

Diferente de zero se o controle não tem nenhuma janela, caso contrário, zero.

##  <a name="m_ctlinfo"></a>  COleControlSite::m_ctlInfo

Informações sobre como a entrada do teclado é tratada pelo controle.

```
CONTROLINFO m_ctlInfo;
```

### <a name="remarks"></a>Comentários

Essas informações são armazenadas em um [CONTROLINFO](/windows/desktop/api/ocidl/ns-ocidl-tagcontrolinfo) estrutura.

##  <a name="m_dweventsink"></a>  COleControlSite::m_dwEventSink

Contém o cookie do ponto de conexão do coletor de eventos do controle.

```
DWORD m_dwEventSink;
```

##  <a name="m_dwmiscstatus"></a>  COleControlSite::m_dwMiscStatus

Contém informações diversas sobre o controle.

```
DWORD m_dwMiscStatus;
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [OLEMISC](/windows/desktop/api/oleidl/ne-oleidl-tagolemisc)no SDK do Windows.

##  <a name="m_dwpropnotifysink"></a>  COleControlSite::m_dwPropNotifySink

Contém o [IPropertyNotifySink](/windows/desktop/api/ocidl/nn-ocidl-ipropertynotifysink) cookie.

```
DWORD m_dwPropNotifySink;
```

##  <a name="m_dwstyle"></a>  COleControlSite::m_dwStyle

Contém os estilos de janela do controle.

```
DWORD m_dwStyle;
```

##  <a name="m_hwnd"></a>  COleControlSite::m_hWnd

Contém o HWND do controle, ou nulo se o controle for sem janelas.

```
HWND m_hWnd;
```

##  <a name="m_iidevents"></a>  COleControlSite::m_iidEvents

Contém a ID de interface da interface de coletor de evento do controle padrão.

```
IID m_iidEvents;
```

##  <a name="m_nid"></a>  COleControlSite::m_nID

Contém a ID de item de caixa de diálogo. do controle

```
UINT m_nID;
```

##  <a name="m_pactiveobject"></a>  COleControlSite::m_pActiveObject

Contém o [IOleInPlaceActiveObject](/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceactiveobject) interface do controle.

```
LPOLEINPLACEACTIVEOBJECT m_pActiveObject;
```

##  <a name="m_pctrlcont"></a>  COleControlSite::m_pCtrlCont

Contém o contêiner do controle (que representa o formulário).

```
COleControlContainer* m_pCtrlCont;
```

##  <a name="m_pinplaceobject"></a>  COleControlSite::m_pInPlaceObject

Contém o `IOleInPlaceObject` [IOleInPlaceObject](/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceobject) interface do controle.

```
LPOLEINPLACEOBJECT m_pInPlaceObject;
```

##  <a name="m_pobject"></a>  COleControlSite::m_pObject

Contém o `IOleObjectInterface` interface do controle.

```
LPOLEOBJECT m_pObject;
```

##  <a name="m_pwindowlessobject"></a>  COleControlSite::m_pWindowlessObject

Contém o `IOleInPlaceObjectWindowless` [IOleInPlaceObjectWindowless](/windows/desktop/api/ocidl/nn-ocidl-ioleinplaceobjectwindowless) interface do controle.

```
IOleInPlaceObjectWindowless* m_pWindowlessObject;
```

##  <a name="m_pwndctrl"></a>  COleControlSite::m_pWndCtrl

Contém um ponteiro para o `CWnd` objeto que representa o controle em si.

```
CWnd* m_pWndCtrl;
```

##  <a name="m_rect"></a>  COleControlSite::m_rect

Contém os limites do controle, relativa à janela do contêiner.

```
CRect m_rect;
```

##  <a name="modifystyle"></a>  COleControlSite::ModifyStyle

Modifica os estilos do controle.

```
virtual BOOL ModifyStyle(
    DWORD dwRemove,
    DWORD dwAdd,
    UINT nFlags);
```

### <a name="parameters"></a>Parâmetros

*dwRemove*<br/>
Os estilos a ser removido dos estilos de janela atual.

*dwAdd*<br/>
Os estilos a ser adicionado dos estilos de janela atual.

*nFlags*<br/>
Sinalizadores de posicionamento de janela. Para obter uma lista de valores possíveis, consulte o [SetWindowPos](/windows/desktop/api/winuser/nf-winuser-setwindowpos) função no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se os estilos são alteradas, caso contrário, zero.

### <a name="remarks"></a>Comentários

Propriedade Enabled de estoque do controle será modificado para corresponder à configuração para WS_DISABLED. Propriedade de estilo da borda do controle estoque será modificada para coincidir com a configuração solicitada para WS_BORDER. Todos os outros estilos são aplicados diretamente para o identificador de janela do controle, caso haja algum.

Modifica os estilos de janela do controle. Estilos a ser adicionado ou removido podem ser combinados usando o OR bit a bit ( &#124; ) operador. Consulte a [CreateWindow](/windows/desktop/api/winuser/nf-winuser-createwindowa) função no SDK do Windows para obter informações sobre os estilos de janela disponíveis.

Se *nFlags* for diferente de zero `ModifyStyle` chama a função Win32 `SetWindowPos`e redesenhar a janela combinando *nFlags* com os quatro sinalizadores a seguir:

- SWP_NOSIZE retém o tamanho atual.

- SWP_NOMOVE retém a posição atual.

- SWP_NOZORDER retém a ordem Z atual.

- SWP_NOACTIVATE não ativa a janela.

Para modificar uma janela do estilos estendidos, chame [ModifyStyleEx](#modifystyleex).

##  <a name="modifystyleex"></a>  COleControlSite::ModifyStyleEx

Modifica os estilos estendidos do controle.

```
virtual BOOL ModifyStyleEx(
    DWORD dwRemove,
    DWORD dwAdd,
    UINT nFlags);
```

### <a name="parameters"></a>Parâmetros

*dwRemove*<br/>
Os estilos estendidos a serem removidos dos estilos de janela atual.

*dwAdd*<br/>
Os estilos estendidos a serem adicionados dos estilos de janela atual.

*nFlags*<br/>
Sinalizadores de posicionamento de janela. Para obter uma lista de valores possíveis, consulte o [SetWindowPos](/windows/desktop/api/winuser/nf-winuser-setwindowpos) função no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se os estilos são alteradas, caso contrário, zero.

### <a name="remarks"></a>Comentários

Estoque do controle propriedade Appearance será modificado para corresponder à configuração para WS_EX_CLIENTEDGE. Todos os outros estilos de janela estendidos são aplicados diretamente ao identificador de janela do controle, caso haja algum.

Modifica a janela estilos do objeto de controle de site estendidos. Estilos a ser adicionado ou removido podem ser combinados usando o OR bit a bit ( &#124; ) operador. Consulte a [CreateWindowEx](/windows/desktop/api/winuser/nf-winuser-createwindowexa) função no SDK do Windows para obter informações sobre os estilos de janela disponíveis.

Se *nFlags* for diferente de zero `ModifyStyleEx` chama a função Win32 `SetWindowPos`e redesenhar a janela combinando *nFlags* com os quatro sinalizadores a seguir:

- SWP_NOSIZE retém o tamanho atual.

- SWP_NOMOVE retém a posição atual.

- SWP_NOZORDER retém a ordem Z atual.

- SWP_NOACTIVATE não ativa a janela.

Para modificar uma janela do estilos estendidos, chame [ModifyStyle](#modifystyle).

##  <a name="movewindow"></a>  COleControlSite::MoveWindow

Altera a posição do controle.

```
virtual void MoveWindow(
    int x,
    int y,
    int nWidth,
    int nHeight);
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
A nova posição do lado esquerdo da janela.

*y*<br/>
A nova posição na parte superior da janela.

*nWidth*<br/>
A nova largura da janela

*nHeight*<br/>
A nova altura da janela.

##  <a name="quickactivate"></a>  COleControlSite::QuickActivate

Rápido ativa o controle independente.

```
virtual BOOL QuickActivate();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o site do controle foi ativado, caso contrário, zero.

### <a name="remarks"></a>Comentários

Essa função deve ser chamada somente se o usuário está substituindo o processo de criação do controle.

O `IPersist*::Load` e `IPersist*::InitNew` métodos devem ser chamados após a ativação rápida. O controle deve estabelecer suas conexões com coletores do contêiner durante a ativação rápida. No entanto, essas conexões não são ativas até `IPersist*::Load` ou `IPersist*::InitNew` foi chamado.

##  <a name="safesetproperty"></a>  COleControlSite::SafeSetProperty

Define a propriedade do controle especificada pelo *dwDispID*.

```
virtual BOOL AFX_CDECL SafeSetProperty(
    DISPID dwDispID,
    VARTYPE vtProp, ...);
```

### <a name="parameters"></a>Parâmetros

*dwDispID*<br/>
Identifica a ID de expedição da propriedade ou método, encontrado na propriedade do controle `IDispatch` interface a ser definido.

*vtProp*<br/>
Especifica o tipo da propriedade a ser definido. Para os valores possíveis, consulte a seção comentários para [COleDispatchDriver::InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).

*...*<br/>
Um único parâmetro do tipo especificado pelo *vtProp*.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, zero.

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Diferentemente `SetProperty` e `SetPropertyV`, se um erro for encontrado (por exemplo, a tentativa de definir uma propriedade inexistente), nenhuma exceção é lançada.

##  <a name="setdefaultbutton"></a>  COleControlSite::SetDefaultButton

Define o controle como o botão padrão.

```
void SetDefaultButton(BOOL bDefault);
```

### <a name="parameters"></a>Parâmetros

*bNível padrão*<br/>
Diferente de zero se o controle deve se tornar o botão padrão; Caso contrário, zero.

### <a name="remarks"></a>Comentários

> [!NOTE]
>  O controle deve ter o conjunto de bits de status OLEMISC_ACTSLIKEBUTTON.

##  <a name="setdlgctrlid"></a>  COleControlSite::SetDlgCtrlID

Altera o valor do identificador de item de caixa de diálogo do controle.

```
virtual int SetDlgCtrlID(int nID);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
O novo valor de identificador.

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, a caixa de diálogo anterior item identificador da janela. Caso contrário, 0.

### <a name="remarks"></a>Comentários

##  <a name="setfocus"></a>  COleControlSite::SetFocus

Define o foco para o controle.

```
virtual CWnd* SetFocus();
virtual CWnd* SetFocus(LPMSG lpmsg);
```

### <a name="parameters"></a>Parâmetros

*lpmsg*<br/>
Um ponteiro para um [estrutura MSG](/windows/desktop/api/winuser/ns-winuser-tagmsg). Essa estrutura contém o disparo de mensagem do Windows a `SetFocus` solicitação para o controle contido no site atual do controle.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a janela que tinha o foco anteriormente.

##  <a name="setproperty"></a>  COleControlSite::SetProperty

Define a propriedade do controle especificada pelo *dwDispID*.

```
virtual void AFX_CDECL SetProperty(
    DISPID dwDispID,
    VARTYPE vtProp, ...);
```

### <a name="parameters"></a>Parâmetros

*dwDispID*<br/>
Identifica a ID de expedição da propriedade ou método, encontrado na propriedade do controle `IDispatch` interface a ser definido.

*vtProp*<br/>
Especifica o tipo da propriedade a ser definido. Para os valores possíveis, consulte a seção comentários para [COleDispatchDriver::InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).

*...*<br/>
Um único parâmetro do tipo especificado pelo *vtProp*.

### <a name="remarks"></a>Comentários

Se `SetProperty` encontrar um erro, uma exceção será lançada.

O tipo de exceção é determinado pelo valor retornado da tentativa de definir a propriedade ou método. Se o valor retornado será `DISP_E_EXCEPTION`, um `COleDispatchExcpetion` for lançada; caso contrário, um `COleException`.

##  <a name="setpropertyv"></a>  COleControlSite::SetPropertyV

Define a propriedade do controle especificada pelo *dwDispID*.

```
virtual void SetPropertyV(
    DISPID dwDispID,
    VARTYPE vtProp,
    va_list argList);
```

### <a name="parameters"></a>Parâmetros

*dwDispID*<br/>
Identifica a ID de expedição da propriedade ou método, encontrado na propriedade do controle `IDispatch` interface a ser definido.

*vtProp*<br/>
Especifica o tipo da propriedade a ser definido. Para os valores possíveis, consulte a seção comentários para [COleDispatchDriver::InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).

*argList*<br/>
Ponteiro para a lista de argumentos.

### <a name="remarks"></a>Comentários

Parâmetros extras para o método ou propriedade que está sendo invocado podem ser passeed usando o *arg_list* parâmetro. Se `SetProperty` encontrar um erro, uma exceção será lançada.

O tipo de exceção é determinado pelo valor retornado da tentativa de definir a propriedade ou método. Se o valor retornado será `DISP_E_EXCEPTION`, um `COleDispatchExcpetion` for lançada; caso contrário, um `COleException`.

##  <a name="setwindowpos"></a>  COleControlSite::SetWindowPos

Define o tamanho, posição e a ordem Z do site do controle.

```
virtual BOOL SetWindowPos(
    const CWnd* pWndInsertAfter,
    int x,
    int y,
    int cx,
    int cy,
    UINT nFlags);
```

### <a name="parameters"></a>Parâmetros

*pWndInsertAfter*<br/>
Um ponteiro para a janela.

*x*<br/>
A nova posição do lado esquerdo da janela.

*y*<br/>
A nova posição na parte superior da janela.

*CX*<br/>
A nova largura da janela

*Cy*<br/>
A nova altura da janela.

*nFlags*<br/>
Especifica a janela de dimensionamento e posicionamento sinalizadores. Para os valores possíveis, consulte a seção comentários para [SetWindowPos](/windows/desktop/api/winuser/nf-winuser-setwindowpos) no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se for bem-sucedido, caso contrário, zero.

##  <a name="setwindowtext"></a>  COleControlSite::SetWindowText

Define o texto para o site do controle.

```
virtual void SetWindowText(LPCTSTR lpszString);
```

### <a name="parameters"></a>Parâmetros

*lpszString*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo a ser usado como o novo texto de título ou controle.

### <a name="remarks"></a>Comentários

Essa função primeiro tenta definir a propriedade de estoque de legenda. Se não há suporte para a propriedade de estoque de legenda, a propriedade Text é definida em vez disso.

##  <a name="showwindow"></a>  COleControlSite::ShowWindow

Define o estado de Mostrar da janela.

```
virtual BOOL ShowWindow(int nCmdShow);
```

### <a name="parameters"></a>Parâmetros

*nCmdShow*<br/>
Especifica como o site do controle a ser mostrado. Ele deve ser um dos seguintes valores:

- SW_HIDE oculta essa janela e passa a ativação para outra janela.

- SW_MINIMIZE minimiza a janela e ativa a janela de nível superior da lista desse sistema.

- SW_RESTORE ativa e exibe a janela. Se a janela é minimizada ou maximizada, o Windows irá restaurá-lo em seu tamanho e posição originais.

- SW_SHOW ativa a janela e exibe-o em sua posição e tamanho atual.

- SW_SHOWMAXIMIZED ativa a janela e a exibe como uma janela maximizada.

- SW_SHOWMINIMIZED ativa a janela e exibe-o como um ícone.

- SW_SHOWMINNOACTIVE exibe a janela como um ícone. A janela ativa no momento permanece ativa.

- SW_SHOWNA exibe a janela em seu estado atual. A janela ativa no momento permanece ativa.

- SW_SHOWNOACTIVATE exibe a janela em seu tamanho e posição mais recentes. A janela ativa no momento permanece ativa.

- Ativa do SW_SHOWNORMAL e exibe a janela. Se a janela é minimizada ou maximizada, o Windows irá restaurá-lo em seu tamanho e posição originais.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a janela era visível anteriormente; 0 se a janela anteriormente estava oculto.

## <a name="see-also"></a>Consulte também

[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleControlContainer](../../mfc/reference/colecontrolcontainer-class.md)
