---
title: Executar função membro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- WinMain method [MFC]
ms.assetid: 24ab7597-2354-495b-9a20-2c8ccc7385b3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: be1d7d90b4c13a23e2e3456e7371abbae61be4e9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33379890"
---
# <a name="run-member-function"></a>Executar função membro
Um aplicativo framework passa a maior parte de seu tempo com o [executar](../mfc/reference/cwinapp-class.md#run) função de membro de classe [CWinApp](../mfc/reference/cwinapp-class.md). Após a inicialização, `WinMain` chamadas **executar** para processar o loop de mensagens.  
  
 **Executar** ciclos através de um loop de mensagem, verificando a fila de mensagens para as mensagens disponíveis. Se uma mensagem estiver disponível, **executar** distribui-o para a ação. Se nenhuma mensagem estiver disponível, que geralmente é verdadeiro, **executar** chamadas `OnIdle` fazer qualquer processamento de tempo ocioso que você ou o framework talvez tenha feito. Se não houver nenhuma mensagem e nenhum processamento ocioso, o aplicativo aguarda até que algo ocorra. Quando o aplicativo termina, **executar** chamadas `ExitInstance`. A figura no [função de membro OnIdle](../mfc/onidle-member-function.md) mostra a sequência de ações no loop de mensagem.  
  
 Distribuição de mensagem depende do tipo de mensagem. Para obter mais informações, consulte [mensagens e comandos no Framework](../mfc/messages-and-commands-in-the-framework.md).  
  
## <a name="see-also"></a>Consulte também  
 [CWinApp: a classe do aplicativo](../mfc/cwinapp-the-application-class.md)
