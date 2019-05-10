---
title: Exibindo asserções
ms.date: 05/05/2019
helpviewer_keywords:
- debugging [ATL], displaying assertions
- assertions, displaying
- debugging assertions
- assertions, debugging
ms.assetid: fa353fe8-4656-4384-a5d2-8866bc977f06
ms.openlocfilehash: 962a33a7d5d922f7f1655e22b2c9d0acdcf8925c
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65221256"
---
# <a name="displaying-assertions"></a>Exibindo asserções

Se o cliente conectado ao seu serviço parece parar de responder, o serviço pode ter confirmado e exibida uma caixa de mensagem que não é possível ver. Você pode confirmar isso usando o depurador do Visual Studio para depurar seu código (consulte [usando o Gerenciador de tarefas](../atl/using-task-manager.md) anteriormente nesta seção).

Se você determinar que seu serviço está exibindo uma caixa de mensagem que não é possível ver, talvez você queira definir o **permitir que o serviço interaja com a área de trabalho** opção antes de usar o serviço novamente. Essa opção é um parâmetro de inicialização que permite que todas as caixas de mensagem exibidas pelo serviço apareça na área de trabalho. Para definir essa opção, abra o aplicativo de painel de controle de serviços, selecione o serviço, clique em **inicialização**e, em seguida, selecione o **permitem que o serviço interaja com a área de trabalho** opção.

## <a name="see-also"></a>Consulte também

[Dicas de depuração](../atl/debugging-tips.md)
