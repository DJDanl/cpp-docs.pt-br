---
title: Classe CComControlBase
ms.date: 11/04/2016
f1_keywords:
- CComControlBase
- ATLCTL/ATL::CComControlBase
- ATLCTL/ATL::CComControlBase::AppearanceType
- ATLCTL/ATL::CComControlBase::CComControlBase
- ATLCTL/ATL::CComControlBase::ControlQueryInterface
- ATLCTL/ATL::CComControlBase::DoesVerbActivate
- ATLCTL/ATL::CComControlBase::DoesVerbUIActivate
- ATLCTL/ATL::CComControlBase::DoVerbProperties
- ATLCTL/ATL::CComControlBase::FireViewChange
- ATLCTL/ATL::CComControlBase::GetAmbientAppearance
- ATLCTL/ATL::CComControlBase::GetAmbientAutoClip
- ATLCTL/ATL::CComControlBase::GetAmbientBackColor
- ATLCTL/ATL::CComControlBase::GetAmbientCharSet
- ATLCTL/ATL::CComControlBase::GetAmbientCodePage
- ATLCTL/ATL::CComControlBase::GetAmbientDisplayAsDefault
- ATLCTL/ATL::CComControlBase::GetAmbientDisplayName
- ATLCTL/ATL::CComControlBase::GetAmbientFont
- ATLCTL/ATL::CComControlBase::GetAmbientFontDisp
- ATLCTL/ATL::CComControlBase::GetAmbientForeColor
- ATLCTL/ATL::CComControlBase::GetAmbientLocaleID
- ATLCTL/ATL::CComControlBase::GetAmbientMessageReflect
- ATLCTL/ATL::CComControlBase::GetAmbientPalette
- ATLCTL/ATL::CComControlBase::GetAmbientProperty
- ATLCTL/ATL::CComControlBase::GetAmbientRightToLeft
- ATLCTL/ATL::CComControlBase::GetAmbientScaleUnits
- ATLCTL/ATL::CComControlBase::GetAmbientShowGrabHandles
- ATLCTL/ATL::CComControlBase::GetAmbientShowHatching
- ATLCTL/ATL::CComControlBase::GetAmbientSupportsMnemonics
- ATLCTL/ATL::CComControlBase::GetAmbientTextAlign
- ATLCTL/ATL::CComControlBase::GetAmbientTopToBottom
- ATLCTL/ATL::CComControlBase::GetAmbientUIDead
- ATLCTL/ATL::CComControlBase::GetAmbientUserMode
- ATLCTL/ATL::CComControlBase::GetDirty
- ATLCTL/ATL::CComControlBase::GetZoomInfo
- ATLCTL/ATL::CComControlBase::InPlaceActivate
- ATLCTL/ATL::CComControlBase::InternalGetSite
- ATLCTL/ATL::CComControlBase::OnDraw
- ATLCTL/ATL::CComControlBase::OnDrawAdvanced
- ATLCTL/ATL::CComControlBase::OnKillFocus
- ATLCTL/ATL::CComControlBase::OnMouseActivate
- ATLCTL/ATL::CComControlBase::OnPaint
- ATLCTL/ATL::CComControlBase::OnSetFocus
- ATLCTL/ATL::CComControlBase::PreTranslateAccelerator
- ATLCTL/ATL::CComControlBase::SendOnClose
- ATLCTL/ATL::CComControlBase::SendOnDataChange
- ATLCTL/ATL::CComControlBase::SendOnRename
- ATLCTL/ATL::CComControlBase::SendOnSave
- ATLCTL/ATL::CComControlBase::SendOnViewChange
- ATLCTL/ATL::CComControlBase::SetControlFocus
- ATLCTL/ATL::CComControlBase::SetDirty
- ATLCTL/ATL::CComControlBase::m_bAutoSize
- ATLCTL/ATL::CComControlBase::m_bDrawFromNatural
- ATLCTL/ATL::CComControlBase::m_bDrawGetDataInHimetric
- ATLCTL/ATL::CComControlBase::m_bInPlaceActive
- ATLCTL/ATL::CComControlBase::m_bInPlaceSiteEx
- ATLCTL/ATL::CComControlBase::m_bNegotiatedWnd
- ATLCTL/ATL::CComControlBase::m_bRecomposeOnResize
- ATLCTL/ATL::CComControlBase::m_bRequiresSave
- ATLCTL/ATL::CComControlBase::m_bResizeNatural
- ATLCTL/ATL::CComControlBase::m_bUIActive
- ATLCTL/ATL::CComControlBase::m_bUsingWindowRgn
- ATLCTL/ATL::CComControlBase::m_bWasOnceWindowless
- ATLCTL/ATL::CComControlBase::m_bWindowOnly
- ATLCTL/ATL::CComControlBase::m_bWndLess
- ATLCTL/ATL::CComControlBase::m_hWndCD
- ATLCTL/ATL::CComControlBase::m_nFreezeEvents
- ATLCTL/ATL::CComControlBase::m_rcPos
- ATLCTL/ATL::CComControlBase::m_sizeExtent
- ATLCTL/ATL::CComControlBase::m_sizeNatural
- ATLCTL/ATL::CComControlBase::m_spAdviseSink
- ATLCTL/ATL::CComControlBase::m_spAmbientDispatch
- ATLCTL/ATL::CComControlBase::m_spClientSite
- ATLCTL/ATL::CComControlBase::m_spDataAdviseHolder
- ATLCTL/ATL::CComControlBase::m_spInPlaceSite
- ATLCTL/ATL::CComControlBase::m_spOleAdviseHolder
helpviewer_keywords:
- CComControlBase class
ms.assetid: 3d1bf022-acf2-4092-8283-ff8cee6332f3
ms.openlocfilehash: def8334cf0ed9b6b2ee821e1e0f1a717d90f2163
ms.sourcegitcommit: b032daf81cb5fdb1f5a988277ee30201441c4945
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2018
ms.locfileid: "51694576"
---
# <a name="ccomcontrolbase-class"></a>Classe CComControlBase

