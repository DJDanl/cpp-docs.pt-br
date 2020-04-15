---
title: Classe CMFCWindowsManagerDialog
ms.date: 11/04/2016
f1_keywords:
- CMFCWindowsManagerDialog
- AFXWINDOWSMANAGERDIALOG/CMFCWindowsManagerDialog
- AFXWINDOWSMANAGERDIALOG/CMFCWindowsManagerDialog::CMFCWindowsManagerDialog
helpviewer_keywords:
- CMFCWindowsManagerDialog [MFC], CMFCWindowsManagerDialog
ms.assetid: 35b4b0db-33c4-4b22-94d8-5e3396341340
ms.openlocfilehash: e3928c0d3ae4f607dceb99c0762277e8ea9ddbde
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81319832"
---
# <a name="cmfcwindowsmanagerdialog-class"></a>Classe CMFCWindowsManagerDialog

O `CMFCWindowsManagerDialog` objeto permite que um usuário gerencie janelas de crianças MDI em um aplicativo MDI.

## <a name="syntax"></a>Sintaxe

```
class CMFCWindowsManagerDialog : public CDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCWindowsManagerDiálogo::CMFCWindowsManagerDiálogo](#cmfcwindowsmanagerdialog)|Constrói um objeto `CMFCWindowsManagerDialog`.|

## <a name="remarks"></a>Comentários

O `CMFCWindowsManagerDialog` contém uma lista de janelas de crianças MDI que estão atualmente abertas no aplicativo. O usuário pode controlar manualmente o estado das janelas de crianças MDI usando esta caixa de diálogo.

`CMFCWindowsManagerDialog`está incorporado dentro da [classe CMDIFrameWndEx](../../mfc/reference/cmdiframewndex-class.md). Não `CMFCWindowsManagerDialog` é uma classe que você deve criar manualmente. Em vez disso, chame a função [CMDIFrameWndEx::ShowWindowsDialog](../../mfc/reference/cmdiframewndex-class.md#showwindowsdialog), e criará e exibirá um `CMFCWindowsManagerDialog` objeto.

## <a name="example"></a>Exemplo

O exemplo a seguir `CMFCWindowsManagerDialog` demonstra como `CMDIFrameWndEx::ShowWindowsDialog`construir um objeto chamando . Este trecho de código faz parte da [amostra visual studio demo](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_VisualStudioDemo#18](../../mfc/codesnippet/cpp/cmfcwindowsmanagerdialog-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cdialog](../../mfc/reference/cdialog-class.md)

[Cmfcwindowsmanagerdialog](../../mfc/reference/cmfcwindowsmanagerdialog-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxWindowsManagerDialog.h

## <a name="cmfcwindowsmanagerdialogcmfcwindowsmanagerdialog"></a><a name="cmfcwindowsmanagerdialog"></a>CMFCWindowsManagerDiálogo::CMFCWindowsManagerDiálogo

Constrói um objeto [CMFCWindowsManagerDialog.](../../mfc/reference/cmfcwindowsmanagerdialog-class.md)

```
CMFCWindowsManagerDialog(
    CMDIFrameWndEx* pMDIFrame,
    BOOL bHelpButton = FALSE);
```

### <a name="parameters"></a>Parâmetros

*pMDIFrame*<br/>
[em] Um ponteiro para a janela dos pais ou dono.

*bHelpButton*<br/>
[em] Um parâmetro booleano que especifica se a estrutura exibe um botão **De ajuda.**

### <a name="remarks"></a>Comentários

Para obter mais informações sobre os gestores visuais, consulte [Gerenciador de Visualização](../../mfc/visualization-manager.md).

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMDIFrameWndEx](../../mfc/reference/cmdiframewndex-class.md)
