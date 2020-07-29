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
ms.openlocfilehash: 6baaad9e3eae077b0ec460ba4e881508245bb894
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87224312"
---
# <a name="ccomcontrolbase-class"></a>Classe CComControlBase

Essa classe fornece métodos para criar e gerenciar controles ATL.

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
class ATL_NO_VTABLE CComControlBase
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CComControlBase:: AppearanceType](#appearancetype)|Substituir se a `m_nAppearance` Propriedade Stock não for do tipo **`short`** .|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComControlBase::CComControlBase](#ccomcontrolbase)|O construtor.|
|[CComControlBase:: ~ CComControlBase](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComControlBase::ControlQueryInterface](#controlqueryinterface)|Recupera um ponteiro para a interface solicitada.|
|[CComControlBase::D oesVerbActivate](#doesverbactivate)|Verifica se o parâmetro *iVerb* usado pelo `IOleObjectImpl::DoVerb` ativa a interface do usuário do controle (*iVerb* é igual a OLEIVERB_UIACTIVATE), define a ação tomada quando o usuário clica duas vezes no controle (*iVerb* é igual a OLEIVERB_PRIMARY), exibe o controle (*iVerb* é igual a OLEIVERB_SHOW) ou ativa o controle (*iVerb* é igual a OLEIVERB_INPLACEACTIVATE).|
|[CComControlBase::D oesVerbUIActivate](#doesverbuiactivate)|Verifica se o parâmetro *iVerb* usado pelo `IOleObjectImpl::DoVerb` faz com que a interface do usuário do controle seja ativada e retorna true.|
|[CComControlBase::D oVerbProperties](#doverbproperties)|Exibe as páginas de propriedades do controle.|
|[CComControlBase::FireViewChange](#fireviewchange)|Chame esse método para instruir o contêiner a redesenhar o controle ou notifique os coletores de aviso registrados que a exibição do controle alterou.|
|[CComControlBase::GetAmbientAppearance](#getambientappearance)|Recupera DISPID_AMBIENT_APPEARANCE, a configuração de aparência atual para o controle: 0 para Flat e 1 para 3D.|
|[CComControlBase::GetAmbientAutoClip](#getambientautoclip)|Recupera DISPID_AMBIENT_AUTOCLIP, um sinalizador que indica se o contêiner dá suporte ao recorte automático da área de exibição do controle.|
|[CComControlBase::GetAmbientBackColor](#getambientbackcolor)|Recupera DISPID_AMBIENT_BACKCOLOR, a cor do plano de fundo do ambiente de todos os controles, definida pelo contêiner.|
|[CComControlBase::GetAmbientCharSet](#getambientcharset)|Recupera DISPID_AMBIENT_CHARSET, o conjunto de caracteres de ambiente para todos os controles, definidos pelo contêiner.|
|[CComControlBase::GetAmbientCodePage](#getambientcodepage)|Recupera DISPID_AMBIENT_CODEPAGE, o conjunto de caracteres de ambiente para todos os controles, definidos pelo contêiner.|
|[CComControlBase::GetAmbientDisplayAsDefault](#getambientdisplayasdefault)|Recupera DISPID_AMBIENT_DISPLAYASDEFAULT, um sinalizador que será verdadeiro se o contêiner tiver marcado o controle nesse site para ser um botão padrão e, portanto, um controle de botão deverá se desenhar com um quadro mais espesso.|
|[CComControlBase::GetAmbientDisplayName](#getambientdisplayname)|Recupera DISPID_AMBIENT_DISPLAYNAME, o nome que o contêiner forneceu para o controle.|
|[CComControlBase::GetAmbientFont](#getambientfont)|Recupera um ponteiro para a interface de ambiente do contêiner `IFont` .|
|[CComControlBase::GetAmbientFontDisp](#getambientfontdisp)|Recupera um ponteiro para a interface de expedição de ambiente do contêiner `IFontDisp` .|
|[CComControlBase::GetAmbientForeColor](#getambientforecolor)|Recupera DISPID_AMBIENT_FORECOLOR, a cor de primeiro plano do ambiente para todos os controles, definidos pelo contêiner.|
|[CComControlBase::GetAmbientLocaleID](#getambientlocaleid)|Recupera DISPID_AMBIENT_LOCALEID, o identificador do idioma usado pelo contêiner.|
|[CComControlBase::GetAmbientMessageReflect](#getambientmessagereflect)|Recupera DISPID_AMBIENT_MESSAGEREFLECT, um sinalizador que indica se o contêiner deseja receber mensagens de janela (como WM_DRAWITEM) como eventos.|
|[CComControlBase::GetAmbientPalette](#getambientpalette)|Recupera DISPID_AMBIENT_PALETTE, usado para acessar o HPALETTE do contêiner.|
|[CComControlBase:: getambienteproperty](#getambientproperty)|Recupera a propriedade de contêiner especificada pela *ID*.|
|[CComControlBase::GetAmbientRightToLeft](#getambientrighttoleft)|Recupera DISPID_AMBIENT_RIGHTTOLEFT, a direção em que o conteúdo é exibido pelo contêiner.|
|[CComControlBase::GetAmbientScaleUnits](#getambientscaleunits)|Recupera DISPID_AMBIENT_SCALEUNITS, as unidades de ambiente do contêiner (como polegadas ou centímetros) para exibições de rótulos.|
|[CComControlBase::GetAmbientShowGrabHandles](#getambientshowgrabhandles)|Recupera DISPID_AMBIENT_SHOWGRABHANDLES, um sinalizador que indica se o contêiner permite que o controle exiba alças de captura para si mesmo quando ativo.|
|[CComControlBase::GetAmbientShowHatching](#getambientshowhatching)|Recupera DISPID_AMBIENT_SHOWHATCHING, um sinalizador que indica se o contêiner permite que o controle seja exibido com um padrão hachurado quando a interface do usuário está ativa.|
|[CComControlBase::GetAmbientSupportsMnemonics](#getambientsupportsmnemonics)|Recupera DISPID_AMBIENT_SUPPORTSMNEMONICS, um sinalizador que indica se o contêiner oferece suporte a mnemônicos de teclado.|
|[CComControlBase::GetAmbientTextAlign](#getambienttextalign)|Recupera DISPID_AMBIENT_TEXTALIGN, o alinhamento do texto preferido pelo contêiner: 0 para alinhamento geral (números à direita, texto à esquerda), 1 para alinhamento à esquerda, 2 para alinhamento no centro e 3 para alinhamento à direita.|
|[CComControlBase::GetAmbientTopToBottom](#getambienttoptobottom)|Recupera DISPID_AMBIENT_TOPTOBOTTOM, a direção em que o conteúdo é exibido pelo contêiner.|
|[CComControlBase::GetAmbientUIDead](#getambientuidead)|Recupera DISPID_AMBIENT_UIDEAD, um sinalizador que indica se o contêiner deseja que o controle responda às ações da interface do usuário.|
|[CComControlBase::GetAmbientUserMode](#getambientusermode)|Recupera DISPID_AMBIENT_USERMODE, um sinalizador que indica se o contêiner está no modo de execução (TRUE) ou no modo de design (FALSE).|
|[CComControlBase:: GetDirty](#getdirty)|Retorna o valor do membro de dados `m_bRequiresSave` .|
|[CComControlBase::GetZoomInfo](#getzoominfo)|Recupera os valores x e y do numerador e do denominador do fator de zoom para um controle ativado para edição in-loco.|
|[CComControlBase::InPlaceActivate](#inplaceactivate)|Faz com que o controle faça a transição do estado inativo para qualquer Estado que o verbo em *iVerb* indica.|
|[CComControlBase::InternalGetSite](#internalgetsite)|Chame esse método para consultar o site de controle para obter um ponteiro para a interface identificada.|
|[CComControlBase:: OnDraw](#ondraw)|Substitua esse método para desenhar seu controle.|
|[CComControlBase::OnDrawAdvanced](#ondrawadvanced)|O padrão `OnDrawAdvanced` prepara um contexto de dispositivo normalizado para desenho e, em seguida, chama o método da classe de controle `OnDraw` .|
|[CComControlBase::OnKillFocus](#onkillfocus)|Verifica se o controle está ativo no local e tem um site de controle válido e, em seguida, informa ao contêiner que o foco do controle foi perdido.|
|[CComControlBase::OnMouseActivate](#onmouseactivate)|Verifica se a interface do usuário está no modo de usuário e ativa o controle.|
|[CComControlBase:: OnPaint](#onpaint)|Prepara o contêiner para pintura, obtém a área do cliente do controle e, em seguida, chama o método da classe de controle `OnDraw` .|
|[CComControlBase:: OnSetFocus](#onsetfocus)|Verifica se o controle está ativo no local e tem um site de controle válido e informa ao contêiner que o controle ganhou o foco.|
|[CComControlBase::P retranslateaccelerator](#pretranslateaccelerator)|Substitua esse método para fornecer seus próprios manipuladores de acelerador de teclado.|
|[CComControlBase::SendOnClose](#sendonclose)|Notifica todos os coletores de consultoria registrados com o detentor do aviso de que o controle foi fechado.|
|[CComControlBase::SendOnDataChange](#sendondatachange)|Notifica todos os coletores de consultoria registrados com o detentor do aviso de que os dados de controle foram alterados.|
|[CComControlBase::SendOnRename](#sendonrename)|Notifica todos os coletores de consultoria registrados com o detentor do aviso de que o controle tem um novo moniker.|
|[CComControlBase::SendOnSave](#sendonsave)|Notifica todos os coletores de consultoria registrados com o detentor do aviso de que o controle foi salvo.|
|[CComControlBase::SendOnViewChange](#sendonviewchange)|Notifica todos os coletores de consultoria registrados que a exibição do controle foi alterada.|
|[CComControlBase::SetControlFocus](#setcontrolfocus)|Define ou remove o foco do teclado para ou do controle.|
|[CComControlBase:: SetDirty](#setdirty)|Define o membro de dados `m_bRequiresSave` para o valor em *bDirty*.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComControlBase:: m_bAutoSize](#m_bautosize)|Sinalizador que indica que o controle não pode ter nenhum outro tamanho.|
|[CComControlBase:: m_bDrawFromNatural](#m_bdrawfromnatural)|Sinalizador que indica que `IDataObjectImpl::GetData` e `CComControlBase::GetZoomInfo` deve definir o tamanho do controle em `m_sizeNatural` vez de `m_sizeExtent` .|
|[CComControlBase:: m_bDrawGetDataInHimetric](#m_bdrawgetdatainhimetric)|Sinalizador que indica que o `IDataObjectImpl::GetData` deve usar unidades HIMETRIC e não pixels durante o desenho.|
|[CComControlBase:: m_bInPlaceActive](#m_binplaceactive)|Sinalizador que indica que o controle está ativo no local.|
|[CComControlBase:: m_bInPlaceSiteEx](#m_binplacesiteex)|Sinalizador que indica que o contêiner dá suporte aos `IOleInPlaceSiteEx` recursos de controle de interface e OCX96, como controles sem janelas e de cintilação.|
|[CComControlBase:: m_bNegotiatedWnd](#m_bnegotiatedwnd)|Sinalizador que indica se o controle foi negociado com o contêiner sobre o suporte para recursos de controle de OCX96 (como controles sem cintilação e de janela) e se o controle é em janela ou sem janela.|
|[CComControlBase:: m_bRecomposeOnResize](#m_brecomposeonresize)|Sinalizador que indica que o controle deseja recompor sua apresentação quando o contêiner altera o tamanho de exibição do controle.|
|[CComControlBase:: m_bRequiresSave](#m_brequiressave)|Sinalizador que indica que o controle foi alterado desde que foi salvo pela última vez.|
|[CComControlBase:: m_bResizeNatural](#m_bresizenatural)|Sinalizador que indica que o controle deseja redimensionar sua extensão natural (seu tamanho físico não dimensionado) quando o contêiner altera o tamanho de exibição do controle.|
|[CComControlBase:: m_bUIActive](#m_buiactive)|Sinalizador que indica que a interface do usuário do controle, como menus e barras de ferramentas, está ativa.|
|[CComControlBase:: m_bUsingWindowRgn](#m_busingwindowrgn)|Sinalizador que indica que o controle está usando a região de janela fornecida pelo contêiner.|
|[CComControlBase:: m_bWasOnceWindowless](#m_bwasoncewindowless)|Sinalizador que indica que o controle não tem janela, mas pode ou não ser sem janela agora.|
|[CComControlBase:: m_bWindowOnly](#m_bwindowonly)|Sinalizador que indica que o controle deve ser janelas, mesmo se o contêiner oferecer suporte a controles sem janela.|
|[CComControlBase:: m_bWndLess](#m_bwndless)|Sinalizador que indica que o controle não tem janela.|
|[CComControlBase:: m_hWndCD](#m_hwndcd)|Contém uma referência ao identificador de janela associado ao controle.|
|[CComControlBase:: m_nFreezeEvents](#m_nfreezeevents)|Uma contagem do número de vezes que o contêiner tem eventos congelados (recusados a aceitar eventos) sem a descongelação de eventos (aceitação de eventos).|
|[CComControlBase:: m_rcPos](#m_rcpos)|A posição em pixels do controle, expressa nas coordenadas do contêiner.|
|[CComControlBase:: m_sizeExtent](#m_sizeextent)|A extensão do controle em unidades HIMETRIC (cada unidade é 0, 1 milímetros) para uma exibição específica.|
|[CComControlBase:: m_sizeNatural](#m_sizenatural)|O tamanho físico do controle em unidades HIMETRIC (cada unidade é 0, 1 milímetros).|
|[CComControlBase:: m_spAdviseSink](#m_spadvisesink)|Um ponteiro direto para a conexão de consultoria no contêiner (o [IAdviseSink](/windows/win32/api/objidl/nn-objidl-iadvisesink)do contêiner).|
|[CComControlBase:: m_spAmbientDispatch](#m_spambientdispatch)|Um `CComDispatchDriver` objeto que permite recuperar e definir as propriedades do contêiner por meio de um `IDispatch` ponteiro.|
|[CComControlBase:: m_spClientSite](#m_spclientsite)|Um ponteiro para o site do cliente do controle dentro do contêiner.|
|[CComControlBase:: m_spDataAdviseHolder](#m_spdataadviseholder)|Fornece um meio padrão para manter as conexões de consultoria entre objetos de dados e coletores de aviso.|
|[CComControlBase:: m_spInPlaceSite](#m_spinplacesite)|Um ponteiro para o ponteiro de interface [IOleInPlaceSite](/windows/win32/api/oleidl/nn-oleidl-ioleinplacesite), [IOleInPlaceSiteEx](/windows/win32/api/ocidl/nn-ocidl-ioleinplacesiteex)ou [IOleInPlaceSiteWindowless](/windows/win32/api/ocidl/nn-ocidl-ioleinplacesitewindowless) do contêiner.|
|[CComControlBase:: m_spOleAdviseHolder](#m_spoleadviseholder)|Fornece uma implementação padrão de uma maneira de manter as conexões de consultoria.|

## <a name="remarks"></a>Comentários

Essa classe fornece métodos para criar e gerenciar controles ATL. A [classe CComControl](../../atl/reference/ccomcontrol-class.md) deriva de `CComControlBase` . Quando você cria um controle padrão ou um controle DHTML usando o assistente de controle ATL, o assistente derivará automaticamente a classe de `CComControlBase` .

Para obter mais informações sobre como criar um controle, consulte o [tutorial do ATL](../../atl/active-template-library-atl-tutorial.md). Para obter mais informações sobre o assistente de projeto do ATL, consulte o artigo [criando um projeto do ATL](../../atl/reference/creating-an-atl-project.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl. h

## <a name="ccomcontrolbaseappearancetype"></a><a name="appearancetype"></a>CComControlBase:: AppearanceType

Substituir se a `m_nAppearance` Propriedade Stock não for do tipo **`short`** .

```
typedef short AppearanceType;
```

### <a name="remarks"></a>Comentários

O assistente de controle ATL adiciona a `m_nAppearance` Propriedade Stock do tipo short. Substituir `AppearanceType` se você usar um tipo de dados diferente.

## <a name="ccomcontrolbaseccomcontrolbase"></a><a name="ccomcontrolbase"></a>CComControlBase::CComControlBase

O construtor.

```
CComControlBase(HWND& h);
```

### <a name="parameters"></a>parâmetros

*h*<br/>
O identificador para a janela associada ao controle.

### <a name="remarks"></a>Comentários

Inicializa o tamanho do controle para 5080X5080 HIMETRIC unidades (2 "X2") e inicializa os `CComControlBase` valores de membro de dados como NULL ou false.

## <a name="ccomcontrolbaseccomcontrolbase"></a><a name="dtor"></a>CComControlBase:: ~ CComControlBase

O destruidor.

```
~CComControlBase();
```

### <a name="remarks"></a>Comentários

Se o controle estiver em janela, `~CComControlBase` destrua-o chamando [DestroyWindow](/windows/win32/api/winuser/nf-winuser-destroywindow).

## <a name="ccomcontrolbasecontrolqueryinterface"></a><a name="controlqueryinterface"></a>CComControlBase::ControlQueryInterface

Recupera um ponteiro para a interface solicitada.

```
virtual HRESULT ControlQueryInterface(const IID& iid,
    void** ppv);
```

### <a name="parameters"></a>parâmetros

*IID*<br/>
O GUID da interface que está sendo solicitada.

*ppv*<br/>
Um ponteiro para o ponteiro de interface identificado por *IID*ou NULL se a interface não for encontrada.

### <a name="remarks"></a>Comentários

O só lida COM interfaces na tabela de mapa COM.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#15](../../atl/codesnippet/cpp/ccomcontrolbase-class_1.cpp)]

## <a name="ccomcontrolbasedoesverbactivate"></a><a name="doesverbactivate"></a>CComControlBase::D oesVerbActivate

Verifica se o parâmetro *iVerb* usado pelo `IOleObjectImpl::DoVerb` ativa a interface do usuário do controle (*iVerb* é igual a OLEIVERB_UIACTIVATE), define a ação tomada quando o usuário clica duas vezes no controle (*iVerb* é igual a OLEIVERB_PRIMARY), exibe o controle (*iVerb* é igual a OLEIVERB_SHOW) ou ativa o controle (*iVerb* é igual a OLEIVERB_INPLACEACTIVATE).

```
BOOL DoesVerbActivate(LONG iVerb);
```

### <a name="parameters"></a>parâmetros

*iVerb*<br/>
Valor que indica a ação a ser executada pelo `DoVerb` .

### <a name="return-value"></a>Valor retornado

Retornará TRUE se *iVerb* for igual a OLEIVERB_UIACTIVATE, OLEIVERB_PRIMARY, OLEIVERB_SHOW ou OLEIVERB_INPLACEACTIVATE; caso contrário, retornará FALSE.

### <a name="remarks"></a>Comentários

Você pode substituir esse método para definir seu próprio verbo de ativação.

## <a name="ccomcontrolbasedoesverbuiactivate"></a><a name="doesverbuiactivate"></a>CComControlBase::D oesVerbUIActivate

Verifica se o parâmetro *iVerb* usado pelo `IOleObjectImpl::DoVerb` faz com que a interface do usuário do controle seja ativada e retorna true.

```
BOOL DoesVerbUIActivate(LONG iVerb);
```

### <a name="parameters"></a>parâmetros

*iVerb*<br/>
Valor que indica a ação a ser executada pelo `DoVerb` .

### <a name="return-value"></a>Valor retornado

Retornará TRUE se *iVerb* for igual a OLEIVERB_UIACTIVATE, OLEIVERB_PRIMARY, OLEIVERB_SHOW ou OLEIVERB_INPLACEACTIVATE. Caso contrário, o método retornará FALSE.

## <a name="ccomcontrolbasedoverbproperties"></a><a name="doverbproperties"></a>CComControlBase::D oVerbProperties

Exibe as páginas de propriedades do controle.

```
HRESULT DoVerbProperties(LPCRECT /* prcPosRect */, HWND hwndParent);
```

### <a name="parameters"></a>parâmetros

*prcPosRec*<br/>
Reservado.

*hwndParent*<br/>
Identificador da janela que contém o controle.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#19](../../atl/codesnippet/cpp/ccomcontrolbase-class_2.cpp)]

[!code-cpp[NVC_ATL_COM#20](../../atl/codesnippet/cpp/ccomcontrolbase-class_3.h)]

## <a name="ccomcontrolbasefireviewchange"></a><a name="fireviewchange"></a>CComControlBase::FireViewChange

Chame esse método para instruir o contêiner a redesenhar o controle ou notifique os coletores de aviso registrados que a exibição do controle alterou.

```
HRESULT FireViewChange();
```

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

Se o controle estiver ativo (o membro de dados da classe de controle [CComControlBase:: m_bInPlaceActive](#m_binplaceactive) for true), o notificará o contêiner de que você deseja redesenhar o controle inteiro. Se o controle estiver inativo, notificará os coletores de aviso registrados do controle (por meio do membro de dados da classe de controle [CComControlBase:: m_spAdviseSink](#m_spadvisesink)) que a exibição do controle foi alterada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#21](../../atl/codesnippet/cpp/ccomcontrolbase-class_4.cpp)]

## <a name="ccomcontrolbasegetambientappearance"></a><a name="getambientappearance"></a>CComControlBase::GetAmbientAppearance

Recupera DISPID_AMBIENT_APPEARANCE, a configuração de aparência atual para o controle: 0 para Flat e 1 para 3D.

```
HRESULT GetAmbientAppearance(short& nAppearance);
```

### <a name="parameters"></a>parâmetros

*nAppearance*<br/>
A propriedade DISPID_AMBIENT_APPEARANCE.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#22](../../atl/codesnippet/cpp/ccomcontrolbase-class_5.h)]

## <a name="ccomcontrolbasegetambientautoclip"></a><a name="getambientautoclip"></a>CComControlBase::GetAmbientAutoClip

Recupera DISPID_AMBIENT_AUTOCLIP, um sinalizador que indica se o contêiner dá suporte ao recorte automático da área de exibição do controle.

```
HRESULT GetAmbientAutoClip(BOOL& bAutoClip);
```

### <a name="parameters"></a>parâmetros

*bAutoClip*<br/>
A propriedade DISPID_AMBIENT_AUTOCLIP.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

## <a name="ccomcontrolbasegetambientbackcolor"></a><a name="getambientbackcolor"></a>CComControlBase::GetAmbientBackColor

Recupera DISPID_AMBIENT_BACKCOLOR, a cor do plano de fundo do ambiente de todos os controles, definida pelo contêiner.

```
HRESULT GetAmbientBackColor(OLE_COLOR& BackColor);
```

### <a name="parameters"></a>parâmetros

*Fundo*<br/>
A propriedade DISPID_AMBIENT_BACKCOLOR.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

## <a name="ccomcontrolbasegetambientcharset"></a><a name="getambientcharset"></a>CComControlBase::GetAmbientCharSet

Recupera DISPID_AMBIENT_CHARSET, o conjunto de caracteres de ambiente para todos os controles, definidos pelo contêiner.

```
HRESULT GetAmbientCharSet(BSTR& bstrCharSet);
```

### <a name="parameters"></a>parâmetros

*bstrCharSet*<br/>
A propriedade DISPID_AMBIENT_CHARSET.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="ccomcontrolbasegetambientcodepage"></a><a name="getambientcodepage"></a>CComControlBase::GetAmbientCodePage

Recupera DISPID_AMBIENT_CODEPAGE, a página de código do ambiente para todos os controles, definidos pelo contêiner.

```
HRESULT GetAmbientCodePage(ULONG& ulCodePage);
```

### <a name="parameters"></a>parâmetros

*ulCodePage*<br/>
A propriedade DISPID_AMBIENT_CODEPAGE.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="ccomcontrolbasegetambientdisplayasdefault"></a><a name="getambientdisplayasdefault"></a>CComControlBase::GetAmbientDisplayAsDefault

Recupera DISPID_AMBIENT_DISPLAYASDEFAULT, um sinalizador que será verdadeiro se o contêiner tiver marcado o controle nesse site para ser um botão padrão e, portanto, um controle de botão deverá se desenhar com um quadro mais espesso.

```
HRESULT GetAmbientDisplayAsDefault(BOOL& bDisplayAsDefault);
```

### <a name="parameters"></a>parâmetros

*bDisplayAsDefault*<br/>
A propriedade DISPID_AMBIENT_DISPLAYASDEFAULT.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

## <a name="ccomcontrolbasegetambientdisplayname"></a><a name="getambientdisplayname"></a>CComControlBase::GetAmbientDisplayName

Recupera DISPID_AMBIENT_DISPLAYNAME, o nome que o contêiner forneceu para o controle.

```
HRESULT GetAmbientDisplayName(BSTR& bstrDisplayName);
```

### <a name="parameters"></a>parâmetros

*bstrDisplayName*<br/>
A propriedade DISPID_AMBIENT_DISPLAYNAME.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

## <a name="ccomcontrolbasegetambientfont"></a><a name="getambientfont"></a>CComControlBase::GetAmbientFont

Recupera um ponteiro para a interface de ambiente do contêiner `IFont` .

```
HRESULT GetAmbientFont(IFont** ppFont);
```

### <a name="parameters"></a>parâmetros

*ppFont*<br/>
Um ponteiro para a interface [IFont](/windows/win32/api/ocidl/nn-ocidl-ifont) de ambiente do contêiner.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

Se a propriedade for nula, o ponteiro será nulo. Se o ponteiro não for nulo, o chamador deverá liberar o ponteiro.

## <a name="ccomcontrolbasegetambientfontdisp"></a><a name="getambientfontdisp"></a>CComControlBase::GetAmbientFontDisp

Recupera um ponteiro para a interface de expedição de ambiente do contêiner `IFontDisp` .

```
HRESULT GetAmbientFontDisp(IFontDisp** ppFont);
```

### <a name="parameters"></a>parâmetros

*ppFont*<br/>
Um ponteiro para a interface de expedição de [IFontDisp](/windows/win32/api/ocidl/nn-ocidl-ifontdisp) de ambiente do contêiner.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Se a propriedade for nula, o ponteiro será nulo. Se o ponteiro não for nulo, o chamador deverá liberar o ponteiro.

## <a name="ccomcontrolbasegetambientforecolor"></a><a name="getambientforecolor"></a>CComControlBase::GetAmbientForeColor

Recupera DISPID_AMBIENT_FORECOLOR, a cor de primeiro plano do ambiente para todos os controles, definidos pelo contêiner.

```
HRESULT GetAmbientForeColor(OLE_COLOR& ForeColor);
```

### <a name="parameters"></a>parâmetros

*Cor*<br/>
A propriedade DISPID_AMBIENT_FORECOLOR.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

## <a name="ccomcontrolbasegetambientlocaleid"></a><a name="getambientlocaleid"></a>CComControlBase::GetAmbientLocaleID

Recupera DISPID_AMBIENT_LOCALEID, o identificador do idioma usado pelo contêiner.

```
HRESULT GetAmbientLocaleID(LCID& lcid);
```

### <a name="parameters"></a>parâmetros

*lcid*<br/>
A propriedade DISPID_AMBIENT_LOCALEID.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

O controle pode usar esse identificador para adaptar sua interface do usuário a diferentes idiomas.

## <a name="ccomcontrolbasegetambientmessagereflect"></a><a name="getambientmessagereflect"></a>CComControlBase::GetAmbientMessageReflect

Recupera DISPID_AMBIENT_MESSAGEREFLECT, um sinalizador que indica se o contêiner deseja receber mensagens de janela (como `WM_DRAWITEM` ) como eventos.

```
HRESULT GetAmbientMessageReflect(BOOL& bMessageReflect);
```

### <a name="parameters"></a>parâmetros

*bMessageReflect*<br/>
A propriedade DISPID_AMBIENT_MESSAGEREFLECT.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

## <a name="ccomcontrolbasegetambientpalette"></a><a name="getambientpalette"></a>CComControlBase::GetAmbientPalette

Recupera DISPID_AMBIENT_PALETTE, usado para acessar o HPALETTE do contêiner.

```
HRESULT GetAmbientPalette(HPALETTE& hPalette);
```

### <a name="parameters"></a>parâmetros

*hPalette*<br/>
A propriedade DISPID_AMBIENT_PALETTE.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

## <a name="ccomcontrolbasegetambientproperty"></a><a name="getambientproperty"></a>CComControlBase:: getambienteproperty

Recupera a propriedade de contêiner especificada por *DISPID*.

```
HRESULT GetAmbientProperty(DISPID dispid, VARIANT& var);
```

### <a name="parameters"></a>parâmetros

*DISPID*<br/>
Identificador da propriedade de contêiner a ser recuperada.

*var*<br/>
Variável para receber a propriedade.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

A ATL forneceu um conjunto de funções auxiliares para recuperar propriedades específicas, por exemplo, [CComControlBase:: GetAmbientBackColor](#getambientbackcolor). Se não houver nenhum método adequado disponível, use `GetAmbientProperty` .

## <a name="ccomcontrolbasegetambientrighttoleft"></a><a name="getambientrighttoleft"></a>CComControlBase::GetAmbientRightToLeft

Recupera DISPID_AMBIENT_RIGHTTOLEFT, a direção em que o conteúdo é exibido pelo contêiner.

```
HRESULT GetAmbientRightToLeft(BOOL& bRightToLeft);
```

### <a name="parameters"></a>parâmetros

*bRightToLeft*<br/>
A propriedade DISPID_AMBIENT_RIGHTTOLEFT. Defina como TRUE se o conteúdo for exibido da direita para a esquerda, FALSE se for exibido da esquerda para a direita.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="ccomcontrolbasegetambientscaleunits"></a><a name="getambientscaleunits"></a>CComControlBase::GetAmbientScaleUnits

Recupera DISPID_AMBIENT_SCALEUNITS, as unidades de ambiente do contêiner (como polegadas ou centímetros) para exibições de rótulos.

```
HRESULT GetAmbientScaleUnits(BSTR& bstrScaleUnits);
```

### <a name="parameters"></a>parâmetros

*bstrScaleUnits*<br/>
A propriedade DISPID_AMBIENT_SCALEUNITS.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

## <a name="ccomcontrolbasegetambientshowgrabhandles"></a><a name="getambientshowgrabhandles"></a>CComControlBase::GetAmbientShowGrabHandles

Recupera DISPID_AMBIENT_SHOWGRABHANDLES, um sinalizador que indica se o contêiner permite que o controle exiba alças de captura para si mesmo quando ativo.

```
HRESULT GetAmbientShowGrabHandles(BOOL& bShowGrabHandles);
```

### <a name="parameters"></a>parâmetros

*bShowGrabHandles*<br/>
A propriedade DISPID_AMBIENT_SHOWGRABHANDLES.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

## <a name="ccomcontrolbasegetambientshowhatching"></a><a name="getambientshowhatching"></a>CComControlBase::GetAmbientShowHatching

Recupera DISPID_AMBIENT_SHOWHATCHING, um sinalizador que indica se o contêiner permite que o controle seja exibido com um padrão hachurado quando a interface do usuário do controle estiver ativa.

```
HRESULT GetAmbientShowHatching(BOOL& bShowHatching);
```

### <a name="parameters"></a>parâmetros

*bShowHatching*<br/>
A propriedade DISPID_AMBIENT_SHOWHATCHING.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

## <a name="ccomcontrolbasegetambientsupportsmnemonics"></a><a name="getambientsupportsmnemonics"></a>CComControlBase::GetAmbientSupportsMnemonics

Recupera DISPID_AMBIENT_SUPPORTSMNEMONICS, um sinalizador que indica se o contêiner oferece suporte a mnemônicos de teclado.

```
HRESULT GetAmbientSupportsMnemonics(BOOL& bSupportsMnemonics);
```

### <a name="parameters"></a>parâmetros

*bSupportsMnemonics*<br/>
A propriedade DISPID_AMBIENT_SUPPORTSMNEMONICS.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

## <a name="ccomcontrolbasegetambienttextalign"></a><a name="getambienttextalign"></a>CComControlBase::GetAmbientTextAlign

Recupera DISPID_AMBIENT_TEXTALIGN, o alinhamento do texto preferido pelo contêiner: 0 para alinhamento geral (números à direita, texto à esquerda), 1 para alinhamento à esquerda, 2 para alinhamento no centro e 3 para alinhamento à direita.

```
HRESULT GetAmbientTextAlign(short& nTextAlign);
```

### <a name="parameters"></a>parâmetros

*nTextAlign*<br/>
A propriedade DISPID_AMBIENT_TEXTALIGN.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

## <a name="ccomcontrolbasegetambienttoptobottom"></a><a name="getambienttoptobottom"></a>CComControlBase::GetAmbientTopToBottom

Recupera DISPID_AMBIENT_TOPTOBOTTOM, a direção em que o conteúdo é exibido pelo contêiner.

```
HRESULT GetAmbientTopToBottom(BOOL& bTopToBottom);
```

### <a name="parameters"></a>parâmetros

*bTopToBottom*<br/>
A propriedade DISPID_AMBIENT_TOPTOBOTTOM. Defina como verdadeiro se o texto for exibido de cima para baixo, falso se for exibido de baixo para cima.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="ccomcontrolbasegetambientuidead"></a><a name="getambientuidead"></a>CComControlBase::GetAmbientUIDead

Recupera DISPID_AMBIENT_UIDEAD, um sinalizador que indica se o contêiner deseja que o controle responda às ações da interface do usuário.

```
HRESULT GetAmbientUIDead(BOOL& bUIDead);
```

### <a name="parameters"></a>parâmetros

*bUIDead*<br/>
A propriedade DISPID_AMBIENT_UIDEAD.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

Se for TRUE, o controle não deverá responder. Esse sinalizador se aplica independentemente do sinalizador de DISPID_AMBIENT_USERMODE. Consulte [CComControlBase:: GetAmbientUserMode](#getambientusermode).

## <a name="ccomcontrolbasegetambientusermode"></a><a name="getambientusermode"></a>CComControlBase::GetAmbientUserMode

Recupera DISPID_AMBIENT_USERMODE, um sinalizador que indica se o contêiner está no modo de execução (TRUE) ou no modo de design (FALSE).

```
HRESULT GetAmbientUserMode(BOOL& bUserMode);
```

### <a name="parameters"></a>parâmetros

*bUserMode*<br/>
A propriedade DISPID_AMBIENT_USERMODE.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

## <a name="ccomcontrolbasegetdirty"></a><a name="getdirty"></a>CComControlBase:: GetDirty

Retorna o valor do membro de dados `m_bRequiresSave` .

```
BOOL GetDirty();
```

### <a name="return-value"></a>Valor retornado

Retorna o valor do [m_bRequiresSave](#m_brequiressave)de membros de dados.

### <a name="remarks"></a>Comentários

Esse valor é definido usando [CComControlBase:: SetDirty](#setdirty).

## <a name="ccomcontrolbasegetzoominfo"></a><a name="getzoominfo"></a>CComControlBase::GetZoomInfo

Recupera os valores x e y do numerador e do denominador do fator de zoom para um controle ativado para edição in-loco.

```cpp
void GetZoomInfo(ATL_DRAWINFO& di);
```

### <a name="parameters"></a>parâmetros

*di*<br/>
A estrutura que manterá o numerador e o denominador do fator de zoom. Para obter mais informações, consulte [ATL_DRAWINFO](../../atl/reference/atl-drawinfo-structure.md).

### <a name="remarks"></a>Comentários

O fator de zoom é a proporção do tamanho natural do controle em sua extensão atual.

## <a name="ccomcontrolbaseinplaceactivate"></a><a name="inplaceactivate"></a>CComControlBase::InPlaceActivate

Faz com que o controle faça a transição do estado inativo para qualquer Estado que o verbo em *iVerb* indica.

```
HRESULT InPlaceActivate(LONG iVerb, const RECT* prcPosRect = NULL);
```

### <a name="parameters"></a>parâmetros

*iVerb*<br/>
Valor que indica a ação a ser executada por [IOleObjectImpl::D overb](../../atl/reference/ioleobjectimpl-class.md#doverb).

*prcPosRect*<br/>
Ponteiro para a posição do controle in-loco.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

Antes da ativação, esse método verifica se o controle tem um site do cliente, verifica a quantidade de controle visível e Obtém o local do controle na janela pai. Depois que o controle é ativado, esse método ativa a interface do usuário do controle e informa ao contêiner para tornar o controle visível.

Esse método também recupera um `IOleInPlaceSite` `IOleInPlaceSiteEx` ponteiro de interface, ou `IOleInPlaceSiteWindowless` para o controle e o armazena no membro de dados da classe de controle [CComControlBase:: m_spInPlaceSite](#m_spinplacesite). Os membros de dados da classe de controle [CComControlBase:: m_bInPlaceSiteEx](#m_binplacesiteex), [CComControlBase:: m_bWndLess](#m_bwndless), [CComControlBase:: m_bWasOnceWindowless](#m_bwasoncewindowless)e [CComControlBase:: m_bNegotiatedWnd](#m_bnegotiatedwnd) são definidos como true conforme apropriado.

## <a name="ccomcontrolbaseinternalgetsite"></a><a name="internalgetsite"></a>CComControlBase::InternalGetSite

Chame esse método para consultar o site de controle para obter um ponteiro para a interface identificada.

```
HRESULT InternalGetSite(REFIID riid, void** ppUnkSite);
```

### <a name="parameters"></a>parâmetros

*riid*<br/>
O IID do ponteiro de interface que deve ser retornado em *ppUnkSite*.

*ppUnkSite*<br/>
Endereço da variável de ponteiro que recebe o ponteiro de interface solicitado em *riid*.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Se o site der suporte à interface solicitada em *riid*, o ponteiro será retornado por meio de *ppUnkSite*. Caso contrário, *ppUnkSite* será definido como NULL.

## <a name="ccomcontrolbasem_bautosize"></a><a name="m_bautosize"></a>CComControlBase:: m_bAutoSize

Sinalizador que indica que o controle não pode ter nenhum outro tamanho.

```
unsigned m_bAutoSize:1;
```

### <a name="remarks"></a>Comentários

Esse sinalizador é verificado por `IOleObjectImpl::SetExtent` e, se verdadeiro, faz com que a função retorne E_FAIL.

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma União na classe base.

Se você adicionar a opção de **dimensionamento automático** na guia [Propriedades de ações](../../atl/reference/stock-properties-atl-control-wizard.md) do assistente de controle do ATL, o assistente criará automaticamente esse membro de dados em sua classe de controle, criará os métodos Put e Get para a propriedade e dará suporte a [IPropertyNotifySink](/windows/win32/api/ocidl/nn-ocidl-ipropertynotifysink) para notificar automaticamente o contêiner quando a propriedade for alterada.

## <a name="ccomcontrolbasem_bdrawfromnatural"></a><a name="m_bdrawfromnatural"></a>CComControlBase:: m_bDrawFromNatural

Sinalizador que indica que `IDataObjectImpl::GetData` e `CComControlBase::GetZoomInfo` deve definir o tamanho do controle em `m_sizeNatural` vez de `m_sizeExtent` .

```
unsigned m_bDrawFromNatural:1;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma União na classe base.

## <a name="ccomcontrolbasem_bdrawgetdatainhimetric"></a><a name="m_bdrawgetdatainhimetric"></a>CComControlBase:: m_bDrawGetDataInHimetric

Sinalizador que indica que o `IDataObjectImpl::GetData` deve usar unidades HIMETRIC e não pixels durante o desenho.

```
unsigned m_bDrawGetDataInHimetric:1;
```

### <a name="remarks"></a>Comentários

Cada unidade de HIMETRIC lógica é 0, 1 milímetro.

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma União na classe base.

## <a name="ccomcontrolbasem_binplaceactive"></a><a name="m_binplaceactive"></a>CComControlBase:: m_bInPlaceActive

Sinalizador que indica que o controle está ativo no local.

```
unsigned m_bInPlaceActive:1;
```

### <a name="remarks"></a>Comentários

Isso significa que o controle está visível e sua janela, se houver, está visível, mas seus menus e barras de ferramentas podem não estar ativos. O `m_bUIActive` sinalizador indica que a interface do usuário do controle, como menus, também está ativa.

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma União na classe base.

## <a name="ccomcontrolbasem_binplacesiteex"></a><a name="m_binplacesiteex"></a>CComControlBase:: m_bInPlaceSiteEx

Sinalizador que indica que o contêiner dá suporte aos `IOleInPlaceSiteEx` recursos de controle de interface e OCX96, como controles sem janelas e de cintilação.

```
unsigned m_bInPlaceSiteEx:1;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma União na classe base.

O membro de dados `m_spInPlaceSite` aponta para uma interface [IOleInPlaceSite](/windows/win32/api/oleidl/nn-oleidl-ioleinplacesite), [IOleInPlaceSiteEx](/windows/win32/api/ocidl/nn-ocidl-ioleinplacesiteex)ou [IOleInPlaceSiteWindowless](/windows/win32/api/ocidl/nn-ocidl-ioleinplacesitewindowless) , dependendo do valor dos `m_bWndLess` `m_bInPlaceSiteEx` sinalizadores e. (O membro de dados `m_bNegotiatedWnd` deve ser true para que o `m_spInPlaceSite` ponteiro seja válido.)

Se `m_bWndLess` for false e `m_bInPlaceSiteEx` for true, `m_spInPlaceSite` será um `IOleInPlaceSiteEx` ponteiro de interface. Consulte [m_spInPlaceSite](#m_spinplacesite) para uma tabela que mostra a relação entre esses três membros de dados.

## <a name="ccomcontrolbasem_bnegotiatedwnd"></a><a name="m_bnegotiatedwnd"></a>CComControlBase:: m_bNegotiatedWnd

Sinalizador que indica se o controle foi negociado com o contêiner sobre o suporte para recursos de controle de OCX96 (como controles sem cintilação e de janela) e se o controle é em janela ou sem janela.

```
unsigned m_bNegotiatedWnd:1;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma União na classe base.

O `m_bNegotiatedWnd` sinalizador deve ser true para `m_spInPlaceSite` que o ponteiro seja válido.

## <a name="ccomcontrolbasem_brecomposeonresize"></a><a name="m_brecomposeonresize"></a>CComControlBase:: m_bRecomposeOnResize

Sinalizador que indica que o controle deseja recompor sua apresentação quando o contêiner altera o tamanho de exibição do controle.

```
unsigned m_bRecomposeOnResize:1;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma União na classe base.

Esse sinalizador é verificado por [IOleObjectImpl:: SetExtent](../../atl/reference/ioleobjectimpl-class.md#setextent) e, se verdadeiro, `SetExtent` Notifica o contêiner de alterações de exibição. Se esse sinalizador for definido, o OLEMISC_RECOMPOSEONRESIZE bit na enumeração [OLEMISC](/windows/win32/api/oleidl/ne-oleidl-olemisc) também deverá ser definido.

## <a name="ccomcontrolbasem_brequiressave"></a><a name="m_brequiressave"></a>CComControlBase:: m_bRequiresSave

Sinalizador que indica que o controle foi alterado desde que foi salvo pela última vez.

```
unsigned m_bRequiresSave:1;
```

### <a name="remarks"></a>Comentários

O valor de `m_bRequiresSave` pode ser definido com [CComControlBase:: SetDirty](#setdirty) e recuperado com [CComControlBase:: GetDirty](#getdirty).

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma União na classe base.

## <a name="ccomcontrolbasem_bresizenatural"></a><a name="m_bresizenatural"></a>CComControlBase:: m_bResizeNatural

Sinalizador que indica que o controle deseja redimensionar sua extensão natural (seu tamanho físico não dimensionado) quando o contêiner altera o tamanho de exibição do controle.

```
unsigned m_bResizeNatural:1;
```

### <a name="remarks"></a>Comentários

Esse sinalizador é verificado por `IOleObjectImpl::SetExtent` e, se for true, o tamanho passado `SetExtent` para é atribuído a `m_sizeNatural` .

O tamanho passado para `SetExtent` é sempre atribuído a `m_sizeExtent` , independentemente do valor de `m_bResizeNatural` .

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma União na classe base.

## <a name="ccomcontrolbasem_buiactive"></a><a name="m_buiactive"></a>CComControlBase:: m_bUIActive

Sinalizador que indica que a interface do usuário do controle, como menus e barras de ferramentas, está ativa.

```
unsigned m_bUIActive:1;
```

### <a name="remarks"></a>Comentários

O `m_bInPlaceActive` sinalizador indica que o controle está ativo, mas não que sua interface do usuário está ativa.

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma União na classe base.

## <a name="ccomcontrolbasem_busingwindowrgn"></a><a name="m_busingwindowrgn"></a>CComControlBase:: m_bUsingWindowRgn

Sinalizador que indica que o controle está usando a região de janela fornecida pelo contêiner.

```
unsigned m_bUsingWindowRgn:1;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma União na classe base.

## <a name="ccomcontrolbasem_bwasoncewindowless"></a><a name="m_bwasoncewindowless"></a>CComControlBase:: m_bWasOnceWindowless

Sinalizador que indica que o controle não tem janela, mas pode ou não ser sem janela agora.

```
unsigned m_bWasOnceWindowless:1;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma União na classe base.

## <a name="ccomcontrolbasem_bwindowonly"></a><a name="m_bwindowonly"></a>CComControlBase:: m_bWindowOnly

Sinalizador que indica que o controle deve ser janelas, mesmo se o contêiner oferecer suporte a controles sem janela.

```
unsigned m_bWindowOnly:1;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma União na classe base.

## <a name="ccomcontrolbasem_bwndless"></a><a name="m_bwndless"></a>CComControlBase:: m_bWndLess

Sinalizador que indica que o controle não tem janela.

```
unsigned m_bWndLess:1;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma União na classe base.

O membro de dados `m_spInPlaceSite` aponta para uma interface [IOleInPlaceSite](/windows/win32/api/oleidl/nn-oleidl-ioleinplacesite), [IOleInPlaceSiteEx](/windows/win32/api/ocidl/nn-ocidl-ioleinplacesiteex)ou [IOleInPlaceSiteWindowless](/windows/win32/api/ocidl/nn-ocidl-ioleinplacesitewindowless) , dependendo do valor dos `m_bWndLess` sinalizadores e [CComControlBase:: m_bInPlaceSiteEx](#m_binplacesiteex) . (O membro de dados [CComControlBase:: m_bNegotiatedWnd](#m_bnegotiatedwnd) deve ser true para que o ponteiro [CComControlBase:: m_spInPlaceSite](#m_spinplacesite) seja válido.)

Se `m_bWndLess` for true, `m_spInPlaceSite` será um `IOleInPlaceSiteWindowless` ponteiro de interface. Consulte [CComControlBase:: m_spInPlaceSite](#m_spinplacesite) para uma tabela que mostra a relação completa entre esses membros de dados.

## <a name="ccomcontrolbasem_hwndcd"></a><a name="m_hwndcd"></a>CComControlBase:: m_hWndCD

Contém uma referência ao identificador de janela associado ao controle.

```
HWND& m_hWndCD;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma União na classe base.

## <a name="ccomcontrolbasem_nfreezeevents"></a><a name="m_nfreezeevents"></a>CComControlBase:: m_nFreezeEvents

Uma contagem do número de vezes que o contêiner tem eventos congelados (recusados a aceitar eventos) sem a descongelação de eventos (aceitação de eventos).

```
short m_nFreezeEvents;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma União na classe base.

## <a name="ccomcontrolbasem_rcpos"></a><a name="m_rcpos"></a>CComControlBase:: m_rcPos

A posição em pixels do controle, expressa nas coordenadas do contêiner.

```
RECT m_rcPos;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma União na classe base.

## <a name="ccomcontrolbasem_sizeextent"></a><a name="m_sizeextent"></a>CComControlBase:: m_sizeExtent

A extensão do controle em unidades HIMETRIC (cada unidade é 0, 1 milímetros) para uma exibição específica.

```
SIZE m_sizeExtent;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma União na classe base.

Esse tamanho é dimensionado pela exibição. O tamanho físico do controle é especificado no `m_sizeNatural` membro de dados e é fixo.

Você pode converter o tamanho em pixels com a função global [AtlHiMetricToPixel](pixel-himetric-conversion-global-functions.md#atlhimetrictopixel).

## <a name="ccomcontrolbasem_sizenatural"></a><a name="m_sizenatural"></a>CComControlBase:: m_sizeNatural

O tamanho físico do controle em unidades HIMETRIC (cada unidade é 0, 1 milímetros).

```
SIZE m_sizeNatural;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma União na classe base.

Esse tamanho é fixo, enquanto o tamanho em `m_sizeExtent` é dimensionado pela exibição.

Você pode converter o tamanho em pixels com a função global [AtlHiMetricToPixel](pixel-himetric-conversion-global-functions.md#atlhimetrictopixel).

## <a name="ccomcontrolbasem_spadvisesink"></a><a name="m_spadvisesink"></a>CComControlBase:: m_spAdviseSink

Um ponteiro direto para a conexão de consultoria no contêiner (o [IAdviseSink](/windows/win32/api/objidl/nn-objidl-iadvisesink)do contêiner).

```
CComPtr<IAdviseSink>
    m_spAdviseSink;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma União na classe base.

## <a name="ccomcontrolbasem_spambientdispatch"></a><a name="m_spambientdispatch"></a>CComControlBase:: m_spAmbientDispatch

Um `CComDispatchDriver` objeto que permite recuperar e definir as propriedades de um objeto por meio de um `IDispatch` ponteiro.

```
CComDispatchDriver m_spAmbientDispatch;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma União na classe base.

## <a name="ccomcontrolbasem_spclientsite"></a><a name="m_spclientsite"></a>CComControlBase:: m_spClientSite

Um ponteiro para o site do cliente do controle dentro do contêiner.

```
CComPtr<IOleClientSite>
    m_spClientSite;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma União na classe base.

## <a name="ccomcontrolbasem_spdataadviseholder"></a><a name="m_spdataadviseholder"></a>CComControlBase:: m_spDataAdviseHolder

Fornece um meio padrão para manter as conexões de consultoria entre objetos de dados e coletores de aviso.

```
CComPtr<IDataAdviseHolder>
    m_spDataAdviseHolder;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma União na classe base.

Um objeto de dados é um controle que pode transferir dados e que implementa [IDataObject](/windows/win32/api/objidl/nn-objidl-idataobject), cujos métodos especificam o formato e a mídia de transferência dos dados.

A interface `m_spDataAdviseHolder` implementa os métodos [idataobject::D Advise](/windows/win32/api/objidl/nf-objidl-idataobject-dadvise) e [IDataObject::D Unadvise](/windows/win32/api/objidl/nf-objidl-idataobject-dunadvise) para estabelecer e excluir as conexões de consultoria com o contêiner. O contêiner do controle deve implementar um coletor de aviso dando suporte à interface [IAdviseSink](/windows/win32/api/objidl/nn-objidl-iadvisesink) .

## <a name="ccomcontrolbasem_spinplacesite"></a><a name="m_spinplacesite"></a>CComControlBase:: m_spInPlaceSite

Um ponteiro para o ponteiro de interface [IOleInPlaceSite](/windows/win32/api/oleidl/nn-oleidl-ioleinplacesite), [IOleInPlaceSiteEx](/windows/win32/api/ocidl/nn-ocidl-ioleinplacesiteex)ou [IOleInPlaceSiteWindowless](/windows/win32/api/ocidl/nn-ocidl-ioleinplacesitewindowless) do contêiner.

```
CComPtr<IOleInPlaceSiteWindowless>
    m_spInPlaceSite;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma União na classe base.

O `m_spInPlaceSite` ponteiro só será válido se o sinalizador de [M_BNEGOTIATEDWND](#m_bnegotiatedwnd) for true.

A tabela a seguir mostra como o `m_spInPlaceSite` tipo de ponteiro depende dos sinalizadores de membro de dados de [m_bWndLess](#m_bwndless) e [m_bInPlaceSiteEx](#m_binplacesiteex) :

|Tipo de m_spInPlaceSite|Valor m_bWndLess|Valor m_bInPlaceSiteEx|
|---------------------------|-----------------------|-----------------------------|
|`IOleInPlaceSiteWindowless`|TRUE|VERDADEIRO ou falso|
|`IOleInPlaceSiteEx`|FALSE|TRUE|
|`IOleInPlaceSite`|FALSE|FALSE|

## <a name="ccomcontrolbasem_spoleadviseholder"></a><a name="m_spoleadviseholder"></a>CComControlBase:: m_spOleAdviseHolder

Fornece uma implementação padrão de uma maneira de manter as conexões de consultoria.

```
CComPtr<IOleAdviseHolder>
    m_spOleAdviseHolder;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Para usar esse membro de dados dentro de sua classe de controle, você deve declará-lo como um membro de dados em sua classe de controle. Sua classe de controle não herdará esse membro de dados da classe base porque ela é declarada dentro de uma União na classe base.

A interface `m_spOleAdviseHolder` implementa os métodos [IOleObject:: Advise](/windows/win32/api/oleidl/nf-oleidl-ioleobject-advise) e [IOleObject:: Unadvise](/windows/win32/api/oleidl/nf-oleidl-ioleobject-unadvise) para estabelecer e excluir as conexões de consultoria com o contêiner. O contêiner do controle deve implementar um coletor de aviso dando suporte à interface [IAdviseSink](/windows/win32/api/objidl/nn-objidl-iadvisesink) .

## <a name="ccomcontrolbaseondraw"></a><a name="ondraw"></a>CComControlBase:: OnDraw

Substitua esse método para desenhar seu controle.

```
virtual HRESULT OnDraw(ATL_DRAWINFO& di);
```

### <a name="parameters"></a>parâmetros

*di*<br/>
Uma referência à estrutura de [ATL_DRAWINFO](../../atl/reference/atl-drawinfo-structure.md) que contém informações de desenho, como o aspecto de empate, os limites de controle e se o desenho é otimizado ou não.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

O padrão `OnDraw` exclui ou restaura o contexto do dispositivo ou não faz nada, dependendo dos sinalizadores definidos em [CComControlBase:: OnDrawAdvanced](#ondrawadvanced).

Um `OnDraw` método é adicionado automaticamente à sua classe de controle quando você cria seu controle com o assistente de controle do ATL. O padrão do assistente `OnDraw` desenha um retângulo com o rótulo "ATL 8,0".

### <a name="example"></a>Exemplo

Consulte o exemplo de [CComControlBase:: GetAmbientAppearance](#getambientappearance).

## <a name="ccomcontrolbaseondrawadvanced"></a><a name="ondrawadvanced"></a>CComControlBase::OnDrawAdvanced

O padrão `OnDrawAdvanced` prepara um contexto de dispositivo normalizado para desenho e, em seguida, chama o método da classe de controle `OnDraw` .

```
virtual HRESULT OnDrawAdvanced(ATL_DRAWINFO& di);
```

### <a name="parameters"></a>parâmetros

*di*<br/>
Uma referência à estrutura de [ATL_DRAWINFO](../../atl/reference/atl-drawinfo-structure.md) que contém informações de desenho, como o aspecto de empate, os limites de controle e se o desenho é otimizado ou não.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Substitua esse método se você quiser aceitar o contexto do dispositivo passado pelo contêiner sem normalização.

Consulte [CComControlBase:: OnDraw](#ondraw) para obter mais detalhes.

## <a name="ccomcontrolbaseonkillfocus"></a><a name="onkillfocus"></a>CComControlBase::OnKillFocus

Verifica se o controle está ativo no local e tem um site de controle válido e, em seguida, informa ao contêiner que o foco do controle foi perdido.

```
LRESULT OnKillFocus(UINT /* nMsg */,
    WPARAM /* wParam */,
    LPARAM /* lParam */,
    BOOL& bHandled);
```

### <a name="parameters"></a>parâmetros

*nMsg*<br/>
Reservado.

*wParam*<br/>
Reservado.

*lParam*<br/>
Reservado.

*bHandled*<br/>
Sinalizador que indica se a mensagem de janela foi manipulada com êxito. O padrão é FALSE.

### <a name="return-value"></a>Valor retornado

Sempre retorna 1.

## <a name="ccomcontrolbaseonmouseactivate"></a><a name="onmouseactivate"></a>CComControlBase::OnMouseActivate

Verifica se a interface do usuário está no modo de usuário e ativa o controle.

```
LRESULT OnMouseActivate(UINT /* nMsg */,
    WPARAM /* wParam */,
    LPARAM /* lParam */,
    BOOL& bHandled);
```

### <a name="parameters"></a>parâmetros

*nMsg*<br/>
Reservado.

*wParam*<br/>
Reservado.

*lParam*<br/>
Reservado.

*bHandled*<br/>
Sinalizador que indica se a mensagem de janela foi manipulada com êxito. O padrão é FALSE.

### <a name="return-value"></a>Valor retornado

Sempre retorna 1.

## <a name="ccomcontrolbaseonpaint"></a><a name="onpaint"></a>CComControlBase:: OnPaint

Prepara o contêiner para pintura, obtém a área do cliente do controle e, em seguida, chama o método da classe de controle `OnDrawAdvanced` .

```
LRESULT OnPaint(UINT /* nMsg */,
    WPARAM wParam,
    LPARAM /* lParam */,
    BOOL& /* lResult */);
```

### <a name="parameters"></a>parâmetros

*nMsg*<br/>
Reservado.

*wParam*<br/>
Um HDC existente.

*lParam*<br/>
Reservado.

*lResult*<br/>
Reservado.

### <a name="return-value"></a>Valor retornado

Sempre retorna zero.

### <a name="remarks"></a>Comentários

Se *wParam* não for NULL, `OnPaint` assumirá que ele contém um HDC válido e o usará em vez de [CComControlBase:: m_hWndCD](#m_hwndcd).

## <a name="ccomcontrolbaseonsetfocus"></a><a name="onsetfocus"></a>CComControlBase:: OnSetFocus

Verifica se o controle está ativo no local e tem um site de controle válido e informa ao contêiner que o controle ganhou o foco.

```
LRESULT OnSetFocus(UINT /* nMsg */,
    WPARAM /* wParam */,
    LPARAM /* lParam */,
    BOOL& bHandled);
```

### <a name="parameters"></a>parâmetros

*nMsg*<br/>
Reservado.

*wParam*<br/>
Reservado.

*lParam*<br/>
Reservado.

*bHandled*<br/>
Sinalizador que indica se a mensagem de janela foi manipulada com êxito. O padrão é FALSE.

### <a name="return-value"></a>Valor retornado

Sempre retorna 1.

### <a name="remarks"></a>Comentários

Envia uma notificação para o contêiner que recebeu o foco do controle.

## <a name="ccomcontrolbasepretranslateaccelerator"></a><a name="pretranslateaccelerator"></a>CComControlBase::P retranslateaccelerator

Substitua esse método para fornecer seus próprios manipuladores de acelerador de teclado.

```
BOOL PreTranslateAccelerator(LPMSG /* pMsg */,
    HRESULT& /* hRet */);
```

### <a name="parameters"></a>parâmetros

*pMsg*<br/>
Reservado.

*hRet*<br/>
Reservado.

### <a name="return-value"></a>Valor retornado

Por padrão, retorna FALSE.

## <a name="ccomcontrolbasesendonclose"></a><a name="sendonclose"></a>CComControlBase::SendOnClose

Notifica todos os coletores de consultoria registrados com o detentor do aviso de que o controle foi fechado.

```
HRESULT SendOnClose();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Envia uma notificação de que o controle fechou seus coletores de consultoria.

## <a name="ccomcontrolbasesendondatachange"></a><a name="sendondatachange"></a>CComControlBase::SendOnDataChange

Notifica todos os coletores de consultoria registrados com o detentor do aviso de que os dados de controle foram alterados.

```
HRESULT SendOnDataChange(DWORD advf = 0);
```

### <a name="parameters"></a>parâmetros

*advf*<br/>
Sinalizadores de aviso que especificam como a chamada para [IAdviseSink:: OnDataChange](/windows/win32/api/objidl/nf-objidl-iadvisesink-ondatachange) é feita. Os valores são da enumeração [ADVF](/windows/win32/api/objidl/ne-objidl-advf) .

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="ccomcontrolbasesendonrename"></a><a name="sendonrename"></a>CComControlBase::SendOnRename

Notifica todos os coletores de consultoria registrados com o detentor do aviso de que o controle tem um novo moniker.

```
HRESULT SendOnRename(IMoniker* pmk);
```

### <a name="parameters"></a>parâmetros

*PMK*<br/>
Ponteiro para o novo moniker do controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Envia uma notificação de que o moniker do controle foi alterado.

## <a name="ccomcontrolbasesendonsave"></a><a name="sendonsave"></a>CComControlBase::SendOnSave

Notifica todos os coletores de consultoria registrados com o detentor do aviso de que o controle foi salvo.

```
HRESULT SendOnSave();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Envia uma notificação de que o controle acabou de salvar seus dados.

## <a name="ccomcontrolbasesendonviewchange"></a><a name="sendonviewchange"></a>CComControlBase::SendOnViewChange

Notifica todos os coletores de consultoria registrados que a exibição do controle foi alterada.

```
HRESULT SendOnViewChange(DWORD dwAspect, LONG lindex = -1);
```

### <a name="parameters"></a>parâmetros

*dwAspect*<br/>
O aspecto ou a exibição do controle.

*lindex*<br/>
A parte da exibição que mudou. Somente-1 é válido.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

`SendOnViewChange`chama [IAdviseSink:: OnViewChange](/windows/win32/api/objidl/nf-objidl-iadvisesink-onviewchange). O único valor de *Lindex* atualmente suportado é-1, o que indica que a exibição inteira é de interesse.

## <a name="ccomcontrolbasesetcontrolfocus"></a><a name="setcontrolfocus"></a>CComControlBase::SetControlFocus

Define ou remove o foco do teclado para ou do controle.

```
BOOL SetControlFocus(BOOL bGrab);
```

### <a name="parameters"></a>parâmetros

*bGrab*<br/>
Se for TRUE, definirá o foco do teclado para o controle de chamada. Se for FALSE, remove o foco do teclado do controle de chamada, desde que ele tenha o foco.

### <a name="return-value"></a>Valor retornado

Retornará TRUE se o controle receber o foco com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Para um controle em janela, a função [SetFocus](/windows/win32/api/winuser/nf-winuser-setfocus) da API do Windows é chamada. Para um controle sem janela, [IOleInPlaceSiteWindowless:: SetFocus](/windows/win32/api/ocidl/nf-ocidl-ioleinplacesitewindowless-setfocus) é chamado. Por meio dessa chamada, um controle sem janela Obtém o foco do teclado e pode responder às mensagens da janela.

## <a name="ccomcontrolbasesetdirty"></a><a name="setdirty"></a>CComControlBase:: SetDirty

Define o membro de dados `m_bRequiresSave` para o valor em *bDirty*.

```cpp
void SetDirty(BOOL bDirty);
```

### <a name="parameters"></a>parâmetros

*bDirty*<br/>
Valor do membro de dados [CComControlBase:: m_bRequiresSave](#m_brequiressave).

### <a name="remarks"></a>Comentários

`SetDirty(TRUE)`deve ser chamado para sinalizar que o controle foi alterado desde que foi salvo pela última vez. O valor de `m_bRequiresSave` é recuperado com [CComControlBase:: GetDirty](#getdirty).

## <a name="see-also"></a>Confira também

[Classe CComControl](../../atl/reference/ccomcontrol-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
