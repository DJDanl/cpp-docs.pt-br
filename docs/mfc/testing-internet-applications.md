---
title: Testando aplicativos da Internet | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- Web applications [MFC], testing
- debugging Web applications [MFC], testing applications
- testing [MFC], Internet applications
- debugging [MFC], Web applications
- Internet debugging and testing
ms.assetid: ac4c74e3-d4ad-4e19-8f6c-e270de067f01
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 0cc214eb98b8aa9e927fd471ba313e4cade426a2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="testing-internet-applications"></a>Testando aplicativos da Internet
Há alguns desafios de teste específicos na Internet, especialmente para aplicativos em execução em um servidor Web. O teste inicial provavelmente será feito usando um cliente de usuário único conectado a um servidor de teste. Isso será útil para depurar seu código.  
  
 Você também deseja testar sob condições reais: com vários clientes conectados por conexões de alta velocidade, bem como linhas seriais de baixa velocidade, incluindo as conexões de modem. Pode ser difícil simular condições reais, mas certamente vale a pena de gastos possíveis cenários de tempo de design e executá-los. Se possível, você também deve usar ferramentas de capacidade e o teste de estresse. Determinadas classes de erros, como erros de tempo, são difíceis de localizar e reproduzir.  
  
 Um dos desafios de programação da Internet é sua visibilidade. Muitos acessa seu site pode prejudicar seu servidor. Você deseja que seu servidor degradar de forma suave. Você deseja impedir que qualquer coisa que pode ser destrutiva ao computador de um usuário se o aplicativo falhar (por exemplo, a corrupção de dados ao gravar o registro ou durante a gravação de cookies no cliente).  
  
## <a name="see-also"></a>Consulte também  
 [Tarefas de programação da Internet MFC](../mfc/mfc-internet-programming-tasks.md)   
 [Noções básicas de programação da Internet no MFC](../mfc/mfc-internet-programming-basics.md)

