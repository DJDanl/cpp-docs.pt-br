---
title: Definindo o modo de um objeto CStatusBarCtrl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- CStatusBarCtrl
dev_langs:
- C++
helpviewer_keywords:
- simple mode and status bar controls
- IsSimple method, using
- SetSimple method [MFC]
- status bar controls [MFC], simple and nonsimple modes
- non-simple mode and status bar controls
- CStatusBarCtrl class [MFC], simple and nonsimple modes
ms.assetid: ca6076e5-1501-4e33-8d35-9308941e46c0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7d875f2b93309e96bc3d612a8adc55b5af387026
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="setting-the-mode-of-a-cstatusbarctrl-object"></a>Definindo o modo de um objeto CStatusBarCtrl
Há dois modos para um `CStatusBarCtrl` objeto: simples e. Na maioria dos casos, o controle de barra de status terá uma ou mais partes, juntamente com o texto e talvez um ou mais ícones. Isso é chamado de modo simples. Para obter mais informações sobre esse modo, consulte [inicializando as partes de um objeto CStatusBarCtrl](../mfc/initializing-the-parts-of-a-cstatusbarctrl-object.md).  
  
 No entanto, há casos em que você só precisa exibir uma única linha de texto. Nesse caso, o modo simple é suficiente para suas necessidades. Para alterar o modo do `CStatusBarCtrl` de objeto simples, fazer uma chamada para o [SetSimple](../mfc/reference/cstatusbarctrl-class.md#setsimple) função de membro. Depois que o controle de barra de status está no modo simple, definir o texto chamando o **SetText** função de membro, passando 255 como o valor para o **nPane** parâmetro.  
  
 Você pode usar o [IsSimple](../mfc/reference/cstatusbarctrl-class.md#issimple) função para determinar qual modo o `CStatusBarCtrl` objeto está em.  
  
> [!NOTE]
>  Se o objeto de barra de status está sendo alterado de não simples para simples, ou vice-versa, a janela é redesenhada imediatamente e, se aplicável, qualquer partes definidas são restaurados automaticamente.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CStatusBarCtrl](../mfc/using-cstatusbarctrl.md)   
 [Controles](../mfc/controls-mfc.md)

