---
title: "Realizar operações em controles de edição avançada | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- CRichEditCtrl class [MFC], stream operations
- CRichEditCtrl class [MFC], stream storage
- rich edit controls [MFC], stream operations
- storage, stream in CRichEditCtrl
- stream operations in CRichEditCtrl
- stream storage and CRichEditCtrl
ms.assetid: 110b4684-1e76-4ca6-9ef0-5bc8b2d93c78
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 74dd05bfa1619b9acfe5695fdf0491d4d4b65a78
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="stream-operations-in-rich-edit-controls"></a>Operações de fluxo em controles de edição avançada
Você pode usar fluxos para transferir dados para dentro ou fora de um controle de edição avançada ([CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)). Um fluxo é definido por um [EDITSTREAM](http://msdn.microsoft.com/library/windows/desktop/bb787891) estrutura, que especifica um buffer e uma função de retorno de chamada definido pelo aplicativo.  
  
 Para ler dados em um conjunto avançado de controle de edição (ou seja, transmitir os dados), use o [StreamIn](../mfc/reference/cricheditctrl-class.md#streamin) função de membro. O controle repetidamente chama a função de retorno de chamada definido pelo aplicativo, que transfere uma parte dos dados no buffer de cada vez.  
  
 Para salvar o conteúdo de um conjunto avançado do controle de edição (ou seja, transmitir os saída de dados), você pode usar o [StreamOut](../mfc/reference/cricheditctrl-class.md#streamout) função de membro. O controle repetidamente grava no buffer e, em seguida, chama a função de retorno de chamada definido pelo aplicativo. Para cada chamada, a função de retorno de chamada salva o conteúdo do buffer.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)   
 [Controles](../mfc/controls-mfc.md)

