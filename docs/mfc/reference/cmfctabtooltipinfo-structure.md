---
title: Estrutura de CMFCTabToolTipInfo | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCTabToolTipInfo
dev_langs:
- C++
helpviewer_keywords:
- CMFCTabToolTipInfo struct
ms.assetid: 9c3b3fb9-1497-4d59-932b-0da9348dd5e2
caps.latest.revision: 27
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: b9750cd9369313a3ed6ea9474d401cd0068a75fa
ms.lasthandoff: 02/25/2017

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
 Um ponteiro para um `CMFCTabToolTipInfo` estrutura é passada como um parâmetro de `AFX_WM_ON_GET_TAB_TOOLTIP` mensagem. Essa mensagem é gerada quando o guias MDI estiverem habilitados e o usuário passar o mouse sobre um controle de guia.  
  
## <a name="example"></a>Exemplo  
 A exemplo a seguir mostra como `CMFCTabToolTipInfo` é usado no [MDITabsDemo exemplo: aplicativo do MFC com guias MDI](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_MDITabsDemo n º&2;](../../mfc/reference/codesnippet/cpp/cmfctabtooltipinfo-structure_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CMFCTabToolTipInfo](../../mfc/reference/cmfctabtooltipinfo-structure.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxbasetabctrl.h  
  
##  <a name="a-namemntabindexa--cmfctabtooltipinfomntabindex"></a><a name="m_ntabindex"></a>CMFCTabToolTipInfo::m_nTabIndex  
 Especifica o índice do controle guia.  
  
```  
int m_nTabIndex;  
```  
  
### <a name="remarks"></a>Comentários  
 Índice da guia sobre a qual o usuário está passando.  
  
### <a name="example"></a>Exemplo  
 A exemplo a seguir mostra como `m_nTabIndex` é usado no [MDITabsDemo exemplo: aplicativo do MFC com guias MDI](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_MDITabsDemo n º&2;](../../mfc/reference/codesnippet/cpp/cmfctabtooltipinfo-structure_1.cpp)]  
  
##  <a name="a-namemptabwnda--cmfctabtooltipinfomptabwnd"></a><a name="m_ptabwnd"></a>CMFCTabToolTipInfo::m_pTabWnd  
 Um ponteiro para o controle de guia.  
  
```  
CMFCBaseTabCtrl* m_pTabWnd;  
```  
  
### <a name="example"></a>Exemplo  
 A exemplo a seguir mostra como `m_pTabWnd` é usado no [MDITabsDemo exemplo: aplicativo do MFC com guias MDI](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_MDITabsDemo n º&2;](../../mfc/reference/codesnippet/cpp/cmfctabtooltipinfo-structure_1.cpp)]  
  
##  <a name="a-namemstrtexta--cmfctabtooltipinfomstrtext"></a><a name="m_strtext"></a>CMFCTabToolTipInfo::m_strText  
 O texto de dica de ferramenta.  
  
```  
CString m_strText;  
```  
  
### <a name="remarks"></a>Comentários  
 Se a cadeia de caracteres estiver vazia, a dica de ferramenta não será exibida.  
  
### <a name="example"></a>Exemplo  
 A exemplo a seguir mostra como `m_strText` é usado no [MDITabsDemo exemplo: aplicativo do MFC com guias MDI](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_MDITabsDemo n º&2;](../../mfc/reference/codesnippet/cpp/cmfctabtooltipinfo-structure_1.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)

