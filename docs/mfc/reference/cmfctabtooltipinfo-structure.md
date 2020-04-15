---
title: Estrutura CMFCTabToolTipInfo
ms.date: 11/04/2016
f1_keywords:
- CMFCTabToolTipInfo
helpviewer_keywords:
- CMFCTabToolTipInfo struct
ms.assetid: 9c3b3fb9-1497-4d59-932b-0da9348dd5e2
ms.openlocfilehash: a507d1e69b3524074e50fde0e87fc5ebb6e5ca03
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367335"
---
# <a name="cmfctabtooltipinfo-structure"></a>Estrutura CMFCTabToolTipInfo

Esta estrutura fornece informações sobre a guia MDI que o usuário está pairando sobre.

## <a name="syntax"></a>Sintaxe

```
struct CMFCTabToolTipInfo
```

## <a name="members"></a>Membros

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|----------|-----------------|
|[CMFCTabToolTipInfo::m_nTabIndex](#m_ntabindex)|Especifica o índice do controle da guia.|
|[CMFCTabtoolTipInfo::m_pTabWnd](#m_ptabwnd)|Um ponteiro para o controle da guia.|
|[CMFCTabToolTipInfo::m_strText](#m_strtext)|O texto de dica de ferramenta.|

## <a name="remarks"></a>Comentários

Um ponteiro `CMFCTabToolTipInfo` para uma estrutura é passado como um parâmetro da mensagem AFX_WM_ON_GET_TAB_TOOLTIP. Essa mensagem é gerada quando as guias MDI estão ativadas e o usuário paira sobre um controle de guias.

## <a name="example"></a>Exemplo

O exemplo a `CMFCTabToolTipInfo` seguir mostra como é usado na [amostra MDITabsDemo: MFC Tabed MDI Application](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_MDITabsDemo#2](../../mfc/reference/codesnippet/cpp/cmfctabtooltipinfo-structure_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CMFCTabToolTipInfo](../../mfc/reference/cmfctabtooltipinfo-structure.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxbasetabctrl.h

## <a name="cmfctabtooltipinfom_ntabindex"></a><a name="m_ntabindex"></a>CMFCTabToolTipInfo::m_nTabIndex

Especifica o índice do controle da guia.

```
int m_nTabIndex;
```

### <a name="remarks"></a>Comentários

Índice da guia sobre a qual o usuário está pairando.

### <a name="example"></a>Exemplo

O exemplo a `m_nTabIndex` seguir mostra como é usado na [amostra MDITabsDemo: MFC Tabed MDI Application](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_MDITabsDemo#2](../../mfc/reference/codesnippet/cpp/cmfctabtooltipinfo-structure_1.cpp)]

## <a name="cmfctabtooltipinfom_ptabwnd"></a><a name="m_ptabwnd"></a>CMFCTabtoolTipInfo::m_pTabWnd

Um ponteiro para o controle da guia.

```
CMFCBaseTabCtrl* m_pTabWnd;
```

### <a name="example"></a>Exemplo

O exemplo a `m_pTabWnd` seguir mostra como é usado na [amostra MDITabsDemo: MFC Tabed MDI Application](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_MDITabsDemo#2](../../mfc/reference/codesnippet/cpp/cmfctabtooltipinfo-structure_1.cpp)]

## <a name="cmfctabtooltipinfom_strtext"></a><a name="m_strtext"></a>CMFCTabToolTipInfo::m_strText

O texto de dica de ferramenta.

```
CString m_strText;
```

### <a name="remarks"></a>Comentários

Se a seqüência estiver vazia, a dica de ferramenta não será exibida.

### <a name="example"></a>Exemplo

O exemplo a `m_strText` seguir mostra como é usado na [amostra MDITabsDemo: MFC Tabed MDI Application](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_MDITabsDemo#2](../../mfc/reference/codesnippet/cpp/cmfctabtooltipinfo-structure_1.cpp)]

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
