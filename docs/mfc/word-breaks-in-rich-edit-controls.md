---
title: "Quebras de palavra em controles de edição avançada | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- CRichEditCtrl class [MFC], word breaks in
- word breaks
- breaking words in CRichEditCtrl
- rich edit controls [MFC], word breaks in
ms.assetid: 641dcf9e-7b40-4dc0-85f7-575a8c142f73
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 12ae5d682515a6f266b7e41a2ff89148ea98c0b1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="word-breaks-in-rich-edit-controls"></a>Quebras de palavra em controles de edição avançada
Controle de edição de um conjunto avançado ([CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)) chama uma função que chamou um procedimento de quebra"word" para localizar quebras entre as palavras e determinar onde ele pode quebrar a linha. O controle usa essas informações ao executar operações de quebra automática de linha e ao processar as combinações de teclas CTRL + esquerda e CTRL + seta para direita. Um aplicativo pode enviar mensagens para um controle de edição para substituir o procedimento de quebra de palavras padrão, para recuperar informações de quebra de palavras e para determinar o que um determinado caractere da linha cai.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)   
 [Controles](../mfc/controls-mfc.md)

