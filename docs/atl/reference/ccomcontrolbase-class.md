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
ms.openlocfilehash: 2420e1643444e6cbbf8edff90bbd3ecb1eac8534
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81320784"
---
# <a name="ccomcontrolbase-class"></a>Classe CComControlBase

Esta classe fornece métodos para criar e gerenciar controles ATL.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class ATL_NO_VTABLE CComControlBase
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CComControlBase::'' ''''''Aparência'.](#appearancetype)|Anular se `m_nAppearance` sua propriedade de ações não for do tipo **curto**.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComControlBase::CComControlBase](#ccomcontrolbase)|O construtor.|
|[CComControlBase::~CComControlBase](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComControlBase::ControlQueryInterface](#controlqueryinterface)|Recupera um ponteiro para a interface solicitada.|
|[CComControlBase::DoesVerbActivate](#doesverbactivate)|Verifica se o parâmetro *iVerb* usado `IOleObjectImpl::DoVerb` por ativa a interface do usuário do controle *(iVerb* é igual a OLEIVERB_UIACTIVATE), define a ação tomada quando o usuário clica duas vezes no controle *(iVerb* é igual a OLEIVERB_PRIMARY), exibe o controle *(iVerb* é igual a OLEIVERB_SHOW) ou ativa o controle *(iVerb* é igual a OLEIVERB_INPLACEACTIVATE).|
|[CComControlBase::DoesVerbUIActivate](#doesverbuiactivate)|Verifica se o parâmetro *iVerb* usado faz `IOleObjectImpl::DoVerb` com que a interface de usuário do controle seja ativada e retorna TRUE.|
|[CComControlBase::DoVerbProperties](#doverbproperties)|Exibe as páginas de propriedade do controle.|
|[CComControlBase::FireViewChange](#fireviewchange)|Ligue para este método para dizer ao contêiner para redesenhar o controle ou notificar os adescritores registrados de que a visão do controle foi alterada.|
|[CComControlBase::getAmbientAppearance](#getambientappearance)|Recupera DISPID_AMBIENT_APPEARANCE, a configuração de aparência atual para o controle: 0 para plano e 1 para 3D.|
|[CComcontrolBase::GetambientAutoClip](#getambientautoclip)|Recupera DISPID_AMBIENT_AUTOCLIP, uma bandeira indicando se o contêiner suporta o recorte automático da área de exibição de controle.|
|[CComControlBase::getambientBackColor](#getambientbackcolor)|Recupera DISPID_AMBIENT_BACKCOLOR, a cor de fundo ambiente para todos os controles, definida pelo recipiente.|
|[CcomcontrolBase::getambientcharset](#getambientcharset)|Recupera DISPID_AMBIENT_CHARSET, o conjunto de caracteres ambiente para todos os controles, definido pelo recipiente.|
|[CComControlBase::GetAmbientCodePage](#getambientcodepage)|Recupera DISPID_AMBIENT_CODEPAGE, o conjunto de caracteres ambiente para todos os controles, definido pelo recipiente.|
|[CComControlBase::getambientDisplayAsDefault](#getambientdisplayasdefault)|Recupera DISPID_AMBIENT_DISPLAYASDEFAULT, uma bandeira que é TRUE se o contêiner tiver marcado o controle neste site como um botão padrão e, portanto, um controle de botão deve desenhar-se com um quadro mais grosso.|
|[CComControlBase::GetAmbientDisplayName](#getambientdisplayname)|Recupera DISPID_AMBIENT_DISPLAYNAME, o nome que o contêiner forneceu ao controle.|
|[CComControlBase::getambientfont](#getambientfont)|Recupera um ponteiro para a `IFont` interface ambiente do contêiner.|
|[CComControlBase::GetAmbientFontDisp](#getambientfontdisp)|Recupera um ponteiro para a `IFontDisp` interface de despacho ambiente do contêiner.|
|[CComControlBase::GetAmbientForeColor](#getambientforecolor)|Recupera DISPID_AMBIENT_FORECOLOR, a cor do primeiro plano ambiente para todos os controles, definida pelo recipiente.|
|[CComControlBase::GetAmbientLocaleID](#getambientlocaleid)|Recupera DISPID_AMBIENT_LOCALEID, o identificador da linguagem usada pelo recipiente.|
|[CcomcontrolBase::getambientMessageReflect](#getambientmessagereflect)|Recupera DISPID_AMBIENT_MESSAGEREFLECT, uma bandeira indicando se o contêiner quer receber mensagens de janela (como WM_DRAWITEM) como eventos.|
|[CComControlBase::GetAmbientPalette](#getambientpalette)|Recupera DISPID_AMBIENT_PALETTE, usado para acessar o HPALETTE do contêiner.|
|[CComControlBase::getAmbientProperty](#getambientproperty)|Recupera a propriedade do contêiner especificada por *id*.|
|[CcomcontrolBase::getambientrighttoleft](#getambientrighttoleft)|Recupera DISPID_AMBIENT_RIGHTTOLEFT, a direção em que o conteúdo é exibido pelo recipiente.|
|[CComControlBase::getAmbientScaleUnits](#getambientscaleunits)|Recupera DISPID_AMBIENT_SCALEUNITS, as unidades ambientedo recipiente (como polegadas ou centímetros) para os displays de rotulagem.|
|[CComControlBase::GetAmbientShowGrabHandles](#getambientshowgrabhandles)|Recupera DISPID_AMBIENT_SHOWGRABHANDLES, uma bandeira indicando se o recipiente permite que o controle exiba alças de agarramento para si mesmo quando ativo.|
|[CComControlBase::GetAmbientShowHatching](#getambientshowhatching)|Recupera DISPID_AMBIENT_SHOWHATCHING, uma bandeira indicando se o contêiner permite que o controle se exiba com um padrão eclodido quando a ia está ativa.|
|[CComControlBase::GetAmbientSupportSMnemonics](#getambientsupportsmnemonics)|Recupera DISPID_AMBIENT_SUPPORTSMNEMONICS, uma bandeira indicando se o contêiner suporta mnemônicos do teclado.|
|[CComControlBase::GetAmbientTextalign](#getambienttextalign)|Recupera DISPID_AMBIENT_TEXTALIGN, o alinhamento de texto preferido pelo contêiner: 0 para alinhamento geral (números à direita, texto à esquerda), 1 para alinhamento à esquerda, 2 para alinhamento central e 3 para alinhamento à direita.|
|[CcomcontrolBase::getambienttoptoBottom](#getambienttoptobottom)|Recupera DISPID_AMBIENT_TOPTOBOTTOM, a direção em que o conteúdo é exibido pelo recipiente.|
|[CcomcontrolBase::getambientuidead](#getambientuidead)|Recupera DISPID_AMBIENT_UIDEAD, uma bandeira indicando se o contêiner quer que o controle responda às ações de interface do usuário.|
|[CComControlBase::getambientUsermode](#getambientusermode)|Recupera DISPID_AMBIENT_USERMODE, um sinalizador indicando se o contêiner está no modo de execução (TRUE) ou no modo de design (FALSE).|
|[CComControlBase::GetDirty](#getdirty)|Retorna o valor `m_bRequiresSave`do membro de dados .|
|[CComControlBase::getZoomInfo](#getzoominfo)|Recupera os valores x e y do numerador e denominador do fator zoom para um controle ativado para edição no local.|
|[CcomControlBase::InplaceActivate](#inplaceactivate)|Faz com que o controle transite do estado inativo para qualquer estado que o verbo em *iVerb* indica.|
|[CComControlBase::InternalGetSite](#internalgetsite)|Chame este método para consultar o site de controle para obter um ponteiro para a interface identificada.|
|[CComControlBase::OnDraw](#ondraw)|Anular este método para desenhar seu controle.|
|[CComControlBase::OnDrawAdvanced](#ondrawadvanced)|O `OnDrawAdvanced` padrão prepara um contexto de dispositivo normalizado para `OnDraw` desenho e, em seguida, chama o método da classe de controle.|
|[CComControlBase::OnKillFocus](#onkillfocus)|Verifica se o controle está ativo no local e tem um local de controle válido, em seguida, informa o contêiner que o controle perdeu o foco.|
|[CComControlBase::OnMouseActivate](#onmouseactivate)|Verifica se a ui está no modo de usuário e, em seguida, ativa o controle.|
|[CComControlBase::OnPaint](#onpaint)|Prepara o recipiente para pintura, obtém a área de cliente `OnDraw` do controle e chama o método da classe de controle.|
|[CComControlBase::OnSetFocus](#onsetfocus)|Verifica se o controle está ativo no local e tem um local de controle válido, então informa o contêiner que o controle ganhou foco.|
|[CComControlBase::PreTranslateAccelerator](#pretranslateaccelerator)|Anule este método para fornecer seus próprios manipuladores do acelerador de teclado.|
|[CcomcontrolBase::SendonClose](#sendonclose)|Notifica todos os avisos registrados com o titular da assessoria de que o controle foi fechado.|
|[CcomControlBase::SendonDataChange](#sendondatachange)|Notifica todos os registros de avisos registrados com o titular da assessoria de que os dados de controle foram alterados.|
|[CComControlBase::SendOnRename](#sendonrename)|Notifica todos os afundamentos de aviso registrados com o titular da assessoria de que o controle tem um novo apelido.|
|[CcomControlBase::SendonSave](#sendonsave)|Notifica todos os afundamentos de aviso registrados com o titular do aviso de que o controle foi salvo.|
|[CcomcontrolBase::SendonViewChange](#sendonviewchange)|Notifica todos os avisos registrados de que a visão do controle mudou.|
|[CComControlBase::SetControlFocus](#setcontrolfocus)|Define ou remove o foco do teclado para ou do controle.|
|[CComControlBase::SetDirty](#setdirty)|Define o `m_bRequiresSave` membro de dados para o valor em *bDirty*.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComControlBase::m_bAutoSize](#m_bautosize)|A bandeira indicando o controle não pode ser de outro tamanho.|
|[CComControlBase::m_bDrawFromNatural](#m_bdrawfromnatural)|Bandeira indicando `IDataObjectImpl::GetData` `CComControlBase::GetZoomInfo` isso e deve `m_sizeNatural` definir o `m_sizeExtent`tamanho do controle em vez de .|
|[CComControlBase::m_bDrawGetDataInHimetric](#m_bdrawgetdatainhimetric)|Sinalizador indicando `IDataObjectImpl::GetData` que deve usar unidades HIMETRIC e não pixels ao desenhar.|
|[CComControlBase::m_bInPlaceActive](#m_binplaceactive)|Bandeira indicando que o controle está ativo no local.|
|[CComControlBase::m_bInPlaceSiteEx](#m_binplacesiteex)|O sinalizador indicando que `IOleInPlaceSiteEx` o contêiner suporta os recursos de controle da interface e do OCX96, como controles sem janelas e sem cintilação.|
|[CComControlBase::m_bNegotiatedWnd](#m_bnegotiatedwnd)|Sinalizador indicando se o controle negociou ou não com o contêiner sobre o suporte para recursos de controle OCX96 (como controles sem flicker e sem janelas), e se o controle está ou não sem janelas.|
|[CComControlBase::m_bRecomposeOnResize](#m_brecomposeonresize)|Sinalizador indicando que o controle deseja recompor sua apresentação quando o contêiner altera o tamanho do display do controle.|
|[CComControlBase::m_bRequiresSave](#m_brequiressave)|Bandeira indicando que o controle mudou desde a última salva.|
|[CComControlBase::m_bResizeNatural](#m_bresizenatural)|Bandeira indicando que o controle deseja redimensionar sua extensão natural (seu tamanho físico não dimensionado) quando o recipiente altera o tamanho do display do controle.|
|[CComControlBase::m_bUIActive](#m_buiactive)|O sinalizador indicando a interface de usuário do controle, como menus e barras de ferramentas, está ativo.|
|[CComControlBase::m_bUsingWindowRgn](#m_busingwindowrgn)|A bandeira indicando que o controle está usando a região da janela fornecida pelo contêiner.|
|[CComControlBase::m_bWasOnceWindowless](#m_bwasoncewindowless)|A bandeira indicando que o controle foi sem janelas, mas pode ou não estar sem janelas agora.|
|[CComControlBase::m_bWindowOnly](#m_bwindowonly)|A bandeira indicando que o controle deve ser janelas, mesmo que o contêiner suporte controles sem janelas.|
|[CComControlBase::m_bWndLess](#m_bwndless)|A bandeira indicando que o controle não tem janelas.|
|[CComControlBase::m_hWndCD](#m_hwndcd)|Contém uma referência à alça da janela associada ao controle.|
|[CComControlBase::m_nFreezeEvents](#m_nfreezeevents)|Uma contagem do número de vezes que o contêiner congelou eventos (se recusou a aceitar eventos) sem um degelo intervindo de eventos (aceitação de eventos).|
|[CComControlBase::m_rcPos](#m_rcpos)|A posição nos pixels do controle, expressa nas coordenadas do recipiente.|
|[CComControlBase::m_sizeExtent](#m_sizeextent)|A extensão do controle em unidades HIMETRIC (cada unidade é de 0,01 milímetros) para um display específico.|
|[CComControlBase::m_sizeNatural](#m_sizenatural)|O tamanho físico do controle em unidades HIMETRIC (cada unidade é de 0,01 milímetros).|
|[CComControlBase::m_spAdviseSink](#m_spadvisesink)|Um ponteiro direto para a conexão consultiva no recipiente (o [IAdviseSink](/windows/win32/api/objidl/nn-objidl-iadvisesink)do recipiente ).|
|[CComControlBase::m_spAmbientDispatch](#m_spambientdispatch)|Um `CComDispatchDriver` objeto que permite recuperar e definir as `IDispatch` propriedades do contêiner através de um ponteiro.|
|[CComControlBase::m_spClientSite](#m_spclientsite)|Um ponteiro para o site do cliente do controle dentro do contêiner.|
|[CComControlBase::m_spDataAdviseHolder](#m_spdataadviseholder)|Fornece um meio padrão para manter conexões consultivas entre objetos de dados e aconselhar sinks.|
|[CComControlBase::m_spInPlaceSite](#m_spinplacesite)|Um ponteiro para o ponteiro de interface [IOleInPlaceSite](/windows/win32/api/oleidl/nn-oleidl-ioleinplacesite)do contêiner, [IOleInPlaceSiteEx](/windows/win32/api/ocidl/nn-ocidl-ioleinplacesiteex)ou [iOleInPlaceSiteWindows](/windows/win32/api/ocidl/nn-ocidl-ioleinplacesitewindowless) ponteiro de interface.|
|[CComControlBase::m_spOleAdviseHolder](#m_spoleadviseholder)|Fornece uma implementação padrão de uma maneira de manter conexões consultivas.|

## <a name="remarks"></a>Comentários

Esta classe fornece métodos para criar e gerenciar controles ATL. [CComControl Class](../../atl/reference/ccomcontrol-class.md) deriva `CComControlBase`de . Quando você cria um controle padrão ou controle DHTML usando o Assistente de `CComControlBase`Controle ATL, o assistente derivará automaticamente sua classe de .

Para obter mais informações sobre como criar um controle, consulte o [Tutorial ATL](../../atl/active-template-library-atl-tutorial.md). Para obter mais informações sobre o ASSISTENTE DE PROJETO ATL, consulte o artigo [Criando um Projeto ATL](../../atl/reference/creating-an-atl-project.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

## <a name="ccomcontrolbaseappearancetype"></a><a name="appearancetype"></a>CComControlBase::'' ''''''Aparência'.

Anular se `m_nAppearance` sua propriedade de ações não for do tipo **curto**.

```
typedef short AppearanceType;
```

### <a name="remarks"></a>Comentários

O ASSISTENTE DE `m_nAppearance` CONTROLE ATL adiciona propriedade de estoque do tipo curto. Anular `AppearanceType` se você usar um tipo de dados diferente.

## <a name="ccomcontrolbaseccomcontrolbase"></a><a name="ccomcontrolbase"></a>CComControlBase::CComControlBase

O construtor.

```
CComControlBase(HWND& h);
```

### <a name="parameters"></a>Parâmetros

*H*<br/>
A alça da janela associada ao controle.

### <a name="remarks"></a>Comentários

Inicializa o tamanho do controle para 5080X5080 unidades HIMETRIC (2"X2") e inicializa os valores do membro de `CComControlBase` dados para NULL ou FALSE.

## <a name="ccomcontrolbaseccomcontrolbase"></a><a name="dtor"></a>CComControlBase::~CComControlBase

O destruidor.

```
~CComControlBase();
```

### <a name="remarks"></a>Comentários

Se o controle estiver `~CComControlBase` com janelas, destrua-o chamando [DestroyWindow](/windows/win32/api/winuser/nf-winuser-destroywindow).

## <a name="ccomcontrolbasecontrolqueryinterface"></a><a name="controlqueryinterface"></a>CComControlBase::ControlQueryInterface

Recupera um ponteiro para a interface solicitada.

```
virtual HRESULT ControlQueryInterface(const IID& iid,
    void** ppv);
```

### <a name="parameters"></a>Parâmetros

*Iid*<br/>
O GUID da interface que está sendo solicitada.

*Ppv*<br/>
Um ponteiro para o ponteiro de interface identificado por *iid*ou NULL se a interface não for encontrada.

### <a name="remarks"></a>Comentários

Apenas lida com interfaces na tabela de mapas COM.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#15](../../atl/codesnippet/cpp/ccomcontrolbase-class_1.cpp)]

## <a name="ccomcontrolbasedoesverbactivate"></a><a name="doesverbactivate"></a>CComControlBase::DoesVerbActivate

Verifica se o parâmetro *iVerb* usado `IOleObjectImpl::DoVerb` por ativa a interface do usuário do controle *(iVerb* é igual a OLEIVERB_UIACTIVATE), define a ação tomada quando o usuário clica duas vezes no controle *(iVerb* é igual a OLEIVERB_PRIMARY), exibe o controle *(iVerb* é igual a OLEIVERB_SHOW) ou ativa o controle *(iVerb* é igual a OLEIVERB_INPLACEACTIVATE).

```
BOOL DoesVerbActivate(LONG iVerb);
```

### <a name="parameters"></a>Parâmetros

*Iverb*<br/>
Valor indicando a ação `DoVerb`a ser realizada por .

### <a name="return-value"></a>Valor retornado

Retorna TRUE se *iVerb* for igual a OLEIVERB_UIACTIVATE, OLEIVERB_PRIMARY, OLEIVERB_SHOW ou OLEIVERB_INPLACEACTIVATE; caso contrário, retorna FALSO.

### <a name="remarks"></a>Comentários

Você pode substituir este método para definir seu próprio verbo de ativação.

## <a name="ccomcontrolbasedoesverbuiactivate"></a><a name="doesverbuiactivate"></a>CComControlBase::DoesVerbUIActivate

Verifica se o parâmetro *iVerb* usado faz `IOleObjectImpl::DoVerb` com que a interface de usuário do controle seja ativada e retorna TRUE.

```
BOOL DoesVerbUIActivate(LONG iVerb);
```

### <a name="parameters"></a>Parâmetros

*Iverb*<br/>
Valor indicando a ação `DoVerb`a ser realizada por .

### <a name="return-value"></a>Valor retornado

Retorna TRUE se *iVerb* for igual a OLEIVERB_UIACTIVATE, OLEIVERB_PRIMARY, OLEIVERB_SHOW ou OLEIVERB_INPLACEACTIVATE. Caso contrário, o método retorna FALSO.

## <a name="ccomcontrolbasedoverbproperties"></a><a name="doverbproperties"></a>CComControlBase::DoVerbProperties

Exibe as páginas de propriedade do controle.

```
HRESULT DoVerbProperties(LPCRECT /* prcPosRect */, HWND hwndParent);
```

### <a name="parameters"></a>Parâmetros

*prcPosRec*<br/>
Reservado.

*Hwndparent*<br/>
Alça da janela contendo o controle.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#19](../../atl/codesnippet/cpp/ccomcontrolbase-class_2.cpp)]

[!code-cpp[NVC_ATL_COM#20](../../atl/codesnippet/cpp/ccomcontrolbase-class_3.h)]

## <a name="ccomcontrolbasefireviewchange"></a><a name="fireviewchange"></a>CComControlBase::FireViewChange

Ligue para este método para dizer ao contêiner para redesenhar o controle ou notificar os adescritores registrados de que a visão do controle foi alterada.

```
HRESULT FireViewChange();
```

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

### <a name="remarks"></a>Comentários

Se o controle estiver ativo (o membro da classe de controle [CComControlBase::m_bInPlaceActive](#m_binplaceactive) é TRUE), notificará o contêiner que deseja redesenhar todo o controle. Se o controle estiver inativo, notificará a recomendação registrada do controle (através do membro da classe de controle [CComControlBase::m_spAdviseSink)](#m_spadvisesink)de que a exibição do controle foi alterada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#21](../../atl/codesnippet/cpp/ccomcontrolbase-class_4.cpp)]

## <a name="ccomcontrolbasegetambientappearance"></a><a name="getambientappearance"></a>CComControlBase::getAmbientAppearance

Recupera DISPID_AMBIENT_APPEARANCE, a configuração de aparência atual para o controle: 0 para plano e 1 para 3D.

```
HRESULT GetAmbientAppearance(short& nAppearance);
```

### <a name="parameters"></a>Parâmetros

*nAparição*<br/>
A propriedade DISPID_AMBIENT_APPEARANCE.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#22](../../atl/codesnippet/cpp/ccomcontrolbase-class_5.h)]

## <a name="ccomcontrolbasegetambientautoclip"></a><a name="getambientautoclip"></a>CComcontrolBase::GetambientAutoClip

Recupera DISPID_AMBIENT_AUTOCLIP, uma bandeira indicando se o contêiner suporta o recorte automático da área de exibição de controle.

```
HRESULT GetAmbientAutoClip(BOOL& bAutoClip);
```

### <a name="parameters"></a>Parâmetros

*bAutoClip*<br/>
A propriedade DISPID_AMBIENT_AUTOCLIP.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

## <a name="ccomcontrolbasegetambientbackcolor"></a><a name="getambientbackcolor"></a>CComControlBase::getambientBackColor

Recupera DISPID_AMBIENT_BACKCOLOR, a cor de fundo ambiente para todos os controles, definida pelo recipiente.

```
HRESULT GetAmbientBackColor(OLE_COLOR& BackColor);
```

### <a name="parameters"></a>Parâmetros

*Backcolor*<br/>
A propriedade DISPID_AMBIENT_BACKCOLOR.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

## <a name="ccomcontrolbasegetambientcharset"></a><a name="getambientcharset"></a>CcomcontrolBase::getambientcharset

Recupera DISPID_AMBIENT_CHARSET, o conjunto de caracteres ambiente para todos os controles, definido pelo recipiente.

```
HRESULT GetAmbientCharSet(BSTR& bstrCharSet);
```

### <a name="parameters"></a>Parâmetros

*bstrCharset*<br/>
A propriedade DISPID_AMBIENT_CHARSET.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="ccomcontrolbasegetambientcodepage"></a><a name="getambientcodepage"></a>CComControlBase::GetAmbientCodePage

Recupera DISPID_AMBIENT_CODEPAGE, a página de código ambiente para todos os controles, definida pelo contêiner.

```
HRESULT GetAmbientCodePage(ULONG& ulCodePage);
```

### <a name="parameters"></a>Parâmetros

*ulCodePage*<br/>
A propriedade DISPID_AMBIENT_CODEPAGE.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="ccomcontrolbasegetambientdisplayasdefault"></a><a name="getambientdisplayasdefault"></a>CComControlBase::getambientDisplayAsDefault

Recupera DISPID_AMBIENT_DISPLAYASDEFAULT, uma bandeira que é TRUE se o contêiner tiver marcado o controle neste site como um botão padrão e, portanto, um controle de botão deve desenhar-se com um quadro mais grosso.

```
HRESULT GetAmbientDisplayAsDefault(BOOL& bDisplayAsDefault);
```

### <a name="parameters"></a>Parâmetros

*bDisplayAsDefault*<br/>
A propriedade DISPID_AMBIENT_DISPLAYASDEFAULT.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

## <a name="ccomcontrolbasegetambientdisplayname"></a><a name="getambientdisplayname"></a>CComControlBase::GetAmbientDisplayName

Recupera DISPID_AMBIENT_DISPLAYNAME, o nome que o contêiner forneceu ao controle.

```
HRESULT GetAmbientDisplayName(BSTR& bstrDisplayName);
```

### <a name="parameters"></a>Parâmetros

*bstrDisplayName*<br/>
A propriedade DISPID_AMBIENT_DISPLAYNAME.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

## <a name="ccomcontrolbasegetambientfont"></a><a name="getambientfont"></a>CComControlBase::getambientfont

Recupera um ponteiro para a `IFont` interface ambiente do contêiner.

```
HRESULT GetAmbientFont(IFont** ppFont);
```

### <a name="parameters"></a>Parâmetros

*ppFont*<br/>
Um ponteiro para a interface [iFont](/windows/win32/api/ocidl/nn-ocidl-ifont) ambiente do contêiner.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

### <a name="remarks"></a>Comentários

Se a propriedade for NULA, o ponteiro é NULO. Se o ponteiro não for NULO, o chamador deve soltar o ponteiro.

## <a name="ccomcontrolbasegetambientfontdisp"></a><a name="getambientfontdisp"></a>CComControlBase::GetAmbientFontDisp

Recupera um ponteiro para a `IFontDisp` interface de despacho ambiente do contêiner.

```
HRESULT GetAmbientFontDisp(IFontDisp** ppFont);
```

### <a name="parameters"></a>Parâmetros

*ppFont*<br/>
Um ponteiro para a interface de despacho [IFontDisp](/windows/win32/api/ocidl/nn-ocidl-ifontdisp) ambiente do contêiner.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Se a propriedade for NULA, o ponteiro é NULO. Se o ponteiro não for NULO, o chamador deve soltar o ponteiro.

## <a name="ccomcontrolbasegetambientforecolor"></a><a name="getambientforecolor"></a>CComControlBase::GetAmbientForeColor

Recupera DISPID_AMBIENT_FORECOLOR, a cor do primeiro plano ambiente para todos os controles, definida pelo recipiente.

```
HRESULT GetAmbientForeColor(OLE_COLOR& ForeColor);
```

### <a name="parameters"></a>Parâmetros

*Forecolor*<br/>
A propriedade DISPID_AMBIENT_FORECOLOR.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

## <a name="ccomcontrolbasegetambientlocaleid"></a><a name="getambientlocaleid"></a>CComControlBase::GetAmbientLocaleID

Recupera DISPID_AMBIENT_LOCALEID, o identificador da linguagem usada pelo recipiente.

```
HRESULT GetAmbientLocaleID(LCID& lcid);
```

### <a name="parameters"></a>Parâmetros

*Lcid*<br/>
A propriedade DISPID_AMBIENT_LOCALEID.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

### <a name="remarks"></a>Comentários

O controle pode usar este identificador para adaptar sua interface de usuário para diferentes idiomas.

## <a name="ccomcontrolbasegetambientmessagereflect"></a><a name="getambientmessagereflect"></a>CcomcontrolBase::getambientMessageReflect

Recupera DISPID_AMBIENT_MESSAGEREFLECT, uma bandeira indicando se o contêiner quer `WM_DRAWITEM`receber mensagens de janela (como ) como eventos.

```
HRESULT GetAmbientMessageReflect(BOOL& bMessageReflect);
```

### <a name="parameters"></a>Parâmetros

*bMessageReflect*<br/>
A propriedade DISPID_AMBIENT_MESSAGEREFLECT.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

## <a name="ccomcontrolbasegetambientpalette"></a><a name="getambientpalette"></a>CComControlBase::GetAmbientPalette

Recupera DISPID_AMBIENT_PALETTE, usado para acessar o HPALETTE do contêiner.

```
HRESULT GetAmbientPalette(HPALETTE& hPalette);
```

### <a name="parameters"></a>Parâmetros

*Hpalette*<br/>
A propriedade DISPID_AMBIENT_PALETTE.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

## <a name="ccomcontrolbasegetambientproperty"></a><a name="getambientproperty"></a>CComControlBase::getAmbientProperty

Recupera a propriedade do contêiner especificada por *dispid*.

```
HRESULT GetAmbientProperty(DISPID dispid, VARIANT& var);
```

### <a name="parameters"></a>Parâmetros

*Dispid*<br/>
Identificador da propriedade do contêiner a ser recuperado.

*Var*<br/>
Variável para receber a propriedade.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

### <a name="remarks"></a>Comentários

A ATL forneceu um conjunto de funções de ajuda para recuperar propriedades específicas, por exemplo, [CComControlBase::GetAmbientBackColor](#getambientbackcolor). Se não houver um método `GetAmbientProperty`adequado disponível, use .

## <a name="ccomcontrolbasegetambientrighttoleft"></a><a name="getambientrighttoleft"></a>CcomcontrolBase::getambientrighttoleft

Recupera DISPID_AMBIENT_RIGHTTOLEFT, a direção em que o conteúdo é exibido pelo recipiente.

```
HRESULT GetAmbientRightToLeft(BOOL& bRightToLeft);
```

### <a name="parameters"></a>Parâmetros

*bRightToLeft*<br/>
A propriedade DISPID_AMBIENT_RIGHTTOLEFT. Definir como TRUE se o conteúdo for exibido da direita para a esquerda, FALSO se for exibido da esquerda para a direita.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="ccomcontrolbasegetambientscaleunits"></a><a name="getambientscaleunits"></a>CComControlBase::getAmbientScaleUnits

Recupera DISPID_AMBIENT_SCALEUNITS, as unidades ambientedo recipiente (como polegadas ou centímetros) para os displays de rotulagem.

```
HRESULT GetAmbientScaleUnits(BSTR& bstrScaleUnits);
```

### <a name="parameters"></a>Parâmetros

*unidades de escala bstr*<br/>
A propriedade DISPID_AMBIENT_SCALEUNITS.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

## <a name="ccomcontrolbasegetambientshowgrabhandles"></a><a name="getambientshowgrabhandles"></a>CComControlBase::GetAmbientShowGrabHandles

Recupera DISPID_AMBIENT_SHOWGRABHANDLES, uma bandeira indicando se o recipiente permite que o controle exiba alças de agarramento para si mesmo quando ativo.

```
HRESULT GetAmbientShowGrabHandles(BOOL& bShowGrabHandles);
```

### <a name="parameters"></a>Parâmetros

*bShowGrabHandles*<br/>
A propriedade DISPID_AMBIENT_SHOWGRABHANDLES.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

## <a name="ccomcontrolbasegetambientshowhatching"></a><a name="getambientshowhatching"></a>CComControlBase::GetAmbientShowHatching

Recupera DISPID_AMBIENT_SHOWHATCHING, uma bandeira indicando se o contêiner permite que o controle se exiba com um padrão eclodido quando a interface do usuário do controle estiver ativa.

```
HRESULT GetAmbientShowHatching(BOOL& bShowHatching);
```

### <a name="parameters"></a>Parâmetros

*bShowHatching*<br/>
A propriedade DISPID_AMBIENT_SHOWHATCHING.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

## <a name="ccomcontrolbasegetambientsupportsmnemonics"></a><a name="getambientsupportsmnemonics"></a>CComControlBase::GetAmbientSupportSMnemonics

Recupera DISPID_AMBIENT_SUPPORTSMNEMONICS, uma bandeira indicando se o contêiner suporta mnemônicos do teclado.

```
HRESULT GetAmbientSupportsMnemonics(BOOL& bSupportsMnemonics);
```

### <a name="parameters"></a>Parâmetros

*bSupportsMnemônicos*<br/>
A propriedade DISPID_AMBIENT_SUPPORTSMNEMONICS.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

## <a name="ccomcontrolbasegetambienttextalign"></a><a name="getambienttextalign"></a>CComControlBase::GetAmbientTextalign

Recupera DISPID_AMBIENT_TEXTALIGN, o alinhamento de texto preferido pelo contêiner: 0 para alinhamento geral (números à direita, texto à esquerda), 1 para alinhamento à esquerda, 2 para alinhamento central e 3 para alinhamento à direita.

```
HRESULT GetAmbientTextAlign(short& nTextAlign);
```

### <a name="parameters"></a>Parâmetros

*nTextAlign*<br/>
A propriedade DISPID_AMBIENT_TEXTALIGN.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

## <a name="ccomcontrolbasegetambienttoptobottom"></a><a name="getambienttoptobottom"></a>CcomcontrolBase::getambienttoptoBottom

Recupera DISPID_AMBIENT_TOPTOBOTTOM, a direção em que o conteúdo é exibido pelo recipiente.

```
HRESULT GetAmbientTopToBottom(BOOL& bTopToBottom);
```

### <a name="parameters"></a>Parâmetros

*bTopToBottom*<br/>
A propriedade DISPID_AMBIENT_TOPTOBOTTOM. Definir como TRUE se o texto for exibido de cima para baixo, FALSO se for exibido de baixo para cima.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="ccomcontrolbasegetambientuidead"></a><a name="getambientuidead"></a>CcomcontrolBase::getambientuidead

Recupera DISPID_AMBIENT_UIDEAD, uma bandeira indicando se o contêiner quer que o controle responda às ações de interface do usuário.

```
HRESULT GetAmbientUIDead(BOOL& bUIDead);
```

### <a name="parameters"></a>Parâmetros

*bUIDead*<br/>
A propriedade DISPID_AMBIENT_UIDEAD.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

### <a name="remarks"></a>Comentários

Se VERDADEIRO, o controle não deve responder. Esta bandeira se aplica independentemente da bandeira DISPID_AMBIENT_USERMODE. Consulte [CComControlBase::getambientusermode](#getambientusermode).

## <a name="ccomcontrolbasegetambientusermode"></a><a name="getambientusermode"></a>CComControlBase::getambientUsermode

Recupera DISPID_AMBIENT_USERMODE, um sinalizador indicando se o contêiner está no modo de execução (TRUE) ou no modo de design (FALSE).

```
HRESULT GetAmbientUserMode(BOOL& bUserMode);
```

### <a name="parameters"></a>Parâmetros

*bUserMode*<br/>
A propriedade DISPID_AMBIENT_USERMODE.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

## <a name="ccomcontrolbasegetdirty"></a><a name="getdirty"></a>CComControlBase::GetDirty

Retorna o valor `m_bRequiresSave`do membro de dados .

```
BOOL GetDirty();
```

### <a name="return-value"></a>Valor retornado

Retorna o valor do membro de dados [m_bRequiresSave](#m_brequiressave).

### <a name="remarks"></a>Comentários

Este valor está definido usando [CComControlBase::SetDirty](#setdirty).

## <a name="ccomcontrolbasegetzoominfo"></a><a name="getzoominfo"></a>CComControlBase::getZoomInfo

Recupera os valores x e y do numerador e denominador do fator zoom para um controle ativado para edição no local.

```
void GetZoomInfo(ATL_DRAWINFO& di);
```

### <a name="parameters"></a>Parâmetros

*Di*<br/>
A estrutura que segurará o numerador e denominador do fator zoom. Para obter mais informações, consulte [ATL_DRAWINFO](../../atl/reference/atl-drawinfo-structure.md).

### <a name="remarks"></a>Comentários

O fator zoom é a proporção do tamanho natural do controle até a sua extensão atual.

## <a name="ccomcontrolbaseinplaceactivate"></a><a name="inplaceactivate"></a>CcomControlBase::InplaceActivate

Faz com que o controle transite do estado inativo para qualquer estado que o verbo em *iVerb* indica.

```
HRESULT InPlaceActivate(LONG iVerb, const RECT* prcPosRect = NULL);
```

### <a name="parameters"></a>Parâmetros

*Iverb*<br/>
Valor indicando a ação a ser executada por [IOleObjectImpl::DoVerb](../../atl/reference/ioleobjectimpl-class.md#doverb).

*prcPosRect*<br/>
Ponteiro para a posição do controle no lugar.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

### <a name="remarks"></a>Comentários

Antes da ativação, este método verifica se o controle tem um site cliente, verifica quanto do controle é visível e obtém a localização do controle na janela pai. Depois que o controle é ativado, este método ativa a interface do usuário do controle e informa o recipiente para tornar o controle visível.

Este método também `IOleInPlaceSite`recupera `IOleInPlaceSiteEx`um `IOleInPlaceSiteWindowless` ponteiro de interface ou um ponteiro de interface para o controle e armazena-o no membro de dados da classe de controle [CComControlBase::m_spInPlaceSite](#m_spinplacesite). Os membros da classe de controle [CComControlBase::m_bInPlaceSiteEx,](#m_binplacesiteex) [CComControlBase:m_bWndLess,](#m_bwndless) [CComControlBase::m_bWasOnceWindowless](#m_bwasoncewindowless)e [CComControlBase::m_bNegotiatedWnd](#m_bnegotiatedwnd) são definidos como verdadeiros conforme apropriado.

## <a name="ccomcontrolbaseinternalgetsite"></a><a name="internalgetsite"></a>CComControlBase::InternalGetSite

Chame este método para consultar o site de controle para obter um ponteiro para a interface identificada.

```
HRESULT InternalGetSite(REFIID riid, void** ppUnkSite);
```

### <a name="parameters"></a>Parâmetros

*riid*<br/>
O IID do ponteiro de interface que deve ser devolvido em *ppUnkSite*.

*Ppunksite*<br/>
Endereço da variável ponteiro que recebe o ponteiro de interface solicitado em *riid*.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Se o site suportar a interface solicitada em *riid,* o ponteiro será devolvido por meio de *ppUnkSite*. Caso contrário, *ppUnkSite* está definido como NULL.

## <a name="ccomcontrolbasem_bautosize"></a><a name="m_bautosize"></a>CComControlBase::m_bAutoSize

A bandeira indicando o controle não pode ser de outro tamanho.

```
unsigned m_bAutoSize:1;
```

### <a name="remarks"></a>Comentários

Esta bandeira é `IOleObjectImpl::SetExtent` verificada e, se TRUE, faz com que a função retorne E_FAIL.

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele é declarado dentro de um sindicato na classe base.

Se você adicionar a opção **Tamanho automático** na guia [Propriedades](../../atl/reference/stock-properties-atl-control-wizard.md) de estoque do assistente de controle ATL, o assistente criará automaticamente esse membro de dados em sua classe de controle, criará métodos de colocar e obter para a propriedade e apoiará o [IPropertyNotifySink](/windows/win32/api/ocidl/nn-ocidl-ipropertynotifysink) para notificar automaticamente o contêiner quando a propriedade for mudada.

## <a name="ccomcontrolbasem_bdrawfromnatural"></a><a name="m_bdrawfromnatural"></a>CComControlBase::m_bDrawFromNatural

Bandeira indicando `IDataObjectImpl::GetData` `CComControlBase::GetZoomInfo` isso e deve `m_sizeNatural` definir o `m_sizeExtent`tamanho do controle em vez de .

```
unsigned m_bDrawFromNatural:1;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele é declarado dentro de um sindicato na classe base.

## <a name="ccomcontrolbasem_bdrawgetdatainhimetric"></a><a name="m_bdrawgetdatainhimetric"></a>CComControlBase::m_bDrawGetDataInHimetric

Sinalizador indicando `IDataObjectImpl::GetData` que deve usar unidades HIMETRIC e não pixels ao desenhar.

```
unsigned m_bDrawGetDataInHimetric:1;
```

### <a name="remarks"></a>Comentários

Cada unidade HIMETRIC lógica é de 0,01 milímetros.

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele é declarado dentro de um sindicato na classe base.

## <a name="ccomcontrolbasem_binplaceactive"></a><a name="m_binplaceactive"></a>CComControlBase::m_bInPlaceActive

Bandeira indicando que o controle está ativo no local.

```
unsigned m_bInPlaceActive:1;
```

### <a name="remarks"></a>Comentários

Isso significa que o controle é visível e sua janela, se houver, é visível, mas seus menus e barras de ferramentas podem não estar ativos. O `m_bUIActive` sinalizador indica que a interface de usuário do controle, como menus, também está ativa.

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele é declarado dentro de um sindicato na classe base.

## <a name="ccomcontrolbasem_binplacesiteex"></a><a name="m_binplacesiteex"></a>CComControlBase::m_bInPlaceSiteEx

O sinalizador indicando que `IOleInPlaceSiteEx` o contêiner suporta os recursos de controle da interface e do OCX96, como controles sem janelas e sem cintilação.

```
unsigned m_bInPlaceSiteEx:1;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele é declarado dentro de um sindicato na classe base.

O membro `m_spInPlaceSite` de dados aponta para uma interface [IOleInPlaceSite,](/windows/win32/api/oleidl/nn-oleidl-ioleinplacesite) [IOleInPlaceSiteEx](/windows/win32/api/ocidl/nn-ocidl-ioleinplacesiteex)ou [IOleInPlaceSiteWindowless,](/windows/win32/api/ocidl/nn-ocidl-ioleinplacesitewindowless) dependendo do valor dos `m_bWndLess` sinalizadores. `m_bInPlaceSiteEx` (O membro `m_bNegotiatedWnd` de dados `m_spInPlaceSite` deve ser TRUE para que o ponteiro seja válido.)

Se `m_bWndLess` é `m_bInPlaceSiteEx` FALSE e `m_spInPlaceSite` é `IOleInPlaceSiteEx` TRUE, é um ponteiro de interface. Veja [m_spInPlaceSite](#m_spinplacesite) para uma tabela mostrando a relação entre esses três membros de dados.

## <a name="ccomcontrolbasem_bnegotiatedwnd"></a><a name="m_bnegotiatedwnd"></a>CComControlBase::m_bNegotiatedWnd

Sinalizador indicando se o controle negociou ou não com o contêiner sobre o suporte para recursos de controle OCX96 (como controles sem flicker e sem janelas), e se o controle está ou não sem janelas.

```
unsigned m_bNegotiatedWnd:1;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele é declarado dentro de um sindicato na classe base.

A `m_bNegotiatedWnd` bandeira deve ser `m_spInPlaceSite` VERDADEIRA para que o ponteiro seja válido.

## <a name="ccomcontrolbasem_brecomposeonresize"></a><a name="m_brecomposeonresize"></a>CComControlBase::m_bRecomposeOnResize

Sinalizador indicando que o controle deseja recompor sua apresentação quando o contêiner altera o tamanho do display do controle.

```
unsigned m_bRecomposeOnResize:1;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele é declarado dentro de um sindicato na classe base.

Este sinalizador é verificado por [IOleObjectImpl::SetExtent](../../atl/reference/ioleobjectimpl-class.md#setextent) e, se TRUE, `SetExtent` notifica o contêiner de alterações de exibição. se esta bandeira estiver definida, a OLEMISC_RECOMPOSEONRESIZE bit na enumeração [OLEMISC](/windows/win32/api/oleidl/ne-oleidl-olemisc) também deve ser definida.

## <a name="ccomcontrolbasem_brequiressave"></a><a name="m_brequiressave"></a>CComControlBase::m_bRequiresSave

Bandeira indicando que o controle mudou desde a última salva.

```
unsigned m_bRequiresSave:1;
```

### <a name="remarks"></a>Comentários

O valor `m_bRequiresSave` pode ser definido com [CComControlBase::SetDirty](#setdirty) e recuperado com [CComControlBase::GetDirty](#getdirty).

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele é declarado dentro de um sindicato na classe base.

## <a name="ccomcontrolbasem_bresizenatural"></a><a name="m_bresizenatural"></a>CComControlBase::m_bResizeNatural

Bandeira indicando que o controle deseja redimensionar sua extensão natural (seu tamanho físico não dimensionado) quando o recipiente altera o tamanho do display do controle.

```
unsigned m_bResizeNatural:1;
```

### <a name="remarks"></a>Comentários

Esta bandeira é `IOleObjectImpl::SetExtent` verificada e, se `SetExtent` TRUE, o `m_sizeNatural`tamanho passado é atribuído a .

O tamanho `SetExtent` repassado é `m_sizeExtent`sempre atribuído, independentemente do valor de `m_bResizeNatural`.

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele é declarado dentro de um sindicato na classe base.

## <a name="ccomcontrolbasem_buiactive"></a><a name="m_buiactive"></a>CComControlBase::m_bUIActive

O sinalizador indicando a interface de usuário do controle, como menus e barras de ferramentas, está ativo.

```
unsigned m_bUIActive:1;
```

### <a name="remarks"></a>Comentários

O `m_bInPlaceActive` sinalizador indica que o controle está ativo, mas não que sua interface de usuário esteja ativa.

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele é declarado dentro de um sindicato na classe base.

## <a name="ccomcontrolbasem_busingwindowrgn"></a><a name="m_busingwindowrgn"></a>CComControlBase::m_bUsingWindowRgn

A bandeira indicando que o controle está usando a região da janela fornecida pelo contêiner.

```
unsigned m_bUsingWindowRgn:1;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele é declarado dentro de um sindicato na classe base.

## <a name="ccomcontrolbasem_bwasoncewindowless"></a><a name="m_bwasoncewindowless"></a>CComControlBase::m_bWasOnceWindowless

A bandeira indicando que o controle foi sem janelas, mas pode ou não estar sem janelas agora.

```
unsigned m_bWasOnceWindowless:1;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele é declarado dentro de um sindicato na classe base.

## <a name="ccomcontrolbasem_bwindowonly"></a><a name="m_bwindowonly"></a>CComControlBase::m_bWindowOnly

A bandeira indicando que o controle deve ser janelas, mesmo que o contêiner suporte controles sem janelas.

```
unsigned m_bWindowOnly:1;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele é declarado dentro de um sindicato na classe base.

## <a name="ccomcontrolbasem_bwndless"></a><a name="m_bwndless"></a>CComControlBase::m_bWndLess

A bandeira indicando que o controle não tem janelas.

```
unsigned m_bWndLess:1;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele é declarado dentro de um sindicato na classe base.

O membro `m_spInPlaceSite` de dados aponta para uma interface [IOleInPlaceSite,](/windows/win32/api/oleidl/nn-oleidl-ioleinplacesite) [IOleInPlaceSiteEx](/windows/win32/api/ocidl/nn-ocidl-ioleinplacesiteex)ou [IOleInPlaceSiteWindowless,](/windows/win32/api/ocidl/nn-ocidl-ioleinplacesitewindowless) dependendo do valor dos sinalizadores `m_bWndLess` [CComControlBase:m_bInPlaceSiteEx.](#m_binplacesiteex) (O membro de dados [CComControlBase::m_bNegotiatedWnd](#m_bnegotiatedwnd) deve ser TRUE para que o [ponteiro CComControlBase::m_spInPlaceSite](#m_spinplacesite) seja válido.)

Se `m_bWndLess` é `m_spInPlaceSite` VERDADE, `IOleInPlaceSiteWindowless` é um ponteiro de interface. Consulte [CComControlBase::m_spInPlaceSite](#m_spinplacesite) para uma tabela que mostra a relação completa entre esses membros de dados.

## <a name="ccomcontrolbasem_hwndcd"></a><a name="m_hwndcd"></a>CComControlBase::m_hWndCD

Contém uma referência à alça da janela associada ao controle.

```
HWND& m_hWndCD;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele é declarado dentro de um sindicato na classe base.

## <a name="ccomcontrolbasem_nfreezeevents"></a><a name="m_nfreezeevents"></a>CComControlBase::m_nFreezeEvents

Uma contagem do número de vezes que o contêiner congelou eventos (se recusou a aceitar eventos) sem um degelo intervindo de eventos (aceitação de eventos).

```
short m_nFreezeEvents;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele é declarado dentro de um sindicato na classe base.

## <a name="ccomcontrolbasem_rcpos"></a><a name="m_rcpos"></a>CComControlBase::m_rcPos

A posição nos pixels do controle, expressa nas coordenadas do recipiente.

```
RECT m_rcPos;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele é declarado dentro de um sindicato na classe base.

## <a name="ccomcontrolbasem_sizeextent"></a><a name="m_sizeextent"></a>CComControlBase::m_sizeExtent

A extensão do controle em unidades HIMETRIC (cada unidade é de 0,01 milímetros) para um display específico.

```
SIZE m_sizeExtent;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele é declarado dentro de um sindicato na classe base.

Este tamanho é dimensionado pelo display. O tamanho físico do controle é `m_sizeNatural` especificado no membro de dados e é fixo.

Você pode converter o tamanho em pixels com a função global [AtlHiMetricToPixel](pixel-himetric-conversion-global-functions.md#atlhimetrictopixel).

## <a name="ccomcontrolbasem_sizenatural"></a><a name="m_sizenatural"></a>CComControlBase::m_sizeNatural

O tamanho físico do controle em unidades HIMETRIC (cada unidade é de 0,01 milímetros).

```
SIZE m_sizeNatural;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele é declarado dentro de um sindicato na classe base.

Este tamanho é fixo, `m_sizeExtent` enquanto o tamanho em é dimensionado pelo display.

Você pode converter o tamanho em pixels com a função global [AtlHiMetricToPixel](pixel-himetric-conversion-global-functions.md#atlhimetrictopixel).

## <a name="ccomcontrolbasem_spadvisesink"></a><a name="m_spadvisesink"></a>CComControlBase::m_spAdviseSink

Um ponteiro direto para a conexão consultiva no recipiente (o [IAdviseSink](/windows/win32/api/objidl/nn-objidl-iadvisesink)do recipiente ).

```
CComPtr<IAdviseSink>
    m_spAdviseSink;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele é declarado dentro de um sindicato na classe base.

## <a name="ccomcontrolbasem_spambientdispatch"></a><a name="m_spambientdispatch"></a>CComControlBase::m_spAmbientDispatch

Um `CComDispatchDriver` objeto que permite recuperar e definir as `IDispatch` propriedades de um objeto através de um ponteiro.

```
CComDispatchDriver m_spAmbientDispatch;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele é declarado dentro de um sindicato na classe base.

## <a name="ccomcontrolbasem_spclientsite"></a><a name="m_spclientsite"></a>CComControlBase::m_spClientSite

Um ponteiro para o site do cliente do controle dentro do contêiner.

```
CComPtr<IOleClientSite>
    m_spClientSite;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele é declarado dentro de um sindicato na classe base.

## <a name="ccomcontrolbasem_spdataadviseholder"></a><a name="m_spdataadviseholder"></a>CComControlBase::m_spDataAdviseHolder

Fornece um meio padrão para manter conexões consultivas entre objetos de dados e aconselhar sinks.

```
CComPtr<IDataAdviseHolder>
    m_spDataAdviseHolder;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele é declarado dentro de um sindicato na classe base.

Um objeto de dados é um controle que pode transferir dados e que implementa [o IDataObject](/windows/win32/api/objidl/nn-objidl-idataobject), cujos métodos especificam o formato e o meio de transferência dos dados.

A `m_spDataAdviseHolder` interface implementa os métodos [IDataObject::DAdvise](/windows/win32/api/objidl/nf-objidl-idataobject-dadvise) e [IDataObject::DUnadvise](/windows/win32/api/objidl/nf-objidl-idataobject-dunadvise) para estabelecer e excluir conexões consultivas ao contêiner. O recipiente do controle deve implementar um dissipador de aconselhamento apoiando a interface [IAdviseSink.](/windows/win32/api/objidl/nn-objidl-iadvisesink)

## <a name="ccomcontrolbasem_spinplacesite"></a><a name="m_spinplacesite"></a>CComControlBase::m_spInPlaceSite

Um ponteiro para o ponteiro de interface [IOleInPlaceSite](/windows/win32/api/oleidl/nn-oleidl-ioleinplacesite)do contêiner, [IOleInPlaceSiteEx](/windows/win32/api/ocidl/nn-ocidl-ioleinplacesiteex)ou [iOleInPlaceSiteWindows](/windows/win32/api/ocidl/nn-ocidl-ioleinplacesitewindowless) ponteiro de interface.

```
CComPtr<IOleInPlaceSiteWindowless>
    m_spInPlaceSite;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele é declarado dentro de um sindicato na classe base.

O `m_spInPlaceSite` ponteiro só é válido se a bandeira [m_bNegotiatedWnd](#m_bnegotiatedwnd) for TRUE.

A tabela a `m_spInPlaceSite` seguir mostra como o tipo de ponteiro depende das [bandeiras de](#m_bwndless) membro de dados m_bWndLess e [m_bInPlaceSiteEx:](#m_binplacesiteex)

|m_spInPlaceSite tipo|valor m_bWndLess|valor m_bInPlaceSiteEx|
|---------------------------|-----------------------|-----------------------------|
|`IOleInPlaceSiteWindowless`|TRUE|VERDADEIRO ou FALSO|
|`IOleInPlaceSiteEx`|FALSE|TRUE|
|`IOleInPlaceSite`|FALSE|FALSE|

## <a name="ccomcontrolbasem_spoleadviseholder"></a><a name="m_spoleadviseholder"></a>CComControlBase::m_spOleAdviseHolder

Fornece uma implementação padrão de uma maneira de manter conexões consultivas.

```
CComPtr<IOleAdviseHolder>
    m_spOleAdviseHolder;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ele é declarado dentro de um sindicato na classe base.

A `m_spOleAdviseHolder` interface implementa os métodos [IOleObject::Advise](/windows/win32/api/oleidl/nf-oleidl-ioleobject-advise) e [IOleObject::Unadvise](/windows/win32/api/oleidl/nf-oleidl-ioleobject-unadvise) para estabelecer e excluir conexões de aviso ao contêiner. O recipiente do controle deve implementar um dissipador de aconselhamento apoiando a interface [IAdviseSink.](/windows/win32/api/objidl/nn-objidl-iadvisesink)

## <a name="ccomcontrolbaseondraw"></a><a name="ondraw"></a>CComControlBase::OnDraw

Anular este método para desenhar seu controle.

```
virtual HRESULT OnDraw(ATL_DRAWINFO& di);
```

### <a name="parameters"></a>Parâmetros

*Di*<br/>
Uma referência à estrutura [ATL_DRAWINFO](../../atl/reference/atl-drawinfo-structure.md) que contém informações de desenho, como o aspecto de desenho, os limites de controle e se o desenho é otimizado ou não.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

O `OnDraw` padrão exclui ou restaura o contexto do dispositivo ou não faz nada, dependendo dos sinalizadores definidos no [CComControlBase::OnDrawAdvanced](#ondrawadvanced).

Um `OnDraw` método é adicionado automaticamente à sua classe de controle quando você cria seu controle com o Assistente de Controle ATL. O padrão `OnDraw` do assistente desenha um retângulo com o rótulo "ATL 8.0".

### <a name="example"></a>Exemplo

Veja o exemplo de [CComControlBase::GetAmbientAppearance](#getambientappearance).

## <a name="ccomcontrolbaseondrawadvanced"></a><a name="ondrawadvanced"></a>CComControlBase::OnDrawAdvanced

O `OnDrawAdvanced` padrão prepara um contexto de dispositivo normalizado para `OnDraw` desenho e, em seguida, chama o método da classe de controle.

```
virtual HRESULT OnDrawAdvanced(ATL_DRAWINFO& di);
```

### <a name="parameters"></a>Parâmetros

*Di*<br/>
Uma referência à estrutura [ATL_DRAWINFO](../../atl/reference/atl-drawinfo-structure.md) que contém informações de desenho, como o aspecto de desenho, os limites de controle e se o desenho é otimizado ou não.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Anular este método se você quiser aceitar o contexto do dispositivo passado pelo contêiner sem normalizá-lo.

Consulte [CComControlBase::OnDraw](#ondraw) para obter mais detalhes.

## <a name="ccomcontrolbaseonkillfocus"></a><a name="onkillfocus"></a>CComControlBase::OnKillFocus

Verifica se o controle está ativo no local e tem um local de controle válido, em seguida, informa o contêiner que o controle perdeu o foco.

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

*Bhandled*<br/>
Sinalizador que indica se a mensagem da janela foi manuseada com sucesso. O padrão é FALSO.

### <a name="return-value"></a>Valor retornado

Sempre retorna 1.

## <a name="ccomcontrolbaseonmouseactivate"></a><a name="onmouseactivate"></a>CComControlBase::OnMouseActivate

Verifica se a ui está no modo de usuário e, em seguida, ativa o controle.

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

*Bhandled*<br/>
Sinalizador que indica se a mensagem da janela foi manuseada com sucesso. O padrão é FALSO.

### <a name="return-value"></a>Valor retornado

Sempre retorna 1.

## <a name="ccomcontrolbaseonpaint"></a><a name="onpaint"></a>CComControlBase::OnPaint

Prepara o recipiente para pintura, obtém a área de cliente `OnDrawAdvanced` do controle e chama o método da classe de controle.

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
Um HDC existente.

*lParam*<br/>
Reservado.

*Lresult*<br/>
Reservado.

### <a name="return-value"></a>Valor retornado

Sempre retorna zero.

### <a name="remarks"></a>Comentários

Se *o wParam* `OnPaint` não for NULL, presume-se que ele contém um HDC válido e o usa em vez de [CComControlBase::m_hWndCD](#m_hwndcd).

## <a name="ccomcontrolbaseonsetfocus"></a><a name="onsetfocus"></a>CComControlBase::OnSetFocus

Verifica se o controle está ativo no local e tem um local de controle válido, então informa o contêiner que o controle ganhou foco.

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

*Bhandled*<br/>
Sinalizador que indica se a mensagem da janela foi manuseada com sucesso. O padrão é FALSO.

### <a name="return-value"></a>Valor retornado

Sempre retorna 1.

### <a name="remarks"></a>Comentários

Envia uma notificação ao contêiner de que o controle recebeu foco.

## <a name="ccomcontrolbasepretranslateaccelerator"></a><a name="pretranslateaccelerator"></a>CComControlBase::PreTranslateAccelerator

Anule este método para fornecer seus próprios manipuladores do acelerador de teclado.

```
BOOL PreTranslateAccelerator(LPMSG /* pMsg */,
    HRESULT& /* hRet */);
```

### <a name="parameters"></a>Parâmetros

*pMsg*<br/>
Reservado.

*hRet*<br/>
Reservado.

### <a name="return-value"></a>Valor retornado

Por padrão retorna FALSO.

## <a name="ccomcontrolbasesendonclose"></a><a name="sendonclose"></a>CcomcontrolBase::SendonClose

Notifica todos os avisos registrados com o titular da assessoria de que o controle foi fechado.

```
HRESULT SendOnClose();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Envia uma notificação de que o controle fechou seus afunimas de assessoria.

## <a name="ccomcontrolbasesendondatachange"></a><a name="sendondatachange"></a>CcomControlBase::SendonDataChange

Notifica todos os registros de avisos registrados com o titular da assessoria de que os dados de controle foram alterados.

```
HRESULT SendOnDataChange(DWORD advf = 0);
```

### <a name="parameters"></a>Parâmetros

*Advf*<br/>
Aconselhar sinalizadores que especificam como a chamada para [IAdviseSink::OnDataChange](/windows/win32/api/objidl/nf-objidl-iadvisesink-ondatachange) é feita. Os valores são da enumeração [ADVF.](/windows/win32/api/objidl/ne-objidl-advf)

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="ccomcontrolbasesendonrename"></a><a name="sendonrename"></a>CComControlBase::SendOnRename

Notifica todos os afundamentos de aviso registrados com o titular da assessoria de que o controle tem um novo apelido.

```
HRESULT SendOnRename(IMoniker* pmk);
```

### <a name="parameters"></a>Parâmetros

*Pmk*<br/>
Ponteiro para o novo apelido do controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Envia uma notificação de que o apelido para o controle mudou.

## <a name="ccomcontrolbasesendonsave"></a><a name="sendonsave"></a>CcomControlBase::SendonSave

Notifica todos os afundamentos de aviso registrados com o titular do aviso de que o controle foi salvo.

```
HRESULT SendOnSave();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Envia uma notificação de que o controle acabou de salvar seus dados.

## <a name="ccomcontrolbasesendonviewchange"></a><a name="sendonviewchange"></a>CcomcontrolBase::SendonViewChange

Notifica todos os avisos registrados de que a visão do controle mudou.

```
HRESULT SendOnViewChange(DWORD dwAspect, LONG lindex = -1);
```

### <a name="parameters"></a>Parâmetros

*Dwaspect*<br/>
O aspecto ou visão do controle.

*Lindex*<br/>
A parte da exibição que mudou. Apenas -1 é válido.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

`SendOnViewChange`chama [IAdviseSink::OnViewChange](/windows/win32/api/objidl/nf-objidl-iadvisesink-onviewchange). O único valor do *índice lindex* atualmente suportado é -1, o que indica que toda a visão é de interesse.

## <a name="ccomcontrolbasesetcontrolfocus"></a><a name="setcontrolfocus"></a>CComControlBase::SetControlFocus

Define ou remove o foco do teclado para ou do controle.

```
BOOL SetControlFocus(BOOL bGrab);
```

### <a name="parameters"></a>Parâmetros

*bGrab*<br/>
Se TRUE, define o foco do teclado para o controle de chamada. Se FALSE, remove o foco do teclado do controle de chamada, desde que tenha o foco.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o controle receber com sucesso o foco; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Para um controle com janelas, a função [SetFocus](/windows/win32/api/winuser/nf-winuser-setfocus) da aPI do Windows é chamada. Para um controle sem janelas, [IOleInPlaceSiteWindowless::SetFocus](/windows/win32/api/ocidl/nf-ocidl-ioleinplacesitewindowless-setfocus) é chamado. Através desta chamada, um controle sem janelas obtém o foco do teclado e pode responder às mensagens da janela.

## <a name="ccomcontrolbasesetdirty"></a><a name="setdirty"></a>CComControlBase::SetDirty

Define o `m_bRequiresSave` membro de dados para o valor em *bDirty*.

```
void SetDirty(BOOL bDirty);
```

### <a name="parameters"></a>Parâmetros

*Bdirty*<br/>
Valor do membro de dados [CComControlBase::m_bRequiresSave](#m_brequiressave).

### <a name="remarks"></a>Comentários

`SetDirty(TRUE)`deve ser chamado para sinalizar que o controle mudou desde que foi salvo pela última vez. O valor `m_bRequiresSave` do é recuperado com [CComControlBase::GetDirty](#getdirty).

## <a name="see-also"></a>Confira também

[Classe CComControl](../../atl/reference/ccomcontrol-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
