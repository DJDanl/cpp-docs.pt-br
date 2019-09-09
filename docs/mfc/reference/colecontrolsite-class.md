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
ms.openlocfilehash: 9b9b68a001acdf4b08d9cfc01cc67c43217d9a57
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69504311"
---
# <a name="colecontrolsite-class"></a>Classe COleControlSite

Fornece suporte para interfaces de controle do lado do cliente personalizadas.

## <a name="syntax"></a>Sintaxe

```
class COleControlSite : public CCmdTarget
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleControlSite::COleControlSite](#colecontrolsite)|Constrói um objeto `COleControlSite`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleControlSite::BindDefaultProperty](#binddefaultproperty)|Associa a propriedade padrão do controle hospedado a uma fonte de dados.|
|[COleControlSite::BindProperty](#bindproperty)|Associa uma propriedade do controle hospedado a uma fonte de dados.|
|[COleControlSite::CreateControl](#createcontrol)|Cria um controle ActiveX hospedado.|
|[COleControlSite::DestroyControl](#destroycontrol)|Destrói o controle hospedado.|
|[COleControlSite::DoVerb](#doverb)|Executa um verbo específico do controle hospedado.|
|[COleControlSite::EnableDSC](#enabledsc)|Habilita a fonte de dados para um site de controle.|
|[COleControlSite::EnableWindow](#enablewindow)|Habilita o site de controle.|
|[COleControlSite::FreezeEvents](#freezeevents)|Especifica se o site de controle está aceitando eventos.|
|[COleControlSite::GetDefBtnCode](#getdefbtncode)|Recupera o código do botão padrão para o controle hospedado.|
|[COleControlSite::GetDlgCtrlID](#getdlgctrlid)|Recupera o identificador do controle.|
|[COleControlSite::GetEventIID](#geteventiid)|Recupera a ID de uma interface de evento para um controle hospedado.|
|[COleControlSite::GetExStyle](#getexstyle)|Recupera os estilos estendidos do site de controle.|
|[COleControlSite::GetProperty](#getproperty)|Recupera uma propriedade específica do controle hospedado.|
|[COleControlSite::GetStyle](#getstyle)|Recupera os estilos do site de controle.|
|[COleControlSite::GetWindowText](#getwindowtext)|Recupera o texto do controle hospedado.|
|[COleControlSite::InvokeHelper](#invokehelper)|Invocar um método específico do controle hospedado.|
|[COleControlSite::InvokeHelperV](#invokehelperv)|Invoque um método específico do controle hospedado com uma lista variável de argumentos.|
|[COleControlSite::IsDefaultButton](#isdefaultbutton)|Determina se o controle é o botão padrão na janela.|
|[COleControlSite::IsWindowEnabled](#iswindowenabled)|Verifica o estado visível do site de controle.|
|[COleControlSite::ModifyStyle](#modifystyle)|Modifica os estilos estendidos atuais do site de controle.|
|[COleControlSite::ModifyStyleEx](#modifystyleex)|Modifica os estilos atuais do site de controle.|
|[COleControlSite::MoveWindow](#movewindow)|Altera a posição do site de controle.|
|[COleControlSite::QuickActivate](#quickactivate)|Ativa rapidamente o controle hospedado.|
|[COleControlSite::SafeSetProperty](#safesetproperty)|Define uma propriedade ou método do controle sem a chance de lançar uma exceção.|
|[COleControlSite::SetDefaultButton](#setdefaultbutton)|Define o botão padrão na janela.|
|[COleControlSite::SetDlgCtrlID](#setdlgctrlid)|Recupera o identificador do controle.|
|[COleControlSite::SetFocus](#setfocus)|Define o foco para o site de controle.|
|[COleControlSite::SetProperty](#setproperty)|Define uma propriedade específica do controle hospedado.|
|[COleControlSite::SetPropertyV](#setpropertyv)|Define uma propriedade específica do controle hospedado com uma lista variável de argumentos.|
|[COleControlSite::SetWindowPos](#setwindowpos)|Define a posição do site de controle.|
|[COleControlSite::SetWindowText](#setwindowtext)|Define o texto do controle hospedado.|
|[COleControlSite::ShowWindow](#showwindow)|Mostra ou oculta o site de controle.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[COleControlSite::GetControlInfo](#getcontrolinfo)|Recupera informações de teclado e mnemônicos para o controle hospedado.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleControlSite::m_bIsWindowless](#m_biswindowless)|Determina se o controle hospedado é um controle sem janela.|
|[COleControlSite::m_ctlInfo](#m_ctlinfo)|Contém informações sobre o manuseio de teclado para o controle.|
|[COleControlSite::m_dwEventSink](#m_dweventsink)|O cookie do ponto de conexão do controle.|
|[COleControlSite::m_dwMiscStatus](#m_dwmiscstatus)|Os Estados diversos para o controle hospedado.|
|[COleControlSite::m_dwPropNotifySink](#m_dwpropnotifysink)|O `IPropertyNotifySink` cookie do controle.|
|[COleControlSite::m_dwStyle](#m_dwstyle)|Os estilos do controle hospedado.|
|[COleControlSite::m_hWnd](#m_hwnd)|O identificador do site de controle.|
|[COleControlSite::m_iidEvents](#m_iidevents)|A ID da interface de evento para o controle hospedado.|
|[COleControlSite::m_nID](#m_nid)|A ID do controle hospedado.|
|[COleControlSite::m_pActiveObject](#m_pactiveobject)|Um ponteiro para o `IOleInPlaceActiveObject` objeto do controle hospedado.|
|[COleControlSite::m_pCtrlCont](#m_pctrlcont)|O contêiner do controle hospedado.|
|[COleControlSite::m_pInPlaceObject](#m_pinplaceobject)|Um ponteiro para o `IOleInPlaceObject` objeto do controle hospedado.|
|[COleControlSite::m_pObject](#m_pobject)|Um ponteiro para a `IOleObjectInterface` interface do controle.|
|[COleControlSite::m_pWindowlessObject](#m_pwindowlessobject)|Um ponteiro para a `IOleInPlaceObjectWindowless` interface do controle.|
|[COleControlSite::m_pWndCtrl](#m_pwndctrl)|Um ponteiro para o objeto de janela para o controle hospedado.|
|[COleControlSite::m_rect](#m_rect)|As dimensões do site de controle.|

## <a name="remarks"></a>Comentários

Esse suporte é o principal meio pelo qual um controle ActiveX incorporado Obtém informações sobre o local e a extensão de seu site de exibição, seu moniker, sua interface do usuário, suas propriedades de ambiente e outros recursos fornecidos por seu contêiner. `COleControlSite`implementa totalmente as interfaces [IOleControlSite](/windows/win32/api/ocidl/nn-ocidl-iolecontrolsite), [IOleInPlaceSite](/windows/win32/api/oleidl/nn-oleidl-ioleinplacesite), [IOleClientSite](/windows/win32/api/oleidl/nn-oleidl-ioleclientsite), [IPropertyNotifySink](/windows/win32/api/ocidl/nn-ocidl-ipropertynotifysink), `INotifyDBEvents` `IBoundObjectSite`,, [IRowsetNotify](../../data/oledb/irowsetnotifyimpl-class.md) . Além disso, a interface IDispatch (fornecendo suporte para propriedades de ambiente e coletores de eventos) também é implementada.

Para criar um site de controle ActiveX `COleControlSite`usando o, derive `COleControlSite`uma classe de. Na sua `CWnd`classe derivada para o contêiner (por exemplo, sua caixa de diálogo), substitua `CWnd::CreateControlSite` a função.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

`COleControlSite`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxocc. h

##  <a name="binddefaultproperty"></a>  COleControlSite::BindDefaultProperty

Associa a propriedade de associação simples padrão do objeto de chamada, conforme marcado na biblioteca de tipos, para o cursor subjacente que é definido pelas propriedades DataSource, UserName, password e SQL do controle de fonte de dados.

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
Especifica o tipo da propriedade a ser associada — por exemplo, VT_BSTR, VT_VARIANT e assim por diante.

*szFieldName*<br/>
Especifica o nome da coluna, no cursor fornecido pelo controle da fonte de dados, ao qual a propriedade será associada.

*pDSCWnd*<br/>
Um ponteiro para o `CWnd`objeto derivado que hospeda o controle do código-fonte de dados ao qual a propriedade será associada.

### <a name="remarks"></a>Comentários

O `CWnd` objeto no qual você chama essa função deve ser um controle vinculado a dados.

##  <a name="bindproperty"></a>  COleControlSite::BindProperty

Associa a propriedade vinculada simples do objeto de chamada, conforme marcado na biblioteca de tipos, para o cursor subjacente que é definido pelas propriedades DataSource, UserName, password e SQL do controle de fonte de dados.

```
virtual void BindProperty(
    DISPID dwDispId,
    CWnd* pWndDSC);
