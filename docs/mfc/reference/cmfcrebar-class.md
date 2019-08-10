---
title: Classe CMFCReBar
ms.date: 11/04/2016
f1_keywords:
- CMFCReBar
- AFXREBAR/CMFCReBar
- AFXREBAR/CMFCReBar::AddBar
- AFXREBAR/CMFCReBar::CalcFixedLayout
- AFXREBAR/CMFCReBar::CanFloat
- AFXREBAR/CMFCReBar::Create
- AFXREBAR/CMFCReBar::EnableDocking
- AFXREBAR/CMFCReBar::GetReBarBandInfoSize
- AFXREBAR/CMFCReBar::GetReBarCtrl
- AFXREBAR/CMFCReBar::OnShowControlBarMenu
- AFXREBAR/CMFCReBar::OnToolHitTest
- AFXREBAR/CMFCReBar::OnUpdateCmdUI
- AFXREBAR/CMFCReBar::SetPaneAlignment
helpviewer_keywords:
- CMFCReBar [MFC], AddBar
- CMFCReBar [MFC], CalcFixedLayout
- CMFCReBar [MFC], CanFloat
- CMFCReBar [MFC], Create
- CMFCReBar [MFC], EnableDocking
- CMFCReBar [MFC], GetReBarBandInfoSize
- CMFCReBar [MFC], GetReBarCtrl
- CMFCReBar [MFC], OnShowControlBarMenu
- CMFCReBar [MFC], OnToolHitTest
- CMFCReBar [MFC], OnUpdateCmdUI
- CMFCReBar [MFC], SetPaneAlignment
ms.assetid: 02a60e29-6224-49c1-9e74-e0a7d9f8d023
ms.openlocfilehash: ccd500547bdcf65e922f7b5e5ca8d30e0423933d
ms.sourcegitcommit: bd7ddc044f9083246614b602ef6a758775313214
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2019
ms.locfileid: "68866181"
---
# <a name="cmfcrebar-class"></a>Classe CMFCReBar

Um `CMFCReBar` objeto é uma barra de controle que fornece informações de layout, persistência e estado para controles Rebar.
Para obter mais detalhes, consulte o código-fonte localizado na pasta **vc\\atlmfc\\src\\MFC** da instalação do Visual Studio.
## <a name="syntax"></a>Sintaxe

```
class CMFCReBar : public CPane
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCReBar::AddBar](#addbar)|Adiciona uma banda a um Rebar.|
|[CMFCReBar::CalcFixedLayout](#calcfixedlayout)|(Substitui [CBasePane:: CalcFixedLayout](../../mfc/reference/cbasepane-class.md#calcfixedlayout).)|
|[CMFCReBar::CanFloat](#canfloat)|(Substitui [CBasePane:: CanFloat](../../mfc/reference/cbasepane-class.md#canfloat).)|
|[CMFCReBar:: criar](#create)|Cria o controle rebar e o `CMFCReBar` anexa ao objeto.|
|[CMFCReBar::EnableDocking](#enabledocking)|(Substitui [CBasePane:: EnableDocking](../../mfc/reference/cbasepane-class.md#enabledocking).)|
|[CMFCReBar::GetReBarBandInfoSize](#getrebarbandinfosize)||
|[CMFCReBar::GetReBarCtrl](#getrebarctrl)|Fornece acesso direto ao controle comum [CReBarCtrl](../../mfc/reference/crebarctrl-class.md) subjacente.|
|[CMFCReBar::OnShowControlBarMenu](#onshowcontrolbarmenu)|(Substitui [CPane:: OnShowControlBarMenu](../../mfc/reference/cpane-class.md#onshowcontrolbarmenu).)|
|[CMFCReBar::OnToolHitTest](#ontoolhittest)|(Substitui [CWnd:: OnToolHitTest](../../mfc/reference/cwnd-class.md#ontoolhittest).)|
|[CMFCReBar::OnUpdateCmdUI](#onupdatecmdui)|(Substitui [CBasePane:: OnUpdateCmdUI](cbasepane-class.md).)|
|[CMFCReBar::SetPaneAlignment](#setpanealignment)|(Substitui [CBasePane:: SetPaneAlignment](../../mfc/reference/cbasepane-class.md#setpanealignment).)|

## <a name="remarks"></a>Comentários

Um `CMFCReBar` objeto pode conter uma variedade de janelas filhas. Isso inclui caixas de edição, barras de ferramentas e caixas de listagem. Você pode redimensionar o rebar programaticamente ou o usuário pode redimensionar manualmente o rebar arrastando sua barra de garra. Você também pode definir o plano de fundo de um objeto rebar para um bitmap de sua escolha.

Um objeto rebar se comporta de forma semelhante a um objeto Toolbar. Um controle rebar pode conter uma ou mais bandas, e cada banda pode conter uma barra de garra, um bitmap, um rótulo de texto e uma janela filho.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar vários métodos na `CMFCReBar` classe. O exemplo mostra como criar um controle rebar e adicionar uma banda a ele. A banda funciona como uma barra de ferramentas interna. Este trecho de código faz parte do [exemplo de teste de rebar](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_RebarTest#1](../../mfc/reference/codesnippet/cpp/cmfcrebar-class_1.h)]
[!code-cpp[NVC_MFC_RebarTest#2](../../mfc/reference/codesnippet/cpp/cmfcrebar-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)\
└&nbsp;[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)\
&nbsp;&nbsp;&nbsp;&nbsp;└&nbsp;[CWnd](../../mfc/reference/cwnd-class.md)\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└&nbsp;[CBasePane](../../mfc/reference/cbasepane-class.md)\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└&nbsp;[CPane](../../mfc/reference/cpane-class.md)\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└&nbsp;[CMFCReBar](../../mfc/reference/cmfcrebar-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxRebar. h

##  <a name="addbar"></a>  CMFCReBar::AddBar

Adiciona uma banda a um Rebar.

```
BOOL AddBar(
    CWnd* pBar,
    LPCTSTR pszText = NULL,
    CBitmap* pbmp = NULL,
    DWORD dwStyle = RBBS_GRIPPERALWAYS | RBBS_FIXEDBMP);

