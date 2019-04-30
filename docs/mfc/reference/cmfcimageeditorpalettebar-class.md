---
title: Classe CMFCImageEditorPaletteBar
ms.date: 11/04/2016
f1_keywords:
- CMFCImageEditorPaletteBar
- AFXIMAGEEDITORDIALOG/CMFCImageEditorPaletteBar
- AFXIMAGEEDITORDIALOG/CMFCImageEditorPaletteBar::GetRowHeight
- AFXIMAGEEDITORDIALOG/CMFCImageEditorPaletteBar::IsButtonExtraSizeAvailable
helpviewer_keywords:
- CMFCImageEditorPaletteBar [MFC], GetRowHeight
- CMFCImageEditorPaletteBar [MFC], IsButtonExtraSizeAvailable
ms.assetid: 3fb7ba8e-f254-4d56-b913-9941b4ed8138
ms.openlocfilehash: 6812f3f425186484ef892d7f5c626c0dfce0f863
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62378096"
---
# <a name="cmfcimageeditorpalettebar-class"></a>Classe CMFCImageEditorPaletteBar

Fornece a funcionalidade de barra de paleta para uma caixa de diálogo do editor de imagem.

## <a name="syntax"></a>Sintaxe

```
class CMFCImageEditorPaletteBar : public CMFCToolBar
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|||
|-|-|
|Nome|Descrição|
|[CMFCImageEditorPaletteBar::GetRowHeight](#getrowheight)|Retorna a altura dos botões da barra de ferramentas. (Substitui [CMFCToolBar::GetRowHeight](../../mfc/reference/cmfctoolbar-class.md#getrowheight).)|
|[CMFCImageEditorPaletteBar::IsButtonExtraSizeAvailable](#isbuttonextrasizeavailable)|Determina se a barra de ferramentas pode exibir botões que tem estendido bordas. (Substitui [CMFCToolBar::IsButtonExtraSizeAvailable](../../mfc/reference/cmfctoolbar-class.md#isbuttonextrasizeavailable).)|

### <a name="remarks"></a>Comentários

Essa classe não se destina a ser usada diretamente do seu código.

A estrutura usa essa classe para exibir uma barra de paleta em uma caixa de diálogo do editor de imagem. Para obter mais informações sobre a caixa de diálogo do editor de imagem, consulte [classe CMFCImageEditorDialog](../../mfc/reference/cmfcimageeditordialog-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CBasePane](../../mfc/reference/cbasepane-class.md)

[CPane](../../mfc/reference/cpane-class.md)

[CMFCBaseToolBa](../../mfc/reference/cmfcbasetoolbar-class.md)

[CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)

[CMFCImageEditorPaletteBar](../../mfc/reference/cmfcimageeditorpalettebar-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afximageeditordialog.h

##  <a name="getrowheight"></a>  CMFCImageEditorPaletteBar::GetRowHeight

Retorna a altura dos botões da barra de ferramentas.

```
virtual int GetRowHeight() const;
```

### <a name="return-value"></a>Valor de retorno

A altura de cada botão na barra de ferramentas.

##  <a name="isbuttonextrasizeavailable"></a>  CMFCImageEditorPaletteBar::IsButtonExtraSizeAvailable

Determina se a barra de ferramentas pode exibir botões que tem estendido bordas.

```
virtual BOOL IsButtonExtraSizeAvailable() const;
```

### <a name="return-value"></a>Valor de retorno

Esse método retornará FALSE.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCImageEditorDialog](../../mfc/reference/cmfcimageeditordialog-class.md)
