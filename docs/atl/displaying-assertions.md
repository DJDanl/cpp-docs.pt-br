---
title: "Exibindo asserções | Microsoft Docs"
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
- debugging [ATL], displaying assertions
- assertions, displaying
- debugging assertions
- assertions, debugging
ms.assetid: fa353fe8-4656-4384-a5d2-8866bc977f06
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: bff1ab29841ff2dd9973d538bb763d1fc1126a8f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="displaying-assertions"></a>Exibindo asserções
Se o cliente conectado ao seu serviço parece parar de responder, o serviço pode ter confirmado e exibida uma caixa de mensagem que não é possível ver. Você pode confirmar isso usando o depurador do Visual C++ para depurar seu código (consulte [usando o Gerenciador de tarefas](../atl/using-task-manager.md) anteriormente nesta seção).  
  
 Se você determinar que o serviço esteja exibindo uma caixa de mensagem que não é possível ver, você talvez queira definir o **permitir que o serviço interaja com a área de trabalho** opção antes de usar o serviço novamente. Essa opção é um parâmetro de inicialização que permite que todas as caixas de mensagem exibidas pelo serviço para aparecer na área de trabalho. Para definir essa opção, abra o aplicativo de painel de controle de serviços, selecione o serviço, clique em **inicialização**e, em seguida, selecione o **permitir que o serviço interaja com a área de trabalho** opção.  
  
## <a name="see-also"></a>Consulte também  
 [Dicas de depuração](../atl/debugging-tips.md)

