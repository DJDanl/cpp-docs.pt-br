---
title: Estrutura de CMFCTabToolTipInfo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCTabToolTipInfo
dev_langs:
- C++
helpviewer_keywords:
- CMFCTabToolTipInfo struct
ms.assetid: 9c3b3fb9-1497-4d59-932b-0da9348dd5e2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fb2d1a139a5bc61d665a28f21ab10979802045b3
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33373723"
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
|[CMFCTabToolTipInfo::m_pTabWnd](#m_ptabwnd)|Um ponteiro para o controle de tabulação.|  
|[CMFCTabToolTipInfo::m_strText](#m_strtext)|O texto de dica de ferramenta.|  
  
## <a name="remarks"></a>Comentários  
 Um ponteiro para um `CMFCTabToolTipInfo` estrutura é passada como um parâmetro de `AFX_WM_ON_GET_TAB_TOOLTIP` mensagem. Essa mensagem é gerada quando guias MDI são habilitados e o usuário passa sobre um controle de guia.  
  
## <a name="example"></a>Exemplo  
 A exemplo a seguir mostra como `CMFCTabToolTipInfo` é usado no [MDITabsDemo exemplo: aplicativo do MFC com guias MDI](../../visual-cpp-samples.md).  
  
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
 Índice da guia que passa através do qual o usuário.  
  
### <a name="example"></a>Exemplo  
 A exemplo a seguir mostra como `m_nTabIndex` é usado no [MDITabsDemo exemplo: aplicativo do MFC com guias MDI](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_MDITabsDemo#2](../../mfc/reference/codesnippet/cpp/cmfctabtooltipinfo-structure_1.cpp)]  
  
##  <a name="m_ptabwnd"></a>  CMFCTabToolTipInfo::m_pTabWnd  
 Um ponteiro para o controle de tabulação.  
  
```  
CMFCBaseTabCtrl* m_pTabWnd;  
```  
  
### <a name="example"></a>Exemplo  
 A exemplo a seguir mostra como `m_pTabWnd` é usado no [MDITabsDemo exemplo: aplicativo do MFC com guias MDI](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_MDITabsDemo#2](../../mfc/reference/codesnippet/cpp/cmfctabtooltipinfo-structure_1.cpp)]  
  
##  <a name="m_strtext"></a>  CMFCTabToolTipInfo::m_strText  
 O texto de dica de ferramenta.  
  
```  
CString m_strText;  
```  
  
### <a name="remarks"></a>Comentários  
 Se a cadeia de caracteres estiver vazia, a dica de ferramenta não é exibida.  
  
### <a name="example"></a>Exemplo  
 A exemplo a seguir mostra como `m_strText` é usado no [MDITabsDemo exemplo: aplicativo do MFC com guias MDI](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_MDITabsDemo#2](../../mfc/reference/codesnippet/cpp/cmfctabtooltipinfo-structure_1.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)
