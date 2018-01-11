---
title: "Componentes da caixa de diálogo no Framework | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- MFC dialog boxes [MFC], creating
- dialog classes [MFC], dialog box components
- MFC dialog boxes [MFC], about MFC dialog boxes
- dialog templates [MFC], MFC framework
- MFC dialog boxes [MFC], dialog resource
ms.assetid: 592db160-0a8a-49be-ac72-ead278aca53f
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 840e66def6a908b26b5021537eddee68c50a9628
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="dialog-box-components-in-the-framework"></a>Componentes da caixa de diálogo no Framework
Na estrutura MFC, uma caixa de diálogo tem dois componentes:  
  
-   Um recurso de modelo de caixa de diálogo que especifica os controles da caixa de diálogo e seu posicionamento.  
  
     O recurso de caixa de diálogo armazena um modelo de caixa de diálogo da qual o Windows cria a janela da caixa de diálogo e exibe-o. O modelo especifica características da caixa de diálogo, incluindo seu tamanho, local, estilo e os tipos e posições de controles da caixa de diálogo. Normalmente, você usará um modelo de caixa de diálogo armazenado como um recurso, mas você também pode criar seu próprio modelo na memória.  
  
-   Uma classe de caixa de diálogo, derivada de [CDialog](../mfc/reference/cdialog-class.md), para fornecer uma interface programática para o gerenciamento de caixa de diálogo.  
  
     Uma caixa de diálogo é uma janela e será anexada a uma janela do Windows quando visível. Quando a janela de diálogo é criada, o recurso de modelo de caixa de diálogo é usado como um modelo para a criação de controles de janela para a caixa de diálogo de filho.  
  
## <a name="see-also"></a>Consulte também  
 [Caixas de diálogo](../mfc/dialog-boxes.md)   
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)