```

### <a name="parameters"></a>Parâmetros

*dwDispId*<br/>
Especifica o DISPID de uma propriedade em um controle de associação de dados que deve ser associado a um controle de fonte de dados.

*pWndDSC*<br/>
Um ponteiro para o `CWnd`objeto derivado que hospeda o controle do código-fonte de dados ao qual a propriedade será associada.

### <a name="remarks"></a>Comentários

O `CWnd` objeto no qual você chama essa função deve ser um controle vinculado a dados.

##  <a name="colecontrolsite"></a>  COleControlSite::COleControlSite

Constrói um novo objeto `COleControlSite`.

```
explicit COleControlSite(COleControlContainer* pCtrlCont);
```

### <a name="parameters"></a>Parâmetros

*pCtrlCont*<br/>
Um ponteiro para o contêiner do controle (que representa a janela que hospeda o controle AtiveX).

### <a name="remarks"></a>Comentários

Essa função é chamada pela função [COccManager:: CreateContainer](../../mfc/reference/coccmanager-class.md#createcontainer) . Para obter mais informações sobre como personalizar a criação de contêineres, consulte [COccManager::](../../mfc/reference/coccmanager-class.md#createsite).

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
Um ponteiro para o objeto de janela que representa o controle.

*clsid*<br/>
A ID de classe exclusiva do controle.

*lpszWindowName*<br/>
Um ponteiro para o texto a ser exibido no controle. Define o valor da legenda ou da propriedade de texto do winodw (se houver).

*dwStyle*<br/>
Estilos do Windows. Os estilos disponíveis são listados na seção **comentários** .

*rect*<br/>
Especifica o tamanho e a posição do controle. Pode ser um `CRect` objeto ou uma `RECT` estrutura.

*nID*<br/>
Especifica a ID da janela filho do controle.

*pPersist*<br/>
Um ponteiro para um `CFile` que contém o estado persistente do controle. O valor padrão é NULL, indicando que o controle inicializa a si mesmo sem restaurar seu estado a partir de qualquer armazenamento persistente. Se não for NULL, deve ser um ponteiro para um `CFile`objeto derivado que contém os dados persistentes do controle, na forma de um fluxo ou um armazenamento. Esses dados podem ter sido salvos em uma ativação anterior do cliente. O `CFile` pode conter outros dados, mas deve ter seu ponteiro de leitura/gravação definido como o primeiro byte de dados persistentes no momento da chamada para `CreateControl`.

*bStorage*<br/>
Indica se os dados em *pPersist* devem ser interpretados `IStream` como `IStorage` ou dados. Se os dados no *pPersist* forem um armazenamento, *BSTORAGE* deverá ser verdadeiro. Se os dados em *pPersist* forem um fluxo, *BSTORAGE* deverá ser false. O valor padrão é FALSE.

*bstrLicKey*<br/>
Dados de chave de licença opcionais. Esses dados são necessários apenas para a criação de controles que exigem uma chave de licença em tempo de execução. Se o controle oferecer suporte a licenciamento, você deverá fornecer uma chave de licença para que a criação do controle seja realizada com sucesso. O valor padrão é NULL.

*ppt*<br/>
Um ponteiro para uma `POINT` estrutura que contém o canto superior esquerdo do controle. O tamanho do controle é determinado pelo valor de *psize*. Os valores de *ppt* e *psize* são um método opcional para especificar o tamanho e a posição destas o controle.

*psize*<br/>
Um ponteiro para uma `SIZE` estrutura que contém o tamanho do controle. O canto superior esquerdo é determinado pelo valor de *ppt*. Os valores de *ppt* e *psize* são um método opcional para especificar o tamanho e a posição destas o controle.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Somente um subconjunto dos sinalizadores *dwStyle* do Windows tem suporte `CreateControl`no:

- WS_VISIBLE cria uma janela que inicialmente é visível. Necessário se você quiser que o controle seja visível imediatamente, como janelas comuns.

- WS_DISABLED Cria uma janela que está inicialmente desabilitada. Uma janela desabilitada não pode receber entrada do usuário. Pode ser definido se o controle tiver uma propriedade habilitada.

- WS_BORDER cria uma janela com uma borda de linha fina. Pode ser definido se o controle tiver uma propriedade BorderStyle.

- WS_GROUP especifica o primeiro controle de um grupo de controles. O usuário pode alterar o foco do teclado de um controle no grupo para o próximo usando as teclas de direção. Todos os controles definidos com o estilo WS_GROUP após o primeiro controle pertencem ao mesmo grupo. O próximo controle com o estilo WS_GROUP encerra o grupo e inicia o próximo grupo.

- WS_TABSTOP especifica um controle que pode receber o foco do teclado quando o usuário pressiona a tecla TAB. Pressionar a tecla TAB altera o foco do teclado para o próximo controle do estilo WS_TABSTOP.

Use a segunda sobrecarga para criar controles de tamanho padrão.

##  <a name="destroycontrol"></a>  COleControlSite::DestroyControl

Destrói o `COleControlSite` objeto.

```
virtual BOOL DestroyControl();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido, caso contrário 0.

