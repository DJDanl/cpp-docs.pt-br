---
title: Classe CAutoHideDockSite
ms.date: 11/04/2016
f1_keywords:
- CAutoHideDockSite
- AFXAUTOHIDEDOCKSITE/CAutoHideDockSite
- AFXAUTOHIDEDOCKSITE/CAutoHideDockSite::CanAcceptPane
- AFXAUTOHIDEDOCKSITE/CAutoHideDockSite::DockPane
- AFXAUTOHIDEDOCKSITE/CAutoHideDockSite::GetAlignRect
- AFXAUTOHIDEDOCKSITE/CAutoHideDockSite::RepositionPanes
- AFXAUTOHIDEDOCKSITE/CAutoHideDockSite::SetOffsetLeft
- AFXAUTOHIDEDOCKSITE/CAutoHideDockSite::SetOffsetRight
- AFXAUTOHIDEDOCKSITE/CAutoHideDockSite::UnSetAutoHideMode
- AFXAUTOHIDEDOCKSITE/CAutoHideDockSite::m_nExtraSpace
helpviewer_keywords:
- CAutoHideDockSite [MFC], CanAcceptPane
- CAutoHideDockSite [MFC], DockPane
- CAutoHideDockSite [MFC], GetAlignRect
- CAutoHideDockSite [MFC], RepositionPanes
- CAutoHideDockSite [MFC], SetOffsetLeft
- CAutoHideDockSite [MFC], SetOffsetRight
- CAutoHideDockSite [MFC], UnSetAutoHideMode
- CAutoHideDockSite [MFC], m_nExtraSpace
ms.assetid: 2a0f6bec-c369-4ab7-977d-564e7946ebad
ms.openlocfilehash: f24827e2dc1f4d1131f5b63aebeb0e2b09bc2281
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62388469"
---
# <a name="cautohidedocksite-class"></a>Classe CAutoHideDockSite

O `CAutoHideDockSite` estende o [classe CDockSite](../../mfc/reference/cdocksite-class.md) implementar painéis de encaixe de ocultação automática.

## <a name="syntax"></a>Sintaxe

```
class CAutoHideDockSite : public CDockSite
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|||
|-|-|
|Nome|Descrição|
|`CAutoHideDockSite::CAutoHideDockSite`|Constrói um objeto `CAutoHideDockSite`.|
|`CAutoHideDockSite::~CAutoHideDockSite`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|||
|-|-|
|Nome|Descrição|
|`CAutoHideDockSite::AllowShowOnPaneMenu`|Indica se o `CAutoHideDockSite` é mostrado no menu do painel.|
|[CAutoHideDockSite::CanAcceptPane](#canacceptpane)|Determina se um objeto de painel base é derivado de [classe CMFCAutoHideBar](../../mfc/reference/cmfcautohidebar-class.md).|
|[CAutoHideDockSite::DockPane](#dockpane)|Encaixa um painel a esta `CAuotHideDockSite` objeto.|
|[CAutoHideDockSite::GetAlignRect](#getalignrect)|Recupera o tamanho do site de encaixe em coordenadas da tela.|
|[CAutoHideDockSite::RepositionPanes](#repositionpanes)|Redesenha o painel no `CAutoHideDockSite` com as margens globais e o espaçamento do botão.|
|[CAutoHideDockSite::SetOffsetLeft](#setoffsetleft)|Define a margem no lado esquerdo da barra de encaixe.|
|[CAutoHideDockSite::SetOffsetRight](#setoffsetright)|Define a margem no lado direito da barra de encaixe.|
|[CAutoHideDockSite::UnSetAutoHideMode](#unsetautohidemode)|Chamadas [CMFCAutoHideBar::UnSetAutoHideMode](../../mfc/reference/cmfcautohidebar-class.md#unsetautohidemode) para objetos no `CAutoHideDockSite`.|

### <a name="data-members"></a>Membros de Dados

|||
|-|-|
|Nome|Descrição|
|[CAutoHideDockSite::m_nExtraSpace](#m_nextraspace)|Define o tamanho do espaço entre as barras de ferramentas e a borda da barra de encaixe. Esse espaço é medido desde a borda esquerda ou à borda superior, dependendo do alinhamento para o espaço de encaixe.|

## <a name="remarks"></a>Comentários

Quando você chama [CFrameWndEx::EnableAutoHidePanes](../../mfc/reference/cframewndex-class.md#enableautohidepanes), o framework cria automaticamente um `CAutoHideDockSite` objeto. Na maioria dos casos, você não deve instanciar ou usar essa classe diretamente.

A barra de encaixe é a lacuna entre o lado esquerdo do painel de encaixe e lado esquerdo do [classe CMFCAutoHideButton](../../mfc/reference/cmfcautohidebutton-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CBasePane](../../mfc/reference/cbasepane-class.md)

[CDockSite](../../mfc/reference/cdocksite-class.md)

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como recuperar um `CAutoHideDockSite` do objeto de um `CMFCAutoHideBar` objeto e como definir as margens esquerdas e direita da barra de encaixe.

[!code-cpp[NVC_MFC_RibbonApp#29](../../mfc/reference/codesnippet/cpp/cautohidedocksite-class_1.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxautohidedocksite.h

##  <a name="canacceptpane"></a>  CAutoHideDockSite::CanAcceptPane

Determina se um painel de base é uma [CMFCAutoHideBar](../../mfc/reference/cmfcautohidebar-class.md) do objeto ou dele derivado `CMFCAutoHideBar`.

```
virtual BOOL CanAcceptPane(const CBasePane* pBar) const;
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*pBar*|[in] O painel de base que a estrutura de teste.|

### <a name="return-value"></a>Valor de retorno

