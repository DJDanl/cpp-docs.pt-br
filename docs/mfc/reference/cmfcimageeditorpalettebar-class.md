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
ms.openlocfilehash: 007fa94269a6a42bf076d2d75a18860896503aa1
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88831158"
---
# <a name="cmfcimageeditorpalettebar-class"></a>Classe CMFCImageEditorPaletteBar

Fornece a funcionalidade da barra de paleta para uma caixa de diálogo do editor de imagens.

## <a name="syntax"></a>Sintaxe

```
class CMFCImageEditorPaletteBar : public CMFCToolBar
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|-|-|
|[CMFCImageEditorPaletteBar:: getalturadalinha](#getrowheight)|Retorna a altura dos botões da barra de ferramentas. (Substitui [CMFCToolBar:: getalturadalinha](../../mfc/reference/cmfctoolbar-class.md#getrowheight).)|
|[CMFCImageEditorPaletteBar::IsButtonExtraSizeAvailable](#isbuttonextrasizeavailable)|Determina se a barra de ferramentas pode exibir botões com bordas estendidas. (Substitui [CMFCToolBar:: IsButtonExtraSizeAvailable](../../mfc/reference/cmfctoolbar-class.md#isbuttonextrasizeavailable).)|

### <a name="remarks"></a>Comentários

Essa classe não se destina a ser usada diretamente do seu código.

A estrutura usa essa classe para exibir uma barra de paleta em uma caixa de diálogo do editor de imagens. Para obter mais informações sobre a caixa de diálogo Editor de imagens, consulte [classe CMFCImageEditorDialog](../../mfc/reference/cmfcimageeditordialog-class.md).

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

**Cabeçalho:** afximageeditordialog. h

## <a name="cmfcimageeditorpalettebargetrowheight"></a><a name="getrowheight"></a> CMFCImageEditorPaletteBar:: getalturadalinha

Retorna a altura dos botões da barra de ferramentas.

```
virtual int GetRowHeight() const;
```

### <a name="return-value"></a>Valor Retornado

A altura de cada botão na barra de ferramentas.

## <a name="cmfcimageeditorpalettebarisbuttonextrasizeavailable"></a><a name="isbuttonextrasizeavailable"></a> CMFCImageEditorPaletteBar::IsButtonExtraSizeAvailable

Determina se a barra de ferramentas pode exibir botões com bordas estendidas.

```
virtual BOOL IsButtonExtraSizeAvailable() const;
```

### <a name="return-value"></a>Valor Retornado

Esse método retorna FALSE.

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCImageEditorDialog](../../mfc/reference/cmfcimageeditordialog-class.md)
