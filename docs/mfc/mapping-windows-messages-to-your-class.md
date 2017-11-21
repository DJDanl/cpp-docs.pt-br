---
title: Mapeando mensagens do Windows para a classe | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- MFC dialog boxes [MFC], Windows messages
- message maps [MFC], in dialog class
- Windows messages [MFC], mapping in dialog classes
- messages to dialog class [MFC]
- mappings [MFC], messages to dialog class [MFC]
- message maps [MFC], mapping Windows messages to classes
- messages to dialog class [MFC], mapping
ms.assetid: a4c6fd1f-1d33-47c9-baa0-001755746d6d
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 704bcbb81939ecb721b5b119f8c02a6409c2b82a
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="mapping-windows-messages-to-your-class"></a>Mapeando mensagens do Windows para a classe
Se você precisar de sua caixa de diálogo para lidar com mensagens do Windows, substitua as funções de manipulador adequado. Para fazer isso, use a janela Propriedades para [mapear as mensagens](../mfc/reference/mapping-messages-to-functions.md) para a classe de caixa de diálogo. Isso grava uma entrada de mapa de mensagem para cada mensagem e adiciona as funções de membro de manipulador de mensagens para a classe. Use o editor de código fonte do Visual C++ para escrever código em manipuladores de mensagens.  
  
 Você também pode substituir funções membro de [CDialog](../mfc/reference/cdialog-class.md) e suas classes base, especialmente [CWnd](../mfc/reference/cwnd-class.md).  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Mapeamento e a manipulação de mensagens](../mfc/message-handling-and-mapping.md)  
  
-   [Funções de membro normalmente substituídas](../mfc/commonly-overridden-member-functions.md)  
  
-   [Funções de membro normalmente adicionadas](../mfc/commonly-added-member-functions.md)  
  
## <a name="see-also"></a>Consulte também  
 [Caixas de diálogo](../mfc/dialog-boxes.md)   
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)

