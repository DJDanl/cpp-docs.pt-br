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
ms.openlocfilehash: a07f30fb00dd00e7a6315b8935731ccfc7500843
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81361694"
---
# <a name="cmfcrebar-class"></a>Classe CMFCReBar

Um `CMFCReBar` objeto é uma barra de controle que fornece informações de layout, persistência e estado para controles de vergalhões.
Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

## <a name="syntax"></a>Sintaxe

```
class CMFCReBar : public CPane
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRebar::Addbar](#addbar)|Adiciona uma banda a um vergalhão.|
|[CMFCReBar::CalcFixedLayout](#calcfixedlayout)|(Substitui [cbasepane::CalcFixedLayout](../../mfc/reference/cbasepane-class.md#calcfixedlayout).)|
|[CMFCRebar::CanFloat](#canfloat)|(Substitui [cbasepane::CanFloat](../../mfc/reference/cbasepane-class.md#canfloat).)|
|[CMFCRebar::Criar](#create)|Cria o controle do vergalhão e o prende ao `CMFCReBar` objeto.|
|[CMFCReBar::Habilitar docking](#enabledocking)|(Substitui [cbasepane::EnableDocking](../../mfc/reference/cbasepane-class.md#enabledocking).)|
|[CMFCRebar::GetRebarBandInfoSize](#getrebarbandinfosize)||
|[CMFCReBar::GetReBarCtrl](#getrebarctrl)|Fornece acesso direto ao controle comum [CReBarCtrl](../../mfc/reference/crebarctrl-class.md) subjacente.|
|[CMFCReBar::OnShowControlBarmenu](#onshowcontrolbarmenu)|(Substitui [cpane::OnShowControlBarMenu](../../mfc/reference/cpane-class.md#onshowcontrolbarmenu).)|
|[CMFCRebar::OntoolHitTest](#ontoolhittest)|(Substitui [cwnd::OnToolHitTest](../../mfc/reference/cwnd-class.md#ontoolhittest).)|
|[CMFCReBar::OnUpdateCmdUI](#onupdatecmdui)|(Substitui [cbasepane::OnUpdateCmdUI](cbasepane-class.md).)|
|[CMFCReBar::SetPaneAlignment](#setpanealignment)|(Substitui [cbasepane::SetPaneAlignment](../../mfc/reference/cbasepane-class.md#setpanealignment).)|

## <a name="remarks"></a>Comentários

Um `CMFCReBar` objeto pode conter uma variedade de janelas de crianças. Isso inclui caixas de edição, barras de ferramentas e caixas de lista. Você pode redimensionar o vergalhão programáticamente, ou o usuário pode redimensionar manualmente o vergalhão arrastando sua barra de aperto. Você também pode definir o plano de fundo de um objeto de vergalhões para um bitmap de sua escolha.

Um objeto de vergalhões se comporta de forma semelhante a um objeto de barra de ferramentas. Um controle de vergalhões pode conter uma ou mais bandas, e cada banda pode conter uma barra de aperto, um bitmap, uma etiqueta de texto e uma janela infantil.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCReBar` usar vários métodos na classe. O exemplo mostra como criar um controle de vergalhões e adicionar uma banda a ele. A banda funciona como uma barra de ferramentas interna. Este trecho de código faz parte da amostra de teste de [barra reto](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_RebarTest#1](../../mfc/reference/codesnippet/cpp/cmfcrebar-class_1.h)]
[!code-cpp[NVC_MFC_RebarTest#2](../../mfc/reference/codesnippet/cpp/cmfcrebar-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)\
-&nbsp;[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[CWnd](../../mfc/reference/cwnd-class.md)\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[CBasePane](../../mfc/reference/cbasepane-class.md)\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[CPane](../../mfc/reference/cpane-class.md)\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[CMFCRebar](../../mfc/reference/cmfcrebar-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxRebar.h

## <a name="cmfcrebaraddbar"></a><a name="addbar"></a>CMFCRebar::Addbar

Adiciona uma banda a um vergalhão.

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

*Pbar*<br/>
[dentro, fora] Um ponteiro para a janela da criança que deve ser inserido no vergalhão. O objeto referenciado deve ter o estilo de janela **WS_CHILD.**

*Psztext*<br/>
[em] Especifica o texto a ser exibido na barra de retuma. O texto não faz parte da janela da criança. Em vez disso, é exibido no próprio vergalhão.

*pbmp*<br/>
[dentro, fora] Especifica o bitmap a ser exibido no plano de fundo do vergalhão.

*Dwstyle*<br/>
[em] Contém o estilo para aplicar à banda. Para obter uma lista completa de `fStyle` estilos de banda, consulte a descrição da estrutura [REBARBANDINFO](/windows/win32/api/commctrl/ns-commctrl-rebarbandinfow) na documentação do Windows SDK.

*clrFore*<br/>
[em] Representa a cor do primeiro plano do vergalhão.

*clrBack*<br/>
[em] Representa a cor de fundo do vergalhão.

### <a name="return-value"></a>Valor retornado

TRUE se a banda foi adicionada com sucesso ao vergalhão; caso contrário, FALSE.

## <a name="cmfcrebarcreate"></a><a name="create"></a>CMFCRebar::Criar

Cria o controle do vergalhão e o anexa ao objeto [CMFCReBar.](../../mfc/reference/cmfcrebar-class.md)

```
BOOL Create(
    CWnd* pParentWnd,
    DWORD dwCtrlStyle = RBS_BANDBORDERS,
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_TOP,
    UINT nID = AFX_IDW_REBAR);
```

### <a name="parameters"></a>Parâmetros

*Pparentwnd*<br/>
[dentro, fora] Um ponteiro para a janela pai deste controle de vergalhões.

*dwCtrlStyle*<br/>
[em] Especifica o estilo para o controle do vergalhão. O valor de estilo padrão é **RBS_BANDBORDERS**, que exibe linhas estreitas para bandas adjacentes separadas no controle do vergalhão. Para obter uma lista de estilos válidos, consulte Estilos de controle de [barras](/windows/win32/Controls/rebar-control-styles) na documentação do Windows SDK.

*Dwstyle*<br/>
[em] O estilo da janela do controle do vergalhão. Para obter uma lista de estilos válidos, consulte Estilos de [janela](../../mfc/reference/styles-used-by-mfc.md#window-styles).

*nID*<br/>
[em] A id da janela infantil do vergalhão.

### <a name="return-value"></a>Valor retornado

VERDADE se o vergalhão foi criado com sucesso; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

## <a name="cmfcrebargetrebarctrl"></a><a name="getrebarctrl"></a>CMFCReBar::GetReBarCtrl

Fornece acesso `CReBarCtrl` direto ao controle `CMFCReBar` comum subjacente para objetos.

```
CReBarCtrl& GetReBarCtrl() const;
```

### <a name="return-value"></a>Valor retornado

Uma referência ao `CReBarCtrl` objeto subjacente.

### <a name="remarks"></a>Comentários

Chame este método para aproveitar a funcionalidade de controle comum do Windows ao personalizar seu vergalhão.

## <a name="cmfcrebarcalcfixedlayout"></a><a name="calcfixedlayout"></a>CMFCReBar::CalcFixedLayout

```
virtual CSize CalcFixedLayout(
    BOOL bStretch,
    BOOL bHorz);
```

### <a name="parameters"></a>Parâmetros

[em] *bStretch*<br/>
[em] *bHorz*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcrebarcanfloat"></a><a name="canfloat"></a>CMFCRebar::CanFloat

```
virtual BOOL CanFloat() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcrebarenabledocking"></a><a name="enabledocking"></a>CMFCReBar::Habilitar docking

```
void EnableDocking(DWORD dwDockStyle);
```

### <a name="parameters"></a>Parâmetros

[em] *dwDockStyle*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmfcrebargetrebarbandinfosize"></a><a name="getrebarbandinfosize"></a>CMFCRebar::GetRebarBandInfoSize

```
UINT GetReBarBandInfoSize() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcrebaronshowcontrolbarmenu"></a><a name="onshowcontrolbarmenu"></a>CMFCReBar::OnShowControlBarmenu

```
virtual BOOL OnShowControlBarMenu(CPoint);
```

### <a name="parameters"></a>Parâmetros

[em] *CPoint*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcrebarontoolhittest"></a><a name="ontoolhittest"></a>CMFCRebar::OntoolHitTest

```
virtual INT_PTR OnToolHitTest(
    CPoint point,
    TOOLINFO* pTI) const;
```

### <a name="parameters"></a>Parâmetros

[em] *ponto*<br/>
[em] *pTI*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcrebaronupdatecmdui"></a><a name="onupdatecmdui"></a>CMFCReBar::OnUpdateCmdUI

```
virtual void OnUpdateCmdUI(
    CFrameWnd* pTarget,
    BOOL bDisableIfNoHndler);
```

### <a name="parameters"></a>Parâmetros

[em] *pTarget*<br/>
[em] *bDisableIfNoHndler*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmfcrebarsetpanealignment"></a><a name="setpanealignment"></a>CMFCReBar::SetPaneAlignment

```
virtual void SetPaneAlignment(DWORD dwAlignment);
```

### <a name="parameters"></a>Parâmetros

[em] *dwAlignment*<br/>

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CReBarCtrl](../../mfc/reference/crebarctrl-class.md)<br/>
[Classe CPane](../../mfc/reference/cpane-class.md)
