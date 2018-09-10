---
title: Conectando um Menu pop-up ao aplicativo C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- pop-up menus [C++], connecting to applications
- context menus [C++], connecting to applications
- menus [C++], pop-up
- shortcut menus [C++], connecting to applications
ms.assetid: 295cbf0e-6416-478e-bc3d-472fb98e0e52
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e9a5123481999328e8d3e010f752a27ecef27557
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44313267"
---
# <a name="connecting-a-pop-up-menu-to-your-c-application"></a>Conectando um Menu pop-up ao aplicativo C++

### <a name="to-connect-a-pop-up-menu-to-your-application"></a>Para se conectar a um menu pop-up para seu aplicativo

1. Adicione um manipulador de mensagens para WM_CONTEXTMENU (por exemplo). Para obter mais informações, consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md).

2. Adicione o seguinte código para o manipulador de mensagens:

    ```cpp
    CMenu menu;
    VERIFY(menu.LoadMenu(IDR_MENU1));
    CMenu* pPopup = menu.GetSubMenu(0);
    ASSERT(pPopup != NULL);
    pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, AfxGetMainWnd());
    ```

   > [!NOTE]
   > O [CPoint](../atl-mfc-shared/reference/cpoint-class.md) passados pela mensagem manipulador está em coordenadas da tela.

## <a name="requirements"></a>Requisitos

MFC

## <a name="see-also"></a>Consulte também

[Criando menus pop-up](../windows/creating-pop-up-menus.md)  
[Editor de Menu](../windows/menu-editor.md)  