BOOL AddBar(
    CWnd* pBar,
    COLORREF clrFore,
    COLORREF clrBack,
    LPCTSTR pszText = NULL,
    DWORD dwStyle = RBBS_GRIPPERALWAYS);
```

### <a name="parameters"></a>Parâmetros

*pBar*<br/>
[entrada, saída] Um ponteiro para a janela filho que deve ser inserida no Rebar. O objeto referenciado deve ter o estilo de janela **WS_CHILD** .

*pszText*<br/>
no Especifica o texto a ser exibido no Rebar. O texto não faz parte da janela filho. Em vez disso, ele é exibido no próprio próprio Rebar.

*pbmp*<br/>
[entrada, saída] Especifica o bitmap a ser exibido no plano de fundo do rebar.

*dwStyle*<br/>
no Contém o estilo a ser aplicado à banda. Para obter uma lista completa de estilos de banda, consulte a `fStyle` descrição para na estrutura [REBARBANDINFO](/windows/desktop/api/commctrl/ns-commctrl-tagrebarbandinfoa) na documentação do SDK do Windows.

*clrFore*<br/>
no Representa a cor de primeiro plano do rebar.

*clrBack*<br/>
no Representa a cor do plano de fundo do rebar.

### <a name="return-value"></a>Valor de retorno

TRUE se a banda tiver sido adicionada com êxito ao Rebar; caso contrário, FALSE.

##  <a name="create"></a>CMFCReBar:: criar

Cria o controle rebar e o anexa ao objeto [CMFCReBar](../../mfc/reference/cmfcrebar-class.md) .

```
BOOL Create(
    CWnd* pParentWnd,
    DWORD dwCtrlStyle = RBS_BANDBORDERS,
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_TOP,
    UINT nID = AFX_IDW_REBAR);
```

### <a name="parameters"></a>Parâmetros

*pParentWnd*<br/>
[entrada, saída] Um ponteiro para a janela pai deste controle rebar.

*dwCtrlStyle*<br/>
no Especifica o estilo para o controle rebar. O valor de estilo padrão é **RBS_BANDBORDERS**, que exibe linhas estreitas para separar as faixas adjacentes no controle rebar. Para obter uma lista de estilos válidos, consulte [estilos de controle rebar](/windows/desktop/Controls/rebar-control-styles) na documentação do SDK do Windows.

*dwStyle*<br/>
no O estilo de janela do controle rebar. Para obter uma lista de estilos válidos, consulte [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles).

*nID*<br/>
no A ID da janela filho do rebar.

### <a name="return-value"></a>Valor de retorno

TRUE se o rebar tiver sido criado com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="getrebarctrl"></a>  CMFCReBar::GetReBarCtrl

Fornece acesso direto ao `CReBarCtrl` controle comum subjacente para `CMFCReBar` objetos.

```
CReBarCtrl& GetReBarCtrl() const;
```

### <a name="return-value"></a>Valor de retorno

Uma referência ao objeto subjacente `CReBarCtrl` .

### <a name="remarks"></a>Comentários

Chame esse método para aproveitar a funcionalidade de controle comum do Windows rebar ao personalizar seu rebar.

##  <a name="calcfixedlayout"></a>CMFCReBar::CalcFixedLayout

```
virtual CSize CalcFixedLayout(
    BOOL bStretch,
    BOOL bHorz);
```

### <a name="parameters"></a>Parâmetros

no *bStretch*<br/>
no *bHorz*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="canfloat"></a>CMFCReBar:: CanFloat

```
virtual BOOL CanFloat() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="enabledocking"></a>CMFCReBar::EnableDocking

```
void EnableDocking(DWORD dwDockStyle);
```

### <a name="parameters"></a>Parâmetros

no *dwDockStyle*<br/>

### <a name="remarks"></a>Comentários

##  <a name="getrebarbandinfosize"></a>CMFCReBar::GetReBarBandInfoSize

```
UINT GetReBarBandInfoSize() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="onshowcontrolbarmenu"></a>  CMFCReBar::OnShowControlBarMenu

```
virtual BOOL OnShowControlBarMenu(CPoint);
```

### <a name="parameters"></a>Parâmetros

no *CPoint*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="ontoolhittest"></a>  CMFCReBar::OnToolHitTest

```
virtual INT_PTR OnToolHitTest(
    CPoint point,
    TOOLINFO* pTI) const;
```

### <a name="parameters"></a>Parâmetros

[in] *point*<br/>
[in] *pTI*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="onupdatecmdui"></a>  CMFCReBar::OnUpdateCmdUI

```
virtual void OnUpdateCmdUI(
    CFrameWnd* pTarget,
    BOOL bDisableIfNoHndler);
```

### <a name="parameters"></a>Parâmetros

no *pTarget*<br/>
no *bDisableIfNoHndler*<br/>

### <a name="remarks"></a>Comentários

##  <a name="setpanealignment"></a>CMFCReBar::SetPaneAlignment

```
virtual void SetPaneAlignment(DWORD dwAlignment);
```

### <a name="parameters"></a>Parâmetros

no *dwAlignment*<br/>

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CReBarCtrl](../../mfc/reference/crebarctrl-class.md)<br/>
[Classe CPane](../../mfc/reference/cpane-class.md)
