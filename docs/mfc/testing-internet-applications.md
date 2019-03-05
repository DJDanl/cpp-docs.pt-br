---
title: Testando aplicativos da Internet
ms.date: 11/04/2016
helpviewer_keywords:
- Web applications [MFC], testing
- debugging Web applications [MFC], testing applications
- testing [MFC], Internet applications
- debugging [MFC], Web applications
- Internet debugging and testing
ms.assetid: ac4c74e3-d4ad-4e19-8f6c-e270de067f01
ms.openlocfilehash: e582fd006a49e672fb21c86b054b8d35f489698f
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57290933"
---
# <a name="testing-internet-applications"></a>Testando aplicativos da Internet

Há alguns desafios exclusivos de testes na Internet, especialmente para aplicativos em execução em um servidor Web. O teste inicial provavelmente será feito usando um cliente de usuário único conectado a um servidor de teste. Isso será útil para depurar seu código.

Você também desejará testar em condições reais: com vários clientes conectados por conexões de alta velocidade, bem como linhas seriais de baixa velocidade, incluindo conexões de modem. Pode ser difícil simular condições reais, mas certamente vale a pena gastar possíveis cenários de tempo de design e executá-los. Se possível, você também desejará usar ferramentas para a capacidade de fazer e testes de estresse. Determinadas classes de erros, como erros de tempo, são difíceis de encontrar e reproduzir.

Um dos desafios da programação da Internet é sua visibilidade. Vários acessos ao seu site podem prejudicar seu servidor. Você deseja que o servidor para degradar normalmente. Você deseja impedir que qualquer coisa que poderia ser destrutivos para o computador de um usuário se o aplicativo falhar (por exemplo, corrupção de dados durante a gravação no registro ou durante a gravação de cookies no cliente).

## <a name="see-also"></a>Consulte também

[Tarefas de programação da Internet no MFC](../mfc/mfc-internet-programming-tasks.md)<br/>
[Noções básicas de programação da Internet no MFC](../mfc/mfc-internet-programming-basics.md)
