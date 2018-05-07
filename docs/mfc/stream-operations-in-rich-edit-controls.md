---
title: Realizar operações em controles de edição avançada | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CRichEditCtrl class [MFC], stream operations
- CRichEditCtrl class [MFC], stream storage
- rich edit controls [MFC], stream operations
- storage, stream in CRichEditCtrl
- stream operations in CRichEditCtrl
- stream storage and CRichEditCtrl
ms.assetid: 110b4684-1e76-4ca6-9ef0-5bc8b2d93c78
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 66afb05031b302877dfd34f64e6076f882a256d4
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="stream-operations-in-rich-edit-controls"></a>Operações de fluxo em controles de edição avançada
Você pode usar fluxos para transferir dados para dentro ou fora de um controle de edição avançada ([CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)). Um fluxo é definido por um [EDITSTREAM](http://msdn.microsoft.com/library/windows/desktop/bb787891) estrutura, que especifica um buffer e uma função de retorno de chamada definido pelo aplicativo.  
  
 Para ler dados em um conjunto avançado de controle de edição (ou seja, transmitir os dados), use o [StreamIn](../mfc/reference/cricheditctrl-class.md#streamin) função de membro. O controle repetidamente chama a função de retorno de chamada definido pelo aplicativo, que transfere uma parte dos dados no buffer de cada vez.  
  
 Para salvar o conteúdo de um conjunto avançado do controle de edição (ou seja, transmitir os saída de dados), você pode usar o [StreamOut](../mfc/reference/cricheditctrl-class.md#streamout) função de membro. O controle repetidamente grava no buffer e, em seguida, chama a função de retorno de chamada definido pelo aplicativo. Para cada chamada, a função de retorno de chamada salva o conteúdo do buffer.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)   
 [Controles](../mfc/controls-mfc.md)

