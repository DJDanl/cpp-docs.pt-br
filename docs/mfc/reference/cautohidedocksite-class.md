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
ms.openlocfilehash: 3a4593ac17f0af26517144edb7b01a9ca4203b1a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81352976"
---
# <a name="cautohidedocksite-class"></a>Classe CAutoHideDockSite

O `CAutoHideDockSite` estende a [Classe CDockSite](../../mfc/reference/cdocksite-class.md) para implementar painéis de doca de ocultação automática.

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
|`CAutoHideDockSite::AllowShowOnPaneMenu`|Indica se `CAutoHideDockSite` o é mostrado no menu do painel.|
|[CAutoHideDockSite::CanAcceptPane](#canacceptpane)|Determina se um objeto de painel de base é derivado da [classe CMFCAutoHideBar](../../mfc/reference/cmfcautohidebar-class.md).|
|[CAutoHideDockSite::DockPane](#dockpane)|Docas um painel `CAuotHideDockSite` para este objeto.|
|[CAutoHideDockSite::GetAlignRect](#getalignrect)|Recupera o tamanho do local do dock em coordenadas de tela.|
|[CAutoHideDockSite::ReposicionarPanes](#repositionpanes)|Redesenha o painel `CAutoHideDockSite` com as margens globais e o espaçamento de botões.|
|[CAutoHidedockSite::SetOffsetLeft](#setoffsetleft)|Define a margem do lado esquerdo da barra de acoplamento.|
|[cAutoHidedockSite::SetOffsetSetRight](#setoffsetright)|Define a margem do lado direito da barra de acoplamento.|
|[CAuto'SSiteDeocultação:''Configuração'' 'Ocultar', conjunto 'Ocultar'?](#unsetautohidemode)|Chama [CMFCAutoHideBar::UnSetAutoHideMode](../../mfc/reference/cmfcautohidebar-class.md#unsetautohidemode) para `CAutoHideDockSite`objetos no .|

### <a name="data-members"></a>Membros de dados

|||
|-|-|
|Nome|Descrição|
|[CAutoHideDockSite::m_nExtraSpace](#m_nextraspace)|Define o tamanho do espaço entre as barras de ferramentas e a borda da barra de acoplamento. Este espaço é medido a partir da borda esquerda ou da borda superior, dependendo do alinhamento para o espaço das docas.|

## <a name="remarks"></a>Comentários

Quando você chama [CFrameWndEx::EnableAutoHidePanes,](../../mfc/reference/cframewndex-class.md#enableautohidepanes)a `CAutoHideDockSite` estrutura cria automaticamente um objeto. Na maioria dos casos, você não deve ter que instanciar ou usar esta classe diretamente.

A barra de acoplamento é a lacuna entre o lado esquerdo do painel de doca e o lado esquerdo da [classe CMFCAutoHideButton](../../mfc/reference/cmfcautohidebutton-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cbasepane](../../mfc/reference/cbasepane-class.md)

[Cdocksite](../../mfc/reference/cdocksite-class.md)

## <a name="example"></a>Exemplo

O exemplo a seguir `CAutoHideDockSite` demonstra como `CMFCAutoHideBar` recuperar um objeto de um objeto e como definir as margens esquerda e direita da barra de acoplamento.

[!code-cpp[NVC_MFC_RibbonApp#29](../../mfc/reference/codesnippet/cpp/cautohidedocksite-class_1.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxautohidedocksite.h

## <a name="cautohidedocksitecanacceptpane"></a><a name="canacceptpane"></a>CAutoHideDockSite::CanAcceptPane

Determina se um painel de base é um objeto [CMFCAutoHideBar](../../mfc/reference/cmfcautohidebar-class.md) ou derivado de `CMFCAutoHideBar`.

```
virtual BOOL CanAcceptPane(const CBasePane* pBar) const;
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*Pbar*|[em] O painel base que a estrutura testa.|

### <a name="return-value"></a>Valor retornado

TRUE se *pBar* é `CMFCAutoHideBar`derivado de; FALSO de outra forma.

### <a name="remarks"></a>Comentários

Se um objeto de painel `CMFCAutoHideBar`base for derivado, ele pode conter um `CAutoHideDockSite`.

## <a name="cautohidedocksitedockpane"></a><a name="dockpane"></a>CAutoHideDockSite::DockPane

Acopla um painel a este objeto [CAutoHideDockSite.](../../mfc/reference/cautohidedocksite-class.md)

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
|*Pwnd*|[em] O painel que a estrutura dota.|
|*Dockmethod*|[em] Opções de acoplamento para o painel.|
|*Lprect*|[em] Um retângulo que especifica os limites para o painel ancorado.|

### <a name="remarks"></a>Comentários

A implementação padrão não usa o parâmetro *dockMethod*, que é fornecido para uso futuro.

Se *o lpRect* for NULL, a estrutura coloca o painel no local padrão no local do dock. Se o local do dock for horizontal, o local padrão estará no extremo esquerdo do local de doca. Caso contrário, o local padrão está na parte superior do local de doca.

## <a name="cautohidedocksitegetalignrect"></a><a name="getalignrect"></a>CAutoHideDockSite::GetAlignRect

Recupera o tamanho do local do dock em coordenadas de tela.

```
void GetAlignRect(CRect& rect) const;
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*Rect*|[em] Uma referência a um retângulo. O método armazena o tamanho do local de doca neste retângulo.|

### <a name="remarks"></a>Comentários

O retângulo é ajustado para as margens de deslocamento para que não sejam incluídas.

## <a name="cautohidedocksitem_nextraspace"></a><a name="m_nextraspace"></a>CAutoHideDockSite::m_nExtraSpace

O tamanho do espaço entre as bordas da [Classe CAutoHideDockSite](../../mfc/reference/cautohidedocksite-class.md) e os objetos [CMFCAutoHideBar Class.](../../mfc/reference/cmfcautohidebar-class.md)

```
static int m_nExtraSpace;
```

### <a name="remarks"></a>Comentários

Quando `CMFCAutoHideBar` um está ancorado `CAutoHideDockSite`em um , ele não deve ocupar todo o local de doca. Esta variável global controla o espaço extra entre `CMFCAutoHideBar` a `CAutoHideDockSite` borda esquerda ou superior da borda correspondente. Se a borda superior ou esquerda é usada depende do alinhamento atual.

## <a name="cautohidedocksitesetoffsetleft"></a><a name="setoffsetleft"></a>CAutoHidedockSite::SetOffsetLeft

Define a margem do lado esquerdo da barra de acoplamento.

```
void SetOffsetLeft(int nOffset);
```

### <a name="parameters"></a>Parâmetros

*nOffset*<br/>
[em] O novo deslocamento.

### <a name="remarks"></a>Comentários

Os objetos [CMFCAutoHideBar](../../mfc/reference/cmfcautohidebar-class.md) estão `CAutoHideDockSite` posicionados estáticamente no objeto. Isso significa que o usuário não `CMFCAutoHideBar` pode alterar manualmente a localização dos objetos. O `SetOffsetLeft` método controla o espaçamento entre o `CMFCAutoHideBar` lado esquerdo da `CAutoHideDockSite`esquerda e o esquerdo do .

## <a name="cautohidedocksitesetoffsetright"></a><a name="setoffsetright"></a>cAutoHidedockSite::SetOffsetSetRight

Define a margem do lado direito da barra de acoplamento.

```
void SetOffsetRight(int nOffset);
```

### <a name="parameters"></a>Parâmetros

*nOffset*<br/>
[em] O novo deslocamento.

### <a name="remarks"></a>Comentários

Os objetos [CMFCAutoHideBar](../../mfc/reference/cmfcautohidebar-class.md) estão `CAutoHideDockSite` posicionados estáticamente no objeto. Isso significa que o usuário não pode `CMFCAutoHideBar` alterar manualmente a localização dos objetos. O `SetOffsetRight` método controla o espaçamento entre o `CMFCAutoHideBar` lado direito do `CAutoHideDockSite`mais direito e o lado direito do .

## <a name="cautohidedocksiterepositionpanes"></a><a name="repositionpanes"></a>CAutoHideDockSite::ReposicionarPanes

Redesenha os painéis no [CAutoHideDockSite](../../mfc/reference/cautohidedocksite-class.md).

```
virtual void RepositionPanes(CRect& rectNewClientArea);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*rectNewClientArea*|[em] Um valor reservado.|

### <a name="remarks"></a>Comentários

A implementação padrão não usa *rectNewClientArea*. Ele redesenha os painéis com as margens globais da barra de ferramentas e o espaçamento de botões.

## <a name="cautohidedocksiteunsetautohidemode"></a><a name="unsetautohidemode"></a>CAuto'SSiteDeocultação:''Configuração'' 'Ocultar', conjunto 'Ocultar'?

Chama [CMFCAutoHideBar::UnSetAutoHideMode](../../mfc/reference/cmfcautohidebar-class.md#unsetautohidemode) para objetos no local do dock.

```
void UnSetAutoHideMode(CMFCAutoHideBar* pAutoHideToolbar);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*barra de ferramentas pAutoHide*|[em] Um ponteiro para um painel de [objetos CMFCAutoHideBar](../../mfc/reference/cmfcautohidebar-class.md) localizado no `CAutoHideDockSite`.|

### <a name="remarks"></a>Comentários

Este método procura a linha que contém *pAutoHideToolbar*. Ele `CMFCAutoHideBar.UnSetAutoHideMode` pede todos `CMFCAutoHideBar` os objetos naquela linha. Se *pAutoHideToolbar* não for encontrado ou for `CMFCAutoHideBar.UnSetAutoHideMode` NULL, `CMFCAutoHideBar` este `CAutoHideDockSite`método exige todos os objetos no .

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CDockSite](../../mfc/reference/cdocksite-class.md)