### <a name="remarks"></a>Comentários

Depois de concluído, o objeto é liberado da memória e os ponteiros para o objeto não são mais válidos.

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
|-4|Ativa um controle in-loco.|OLEIVERB_UIACTIVATE|
|-5|Ativa um controle in-loco, sem elementos de interface do usuário adicionais.|OLEIVERB_INPLACEACTIVATE|
|-7|Exibir as propriedades do controle.|OLEIVERB_PROPERTIES|

*lpMsg*<br/>
Ponteiro para a mensagem que causou a ativação do item.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Essa função chama diretamente a interface do `IOleObject` controle para executar o verbo especificado. Se uma exceção for gerada como resultado dessa chamada de função, um código de erro HRESULT será retornado.

Para obter mais informações, consulte [IOleObject::D overb](/windows/win32/api/oleidl/nf-oleidl-ioleobject-doverb) no SDK do Windows.

##  <a name="enabledsc"></a>  COleControlSite::EnableDSC

Habilita a fonte de dados para o site de controle.

```
virtual void EnableDSC();
```

### <a name="remarks"></a>Comentários

Chamado pelo Framework para habilitar e inicializar a fonte de dados para o site de controle. Substitua essa função para fornecer um comportamento personalizado.

##  <a name="enablewindow"></a>  COleControlSite::EnableWindow

