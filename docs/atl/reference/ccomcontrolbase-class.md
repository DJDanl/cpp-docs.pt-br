---
title: Classe CComControlBase | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComControlBase
- ATL.CComControlBase
- ATL::CComControlBase
dev_langs:
- C++
helpviewer_keywords:
- CComControlBase class
ms.assetid: 3d1bf022-acf2-4092-8283-ff8cee6332f3
caps.latest.revision: 20
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 988528a3658dee930df2cac6fd1a4add87302509
ms.lasthandoff: 02/25/2017

---
# <a name="ccomcontrolbase-class"></a>Classe CComControlBase
Essa classe fornece métodos para criar e gerenciar controles da ATL.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class ATL_NO_VTABLE CComControlBase
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComControlBase::AppearanceType](#appearancetype)|Substituir se o `m_nAppearance` propriedade de estoque não é do tipo `short`.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComControlBase::CComControlBase](#ccomcontrolbase)|O construtor.|  
|[CComControlBase:: ~ CComControlBase](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComControlBase::ControlQueryInterface](#controlqueryinterface)|Recupera um ponteiro para a interface solicitada.|  
|[CComControlBase::DoesVerbActivate](#doesverbactivate)|Verifica se o `iVerb` parâmetro usado pelo `IOleObjectImpl::DoVerb` uma interface do usuário do controle é ativado ( `iVerb` é igual a `OLEIVERB_UIACTIVATE`), define a ação executada quando o usuário clica duas vezes no controle ( `iVerb` é igual a `OLEIVERB_PRIMARY`), que exibe o controle ( `iVerb` é igual a `OLEIVERB_SHOW`), ou ativa o controle ( `iVerb` é igual a **OLEIVERB_INPLACEACTIVATE**).|  
|[CComControlBase::DoesVerbUIActivate](#doesverbuiactivate)|Verifica se o `iVerb` parâmetro usado pelo `IOleObjectImpl::DoVerb` faz com que a interface do usuário do controle ativar e retorna **TRUE**.|  
|[CComControlBase::DoVerbProperties](#doverbproperties)|Exibe as páginas de propriedade do controle.|  
|[CComControlBase::FireViewChange](#fireviewchange)|Chame esse método para instruir o contêiner para redesenhar o controle ou notificar os coletores advise registrado que alterou a exibição do controle.|  
|[CComControlBase::GetAmbientAppearance](#getambientappearance)|Recupera **DISPID_AMBIENT_APPEARANCE**, a aparência atual configuração do controle: 0 para simples e 1 para 3D.|  
|[CComControlBase::GetAmbientAutoClip](#getambientautoclip)|Recupera **DISPID_AMBIENT_AUTOCLIP**, um sinalizador que indica se o contêiner oferece suporte a corte automático da área de exibição de controle.|  
|[CComControlBase::GetAmbientBackColor](#getambientbackcolor)|Recupera **DISPID_AMBIENT_BACKCOLOR**, a cor de fundo de ambiente para todos os controles, definido pelo contêiner.|  
|[CComControlBase::GetAmbientCharSet](#getambientcharset)|Recupera **DISPID_AMBIENT_CHARSET**, definir o caractere de ambiente para todos os controles, definidos pelo contêiner.|  
|[CComControlBase::GetAmbientCodePage](#getambientcodepage)|Recupera **DISPID_AMBIENT_CODEPAGE**, definir o caractere de ambiente para todos os controles, definidos pelo contêiner.|  
|[CComControlBase::GetAmbientDisplayAsDefault](#getambientdisplayasdefault)|Recupera **DISPID_AMBIENT_DISPLAYASDEFAULT**, um sinalizador é **TRUE** se o contêiner tiver marcado o controle nesse site para ser um botão padrão e, portanto, um controle de botão deve desenhar a próprio um quadro mais espessa.|  
|[CComControlBase::GetAmbientDisplayName](#getambientdisplayname)|Recupera **DISPID_AMBIENT_DISPLAYNAME**, o nome o contêiner foi fornecido para o controle.|  
|[CComControlBase::GetAmbientFont](#getambientfont)|Recupera um ponteiro para o contêiner do ambiente `IFont` interface.|  
|[CComControlBase::GetAmbientFontDisp](#getambientfontdisp)|Recupera um ponteiro para o contêiner do ambiente **IFontDisp** interface dispatch.|  
|[CComControlBase::GetAmbientForeColor](#getambientforecolor)|Recupera **DISPID_AMBIENT_FORECOLOR**, a cor de primeiro plano de ambiente para todos os controles, definido pelo contêiner.|  
|[CComControlBase::GetAmbientLocaleID](#getambientlocaleid)|Recupera **DISPID_AMBIENT_LOCALEID**, o identificador do idioma usado pelo contêiner.|  
|[CComControlBase::GetAmbientMessageReflect](#getambientmessagereflect)|Recupera **DISPID_AMBIENT_MESSAGEREFLECT**, um sinalizador que indica se o contêiner quer receber mensagens de janela (como `WM_DRAWITEM`) como eventos.|  
|[CComControlBase::GetAmbientPalette](#getambientpalette)|Recupera **DISPID_AMBIENT_PALETTE**, usado para acessar o contêiner `HPALETTE`.|  
|[CComControlBase::GetAmbientProperty](#getambientproperty)|Recupera a propriedade do contêiner especificada pelo `id`.|  
|[CComControlBase::GetAmbientRightToLeft](#getambientrighttoleft)|Recupera **DISPID_AMBIENT_RIGHTTOLEFT**, a direção na qual o conteúdo é exibido pelo contêiner.|  
|[CComControlBase::GetAmbientScaleUnits](#getambientscaleunits)|Recupera **DISPID_AMBIENT_SCALEUNITS**, unidades de ambiente do contêiner (como polegadas ou centímetros) para rotular os exibe.|  
|[CComControlBase::GetAmbientShowGrabHandles](#getambientshowgrabhandles)|Recupera **DISPID_AMBIENT_SHOWGRABHANDLES**, um sinalizador que indica se o contêiner permite que o controle exibir as alças de captura para si mesmo quando ativo.|  
|[CComControlBase::GetAmbientShowHatching](#getambientshowhatching)|Recupera **DISPID_AMBIENT_SHOWHATCHING**, um sinalizador que indica se o contêiner permite que o controle para exibir em si com um padrão hachurado quando a interface do usuário está ativo.|  
|[CComControlBase::GetAmbientSupportsMnemonics](#getambientsupportsmnemonics)|Recupera **DISPID_AMBIENT_SUPPORTSMNEMONICS**, um sinalizador que indica se o contêiner oferece suporte mnemônico do teclado.|  
|[CComControlBase::GetAmbientTextAlign](#getambienttextalign)|Recupera **DISPID_AMBIENT_TEXTALIGN**, o alinhamento de texto preferido pelo contêiner: 0 para o alinhamento geral (texto à direita, números à esquerda), 1 para alinhamento à esquerda, 2 para centralizar e 3 para alinhamento à direita.|  
|[CComControlBase::GetAmbientTopToBottom](#getambienttoptobottom)|Recupera **DISPID_AMBIENT_TOPTOBOTTOM**, a direção na qual o conteúdo é exibido pelo contêiner.|  
|[CComControlBase::GetAmbientUIDead](#getambientuidead)|Recupera **DISPID_AMBIENT_UIDEAD**, um sinalizador que indica se o contêiner quiser o controle para responder às ações de interface do usuário.|  
|[CComControlBase::GetAmbientUserMode](#getambientusermode)|Recupera **DISPID_AMBIENT_USERMODE**, um sinalizador que indica se o contêiner está no modo de execução ( **TRUE**) ou modo de design ( **FALSE**).|  
|[CComControlBase::GetDirty](#getdirty)|Retorna o valor do membro de dados `m_bRequiresSave`.|  
|[CComControlBase::GetZoomInfo](#getzoominfo)|Recupera a x e y valores do numerador e do denominador do fator de zoom para um controle ativado para ativação in-loco.|  
|[CComControlBase::InPlaceActivate](#inplaceactivate)|Faz com que o controle para fazer a transição do estado de inativo para qualquer estado o verbo em `iVerb` indica.|  
|[CComControlBase::InternalGetSite](#internalgetsite)|Chame esse método para consultar o site de controle de um ponteiro para a interface identificada.|  
|[CComControlBase::OnDraw](#ondraw)|Substitua este método para desenhar o controle.|  
|[CComControlBase::OnDrawAdvanced](#ondrawadvanced)|O padrão **OnDrawAdvanced** prepara um contexto de dispositivo normalizado para desenho, em seguida, chama sua classe de controle `OnDraw` método.|  
|[CComControlBase::OnKillFocus](#onkillfocus)|Verifica se o controle está ativo no local e possui um site válido do controle e informa o contêiner que o controle perdeu o foco.|  
|[CComControlBase::OnMouseActivate](#onmouseactivate)|Verifica se a interface do usuário está no modo de usuário e ativa o controle.|  
|[CComControlBase::OnPaint](#onpaint)|Prepara o contêiner para pintura, obtém a área do cliente do controle, em seguida, chama a classe de controle `OnDraw` método.|  
|[CComControlBase::OnSetFocus](#onsetfocus)|Verifica se o controle está ativo no local possui um site válido do controle e informa o contêiner do controle obteve o foco.|  
|[CComControlBase::PreTranslateAccelerator](#pretranslateaccelerator)|Substitui esse método para fornecer sua própria teclado manipuladores de acelerador.|  
|[CComControlBase::SendOnClose](#sendonclose)|Notifica o comunicado de todos os coletores registrados com o detentor de aviso que o controle foi fechado.|  
|[CComControlBase::SendOnDataChange](#sendondatachange)|Notifica o comunicado de todos os coletores registrados com o detentor de advise que os dados de controle mudou.|  
|[CComControlBase::SendOnRename](#sendonrename)|Notifica o comunicado de todos os coletores registrados com o detentor de aviso que o controle tem um novo identificador de origem.|  
|[CComControlBase::SendOnSave](#sendonsave)|Notifica o comunicado de todos os coletores registrados com o proprietário de aviso que o controle foi salvo.|  
|[CComControlBase::SendOnViewChange](#sendonviewchange)|Notifica que todos os registrados Coletores de consultoria que alterou a exibição do controle.|  
|[CComControlBase::SetControlFocus](#setcontrolfocus)|Define ou remove o foco do teclado para ou do controle.|  
|[CComControlBase::SetDirty](#setdirty)|Define o membro de dados `m_bRequiresSave` com o valor em `bDirty`.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComControlBase::m_bAutoSize](#m_bautosize)|Sinalizador que indica que o controle não pode ser qualquer outro tamanho.|  
|[CComControlBase::m_bDrawFromNatural](#m_bdrawfromnatural)|Sinalizador que indica que `IDataObjectImpl::GetData` e `CComControlBase::GetZoomInfo` deve definir o tamanho do controle de `m_sizeNatural` , em vez de `m_sizeExtent`.|  
|[CComControlBase::m_bDrawGetDataInHimetric](#m_bdrawgetdatainhimetric)|Sinalizador que indica que `IDataObjectImpl::GetData` deve usar unidades HIMETRIC e não em pixels, ao desenhar.|  
|[CComControlBase::m_bInPlaceActive](#m_binplaceactive)|Sinalizador que indica que o controle está ativo no local.|  
|[CComControlBase::m_bInPlaceSiteEx](#m_binplacesiteex)|Sinalizador que indica que o contêiner suporta o **IOleInPlaceSiteEx** interface e OCX96 controlam recursos, como controles sem janelas e cintilação.|  
|[CComControlBase::m_bNegotiatedWnd](#m_bnegotiatedwnd)|Sinalizador que indica se o controle tem negociado com o contêiner sobre o suporte para recursos de controle de OCX96 (como controles sem janelas e cintilação), e se o controle é em janelas ou sem janelas.|  
|[CComControlBase::m_bRecomposeOnResize](#m_brecomposeonresize)|Sinalizador que indica que o controle deseja recompor sua apresentação quando o contêiner altera o tamanho da exibição do controle.|  
|[CComControlBase::m_bRequiresSave](#m_brequiressave)|Sinalizador que indica que o controle foi alterado desde que foi salvo pela última vez.|  
|[CComControlBase::m_bResizeNatural](#m_bresizenatural)|Sinalizador que indica o controle deseja redimensionar sua extensão natural (seu tamanho físico fora de escala) quando o contêiner altera o tamanho da exibição do controle.|  
|[CComControlBase::m_bUIActive](#m_buiactive)|Sinalizador que indica a interface do usuário do controle, como menus e barras de ferramentas está ativo.|  
|[CComControlBase::m_bUsingWindowRgn](#m_busingwindowrgn)|Sinalizador que indica que o controle está usando a região da janela fornecido pelo contêiner.|  
|[CComControlBase::m_bWasOnceWindowless](#m_bwasoncewindowless)|Sinalizador que indica o controle foi sem janelas, mas pode ou não ser sem janela agora.|  
|[CComControlBase::m_bWindowOnly](#m_bwindowonly)|Sinalizador que indica que o controle deve ser em janelas, mesmo se o contêiner oferece suporte a controles sem janelas.|  
|[CComControlBase::m_bWndLess](#m_bwndless)|Sinalizador que indica que o controle for sem janelas.|  
|[CComControlBase::m_hWndCD](#m_hwndcd)|Contém uma referência para o identificador de janela associado ao controle.|  
|[CComControlBase::m_nFreezeEvents](#m_nfreezeevents)|Uma contagem do número de vezes que o contêiner congelou eventos (se recusa a aceitar eventos) sem um descongelar intermediário de eventos (aceitação de eventos).|  
|[CComControlBase::m_rcPos](#m_rcpos)|A posição em pixels do controle, expressada nas coordenadas do recipiente.|  
|[CComControlBase::m_sizeExtent](#m_sizeextent)|A extensão do controle em unidades HIMETRIC (cada unidade 0,01 milímetros) para uma exibição específica.|  
|[CComControlBase::m_sizeNatural](#m_sizenatural)|O tamanho físico do controle em unidades HIMETRIC (cada unidade é milímetro 0,01).|  
|[CComControlBase::m_spAdviseSink](#m_spadvisesink)|Um ponteiro direto para a conexão de consultoria no contêiner (o contêiner [IAdviseSink](http://msdn.microsoft.com/library/windows/desktop/ms692513)).|  
|[CComControlBase::m_spAmbientDispatch](#m_spambientdispatch)|A `CComDispatchDriver` objeto que permite recuperar e definir as propriedades do contêiner por meio de um `IDispatch` ponteiro.|  
|[CComControlBase::m_spClientSite](#m_spclientsite)|Um ponteiro para o site do cliente do controle no contêiner.|  
|[CComControlBase::m_spDataAdviseHolder](#m_spdataadviseholder)|Fornece que um padrão significa manter conexões comunicados entre objetos de dados e Coletores de aviso.|  
|[CComControlBase::m_spInPlaceSite](#m_spinplacesite)|Um ponteiro para o contêiner [IOleInPlaceSite](http://msdn.microsoft.com/library/windows/desktop/ms686586), [IOleInPlaceSiteEx](http://msdn.microsoft.com/library/windows/desktop/ms693461), ou [IOleInPlaceSiteWindowless](http://msdn.microsoft.com/library/windows/desktop/ms682300) ponteiro de interface.|  
|[CComControlBase::m_spOleAdviseHolder](#m_spoleadviseholder)|Fornece uma implementação padrão de uma maneira de manter conexões comunicados.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe fornece métodos para criar e gerenciar controles da ATL. [Classe CComControl](../../atl/reference/ccomcontrol-class.md) deriva de `CComControlBase`. Quando você cria um controle de controle padrão ou DHTML usando o Assistente de controle ATL, o assistente automaticamente irá derivar a classe de `CComControlBase`.  
  
 Para obter mais informações sobre como criar um controle, consulte o [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md). Para obter mais informações sobre os ATL Project Wizard, consulte o artigo [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
##  <a name="a-nameappearancetypea--ccomcontrolbaseappearancetype"></a><a name="appearancetype"></a>CComControlBase::AppearanceType  
 Substituir se o **m_nAppearance** propriedade de estoque não é do tipo **curto**.  
  
```
typedef short AppearanceType;
```  
  
### <a name="remarks"></a>Comentários  
 O Assistente de controle ATL adiciona **m_nAppearance** propriedade do tipo curto de estoque. Substituir `AppearanceType` se você usar um tipo de dados diferente.  
  
##  <a name="a-nameccomcontrolbasea--ccomcontrolbaseccomcontrolbase"></a><a name="ccomcontrolbase"></a>CComControlBase::CComControlBase  
 O construtor.  
  
```
CComControlBase(HWND& h);
```  
  
### <a name="parameters"></a>Parâmetros  
 `h`  
 O identificador para a janela associada ao controle.  
  
### <a name="remarks"></a>Comentários  
 Inicializa o tamanho do controle para 5080 X 5080 DÉCIMOS de milímetros (2x "2") e inicializa o `CComControlBase` valores membro de dados **nulo** ou **FALSE**.  
  
##  <a name="a-namedtora--ccomcontrolbaseccomcontrolbase"></a><a name="dtor"></a>CComControlBase:: ~ CComControlBase  
 O destruidor.  
  
```
~CComControlBase();
```  
  
### <a name="remarks"></a>Comentários  
 Se o controle é em janelas, `~CComControlBase` destrói-lo chamando [DestroyWindow](http://msdn.microsoft.com/library/windows/desktop/ms632682).  
  
##  <a name="a-namecontrolqueryinterfacea--ccomcontrolbasecontrolqueryinterface"></a><a name="controlqueryinterface"></a>CComControlBase::ControlQueryInterface  
 Recupera um ponteiro para a interface solicitada.  
  
```
virtual HRESULT ControlQueryInterface(const IID& iid,
    void** ppv);
```  
  
### <a name="parameters"></a>Parâmetros  
 `iid`  
 O GUID da interface que está sendo solicitado.  
  
 `ppv`  
 Um ponteiro para o ponteiro de interface identificado pelo `iid`, ou **nulo** se a interface não for encontrada.  
  
### <a name="remarks"></a>Comentários  
 Apenas lida com interfaces na tabela de mapa COM.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_COM&15;](../../atl/codesnippet/cpp/ccomcontrolbase-class_1.cpp)]  
  
##  <a name="a-namedoesverbactivatea--ccomcontrolbasedoesverbactivate"></a><a name="doesverbactivate"></a>CComControlBase::DoesVerbActivate  
 Verifica se o `iVerb` parâmetro usado pelo `IOleObjectImpl::DoVerb` uma interface do usuário do controle é ativado ( `iVerb` é igual a `OLEIVERB_UIACTIVATE`), define a ação executada quando o usuário clica duas vezes no controle ( `iVerb` é igual a `OLEIVERB_PRIMARY`), que exibe o controle ( `iVerb` é igual a `OLEIVERB_SHOW`), ou ativa o controle ( `iVerb` é igual a **OLEIVERB_INPLACEACTIVATE**).  
  
```
BOOL DoesVerbActivate(LONG iVerb);
```  
  
### <a name="parameters"></a>Parâmetros  
 `iVerb`  
 Valor que indica a ação a ser executada pelo `DoVerb`.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** se `iVerb` é igual a `OLEIVERB_UIACTIVATE`, `OLEIVERB_PRIMARY`, `OLEIVERB_SHOW`, ou **OLEIVERB_INPLACEACTIVATE**; caso contrário, retorna **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Você pode substituir esse método para definir seu próprio verbo de ativação.  
  
##  <a name="a-namedoesverbuiactivatea--ccomcontrolbasedoesverbuiactivate"></a><a name="doesverbuiactivate"></a>CComControlBase::DoesVerbUIActivate  
 Verifica se o `iVerb` parâmetro usado pelo `IOleObjectImpl::DoVerb` faz com que a interface do usuário do controle ativar e retorna **TRUE**.  
  
```
BOOL DoesVerbUIActivate(LONG iVerb);
```  
  
### <a name="parameters"></a>Parâmetros  
 `iVerb`  
 Valor que indica a ação a ser executada pelo `DoVerb`.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** se `iVerb` é igual a `OLEIVERB_UIACTIVATE`, `OLEIVERB_PRIMARY`, `OLEIVERB_SHOW`, ou **OLEIVERB_INPLACEACTIVATE**. Caso contrário, o método retorna **FALSE**.  
  
##  <a name="a-namedoverbpropertiesa--ccomcontrolbasedoverbproperties"></a><a name="doverbproperties"></a>CComControlBase::DoVerbProperties  
 Exibe as páginas de propriedade do controle.  
  
```
HRESULT DoVerbProperties(LPCRECT /* prcPosRect */, HWND hwndParent);
```  
  
### <a name="parameters"></a>Parâmetros  
 `prcPosRec`  
 Reservado.  
  
 *hwndParent*  
 Identificador da janela que contém o controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_COM&19;](../../atl/codesnippet/cpp/ccomcontrolbase-class_2.cpp)]  
  
 [!code-cpp[NVC_ATL_COM&20;](../../atl/codesnippet/cpp/ccomcontrolbase-class_3.h)]  
  
##  <a name="a-namefireviewchangea--ccomcontrolbasefireviewchange"></a><a name="fireviewchange"></a>CComControlBase::FireViewChange  
 Chame esse método para instruir o contêiner para redesenhar o controle ou notificar os coletores advise registrado que alterou a exibição do controle.  
  
```
HRESULT FireViewChange();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
### <a name="remarks"></a>Comentários  
 Se o controle estiver ativo (o membro de dados da classe de controle [CComControlBase::m_bInPlaceActive](#m_binplaceactive) é **TRUE**), notifica o contêiner que deseja redesenhar todo o controle. Se o controle estiver inativo, notifica o controle do registrado Coletores de aviso (por meio do membro de dados de classe de controle [CComControlBase::m_spAdviseSink](#m_spadvisesink)) que alterou a exibição do controle.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_COM&#21;](../../atl/codesnippet/cpp/ccomcontrolbase-class_4.cpp)]  
  
##  <a name="a-namegetambientappearancea--ccomcontrolbasegetambientappearance"></a><a name="getambientappearance"></a>CComControlBase::GetAmbientAppearance  
 Recupera **DISPID_AMBIENT_APPEARANCE**, a aparência atual configuração do controle: 0 para simples e 1 para 3D.  
  
```
HRESULT GetAmbientAppearance(short& nAppearance);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nAppearance`  
 A propriedade **DISPID_AMBIENT_APPEARANCE**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_COM&#22;](../../atl/codesnippet/cpp/ccomcontrolbase-class_5.h)]  
  
##  <a name="a-namegetambientautoclipa--ccomcontrolbasegetambientautoclip"></a><a name="getambientautoclip"></a>CComControlBase::GetAmbientAutoClip  
 Recupera **DISPID_AMBIENT_AUTOCLIP**, um sinalizador que indica se o contêiner oferece suporte a corte automático da área de exibição de controle.  
  
```
HRESULT GetAmbientAutoClip(BOOL& bAutoClip);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bAutoClip*  
 A propriedade **DISPID_AMBIENT_AUTOCLIP**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
##  <a name="a-namegetambientbackcolora--ccomcontrolbasegetambientbackcolor"></a><a name="getambientbackcolor"></a>CComControlBase::GetAmbientBackColor  
 Recupera **DISPID_AMBIENT_BACKCOLOR**, a cor de fundo de ambiente para todos os controles, definido pelo contêiner.  
  
```
HRESULT GetAmbientBackColor(OLE_COLOR& BackColor);
```  
  
### <a name="parameters"></a>Parâmetros  
 *BackColor*  
 A propriedade **DISPID_AMBIENT_BACKCOLOR**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
##  <a name="a-namegetambientcharseta--ccomcontrolbasegetambientcharset"></a><a name="getambientcharset"></a>CComControlBase::GetAmbientCharSet  
 Recupera **DISPID_AMBIENT_CHARSET**, definir o caractere de ambiente para todos os controles, definidos pelo contêiner.  
  
```
HRESULT GetAmbientCharSet(BSTR& bstrCharSet);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bstrCharSet*  
 A propriedade **DISPID_AMBIENT_CHARSET**.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="a-namegetambientcodepagea--ccomcontrolbasegetambientcodepage"></a><a name="getambientcodepage"></a>CComControlBase::GetAmbientCodePage  
 Recupera **DISPID_AMBIENT_CODEPAGE**, a página de código de ambiente para todos os controles, definido pelo contêiner.  
  
```
HRESULT GetAmbientCodePage(ULONG& ulCodePage);
```  
  
### <a name="parameters"></a>Parâmetros  
 *ulCodePage*  
 A propriedade **DISPID_AMBIENT_CODEPAGE**.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="a-namegetambientdisplayasdefaulta--ccomcontrolbasegetambientdisplayasdefault"></a><a name="getambientdisplayasdefault"></a>CComControlBase::GetAmbientDisplayAsDefault  
 Recupera **DISPID_AMBIENT_DISPLAYASDEFAULT**, um sinalizador é **TRUE** se o contêiner tiver marcado o controle nesse site para ser um botão padrão e, portanto, um controle de botão deve desenhar a próprio um quadro mais espessa.  
  
```
HRESULT GetAmbientDisplayAsDefault(BOOL& bDisplayAsDefault);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bDisplayAsDefault`  
 A propriedade **DISPID_AMBIENT_DISPLAYASDEFAULT**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
##  <a name="a-namegetambientdisplaynamea--ccomcontrolbasegetambientdisplayname"></a><a name="getambientdisplayname"></a>CComControlBase::GetAmbientDisplayName  
 Recupera **DISPID_AMBIENT_DISPLAYNAME**, o nome o contêiner foi fornecido para o controle.  
  
```
HRESULT GetAmbientDisplayName(BSTR& bstrDisplayName);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bstrDisplayName*  
 A propriedade **DISPID_AMBIENT_DISPLAYNAME**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
##  <a name="a-namegetambientfonta--ccomcontrolbasegetambientfont"></a><a name="getambientfont"></a>CComControlBase::GetAmbientFont  
 Recupera um ponteiro para o contêiner do ambiente `IFont` interface.  
  
```
HRESULT GetAmbientFont(IFont** ppFont);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppFont`  
 Um ponteiro para o contêiner do ambiente [IFont](http://msdn.microsoft.com/library/windows/desktop/ms680673) interface.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
### <a name="remarks"></a>Comentários  
 Se a propriedade for **nulo**, o ponteiro é **nulo**. Se o ponteiro não é **nulo**, o chamador deve liberar o ponteiro.  
  
##  <a name="a-namegetambientfontdispa--ccomcontrolbasegetambientfontdisp"></a><a name="getambientfontdisp"></a>CComControlBase::GetAmbientFontDisp  
 Recupera um ponteiro para o contêiner do ambiente **IFontDisp** interface dispatch.  
  
```
HRESULT GetAmbientFontDisp(IFontDisp** ppFont);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppFont`  
 Um ponteiro para o contêiner do ambiente [IFontDisp](http://msdn.microsoft.com/library/windows/desktop/ms692695) interface dispatch.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Se a propriedade for **nulo**, o ponteiro é **nulo**. Se o ponteiro não é **nulo**, o chamador deve liberar o ponteiro.  
  
##  <a name="a-namegetambientforecolora--ccomcontrolbasegetambientforecolor"></a><a name="getambientforecolor"></a>CComControlBase::GetAmbientForeColor  
 Recupera **DISPID_AMBIENT_FORECOLOR**, a cor de primeiro plano de ambiente para todos os controles, definido pelo contêiner.  
  
```
HRESULT GetAmbientForeColor(OLE_COLOR& ForeColor);
```  
  
### <a name="parameters"></a>Parâmetros  
 *Cor de primeiro plano*  
 A propriedade **DISPID_AMBIENT_FORECOLOR**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
##  <a name="a-namegetambientlocaleida--ccomcontrolbasegetambientlocaleid"></a><a name="getambientlocaleid"></a>CComControlBase::GetAmbientLocaleID  
 Recupera **DISPID_AMBIENT_LOCALEID**, o identificador do idioma usado pelo contêiner.  
  
```
HRESULT GetAmbientLocaleID(LCID& lcid);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lcid`  
 A propriedade **DISPID_AMBIENT_LOCALEID**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
### <a name="remarks"></a>Comentários  
 O controle pode usar esse identificador para adaptar sua interface do usuário para idiomas diferentes.  
  
##  <a name="a-namegetambientmessagereflecta--ccomcontrolbasegetambientmessagereflect"></a><a name="getambientmessagereflect"></a>CComControlBase::GetAmbientMessageReflect  
 Recupera **DISPID_AMBIENT_MESSAGEREFLECT**, um sinalizador que indica se o contêiner quer receber mensagens de janela (como `WM_DRAWITEM`) como eventos.  
  
```
HRESULT GetAmbientMessageReflect(BOOL& bMessageReflect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bMessageReflect`  
 A propriedade **DISPID_AMBIENT_MESSAGEREFLECT**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
##  <a name="a-namegetambientpalettea--ccomcontrolbasegetambientpalette"></a><a name="getambientpalette"></a>CComControlBase::GetAmbientPalette  
 Recupera **DISPID_AMBIENT_PALETTE**, usado para acessar o contêiner `HPALETTE`.  
  
```
HRESULT GetAmbientPalette(HPALETTE& hPalette);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hPalette`  
 A propriedade **DISPID_AMBIENT_PALETTE**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
##  <a name="a-namegetambientpropertya--ccomcontrolbasegetambientproperty"></a><a name="getambientproperty"></a>CComControlBase::GetAmbientProperty  
 Recupera a propriedade do contêiner especificada pelo `dispid`.  
  
```
HRESULT GetAmbientProperty(DISPID dispid, VARIANT& var);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dispid`  
 Identificador da propriedade contêiner a ser recuperado.  
  
 `var`  
 Variável para receber a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
### <a name="remarks"></a>Comentários  
 ATL fornece um conjunto de funções auxiliares para recuperar propriedades específicas, por exemplo, [CComControlBase::GetAmbientBackColor](#getambientbackcolor). Se não houver nenhum método adequado disponível, use `GetAmbientProperty`.  
  
##  <a name="a-namegetambientrighttolefta--ccomcontrolbasegetambientrighttoleft"></a><a name="getambientrighttoleft"></a>CComControlBase::GetAmbientRightToLeft  
 Recupera **DISPID_AMBIENT_RIGHTTOLEFT**, a direção na qual o conteúdo é exibido pelo contêiner.  
  
```
HRESULT GetAmbientRightToLeft(BOOL& bRightToLeft);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bRightToLeft*  
 A propriedade **DISPID_AMBIENT_RIGHTTOLEFT**. Definido como **TRUE** se o conteúdo é exibido à direita para a esquerda, **FALSE** se ele é exibido à esquerda para a direita.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="a-namegetambientscaleunitsa--ccomcontrolbasegetambientscaleunits"></a><a name="getambientscaleunits"></a>CComControlBase::GetAmbientScaleUnits  
 Recupera **DISPID_AMBIENT_SCALEUNITS**, unidades de ambiente do contêiner (como polegadas ou centímetros) para rotular os exibe.  
  
```
HRESULT GetAmbientScaleUnits(BSTR& bstrScaleUnits);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bstrScaleUnits*  
 A propriedade **DISPID_AMBIENT_SCALEUNITS**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
##  <a name="a-namegetambientshowgrabhandlesa--ccomcontrolbasegetambientshowgrabhandles"></a><a name="getambientshowgrabhandles"></a>CComControlBase::GetAmbientShowGrabHandles  
 Recupera **DISPID_AMBIENT_SHOWGRABHANDLES**, um sinalizador que indica se o contêiner permite que o controle exibir as alças de captura para si mesmo quando ativo.  
  
```
HRESULT GetAmbientShowGrabHandles(BOOL& bShowGrabHandles);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bShowGrabHandles*  
 A propriedade **DISPID_AMBIENT_SHOWGRABHANDLES**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
##  <a name="a-namegetambientshowhatchinga--ccomcontrolbasegetambientshowhatching"></a><a name="getambientshowhatching"></a>CComControlBase::GetAmbientShowHatching  
 Recupera **DISPID_AMBIENT_SHOWHATCHING**, um sinalizador que indica se o contêiner permite que o controle exibir em si com um padrão hachurado quando a interface de usuário do controle está ativa.  
  
```
HRESULT GetAmbientShowHatching(BOOL& bShowHatching);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bShowHatching*  
 A propriedade **DISPID_AMBIENT_SHOWHATCHING**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
##  <a name="a-namegetambientsupportsmnemonicsa--ccomcontrolbasegetambientsupportsmnemonics"></a><a name="getambientsupportsmnemonics"></a>CComControlBase::GetAmbientSupportsMnemonics  
 Recupera **DISPID_AMBIENT_SUPPORTSMNEMONICS**, um sinalizador que indica se o contêiner oferece suporte mnemônico do teclado.  
  
```
HRESULT GetAmbientSupportsMnemonics(BOOL& bSupportsMnemonics);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bSupportsMnemonics*  
 A propriedade **DISPID_AMBIENT_SUPPORTSMNEMONICS**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
##  <a name="a-namegetambienttextaligna--ccomcontrolbasegetambienttextalign"></a><a name="getambienttextalign"></a>CComControlBase::GetAmbientTextAlign  
 Recupera **DISPID_AMBIENT_TEXTALIGN**, o alinhamento de texto preferido pelo contêiner: 0 para o alinhamento geral (texto à direita, números à esquerda), 1 para alinhamento à esquerda, 2 para centralizar e 3 para alinhamento à direita.  
  
```
HRESULT GetAmbientTextAlign(short& nTextAlign);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nTextAlign*  
 A propriedade **DISPID_AMBIENT_TEXTALIGN**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
##  <a name="a-namegetambienttoptobottoma--ccomcontrolbasegetambienttoptobottom"></a><a name="getambienttoptobottom"></a>CComControlBase::GetAmbientTopToBottom  
 Recupera **DISPID_AMBIENT_TOPTOBOTTOM**, a direção na qual o conteúdo é exibido pelo contêiner.  
  
```
HRESULT GetAmbientTopToBottom(BOOL& bTopToBottom);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bTopToBottom*  
 A propriedade **DISPID_AMBIENT_TOPTOBOTTOM**. Definido como **TRUE** se o texto é exibido cima para baixo, **FALSE** se ele for exibido baixo para cima.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="a-namegetambientuideada--ccomcontrolbasegetambientuidead"></a><a name="getambientuidead"></a>CComControlBase::GetAmbientUIDead  
 Recupera **DISPID_AMBIENT_UIDEAD**, um sinalizador que indica se o contêiner quiser o controle para responder às ações de interface do usuário.  
  
```
HRESULT GetAmbientUIDead(BOOL& bUIDead);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bUIDead*  
 A propriedade **DISPID_AMBIENT_UIDEAD**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
### <a name="remarks"></a>Comentários  
 Se **TRUE**, o controle não deve responder. Esse sinalizador se aplica independentemente do **DISPID_AMBIENT_USERMODE** sinalizador. Consulte [CComControlBase::GetAmbientUserMode](#getambientusermode).  
  
##  <a name="a-namegetambientusermodea--ccomcontrolbasegetambientusermode"></a><a name="getambientusermode"></a>CComControlBase::GetAmbientUserMode  
 Recupera **DISPID_AMBIENT_USERMODE**, um sinalizador que indica se o contêiner está no modo de execução ( **TRUE**) ou modo de design ( **FALSE**).  
  
```
HRESULT GetAmbientUserMode(BOOL& bUserMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bUserMode`  
 A propriedade **DISPID_AMBIENT_USERMODE**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
##  <a name="a-namegetdirtya--ccomcontrolbasegetdirty"></a><a name="getdirty"></a>CComControlBase::GetDirty  
 Retorna o valor do membro de dados `m_bRequiresSave`.  
  
```
BOOL GetDirty();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor do membro de dados [m_bRequiresSave](#m_brequiressave).  
  
### <a name="remarks"></a>Comentários  
 Esse valor é definido usando [CComControlBase::SetDirty](#setdirty).  
  
##  <a name="a-namegetzoominfoa--ccomcontrolbasegetzoominfo"></a><a name="getzoominfo"></a>CComControlBase::GetZoomInfo  
 Recupera a x e y valores do numerador e do denominador do fator de zoom para um controle ativado para ativação in-loco.  
  
```
void GetZoomInfo(ATL_DRAWINFO& di);
```  
  
### <a name="parameters"></a>Parâmetros  
 `di`  
 A estrutura que irá conter o numerador e do denominador o fator de zoom. Para obter mais informações, consulte [ATL_DRAWINFO](../../atl/reference/atl-drawinfo-structure.md).  
  
### <a name="remarks"></a>Comentários  
 O fator de zoom é a proporção de tamanho natural do controle sua extensão atual.  
  
##  <a name="a-nameinplaceactivatea--ccomcontrolbaseinplaceactivate"></a><a name="inplaceactivate"></a>CComControlBase::InPlaceActivate  
 Faz com que o controle para fazer a transição do estado de inativo para qualquer estado o verbo em `iVerb` indica.  
  
```
HRESULT InPlaceActivate(LONG iVerb, const RECT* prcPosRect = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `iVerb`  
 Valor que indica a ação a ser executada por [IOleObjectImpl::DoVerb](../../atl/reference/ioleobjectimpl-class.md#doverb).  
  
 *prcPosRect*  
 Ponteiro para a posição do controle no local.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
### <a name="remarks"></a>Comentários  
 Antes da ativação, esse método verifica se o controle tiver um site do cliente, verifica quanto o controle está visível e obtém a localização do controle na janela pai. Depois que o controle é ativado, esse método ativa a interface do usuário do controle e informa o contêiner para tornar o controle visível.  
  
 Esse método também recupera um `IOleInPlaceSite`, **IOleInPlaceSiteEx**, ou **IOleInPlaceSiteWindowless** ponteiro de interface para o controle e o armazena no membro de dados da classe de controle [CComControlBase::m_spInPlaceSite](#m_spinplacesite). Os membros de dados de classe de controle [CComControlBase::m_bInPlaceSiteEx](#m_binplacesiteex), [CComControlBase::m_bWndLess](#m_bwndless), [CComControlBase::m_bWasOnceWindowless](#m_bwasoncewindowless), e [CComControlBase::m_bNegotiatedWnd](#m_bnegotiatedwnd) definido como true conforme apropriado.  
  
##  <a name="a-nameinternalgetsitea--ccomcontrolbaseinternalgetsite"></a><a name="internalgetsite"></a>CComControlBase::InternalGetSite  
 Chame esse método para consultar o site de controle de um ponteiro para a interface identificada.  
  
```
HRESULT InternalGetSite(REFIID riid, void** ppUnkSite);
```  
  
### <a name="parameters"></a>Parâmetros  
 `riid`  
 O IID do ponteiro de interface que deve ser retornado em `ppUnkSite`.  
  
 `ppUnkSite`  
 Endereço da variável de ponteiro que recebe o ponteiro de interface solicitado em `riid`.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Se o site oferece suporte à interface solicitada na `riid`, o ponteiro é retornado por meio de `ppUnkSite`. Caso contrário, `ppUnkSite` é definido como NULL.  
  
##  <a name="a-namembautosizea--ccomcontrolbasembautosize"></a><a name="m_bautosize"></a>CComControlBase::m_bAutoSize  
 Sinalizador que indica que o controle não pode ser qualquer outro tamanho.  
  
```
unsigned m_bAutoSize:1;
```  
  
### <a name="remarks"></a>Comentários  
 Esse sinalizador é verificado pela `IOleObjectImpl::SetExtent` e, se **TRUE**, faz com que a função retorne **E_FAIL**.  
  
> [!NOTE]
>  Para usar esse membro de dados em sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma união na classe base.  
  
 Se você adicionar o **AutoDimensionar** opção o [propriedades de estoque](../../atl/reference/stock-properties-atl-control-wizard.md) guia do Assistente de controle ATL, o assistente automaticamente cria esse membro de dados em sua classe de controle, cria put e métodos get de propriedade e oferece suporte a [IPropertyNotifySink](http://msdn.microsoft.com/library/windows/desktop/ms692638) para notificar o contêiner automaticamente quando a propriedade é alterada.  
  
##  <a name="a-namembdrawfromnaturala--ccomcontrolbasembdrawfromnatural"></a><a name="m_bdrawfromnatural"></a>CComControlBase::m_bDrawFromNatural  
 Sinalizador que indica que `IDataObjectImpl::GetData` e `CComControlBase::GetZoomInfo` deve definir o tamanho do controle de `m_sizeNatural` , em vez de `m_sizeExtent`.  
  
```
unsigned m_bDrawFromNatural:1;
```  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Para usar esse membro de dados em sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma união na classe base.  
  
##  <a name="a-namembdrawgetdatainhimetrica--ccomcontrolbasembdrawgetdatainhimetric"></a><a name="m_bdrawgetdatainhimetric"></a>CComControlBase::m_bDrawGetDataInHimetric  
 Sinalizador que indica que `IDataObjectImpl::GetData` deve usar unidades HIMETRIC e não em pixels, ao desenhar.  
  
```
unsigned m_bDrawGetDataInHimetric:1;
```  
  
### <a name="remarks"></a>Comentários  
 Cada unidade lógica de DÉCIMOS é corresponde a 0,01 milímetro.  
  
> [!NOTE]
>  Para usar esse membro de dados em sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma união na classe base.  
  
##  <a name="a-namembinplaceactivea--ccomcontrolbasembinplaceactive"></a><a name="m_binplaceactive"></a>CComControlBase::m_bInPlaceActive  
 Sinalizador que indica que o controle está ativo no local.  
  
```
unsigned m_bInPlaceActive:1;
```  
  
### <a name="remarks"></a>Comentários  
 Isso significa que o controle está visível e sua janela, se houver, está visível, mas seus menus e barras de ferramentas podem não estar ativas. O `m_bUIActive` sinalizador indica a interface de usuário do controle, como menus, também está ativo.  
  
> [!NOTE]
>  Para usar esse membro de dados em sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma união na classe base.  
  
##  <a name="a-namembinplacesiteexa--ccomcontrolbasembinplacesiteex"></a><a name="m_binplacesiteex"></a>CComControlBase::m_bInPlaceSiteEx  
 Sinalizador que indica que o contêiner suporta o **IOleInPlaceSiteEx** interface e OCX96 controlam recursos, como controles sem janelas e cintilação.  
  
```
unsigned m_bInPlaceSiteEx:1;
```  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Para usar esse membro de dados em sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma união na classe base.  
  
 O membro de dados `m_spInPlaceSite` aponta para um [IOleInPlaceSite](http://msdn.microsoft.com/library/windows/desktop/ms686586), [IOleInPlaceSiteEx](http://msdn.microsoft.com/library/windows/desktop/ms693461), ou [IOleInPlaceSiteWindowless](http://msdn.microsoft.com/library/windows/desktop/ms682300) interface, dependendo do valor da `m_bWndLess` e `m_bInPlaceSiteEx` sinalizadores. (O membro de dados `m_bNegotiatedWnd` deve ser **TRUE** para o `m_spInPlaceSite` ponteiro válido.)  
  
 Se `m_bWndLess` é **FALSE** e `m_bInPlaceSiteEx` é **TRUE**, `m_spInPlaceSite` é um **IOleInPlaceSiteEx** ponteiro de interface. Consulte [m_spInPlaceSite](#m_spinplacesite) para uma tabela que mostra a relação entre esses membros de dados de três.  
  
##  <a name="a-namembnegotiatedwnda--ccomcontrolbasembnegotiatedwnd"></a><a name="m_bnegotiatedwnd"></a>CComControlBase::m_bNegotiatedWnd  
 Sinalizador que indica se o controle tem negociado com o contêiner sobre o suporte para recursos de controle de OCX96 (como controles sem janelas e cintilação), e se o controle é em janelas ou sem janelas.  
  
```
unsigned m_bNegotiatedWnd:1;
```  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Para usar esse membro de dados em sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma união na classe base.  
  
 O `m_bNegotiatedWnd` sinalizador deve ser **TRUE** para o `m_spInPlaceSite` ponteiro válido.  
  
##  <a name="a-namembrecomposeonresizea--ccomcontrolbasembrecomposeonresize"></a><a name="m_brecomposeonresize"></a>CComControlBase::m_bRecomposeOnResize  
 Sinalizador que indica que o controle deseja recompor sua apresentação quando o contêiner altera o tamanho da exibição do controle.  
  
```
unsigned m_bRecomposeOnResize:1;
```  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Para usar esse membro de dados em sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma união na classe base.  
  
 Esse sinalizador é verificado pela [IOleObjectImpl::SetExtent](../../atl/reference/ioleobjectimpl-class.md#setextent) e, se **TRUE**, `SetExtent` notifica o contêiner de alterações de modo de exibição. Se esse sinalizador estiver definido, o **OLEMISC_RECOMPOSEONRESIZE** bit no [OLEMISC](http://msdn.microsoft.com/library/windows/desktop/ms678497) enumeração também deve ser definida.  
  
##  <a name="a-namembrequiressavea--ccomcontrolbasembrequiressave"></a><a name="m_brequiressave"></a>CComControlBase::m_bRequiresSave  
 Sinalizador que indica que o controle foi alterado desde que foi salvo pela última vez.  
  
```
unsigned m_bRequiresSave:1;
```  
  
### <a name="remarks"></a>Comentários  
 O valor de `m_bRequiresSave` podem ser definidas com [CComControlBase::SetDirty](#setdirty) e recuperados com [CComControlBase::GetDirty](#getdirty).  
  
> [!NOTE]
>  Para usar esse membro de dados em sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma união na classe base.  
  
##  <a name="a-namembresizenaturala--ccomcontrolbasembresizenatural"></a><a name="m_bresizenatural"></a>CComControlBase::m_bResizeNatural  
 Sinalizador que indica o controle deseja redimensionar sua extensão natural (seu tamanho físico fora de escala) quando o contêiner altera o tamanho da exibição do controle.  
  
```
unsigned m_bResizeNatural:1;
```  
  
### <a name="remarks"></a>Comentários  
 Esse sinalizador é verificado pela `IOleObjectImpl::SetExtent` e, se **TRUE**, o tamanho do passado para `SetExtent` é atribuído a `m_sizeNatural`.  
  
 O tamanho é passado para `SetExtent` sempre é atribuída ao `m_sizeExtent`, independentemente do valor de `m_bResizeNatural`.  
  
> [!NOTE]
>  Para usar esse membro de dados em sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma união na classe base.  
  
##  <a name="a-namembuiactivea--ccomcontrolbasembuiactive"></a><a name="m_buiactive"></a>CComControlBase::m_bUIActive  
 Sinalizador que indica a interface do usuário do controle, como menus e barras de ferramentas está ativo.  
  
```
unsigned m_bUIActive:1;
```  
  
### <a name="remarks"></a>Comentários  
 O `m_bInPlaceActive` sinalizador indica que o controle está ativo, mas não que sua interface do usuário está ativa.  
  
> [!NOTE]
>  Para usar esse membro de dados em sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma união na classe base.  
  
##  <a name="a-namembusingwindowrgna--ccomcontrolbasembusingwindowrgn"></a><a name="m_busingwindowrgn"></a>CComControlBase::m_bUsingWindowRgn  
 Sinalizador que indica que o controle está usando a região da janela fornecido pelo contêiner.  
  
```
unsigned m_bUsingWindowRgn:1;
```  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Para usar esse membro de dados em sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma união na classe base.  
  
##  <a name="a-namembwasoncewindowlessa--ccomcontrolbasembwasoncewindowless"></a><a name="m_bwasoncewindowless"></a>CComControlBase::m_bWasOnceWindowless  
 Sinalizador que indica o controle foi sem janelas, mas pode ou não ser sem janela agora.  
  
```
unsigned m_bWasOnceWindowless:1;
```  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Para usar esse membro de dados em sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma união na classe base.  
  
##  <a name="a-namembwindowonlya--ccomcontrolbasembwindowonly"></a><a name="m_bwindowonly"></a>CComControlBase::m_bWindowOnly  
 Sinalizador que indica que o controle deve ser em janelas, mesmo se o contêiner oferece suporte a controles sem janelas.  
  
```
unsigned m_bWindowOnly:1;
```  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Para usar esse membro de dados em sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma união na classe base.  
  
##  <a name="a-namembwndlessa--ccomcontrolbasembwndless"></a><a name="m_bwndless"></a>CComControlBase::m_bWndLess  
 Sinalizador que indica que o controle for sem janelas.  
  
```
unsigned m_bWndLess:1;
```  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Para usar esse membro de dados em sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma união na classe base.  
  
 O membro de dados `m_spInPlaceSite` aponta para um [IOleInPlaceSite](http://msdn.microsoft.com/library/windows/desktop/ms686586), [IOleInPlaceSiteEx](http://msdn.microsoft.com/library/windows/desktop/ms693461), ou [IOleInPlaceSiteWindowless](http://msdn.microsoft.com/library/windows/desktop/ms682300) interface, dependendo do valor da `m_bWndLess` e [CComControlBase::m_bInPlaceSiteEx](#m_binplacesiteex) sinalizadores. (O membro de dados [CComControlBase::m_bNegotiatedWnd](#m_bnegotiatedwnd) deve ser **TRUE** para o [CComControlBase::m_spInPlaceSite](#m_spinplacesite) ponteiro válido.)  
  
 Se `m_bWndLess` é **TRUE**, `m_spInPlaceSite` é um **IOleInPlaceSiteWindowless** ponteiro de interface. Consulte [CComControlBase::m_spInPlaceSite](#m_spinplacesite) para uma tabela que mostra a relação completa entre esses membros de dados.  
  
##  <a name="a-namemhwndcda--ccomcontrolbasemhwndcd"></a><a name="m_hwndcd"></a>CComControlBase::m_hWndCD  
 Contém uma referência para o identificador de janela associado ao controle.  
  
```
HWND& m_hWndCD;
```  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Para usar esse membro de dados em sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma união na classe base.  
  
##  <a name="a-namemnfreezeeventsa--ccomcontrolbasemnfreezeevents"></a><a name="m_nfreezeevents"></a>CComControlBase::m_nFreezeEvents  
 Uma contagem do número de vezes que o contêiner congelou eventos (se recusa a aceitar eventos) sem um descongelar intermediário de eventos (aceitação de eventos).  
  
```
short m_nFreezeEvents;
```  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Para usar esse membro de dados em sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma união na classe base.  
  
##  <a name="a-namemrcposa--ccomcontrolbasemrcpos"></a><a name="m_rcpos"></a>CComControlBase::m_rcPos  
 A posição em pixels do controle, expressada nas coordenadas do recipiente.  
  
```
RECT m_rcPos;
```  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Para usar esse membro de dados em sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma união na classe base.  
  
##  <a name="a-namemsizeextenta--ccomcontrolbasemsizeextent"></a><a name="m_sizeextent"></a>CComControlBase::m_sizeExtent  
 A extensão do controle em unidades HIMETRIC (cada unidade 0,01 milímetros) para uma exibição específica.  
  
```
SIZE m_sizeExtent;
```  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Para usar esse membro de dados em sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma união na classe base.  
  
 Esse tamanho é dimensionado por exibição. O tamanho do controle físico é especificado no `m_sizeNatural` membro de dados e é fixo.  
  
 Você pode converter o tamanho em pixels com a função global [AtlHiMetricToPixel](http://msdn.microsoft.com/library/00c3af58-7298-4082-9a2e-5b68a8cec6fd).  
  
##  <a name="a-namemsizenaturala--ccomcontrolbasemsizenatural"></a><a name="m_sizenatural"></a>CComControlBase::m_sizeNatural  
 O tamanho físico do controle em unidades HIMETRIC (cada unidade é milímetro 0,01).  
  
```
SIZE m_sizeNatural;
```  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Para usar esse membro de dados em sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma união na classe base.  
  
 Esse tamanho é fixa, enquanto o tamanho em `m_sizeExtent` é dimensionado por exibição.  
  
 Você pode converter o tamanho em pixels com a função global [AtlHiMetricToPixel](http://msdn.microsoft.com/library/00c3af58-7298-4082-9a2e-5b68a8cec6fd).  
  
##  <a name="a-namemspadvisesinka--ccomcontrolbasemspadvisesink"></a><a name="m_spadvisesink"></a>CComControlBase::m_spAdviseSink  
 Um ponteiro direto para a conexão de consultoria no contêiner (o contêiner [IAdviseSink](http://msdn.microsoft.com/library/windows/desktop/ms692513)).  
  
```
CComPtr<IAdviseSink>
    m_spAdviseSink;
```     
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Para usar esse membro de dados em sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma união na classe base.  
  
##  <a name="a-namemspambientdispatcha--ccomcontrolbasemspambientdispatch"></a><a name="m_spambientdispatch"></a>CComControlBase::m_spAmbientDispatch  
 A `CComDispatchDriver` objeto que permite recuperar e definir propriedades de um objeto por meio de um `IDispatch` ponteiro.  
  
```
CComDispatchDriver m_spAmbientDispatch;
```  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Para usar esse membro de dados em sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma união na classe base.  
  
##  <a name="a-namemspclientsitea--ccomcontrolbasemspclientsite"></a><a name="m_spclientsite"></a>CComControlBase::m_spClientSite  
 Um ponteiro para o site do cliente do controle no contêiner.  
  
```
CComPtr<IOleClientSite>
    m_spClientSite;
```     
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Para usar esse membro de dados em sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma união na classe base.  
  
##  <a name="a-namemspdataadviseholdera--ccomcontrolbasemspdataadviseholder"></a><a name="m_spdataadviseholder"></a>CComControlBase::m_spDataAdviseHolder  
 Fornece que um padrão significa manter conexões comunicados entre objetos de dados e Coletores de aviso.  
  
```
CComPtr<IDataAdviseHolder>
    m_spDataAdviseHolder;
```     
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Para usar esse membro de dados em sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma união na classe base.  
  
 Um objeto de dados é um controle que pode transferir dados e que implementa [IDataObject](http://msdn.microsoft.com/library/windows/desktop/ms688421), cujos métodos especifique a mídia de formato e transferência de dados.  
  
 A interface `m_spDataAdviseHolder` implementa o [IDataObject::DAdvise](http://msdn.microsoft.com/library/windows/desktop/ms692579) e [IDataObject::DUnadvise](http://msdn.microsoft.com/library/windows/desktop/ms692448) métodos para estabelecer e excluir conexões de consultoria para o contêiner. Contêiner do controle deve implementar um coletor advise suportando o [IAdviseSink](http://msdn.microsoft.com/library/windows/desktop/ms692513) interface.  
  
##  <a name="a-namemspinplacesitea--ccomcontrolbasemspinplacesite"></a><a name="m_spinplacesite"></a>CComControlBase::m_spInPlaceSite  
 Um ponteiro para o contêiner [IOleInPlaceSite](http://msdn.microsoft.com/library/windows/desktop/ms686586), [IOleInPlaceSiteEx](http://msdn.microsoft.com/library/windows/desktop/ms693461), ou [IOleInPlaceSiteWindowless](http://msdn.microsoft.com/library/windows/desktop/ms682300) ponteiro de interface.  
  
```
CComPtr<IOleInPlaceSiteWindowless>
    m_spInPlaceSite;
```     
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Para usar esse membro de dados em sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma união na classe base.  
  
 O `m_spInPlaceSite` ponteiro é válido apenas se o [m_bNegotiatedWnd](#m_bnegotiatedwnd) sinalizador é **TRUE**.  
  
 A tabela a seguir mostra como o `m_spInPlaceSite` depende do tipo de ponteiro de [m_bWndLess](#m_bwndless) e [m_bInPlaceSiteEx](#m_binplacesiteex) sinalizadores de membro de dados:  
  
|Tipo de m_spInPlaceSite|m_bWndLess valor|m_bInPlaceSiteEx valor|  
|---------------------------|-----------------------|-----------------------------|  
|**IOleInPlaceSiteWindowless**|**TRUE**|**TRUE** ou **FALSE**|  
|**IOleInPlaceSiteEx**|**FALSE**|**TRUE**|  
|`IOleInPlaceSite`|**FALSE**|**FALSE**|  
  
##  <a name="a-namemspoleadviseholdera--ccomcontrolbasemspoleadviseholder"></a><a name="m_spoleadviseholder"></a>CComControlBase::m_spOleAdviseHolder  
 Fornece uma implementação padrão de uma maneira de manter conexões comunicados.  
  
```
CComPtr<IOleAdviseHolder>
    m_spOleAdviseHolder;
```     
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Para usar esse membro de dados em sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma união na classe base.  
  
 A interface `m_spOleAdviseHolder` implementa o [IOleObject::Advise](http://msdn.microsoft.com/library/windows/desktop/ms686573) e [IOleObject::Unadvise](http://msdn.microsoft.com/library/windows/desktop/ms693749) métodos para estabelecer e excluir conexões de consultoria para o contêiner. Contêiner do controle deve implementar um coletor advise suportando o [IAdviseSink](http://msdn.microsoft.com/library/windows/desktop/ms692513) interface.  
  
##  <a name="a-nameondrawa--ccomcontrolbaseondraw"></a><a name="ondraw"></a>CComControlBase::OnDraw  
 Substitua este método para desenhar o controle.  
  
```
virtual HRESULT OnDraw(ATL_DRAWINFO& di);
```  
  
### <a name="parameters"></a>Parâmetros  
 `di`  
 Uma referência para o [ATL_DRAWINFO](../../atl/reference/atl-drawinfo-structure.md) estrutura que contém informações de desenho como o aspecto de desenho, os limites do controle, e se o desenho é otimizado ou não.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 O padrão `OnDraw` exclui ou restaura o contexto de dispositivo ou não faz nada, dependendo de sinalizadores definidos [CComControlBase::OnDrawAdvanced](#ondrawadvanced).  
  
 Um `OnDraw` método é adicionado automaticamente à sua classe de controle quando você cria o controle com o Assistente de controle ATL. Padrão do assistente `OnDraw` desenha um retângulo com o rótulo "ATL 8.0".  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CComControlBase::GetAmbientAppearance](#getambientappearance).  
  
##  <a name="a-nameondrawadvanceda--ccomcontrolbaseondrawadvanced"></a><a name="ondrawadvanced"></a>CComControlBase::OnDrawAdvanced  
 O padrão `OnDrawAdvanced` prepara um contexto de dispositivo normalizado para desenho, em seguida, chama sua classe de controle `OnDraw` método.  
  
```
virtual HRESULT OnDrawAdvanced(ATL_DRAWINFO& di);
```  
  
### <a name="parameters"></a>Parâmetros  
 `di`  
 Uma referência para o [ATL_DRAWINFO](../../atl/reference/atl-drawinfo-structure.md) estrutura que contém informações de desenho como o aspecto de desenho, os limites do controle, e se o desenho é otimizado ou não.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método se você quiser aceitar o contexto de dispositivo que passou pelo contêiner sem ser normalizado.  
  
 Consulte [CComControlBase::OnDraw](#ondraw) para obter mais detalhes.  
  
##  <a name="a-nameonkillfocusa--ccomcontrolbaseonkillfocus"></a><a name="onkillfocus"></a>CComControlBase::OnKillFocus  
 Verifica se o controle está ativo no local e possui um site válido do controle e informa o contêiner que o controle perdeu o foco.  
  
```
LRESULT OnKillFocus(UINT /* nMsg */,
    WPARAM /* wParam */,
    LPARAM /* lParam */,
    BOOL& bHandled);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nMsg`  
 Reservado.  
  
 `wParam`  
 Reservado.  
  
 `lParam`  
 Reservado.  
  
 `bHandled`  
 Sinalizador que indica se a mensagem de janela foi processada com êxito. O padrão é `FALSE`.  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre retorna 1.  
  
##  <a name="a-nameonmouseactivatea--ccomcontrolbaseonmouseactivate"></a><a name="onmouseactivate"></a>CComControlBase::OnMouseActivate  
 Verifica se a interface do usuário está no modo de usuário e ativa o controle.  
  
```
LRESULT OnMouseActivate(UINT /* nMsg */,
    WPARAM /* wParam */,
    LPARAM /* lParam */,
    BOOL& bHandled);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nMsg`  
 Reservado.  
  
 `wParam`  
 Reservado.  
  
 `lParam`  
 Reservado.  
  
 `bHandled`  
 Sinalizador que indica se a mensagem de janela foi processada com êxito. O padrão é `FALSE`.  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre retorna 1.  
  
##  <a name="a-nameonpainta--ccomcontrolbaseonpaint"></a><a name="onpaint"></a>CComControlBase::OnPaint  
 Prepara o contêiner para pintura, obtém a área do cliente do controle, em seguida, chama a classe de controle `OnDrawAdvanced` método.  
  
```
LRESULT OnPaint(UINT /* nMsg */,
    WPARAM wParam,
    LPARAM /* lParam */,
    BOOL& /* lResult */);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nMsg`  
 Reservado.  
  
 `wParam`  
 HDC um existente.  
  
 `lParam`  
 Reservado.  
  
 `lResult`  
 Reservado.  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre retorna zero.  
  
### <a name="remarks"></a>Comentários  
 Se `wParam` não for nulo, `OnPaint` pressupõe que ele contém um HDC válido e usa-o em vez de [CComControlBase::m_hWndCD](#m_hwndcd).  
  
##  <a name="a-nameonsetfocusa--ccomcontrolbaseonsetfocus"></a><a name="onsetfocus"></a>CComControlBase::OnSetFocus  
 Verifica se o controle está ativo no local possui um site válido do controle e informa o contêiner do controle obteve o foco.  
  
```
LRESULT OnSetFocus(UINT /* nMsg */,
    WPARAM /* wParam */,
    LPARAM /* lParam */,
    BOOL& bHandled);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nMsg`  
 Reservado.  
  
 `wParam`  
 Reservado.  
  
 `lParam`  
 Reservado.  
  
 `bHandled`  
 Sinalizador que indica se a mensagem de janela foi processada com êxito. O padrão é `FALSE`.  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre retorna 1.  
  
### <a name="remarks"></a>Comentários  
 Envia uma notificação ao contêiner que o controle tiver recebido o foco.  
  
##  <a name="a-namepretranslateacceleratora--ccomcontrolbasepretranslateaccelerator"></a><a name="pretranslateaccelerator"></a>CComControlBase::PreTranslateAccelerator  
 Substitui esse método para fornecer sua própria teclado manipuladores de acelerador.  
  
```
BOOL PreTranslateAccelerator(LPMSG /* pMsg */,
    HRESULT& /* hRet */);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pMsg`  
 Reservado.  
  
 *hRet*  
 Reservado.  
  
### <a name="return-value"></a>Valor de retorno  
 Por padrão retorna **FALSE**.  
  
##  <a name="a-namesendonclosea--ccomcontrolbasesendonclose"></a><a name="sendonclose"></a>CComControlBase::SendOnClose  
 Notifica o comunicado de todos os coletores registrados com o detentor de aviso que o controle foi fechado.  
  
```
HRESULT SendOnClose();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Envia uma notificação de que o controle foi fechado seus Coletores de consultoria.  
  
##  <a name="a-namesendondatachangea--ccomcontrolbasesendondatachange"></a><a name="sendondatachange"></a>CComControlBase::SendOnDataChange  
 Notifica o comunicado de todos os coletores registrados com o detentor de advise que os dados de controle mudou.  
  
```
HRESULT SendOnDataChange(DWORD advf = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 *advf*  
 Aconselhamos sinalizadores que especificam como a chamada para [IAdviseSink::OnDataChange](http://msdn.microsoft.com/library/windows/desktop/ms687283) é feita. Os valores variam da [ADVF](http://msdn.microsoft.com/library/windows/desktop/ms693742) enumeração.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="a-namesendonrenamea--ccomcontrolbasesendonrename"></a><a name="sendonrename"></a>CComControlBase::SendOnRename  
 Notifica o comunicado de todos os coletores registrados com o detentor de aviso que o controle tem um novo identificador de origem.  
  
```
HRESULT SendOnRename(IMoniker* pmk);
```  
  
### <a name="parameters"></a>Parâmetros  
 *PMK*  
 Ponteiro para o novo identificador de origem do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Envia uma notificação de que o identificador de origem para o controle foi alterado.  
  
##  <a name="a-namesendonsavea--ccomcontrolbasesendonsave"></a><a name="sendonsave"></a>CComControlBase::SendOnSave  
 Notifica o comunicado de todos os coletores registrados com o proprietário de aviso que o controle foi salvo.  
  
```
HRESULT SendOnSave();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Envia uma notificação de que o controle tenha apenas salva seus dados.  
  
##  <a name="a-namesendonviewchangea--ccomcontrolbasesendonviewchange"></a><a name="sendonviewchange"></a>CComControlBase::SendOnViewChange  
 Notifica que todos os registrados Coletores de consultoria que alterou a exibição do controle.  
  
```
HRESULT SendOnViewChange(DWORD dwAspect, LONG lindex = -1);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwAspect`  
 O aspecto ou modo de exibição do controle.  
  
 *lindex*  
 A parte do modo de exibição que foi alterado. Apenas -1 é válido.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 `SendOnViewChange`chamadas [IAdviseSink::OnViewChange](http://msdn.microsoft.com/library/windows/desktop/ms694337). O único valor de *lindex* suporte atualmente é -1, que indica que o modo de exibição é de interesse.  
  
##  <a name="a-namesetcontrolfocusa--ccomcontrolbasesetcontrolfocus"></a><a name="setcontrolfocus"></a>CComControlBase::SetControlFocus  
 Define ou remove o foco do teclado para ou do controle.  
  
```
BOOL SetControlFocus(BOOL bGrab);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bGrab*  
 Se **TRUE**, define o foco do teclado para o controle de chamada. Se **FALSE**, remove o foco do teclado de controle de chamada, desde que tenha o foco.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** se com êxito, o controle recebe foco; caso contrário, **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Para um controle de janela, a função de API do Windows [SetFocus](http://msdn.microsoft.com/library/windows/desktop/ms646312) é chamado. Para um controle sem janelas, [IOleInPlaceSiteWindowless::SetFocus](http://msdn.microsoft.com/library/windows/desktop/ms679745) é chamado. Por meio desta chamada, um controle sem janelas obtém o foco do teclado e responde às mensagens de janela.  
  
##  <a name="a-namesetdirtya--ccomcontrolbasesetdirty"></a><a name="setdirty"></a>CComControlBase::SetDirty  
 Define o membro de dados `m_bRequiresSave` com o valor em `bDirty`.  
  
```
void SetDirty(BOOL bDirty);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bDirty`  
 Valor do membro de dados [CComControlBase::m_bRequiresSave](#m_brequiressave).  
  
### <a name="remarks"></a>Comentários  
 **SetDirty(TRUE)** deve ser chamado para sinalizar que o controle foi alterado desde que foi salvo pela última vez. O valor de `m_bRequiresSave` é recuperada com [CComControlBase::GetDirty](#getdirty).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComControl](../../atl/reference/ccomcontrol-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

