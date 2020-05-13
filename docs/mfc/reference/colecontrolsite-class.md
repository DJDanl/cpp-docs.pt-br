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
ms.openlocfilehash: 90c41a1be1a66cdceebb3f045a98167e56b7cf4c
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753951"
---
# <a name="colecontrolsite-class"></a>Classe COleControlSite

Fornece suporte para interfaces de controle personalizadas do lado do cliente.

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
|[COleControlSite::BindDefaultProperty](#binddefaultproperty)|Vincula a propriedade padrão do controle hospedado a uma fonte de dados.|
|[COleControlSite::BindProperty](#bindproperty)|Vincula uma propriedade do controle hospedado a uma fonte de dados.|
|[COleControlSite::CreateControl](#createcontrol)|Cria um controle ActiveX hospedado.|
|[COleControlSite::DestroyControl](#destroycontrol)|Destrói o controle hospedado.|
|[COleControlSite::DoVerb](#doverb)|Executa um verbo específico do controle hospedado.|
|[COleControlSite::EnableDSC](#enabledsc)|Permite o fornecimento de dados para um local de controle.|
|[COleControlSite::Ativarjanela](#enablewindow)|Habilita o local de controle.|
|[COleControlSite::FreezeEvents](#freezeevents)|Especifica se o site de controle está aceitando eventos.|
|[COleControlSite::GetDefBtnCode](#getdefbtncode)|Recupera o código de botão padrão para o controle hospedado.|
|[COleControlSite::GetDlgCtrlID](#getdlgctrlid)|Recupera o identificador do controle.|
|[COleControlSite::GetEventIID](#geteventiid)|Recupera o ID de uma interface de evento para um controle hospedado.|
|[COleControlSite::GetExStyle](#getexstyle)|Recupera os estilos estendidos do local de controle.|
|[COleControlSite::GetProperty](#getproperty)|Recupera uma propriedade específica do controle hospedado.|
|[COleControlSite::GetStyle](#getstyle)|Recupera os estilos do local de controle.|
|[COleControlSite::GetWindowText](#getwindowtext)|Recupera o texto do controle hospedado.|
|[COleControlSite::InvokeHelper](#invokehelper)|Invoque um método específico do controle hospedado.|
|[COleControlSite::InvokeHelperV](#invokehelperv)|Invoque um método específico do controle hospedado com uma lista variável de argumentos.|
|[COleControlSite::IsDefaultButton](#isdefaultbutton)|Determina se o controle é o botão padrão na janela.|
|[COleControlSite::IsWindowEnabled](#iswindowenabled)|Verifica o estado visível do local de controle.|
|[COleControlSite::ModifyStyle](#modifystyle)|Modifica os estilos estendidos atuais do local de controle.|
|[COleControlSite::ModifyStyleEx](#modifystyleex)|Modifica os estilos atuais do local de controle.|
|[COleControlSite::MoveWindow](#movewindow)|Muda a posição do local de controle.|
|[COleControlSite::QuickActivate](#quickactivate)|Ativa rapidamente o controle hospedado.|
|[COleControlSite::SafeSetProperty](#safesetproperty)|Define uma propriedade ou método do controle sem chance de abrir uma exceção.|
|[COleControlSite::SetDefaultButton](#setdefaultbutton)|Define o botão padrão na janela.|
|[COleControlSite::SetDlgCtrlID](#setdlgctrlid)|Recupera o identificador do controle.|
|[COleControlSite::SetFocus](#setfocus)|Define o foco para o local de controle.|
|[COleControlSite::SetProperty](#setproperty)|Define uma propriedade específica do controle hospedado.|
|[COleControlSite::SetPropertyV](#setpropertyv)|Define uma propriedade específica do controle hospedado com uma lista variável de argumentos.|
|[COleControlSite::SetWindowPos](#setwindowpos)|Define a posição do local de controle.|
|[COleControlSite::SetWindowText](#setwindowtext)|Define o texto do controle hospedado.|
|[COleControlSite::ShowWindow](#showwindow)|Mostra ou esconde o local de controle.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[COleControlSite::GetControlInfo](#getcontrolinfo)|Recupera informações do teclado e mnemônicos para o controle hospedado.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleControlSite::m_bIsWindowless](#m_biswindowless)|Determina se o controle hospedado é um controle sem janelas.|
|[COleControlSite::m_ctlInfo](#m_ctlinfo)|Contém informações sobre o manuseio do teclado para o controle.|
|[COleControlSite::m_dwEventSink](#m_dweventsink)|O cookie do ponto de conexão do controle.|
|[COleControlSite::m_dwMiscStatus](#m_dwmiscstatus)|Os estados diversos para o controle hospedado.|
|[COleControlSite::m_dwPropNotifySink](#m_dwpropnotifysink)|O `IPropertyNotifySink` biscoito do controle.|
|[COleControlSite::m_dwStyle](#m_dwstyle)|Os estilos do controle hospedado.|
|[COleControlSite::m_hWnd](#m_hwnd)|A alça do local de controle.|
|[COleControlSite::m_iidEvents](#m_iidevents)|O ID da interface de evento para o controle hospedado.|
|[COleControlSite::m_nID](#m_nid)|A id do controle hospedado.|
|[COleControlSite::m_pActiveObject](#m_pactiveobject)|Um ponteiro `IOleInPlaceActiveObject` para o objeto do controle hospedado.|
|[COleControlSite::m_pCtrlCont](#m_pctrlcont)|O contêiner do controle hospedado.|
|[COleControlSite::m_pInPlaceObject](#m_pinplaceobject)|Um ponteiro `IOleInPlaceObject` para o objeto do controle hospedado.|
|[COleControlSite::m_pObject](#m_pobject)|Um ponteiro `IOleObjectInterface` para a interface do controle.|
|[COleControlSite::m_pWindowlessObject](#m_pwindowlessobject)|Um ponteiro `IOleInPlaceObjectWindowless` para a interface do controle.|
|[COleControlSite::m_pWndCtrl](#m_pwndctrl)|Um ponteiro para o objeto da janela para o controle hospedado.|
|[COleControlSite::m_rect](#m_rect)|As dimensões do local de controle.|

## <a name="remarks"></a>Comentários

Esse suporte é o principal meio pelo qual um controle ActiveX incorporado obtém informações sobre a localização e extensão de seu site de exibição, seu apelido, sua interface de usuário, suas propriedades ambientais e outros recursos fornecidos por seu contêiner. `COleControlSite`implementa totalmente as interfaces [IOleControlSite,](/windows/win32/api/ocidl/nn-ocidl-iolecontrolsite) [IOleInPlaceSite,](/windows/win32/api/oleidl/nn-oleidl-ioleinplacesite) [IOleClientSite,](/windows/win32/api/oleidl/nn-oleidl-ioleclientsite) [IPropertyNotifySink](/windows/win32/api/ocidl/nn-ocidl-ipropertynotifysink), `IBoundObjectSite`, `INotifyDBEvents`, [IRowSetNotify](../../data/oledb/irowsetnotifyimpl-class.md) interfaces. Além disso, a interface IDispatch (que fornece suporte para propriedades ambientais e sumidouros de eventos) também é implementada.

Para criar um site `COleControlSite`de controle ActiveX usando , obtenha uma classe de `COleControlSite`. Em `CWnd`sua classe derivada para o contêiner (por exemplo, `CWnd::CreateControlSite` sua caixa de diálogo) sobreponha a função.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

`COleControlSite`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxocc.h

## <a name="colecontrolsitebinddefaultproperty"></a><a name="binddefaultproperty"></a>COleControlSite::BindDefaultProperty

Vincula a propriedade padrão do objeto de chamada, conforme marcado na biblioteca do tipo, ao cursor subjacente definido pelas propriedades DataSource, UserName, Password e SQL do controle de origem de dados.

```
virtual void BindDefaultProperty(
    DISPID dwDispID,
    VARTYPE vtProp,
    LPCTSTR szFieldName,
    CWnd* pDSCWnd);
```

### <a name="parameters"></a>Parâmetros

*Dwdispid*<br/>
Especifica o DISPID de uma propriedade em um controle vinculado a dados que deve ser vinculado a um controle de origem de dados.

*Vtprop*<br/>
Especifica o tipo de propriedade a ser vinculada — por exemplo, VT_BSTR, VT_VARIANT e assim por diante.

*szFieldName*<br/>
Especifica o nome da coluna, no cursor fornecido pelo controle de origem de dados, ao qual a propriedade será vinculada.

*pDSCWnd*<br/>
Um ponteiro `CWnd`para o objeto derivado que hospeda o controle de origem de dados ao qual a propriedade será vinculada.

### <a name="remarks"></a>Comentários

O `CWnd` objeto no qual você chama esta função deve ser um controle vinculado a dados.

## <a name="colecontrolsitebindproperty"></a><a name="bindproperty"></a>COleControlSite::BindProperty

Vincula a propriedade vinculada simples do objeto de chamada, conforme marcado na biblioteca do tipo, ao cursor subjacente definido pelas propriedades DataSource, UserName, Password e SQL do controle de origem de dados.

```
virtual void BindProperty(
    DISPID dwDispId,
    CWnd* pWndDSC);
```

### <a name="parameters"></a>Parâmetros

*Dwdispid*<br/>
Especifica o DISPID de uma propriedade em um controle vinculado a dados que deve ser vinculado a um controle de origem de dados.

*pWndDSC*<br/>
Um ponteiro `CWnd`para o objeto derivado que hospeda o controle de origem de dados ao qual a propriedade será vinculada.

### <a name="remarks"></a>Comentários

O `CWnd` objeto no qual você chama esta função deve ser um controle vinculado a dados.

## <a name="colecontrolsitecolecontrolsite"></a><a name="colecontrolsite"></a>COleControlSite::COleControlSite

Constrói um novo objeto `COleControlSite`.

```
explicit COleControlSite(COleControlContainer* pCtrlCont);
```

### <a name="parameters"></a>Parâmetros

*pCtrlCont*<br/>
Um ponteiro para o contêiner do controle (que representa a janela que hospeda o controle AtiveX).

### <a name="remarks"></a>Comentários

Essa função é chamada pela função [COccManager::CreateContainer.](../../mfc/reference/coccmanager-class.md#createcontainer) Para obter mais informações sobre a personalização da criação de contêineres, consulte [COccManager::CreateSite](../../mfc/reference/coccmanager-class.md#createsite).

## <a name="colecontrolsitecreatecontrol"></a><a name="createcontrol"></a>COleControlSite::CreateControl

Cria um controle ActiveX, `COleControlSite` hospedado pelo objeto.

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
Um ponteiro para o objeto da janela representando o controle.

*clsid*<br/>
A identificação única da classe do controle.

*lpszWindowName*<br/>
Um ponteiro para o texto a ser exibido no controle. Define o valor da propriedade Legenda ou Texto do winodw (se houver).

*Dwstyle*<br/>
Estilos de windows. Os estilos disponíveis estão listados na seção **Observações.**

*Rect*<br/>
Especifica o tamanho e a posição do controle. Pode ser um `CRect` objeto `RECT` ou uma estrutura.

*nID*<br/>
Especifica a id da janela do filho do controle.

*Ppersist*<br/>
Um ponteiro `CFile` para um estado persistente para o controle. O valor padrão é NULL, indicando que o controle se inicia sem restaurar seu estado de qualquer armazenamento persistente. Se não for NULO, deve `CFile`ser um ponteiro para um objeto derivado que contenha os dados persistentes do controle, na forma de um fluxo ou de um armazenamento. Esses dados poderiam ter sido salvos em uma ativação prévia do cliente. O `CFile` pode conter outros dados, mas deve ter seu ponteiro de leitura de gravação definido `CreateControl`para o primeiro byte de dados persistentes no momento da chamada para .

*Bstorage*<br/>
Indica se os dados em *pPersist* devem ser interpretados como `IStorage` ou `IStream` dados. Se os dados em *pPersist* forem um armazenamento, *bArmazenamento* deve ser VERDADEIRO. Se os dados em *pPersist* forem um fluxo, *bArmazenamento* deve ser FALSO. O valor padrão é FALSE.

*bstrlickey*<br/>
Dados de chave de licença opcionais. Esses dados são necessários apenas para criar controles que requerem uma chave de licença em tempo de execução. Se o controle suportar o licenciamento, você deve fornecer uma chave de licença para a criação do controle para ter sucesso. O valor padrão é NULL.

*Ppt*<br/>
Um ponteiro `POINT` para uma estrutura que contém o canto superior esquerdo do controle. O tamanho do controle é determinado pelo valor do *tamanho*. Os valores *ppt* e *psize* são um método opcional de especificar o tamanho e posicionar o opf no controle.

*Psize*<br/>
Um ponteiro `SIZE` para uma estrutura que contém o tamanho do controle. O canto superior esquerdo é determinado pelo valor de *ppt*. Os valores *ppt* e *psize* são um método opcional de especificar o tamanho e posicionar o opf no controle.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Apenas um subconjunto das bandeiras *dwStyle* do Windows são suportados por: `CreateControl`

- WS_VISIBLE Cria uma janela que é inicialmente visível. Necessário se você quiser que o controle seja visível imediatamente, como janelas comuns.

- WS_DISABLED Cria uma janela inicialmente desativada. Uma janela desativada não pode receber entrada do usuário. Pode ser definido se o controle tiver uma propriedade Habilitada.

- WS_BORDER cria uma janela com uma borda de linha fina. Pode ser definido se o controle tiver uma propriedade BorderStyle.

- WS_GROUP Especifica o primeiro controle de um grupo de controles. O usuário pode alterar o foco do teclado de um controle no grupo para o próximo usando as teclas de direção. Todos os controles definidos com o estilo WS_GROUP após o primeiro controle pertencem ao mesmo grupo. O próximo controle com o WS_GROUP estilo termina o grupo e começa o próximo grupo.

- WS_TABSTOP Especifica um controle que pode receber o foco do teclado quando o usuário pressiona a tecla TAB. Pressionar a tecla TAB altera o foco do teclado para o próximo controle do estilo WS_TABSTOP.

Use a segunda sobrecarga para criar controles de tamanho padrão.

## <a name="colecontrolsitedestroycontrol"></a><a name="destroycontrol"></a>COleControlSite::DestroyControl

Destrói o `COleControlSite` objeto.

```
virtual BOOL DestroyControl();
```

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido, caso contrário 0.

### <a name="remarks"></a>Comentários

Uma vez concluído, o objeto é liberado da memória e quaisquer ponteiros para o objeto não são mais válidos.

## <a name="colecontrolsitedoverb"></a><a name="doverb"></a>COleControlSite::DoVerb

Executa o verbo especificado.

```
virtual HRESULT DoVerb(
    LONG nVerb,
    LPMSG lpMsg = NULL);
```

### <a name="parameters"></a>Parâmetros

*Nverb*<br/>
Especifica o verbo a ser executado. Pode incluir um dos seguintes:

|Valor|Significado|Símbolo|
|-----------|-------------|------------|
|0|Verbo primário|OLEIVERB_PRIMARY|
|-1|Verbo secundário|(Nenhuma)|
|1|Exibe o objeto para edição.|Oleiverb_show|
|-2|Edie o item em uma janela separada.|OLEIVERB_OPEN|
|-3|Esconde o objeto.|OLEIVERB_HIDE|
|-4|Ativa um controle no local.|Oleiverb_uiactivate|
|-5|Ativa um controle no local, sem elementos adicionais de interface do usuário.|OLEIVERB_INPLACEACTIVATE|
|-7|Exibir as propriedades do controle.|OLEIVERB_PROPERTIES|

*Lpmsg*<br/>
Ponteiro para a mensagem que fez com que o item fosse ativado.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Esta função é chamada diretamente `IOleObject` através da interface do controle para executar o verbo especificado. Se uma exceção for lançada como resultado dessa chamada de função, um código de erro HRESULT será retornado.

Para obter mais informações, consulte [IOleObject::DoVerb](/windows/win32/api/oleidl/nf-oleidl-ioleobject-doverb) no Windows SDK.

## <a name="colecontrolsiteenabledsc"></a><a name="enabledsc"></a>COleControlSite::EnableDSC

Permite o fornecimento de dados para o local de controle.

```
virtual void EnableDSC();
```

### <a name="remarks"></a>Comentários

Chamado pela estrutura para habilitar e inicializar o fornecimento de dados para o site de controle. Anular esta função para fornecer comportamento personalizado.

## <a name="colecontrolsiteenablewindow"></a><a name="enablewindow"></a>COleControlSite::Ativarjanela

Ativa ou desativa a entrada do mouse e do teclado no local de controle.

```
virtual BOOL EnableWindow(BOOL bEnable);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
Especifica se habilita ou desativa a janela: TRUE se a entrada da janela for ativada, caso contrário, FALSA.

### <a name="return-value"></a>Valor retornado

Não zero se a janela foi previamente desativada, caso contrário 0.

## <a name="colecontrolsitefreezeevents"></a><a name="freezeevents"></a>COleControlSite::FreezeEvents

Especifica se o local de controle lidará ou ignorará os eventos disparados de um controle.

```cpp
void FreezeEvents(BOOL bFreeze);
```

### <a name="parameters"></a>Parâmetros

*bFreeze*<br/>
Especifica se o site de controle deseja parar de aceitar eventos. Não zero se o controle não estiver aceitando eventos; caso contrário, zero.

### <a name="remarks"></a>Comentários

Se *bFreeze* for TRUE, o site de controle solicita o controle para parar eventos de fring. Se *bFreeze* for FALSE, o site de controle solicita que o controle continue disparando eventos.

> [!NOTE]
> O controle não é necessário para parar os eventos de disparo se solicitado pelo site de controle. Pode continuar disparando, mas todos os eventos subseqüentes serão ignorados pelo local de controle.

## <a name="colecontrolsitegetcontrolinfo"></a><a name="getcontrolinfo"></a>COleControlSite::GetControlInfo

Recupera informações sobre mnemônicos de teclado e comportamento do teclado.

```cpp
void GetControlInfo();
```

### <a name="remarks"></a>Comentários

As informações são armazenadas no [COleControlSite::m_ctlInfo](#m_ctlinfo).

## <a name="colecontrolsitegetdefbtncode"></a><a name="getdefbtncode"></a>COleControlSite::GetDefBtnCode

Determina se o controle é um botão padrão.

```
DWORD GetDefBtnCode();
```

### <a name="return-value"></a>Valor retornado

Pode ser um dos seguintes valores:

- DLGC_DEFPUSHBUTTON Control é o botão padrão na caixa de diálogo.

- DLGC_UNDEFPUSHBUTTON Control não é o botão padrão na caixa de diálogo.

- **0** O controle não é um botão.

## <a name="colecontrolsitegetdlgctrlid"></a><a name="getdlgctrlid"></a>COleControlSite::GetDlgCtrlID

Recupera o identificador do controle.

```
virtual int GetDlgCtrlID() const;
```

### <a name="return-value"></a>Valor retornado

O identificador do item de diálogo do controle.

## <a name="colecontrolsitegeteventiid"></a><a name="geteventiid"></a>COleControlSite::GetEventIID

Recupera um ponteiro para a interface de evento padrão do controle.

```
BOOL GetEventIID(IID* piid);
```

### <a name="parameters"></a>Parâmetros

*Piid*<br/>
Um ponteiro para um ID de interface.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido, caso contrário 0. Se for bem-sucedido, *piid* contém o ID de interface para a interface de evento padrão do controle.

## <a name="colecontrolsitegetexstyle"></a><a name="getexstyle"></a>COleControlSite::GetExStyle

Recupera os estilos estendidos da janela.

```
virtual DWORD GetExStyle() const;
```

### <a name="return-value"></a>Valor retornado

A janela de controle tem estilos estendidos.

### <a name="remarks"></a>Comentários

Para recuperar os estilos regulares, ligue para [COleControlSite::GetStyle](#getstyle).

## <a name="colecontrolsitegetproperty"></a><a name="getproperty"></a>COleControlSite::GetProperty

Obtém a propriedade de controle especificada por *dwDispID*.

```
virtual void GetProperty(
    DISPID dwDispID,
    VARTYPE vtProp,
    void* pvProp) const;
```

### <a name="parameters"></a>Parâmetros

*Dwdispid*<br/>
Identifica o ID de expedição da propriedade, `IDispatch` encontrado na interface padrão do controle, a ser recuperado.

*Vtprop*<br/>
Especifica o tipo da propriedade a ser recuperada. Para obter valores possíveis, consulte a seção Observações de [COleDispatchDriver::InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).

*Pvprop*<br/>
Endereço da variável que receberá o valor da propriedade. Deve corresponder ao tipo especificado por *vtProp*.

### <a name="remarks"></a>Comentários

O valor é devolvido através *de pvProp*.

## <a name="colecontrolsitegetstyle"></a><a name="getstyle"></a>COleControlSite::GetStyle

Recupera os estilos do local de controle.

```
virtual DWORD GetStyle() const;
```

### <a name="return-value"></a>Valor retornado

Os estilos da janela.

### <a name="remarks"></a>Comentários

Para obter uma lista de valores possíveis, consulte Estilos do [Windows](../../mfc/reference/styles-used-by-mfc.md#window-styles). Para recuperar os estilos estendidos do site de controle, ligue para [COleControlSite::GetExStyle](#getexstyle).

## <a name="colecontrolsitegetwindowtext"></a><a name="getwindowtext"></a>COleControlSite::GetWindowText

Recupera o texto atual do controle.

```
virtual void GetWindowText(CString& str) const;
```

### <a name="parameters"></a>Parâmetros

*Str*<br/>
Uma referência `CString` a um objeto que contém o texto atual do controle.

### <a name="remarks"></a>Comentários

Se o controle suportar a propriedade de estoque caption, esse valor será devolvido. Se a propriedade de estoque caption não for suportada, o valor da propriedade Text será devolvido.

## <a name="colecontrolsiteinvokehelper"></a><a name="invokehelper"></a>COleControlSite::InvokeHelper

Invoca o método ou propriedade especificado por *dwDispID,* no contexto especificado por *wFlags*.

```
virtual void AFX_CDECL InvokeHelper(
    DISPID dwDispID,
    WORD wFlags,
    VARTYPE vtRet,
    void* pvRet,
    const BYTE* pbParamInfo, ...);
```

### <a name="parameters"></a>Parâmetros

*Dwdispid*<br/>
Identifica o ID de expedição da propriedade ou `IDispatch` método, encontrado na interface do controle, a ser invocado.

*Wflags*<br/>
Sinalizadores descrevendo o contexto da chamada para IDispatch::Invocar. Para possíveis valores `IDispatch::Invoke` *wFlags,* consulte no SDK do Windows.

*vtRet*<br/>
Especifica o tipo do valor de retorno. Para obter valores possíveis, consulte a seção Observações de [COleDispatchDriver::InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).

*pvRet*<br/>
Endereço da variável que receberá o valor do imóvel ou o valor de retorno. Deve corresponder ao tipo especificado por *vtRet*.

*Pbparaminfo*<br/>
Ponteiro para uma seqüência de bytes com término nulo especificando os tipos dos parâmetros após *pbParamInfo*. Para obter valores possíveis, consulte a seção Observações de [COleDispatchDriver::InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).

*...*<br/>
Lista variável de parâmetros, de tipos especificados no *pbParamInfo*.

### <a name="remarks"></a>Comentários

O parâmetro *pbParamInfo* especifica os tipos dos parâmetros passados para o método ou propriedade. A lista variável de argumentos é representada por ... na declaração de sintaxe.

Esta função converte os parâmetros em valores VARIANTARG e, em seguida, invoca o `IDispatch::Invoke` método no controle. Se a `IDispatch::Invoke` chamada falhar, esta função abrirá uma exceção. Se o código de `IDispatch::Invoke` `DISP_E_EXCEPTION`status devolvido for, esta função lança um `COleDispatchException` objeto, caso contrário ele lança um `COleException`.

## <a name="colecontrolsiteinvokehelperv"></a><a name="invokehelperv"></a>COleControlSite::InvokeHelperV

Invoca o método ou propriedade especificado por *dwDispID,* no contexto especificado por *wFlags*.

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

*Dwdispid*<br/>
Identifica o ID de expedição da propriedade ou `IDispatch` método, encontrado na interface do controle, a ser invocado.

*Wflags*<br/>
Sinalizadores descrevendo o contexto da chamada para IDispatch::Invocar.

*vtRet*<br/>
Especifica o tipo do valor de retorno. Para obter valores possíveis, consulte a seção Observações de [COleDispatchDriver::InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).

*pvRet*<br/>
Endereço da variável que receberá o valor do imóvel ou o valor de retorno. Deve corresponder ao tipo especificado por *vtRet*.

*Pbparaminfo*<br/>
Ponteiro para uma seqüência de bytes com término nulo especificando os tipos dos parâmetros após *pbParamInfo*. Para obter valores possíveis, consulte a seção Observações de [COleDispatchDriver::InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).

*Arglist*<br/>
Ponteiro para uma lista de argumentos variáveis.

### <a name="remarks"></a>Comentários

O parâmetro *pbParamInfo* especifica os tipos dos parâmetros passados para o método ou propriedade. Parâmetros extras para o método ou propriedade que está sendo invocado podem ser passados usando o parâmetro *va_list.*

Normalmente, essa função `COleControlSite::InvokeHelper`é chamada por .

## <a name="colecontrolsiteisdefaultbutton"></a><a name="isdefaultbutton"></a>COleControlSite::IsDefaultButton

Determina se o controle é o botão padrão.

```
BOOL IsDefaultButton();
```

### <a name="return-value"></a>Valor retornado

Não zero se o controle for o botão padrão na janela, caso contrário, zero.

## <a name="colecontrolsiteiswindowenabled"></a><a name="iswindowenabled"></a>COleControlSite::IsWindowEnabled

Determina se o local de controle está ativado.

```
virtual BOOL IsWindowEnabled() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o controle estiver ativado, caso contrário zero.

### <a name="remarks"></a>Comentários

O valor é recuperado da propriedade de estoque habilitado do controle.

## <a name="colecontrolsitem_biswindowless"></a><a name="m_biswindowless"></a>COleControlSite::m_bIsWindowless

Determina se o objeto é um controle sem janelas.

```
BOOL m_bIsWindowless;
```

### <a name="remarks"></a>Comentários

Não zero se o controle não tiver janela, caso contrário zero.

## <a name="colecontrolsitem_ctlinfo"></a><a name="m_ctlinfo"></a>COleControlSite::m_ctlInfo

Informações sobre como a entrada do teclado é tratada pelo controle.

```
CONTROLINFO m_ctlInfo;
```

### <a name="remarks"></a>Comentários

Essas informações são armazenadas em uma estrutura [CONTROLINFO.](/windows/win32/api/ocidl/ns-ocidl-controlinfo)

## <a name="colecontrolsitem_dweventsink"></a><a name="m_dweventsink"></a>COleControlSite::m_dwEventSink

Contém o cookie do ponto de conexão da pia de eventos do controle.

```
DWORD m_dwEventSink;
```

## <a name="colecontrolsitem_dwmiscstatus"></a><a name="m_dwmiscstatus"></a>COleControlSite::m_dwMiscStatus

Contém informações diversas sobre o controle.

```
DWORD m_dwMiscStatus;
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [OLEMISC](/windows/win32/api/oleidl/ne-oleidl-olemisc)no SDK do Windows.

## <a name="colecontrolsitem_dwpropnotifysink"></a><a name="m_dwpropnotifysink"></a>COleControlSite::m_dwPropNotifySink

Contém o cookie [IPropertyNotifySink.](/windows/win32/api/ocidl/nn-ocidl-ipropertynotifysink)

```
DWORD m_dwPropNotifySink;
```

## <a name="colecontrolsitem_dwstyle"></a><a name="m_dwstyle"></a>COleControlSite::m_dwStyle

Contém os estilos de janela do controle.

```
DWORD m_dwStyle;
```

## <a name="colecontrolsitem_hwnd"></a><a name="m_hwnd"></a>COleControlSite::m_hWnd

Contém o HWND do controle ou NULL se o controle estiver sem janelas.

```
HWND m_hWnd;
```

## <a name="colecontrolsitem_iidevents"></a><a name="m_iidevents"></a>COleControlSite::m_iidEvents

Contém o ID de interface da interface de dissipador de eventos padrão do controle.

```
IID m_iidEvents;
```

## <a name="colecontrolsitem_nid"></a><a name="m_nid"></a>COleControlSite::m_nID

Contém o id do item de diálogo do controle.

```
UINT m_nID;
```

## <a name="colecontrolsitem_pactiveobject"></a><a name="m_pactiveobject"></a>COleControlSite::m_pActiveObject

Contém a interface [IOleInPlaceActiveObject](/windows/win32/api/oleidl/nn-oleidl-ioleinplaceactiveobject) do controle.

```
LPOLEINPLACEACTIVEOBJECT m_pActiveObject;
```

## <a name="colecontrolsitem_pctrlcont"></a><a name="m_pctrlcont"></a>COleControlSite::m_pCtrlCont

Contém o recipiente do controle (representando o formulário).

```
COleControlContainer* m_pCtrlCont;
```

## <a name="colecontrolsitem_pinplaceobject"></a><a name="m_pinplaceobject"></a>COleControlSite::m_pInPlaceObject

Contém `IOleInPlaceObject` a interface [IOleInPlaceObject](/windows/win32/api/oleidl/nn-oleidl-ioleinplaceobject) do controle.

```
LPOLEINPLACEOBJECT m_pInPlaceObject;
```

## <a name="colecontrolsitem_pobject"></a><a name="m_pobject"></a>COleControlSite::m_pObject

Contém `IOleObjectInterface` a interface do controle.

```
LPOLEOBJECT m_pObject;
```

## <a name="colecontrolsitem_pwindowlessobject"></a><a name="m_pwindowlessobject"></a>COleControlSite::m_pWindowlessObject

Contém `IOleInPlaceObjectWindowless`a interface [IOleInPlaceObjectWindowless](/windows/win32/api/ocidl/nn-ocidl-ioleinplaceobjectwindowless) do controle.

```
IOleInPlaceObjectWindowless* m_pWindowlessObject;
```

## <a name="colecontrolsitem_pwndctrl"></a><a name="m_pwndctrl"></a>COleControlSite::m_pWndCtrl

Contém um ponteiro `CWnd` para o objeto que representa o próprio controle.

```
CWnd* m_pWndCtrl;
```

## <a name="colecontrolsitem_rect"></a><a name="m_rect"></a>COleControlSite::m_rect

Contém os limites do controle, em relação à janela do recipiente.

```
CRect m_rect;
```

## <a name="colecontrolsitemodifystyle"></a><a name="modifystyle"></a>COleControlSite::ModifyStyle

Modifica os estilos do controle.

```
virtual BOOL ModifyStyle(
    DWORD dwRemove,
    DWORD dwAdd,
    UINT nFlags);
```

### <a name="parameters"></a>Parâmetros

*dwRemover*<br/>
Os estilos a serem removidos dos estilos de janela atuais.

*dwAdd*<br/>
Os estilos a serem adicionados a partir dos estilos de janela atuais.

*Nflags*<br/>
Bandeiras de posicionamento da janela. Para obter uma lista de valores possíveis, consulte a função [SetWindowPos](/windows/win32/api/winuser/nf-winuser-setwindowpos) no SDK do Windows.

### <a name="return-value"></a>Valor retornado

Não zero se os estilos forem alterados, caso contrário zero.

### <a name="remarks"></a>Comentários

Estoque do controle A propriedade habilitada será modificada para corresponder à configuração de WS_DISABLED. A propriedade border style do controle será modificada para corresponder à configuração solicitada para WS_BORDER. Todos os outros estilos são aplicados diretamente na alça da janela do controle, se houver presente.

Modifica os estilos de janela do controle. Os estilos a serem adicionados ou removidos podem ser combinados usando o operador bitwise OR (&#124;). Consulte a função [CreateWindow](/windows/win32/api/winuser/nf-winuser-createwindoww) no SDK do Windows para obter informações sobre os estilos de janela disponíveis.

Se *nFlags* não `ModifyStyle` for zero, chamará a função `SetWindowPos`Win32 e redesenha a janela combinando *nFlags* com as quatro bandeiras a seguir:

- SWP_NOSIZE Retém o tamanho atual.

- SWP_NOMOVE Mantém a posição atual.

- SWP_NOZORDER retém a ordem Z atual.

- SWP_NOACTIVATE Não ativa a janela.

Para modificar os estilos estendidos de uma janela, chame [ModifyStyleEx](#modifystyleex).

## <a name="colecontrolsitemodifystyleex"></a><a name="modifystyleex"></a>COleControlSite::ModifyStyleEx

Modifica os estilos estendidos do controle.

```
virtual BOOL ModifyStyleEx(
    DWORD dwRemove,
    DWORD dwAdd,
    UINT nFlags);
```

### <a name="parameters"></a>Parâmetros

*dwRemover*<br/>
Os estilos estendidos a serem removidos dos estilos de janela atuais.

*dwAdd*<br/>
Os estilos estendidos a serem adicionados a partir dos estilos de janela atuais.

*Nflags*<br/>
Bandeiras de posicionamento da janela. Para obter uma lista de valores possíveis, consulte a função [SetWindowPos](/windows/win32/api/winuser/nf-winuser-setwindowpos) no SDK do Windows.

### <a name="return-value"></a>Valor retornado

Não zero se os estilos forem alterados, caso contrário zero.

### <a name="remarks"></a>Comentários

A propriedade de aparência de estoque do controle será modificada para corresponder à configuração de WS_EX_CLIENTEDGE. Todos os outros estilos de janela estendidos são aplicados diretamente na alça da janela do controle, se houver presente.

Modifica os estilos estendidos da janela do objeto do local de controle. Os estilos a serem adicionados ou removidos podem ser combinados usando o operador bitwise OR (&#124;). Consulte a função [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) no SDK do Windows para obter informações sobre os estilos de janela disponíveis.

Se *nFlags* não `ModifyStyleEx` for zero, chamará a função `SetWindowPos`Win32 e redesenha a janela combinando *nFlags* com as quatro bandeiras a seguir:

- SWP_NOSIZE Retém o tamanho atual.

- SWP_NOMOVE Mantém a posição atual.

- SWP_NOZORDER retém a ordem Z atual.

- SWP_NOACTIVATE Não ativa a janela.

Para modificar os estilos estendidos de uma janela, chame [ModifyStyle](#modifystyle).

## <a name="colecontrolsitemovewindow"></a><a name="movewindow"></a>COleControlSite::MoveWindow

Muda a posição do controle.

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

*Y*<br/>
A nova posição do topo da janela.

*Nwidth*<br/>
A nova largura da janela

*Nheight*<br/>
A nova altura da janela.

## <a name="colecontrolsitequickactivate"></a><a name="quickactivate"></a>COleControlSite::QuickActivate

Rápido ativa o controle contido.

```
virtual BOOL QuickActivate();
```

### <a name="return-value"></a>Valor retornado

Não zero se o local de controle foi ativado, caso contrário zero.

### <a name="remarks"></a>Comentários

Essa função só deve ser chamada se o usuário estiver substituindo o processo de criação do controle.

Os `IPersist*::Load` `IPersist*::InitNew` métodos devem ser chamados após a ativação rápida ocorrer. O controle deve estabelecer suas conexões com as pias do recipiente durante a ativação rápida. No entanto, essas conexões não estão vivas até `IPersist*::Load` ou `IPersist*::InitNew` foram chamadas.

## <a name="colecontrolsitesafesetproperty"></a><a name="safesetproperty"></a>COleControlSite::SafeSetProperty

Define a propriedade de controle especificada por *dwDispID*.

```
virtual BOOL AFX_CDECL SafeSetProperty(
    DISPID dwDispID,
    VARTYPE vtProp, ...);
```

### <a name="parameters"></a>Parâmetros

*Dwdispid*<br/>
Identifica o ID de expedição da propriedade ou `IDispatch` método, encontrado na interface do controle, a ser definido.

*Vtprop*<br/>
Especifica o tipo de propriedade a ser definida. Para obter valores possíveis, consulte a seção Observações de [COleDispatchDriver::InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).

*...*<br/>
Um único parâmetro do tipo especificado por *vtProp*.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

> [!NOTE]
> Ao `SetProperty` `SetPropertyV`contrário e, se um erro for encontrado (como tentar definir uma propriedade inexistente), nenhuma exceção é lançada.

## <a name="colecontrolsitesetdefaultbutton"></a><a name="setdefaultbutton"></a>COleControlSite::SetDefaultButton

Define o controle como o botão padrão.

```cpp
void SetDefaultButton(BOOL bDefault);
```

### <a name="parameters"></a>Parâmetros

*bDefault*<br/>
Não zero se o controle se tornar o botão padrão; caso contrário, zero.

### <a name="remarks"></a>Comentários

> [!NOTE]
> O controle deve ter o OLEMISC_ACTSLIKEBUTTON bit de status definido.

## <a name="colecontrolsitesetdlgctrlid"></a><a name="setdlgctrlid"></a>COleControlSite::SetDlgCtrlID

Altera o valor do identificador de item de diálogo do controle.

```
virtual int SetDlgCtrlID(int nID);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
O novo valor do identificador.

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, o identificador de item de diálogo anterior da janela; caso contrário, 0.

### <a name="remarks"></a>Comentários

## <a name="colecontrolsitesetfocus"></a><a name="setfocus"></a>COleControlSite::SetFocus

Define o foco para o controle.

```
virtual CWnd* SetFocus();
virtual CWnd* SetFocus(LPMSG lpmsg);
```

### <a name="parameters"></a>Parâmetros

*Lpmsg*<br/>
Um ponteiro para uma [estrutura MSG](/windows/win32/api/winuser/ns-winuser-msg). Esta estrutura contém a mensagem do Windows acionando a `SetFocus` solicitação do controle contido no site de controle atual.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a janela que anteriormente tinha foco.

## <a name="colecontrolsitesetproperty"></a><a name="setproperty"></a>COleControlSite::SetProperty

Define a propriedade de controle especificada por *dwDispID*.

```
virtual void AFX_CDECL SetProperty(
    DISPID dwDispID,
    VARTYPE vtProp, ...);
```

### <a name="parameters"></a>Parâmetros

*Dwdispid*<br/>
Identifica o ID de expedição da propriedade ou `IDispatch` método, encontrado na interface do controle, a ser definido.

*Vtprop*<br/>
Especifica o tipo de propriedade a ser definida. Para obter valores possíveis, consulte a seção Observações de [COleDispatchDriver::InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).

*...*<br/>
Um único parâmetro do tipo especificado por *vtProp*.

### <a name="remarks"></a>Comentários

Se `SetProperty` encontrar um erro, uma exceção é lançada.

O tipo de exceção é determinado pelo valor de retorno da tentativa de definir a propriedade ou método. Se o valor `DISP_E_EXCEPTION`de `COleDispatchExcpetion` retorno for , a é jogado; caso contrário, um `COleException`.

## <a name="colecontrolsitesetpropertyv"></a><a name="setpropertyv"></a>COleControlSite::SetPropertyV

Define a propriedade de controle especificada por *dwDispID*.

```
virtual void SetPropertyV(
    DISPID dwDispID,
    VARTYPE vtProp,
    va_list argList);
```

### <a name="parameters"></a>Parâmetros

*Dwdispid*<br/>
Identifica o ID de expedição da propriedade ou `IDispatch` método, encontrado na interface do controle, a ser definido.

*Vtprop*<br/>
Especifica o tipo de propriedade a ser definida. Para obter valores possíveis, consulte a seção Observações de [COleDispatchDriver::InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).

*Arglist*<br/>
Ponteiro para a lista de argumentos.

### <a name="remarks"></a>Comentários

Parâmetros extras para o método ou propriedade que está sendo invocado podem ser passados usando o parâmetro *arg_list.* Se `SetProperty` encontrar um erro, uma exceção é lançada.

O tipo de exceção é determinado pelo valor de retorno da tentativa de definir a propriedade ou método. Se o valor `DISP_E_EXCEPTION`de `COleDispatchExcpetion` retorno for , a é jogado; caso contrário, um `COleException`.

## <a name="colecontrolsitesetwindowpos"></a><a name="setwindowpos"></a>COleControlSite::SetWindowPos

Define a ordem de tamanho, posição e Z do local de controle.

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

*Pwndinsertafter*<br/>
Um ponteiro para a janela.

*x*<br/>
A nova posição do lado esquerdo da janela.

*Y*<br/>
A nova posição do topo da janela.

*Cx*<br/>
A nova largura da janela

*Cy*<br/>
A nova altura da janela.

*Nflags*<br/>
Especifica as bandeiras de dimensionamento e posicionamento da janela. Para obter valores possíveis, consulte a seção Observações para [SetWindowPos](/windows/win32/api/winuser/nf-winuser-setwindowpos) no Windows SDK.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido, caso contrário zero.

## <a name="colecontrolsitesetwindowtext"></a><a name="setwindowtext"></a>COleControlSite::SetWindowText

Define o texto para o site de controle.

```
virtual void SetWindowText(LPCTSTR lpszString);
```

### <a name="parameters"></a>Parâmetros

*lpszString*<br/>
Ponteiro para uma seqüência de seqüência de terminadas nula para ser usado como o novo título ou texto de controle.

### <a name="remarks"></a>Comentários

Esta função primeiro tenta definir a propriedade caption stock. Se a propriedade caption stock não for suportada, a propriedade Texto será definida em vez disso.

## <a name="colecontrolsiteshowwindow"></a><a name="showwindow"></a>COleControlSite::ShowWindow

Define o estado do show da janela.

```
virtual BOOL ShowWindow(int nCmdShow);
```

### <a name="parameters"></a>Parâmetros

*Ncmdshow*<br/>
Especifica como o local de controle deve ser mostrado. Deve ser um dos seguintes valores:

- SW_HIDE Esconde esta janela e passa a ativação para outra janela.

- SW_MINIMIZE Minimiza a janela e ativa a janela de nível superior na lista do sistema.

- SW_RESTORE Ativa e exibe a janela. Se a janela for minimizada ou maximizada, o Windows a restaurará ao seu tamanho e posição originais.

- SW_SHOW Ativa a janela e a exibe em seu tamanho e posição atuais.

- SW_SHOWMAXIMIZED Ativa a janela e a exibe como uma janela maximizada.

- SW_SHOWMINIMIZED Ativa a janela e a exibe como um ícone.

- SW_SHOWMINNOACTIVE Exibe a janela como um ícone. A janela que está atualmente ativa permanece ativa.

- SW_SHOWNA Exibe a janela em seu estado atual. A janela que está atualmente ativa permanece ativa.

- SW_SHOWNOACTIVATE Exibe a janela em seu tamanho e posição mais recentes. A janela que está atualmente ativa permanece ativa.

- SW_SHOWNORMAL Ativa e exibe a janela. Se a janela for minimizada ou maximizada, o Windows a restaurará ao seu tamanho e posição originais.

### <a name="return-value"></a>Valor retornado

Não zero se a janela fosse visível anteriormente; 0 se a janela estava anteriormente escondida.

## <a name="see-also"></a>Confira também

[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleControlContainer](../../mfc/reference/colecontrolcontainer-class.md)
