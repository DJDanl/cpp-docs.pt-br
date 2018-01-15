---
title: Classe CMFCWindowsManagerDialog | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCWindowsManagerDialog
- AFXWINDOWSMANAGERDIALOG/CMFCWindowsManagerDialog
- AFXWINDOWSMANAGERDIALOG/CMFCWindowsManagerDialog::CMFCWindowsManagerDialog
dev_langs: C++
helpviewer_keywords: CMFCWindowsManagerDialog [MFC], CMFCWindowsManagerDialog
ms.assetid: 35b4b0db-33c4-4b22-94d8-5e3396341340
caps.latest.revision: "25"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1f20a93135a6f310b626cbe12f68f72c64e4ce8e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmfcwindowsmanagerdialog-class"></a>Classe CMFCWindowsManagerDialog
O `CMFCWindowsManagerDialog` objeto permite que um usuário gerencie janelas filho MDI um aplicativo de MDI.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCWindowsManagerDialog : public CDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCWindowsManagerDialog::CMFCWindowsManagerDialog](#cmfcwindowsmanagerdialog)|Constrói um objeto `CMFCWindowsManagerDialog`.|  
  
## <a name="remarks"></a>Comentários  
 O `CMFCWindowsManagerDialog` contém uma lista de janelas filho MDI que estão abertos no momento no aplicativo. O usuário pode controlar manualmente o estado de janelas filho MDI usando essa caixa de diálogo.  
  
 `CMFCWindowsManagerDialog`incorporado a [CMDIFrameWndEx classe](../../mfc/reference/cmdiframewndex-class.md). O `CMFCWindowsManagerDialog` não é uma classe que você deve criar manualmente. Em vez disso, chame a função [CMDIFrameWndEx::ShowWindowsDialog](../../mfc/reference/cmdiframewndex-class.md#showwindowsdialog), e irá criar e exibir um `CMFCWindowsManagerDialog` objeto.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como construir um `CMFCWindowsManagerDialog` objeto chamando `CMDIFrameWndEx::ShowWindowsDialog`. Este trecho de código é parte do [exemplo de demonstração do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo#18](../../mfc/codesnippet/cpp/cmfcwindowsmanagerdialog-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CMFCWindowsManagerDialog](../../mfc/reference/cmfcwindowsmanagerdialog-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxWindowsManagerDialog.h  
  
##  <a name="cmfcwindowsmanagerdialog"></a>CMFCWindowsManagerDialog::CMFCWindowsManagerDialog  
 Constrói um [CMFCWindowsManagerDialog](../../mfc/reference/cmfcwindowsmanagerdialog-class.md) objeto.  
  
```  
CMFCWindowsManagerDialog(
    CMDIFrameWndEx* pMDIFrame,  
    BOOL bHelpButton = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pMDIFrame`  
 Um ponteiro para a janela pai ou proprietário.  
  
 [in] `bHelpButton`  
 Um parâmetro booleano que especifica se a estrutura exibe um **ajuda** botão.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre gerenciadores de visual, consulte [Gerenciador de visualização](../../mfc/visualization-manager.md).  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMDIFrameWndEx](../../mfc/reference/cmdiframewndex-class.md)