TRUE se *pBar* é derivado de `CMFCAutoHideBar`; FALSE caso contrário.

### <a name="remarks"></a>Comentários

Se um objeto de painel base é derivado de `CMFCAutoHideBar`, ele pode conter um `CAutoHideDockSite`.

##  <a name="dockpane"></a>  CAutoHideDockSite::DockPane

Encaixa um painel a esta [CAutoHideDockSite](../../mfc/reference/cautohidedocksite-class.md) objeto.

```
virtual void DockPane(
    CPane* pWnd,
    AFX_DOCK_METHOD dockMethod,
    LPRECT lpRect = NULL);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*pWnd*|[in] O painel que encaixa o framework.|
|*dockMethod*|[in] Opções para o painel de encaixe.|
|*lpRect*|[in] Um retângulo que especifica os limites para o painel encaixado.|

### <a name="remarks"></a>Comentários

A implementação padrão não usa o parâmetro *dockMethod*, que é fornecido para uso futuro.

Se *lpRect* for NULL, o framework coloca o painel no local padrão no site de encaixe. Se o local de encaixe é horizontal, o local padrão é na extremidade esquerda do local de encaixe. Caso contrário, o local padrão é na parte superior do local de encaixe.

##  <a name="getalignrect"></a>  CAutoHideDockSite::GetAlignRect

Recupera o tamanho do site de encaixe em coordenadas da tela.

```
void GetAlignRect(CRect& rect) const;
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*rect*|[in] Uma referência a um retângulo. O método armazena o tamanho do site encaixar nesse retângulo.|

### <a name="remarks"></a>Comentários

O retângulo é ajustado para as margens de deslocamento para que eles não estão incluídos.

##  <a name="m_nextraspace"></a>  CAutoHideDockSite::m_nExtraSpace

O tamanho do espaço entre as bordas do [classe CAutoHideDockSite](../../mfc/reference/cautohidedocksite-class.md) e o [classe CMFCAutoHideBar](../../mfc/reference/cmfcautohidebar-class.md) objetos.

```
static int m_nExtraSpace;
```

### <a name="remarks"></a>Comentários

Quando um `CMFCAutoHideBar` estiver encaixada em um `CAutoHideDockSite`, ele não deve ocupar o local de encaixe inteira. Essa variável global controla o espaço extra entre a borda esquerda ou superior do `CMFCAutoHideBar` e o correspondente `CAutoHideDockSite` edge. Se a borda superior ou esquerda é usada depende do alinhamento atual.

##  <a name="setoffsetleft"></a>  CAutoHideDockSite::SetOffsetLeft

Define a margem no lado esquerdo da barra de encaixe.

```
void SetOffsetLeft(int nOffset);
```

### <a name="parameters"></a>Parâmetros

*nOffset*<br/>
[in] O novo deslocamento.

### <a name="remarks"></a>Comentários

[CMFCAutoHideBar](../../mfc/reference/cmfcautohidebar-class.md) objetos são posicionados na estaticamente o `CAutoHideDockSite` objeto. Isso significa que o usuário não pode alterar manualmente o local do `CMFCAutoHideBar` objetos. O `SetOffsetLeft` método controla o espaçamento entre o lado esquerdo do mais à esquerda `CMFCAutoHideBar` e o lado esquerdo do `CAutoHideDockSite`.

##  <a name="setoffsetright"></a>  CAutoHideDockSite::SetOffsetRight

Define a margem no lado direito da barra de encaixe.

```
void SetOffsetRight(int nOffset);
```

### <a name="parameters"></a>Parâmetros

*nOffset*<br/>
[in] O novo deslocamento.

### <a name="remarks"></a>Comentários

[CMFCAutoHideBar](../../mfc/reference/cmfcautohidebar-class.md) objetos são posicionados na estaticamente o `CAutoHideDockSite` objeto. Isso significa que o usuário não pode alterar manualmente o local do `CMFCAutoHideBar` objetos. O `SetOffsetRight` método controla o espaçamento entre o lado direito da extrema direita `CMFCAutoHideBar` e à direita do `CAutoHideDockSite`.

##  <a name="repositionpanes"></a>  CAutoHideDockSite::RepositionPanes

Redesenha os painéis na [CAutoHideDockSite](../../mfc/reference/cautohidedocksite-class.md).

```
virtual void RepositionPanes(CRect& rectNewClientArea);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*rectNewClientArea*|[in] Um valor reservado.|

### <a name="remarks"></a>Comentários

A implementação padrão não usa *rectNewClientArea*. Ele redesenha os painéis com as margens de barra de ferramentas global e o espaçamento do botão.

##  <a name="unsetautohidemode"></a>  CAutoHideDockSite::UnSetAutoHideMode

Chamadas [CMFCAutoHideBar::UnSetAutoHideMode](../../mfc/reference/cmfcautohidebar-class.md#unsetautohidemode) para objetos no site de encaixe.

```
void UnSetAutoHideMode(CMFCAutoHideBar* pAutoHideToolbar);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*pAutoHideToolbar*|[in] Um ponteiro para um [CMFCAutoHideBar](../../mfc/reference/cmfcautohidebar-class.md) painel de objeto localizado no `CAutoHideDockSite`.|

### <a name="remarks"></a>Comentários

Esse método pesquisará a linha que contém *pAutoHideToolbar*. Ele chama `CMFCAutoHideBar.UnSetAutoHideMode` para todos os `CMFCAutoHideBar` objetos nessa linha. Se *pAutoHideToolbar* não for encontrado ou é NULL, esse método chama `CMFCAutoHideBar.UnSetAutoHideMode` para todos os o `CMFCAutoHideBar` objetos no `CAutoHideDockSite`.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CDockSite](../../mfc/reference/cdocksite-class.md)
