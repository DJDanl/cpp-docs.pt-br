---
title: Classe CMFCDropDownFrame
ms.date: 11/04/2016
f1_keywords:
- CMFCDropDownFrame
- AFXDROPDOWNTOOLBAR/CMFCDropDownFrame
- AFXDROPDOWNTOOLBAR/CMFCDropDownFrame::Create
- AFXDROPDOWNTOOLBAR/CMFCDropDownFrame::GetParentMenuBar
- AFXDROPDOWNTOOLBAR/CMFCDropDownFrame::GetParentPopupMenu
- AFXDROPDOWNTOOLBAR/CMFCDropDownFrame::RecalcLayout
- AFXDROPDOWNTOOLBAR/CMFCDropDownFrame::SetAutoDestroy
helpviewer_keywords:
- CMFCDropDownFrame [MFC], Create
- CMFCDropDownFrame [MFC], GetParentMenuBar
- CMFCDropDownFrame [MFC], GetParentPopupMenu
- CMFCDropDownFrame [MFC], RecalcLayout
- CMFCDropDownFrame [MFC], SetAutoDestroy
ms.assetid: 09ff81a9-de00-43ec-9df9-b626f7728c4b
ms.openlocfilehash: 534dc90443371c8440e0cb317540f2cf80f6eacc
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62237367"
---
# <a name="cmfcdropdownframe-class"></a>Classe CMFCDropDownFrame

Fornece a funcionalidade de janela de quadro da lista suspensa para barras de ferramentas de lista suspensa e botões da barra de ferramentas da lista suspensa.

## <a name="syntax"></a>Sintaxe

