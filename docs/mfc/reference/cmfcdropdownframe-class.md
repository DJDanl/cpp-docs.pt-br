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
ms.openlocfilehash: a5e95efe1880f1177490d55988ca1fe42c606b15
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367549"
---
# <a name="cmfcdropdownframe-class"></a>Classe CMFCDropDownFrame

Fornece a funcionalidade da janela do quadro para baixo para barras de ferramentas gotas e botões de barra de ferramentas gota.

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
|[CMFCDropDownFrame::Criar](#create)|Cria um objeto `CMFCDropDownFrame`.|
|`CMFCDropDownFrame::CreateObject`|Usado pela estrutura para criar uma instância dinâmica desse tipo de classe.|
|[CMFCDropDownframe::getParentmenubar](#getparentmenubar)|Recupera a barra de menu pai do quadro suspenso.|
|[CMFCDropDownFrame::GetParentPopupMenu](#getparentpopupmenu)|Recupera o menu pop-up pai do quadro suspenso.|
|`CMFCDropDownFrame::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a este tipo de classe.|
|[CMFCDropDownFrame::RecalcLayout](#recalclayout)|Reposiciona o quadro de isento.|
|[CMFCDropDownFrame::SetAutoDestroy](#setautodestroy)|Define se a janela da barra de ferramentas suspensa da criança é destruída automaticamente.|

### <a name="remarks"></a>Comentários

Essa classe não se destina a ser usada diretamente do seu código.

A estrutura usa essa classe para `CMFCDropDownToolbar` `CMFCDropDownToolbarButton` fornecer comportamento de quadro para as classes e classes. Para obter mais informações sobre essas classes, consulte [CMFCDropDownToolBar Class](../../mfc/reference/cmfcdropdowntoolbar-class.md) e [CMFCDropDownToolbarButton Class](../../mfc/reference/cmfcdropdowntoolbarbutton-class.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCDropDownFrame` recuperar `CFrameWnd` um ponteiro para um objeto de uma classe e como definir a janela da barra de ferramentas suspensa para criança a ser destruída automaticamente.

[!code-cpp[NVC_MFC_RibbonApp#36](../../mfc/reference/codesnippet/cpp/cmfcdropdownframe-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CFrameWnd](../../mfc/reference/cframewnd-class.md)

[Cminiframewnd](../../mfc/reference/cminiframewnd-class.md)

[Cmfcdropdownframe](../../mfc/reference/cmfcdropdownframe-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdropdowntoolbar.h

## <a name="cmfcdropdownframecreate"></a><a name="create"></a>CMFCDropDownFrame::Criar

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
|*pWndParent*|[em] A janela dos pais do quadro de queda.|
|*x*|[em] A coordenada de tela horizontal para a localização do quadro down-down.|
|*Y*|[em] A coordenada de tela vertical para a localização do quadro down-down.|
|*barra de ferramentas pWndOrigin*|[em] A barra de ferramentas que tem os botões de baixa que este método usa para preencher o novo objeto de quadro estilhaçado.|

### <a name="return-value"></a>Valor retornado

TRUE se o quadro de baixa foi criado com sucesso; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Este método chama o método [Base CMiniFrameWnd::CreateEx](../../mfc/reference/cminiframewnd-class.md#createex) para criar a janela de quadro saudosa com o estilo WS_POPUP. A janela do quadro de sumário é exibida nas coordenadas de tela especificadas. Este método falha se o método [CMiniFrameWnd::CreateEx](../../mfc/reference/cminiframewnd-class.md#createex) retornar FALSO.

A `CMFCDropDownFrame` classe cria uma cópia `CMFCDropDownToolBar` do parâmetro fornecido. Este método copia as imagens `pWndOriginToolbar` do botão `m_pWndOriginToolbar` e os estados do botão do parâmetro para o membro de dados.

## <a name="cmfcdropdownframegetparentmenubar"></a><a name="getparentmenubar"></a>CMFCDropDownframe::getParentmenubar

Recupera a barra de menu pai do quadro suspenso.

```
CMFCMenuBar* GetParentMenuBar() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a barra de menu pai do quadro suspenso ou NULL se o quadro não tiver pai.

### <a name="remarks"></a>Comentários

Este método recupera a barra de menu pai do botão pai. Este método retorna NULL se o quadro suspenso não tiver nenhum botão pai ou o botão pai não tiver barra de menu dos pais.

## <a name="cmfcdropdownframegetparentpopupmenu"></a><a name="getparentpopupmenu"></a>CMFCDropDownFrame::GetParentPopupMenu

Recupera o menu pop-up pai do quadro suspenso.

```
CMFCDropDownFrame* GetParentPopupMenu() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o menu suspenso pai do quadro suspenso ou NULL se o quadro não tiver pai.

### <a name="remarks"></a>Comentários

Este método recupera o menu pai do botão pai. Este método retorna NULL se o quadro suspenso não tiver nenhum botão pai ou o botão pai não tiver menu pai.

## <a name="cmfcdropdownframerecalclayout"></a><a name="recalclayout"></a>CMFCDropDownFrame::RecalcLayout

Reposiciona o quadro de isento.

```
virtual void RecalcLayout(BOOL bNotify = TRUE);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*bNotificar*|[em] Utilizadas.|

### <a name="remarks"></a>Comentários

A estrutura chama esse método quando o quadro de saque é criado ou a janela pai é redimensionada. Este método calcula a posição e o tamanho do quadro de baixa usando a posição e o tamanho da janela pai.

## <a name="cmfcdropdownframesetautodestroy"></a><a name="setautodestroy"></a>CMFCDropDownFrame::SetAutoDestroy

Define se a janela da barra de ferramentas suspensa da criança é destruída automaticamente.

```
void SetAutoDestroy(BOOL bAutoDestroy = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bAutoDestroy*<br/>
[em] True para destruir automaticamente a janela de barra de ferramentas drop-down associada; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se *bAutoDestroy* for TRUE, o `CMFCDropDownFrame` destruidor destruirá a janela da barra de ferramentas associada. O valor padrão é TRUE.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCDropDownToolBar](../../mfc/reference/cmfcdropdowntoolbar-class.md)<br/>
[Classe CMFCDropDownToolbarButton](../../mfc/reference/cmfcdropdowntoolbarbutton-class.md)
