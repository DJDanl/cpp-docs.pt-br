---
title: Classe COleControlSite | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs: C++
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
caps.latest.revision: "24"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 80541bc777d2c77209812cbee621045b7d6c6507
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
|[COleControlSite::BindDefaultProperty](#binddefaultproperty)|Associa a propriedade padrão do controle hospedado com uma fonte de dados.|  
|[COleControlSite::BindProperty](#bindproperty)|Associa uma propriedade do controle hospedado com uma fonte de dados.|  
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
|[COleControlSite::IsDefaultButton](#isdefaultbutton)|Determina se o controle de botão padrão na janela.|  
|[COleControlSite::IsWindowEnabled](#iswindowenabled)|Verifica o estado de visibilidade do site do controle.|  
|[COleControlSite::ModifyStyle](#modifystyle)|Modifica atual estendidos estilos do site do controle.|  
|[COleControlSite::ModifyStyleEx](#modifystyleex)|Modifica os estilos atuais do site do controle.|  
|[COleControlSite::MoveWindow](#movewindow)|Altera a posição do site do controle.|  
|[COleControlSite::QuickActivate](#quickactivate)|Rápida ativa o controle hospedado.|  
|[COleControlSite::SafeSetProperty](#safesetproperty)|Define uma propriedade ou método de controle sem chance de gerar uma exceção.|  
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
|[COleControlSite::GetControlInfo](#getcontrolinfo)|Recupera informações de teclado e mnemônicos para o controle hospedado.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleControlSite::m_bIsWindowless](#m_biswindowless)|Determina se o controle hospedado é um controle sem janelas.|  
|[COleControlSite::m_ctlInfo](#m_ctlinfo)|Contém informações sobre o teclado para o controle.|  
|[COleControlSite::m_dwEventSink](#m_dweventsink)|O cookie de ponto de conexão do controle.|  
|[COleControlSite::m_dwMiscStatus](#m_dwmiscstatus)|Os diversos estados do controle hospedado.|  
|[COleControlSite::m_dwPropNotifySink](#m_dwpropnotifysink)|O `IPropertyNotifySink` cookie do controle.|  
|[COleControlSite::m_dwStyle](#m_dwstyle)|Os estilos de controle hospedado.|  
|[COleControlSite::m_hWnd](#m_hwnd)|O identificador do site do controle.|  
|[COleControlSite::m_iidEvents](#m_iidevents)|A ID da interface de eventos para o controle hospedado.|  
|[COleControlSite::m_nID](#m_nid)|A ID do controle hospedado.|  
|[COleControlSite::m_pActiveObject](#m_pactiveobject)|Um ponteiro para o `IOleInPlaceActiveObject` objeto do controle hospedado.|  
|[COleControlSite::m_pCtrlCont](#m_pctrlcont)|O contêiner do controle hospedado.|  
|[COleControlSite::m_pInPlaceObject](#m_pinplaceobject)|Um ponteiro para o `IOleInPlaceObject` objeto do controle hospedado.|  
|[COleControlSite::m_pObject](#m_pobject)|Um ponteiro para o `IOleObjectInterface` interface do controle.|  
|[COleControlSite::m_pWindowlessObject](#m_pwindowlessobject)|Um ponteiro para o `IOleInPlaceObjectWindowless` interface do controle.|  
|[COleControlSite::m_pWndCtrl](#m_pwndctrl)|Um ponteiro para o objeto de janela para o controle hospedado.|  
|[COleControlSite::m_rect](#m_rect)|As dimensões do site do controle.|  
  
## <a name="remarks"></a>Comentários  
 Esse suporte é o principal meio pelo qual um controle ActiveX incorporado obtém informações sobre o local e a extensão do seu site de exibição, o identificador de origem, sua interface de usuário, suas propriedades de ambiente e outros recursos fornecidos por seu contêiner. `COleControlSite`implementa totalmente a [IOleControlSite](http://msdn.microsoft.com/library/windows/desktop/ms688502), [IOleInPlaceSite](http://msdn.microsoft.com/library/windows/desktop/ms686586), [IOleClientSite](http://msdn.microsoft.com/library/windows/desktop/ms693706), [IPropertyNotifySink](http://msdn.microsoft.com/library/windows/desktop/ms692638), **IBoundObjectSite**, **INotifyDBEvents**, [IRowSetNotify](../../data/oledb/irowsetnotifyimpl-class.md) interfaces. Além disso, a interface IDispatch (fornecendo suporte para propriedades de ambiente e Coletores de eventos) também é implementada.  
  
 Para criar um site de controle ActiveX usando `COleControlSite`, derive uma classe de `COleControlSite`. No seu `CWnd`-classe derivada para o contêiner (por exemplo, a caixa de diálogo) substituir o **CWnd::CreateControlSite** função.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 `COleControlSite`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxocc.h  
  
##  <a name="binddefaultproperty"></a>COleControlSite::BindDefaultProperty  
 Associa a chamada propriedade padrão do objeto simples associadas, como marcada na biblioteca de tipos, até o cursor subjacente que é definido pelas propriedades do controle de fonte de dados SQL, nome de usuário, senha e a fonte de dados.  
  
```  
virtual void BindDefaultProperty(
    DISPID dwDispID,  
    VARTYPE vtProp,  
    LPCTSTR szFieldName,  
    CWnd* pDSCWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwDispID`  
 Especifica o **DISPID** de uma propriedade em um controle de associação de dados que é vinculado a um controle de fonte de dados.  
  
 `vtProp`  
 Especifica o tipo da propriedade a ser vinculado — por exemplo, `VT_BSTR`, **VT_VARIANT**, e assim por diante.  
  
 `szFieldName`  
 Especifica o nome da coluna, o cursor fornecidos pelo controle de fonte de dados, para que a propriedade será associada.  
  
 `pDSCWnd`  
 Um ponteiro para o `CWnd`-objeto derivado que hospeda o controle de fonte de dados ao qual a propriedade será associada.  
  
### <a name="remarks"></a>Comentários  
 O `CWnd` objeto no qual você chamar esta função deve ser um controle associado a dados.  
  
##  <a name="bindproperty"></a>COleControlSite::BindProperty  
 Associa a chamada propriedade do objeto simples associadas, como marcada na biblioteca de tipos, até o cursor subjacente que é definido pelas propriedades do controle de fonte de dados SQL, nome de usuário, senha e a fonte de dados.  
  
```  
virtual void BindProperty(
    DISPID dwDispId,  
    CWnd* pWndDSC);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwDispId*  
 Especifica o **DISPID** de uma propriedade em um controle de associação de dados que é vinculado a um controle de fonte de dados.  
  
 `pWndDSC`  
 Um ponteiro para o `CWnd`-objeto derivado que hospeda o controle de fonte de dados ao qual a propriedade será associada.  
  
### <a name="remarks"></a>Comentários  
 O `CWnd` objeto no qual você chamar esta função deve ser um controle associado a dados.  
  
##  <a name="colecontrolsite"></a>COleControlSite::COleControlSite  
 Constrói um novo objeto `COleControlSite`.  
  
```  
explicit COleControlSite(COleControlContainer* pCtrlCont);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pCtrlCont`  
 Um ponteiro para o contêiner do controle (que representa a janela que hospeda o controle ActiveX).  
  
### <a name="remarks"></a>Comentários  
 Essa função é chamada [COccManager::CreateContainer](../../mfc/reference/coccmanager-class.md#createcontainer) função. Para obter mais informações sobre como personalizar a criação de contêineres, consulte [COccManager::CreateSite](../../mfc/reference/coccmanager-class.md#createsite).  
  
##  <a name="createcontrol"></a>COleControlSite::CreateControl  
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
 `pWndCtrl`  
 Um ponteiro para o objeto de janela que representa o controle.  
  
 `clsid`  
 A ID exclusiva de classe do controle.  
  
 `lpszWindowName`  
 Um ponteiro para o texto a ser exibido no controle. Define o valor da propriedade de legenda ou o texto do winodw (se houver).  
  
 `dwStyle`  
 Estilos de Windows. Os estilos disponíveis são listados sob o **comentários** seção.  
  
 `rect`  
 Especifica o tamanho e a posição do controle. Ele pode ser um `CRect` objeto ou um `RECT` estrutura.  
  
 `nID`  
 Especifica a ID de janela filho do controle  
  
 `pPersist`  
 Um ponteiro para um `CFile` que contém o estado persistente para o controle. O valor padrão é **nulo**, indicando que o controle inicializa a próprio sem restaurar o estado de qualquer armazenamento persistente. Se não **nulo**, ele deve ser um ponteiro para um `CFile`-derivados do objeto que contém os dados do controle persistente, na forma de um fluxo ou de armazenamento. Esses dados podem ter sido salvo em uma ativação anterior do cliente. O `CFile` pode conter outros dados, mas deve ter o ponteiro de leitura-gravação definido como o primeiro byte de dados persistentes no momento da chamada para `CreateControl`.  
  
 `bStorage`  
 Indica se os dados em `pPersist` devem ser interpretadas como `IStorage` ou `IStream` dados. Se os dados em `pPersist` é um armazenamento `bStorage` devem ser **TRUE**. Se os dados em `pPersist` é um fluxo `bStorage` devem ser **FALSE**. O valor padrão é **FALSE**.  
  
 `bstrLicKey`  
 Dados opcionais de chave de licença. Esses dados é necessária somente para a criação de controles que exigem uma chave de licença de tempo de execução. Se o controle dá suporte ao licenciamento, você deve fornecer uma chave de licença para a criação do controle seja bem-sucedida. O valor padrão é **nulo**.  
  
 `ppt`  
 Um ponteiro para um **ponto** estrutura que contém o canto superior esquerdo do controle. O tamanho do controle é determinado pelo valor de *psize*. O `ppt` e *psize* valores são um método opcional de especificar o tamanho e posição opf o controle.  
  
 *psize*  
 Um ponteiro para um **tamanho** estrutura que contém o tamanho do controle. O canto superior esquerdo é determinado pelo valor de `ppt`. O `ppt` e *psize* valores são um método opcional de especificar o tamanho e posição opf o controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Apenas um subconjunto das janelas de `dwStyle` sinalizadores são suportados pelo `CreateControl`:  
  
- **WS_VISIBLE** cria uma janela que é visível inicialmente. Necessário se você quiser que o controle esteja visível imediatamente, como janelas comuns.  
  
- **WS_DISABLED** cria uma janela que é inicialmente desabilitada. Uma janela desabilitada não pode receber entrada do usuário. Pode ser definido se o controle tiver uma propriedade Enabled.  
  
- `WS_BORDER`Cria uma janela com uma borda de linha fina. Pode ser definido se o controle tem uma propriedade BorderStyle.  
  
- **WS_GROUP** Especifica o primeiro controle de um grupo de controles. O usuário pode alterar o foco do teclado de um controle no grupo para o próximo usando as teclas de direção. Todos os controles definidos com o **WS_GROUP** após o primeiro controle pertencem ao mesmo grupo de estilo. O próximo controle com o **WS_GROUP** estilo encerra o grupo e inicia o próximo grupo.  
  
- **WS_TABSTOP** Especifica um controle que pode receber o foco do teclado quando o usuário pressiona a tecla TAB. Pressionar a tecla TAB altera o foco do teclado para o próximo controle do **WS_TABSTOP** estilo.  
  
 Use a segunda sobrecarga para criar controles de tamanho padrão.  
  
##  <a name="destroycontrol"></a>COleControlSite::DestroyControl  
 Destrói a `COleControlSite` objeto.  
  
```  
virtual BOOL DestroyControl();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedido, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Depois de concluído, o objeto é liberado da memória e qualquer ponteiros para o objeto não são mais válidos.  
  
##  <a name="doverb"></a>COleControlSite::DoVerb  
 Executa o verbo especificado.  
  
```  
virtual HRESULT DoVerb(
    LONG nVerb,  
    LPMSG lpMsg = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nVerb`  
 Especifica o verbo a ser executado. Ele pode incluir um dos seguintes:  
  
|Valor|Significado|Símbolo|  
|-----------|-------------|------------|  
|0|Verbo primário|`OLEIVERB_PRIMARY`|  
|-1|Verbo secundário|(Nenhum)|  
|1|Exibe o objeto para edição.|`OLEIVERB_SHOW`|  
|-2|Edita o item em uma janela separada.|`OLEIVERB_OPEN`|  
|-3|Oculta o objeto.|`OLEIVERB_HIDE`|  
|-4|Ativa um controle no local.|`OLEIVERB_UIACTIVATE`|  
|-5|Ativa um controle no local, sem os elementos de interface de usuário adicionais.|**OLEIVERB_INPLACEACTIVATE**|  
|-7|Exiba as propriedades do controle.|**OLEIVERB_PROPERTIES**|  
  
 `lpMsg`  
 Ponteiro para a mensagem que causou o item a ser ativado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Esta função chama diretamente por meio do controle `IOleObject` interface para executar o verbo especificado. Se uma exceção é lançada como resultado da chamada de função, um `HRESULT` código de erro é retornado.  
  
 Para obter mais informações, consulte [IOleObject:: DoVerb](http://msdn.microsoft.com/library/windows/desktop/ms694508) no SDK do Windows.  
  
##  <a name="enabledsc"></a>COleControlSite::EnableDSC  
 Permite que os dados de origem para o site de controle.  
  
```  
virtual void EnableDSC();
```  
  
### <a name="remarks"></a>Comentários  
 Chamado pelo framework para ativar e inicializar dados de origem para o site de controle. Substitua essa função para fornecer um comportamento personalizado.  
  
##  <a name="enablewindow"></a>COleControlSite::EnableWindow  
 Habilita ou desabilita o site de controle de entrada do teclado e mouse.  
  
```  
virtual BOOL EnableWindow(BOOL bEnable);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bEnable`  
 Especifica se deseja habilitar ou desabilitar a janela: **TRUE** se a entrada de janela é para ser habilitado, caso contrário, **FALSE**.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a janela já estava desabilitada, caso contrário, 0.  
  
##  <a name="freezeevents"></a>COleControlSite::FreezeEvents  
 Especifica se o site do controle será tratar ou ignorar eventos disparados por um controle.  
  
```  
void FreezeEvents(BOOL bFreeze);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bFreeze`  
 Especifica se o site de controle deseja parar de aceitar eventos. Diferente de zero se o controle não está aceitando eventos; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Se `bFreeze` é **TRUE**, o site de controle solicita o controle para interromper eventos fring. Se `bFreeze` é **FALSE**, o site de controle solicita o controle para continuar acionando eventos.  
  
> [!NOTE]
>  O controle não é necessário para interromper eventos acionados, se solicitado pelo site de controle. Ele pode continuar acionando mas todos os eventos subsequentes serão ignorados pelo site de controle.  
  
##  <a name="getcontrolinfo"></a>COleControlSite::GetControlInfo  
 Recupera informações sobre mnemônicos de teclado de um controle e o comportamento do teclado.  
  
```  
void GetControlInfo();
```  
  
### <a name="remarks"></a>Comentários  
 As informações são armazenadas em [COleControlSite::m_ctlInfo](#m_ctlinfo).  
  
##  <a name="getdefbtncode"></a>COleControlSite::GetDefBtnCode  
 Determina se o controle é um botão de ação padrão.  
  
```  
DWORD GetDefBtnCode();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Pode ser um dos seguintes valores:  
  
- **DLGC_DEFPUSHBUTTON** controle é o botão padrão na caixa de diálogo.  
  
- **DLGC_UNDEFPUSHBUTTON** controle não é o botão padrão na caixa de diálogo.  
  
- **0** controle não é um botão.  
  
##  <a name="getdlgctrlid"></a>COleControlSite::GetDlgCtrlID  
 Recupera o identificador do controle.  
  
```  
virtual int GetDlgCtrlID() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador do item de caixa de diálogo do controle.  
  
##  <a name="geteventiid"></a>COleControlSite::GetEventIID  
 Recupera um ponteiro para a interface de evento padrão do controle.  
  
```  
BOOL GetEventIID(IID* piid);
```  
  
### <a name="parameters"></a>Parâmetros  
 `piid`  
 Um ponteiro para uma ID de interface.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedido, caso contrário, 0. Se for bem-sucedido, `piid` contém a ID de interface para a interface de evento padrão do controle.  
  
##  <a name="getexstyle"></a>COleControlSite::GetExStyle  
 Recupera os estilos estendidos da janela.  
  
```  
virtual DWORD GetExStyle() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Estilos estendida da janela do controle.  
  
### <a name="remarks"></a>Comentários  
 Para recuperar os estilos regulares, chame [COleControlSite::GetStyle](#getstyle).  
  
##  <a name="getproperty"></a>COleControlSite::GetProperty  
 Obtém a propriedade do controle especificada pelo `dwDispID`.  
  
```  
virtual void GetProperty(
    DISPID dwDispID,  
    VARTYPE vtProp,  
    void* pvProp) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwDispID`  
 Identifica a ID de expedição da propriedade, encontrada no padrão do controle `IDispatch` interface a ser recuperado.  
  
 `vtProp`  
 Especifica o tipo da propriedade a ser recuperado. Para os valores possíveis, consulte a seção comentários para [COleDispatchDriver::InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).  
  
 `pvProp`  
 Endereço da variável que receberá o valor da propriedade. Ele deve corresponder ao tipo especificado pelo `vtProp`.  
  
### <a name="remarks"></a>Comentários  
 O valor é retornado por meio de `pvProp`.  
  
##  <a name="getstyle"></a>COleControlSite::GetStyle  
 Recupera os estilos do site do controle.  
  
```  
virtual DWORD GetStyle() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Estilos da janela.  
  
### <a name="remarks"></a>Comentários  
 Para obter uma lista de valores possíveis, consulte [estilos Windows](../../mfc/reference/styles-used-by-mfc.md#window-styles). Para recuperar os estilos estendidos do site de controle, chame [COleControlSite::GetExStyle](#getexstyle).  
  
##  <a name="getwindowtext"></a>COleControlSite::GetWindowText  
 Recupera o texto atual do controle.  
  
```  
virtual void GetWindowText(CString& str) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 Uma referência a um `CString` objeto que contém o texto atual do controle.  
  
### <a name="remarks"></a>Comentários  
 Se o controle suporta a propriedade de estoque de legenda, esse valor é retornado. Se não há suporte para a propriedade de estoque de legenda, o valor da propriedade Text é retornado.  
  
##  <a name="invokehelper"></a>COleControlSite::InvokeHelper  
 Invoca o método ou propriedade especificada pelo `dwDispID`, no contexto especificado pelos `wFlags`.  
  
```  
virtual void AFX_CDECL InvokeHelper(
    DISPID dwDispID,  
    WORD wFlags,  
    VARTYPE vtRet,  
    void* pvRet,  
    const BYTE* pbParamInfo, ...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwDispID`  
 Identifica a ID de expedição da propriedade ou método, encontrado no controle do `IDispatch` interface a ser invocado.  
  
 `wFlags`  
 Sinalizadores que descrevem o contexto da chamada para IDispatch:: Invoke. Para possível `wFlags` valores, consulte `IDispatch::Invoke` no SDK do Windows.  
  
 `vtRet`  
 Especifica o tipo do valor de retorno. Para os valores possíveis, consulte a seção comentários para [COleDispatchDriver::InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).  
  
 `pvRet`  
 Endereço da variável que receberá o valor da propriedade ou valor de retorno. Ele deve corresponder ao tipo especificado pelo `vtRet`.  
  
 `pbParamInfo`  
 Ponteiro para uma cadeia de caracteres terminada em nulo de bytes especificando os tipos dos parâmetros a seguir `pbParamInfo`. Para os valores possíveis, consulte a seção comentários para [COleDispatchDriver::InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).  
  
 *...*  
 A lista de variáveis de parâmetros de tipos especificados no `pbParamInfo`.  
  
### <a name="remarks"></a>Comentários  
 O `pbParamInfo` parâmetro especifica os tipos de parâmetros passados para o método ou propriedade. Lista de argumentos variável é representada por... na declaração da sintaxe.  
  
 Esta função converte os parâmetros a serem **VARIANTARG** valores e, em seguida, invoca o **IDispatch:: Invoke** método no controle. Se a chamada para **IDispatch:: Invoke** falhar, esta função lançará uma exceção. Se o código de status retornado pelo **IDispatch:: Invoke** é `DISP_E_EXCEPTION`, essa função lança um **COleDispatchException** objeto, caso contrário, ele lança um `COleException`.  
  
##  <a name="invokehelperv"></a>COleControlSite::InvokeHelperV  
 Invoca o método ou propriedade especificada pelo `dwDispID`, no contexto especificado pelos `wFlags`.  
  
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
 `dwDispID`  
 Identifica a ID de expedição da propriedade ou método, encontrado no controle do `IDispatch` interface a ser invocado.  
  
 `wFlags`  
 Sinalizadores que descrevem o contexto da chamada para IDispatch:: Invoke.  
  
 `vtRet`  
 Especifica o tipo do valor de retorno. Para os valores possíveis, consulte a seção comentários para [COleDispatchDriver::InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).  
  
 `pvRet`  
 Endereço da variável que receberá o valor da propriedade ou valor de retorno. Ele deve corresponder ao tipo especificado pelo `vtRet`.  
  
 `pbParamInfo`  
 Ponteiro para uma cadeia de caracteres terminada em nulo de bytes especificando os tipos dos parâmetros a seguir `pbParamInfo`. Para os valores possíveis, consulte a seção comentários para [COleDispatchDriver::InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).  
  
 `argList`  
 Ponteiro para uma lista de argumentos variável.  
  
### <a name="remarks"></a>Comentários  
 O `pbParamInfo` parâmetro especifica os tipos de parâmetros passados para o método ou propriedade. Parâmetros adicionais para o método ou propriedade que está sendo invocado podem ser passados usando o *va_list* parâmetro.  
  
 Normalmente, essa função é chamada `COleControlSite::InvokeHelper`.  
  
##  <a name="isdefaultbutton"></a>COleControlSite::IsDefaultButton  
 Determina se o controle é o botão padrão.  
  
```  
BOOL IsDefaultButton();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o controle é o botão padrão na janela, caso contrário, zero.  
  
##  <a name="iswindowenabled"></a>COleControlSite::IsWindowEnabled  
 Determina se o site de controle está habilitado.  
  
```  
virtual BOOL IsWindowEnabled() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o controle estiver habilitado, caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 O valor é recuperado da propriedade de estoque do controle habilitado.  
  
##  <a name="m_biswindowless"></a>COleControlSite::m_bIsWindowless  
 Determina se o objeto é um controle sem janelas.  
  
```  
BOOL m_bIsWindowless;  
```  
  
### <a name="remarks"></a>Comentários  
 Diferente de zero se o controle não tem nenhuma janela, caso contrário, zero.  
  
##  <a name="m_ctlinfo"></a>COleControlSite::m_ctlInfo  
 Obter informações sobre como a entrada do teclado é tratada pelo controle.  
  
```  
CONTROLINFO m_ctlInfo;  
```  
  
### <a name="remarks"></a>Comentários  
 Essas informações são armazenadas em um [CONTROLINFO](http://msdn.microsoft.com/library/windows/desktop/ms680734) estrutura.  
  
##  <a name="m_dweventsink"></a>COleControlSite::m_dwEventSink  
 Contém o cookie do ponto de conexão do coletor de eventos do controle.  
  
```  
DWORD m_dwEventSink;  
```  
  
##  <a name="m_dwmiscstatus"></a>COleControlSite::m_dwMiscStatus  
 Contém informações diversas sobre o controle.  
  
```  
DWORD m_dwMiscStatus;  
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [OLEMISC](http://msdn.microsoft.com/library/windows/desktop/ms678497)no SDK do Windows.  
  
##  <a name="m_dwpropnotifysink"></a>COleControlSite::m_dwPropNotifySink  
 Contém o [IPropertyNotifySink](http://msdn.microsoft.com/library/windows/desktop/ms692638) cookie.  
  
```  
DWORD m_dwPropNotifySink;  
```  
  
##  <a name="m_dwstyle"></a>COleControlSite::m_dwStyle  
 Contém os estilos de janela do controle.  
  
```  
DWORD m_dwStyle;  
```  
  
##  <a name="m_hwnd"></a>COleControlSite::m_hWnd  
 Contém o `HWND` do controle, ou **nulo** se o controle for sem janelas.  
  
```  
HWND m_hWnd;  
```  
  
##  <a name="m_iidevents"></a>COleControlSite::m_iidEvents  
 Contém a ID de interface da interface de coletor de eventos de padrão de controle.  
  
```  
IID m_iidEvents;  
```  
  
##  <a name="m_nid"></a>COleControlSite::m_nID  
 Contém a ID de item de caixa de diálogo. do controle  
  
```  
UINT m_nID;  
```  
  
##  <a name="m_pactiveobject"></a>COleControlSite::m_pActiveObject  
 Contém o [IOleInPlaceActiveObject](http://msdn.microsoft.com/library/windows/desktop/ms691299) interface do controle.  
  
```  
LPOLEINPLACEACTIVEOBJECT m_pActiveObject;  
```  
  
##  <a name="m_pctrlcont"></a>COleControlSite::m_pCtrlCont  
 Contém o contêiner do controle (que representa o formulário).  
  
```  
COleControlContainer* m_pCtrlCont;  
```  
  
##  <a name="m_pinplaceobject"></a>COleControlSite::m_pInPlaceObject  
 Contém o `IOleInPlaceObject` [IOleInPlaceObject](http://msdn.microsoft.com/library/windows/desktop/ms692646) interface do controle.  
  
```  
LPOLEINPLACEOBJECT m_pInPlaceObject;  
```  
  
##  <a name="m_pobject"></a>COleControlSite::m_pObject  
 Contém o **IOleObjectInterface** interface do controle.  
  
```  
LPOLEOBJECT m_pObject;  
```  
  
##  <a name="m_pwindowlessobject"></a>COleControlSite::m_pWindowlessObject  
 Contém o `IOleInPlaceObjectWindowless` [IOleInPlaceObjectWindowless](http://msdn.microsoft.com/library/windows/desktop/ms687304) interface do controle.  
  
```  
IOleInPlaceObjectWindowless* m_pWindowlessObject;  
```  
  
##  <a name="m_pwndctrl"></a>COleControlSite::m_pWndCtrl  
 Contém um ponteiro para o `CWnd` objeto que representa o controle em si.  
  
```  
CWnd* m_pWndCtrl;  
```  
  
##  <a name="m_rect"></a>COleControlSite::m_rect  
 Contém os limites do controle, relativa à janela do contêiner.  
  
```  
CRect m_rect;  
```  
  
##  <a name="modifystyle"></a>COleControlSite::ModifyStyle  
 Modifica os estilos de controle.  
  
```  
virtual BOOL ModifyStyle(
    DWORD dwRemove,  
    DWORD dwAdd,  
    UINT nFlags);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwRemove`  
 Os estilos a ser removido dos estilos da janela atual.  
  
 `dwAdd`  
 Os estilos a ser adicionado a estilos de janela atual.  
  
 `nFlags`  
 Sinalizadores de posicionamento de janela. Para obter uma lista de valores possíveis, consulte o [SetWindowPos](http://msdn.microsoft.com/library/windows/desktop/ms633545) função no SDK do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se os estilos forem alteradas, caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Propriedade Enabled de estoque do controle será modificado para corresponder à configuração de **WS_DISABLED**. Propriedade de estilo da borda do controle estoque será modificada para coincidir com a configuração solicitada para `WS_BORDER`. Todos os outros estilos são aplicados diretamente para o identificador de janela do controle, se houver.  
  
 Modifica os estilos de janela do controle. Estilos que devem ser adicionados ou removidos podem ser combinados usando o OR bit a bit (&#124;) operador. Consulte o [CreateWindow](http://msdn.microsoft.com/library/windows/desktop/ms632679) função no SDK do Windows para obter informações sobre os estilos de janela disponível.  
  
 Se `nFlags` é diferente de zero, `ModifyStyle` chama a função Win32 `SetWindowPos`e redesenhar a janela combinando `nFlags` com quatro sinalizadores a seguir:  
  
- `SWP_NOSIZE`Mantém o tamanho atual.  
  
- `SWP_NOMOVE`Retém a posição atual.  
  
- `SWP_NOZORDER`Retém a ordem Z atual.  
  
- `SWP_NOACTIVATE`Não ative a janela.  
  
 Para modificar uma janela estendidos do estilos, chame [ModifyStyleEx](#modifystyleex).  
  
##  <a name="modifystyleex"></a>COleControlSite::ModifyStyleEx  
 Modifica os estilos estendidos do controle.  
  
```  
virtual BOOL ModifyStyleEx(
    DWORD dwRemove,  
    DWORD dwAdd,  
    UINT nFlags);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwRemove`  
 Os estilos estendidos a ser removido dos estilos da janela atual.  
  
 `dwAdd`  
 Os estilos estendidos a serem adicionados a estilos de janela atual.  
  
 `nFlags`  
 Sinalizadores de posicionamento de janela. Para obter uma lista de valores possíveis, consulte o [SetWindowPos](http://msdn.microsoft.com/library/windows/desktop/ms633545) função no SDK do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se os estilos forem alteradas, caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 A propriedade do controle estoque aparência será modificada para corresponder à configuração de **WS_EX_CLIENTEDGE**. Todos os outros estilos de janela estendidos são aplicados diretamente para o identificador de janela do controle, se houver.  
  
 Modifica a janela estendidos estilos do objeto de controle do site. Estilos que devem ser adicionados ou removidos podem ser combinados usando o OR bit a bit (&#124;) operador. Consulte o [CreateWindowEx](http://msdn.microsoft.com/library/windows/desktop/ms632680) função no SDK do Windows para obter informações sobre os estilos de janela disponível.  
  
 Se `nFlags` é diferente de zero, `ModifyStyleEx` chama a função Win32 `SetWindowPos`e redesenhar a janela combinando `nFlags` com quatro sinalizadores a seguir:  
  
- `SWP_NOSIZE`Mantém o tamanho atual.  
  
- `SWP_NOMOVE`Retém a posição atual.  
  
- `SWP_NOZORDER`Retém a ordem Z atual.  
  
- `SWP_NOACTIVATE`Não ative a janela.  
  
 Para modificar uma janela estendidos do estilos, chame [ModifyStyle](#modifystyle).  
  
##  <a name="movewindow"></a>COleControlSite::MoveWindow  
 Altera a posição do controle.  
  
```  
virtual void MoveWindow(
    int x,  
    int y,  
    int nWidth,  
    int nHeight);
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 A nova posição do lado esquerdo da janela.  
  
 *y*  
 A nova posição na parte superior da janela.  
  
 `nWidth`  
 A nova largura da janela  
  
 `nHeight`  
 A nova altura da janela.  
  
##  <a name="quickactivate"></a>COleControlSite::QuickActivate  
 Rápida ativa o controle independente.  
  
```  
virtual BOOL QuickActivate();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o site de controle foi ativado, caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Essa função deve ser chamada somente se o usuário está substituindo o processo de criação do controle.  
  
 O `IPersist*::Load` e `IPersist*::InitNew` métodos devem ser chamados após a ativação rápida. O controle deve estabelecer suas conexões com coletores do contêiner durante a ativação rápida. No entanto, essas conexões não são em tempo real até `IPersist*::Load` ou `IPersist*::InitNew` foi chamado.  
  
##  <a name="safesetproperty"></a>COleControlSite::SafeSetProperty  
 Define a propriedade do controle especificada pelo `dwDispID`.  
  
```  
virtual BOOL AFX_CDECL SafeSetProperty(
    DISPID dwDispID,  
    VARTYPE vtProp, ...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwDispID`  
 Identifica a ID de expedição da propriedade ou método, encontrado no controle do `IDispatch` interface a ser definido.  
  
 `vtProp`  
 Especifica o tipo de propriedade a ser definida. Para os valores possíveis, consulte a seção comentários para [COleDispatchDriver::InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).  
  
 *...*  
 Um único parâmetro do tipo especificado pelo `vtProp`.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Ao contrário de `SetProperty` e `SetPropertyV`, se um erro for encontrado (por exemplo, a tentativa de definir uma propriedade que não existe), nenhuma exceção é lançada.  
  
##  <a name="setdefaultbutton"></a>COleControlSite::SetDefaultButton  
 Define o controle como botão padrão.  
  
```  
void SetDefaultButton(BOOL bDefault);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bDefault`  
 Diferente de zero se o controle deve se tornar o botão padrão; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  O controle deve ter o **OLEMISC_ACTSLIKEBUTTON** conjunto de bits de status.  
  
##  <a name="setdlgctrlid"></a>COleControlSite::SetDlgCtrlID  
 Altera o valor do identificador de item de caixa de diálogo do controle.  
  
```  
virtual int SetDlgCtrlID(int nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 O novo valor de identificador.  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, a caixa de diálogo anterior item identificador da janela. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setfocus"></a>COleControlSite::SetFocus  
 Define o foco para o controle.  
  
```  
virtual CWnd* SetFocus();  
virtual CWnd* SetFocus(LPMSG lpmsg);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpmsg*  
 Um ponteiro para um [estrutura MSG](../../mfc/reference/msg-structure1.md). Essa estrutura contém o disparo de mensagem do Windows a `SetFocus` solicitação para o controle no site atual do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a janela que tinha o foco.  
  
##  <a name="setproperty"></a>COleControlSite::SetProperty  
 Define a propriedade do controle especificada pelo `dwDispID`.  
  
```  
virtual void AFX_CDECL SetProperty(
    DISPID dwDispID,  
    VARTYPE vtProp, ...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwDispID`  
 Identifica a ID de expedição da propriedade ou método, encontrado no controle do `IDispatch` interface a ser definido.  
  
 `vtProp`  
 Especifica o tipo de propriedade a ser definida. Para os valores possíveis, consulte a seção comentários para [COleDispatchDriver::InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).  
  
 *...*  
 Um único parâmetro do tipo especificado pelo `vtProp`.  
  
### <a name="remarks"></a>Comentários  
 Se `SetProperty` encontra um erro, uma exceção será lançada.  
  
 O tipo de exceção é determinado pelo valor de retorno da tentativa de definir a propriedade ou método. Se o valor de retorno é `DISP_E_EXCEPTION`, um **COleDispatchExcpetion** for lançado; caso contrário, um `COleException`.  
  
##  <a name="setpropertyv"></a>COleControlSite::SetPropertyV  
 Define a propriedade do controle especificada pelo `dwDispID`.  
  
```  
virtual void SetPropertyV(
    DISPID dwDispID,  
    VARTYPE vtProp,  
    va_list argList);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwDispID`  
 Identifica a ID de expedição da propriedade ou método, encontrado no controle do `IDispatch` interface a ser definido.  
  
 `vtProp`  
 Especifica o tipo de propriedade a ser definida. Para os valores possíveis, consulte a seção comentários para [COleDispatchDriver::InvokeHelper](../../mfc/reference/coledispatchdriver-class.md#invokehelper).  
  
 `argList`  
 Ponteiro para a lista de argumentos.  
  
### <a name="remarks"></a>Comentários  
 Parâmetros adicionais para o método ou propriedade que está sendo invocado podem ser passeed usando o *arg_list* parâmetro. Se `SetProperty` encontra um erro, uma exceção será lançada.  
  
 O tipo de exceção é determinado pelo valor de retorno da tentativa de definir a propriedade ou método. Se o valor de retorno é `DISP_E_EXCEPTION`, um **COleDispatchExcpetion** for lançado; caso contrário, um `COleException`.  
  
##  <a name="setwindowpos"></a>COleControlSite::SetWindowPos  
 Define o tamanho, posição e ordem Z do site de controle.  
  
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
 `pWndInsertAfter`  
 Um ponteiro para a janela.  
  
 *x*  
 A nova posição do lado esquerdo da janela.  
  
 *y*  
 A nova posição na parte superior da janela.  
  
 `cx`  
 A nova largura da janela  
  
 `cy`  
 A nova altura da janela.  
  
 `nFlags`  
 Especifica a janela de dimensionamento e o posicionamento de sinalizadores. Para os valores possíveis, consulte a seção comentários para [SetWindowPos](http://msdn.microsoft.com/library/windows/desktop/ms633545) no SDK do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedido, caso contrário, zero.  
  
##  <a name="setwindowtext"></a>COleControlSite::SetWindowText  
 Define o texto para o site de controle.  
  
```  
virtual void SetWindowText(LPCTSTR lpszString);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszString`  
 Ponteiro para uma cadeia de caracteres terminada em nulo a ser usado como o novo texto do título ou controle.  
  
### <a name="remarks"></a>Comentários  
 Essa função primeiro tenta definir a propriedade de estoque de legenda. Se não há suporte para a propriedade de estoque de legenda, a propriedade Text é definida em vez disso.  
  
##  <a name="showwindow"></a>COleControlSite::ShowWindow  
 Define o estado de Mostrar da janela.  
  
```  
virtual BOOL ShowWindow(int nCmdShow);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nCmdShow`  
 Especifica como o site de controle deve ser mostrado. Ele deve ser um dos seguintes valores:  
  
- **SW_HIDE** oculta essa janela e passa a ativação para outra janela.  
  
- **SW_MINIMIZE** minimiza a janela e ativa a janela de nível superior na lista do sistema.  
  
- **SW_RESTORE** ativa e exibe a janela. Se a janela está minimizada ou maximizada, o Windows restaurá-lo em seu tamanho e posição original.  
  
- **SW_SHOW** ativa a janela e exibe-o em sua posição e tamanho atual.  
  
- **SW_SHOWMAXIMIZED** ativa a janela e exibe uma janela maximizada.  
  
- **SW_SHOWMINIMIZED** ativa a janela e exibe-o como um ícone.  
  
- **SW_SHOWMINNOACTIVE** exibe a janela como um ícone. A janela ativa no momento permanece ativa.  
  
- **SW_SHOWNA** exibe a janela em seu estado atual. A janela ativa no momento permanece ativa.  
  
- **SW_SHOWNOACTIVATE** exibe a janela em seu tamanho e posição mais recentes. A janela ativa no momento permanece ativa.  
  
- **SW_SHOWNORMAL** ativa e exibe a janela. Se a janela está minimizada ou maximizada, o Windows restaurá-lo em seu tamanho e posição original.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a janela foi anteriormente visível; 0 se a janela anteriormente oculto.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleControlContainer](../../mfc/reference/colecontrolcontainer-class.md)