Habilita ou desabilita a entrada do mouse e do teclado para o site de controle.

```
virtual BOOL EnableWindow(BOOL bEnable);
```

### <a name="parameters"></a>Parâmetros

*bEnable*<br/>
Especifica se a janela deve ser habilitada ou desabilitada: TRUE se a entrada da janela for ser habilitada; caso contrário, FALSE.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a janela foi desabilitada anteriormente, caso contrário, 0.

##  <a name="freezeevents"></a>  COleControlSite::FreezeEvents

Especifica se o site de controle manipulará ou ignorará eventos acionados de um controle.

```
void FreezeEvents(BOOL bFreeze);
```

### <a name="parameters"></a>Parâmetros

*bFreeze*<br/>
Especifica se o site de controle deseja parar de aceitar eventos. Diferente de zero se o controle não estiver aceitando eventos; caso contrário, zero.

### <a name="remarks"></a>Comentários

Se *bFreeze* for true, o site de controle solicitará que o controle interrompa os eventos de borda. Se *bFreeze* for false, o site de controle solicitará que o controle continue acionando eventos.

> [!NOTE]
>  O controle não é necessário para parar de acionar eventos, se solicitado pelo site de controle. Ele pode continuar acionando, mas todos os eventos subsequentes serão ignorados pelo site de controle.

##  <a name="getcontrolinfo"></a>  COleControlSite::GetControlInfo

Recupera informações sobre os mnemônicos de teclado e o comportamento de teclado de um controle.

```
void GetControlInfo();
```

### <a name="remarks"></a>Comentários

