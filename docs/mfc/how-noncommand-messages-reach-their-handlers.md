---
title: "Como mensagens sem comando alcançam os identificadores | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- messages [MFC], routing
- noncommand messages
- Windows messages [MFC], routing
- message handling [MFC], noncommand messages
ms.assetid: e7df8aef-9fae-41f4-9c11-881d8465f602
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 33d0d65c9916cfc571ecfd623138938c0c883ba5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-noncommand-messages-reach-their-handlers"></a>Como mensagens sem comando alcançam os identificadores
Diferentemente dos comandos, mensagens padrão do Windows não sejam roteadas por meio de uma cadeia de comando destinos, mas geralmente são tratadas pela janela ao qual o Windows envia a mensagem. A janela pode ser uma janela do quadro principal, uma janela de filho MDI, um controle padrão, uma caixa de diálogo, uma exibição ou outro tipo de janela filho.  
  
 Em tempo de execução, cada janela de Windows é anexada a um objeto de janela (derivado direta ou indiretamente de `CWnd`) que tem suas próprias funções de mapa e o manipulador de mensagem associado. A estrutura usa o mapa de mensagem — para um comando — para mapear as mensagens de entrada para manipuladores.  
  
## <a name="see-also"></a>Consulte também  
 [Como o Framework chama um manipulador](../mfc/how-the-framework-calls-a-handler.md)

