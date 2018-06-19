---
title: Quebras de palavra em controles de edição avançada | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CRichEditCtrl class [MFC], word breaks in
- word breaks
- breaking words in CRichEditCtrl
- rich edit controls [MFC], word breaks in
ms.assetid: 641dcf9e-7b40-4dc0-85f7-575a8c142f73
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 373a30ed4a327cff99cb3cfce873707314608b57
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33382954"
---
# <a name="word-breaks-in-rich-edit-controls"></a>Quebras de palavra em controles de edição avançada
Controle de edição de um conjunto avançado ([CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)) chama uma função que chamou um procedimento de quebra"word" para localizar quebras entre as palavras e determinar onde ele pode quebrar a linha. O controle usa essas informações ao executar operações de quebra automática de linha e ao processar as combinações de teclas CTRL + esquerda e CTRL + seta para direita. Um aplicativo pode enviar mensagens para um controle de edição para substituir o procedimento de quebra de palavras padrão, para recuperar informações de quebra de palavras e para determinar o que um determinado caractere da linha cai.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)   
 [Controles](../mfc/controls-mfc.md)

