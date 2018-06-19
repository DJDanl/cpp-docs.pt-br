---
title: Testando aplicativos da Internet | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Web applications [MFC], testing
- debugging Web applications [MFC], testing applications
- testing [MFC], Internet applications
- debugging [MFC], Web applications
- Internet debugging and testing
ms.assetid: ac4c74e3-d4ad-4e19-8f6c-e270de067f01
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 61ffc5b11783806555b210b8561cbe6cdd2878ef
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33380062"
---
# <a name="testing-internet-applications"></a>Testando aplicativos da Internet
Há alguns desafios de teste específicos na Internet, especialmente para aplicativos em execução em um servidor Web. O teste inicial provavelmente será feito usando um cliente de usuário único conectado a um servidor de teste. Isso será útil para depurar seu código.  
  
 Você também deseja testar sob condições reais: com vários clientes conectados por conexões de alta velocidade, bem como linhas seriais de baixa velocidade, incluindo as conexões de modem. Pode ser difícil simular condições reais, mas certamente vale a pena de gastos possíveis cenários de tempo de design e executá-los. Se possível, você também deve usar ferramentas de capacidade e o teste de estresse. Determinadas classes de erros, como erros de tempo, são difíceis de localizar e reproduzir.  
  
 Um dos desafios de programação da Internet é sua visibilidade. Muitos acessa seu site pode prejudicar seu servidor. Você deseja que seu servidor degradar de forma suave. Você deseja impedir que qualquer coisa que pode ser destrutiva ao computador de um usuário se o aplicativo falhar (por exemplo, a corrupção de dados ao gravar o registro ou durante a gravação de cookies no cliente).  
  
## <a name="see-also"></a>Consulte também  
 [Tarefas de programação da Internet MFC](../mfc/mfc-internet-programming-tasks.md)   
 [Noções básicas de programação da Internet no MFC](../mfc/mfc-internet-programming-basics.md)

