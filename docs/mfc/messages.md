---
title: Mensagens | Microsoft Docs
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
- messages, MFC
- messages [MFC]
ms.assetid: b1476310-a135-42ca-817c-444fb3675491
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d03eed129fd5a2a7c73f7c7948cb766813f63c34
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="messages"></a>Mensagens
O loop de mensagem no **executar** função de membro de classe `CWinApp` recupera as mensagens geradas por vários eventos em fila. Por exemplo, quando o usuário clica com o mouse, o Windows envia várias mensagens de mouse relacionados, como `WM_LBUTTONDOWN` quando o botão esquerdo do mouse é pressionado e `WM_LBUTTONUP` quando o botão esquerdo do mouse é liberado. A implementação da estrutura de loop de mensagem do aplicativo envia a mensagem para a janela apropriada.  
  
 As categorias importantes de mensagens são descritas na [categorias de mensagem](../mfc/message-categories.md).  
  
## <a name="see-also"></a>Consulte também  
 [Mensagens e comandos no Framework](../mfc/messages-and-commands-in-the-framework.md)

