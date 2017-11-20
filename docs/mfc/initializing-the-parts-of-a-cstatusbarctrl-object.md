---
title: Inicializando as partes de um objeto CStatusBarCtrl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: CStatusBarCtrl
dev_langs: C++
helpviewer_keywords:
- CStatusBarCtrl class [MFC], simple mode
- status bars [MFC], declaring parts of
- simple status bars [MFC]
- status bars [MFC], icons
- status bars [MFC], simple mode
- icons, using in status bars
- CStatusBarCtrl class [MFC], declaring parts of
ms.assetid: 60e8f285-d2d8-424a-a6ea-2fc548370303
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 4c0171255e470e1ef4b675c9f9c4cd34c90119d8
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="initializing-the-parts-of-a-cstatusbarctrl-object"></a>Inicializando as partes de um objeto CStatusBarCtrl
Por padrão, uma barra de status exibe informações de status usando painéis separados. Esses painéis (também conhecidos como partes) podem conter uma cadeia de caracteres de texto, um ícone ou ambos.  
  
 Use [SetParts](../mfc/reference/cstatusbarctrl-class.md#setparts) para definir quantos partes e o comprimento, terá a barra de status. Depois de ter criado as partes da barra de status, fazer chamadas para [SetText](../mfc/reference/cstatusbarctrl-class.md#settext) e [SetIcon](../mfc/reference/cstatusbarctrl-class.md#seticon) para definir o texto ou ícone de uma parte específica da barra de status. Quando a parte foi definida com êxito, o controle é redesenhado automaticamente.  
  
 O exemplo a seguir inicializa um existente `CStatusBarCtrl` objeto (`m_StatusBarCtrl`) com quatro painéis e, em seguida, define um ícone (IDI_ICON1) e um texto na segunda parte.  
  
 [!code-cpp[NVC_MFCControlLadenDialog#31](../mfc/codesnippet/cpp/initializing-the-parts-of-a-cstatusbarctrl-object_1.cpp)]  
  
 Para obter mais informações sobre como definir o modo de um `CStatusBarCtrl` objeto simple, consulte [definindo o modo de um objeto CStatusBarCtrl](../mfc/setting-the-mode-of-a-cstatusbarctrl-object.md).  
  
## <a name="see-also"></a>Consulte também  
 [Usando CStatusBarCtrl](../mfc/using-cstatusbarctrl.md)   
 [Controles](../mfc/controls-mfc.md)

