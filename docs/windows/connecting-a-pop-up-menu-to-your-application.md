---
title: Conectando um Menu pop-up ao aplicativo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- pop-up menus, connecting to applications
- context menus, connecting to applications
- menus, pop-up
- shortcut menus, connecting to applications
ms.assetid: 295cbf0e-6416-478e-bc3d-472fb98e0e52
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5bfe5c4dba3dc8e86eb9a47a6e163af94872b933
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39641256"
---
# <a name="connecting-a-pop-up-menu-to-your-application"></a>Conectando um menu pop-up ao aplicativo
### <a name="to-connect-a-pop-up-menu-to-your-application"></a>Para se conectar a um menu pop-up para seu aplicativo  
  
1.  Adicione um manipulador de mensagens para WM_CONTEXTMENU (por exemplo). Para obter mais informações, consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md).  
  
2.  Adicione o seguinte código para o manipulador de mensagens:  
  
    ```cpp  
    CMenu menu;  
    VERIFY(menu.LoadMenu(IDR_MENU1));  
    CMenu* pPopup = menu.GetSubMenu(0);  
    ASSERT(pPopup != NULL);  
    pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, AfxGetMainWnd());  
    ```  
  
    > [!NOTE]
    >  O [CPoint](../atl-mfc-shared/reference/cpoint-class.md) passados pela mensagem manipulador está em coordenadas da tela.  
  
## <a name="requirements"></a>Requisitos  
 MFC  
  
## <a name="see-also"></a>Consulte também  
 [Criando Menus pop-up](../windows/creating-pop-up-menus.md)   
 [Editor de Menu](../windows/menu-editor.md)   