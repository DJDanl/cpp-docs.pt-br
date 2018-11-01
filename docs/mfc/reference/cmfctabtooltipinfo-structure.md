---
title: Estrutura CMFCTabToolTipInfo
ms.date: 11/04/2016
f1_keywords:
- CMFCTabToolTipInfo
helpviewer_keywords:
- CMFCTabToolTipInfo struct
ms.assetid: 9c3b3fb9-1497-4d59-932b-0da9348dd5e2
ms.openlocfilehash: b785754a7970573c42fcc1d0736541416f522c9a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50429113"
---
# <a name="cmfctabtooltipinfo-structure"></a>Estrutura CMFCTabToolTipInfo

Essa estrutura fornece informações sobre a guia MDI que o usuário está focalizando.

## <a name="syntax"></a>Sintaxe

```
struct CMFCTabToolTipInfo
```

## <a name="members"></a>Membros

### <a name="data-members"></a>Membros de Dados

|Nome|Descrição|
|----------|-----------------|
|[CMFCTabToolTipInfo::m_nTabIndex](#m_ntabindex)|Especifica o índice do controle guia.|
|[CMFCTabToolTipInfo::m_pTabWnd](#m_ptabwnd)|Um ponteiro para o controle de guia.|
|[CMFCTabToolTipInfo::m_strText](#m_strtext)|O texto de dica de ferramenta.|

## <a name="remarks"></a>Comentários

Um ponteiro para um `CMFCTabToolTipInfo` estrutura é passada como um parâmetro da mensagem AFX_WM_ON_GET_TAB_TOOLTIP. Essa mensagem é gerada quando guias MDI são habilitadas e o usuário passa o mouse sobre um controle guia.

## <a name="example"></a>Exemplo

A exemplo a seguir mostra como `CMFCTabToolTipInfo` é usado em de [MDITabsDemo exemplo: aplicativo do MFC com guias MDI](../../visual-cpp-samples.md).

[!code-cpp[NVC_MFC_MDITabsDemo#2](../../mfc/reference/codesnippet/cpp/cmfctabtooltipinfo-structure_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CMFCTabToolTipInfo](../../mfc/reference/cmfctabtooltipinfo-structure.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxbasetabctrl.h

##  <a name="m_ntabindex"></a>  CMFCTabToolTipInfo::m_nTabIndex

Especifica o índice do controle guia.

```
int m_nTabIndex;
```

### <a name="remarks"></a>Comentários

Índice da guia sobre o qual o usuário está passando.

### <a name="example"></a>Exemplo

A exemplo a seguir mostra como `m_nTabIndex` é usado em de [MDITabsDemo exemplo: aplicativo do MFC com guias MDI](../../visual-cpp-samples.md).

[!code-cpp[NVC_MFC_MDITabsDemo#2](../../mfc/reference/codesnippet/cpp/cmfctabtooltipinfo-structure_1.cpp)]

##  <a name="m_ptabwnd"></a>  CMFCTabToolTipInfo::m_pTabWnd

Um ponteiro para o controle de guia.

```
CMFCBaseTabCtrl* m_pTabWnd;
```

### <a name="example"></a>Exemplo

A exemplo a seguir mostra como `m_pTabWnd` é usado em de [MDITabsDemo exemplo: aplicativo do MFC com guias MDI](../../visual-cpp-samples.md).

[!code-cpp[NVC_MFC_MDITabsDemo#2](../../mfc/reference/codesnippet/cpp/cmfctabtooltipinfo-structure_1.cpp)]

##  <a name="m_strtext"></a>  CMFCTabToolTipInfo::m_strText

O texto de dica de ferramenta.

```
CString m_strText;
```

### <a name="remarks"></a>Comentários

Se a cadeia de caracteres estiver vazia, a dica de ferramenta não é exibida.

### <a name="example"></a>Exemplo

A exemplo a seguir mostra como `m_strText` é usado em de [MDITabsDemo exemplo: aplicativo do MFC com guias MDI](../../visual-cpp-samples.md).

[!code-cpp[NVC_MFC_MDITabsDemo#2](../../mfc/reference/codesnippet/cpp/cmfctabtooltipinfo-structure_1.cpp)]

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
