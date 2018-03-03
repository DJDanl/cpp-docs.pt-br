---
title: Mapeando mensagens | Microsoft Docs
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
- message maps [MFC], about message maps
- mappings [MFC], commands
- commands [MFC], mapping
- command mapping [MFC]
- message handling [MFC], connecting to handler functions
- commands [MFC], connecting to handler functions
- mappings [MFC], messages
- messages [MFC], mapping
ms.assetid: 996f0652-0698-4b8c-b893-cdaa836d9d0f
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c415b12b22c19a5e1f2d19fd9c808a98485eb7ae
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="mapping-messages"></a>Mapeando mensagens
Cada classe de estrutura que pode receber mensagens ou comandos tem seu próprio "mapa de mensagem". A estrutura usa mapas de mensagem para conectar-se as mensagens e comandos para suas funções de manipulador. Qualquer classe derivada da classe `CCmdTarget` pode ter um mapa de mensagem. Outros artigos explicam os mapas de mensagem em detalhes e descrevem como usá-los.  
  
 Apesar do nome "mapa de mensagem," mensagem mapas tratar duas mensagens e comandos — todas as três categorias de mensagens listadas na [categorias de mensagem](../mfc/message-categories.md).  
  
## <a name="see-also"></a>Consulte também  
 [Mensagens e comandos no Framework](../mfc/messages-and-commands-in-the-framework.md)

