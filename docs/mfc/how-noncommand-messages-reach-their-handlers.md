---
title: Como mensagens sem comando alcançam os identificadores | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- messages [MFC], routing
- noncommand messages
- Windows messages [MFC], routing
- message handling [MFC], noncommand messages
ms.assetid: e7df8aef-9fae-41f4-9c11-881d8465f602
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3999c74bf7a612acb998e7a044c12948d7679d9b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="how-noncommand-messages-reach-their-handlers"></a>Como mensagens sem comando alcançam os identificadores
Diferentemente dos comandos, mensagens padrão do Windows não sejam roteadas por meio de uma cadeia de comando destinos, mas geralmente são tratadas pela janela ao qual o Windows envia a mensagem. A janela pode ser uma janela do quadro principal, uma janela de filho MDI, um controle padrão, uma caixa de diálogo, uma exibição ou outro tipo de janela filho.  
  
 Em tempo de execução, cada janela de Windows é anexada a um objeto de janela (derivado direta ou indiretamente de `CWnd`) que tem suas próprias funções de mapa e o manipulador de mensagem associado. A estrutura usa o mapa de mensagem — para um comando — para mapear as mensagens de entrada para manipuladores.  
  
## <a name="see-also"></a>Consulte também  
 [Como o Framework chama um manipulador](../mfc/how-the-framework-calls-a-handler.md)