As informações são armazenadas em [COleControlSite:: m_ctlInfo](#m_ctlinfo).

##  <a name="getdefbtncode"></a>  COleControlSite::GetDefBtnCode

Determina se o controle é um botão de ação padrão.

```
DWORD GetDefBtnCode();
```

### <a name="return-value"></a>Valor de retorno

Pode ser um dos seguintes valores:

- O controle DLGC_DEFPUSHBUTTON é o botão padrão na caixa de diálogo.

- O controle DLGC_UNDEFPUSHBUTTON não é o botão padrão na caixa de diálogo.

- o controle **0** não é um botão.

##  <a name="getdlgctrlid"></a>  COleControlSite::GetDlgCtrlID

Recupera o identificador do controle.

```
virtual int GetDlgCtrlID() const;
```

### <a name="return-value"></a>Valor de retorno

O identificador do item de caixa de diálogo do controle.

##  <a name="geteventiid"></a>  COleControlSite::GetEventIID

Recupera um ponteiro para a interface de evento do controle padrão.

```
BOOL GetEventIID(IID* piid);
```

### <a name="parameters"></a>Parâmetros

*piid*<br/>
Um ponteiro para uma ID de interface.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido, caso contrário 0. Se for bem-sucedido, *piid* conterá a ID da interface para a interface de evento padrão do controle.

##  <a name="getexstyle"></a>  COleControlSite::GetExStyle

Recupera os estilos estendidos da janela.

```
virtual DWORD GetExStyle() const;
```

### <a name="return-value"></a>Valor de retorno

Os estilos estendidos da janela de controle.

### <a name="remarks"></a>Comentários

Para recuperar os estilos regulares, chame [COleControlSite:: GetStyle](#getstyle).

##  <a name="getproperty"></a>  COleControlSite::GetProperty

Obtém a propriedade de controle especificada por *dwDispID*.

```
virtual void GetProperty(
    DISPID dwDispID,
    VARTYPE vtProp,
    void* pvProp) const;
```

### <a name="parameters"></a>Parâmetros

*dwDispID*<br/>
Identifica a ID de expedição da propriedade, encontrada na interface padrão `IDispatch` do controle, a ser recuperada.

*vtProp*<br/>
Especifica o tipo da propriedade a ser recuperada. Para obter os valores possíveis, consulte a seção comentários para [COleDispatchDriver:: especificados InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).

*pvProp*<br/>
Endereço da variável que receberá o valor da propriedade. Ele deve corresponder ao tipo especificado por *vtProp*.

### <a name="remarks"></a>Comentários

O valor é retornado por meio de *pvProp*.

##  <a name="getstyle"></a>  COleControlSite::GetStyle

Recupera os estilos do site de controle.

```
virtual DWORD GetStyle() const;
```

### <a name="return-value"></a>Valor de retorno

Os estilos da janela.

### <a name="remarks"></a>Comentários

Para obter uma lista de valores possíveis, consulte [Windows Styles](../../mfc/reference/styles-used-by-mfc.md#window-styles). Para recuperar os estilos estendidos do site de controle, chame [COleControlSite:: GetExStyle](#getexstyle).

##  <a name="getwindowtext"></a>  COleControlSite::GetWindowText

Recupera o texto atual do controle.

```
virtual void GetWindowText(CString& str) const;
```

### <a name="parameters"></a>Parâmetros

*str*<br/>
Uma referência a um `CString` objeto que contém o texto atual do controle.

### <a name="remarks"></a>Comentários

Se o controle oferecer suporte à propriedade de ação de legenda, esse valor será retornado. Se a propriedade de ação de legenda não for suportada, o valor da propriedade Text será retornado.

##  <a name="invokehelper"></a>  COleControlSite::InvokeHelper

Invoca o método ou a propriedade especificada por *dwDispID*, no contexto especificado por *wFlags*.

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
Identifica a ID de expedição da propriedade ou do método, encontrado na interface do `IDispatch` controle, a ser invocado.

*wFlags*<br/>
Sinalizadores que descrevem o contexto da chamada para IDispatch:: Invoke. Para obter possíveis valores de wFlags `IDispatch::Invoke` , consulte na SDK do Windows.

*vtRet*<br/>
Especifica o tipo do valor de retorno. Para obter os valores possíveis, consulte a seção comentários para [COleDispatchDriver:: especificados InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).

*pvRet*<br/>
Endereço da variável que receberá o valor da propriedade ou o valor de retorno. Ele deve corresponder ao tipo especificado por *vtRet*.

*pbParamInfo*<br/>
Ponteiro para uma cadeia de caracteres de bytes terminada em nulo especificando os tipos dos parâmetros após *pbParamInfo*. Para obter os valores possíveis, consulte a seção comentários para [COleDispatchDriver:: especificados InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).

*...*<br/>
Lista variável de parâmetros, dos tipos especificados em *pbParamInfo*.

### <a name="remarks"></a>Comentários

O parâmetro *pbParamInfo* especifica os tipos dos parâmetros passados para o método ou a propriedade. A lista variável de argumentos é representada por... na declaração de sintaxe.

Essa função converte os parâmetros em valores VARIANTARG e, em seguida, `IDispatch::Invoke` invoca o método no controle. Se a chamada para `IDispatch::Invoke` falhar, essa função gerará uma exceção. Se o código de status retornado `IDispatch::Invoke` por `DISP_E_EXCEPTION`for, essa função lançará um `COleDispatchException` objeto, caso contrário `COleException`, ele lançará um.

##  <a name="invokehelperv"></a>  COleControlSite::InvokeHelperV

Invoca o método ou a propriedade especificada por *dwDispID*, no contexto especificado por *wFlags*.

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
Identifica a ID de expedição da propriedade ou do método, encontrado na interface do `IDispatch` controle, a ser invocado.

*wFlags*<br/>
Sinalizadores que descrevem o contexto da chamada para IDispatch:: Invoke.

*vtRet*<br/>
Especifica o tipo do valor de retorno. Para obter os valores possíveis, consulte a seção comentários para [COleDispatchDriver:: especificados InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).

*pvRet*<br/>
Endereço da variável que receberá o valor da propriedade ou o valor de retorno. Ele deve corresponder ao tipo especificado por *vtRet*.

*pbParamInfo*<br/>
Ponteiro para uma cadeia de caracteres de bytes terminada em nulo especificando os tipos dos parâmetros após *pbParamInfo*. Para obter os valores possíveis, consulte a seção comentários para [COleDispatchDriver:: especificados InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).

*argList*<br/>
Ponteiro para uma lista de argumentos variáveis.

### <a name="remarks"></a>Comentários

O parâmetro *pbParamInfo* especifica os tipos dos parâmetros passados para o método ou a propriedade. Parâmetros adicionais para o método ou a propriedade que está sendo invocada podem ser passados usando o parâmetro *va_list* .

Normalmente, essa função é chamada por `COleControlSite::InvokeHelper`.

##  <a name="isdefaultbutton"></a>  COleControlSite::IsDefaultButton

Determina se o controle é o botão padrão.

```
BOOL IsDefaultButton();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o controle for o botão padrão na janela, caso contrário, zero.

##  <a name="iswindowenabled"></a>  COleControlSite::IsWindowEnabled

Determina se o site de controle está habilitado.

```
virtual BOOL IsWindowEnabled() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o controle estiver habilitado, caso contrário, zero.

### <a name="remarks"></a>Comentários

O valor é recuperado da propriedade Stock habilitada do controle.

##  <a name="m_biswindowless"></a>  COleControlSite::m_bIsWindowless

Determina se o objeto é um controle sem janela.

```
BOOL m_bIsWindowless;
```

### <a name="remarks"></a>Comentários

Diferente de zero se o controle não tiver nenhuma janela, caso contrário, zero.

##  <a name="m_ctlinfo"></a>  COleControlSite::m_ctlInfo

Informações sobre como a entrada do teclado é manipulada pelo controle.

```
CONTROLINFO m_ctlInfo;
```

### <a name="remarks"></a>Comentários

Essas informações são armazenadas em uma estrutura [CONTROLINFO](/windows/win32/api/ocidl/ns-ocidl-controlinfo) .

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

Para obter mais informações, consulte [OLEMISC](/windows/win32/api/oleidl/ne-oleidl-olemisc)no SDK do Windows.

##  <a name="m_dwpropnotifysink"></a>  COleControlSite::m_dwPropNotifySink

Contém o cookie [IPropertyNotifySink](/windows/win32/api/ocidl/nn-ocidl-ipropertynotifysink) .

```
DWORD m_dwPropNotifySink;
```

##  <a name="m_dwstyle"></a>  COleControlSite::m_dwStyle

Contém os estilos de janela do controle.

```
DWORD m_dwStyle;
```

##  <a name="m_hwnd"></a>  COleControlSite::m_hWnd

Contém o HWND do controle, ou NULL se o controle não tiver janela.

```
HWND m_hWnd;
```

##  <a name="m_iidevents"></a>  COleControlSite::m_iidEvents

Contém a ID da interface da interface do coletor de eventos padrão do controle.

```
IID m_iidEvents;
```

##  <a name="m_nid"></a>  COleControlSite::m_nID

Contém a ID do item de diálogo do controle.

```
UINT m_nID;
```

##  <a name="m_pactiveobject"></a>  COleControlSite::m_pActiveObject

Contém a interface [IOleInPlaceActiveObject](/windows/win32/api/oleidl/nn-oleidl-ioleinplaceactiveobject) do controle.

```
LPOLEINPLACEACTIVEOBJECT m_pActiveObject;
```

##  <a name="m_pctrlcont"></a>  COleControlSite::m_pCtrlCont

Contém o contêiner do controle (representando o formulário).

```
COleControlContainer* m_pCtrlCont;
```

##  <a name="m_pinplaceobject"></a>  COleControlSite::m_pInPlaceObject

Contém a `IOleInPlaceObject` interface [IOleInPlaceObject](/windows/win32/api/oleidl/nn-oleidl-ioleinplaceobject) do controle.

```
LPOLEINPLACEOBJECT m_pInPlaceObject;
```

##  <a name="m_pobject"></a>  COleControlSite::m_pObject

Contém a `IOleObjectInterface` interface do controle.

```
LPOLEOBJECT m_pObject;
```

##  <a name="m_pwindowlessobject"></a>  COleControlSite::m_pWindowlessObject

Contém a `IOleInPlaceObjectWindowless`interface [IOleInPlaceObjectWindowless](/windows/win32/api/ocidl/nn-ocidl-ioleinplaceobjectwindowless) do controle.

```
IOleInPlaceObjectWindowless* m_pWindowlessObject;
```

##  <a name="m_pwndctrl"></a>  COleControlSite::m_pWndCtrl

Contém um ponteiro para o `CWnd` objeto que representa o próprio controle.

```
CWnd* m_pWndCtrl;
```

##  <a name="m_rect"></a>  COleControlSite::m_rect

Contém os limites do controle, em relação à janela do contêiner.

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
Os estilos a serem removidos dos estilos de janela atuais.

*dwAdd*<br/>
Os estilos a serem adicionados dos estilos de janela atuais.

*nFlags*<br/>
Sinalizadores de posicionamento da janela. Para obter uma lista de valores possíveis, consulte a função [SetWindowPos](/windows/win32/api/winuser/nf-winuser-setwindowpos) no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se os estilos forem alterados, caso contrário, zero.

### <a name="remarks"></a>Comentários

A propriedade habilitada para estoque do controle será modificada para corresponder à configuração de WS_DISABLED. A propriedade de estilo de borda de estoque do controle será modificada para corresponder à configuração solicitada para WS_BORDER. Todos os outros estilos são aplicados diretamente ao identificador de janela do controle, se houver um.

Modifica os estilos de janela do controle. Os estilos a serem adicionados ou removidos podem ser combinados usando-se o operador &#124; or (). Consulte a função [CreateWindow](/windows/win32/api/winuser/nf-winuser-createwindoww) no SDK do Windows para obter informações sobre os estilos de janela disponíveis.

Se *nFlags* for diferente de `ModifyStyle` zero, chamará `SetWindowPos`a função do Win32 e redesenhará a janela combinando *nFlags* com os quatro sinalizadores a seguir:

- SWP_NOSIZE Retém o tamanho atual.

- SWP_NOMOVE Mantém a posição atual.

- SWP_NOZORDER retém a ordem Z atual.

- O SWP_NOACTIVATE Não ativa a janela.

Para modificar os estilos estendidos de uma janela, chame [ModifyStyleEx](#modifystyleex).

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
Os estilos estendidos a serem removidos dos estilos de janela atuais.

*dwAdd*<br/>
Os estilos estendidos a serem adicionados dos estilos de janela atuais.

*nFlags*<br/>
Sinalizadores de posicionamento da janela. Para obter uma lista de valores possíveis, consulte a função [SetWindowPos](/windows/win32/api/winuser/nf-winuser-setwindowpos) no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se os estilos forem alterados, caso contrário, zero.

### <a name="remarks"></a>Comentários

A propriedade de aparência de estoque do controle será modificada para corresponder à configuração de WS_EX_CLIENTEDGE. Todos os outros estilos de janela estendidos são aplicados diretamente ao identificador de janela do controle, se houver um.

Modifica os estilos estendidos da janela do objeto do site de controle. Os estilos a serem adicionados ou removidos podem ser combinados usando-se o operador &#124; or (). Consulte a função [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) na SDK do Windows para obter informações sobre os estilos de janela disponíveis.

Se *nFlags* for diferente de `ModifyStyleEx` zero, chamará `SetWindowPos`a função do Win32 e redesenhará a janela combinando *nFlags* com os quatro sinalizadores a seguir:

- SWP_NOSIZE Retém o tamanho atual.

- SWP_NOMOVE Mantém a posição atual.

- SWP_NOZORDER retém a ordem Z atual.

- O SWP_NOACTIVATE Não ativa a janela.

Para modificar os estilos estendidos de uma janela, chame [ModifyStyle](#modifystyle).

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
A nova posição da parte superior da janela.

*nWidth*<br/>
A nova largura da janela

*nHeight*<br/>
A nova altura da janela.

##  <a name="quickactivate"></a>  COleControlSite::QuickActivate

Ativa rapidamente o controle contido.

```
virtual BOOL QuickActivate();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o site de controle foi ativado, caso contrário zero.

### <a name="remarks"></a>Comentários

Essa função deve ser chamada somente se o usuário estiver substituindo o processo de criação do controle.

Os `IPersist*::Load` métodos `IPersist*::InitNew` e devem ser chamados depois que a ativação rápida ocorrer. O controle deve estabelecer suas conexões com os coletores do contêiner durante a ativação rápida. No entanto, essas conexões não são `IPersist*::Load` dinâmicas até ou `IPersist*::InitNew` foram chamadas.

##  <a name="safesetproperty"></a>  COleControlSite::SafeSetProperty

Define a propriedade de controle especificada por *dwDispID*.

```
virtual BOOL AFX_CDECL SafeSetProperty(
    DISPID dwDispID,
    VARTYPE vtProp, ...);
```

### <a name="parameters"></a>Parâmetros

*dwDispID*<br/>
Identifica a ID de expedição da propriedade ou do método, encontrado na interface do `IDispatch` controle, a ser definido.

*vtProp*<br/>
Especifica o tipo de propriedade a ser definida. Para obter os valores possíveis, consulte a seção comentários para [COleDispatchDriver:: especificados InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).

*...*<br/>
Um único parâmetro do tipo especificado por *vtProp*.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Ao `SetProperty` contrário `SetPropertyV`de e, se um erro for encontrado (como tentar definir uma propriedade inexistente), nenhuma exceção será lançada.

##  <a name="setdefaultbutton"></a>  COleControlSite::SetDefaultButton

Define o controle como o botão padrão.

```
void SetDefaultButton(BOOL bDefault);
```

### <a name="parameters"></a>Parâmetros

*bDefault*<br/>
Diferente de zero se o controle deve se tornar o botão padrão; caso contrário, zero.

### <a name="remarks"></a>Comentários

> [!NOTE]
>  O controle deve ter o bit de status OLEMISC_ACTSLIKEBUTTON definido.

##  <a name="setdlgctrlid"></a>  COleControlSite::SetDlgCtrlID

Altera o valor do identificador de item de caixa de diálogo do controle.

```
virtual int SetDlgCtrlID(int nID);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
O novo valor do identificador.

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, o identificador de item de caixa de diálogo anterior da janela; caso contrário, 0.

### <a name="remarks"></a>Comentários

##  <a name="setfocus"></a>  COleControlSite::SetFocus

Define o foco para o controle.

```
virtual CWnd* SetFocus();
virtual CWnd* SetFocus(LPMSG lpmsg);
```

### <a name="parameters"></a>Parâmetros

*lpmsg*<br/>
Um ponteiro para uma [estrutura de MSG](/windows/win32/api/winuser/ns-winuser-msg). Essa estrutura contém a mensagem do Windows que dispara `SetFocus` a solicitação para o controle contido no site de controle atual.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a janela que anteriormente tinha o foco.

##  <a name="setproperty"></a>  COleControlSite::SetProperty

Define a propriedade de controle especificada por *dwDispID*.

```
virtual void AFX_CDECL SetProperty(
    DISPID dwDispID,
    VARTYPE vtProp, ...);
```

### <a name="parameters"></a>Parâmetros

*dwDispID*<br/>
Identifica a ID de expedição da propriedade ou do método, encontrado na interface do `IDispatch` controle, a ser definido.

*vtProp*<br/>
Especifica o tipo de propriedade a ser definida. Para obter os valores possíveis, consulte a seção comentários para [COleDispatchDriver:: especificados InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).

*...*<br/>
Um único parâmetro do tipo especificado por *vtProp*.

### <a name="remarks"></a>Comentários

Se `SetProperty` o encontrar um erro, uma exceção será lançada.

O tipo de exceção é determinado pelo valor de retorno da tentativa de definir a propriedade ou o método. Se o valor de retorno `DISP_E_EXCEPTION`for, `COleDispatchExcpetion` um será lançado; caso `COleException`contrário, um.

##  <a name="setpropertyv"></a>  COleControlSite::SetPropertyV

Define a propriedade de controle especificada por *dwDispID*.

```
virtual void SetPropertyV(
    DISPID dwDispID,
    VARTYPE vtProp,
    va_list argList);
```

### <a name="parameters"></a>Parâmetros

*dwDispID*<br/>
Identifica a ID de expedição da propriedade ou do método, encontrado na interface do `IDispatch` controle, a ser definido.

*vtProp*<br/>
Especifica o tipo de propriedade a ser definida. Para obter os valores possíveis, consulte a seção comentários para [COleDispatchDriver:: especificados InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).

*argList*<br/>
Ponteiro para a lista de argumentos.

### <a name="remarks"></a>Comentários

Parâmetros adicionais para o método ou a propriedade que está sendo invocada podem ser passeed usando o parâmetro *arg_list* . Se `SetProperty` o encontrar um erro, uma exceção será lançada.

O tipo de exceção é determinado pelo valor de retorno da tentativa de definir a propriedade ou o método. Se o valor de retorno `DISP_E_EXCEPTION`for, `COleDispatchExcpetion` um será lançado; caso `COleException`contrário, um.

##  <a name="setwindowpos"></a>  COleControlSite::SetWindowPos

Define o tamanho, a posição e a ordem Z do site de controle.

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
A nova posição da parte superior da janela.

*cx*<br/>
A nova largura da janela

*cy*<br/>
A nova altura da janela.

*nFlags*<br/>
Especifica os sinalizadores de dimensionamento e de posicionamento da janela. Para obter os valores possíveis, consulte a seção comentários para [SetWindowPos](/windows/win32/api/winuser/nf-winuser-setwindowpos) no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, caso contrário, zero.

##  <a name="setwindowtext"></a>  COleControlSite::SetWindowText

Define o texto para o site de controle.

```
virtual void SetWindowText(LPCTSTR lpszString);
```

### <a name="parameters"></a>Parâmetros

*lpszString*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo a ser usada como o novo título ou texto de controle.

### <a name="remarks"></a>Comentários

Essa função tenta primeiro definir a propriedade de ação legenda. Se a propriedade de ação de legenda não for suportada, a propriedade Text será definida em seu lugar.

##  <a name="showwindow"></a>  COleControlSite::ShowWindow

Define o estado de exibição da janela.

```
virtual BOOL ShowWindow(int nCmdShow);
```

### <a name="parameters"></a>Parâmetros

*nCmdShow*<br/>
Especifica como o site de controle deve ser mostrado. Deve ser um dos seguintes valores:

- SW_HIDE oculta essa janela e passa a ativação para outra janela.

- SW_MINIMIZE minimiza a janela e ativa a janela de nível superior na lista do sistema.

- SW_RESTORE Ativa e exibe a janela. Se a janela for minimizada ou maximizada, o Windows a restaurará para seu tamanho e posição originais.

- SW_SHOW ativa a janela e a exibe em seu tamanho e posição atuais.

- SW_SHOWMAXIMIZED ativa a janela e a exibe como uma janela maximizada.

- SW_SHOWMINIMIZED Ativa a janela e a exibe como um ícone.

- SW_SHOWMINNOACTIVE exibe a janela como um ícone. A janela ativa no momento permanece ativa.

- SW_SHOWNA exibe a janela em seu estado atual. A janela ativa no momento permanece ativa.

- SW_SHOWNOACTIVATE Exibe a janela em seu tamanho e posição mais recentes. A janela ativa no momento permanece ativa.

- SW_SHOWNORMAL ativa e exibe a janela. Se a janela for minimizada ou maximizada, o Windows a restaurará para seu tamanho e posição originais.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a janela estava visível anteriormente; 0 se a janela tiver sido ocultada anteriormente.

## <a name="see-also"></a>Consulte também

[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleControlContainer](../../mfc/reference/colecontrolcontainer-class.md)
