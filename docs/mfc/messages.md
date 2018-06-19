---
title: Mensagens | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- messages, MFC
- messages [MFC]
ms.assetid: b1476310-a135-42ca-817c-444fb3675491
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: abd49410f9982788e9403f0cb83ca8656473417d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33344098"
---
# <a name="messages"></a>Mensagens
O loop de mensagem no **executar** função de membro de classe `CWinApp` recupera as mensagens geradas por vários eventos em fila. Por exemplo, quando o usuário clica com o mouse, o Windows envia várias mensagens de mouse relacionados, como `WM_LBUTTONDOWN` quando o botão esquerdo do mouse é pressionado e `WM_LBUTTONUP` quando o botão esquerdo do mouse é liberado. A implementação da estrutura de loop de mensagem do aplicativo envia a mensagem para a janela apropriada.  
  
 As categorias importantes de mensagens são descritas na [categorias de mensagem](../mfc/message-categories.md).  
  
## <a name="see-also"></a>Consulte também  
 [Mensagens e comandos no Framework](../mfc/messages-and-commands-in-the-framework.md)