```
class CMFCDropDownFrame : public CMiniFrameWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|||
|-|-|
|Nome|Descrição|
|`CMFCDropDownFrame::CMFCDropDownFrame`|Construtor padrão.|
|`CMFCDropDownFrame::~CMFCDropDownFrame`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|||
|-|-|
|Nome|Descrição|
|[CMFCDropDownFrame::Create](#create)|Cria um objeto `CMFCDropDownFrame`.|
|`CMFCDropDownFrame::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|
|[CMFCDropDownFrame::GetParentMenuBar](#getparentmenubar)|Recupera a barra de menu pai do quadro de lista suspensa.|
|[CMFCDropDownFrame::GetParentPopupMenu](#getparentpopupmenu)|Recupera o menu pop-up do pai do quadro de lista suspensa.|
|`CMFCDropDownFrame::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto que está associado com esse tipo de classe.|
|[CMFCDropDownFrame::RecalcLayout](#recalclayout)|Reposiciona o quadro da lista suspensa.|
|[CMFCDropDownFrame::SetAutoDestroy](#setautodestroy)|Define se a janela filho da lista suspensa da barra de ferramentas é destruída automaticamente.|

### <a name="remarks"></a>Comentários

Essa classe não se destina a ser usada diretamente do seu código.

A estrutura usa essa classe para fornecer comportamento de quadro para o `CMFCDropDownToolbar` e `CMFCDropDownToolbarButton` classes. Para obter mais informações sobre essas classes, consulte [classe CMFCDropDownToolBar](../../mfc/reference/cmfcdropdowntoolbar-class.md) e [classe CMFCDropDownToolbarButton](../../mfc/reference/cmfcdropdowntoolbarbutton-class.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como recuperar um ponteiro para um `CMFCDropDownFrame` do objeto de um `CFrameWnd` classe e como definir o filho janela suspensa da barra de ferramentas a ser destruído automaticamente.

[!code-cpp[NVC_MFC_RibbonApp#36](../../mfc/reference/codesnippet/cpp/cmfcdropdownframe-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CFrameWnd](../../mfc/reference/cframewnd-class.md)

[CMiniFrameWnd](../../mfc/reference/cminiframewnd-class.md)

[CMFCDropDownFrame](../../mfc/reference/cmfcdropdownframe-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdropdowntoolbar.h

##  <a name="create"></a>  CMFCDropDownFrame::Create

Cria um objeto `CMFCDropDownFrame`.

```
virtual BOOL Create(
    CWnd* pWndParent,
    int x,
    int y,
    CMFCDropDownToolBar* pWndOriginToolbar);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*pWndParent*|[in] A janela pai do quadro de lista suspensa.|
|*x*|[in] A coordenada horizontal da tela para o local do quadro suspensa.|
|*y*|[in] A coordenada vertical da tela para o local do quadro suspensa.|
|*pWndOriginToolbar*|[in] A barra de ferramentas tem os botões de menu suspenso que esse método usa para popular o novo objeto de quadro da lista suspensa.|

### <a name="return-value"></a>Valor de retorno

TRUE se o quadro da lista suspensa foi criado com êxito; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método chama base [CMiniFrameWnd::CreateEx](../../mfc/reference/cminiframewnd-class.md#createex) método para criar a janela do quadro da lista suspensa com o estilo WS_POPUP. A janela do quadro da lista suspensa aparece em coordenadas da tela especificadas. Esse método falhará se o [CMiniFrameWnd::CreateEx](../../mfc/reference/cminiframewnd-class.md#createex) método retornará FALSE.

O `CMFCDropDownFrame` classe cria uma cópia fornecidos `CMFCDropDownToolBar` parâmetro. Esse método copia as imagens de botão e os estados do botão do `pWndOriginToolbar` parâmetro para o `m_pWndOriginToolbar` membro de dados.

##  <a name="getparentmenubar"></a>  CMFCDropDownFrame::GetParentMenuBar

Recupera a barra de menu pai do quadro de lista suspensa.

```
CMFCMenuBar* GetParentMenuBar() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a barra de menu pai do quadro da lista suspensa, ou nulo se o quadro não tem nenhum pai.

### <a name="remarks"></a>Comentários

Esse método recupera a barra de menu pai do botão pai. Esse método retornará nulo se o quadro de lista suspensa não tem nenhum botão pai ou no botão pai não tiver nenhuma barra de menu pai.

##  <a name="getparentpopupmenu"></a>  CMFCDropDownFrame::GetParentPopupMenu

Recupera o menu pop-up do pai do quadro de lista suspensa.

```
CMFCDropDownFrame* GetParentPopupMenu() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o menu suspenso de pai do quadro da lista suspensa, ou nulo se o quadro não tem nenhum pai.

### <a name="remarks"></a>Comentários

Esse método recupera o menu pai do botão pai. Esse método retornará nulo se o quadro de lista suspensa não tem nenhum botão pai ou o botão de pai não tem nenhum menu pai.

##  <a name="recalclayout"></a>  CMFCDropDownFrame::RecalcLayout

Reposiciona o quadro da lista suspensa.

```
virtual void RecalcLayout(BOOL bNotify = TRUE);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*bNotify*|[in] Não utilizado.|

### <a name="remarks"></a>Comentários

O framework chama esse método quando o quadro da lista suspensa é criado ou a janela pai é redimensionada. Esse método calcula a posição e tamanho do quadro suspensa usando-se a posição e tamanho da janela pai.

##  <a name="setautodestroy"></a>  CMFCDropDownFrame::SetAutoDestroy

Define se a janela filho da lista suspensa da barra de ferramentas é destruída automaticamente.

```
void SetAutoDestroy(BOOL bAutoDestroy = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bAutoDestroy*<br/>
[in] TRUE para destruir automaticamente a janela de ferramentas de lista suspensa associada; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se *bAutoDestroy* for TRUE, então o `CMFCDropDownFrame` destruidor destrói a janela de ferramentas de lista suspensa associada. O valor padrão é TRUE.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCDropDownToolBar](../../mfc/reference/cmfcdropdowntoolbar-class.md)<br/>
[Classe CMFCDropDownToolbarButton](../../mfc/reference/cmfcdropdowntoolbarbutton-class.md)
