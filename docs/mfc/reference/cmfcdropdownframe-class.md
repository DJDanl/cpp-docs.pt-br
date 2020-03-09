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
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78869058"
---
# <a name="cmfcdropdownframe-class"></a>Classe CMFCDropDownFrame

Fornece a funcionalidade da janela de quadro suspensa para barras de ferramentas suspensas e botões da barra de ferramentas suspensas.

## <a name="syntax"></a>Sintaxe

```
class CMFCDropDownFrame : public CMiniFrameWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|||
|-|-|
|{1&gt;Nome&lt;1}|Descrição|
|`CMFCDropDownFrame::CMFCDropDownFrame`|Construtor padrão.|
|`CMFCDropDownFrame::~CMFCDropDownFrame`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|||
|-|-|
|{1&gt;Nome&lt;1}|Descrição|
|[CMFCDropDownFrame:: criar](#create)|Cria um objeto `CMFCDropDownFrame`.|
|`CMFCDropDownFrame::CreateObject`|Usado pela estrutura para criar uma instância dinâmica desse tipo de classe.|
|[CMFCDropDownFrame::GetParentMenuBar](#getparentmenubar)|Recupera a barra de menus pai do quadro suspenso.|
|[CMFCDropDownFrame::GetParentPopupMenu](#getparentpopupmenu)|Recupera o menu pop-up pai do quadro suspenso.|
|`CMFCDropDownFrame::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a esse tipo de classe.|
|[CMFCDropDownFrame::RecalcLayout](#recalclayout)|Reposiciona o quadro suspenso.|
|[CMFCDropDownFrame::SetAutoDestroy](#setautodestroy)|Define se a janela da barra de ferramentas suspensa filho é destruída automaticamente.|

### <a name="remarks"></a>Comentários

Essa classe não se destina a ser usada diretamente do seu código.

A estrutura usa essa classe para fornecer o comportamento de quadro para as classes `CMFCDropDownToolbar` e `CMFCDropDownToolbarButton`. Para obter mais informações sobre essas classes, consulte [Classe CMFCDropDownToolBar](../../mfc/reference/cmfcdropdowntoolbar-class.md) e [classe CMFCDropDownToolbarButton](../../mfc/reference/cmfcdropdowntoolbarbutton-class.md).

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir demonstra como recuperar um ponteiro para um objeto `CMFCDropDownFrame` de uma classe `CFrameWnd` e como definir a janela da barra de ferramentas suspensa filho para ser destruída automaticamente.

[!code-cpp[NVC_MFC_RibbonApp#36](../../mfc/reference/codesnippet/cpp/cmfcdropdownframe-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CFrameWnd](../../mfc/reference/cframewnd-class.md)

[CMiniFrameWnd](../../mfc/reference/cminiframewnd-class.md)

[CMFCDropDownFrame](../../mfc/reference/cmfcdropdownframe-class.md)

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** afxdropdowntoolbar. h

##  <a name="create"></a>CMFCDropDownFrame:: criar

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
|*pWndParent*|no A janela pai do quadro suspenso.|
|*x*|no A coordenada de tela horizontal para o local do quadro abaixo.|
|*y*|no A tela vertical coordenada para o local do quadro abaixo.|
|*pWndOriginToolbar*|no A barra de ferramentas que tem os botões suspensos que esse método usa para popular o novo objeto de quadro suspenso.|

### <a name="return-value"></a>Valor retornado

TRUE se o quadro suspenso foi criado com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método chama o método base [CMiniFrameWnd:: CreateEx](../../mfc/reference/cminiframewnd-class.md#createex) para criar a janela de quadro suspensa com o estilo de WS_POPUP. A janela do quadro suspenso é exibida nas coordenadas de tela especificadas. Esse método falhará se o método [CMiniFrameWnd:: CreateEx](../../mfc/reference/cminiframewnd-class.md#createex) retornar false.

A classe `CMFCDropDownFrame` cria uma cópia do parâmetro `CMFCDropDownToolBar` fornecido. Esse método copia as imagens de botão e os Estados de botão do parâmetro `pWndOriginToolbar` para o membro de dados `m_pWndOriginToolbar`.

##  <a name="getparentmenubar"></a>CMFCDropDownFrame::GetParentMenuBar

Recupera a barra de menus pai do quadro suspenso.

```
CMFCMenuBar* GetParentMenuBar() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a barra de menus pai do quadro suspenso ou nulo se o quadro não tiver nenhum pai.

### <a name="remarks"></a>Comentários

Esse método recupera a barra de menus pai do botão pai. Esse método retornará nulo se o quadro suspenso não tiver nenhum botão pai ou o botão pai não tiver nenhuma barra de menus pai.

##  <a name="getparentpopupmenu"></a>CMFCDropDownFrame::GetParentPopupMenu

Recupera o menu pop-up pai do quadro suspenso.

```
CMFCDropDownFrame* GetParentPopupMenu() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o menu suspenso pai do quadro suspenso ou nulo se o quadro não tiver nenhum pai.

### <a name="remarks"></a>Comentários

Esse método recupera o menu pai do botão pai. Esse método retornará NULL se o quadro suspenso não tiver nenhum botão pai ou o botão pai não tiver nenhum menu pai.

##  <a name="recalclayout"></a>CMFCDropDownFrame::RecalcLayout

Reposiciona o quadro suspenso.

```
virtual void RecalcLayout(BOOL bNotify = TRUE);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*bNotify*|no Não utilizado.|

### <a name="remarks"></a>Comentários

A estrutura chama esse método quando o quadro suspenso é criado ou a janela pai é redimensionada. Esse método calcula a posição e o tamanho do quadro suspenso usando a posição e o tamanho da janela pai.

##  <a name="setautodestroy"></a>CMFCDropDownFrame::SetAutoDestroy

Define se a janela da barra de ferramentas suspensa filho é destruída automaticamente.

```
void SetAutoDestroy(BOOL bAutoDestroy = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bAutoDestroy*<br/>
no TRUE para destruir automaticamente a janela da barra de ferramentas suspensa associada; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se *bAutoDestroy* for true, o destruidor `CMFCDropDownFrame` destruirá a janela da barra de ferramentas suspensa associada. O valor padrão é TRUE.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCDropDownToolBar](../../mfc/reference/cmfcdropdowntoolbar-class.md)<br/>
[Classe CMFCDropDownToolbarButton](../../mfc/reference/cmfcdropdowntoolbarbutton-class.md)