Essa classe fornece métodos para criar e gerenciar os controles ATL.

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
|[CComControlBase::AppearanceType](#appearancetype)|Substituir se sua `m_nAppearance` propriedade de estoque não é do tipo **curto**.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComControlBase::CComControlBase](#ccomcontrolbase)|O construtor.|
|[CComControlBase:: ~ CComControlBase](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComControlBase::ControlQueryInterface](#controlqueryinterface)|Recupera um ponteiro para a interface solicitada.|
|[CComControlBase::DoesVerbActivate](#doesverbactivate)|Verifica se o *iVerb* parâmetro usado pelo `IOleObjectImpl::DoVerb` o ativa a interface do usuário do controle (*iVerb* é igual a OLEIVERB_UIACTIVATE), define a ação executada quando o usuário clica duas vezes o controle (*iVerb* é igual a OLEIVERB_PRIMARY), exibe o controle (*iVerb* é igual a OLEIVERB_SHOW), ou ativa o controle (*iVerb* é igual a OLEIVERB _INPLACEACTIVATE).|
|[CComControlBase::DoesVerbUIActivate](#doesverbuiactivate)|Verifica se o *iVerb* parâmetro usado pelo `IOleObjectImpl::DoVerb` faz com que a interface do usuário do controle ativar e retorna TRUE.|
|[CComControlBase::DoVerbProperties](#doverbproperties)|Exibe as páginas de propriedades do controle.|
|[CComControlBase::FireViewChange](#fireviewchange)|Chame esse método para instruir o contêiner para redesenhar o controle ou notificar os coletores de advise registrado exibição do controle foi alterado.|
|[CComControlBase::GetAmbientAppearance](#getambientappearance)|Recupera o DISPID_AMBIENT_APPEARANCE, a aparência atual definindo para o controle: 0 para simples e 1 para 3D.|
|[CComControlBase::GetAmbientAutoClip](#getambientautoclip)|Recupera o DISPID_AMBIENT_AUTOCLIP, um sinalizador que indica se o contêiner dá suporte a recorte automático da área de exibição de controle.|
|[CComControlBase::GetAmbientBackColor](#getambientbackcolor)|Recupera o DISPID_AMBIENT_BACKCOLOR, a cor da tela de fundo ambiente para todos os controles, definido pelo contêiner.|
|[CComControlBase::GetAmbientCharSet](#getambientcharset)|Recupera o DISPID_AMBIENT_CHARSET, o caractere de ambiente definidas para todos os controles, definidos pelo contêiner.|
|[CComControlBase::GetAmbientCodePage](#getambientcodepage)|Recupera o DISPID_AMBIENT_CODEPAGE, o caractere de ambiente definidas para todos os controles, definidos pelo contêiner.|
|[CComControlBase::GetAmbientDisplayAsDefault](#getambientdisplayasdefault)|Recupera o DISPID_AMBIENT_DISPLAYASDEFAULT, um sinalizador que será TRUE se o contêiner tiver marcado o controle esse site para ser um botão padrão e, portanto, um controle de botão deve desenhar a próprio um quadro mais espessas.|
|[CComControlBase::GetAmbientDisplayName](#getambientdisplayname)|Recupera o DISPID_AMBIENT_DISPLAYNAME, o nome do contêiner tem fornecido para o controle.|
|[CComControlBase::GetAmbientFont](#getambientfont)|Recupera um ponteiro para o contêiner do ambiente `IFont` interface.|
|[CComControlBase::GetAmbientFontDisp](#getambientfontdisp)|Recupera um ponteiro para o contêiner do ambiente `IFontDisp` interface de expedição.|
|[CComControlBase::GetAmbientForeColor](#getambientforecolor)|Recupera o DISPID_AMBIENT_FORECOLOR, a cor de primeiro plano de ambiente para todos os controles, definido pelo contêiner.|
|[CComControlBase::GetAmbientLocaleID](#getambientlocaleid)|Recupera o DISPID_AMBIENT_LOCALEID, o identificador do idioma usado pelo contêiner.|
|[CComControlBase::GetAmbientMessageReflect](#getambientmessagereflect)|Recupera o DISPID_AMBIENT_MESSAGEREFLECT, um sinalizador que indica se o contêiner quer receber mensagens de janela (como WM_DRAWITEM) como eventos.|
|[CComControlBase::GetAmbientPalette](#getambientpalette)|Recupera DISPID_AMBIENT_PALETTE, usado para acessar HPALETTE do contêiner.|
|[CComControlBase::GetAmbientProperty](#getambientproperty)|Recupera a propriedade de contêiner especificada pelo *id*.|
|[CComControlBase::GetAmbientRightToLeft](#getambientrighttoleft)|Recupera o DISPID_AMBIENT_RIGHTTOLEFT, a direção na qual o conteúdo é exibido pelo contêiner.|
|[CComControlBase::GetAmbientScaleUnits](#getambientscaleunits)|Recupera DISPID_AMBIENT_SCALEUNITS, unidades de ambiente do contêiner (como polegadas ou centímetros) para rotulação exibe.|
|[CComControlBase::GetAmbientShowGrabHandles](#getambientshowgrabhandles)|Recupera o DISPID_AMBIENT_SHOWGRABHANDLES, um sinalizador que indica se o contêiner permite o controle para exibir as alças de captura para si mesmo quando ativo.|
|[CComControlBase::GetAmbientShowHatching](#getambientshowhatching)|Recupera o DISPID_AMBIENT_SHOWHATCHING, um sinalizador que indica se o contêiner permite que o controle exibir a mesmo com um padrão hachurado quando a interface do usuário está ativo.|
|[CComControlBase::GetAmbientSupportsMnemonics](#getambientsupportsmnemonics)|Recupera o DISPID_AMBIENT_SUPPORTSMNEMONICS, um sinalizador que indica se o contêiner dá suporte a mnemônicos de teclado.|
|[CComControlBase::GetAmbientTextAlign](#getambienttextalign)|Recupera o DISPID_AMBIENT_TEXTALIGN, o alinhamento de texto preferido pelo contêiner: 0 para o alinhamento geral (texto à direita, números à esquerda), 1 para alinhamento à esquerda, 2 para alinhamento centralizado e 3 para o alinhamento à direita.|
|[CComControlBase::GetAmbientTopToBottom](#getambienttoptobottom)|Recupera o DISPID_AMBIENT_TOPTOBOTTOM, a direção na qual o conteúdo é exibido pelo contêiner.|
|[CComControlBase::GetAmbientUIDead](#getambientuidead)|Recupera o DISPID_AMBIENT_UIDEAD, um sinalizador que indica se o contêiner quiser o controle para responder às ações de interface do usuário.|
|[CComControlBase::GetAmbientUserMode](#getambientusermode)|Recupera o DISPID_AMBIENT_USERMODE, um sinalizador que indica se o contêiner está no modo de execução (TRUE) ou modo de design (FALSE).|
|[CComControlBase::GetDirty](#getdirty)|Retorna o valor do membro de dados `m_bRequiresSave`.|
|[CComControlBase::GetZoomInfo](#getzoominfo)|Recupera a x e y valores do numerador e do denominador do fator de zoom para um controle ativada para ativação in-loco.|
|[CComControlBase::InPlaceActivate](#inplaceactivate)|Faz com que o controle para fazer a transição do estado inativo tudo o que declarar o verbo na *iVerb* indica.|
|[CComControlBase::InternalGetSite](#internalgetsite)|Chame esse método para consultar o site de controle de um ponteiro para a interface identificada.|
|[CComControlBase::OnDraw](#ondraw)|Substitua este método para desenhar seu controle.|
|[CComControlBase::OnDrawAdvanced](#ondrawadvanced)|O padrão `OnDrawAdvanced` prepara um contexto de dispositivo normalizado para desenhar e, em seguida, chama sua classe de controle `OnDraw` método.|
|[CComControlBase::OnKillFocus](#onkillfocus)|Verifica se o controle está ativo no local e tem um site de controle válido e informa o contêiner que o controle perdeu o foco.|
|[CComControlBase::OnMouseActivate](#onmouseactivate)|Verifica que a interface do usuário está no modo de usuário e, em seguida, ativa o controle.|
|[CComControlBase::OnPaint](#onpaint)|Prepara o contêiner para pintura, obtém a área de cliente do controle, em seguida, chama a classe de controle `OnDraw` método.|
|[CComControlBase::OnSetFocus](#onsetfocus)|Verificações que o controle está ativo no local e tem um site de controle válido e informa o contêiner de controle ganhou o foco.|
|[CComControlBase::PreTranslateAccelerator](#pretranslateaccelerator)|Substitua este método para fornecer seu próprio teclado manipuladores de acelerador.|
|[CComControlBase::SendOnClose](#sendonclose)|Notifica os coletores de todos os de supervisão registrados com o detentor de avisos que o controle foi fechado.|
|[CComControlBase::SendOnDataChange](#sendondatachange)|Notifica os coletores de todos os de supervisão registrados com o detentor da advise que os dados de controle foi alterado.|
|[CComControlBase::SendOnRename](#sendonrename)|Notifica os coletores de todos os de supervisão registrados com o detentor de avisos que o controle tem um novo moniker.|
|[CComControlBase::SendOnSave](#sendonsave)|Notifica os coletores de todos os de supervisão registrados com o detentor da advise que o controle foi salvo.|
|[CComControlBase::SendOnViewChange](#sendonviewchange)|Notifica que todos os registrados Coletores de supervisão para exibição do controle foi alterado.|
|[CComControlBase::SetControlFocus](#setcontrolfocus)|Define ou remove o foco do teclado de ou para o controle.|
|[CComControlBase::SetDirty](#setdirty)|Define o membro de dados `m_bRequiresSave` ao valor na *bDirty*.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComControlBase::m_bAutoSize](#m_bautosize)|Sinalizador que indica que o controle não pode ser qualquer outro tamanho.|
|[CComControlBase::m_bDrawFromNatural](#m_bdrawfromnatural)|Sinalizador que indica que `IDataObjectImpl::GetData` e `CComControlBase::GetZoomInfo` deve definir o tamanho do controle de `m_sizeNatural` , em vez de `m_sizeExtent`.|
|[CComControlBase::m_bDrawGetDataInHimetric](#m_bdrawgetdatainhimetric)|Sinalizador que indica que `IDataObjectImpl::GetData` devem usar unidades HIMETRIC e não em pixels, ao desenhar.|
|[CComControlBase::m_bInPlaceActive](#m_binplaceactive)|Sinalizador que indica que o controle está ativo no local.|
|[CComControlBase::m_bInPlaceSiteEx](#m_binplacesiteex)|Sinalizador que indica o dá suporte a contêiner o `IOleInPlaceSiteEx` interface e OCX96 controlam os recursos, tais como controles sem janelas e sem cintilações.|
|[CComControlBase::m_bNegotiatedWnd](#m_bnegotiatedwnd)|Sinalizador que indica se ou não o controle tem negociado com o contêiner sobre o suporte para recursos de controle de OCX96 (como controles sem janelas e cintilação) e se o controle é em janelas ou sem janelas.|
|[CComControlBase::m_bRecomposeOnResize](#m_brecomposeonresize)|Sinalizador que indica que o controle deseja recompor sua apresentação quando o contêiner de tamanho de exibição do controle é alterado.|
|[CComControlBase::m_bRequiresSave](#m_brequiressave)|Sinalizador que indica que o controle foi alterado desde que foi salvo pela última vez.|
|[CComControlBase::m_bResizeNatural](#m_bresizenatural)|Sinalizador que indica o controle deseja redimensionar sua extensão natural (seu tamanho físico fora de escala) quando o contêiner altera o tamanho da exibição do controle.|
|[CComControlBase::m_bUIActive](#m_buiactive)|Sinalizador que indica a interface do usuário do controle, como menus e barras de ferramentas está ativo.|
|[CComControlBase::m_bUsingWindowRgn](#m_busingwindowrgn)|Sinalizador que indica que o controle está usando a região da janela fornecido pelo contêiner.|
|[CComControlBase::m_bWasOnceWindowless](#m_bwasoncewindowless)|Sinalizador que indica o controle tiver sido sem janelas, mas pode ou não ser sem janelas agora.|
|[CComControlBase::m_bWindowOnly](#m_bwindowonly)|Sinalizador que indica que o controle deve ser em janelas, mesmo se o contêiner dá suporte a controles sem janelas.|
|[CComControlBase::m_bWndLess](#m_bwndless)|Sinalizador que indica que o controle for sem janelas.|
|[CComControlBase::m_hWndCD](#m_hwndcd)|Contém uma referência para o identificador de janela associado ao controle.|
|[CComControlBase::m_nFreezeEvents](#m_nfreezeevents)|Uma contagem do número de vezes que o contêiner congelou (se recusou a aceitar eventos) de eventos sem uma intervenção descongelar de eventos (aceitação de eventos).|
|[CComControlBase::m_rcPos](#m_rcpos)|A posição em pixels do controle, expressada em coordenadas de contêiner.|
|[CComControlBase::m_sizeExtent](#m_sizeextent)|A extensão do controle em unidades HIMETRIC (cada unidade 0,01 milímetros) para um determinado vídeo.|
|[CComControlBase::m_sizeNatural](#m_sizenatural)|O tamanho físico do controle em unidades HIMETRIC (cada unidade 0,01 milímetros).|
|[CComControlBase::m_spAdviseSink](#m_spadvisesink)|Um ponteiro direto para a conexão de consultoria no contêiner (o contêiner [IAdviseSink](/windows/desktop/api/objidl/nn-objidl-iadvisesink)).|
|[CComControlBase::m_spAmbientDispatch](#m_spambientdispatch)|Um `CComDispatchDriver` objeto que permite recuperar e definir as propriedades do contêiner por meio de um `IDispatch` ponteiro.|
|[CComControlBase::m_spClientSite](#m_spclientsite)|Um ponteiro para o site do cliente do controle dentro do contêiner.|
|[CComControlBase::m_spDataAdviseHolder](#m_spdataadviseholder)|Fornece um padrão significa que manter as conexões de consultoria entre objetos de dados e Coletores de aviso.|
|[CComControlBase::m_spInPlaceSite](#m_spinplacesite)|Um ponteiro para o contêiner [IOleInPlaceSite](/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite), [IOleInPlaceSiteEx](/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesiteex), ou [IOleInPlaceSiteWindowless](/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesitewindowless) ponteiro de interface.|
|[CComControlBase::m_spOleAdviseHolder](#m_spoleadviseholder)|Fornece uma implementação padrão de uma maneira de manter conexões de consultoria.|

## <a name="remarks"></a>Comentários

Essa classe fornece métodos para criar e gerenciar os controles ATL. [Classe CComControl](../../atl/reference/ccomcontrol-class.md) deriva `CComControlBase`. Quando você cria um controle de controle padrão ou DHTML usando o Assistente de controle do ATL, o assistente automaticamente será derive sua classe da `CComControlBase`.

Para obter mais informações sobre como criar um controle, consulte o [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md). Para obter mais informações sobre o Assistente de projeto da ATL, consulte o artigo [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

##  <a name="appearancetype"></a>  CComControlBase::AppearanceType

Substituir se sua `m_nAppearance` propriedade de estoque não é do tipo **curto**.

```
typedef short AppearanceType;
```

### <a name="remarks"></a>Comentários

O Assistente de controle ATL adiciona `m_nAppearance` propriedade do tipo curto de estoque. Substituir `AppearanceType` se você usar outro tipo de dados.

##  <a name="ccomcontrolbase"></a>  CComControlBase::CComControlBase

O construtor.

```
CComControlBase(HWND& h);
```

### <a name="parameters"></a>Parâmetros

*h*<br/>
O identificador para a janela associada ao controle.

### <a name="remarks"></a>Comentários

Inicializa o tamanho do controle para unidades HIMETRIC de 5080 X 5080 (2x "2") e inicializa o `CComControlBase` valores de membro de dados como NULL ou FALSE.

##  <a name="dtor"></a>  CComControlBase:: ~ CComControlBase

O destruidor.

```
~CComControlBase();
```

### <a name="remarks"></a>Comentários

Se o controle estiver em janelas, `~CComControlBase` destrói chamando [DestroyWindow](/windows/desktop/api/winuser/nf-winuser-destroywindow).

##  <a name="controlqueryinterface"></a>  CComControlBase::ControlQueryInterface

Recupera um ponteiro para a interface solicitada.

```
virtual HRESULT ControlQueryInterface(const IID& iid,
    void** ppv);
```

### <a name="parameters"></a>Parâmetros

*IID*<br/>
O GUID da interface que está sendo solicitado.

*ppv*<br/>
Um ponteiro para o ponteiro de interface identificado pelo *iid*, ou nulo se a interface não foi encontrada.

### <a name="remarks"></a>Comentários

somente lida com interfaces na tabela de mapa COM.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#15](../../atl/codesnippet/cpp/ccomcontrolbase-class_1.cpp)]

##  <a name="doesverbactivate"></a>  CComControlBase::DoesVerbActivate

Verifica se o *iVerb* parâmetro usado pelo `IOleObjectImpl::DoVerb` o ativa a interface do usuário do controle (*iVerb* é igual a OLEIVERB_UIACTIVATE), define a ação executada quando o usuário clica duas vezes o controle (*iVerb* é igual a OLEIVERB_PRIMARY), exibe o controle (*iVerb* é igual a OLEIVERB_SHOW), ou ativa o controle (*iVerb* é igual a OLEIVERB _INPLACEACTIVATE).

```
BOOL DoesVerbActivate(LONG iVerb);
```

### <a name="parameters"></a>Parâmetros

*iVerb*<br/>
Valor que indica a ação a ser executada pelo `DoVerb`.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se *iVerb* é igual a OLEIVERB_UIACTIVATE, OLEIVERB_PRIMARY, OLEIVERB_SHOW ou OLEIVERB_INPLACEACTIVATE; caso contrário, retornará FALSE.

### <a name="remarks"></a>Comentários

Você pode substituir esse método para definir seu próprio verbo de ativação.

##  <a name="doesverbuiactivate"></a>  CComControlBase::DoesVerbUIActivate

Verifica se o *iVerb* parâmetro usado pelo `IOleObjectImpl::DoVerb` faz com que a interface do usuário do controle ativar e retorna TRUE.

```
BOOL DoesVerbUIActivate(LONG iVerb);
```

### <a name="parameters"></a>Parâmetros

*iVerb*<br/>
Valor que indica a ação a ser executada pelo `DoVerb`.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se *iVerb* é igual a OLEIVERB_UIACTIVATE, OLEIVERB_PRIMARY, OLEIVERB_SHOW ou OLEIVERB_INPLACEACTIVATE. Caso contrário, o método retornará FALSE.

##  <a name="doverbproperties"></a>  CComControlBase::DoVerbProperties

Exibe as páginas de propriedades do controle.

```
HRESULT DoVerbProperties(LPCRECT /* prcPosRect */, HWND hwndParent);
```

### <a name="parameters"></a>Parâmetros

*prcPosRec*<br/>
Reservado.

*hwndParent*<br/>
Identificador da janela que contém o controle.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#19](../../atl/codesnippet/cpp/ccomcontrolbase-class_2.cpp)]

[!code-cpp[NVC_ATL_COM#20](../../atl/codesnippet/cpp/ccomcontrolbase-class_3.h)]

##  <a name="fireviewchange"></a>  CComControlBase::FireViewChange

Chame esse método para instruir o contêiner para redesenhar o controle ou notificar os coletores de advise registrado exibição do controle foi alterado.

```
HRESULT FireViewChange();
```

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

Se o controle está ativo (o membro de dados de classe do controle [CComControlBase::m_bInPlaceActive](#m_binplaceactive) é TRUE), notifica o contêiner que você deseja redesenhar o controle inteiro. Se o controle estiver inativo, notifica o controle do registrado aconselhar coletores (por meio do membro de dados da classe de controle [CComControlBase::m_spAdviseSink](#m_spadvisesink)) que a exibição do controle foi alterado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#21](../../atl/codesnippet/cpp/ccomcontrolbase-class_4.cpp)]

##  <a name="getambientappearance"></a>  CComControlBase::GetAmbientAppearance

Recupera o DISPID_AMBIENT_APPEARANCE, a aparência atual definindo para o controle: 0 para simples e 1 para 3D.

```
HRESULT GetAmbientAppearance(short& nAppearance);
```

### <a name="parameters"></a>Parâmetros

*nAppearance*<br/>
A propriedade DISPID_AMBIENT_APPEARANCE.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#22](../../atl/codesnippet/cpp/ccomcontrolbase-class_5.h)]

##  <a name="getambientautoclip"></a>  CComControlBase::GetAmbientAutoClip

Recupera o DISPID_AMBIENT_AUTOCLIP, um sinalizador que indica se o contêiner dá suporte a recorte automático da área de exibição de controle.

```
HRESULT GetAmbientAutoClip(BOOL& bAutoClip);
```

### <a name="parameters"></a>Parâmetros

*bAutoClip*<br/>
A propriedade DISPID_AMBIENT_AUTOCLIP.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

##  <a name="getambientbackcolor"></a>  CComControlBase::GetAmbientBackColor

Recupera o DISPID_AMBIENT_BACKCOLOR, a cor da tela de fundo ambiente para todos os controles, definido pelo contêiner.

```
HRESULT GetAmbientBackColor(OLE_COLOR& BackColor);
```

### <a name="parameters"></a>Parâmetros

*BackColor*<br/>
A propriedade DISPID_AMBIENT_BACKCOLOR.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

##  <a name="getambientcharset"></a>  CComControlBase::GetAmbientCharSet

Recupera o DISPID_AMBIENT_CHARSET, o caractere de ambiente definidas para todos os controles, definidos pelo contêiner.

```
HRESULT GetAmbientCharSet(BSTR& bstrCharSet);
```

### <a name="parameters"></a>Parâmetros

*bstrCharSet*<br/>
A propriedade DISPID_AMBIENT_CHARSET.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

##  <a name="getambientcodepage"></a>  CComControlBase::GetAmbientCodePage

Recupera o DISPID_AMBIENT_CODEPAGE, a página de código de ambiente para todos os controles, definido pelo contêiner.

```
HRESULT GetAmbientCodePage(ULONG& ulCodePage);
```

### <a name="parameters"></a>Parâmetros

*ulCodePage*<br/>
A propriedade DISPID_AMBIENT_CODEPAGE.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

##  <a name="getambientdisplayasdefault"></a>  CComControlBase::GetAmbientDisplayAsDefault

Recupera o DISPID_AMBIENT_DISPLAYASDEFAULT, um sinalizador que será TRUE se o contêiner tiver marcado o controle esse site para ser um botão padrão e, portanto, um controle de botão deve desenhar a próprio um quadro mais espessas.

```
HRESULT GetAmbientDisplayAsDefault(BOOL& bDisplayAsDefault);
```

### <a name="parameters"></a>Parâmetros

*bDisplayAsDefault*<br/>
A propriedade DISPID_AMBIENT_DISPLAYASDEFAULT.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

##  <a name="getambientdisplayname"></a>  CComControlBase::GetAmbientDisplayName

Recupera o DISPID_AMBIENT_DISPLAYNAME, o nome do contêiner tem fornecido para o controle.

```
HRESULT GetAmbientDisplayName(BSTR& bstrDisplayName);
```

### <a name="parameters"></a>Parâmetros

*bstrDisplayName*<br/>
A propriedade DISPID_AMBIENT_DISPLAYNAME.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

##  <a name="getambientfont"></a>  CComControlBase::GetAmbientFont

Recupera um ponteiro para o contêiner do ambiente `IFont` interface.

```
HRESULT GetAmbientFont(IFont** ppFont);
```

### <a name="parameters"></a>Parâmetros

*ppFont*<br/>
Um ponteiro para o contêiner do ambiente [IFont](/windows/desktop/api/ocidl/nn-ocidl-ifont) interface.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

Se a propriedade for NULL, o ponteiro é NULL. Se o ponteiro não for nulo, o chamador deve liberar o ponteiro.

##  <a name="getambientfontdisp"></a>  CComControlBase::GetAmbientFontDisp

Recupera um ponteiro para o contêiner do ambiente `IFontDisp` interface de expedição.

```
HRESULT GetAmbientFontDisp(IFontDisp** ppFont);
```

### <a name="parameters"></a>Parâmetros

*ppFont*<br/>
Um ponteiro para o contêiner do ambiente [IFontDisp](https://msdn.microsoft.com/library/windows/desktop/ms692695) interface de expedição.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Se a propriedade for NULL, o ponteiro é NULL. Se o ponteiro não for nulo, o chamador deve liberar o ponteiro.

##  <a name="getambientforecolor"></a>  CComControlBase::GetAmbientForeColor

Recupera o DISPID_AMBIENT_FORECOLOR, a cor de primeiro plano de ambiente para todos os controles, definido pelo contêiner.

```
HRESULT GetAmbientForeColor(OLE_COLOR& ForeColor);
```

### <a name="parameters"></a>Parâmetros

*Cor de primeiro plano*<br/>
A propriedade DISPID_AMBIENT_FORECOLOR.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

##  <a name="getambientlocaleid"></a>  CComControlBase::GetAmbientLocaleID

Recupera o DISPID_AMBIENT_LOCALEID, o identificador do idioma usado pelo contêiner.

```
HRESULT GetAmbientLocaleID(LCID& lcid);
```

### <a name="parameters"></a>Parâmetros

*lcid*<br/>
A propriedade DISPID_AMBIENT_LOCALEID.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

O controle pode usar esse identificador para adaptar sua interface do usuário para diferentes idiomas.

##  <a name="getambientmessagereflect"></a>  CComControlBase::GetAmbientMessageReflect

Recupera o DISPID_AMBIENT_MESSAGEREFLECT, um sinalizador que indica se o contêiner quer receber mensagens de janela (como `WM_DRAWITEM`) como eventos.

```
HRESULT GetAmbientMessageReflect(BOOL& bMessageReflect);
```

### <a name="parameters"></a>Parâmetros

*bMessageReflect*<br/>
A propriedade DISPID_AMBIENT_MESSAGEREFLECT.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

##  <a name="getambientpalette"></a>  CComControlBase::GetAmbientPalette

Recupera DISPID_AMBIENT_PALETTE, usado para acessar HPALETTE do contêiner.

```
HRESULT GetAmbientPalette(HPALETTE& hPalette);
```

### <a name="parameters"></a>Parâmetros

*hPalette*<br/>
A propriedade DISPID_AMBIENT_PALETTE.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

##  <a name="getambientproperty"></a>  CComControlBase::GetAmbientProperty

Recupera a propriedade de contêiner especificada pelo *dispid*.

```
HRESULT GetAmbientProperty(DISPID dispid, VARIANT& var);
```

### <a name="parameters"></a>Parâmetros

*DISPID*<br/>
Identificador da propriedade contêiner a ser recuperado.

*var*<br/>
Variável para receber a propriedade.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

ATL forneceu um conjunto de funções auxiliares para recuperar propriedades específicas, por exemplo, [CComControlBase::GetAmbientBackColor](#getambientbackcolor). Se não houver nenhum método adequado disponível, use `GetAmbientProperty`.

##  <a name="getambientrighttoleft"></a>  CComControlBase::GetAmbientRightToLeft

Recupera o DISPID_AMBIENT_RIGHTTOLEFT, a direção na qual o conteúdo é exibido pelo contêiner.

```
HRESULT GetAmbientRightToLeft(BOOL& bRightToLeft);
```

### <a name="parameters"></a>Parâmetros

*bRightToLeft*<br/>
A propriedade DISPID_AMBIENT_RIGHTTOLEFT. FALSE se for definido como TRUE se o conteúdo é exibido à direita para a esquerda, exibido à esquerda para a direita.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

##  <a name="getambientscaleunits"></a>  CComControlBase::GetAmbientScaleUnits

Recupera DISPID_AMBIENT_SCALEUNITS, unidades de ambiente do contêiner (como polegadas ou centímetros) para rotulação exibe.

```
HRESULT GetAmbientScaleUnits(BSTR& bstrScaleUnits);
```

### <a name="parameters"></a>Parâmetros

*bstrScaleUnits*<br/>
A propriedade DISPID_AMBIENT_SCALEUNITS.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

##  <a name="getambientshowgrabhandles"></a>  CComControlBase::GetAmbientShowGrabHandles

Recupera o DISPID_AMBIENT_SHOWGRABHANDLES, um sinalizador que indica se o contêiner permite o controle para exibir as alças de captura para si mesmo quando ativo.

```
HRESULT GetAmbientShowGrabHandles(BOOL& bShowGrabHandles);
```

### <a name="parameters"></a>Parâmetros

*bShowGrabHandles*<br/>
A propriedade DISPID_AMBIENT_SHOWGRABHANDLES.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

##  <a name="getambientshowhatching"></a>  CComControlBase::GetAmbientShowHatching

Recupera o DISPID_AMBIENT_SHOWHATCHING, um sinalizador que indica se o contêiner permite que o controle exibir a mesmo com um padrão hachurado quando a interface do usuário do controle está ativo.

```
HRESULT GetAmbientShowHatching(BOOL& bShowHatching);
```

### <a name="parameters"></a>Parâmetros

*bShowHatching*<br/>
A propriedade DISPID_AMBIENT_SHOWHATCHING.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

##  <a name="getambientsupportsmnemonics"></a>  CComControlBase::GetAmbientSupportsMnemonics

Recupera o DISPID_AMBIENT_SUPPORTSMNEMONICS, um sinalizador que indica se o contêiner dá suporte a mnemônicos de teclado.

```
HRESULT GetAmbientSupportsMnemonics(BOOL& bSupportsMnemonics);
```

### <a name="parameters"></a>Parâmetros

*bSupportsMnemonics*<br/>
A propriedade DISPID_AMBIENT_SUPPORTSMNEMONICS.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

##  <a name="getambienttextalign"></a>  CComControlBase::GetAmbientTextAlign

Recupera o DISPID_AMBIENT_TEXTALIGN, o alinhamento de texto preferido pelo contêiner: 0 para o alinhamento geral (texto à direita, números à esquerda), 1 para alinhamento à esquerda, 2 para alinhamento centralizado e 3 para o alinhamento à direita.

```
HRESULT GetAmbientTextAlign(short& nTextAlign);
```

### <a name="parameters"></a>Parâmetros

*nTextAlign*<br/>
A propriedade DISPID_AMBIENT_TEXTALIGN.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

##  <a name="getambienttoptobottom"></a>  CComControlBase::GetAmbientTopToBottom

Recupera o DISPID_AMBIENT_TOPTOBOTTOM, a direção na qual o conteúdo é exibido pelo contêiner.

```
HRESULT GetAmbientTopToBottom(BOOL& bTopToBottom);
```

### <a name="parameters"></a>Parâmetros

*bTopToBottom*<br/>
A propriedade DISPID_AMBIENT_TOPTOBOTTOM. Definido como TRUE se o texto é exibido cima para baixo, FALSO se ele for exibido inferior para cima.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

##  <a name="getambientuidead"></a>  CComControlBase::GetAmbientUIDead

Recupera o DISPID_AMBIENT_UIDEAD, um sinalizador que indica se o contêiner quiser o controle para responder às ações de interface do usuário.

```
HRESULT GetAmbientUIDead(BOOL& bUIDead);
```

### <a name="parameters"></a>Parâmetros

*bUIDead*<br/>
A propriedade DISPID_AMBIENT_UIDEAD.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

Se for TRUE, o controle não deve responder. Esse sinalizador se aplica independentemente do sinalizador DISPID_AMBIENT_USERMODE. Ver [CComControlBase::GetAmbientUserMode](#getambientusermode).

##  <a name="getambientusermode"></a>  CComControlBase::GetAmbientUserMode

Recupera o DISPID_AMBIENT_USERMODE, um sinalizador que indica se o contêiner está no modo de execução (TRUE) ou modo de design (FALSE).

```
HRESULT GetAmbientUserMode(BOOL& bUserMode);
```

### <a name="parameters"></a>Parâmetros

*bUserMode*<br/>
A propriedade DISPID_AMBIENT_USERMODE.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

##  <a name="getdirty"></a>  CComControlBase::GetDirty

Retorna o valor do membro de dados `m_bRequiresSave`.

```
BOOL GetDirty();
```

### <a name="return-value"></a>Valor de retorno

Retorna o valor do membro de dados [m_bRequiresSave](#m_brequiressave).

### <a name="remarks"></a>Comentários

Esse valor é definido usando [CComControlBase::SetDirty](#setdirty).

##  <a name="getzoominfo"></a>  CComControlBase::GetZoomInfo

Recupera a x e y valores do numerador e do denominador do fator de zoom para um controle ativada para ativação in-loco.

```
void GetZoomInfo(ATL_DRAWINFO& di);
```

### <a name="parameters"></a>Parâmetros

*injeção de dependência*<br/>
A estrutura que conterá o numerador e do denominador o fator de zoom. Para obter mais informações, consulte [ATL_DRAWINFO](../../atl/reference/atl-drawinfo-structure.md).

### <a name="remarks"></a>Comentários

O fator de zoom é a proporção de tamanho natural do controle para sua extensão atual.

##  <a name="inplaceactivate"></a>  CComControlBase::InPlaceActivate

Faz com que o controle para fazer a transição do estado inativo tudo o que declarar o verbo na *iVerb* indica.

```
HRESULT InPlaceActivate(LONG iVerb, const RECT* prcPosRect = NULL);
```

### <a name="parameters"></a>Parâmetros

*iVerb*<br/>
Valor que indica a ação a ser executada pelo [IOleObjectImpl::DoVerb](../../atl/reference/ioleobjectimpl-class.md#doverb).

*prcPosRect*<br/>
Ponteiro para a posição do controle no local.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

Antes da ativação, esse método verifica que o controle tem um site do cliente, verifica a quantidade do controle está visível e obtém a localização do controle na janela pai. Depois que o controle é ativado, esse método ativa a interface do usuário do controle e informa o contêiner para tornar o controle visível.

Esse método também recupera uma `IOleInPlaceSite`, `IOleInPlaceSiteEx`, ou `IOleInPlaceSiteWindowless` ponteiro de interface para o controle e o armazena no membro de dados da classe de controle [CComControlBase::m_spInPlaceSite](#m_spinplacesite). Os membros de dados de classe do controle [CComControlBase::m_bInPlaceSiteEx](#m_binplacesiteex), [CComControlBase::m_bWndLess](#m_bwndless), [CComControlBase::m_bWasOnceWindowless](#m_bwasoncewindowless)e [ CComControlBase::m_bNegotiatedWnd](#m_bnegotiatedwnd) definida como verdadeira, conforme apropriado.

##  <a name="internalgetsite"></a>  CComControlBase::InternalGetSite

Chame esse método para consultar o site de controle de um ponteiro para a interface identificada.

```
HRESULT InternalGetSite(REFIID riid, void** ppUnkSite);
```

### <a name="parameters"></a>Parâmetros

*riid*<br/>
O IID do ponteiro da interface que deve ser retornado em *ppUnkSite*.

*ppUnkSite*<br/>
Endereço da variável de ponteiro que recebe o ponteiro de interface solicitado no *riid*.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Se o site oferece suporte à interface solicitada na *riid*, o ponteiro é retornado por meio do *ppUnkSite*. Caso contrário, *ppUnkSite* é definido como NULL.

##  <a name="m_bautosize"></a>  CComControlBase::m_bAutoSize

Sinalizador que indica que o controle não pode ser qualquer outro tamanho.

```
unsigned m_bAutoSize:1;
```

### <a name="remarks"></a>Comentários

Esse sinalizador é verificado pela `IOleObjectImpl::SetExtent` e, se for TRUE, faz com que a função retornar E_FAIL.

> [!NOTE]
>  Para usar este membro de dados dentro de sua classe de controle, você deve declará-la como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele está declarado dentro de uma união na classe base.

Se você adicionar o **AutoDimensionar** opção a [propriedades do estoque](../../atl/reference/stock-properties-atl-control-wizard.md) guia do Assistente de controle da ATL, o assistente automaticamente cria esse membro de dados em sua classe de controle, cria um put e métodos para a propriedade get e suporta [IPropertyNotifySink](/windows/desktop/api/ocidl/nn-ocidl-ipropertynotifysink) para notificar o contêiner automaticamente quando a propriedade é alterada.

##  <a name="m_bdrawfromnatural"></a>  CComControlBase::m_bDrawFromNatural

Sinalizador que indica que `IDataObjectImpl::GetData` e `CComControlBase::GetZoomInfo` deve definir o tamanho do controle de `m_sizeNatural` , em vez de `m_sizeExtent`.

```
unsigned m_bDrawFromNatural:1;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Para usar este membro de dados dentro de sua classe de controle, você deve declará-la como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele está declarado dentro de uma união na classe base.

##  <a name="m_bdrawgetdatainhimetric"></a>  CComControlBase::m_bDrawGetDataInHimetric

Sinalizador que indica que `IDataObjectImpl::GetData` devem usar unidades HIMETRIC e não em pixels, ao desenhar.

```
unsigned m_bDrawGetDataInHimetric:1;
```

### <a name="remarks"></a>Comentários

Cada unidade lógica de HIMETRIC é 0,01 milímetro.

> [!NOTE]
>  Para usar este membro de dados dentro de sua classe de controle, você deve declará-la como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele está declarado dentro de uma união na classe base.

##  <a name="m_binplaceactive"></a>  CComControlBase::m_bInPlaceActive

Sinalizador que indica que o controle está ativo no local.

```
unsigned m_bInPlaceActive:1;
```

### <a name="remarks"></a>Comentários

Isso significa que o controle está visível e sua janela, se houver, está visível, mas seus menus e barras de ferramentas não podem estar ativos. O `m_bUIActive` sinalizador indica a interface do usuário do controle, como menus, também está ativo.

> [!NOTE]
>  Para usar este membro de dados dentro de sua classe de controle, você deve declará-la como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele está declarado dentro de uma união na classe base.

##  <a name="m_binplacesiteex"></a>  CComControlBase::m_bInPlaceSiteEx

Sinalizador que indica o dá suporte a contêiner o `IOleInPlaceSiteEx` interface e OCX96 controlam os recursos, tais como controles sem janelas e sem cintilações.

```
unsigned m_bInPlaceSiteEx:1;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Para usar este membro de dados dentro de sua classe de controle, você deve declará-la como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele está declarado dentro de uma união na classe base.

O membro de dados `m_spInPlaceSite` aponta para um [IOleInPlaceSite](/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite), [IOleInPlaceSiteEx](/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesiteex), ou [IOleInPlaceSiteWindowless](/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesitewindowless) interface, dependendo do valor da `m_bWndLess` e `m_bInPlaceSiteEx` sinalizadores. (O membro de dados `m_bNegotiatedWnd` deve ser verdadeiro para o `m_spInPlaceSite` ponteiro seja válido.)

Se `m_bWndLess` é FALSE e `m_bInPlaceSiteEx` for TRUE, `m_spInPlaceSite` é um `IOleInPlaceSiteEx` ponteiro de interface. Ver [m_spInPlaceSite](#m_spinplacesite) para uma tabela que mostra a relação entre esses membros de dados de três.

##  <a name="m_bnegotiatedwnd"></a>  CComControlBase::m_bNegotiatedWnd

Sinalizador que indica se ou não o controle tem negociado com o contêiner sobre o suporte para recursos de controle de OCX96 (como controles sem janelas e cintilação) e se o controle é em janelas ou sem janelas.

```
unsigned m_bNegotiatedWnd:1;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Para usar este membro de dados dentro de sua classe de controle, você deve declará-la como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele está declarado dentro de uma união na classe base.

O `m_bNegotiatedWnd` sinalizador deve ser verdadeiro para o `m_spInPlaceSite` ponteiro seja válido.

##  <a name="m_brecomposeonresize"></a>  CComControlBase::m_bRecomposeOnResize

Sinalizador que indica que o controle deseja recompor sua apresentação quando o contêiner de tamanho de exibição do controle é alterado.

```
unsigned m_bRecomposeOnResize:1;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Para usar este membro de dados dentro de sua classe de controle, você deve declará-la como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele está declarado dentro de uma união na classe base.

Esse sinalizador é verificado pela [IOleObjectImpl::SetExtent](../../atl/reference/ioleobjectimpl-class.md#setextent) e, se for TRUE, `SetExtent` notifica o contêiner de alterações de modo de exibição. Se esse sinalizador estiver definido, o OLEMISC_RECOMPOSEONRESIZE bit na [OLEMISC](/windows/desktop/api/oleidl/ne-oleidl-tagolemisc) enumeração também deve ser definida.

##  <a name="m_brequiressave"></a>  CComControlBase::m_bRequiresSave

Sinalizador que indica que o controle foi alterado desde que foi salvo pela última vez.

```
unsigned m_bRequiresSave:1;
```

### <a name="remarks"></a>Comentários

O valor de `m_bRequiresSave` pode ser definido com [CComControlBase::SetDirty](#setdirty) e recuperados com [CComControlBase::GetDirty](#getdirty).

> [!NOTE]
>  Para usar este membro de dados dentro de sua classe de controle, você deve declará-la como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele está declarado dentro de uma união na classe base.

##  <a name="m_bresizenatural"></a>  CComControlBase::m_bResizeNatural

Sinalizador que indica o controle deseja redimensionar sua extensão natural (seu tamanho físico fora de escala) quando o contêiner altera o tamanho da exibição do controle.

```
unsigned m_bResizeNatural:1;
```

### <a name="remarks"></a>Comentários

Esse sinalizador é verificado pela `IOleObjectImpl::SetExtent` e, se for TRUE, o tamanho passado para `SetExtent` é atribuído a `m_sizeNatural`.

O tamanho passado para `SetExtent` sempre é atribuído a `m_sizeExtent`, independentemente do valor de `m_bResizeNatural`.

> [!NOTE]
>  Para usar este membro de dados dentro de sua classe de controle, você deve declará-la como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele está declarado dentro de uma união na classe base.

##  <a name="m_buiactive"></a>  CComControlBase::m_bUIActive

Sinalizador que indica a interface do usuário do controle, como menus e barras de ferramentas está ativo.

```
unsigned m_bUIActive:1;
```

### <a name="remarks"></a>Comentários

O `m_bInPlaceActive` sinalizador indica que o controle está ativo, mas não que sua interface do usuário está ativa.

> [!NOTE]
>  Para usar este membro de dados dentro de sua classe de controle, você deve declará-la como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele está declarado dentro de uma união na classe base.

##  <a name="m_busingwindowrgn"></a>  CComControlBase::m_bUsingWindowRgn

Sinalizador que indica que o controle está usando a região da janela fornecido pelo contêiner.

```
unsigned m_bUsingWindowRgn:1;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Para usar este membro de dados dentro de sua classe de controle, você deve declará-la como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele está declarado dentro de uma união na classe base.

##  <a name="m_bwasoncewindowless"></a>  CComControlBase::m_bWasOnceWindowless

Sinalizador que indica o controle tiver sido sem janelas, mas pode ou não ser sem janelas agora.

```
unsigned m_bWasOnceWindowless:1;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Para usar este membro de dados dentro de sua classe de controle, você deve declará-la como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele está declarado dentro de uma união na classe base.

##  <a name="m_bwindowonly"></a>  CComControlBase::m_bWindowOnly

Sinalizador que indica que o controle deve ser em janelas, mesmo se o contêiner dá suporte a controles sem janelas.

```
unsigned m_bWindowOnly:1;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Para usar este membro de dados dentro de sua classe de controle, você deve declará-la como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele está declarado dentro de uma união na classe base.

##  <a name="m_bwndless"></a>  CComControlBase::m_bWndLess

Sinalizador que indica que o controle for sem janelas.

```
unsigned m_bWndLess:1;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Para usar este membro de dados dentro de sua classe de controle, você deve declará-la como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele está declarado dentro de uma união na classe base.

O membro de dados `m_spInPlaceSite` aponta para um [IOleInPlaceSite](/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite), [IOleInPlaceSiteEx](/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesiteex), ou [IOleInPlaceSiteWindowless](/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesitewindowless) interface, dependendo do valor da `m_bWndLess` e [CComControlBase::m_bInPlaceSiteEx](#m_binplacesiteex) sinalizadores. (O membro de dados [CComControlBase::m_bNegotiatedWnd](#m_bnegotiatedwnd) deve ser verdadeiro para o [CComControlBase::m_spInPlaceSite](#m_spinplacesite) ponteiro seja válido.)

Se `m_bWndLess` for TRUE, `m_spInPlaceSite` é um `IOleInPlaceSiteWindowless` ponteiro de interface. Ver [CComControlBase::m_spInPlaceSite](#m_spinplacesite) para uma tabela que mostra a relação completa entre esses membros de dados.

##  <a name="m_hwndcd"></a>  CComControlBase::m_hWndCD

Contém uma referência para o identificador de janela associado ao controle.

```
HWND& m_hWndCD;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Para usar este membro de dados dentro de sua classe de controle, você deve declará-la como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele está declarado dentro de uma união na classe base.

##  <a name="m_nfreezeevents"></a>  CComControlBase::m_nFreezeEvents

Uma contagem do número de vezes que o contêiner congelou (se recusou a aceitar eventos) de eventos sem uma intervenção descongelar de eventos (aceitação de eventos).

```
short m_nFreezeEvents;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Para usar este membro de dados dentro de sua classe de controle, você deve declará-la como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele está declarado dentro de uma união na classe base.

##  <a name="m_rcpos"></a>  CComControlBase::m_rcPos

A posição em pixels do controle, expressada em coordenadas de contêiner.

```
RECT m_rcPos;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Para usar este membro de dados dentro de sua classe de controle, você deve declará-la como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele está declarado dentro de uma união na classe base.

##  <a name="m_sizeextent"></a>  CComControlBase::m_sizeExtent

A extensão do controle em unidades HIMETRIC (cada unidade 0,01 milímetros) para um determinado vídeo.

```
SIZE m_sizeExtent;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Para usar este membro de dados dentro de sua classe de controle, você deve declará-la como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele está declarado dentro de uma união na classe base.

Esse tamanho é dimensionado por exibição. O tamanho do controle físico é especificado no `m_sizeNatural` membro de dados e é fixo.

Você pode converter o tamanho em pixels com a função global [AtlHiMetricToPixel](pixel-himetric-conversion-global-functions.md#atlhimetrictopixel).

##  <a name="m_sizenatural"></a>  CComControlBase::m_sizeNatural

O tamanho físico do controle em unidades HIMETRIC (cada unidade 0,01 milímetros).

```
SIZE m_sizeNatural;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Para usar este membro de dados dentro de sua classe de controle, você deve declará-la como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele está declarado dentro de uma união na classe base.

Esse tamanho é fixo, enquanto o tamanho em `m_sizeExtent` é dimensionado por exibição.

Você pode converter o tamanho em pixels com a função global [AtlHiMetricToPixel](pixel-himetric-conversion-global-functions.md#atlhimetrictopixel).

##  <a name="m_spadvisesink"></a>  CComControlBase::m_spAdviseSink

Um ponteiro direto para a conexão de consultoria no contêiner (o contêiner [IAdviseSink](/windows/desktop/api/objidl/nn-objidl-iadvisesink)).

```
CComPtr<IAdviseSink>
    m_spAdviseSink;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Para usar este membro de dados dentro de sua classe de controle, você deve declará-la como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele está declarado dentro de uma união na classe base.

##  <a name="m_spambientdispatch"></a>  CComControlBase::m_spAmbientDispatch

Um `CComDispatchDriver` objeto que permite recuperar e definir propriedades de um objeto por meio de um `IDispatch` ponteiro.

```
CComDispatchDriver m_spAmbientDispatch;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Para usar este membro de dados dentro de sua classe de controle, você deve declará-la como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele está declarado dentro de uma união na classe base.

##  <a name="m_spclientsite"></a>  CComControlBase::m_spClientSite

Um ponteiro para o site do cliente do controle dentro do contêiner.

```
CComPtr<IOleClientSite>
    m_spClientSite;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Para usar este membro de dados dentro de sua classe de controle, você deve declará-la como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele está declarado dentro de uma união na classe base.

##  <a name="m_spdataadviseholder"></a>  CComControlBase::m_spDataAdviseHolder

Fornece um padrão significa que manter as conexões de consultoria entre objetos de dados e Coletores de aviso.

```
CComPtr<IDataAdviseHolder>
    m_spDataAdviseHolder;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Para usar este membro de dados dentro de sua classe de controle, você deve declará-la como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele está declarado dentro de uma união na classe base.

Um objeto de dados é um controle que pode transferir dados e que implementa [IDataObject](/windows/desktop/api/objidl/nn-objidl-idataobject), cujos métodos especificam a mídia de formato e transferência de dados.

A interface `m_spDataAdviseHolder` implementa o [IDataObject::DAdvise](/windows/desktop/api/objidl/nf-objidl-idataobject-dadvise) e [IDataObject::DUnadvise](/windows/desktop/api/objidl/nf-objidl-idataobject-dunadvise) métodos para estabelecer e excluir conexões de consultoria para o contêiner. O contêiner do controle deve implementar um coletor de aviso, oferecendo suporte a [IAdviseSink](/windows/desktop/api/objidl/nn-objidl-iadvisesink) interface.

##  <a name="m_spinplacesite"></a>  CComControlBase::m_spInPlaceSite

Um ponteiro para o contêiner [IOleInPlaceSite](/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite), [IOleInPlaceSiteEx](/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesiteex), ou [IOleInPlaceSiteWindowless](/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesitewindowless) ponteiro de interface.

```
CComPtr<IOleInPlaceSiteWindowless>
    m_spInPlaceSite;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Para usar este membro de dados dentro de sua classe de controle, você deve declará-la como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele está declarado dentro de uma união na classe base.

O `m_spInPlaceSite` ponteiro é válido somente se o [m_bNegotiatedWnd](#m_bnegotiatedwnd) sinalizador é verdadeiro.

A tabela a seguir mostra como o `m_spInPlaceSite` depende do tipo de ponteiro a [m_bWndLess](#m_bwndless) e [m_bInPlaceSiteEx](#m_binplacesiteex) sinalizadores de membro de dados:

|Tipo de m_spInPlaceSite|m_bWndLess valor|m_bInPlaceSiteEx valor|
|---------------------------|-----------------------|-----------------------------|
|`IOleInPlaceSiteWindowless`|TRUE|VERDADEIRO ou falso|
|`IOleInPlaceSiteEx`|FALSE|TRUE|
|`IOleInPlaceSite`|FALSE|FALSE|

##  <a name="m_spoleadviseholder"></a>  CComControlBase::m_spOleAdviseHolder

Fornece uma implementação padrão de uma maneira de manter conexões de consultoria.

```
CComPtr<IOleAdviseHolder>
    m_spOleAdviseHolder;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Para usar este membro de dados dentro de sua classe de controle, você deve declará-la como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele está declarado dentro de uma união na classe base.

A interface `m_spOleAdviseHolder` implementa o [IOleObject::Advise](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-advise) e [IOleObject::Unadvise](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-unadvise) métodos para estabelecer e excluir conexões de consultoria para o contêiner. O contêiner do controle deve implementar um coletor de aviso, oferecendo suporte a [IAdviseSink](/windows/desktop/api/objidl/nn-objidl-iadvisesink) interface.

##  <a name="ondraw"></a>  CComControlBase::OnDraw

Substitua este método para desenhar seu controle.

```
virtual HRESULT OnDraw(ATL_DRAWINFO& di);
```

### <a name="parameters"></a>Parâmetros

*injeção de dependência*<br/>
Uma referência para o [ATL_DRAWINFO](../../atl/reference/atl-drawinfo-structure.md) estrutura que contém informações de desenho, como o aspecto de desenho, os limites do controle, e o desenho otimizado ou não.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

O padrão `OnDraw` exclui ou restaura o contexto de dispositivo ou não faz nada, dependendo de sinalizadores definidos no [CComControlBase::OnDrawAdvanced](#ondrawadvanced).

Um `OnDraw` método é adicionado automaticamente à sua classe de controle quando você cria o controle com o Assistente de controle do ATL. Padrão do assistente `OnDraw` desenha um retângulo com o rótulo "ATL 8.0".

### <a name="example"></a>Exemplo

Veja o exemplo de [CComControlBase::GetAmbientAppearance](#getambientappearance).

##  <a name="ondrawadvanced"></a>  CComControlBase::OnDrawAdvanced

O padrão `OnDrawAdvanced` prepara um contexto de dispositivo normalizado para desenhar e, em seguida, chama sua classe de controle `OnDraw` método.

```
virtual HRESULT OnDrawAdvanced(ATL_DRAWINFO& di);
```

### <a name="parameters"></a>Parâmetros

*injeção de dependência*<br/>
Uma referência para o [ATL_DRAWINFO](../../atl/reference/atl-drawinfo-structure.md) estrutura que contém informações de desenho, como o aspecto de desenho, os limites do controle, e o desenho otimizado ou não.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Substitua este método se você quiser aceitar o contexto de dispositivo que passou pelo contêiner sem ser normalizado.

Ver [CComControlBase::OnDraw](#ondraw) para obter mais detalhes.

##  <a name="onkillfocus"></a>  CComControlBase::OnKillFocus

Verifica se o controle está ativo no local e tem um site de controle válido e informa o contêiner que o controle perdeu o foco.

```
LRESULT OnKillFocus(UINT /* nMsg */,
    WPARAM /* wParam */,
    LPARAM /* lParam */,
    BOOL& bHandled);
```

### <a name="parameters"></a>Parâmetros

*nMsg*<br/>
Reservado.

*wParam*<br/>
Reservado.

*lParam*<br/>
Reservado.

*bHandled*<br/>
Sinalizador que indica se a mensagem de janela foi tratada com êxito. O padrão é FALSE.

### <a name="return-value"></a>Valor de retorno

Sempre retorna 1.

##  <a name="onmouseactivate"></a>  CComControlBase::OnMouseActivate

Verifica que a interface do usuário está no modo de usuário e, em seguida, ativa o controle.

```
LRESULT OnMouseActivate(UINT /* nMsg */,
    WPARAM /* wParam */,
    LPARAM /* lParam */,
    BOOL& bHandled);
```

### <a name="parameters"></a>Parâmetros

*nMsg*<br/>
Reservado.

*wParam*<br/>
Reservado.

*lParam*<br/>
Reservado.

*bHandled*<br/>
Sinalizador que indica se a mensagem de janela foi tratada com êxito. O padrão é FALSE.

### <a name="return-value"></a>Valor de retorno

Sempre retorna 1.

##  <a name="onpaint"></a>  CComControlBase::OnPaint

Prepara o contêiner para pintura, obtém a área de cliente do controle, em seguida, chama a classe de controle `OnDrawAdvanced` método.

```
LRESULT OnPaint(UINT /* nMsg */,
    WPARAM wParam,
    LPARAM /* lParam */,
    BOOL& /* lResult */);
```

### <a name="parameters"></a>Parâmetros

*nMsg*<br/>
Reservado.

*wParam*<br/>
HDC um existente.

*lParam*<br/>
Reservado.

*lResult*<br/>
Reservado.

### <a name="return-value"></a>Valor de retorno

Sempre retorna zero.

### <a name="remarks"></a>Comentários

Se *wParam* não for nulo, `OnPaint` pressupõe que ele contém um HDC válido e usa-em vez de [CComControlBase::m_hWndCD](#m_hwndcd).

##  <a name="onsetfocus"></a>  CComControlBase::OnSetFocus

Verificações que o controle está ativo no local e tem um site de controle válido e informa o contêiner de controle ganhou o foco.

```
LRESULT OnSetFocus(UINT /* nMsg */,
    WPARAM /* wParam */,
    LPARAM /* lParam */,
    BOOL& bHandled);
```

### <a name="parameters"></a>Parâmetros

*nMsg*<br/>
Reservado.

*wParam*<br/>
Reservado.

*lParam*<br/>
Reservado.

*bHandled*<br/>
Sinalizador que indica se a mensagem de janela foi tratada com êxito. O padrão é FALSE.

### <a name="return-value"></a>Valor de retorno

Sempre retorna 1.

### <a name="remarks"></a>Comentários

Envia uma notificação para o contêiner que o controle recebeu o foco.

##  <a name="pretranslateaccelerator"></a>  CComControlBase::PreTranslateAccelerator

Substitua este método para fornecer seu próprio teclado manipuladores de acelerador.

```
BOOL PreTranslateAccelerator(LPMSG /* pMsg */,
    HRESULT& /* hRet */);
```

### <a name="parameters"></a>Parâmetros

*pMsg*<br/>
Reservado.

*hRet*<br/>
Reservado.

### <a name="return-value"></a>Valor de retorno

Por padrão, retorna FALSE.

##  <a name="sendonclose"></a>  CComControlBase::SendOnClose

Notifica os coletores de todos os de supervisão registrados com o detentor de avisos que o controle foi fechado.

```
HRESULT SendOnClose();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Envia uma notificação de que o controle tiver fechado seu Coletores de supervisão.

##  <a name="sendondatachange"></a>  CComControlBase::SendOnDataChange

Notifica os coletores de todos os de supervisão registrados com o detentor da advise que os dados de controle foi alterado.

```
HRESULT SendOnDataChange(DWORD advf = 0);
```

### <a name="parameters"></a>Parâmetros

*advf*<br/>
Aconselhamos sinalizadores que especificam como a chamada para [IAdviseSink::OnDataChange](/windows/desktop/api/objidl/nf-objidl-iadvisesink-ondatachange) é feita. Os valores são do [ADVF](/windows/desktop/api/objidl/ne-objidl-tagadvf) enumeração.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

##  <a name="sendonrename"></a>  CComControlBase::SendOnRename

Notifica os coletores de todos os de supervisão registrados com o detentor de avisos que o controle tem um novo moniker.

```
HRESULT SendOnRename(IMoniker* pmk);
```

### <a name="parameters"></a>Parâmetros

*PMK*<br/>
Ponteiro para o novo moniker do controle.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Envia uma notificação de que o identificador de origem para o controle foi alterado.

##  <a name="sendonsave"></a>  CComControlBase::SendOnSave

Notifica os coletores de todos os de supervisão registrados com o detentor da advise que o controle foi salvo.

```
HRESULT SendOnSave();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Envia uma notificação de que o controle acabou de salvar seus dados.

##  <a name="sendonviewchange"></a>  CComControlBase::SendOnViewChange

Notifica que todos os registrados Coletores de supervisão para exibição do controle foi alterado.

```
HRESULT SendOnViewChange(DWORD dwAspect, LONG lindex = -1);
```

### <a name="parameters"></a>Parâmetros

*dwAspect*<br/>
O aspecto ou a exibição do controle.

*lindex*<br/>
A parte da exibição que mudou. Apenas -1 é válido.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

`SendOnViewChange` chamadas [IAdviseSink::OnViewChange](/windows/desktop/api/objidl/nf-objidl-iadvisesink-onviewchange). O único valor de *lindex* atualmente com suporte é 1, que indica que toda a exibição é de interesse.

##  <a name="setcontrolfocus"></a>  CComControlBase::SetControlFocus

Define ou remove o foco do teclado de ou para o controle.

```
BOOL SetControlFocus(BOOL bGrab);
```

### <a name="parameters"></a>Parâmetros

*bGrab*<br/>
Se for TRUE, define o foco do teclado para o controle de chamada. Se for FALSE, remove o foco do teclado do controle chamado, desde que tenha o foco.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o controle com êxito recebe o foco; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Para um controle da janela, a função da API do Windows [SetFocus](/windows/desktop/api/winuser/nf-winuser-setfocus) é chamado. Para um controle sem janelas, [IOleInPlaceSiteWindowless::SetFocus](/windows/desktop/api/ocidl/nf-ocidl-ioleinplacesitewindowless-setfocus) é chamado. Por meio dessa chamada, um controle sem janelas obtém o foco do teclado e responde às mensagens de janela.

##  <a name="setdirty"></a>  CComControlBase::SetDirty

Define o membro de dados `m_bRequiresSave` ao valor na *bDirty*.

```
void SetDirty(BOOL bDirty);
```

### <a name="parameters"></a>Parâmetros

*bDirty*<br/>
Valor do membro de dados [CComControlBase::m_bRequiresSave](#m_brequiressave).

### <a name="remarks"></a>Comentários

`SetDirty(TRUE)` deve ser chamado para sinalizar que o controle foi alterado desde que foi salvo pela última vez. O valor de `m_bRequiresSave` é recuperada com [CComControlBase::GetDirty](#getdirty).

## <a name="see-also"></a>Consulte também

[Classe CComControl](../../atl/reference/ccomcontrol-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
