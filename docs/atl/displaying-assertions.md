---
title: Exibindo asserções | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- debugging [ATL], displaying assertions
- assertions, displaying
- debugging assertions
- assertions, debugging
ms.assetid: fa353fe8-4656-4384-a5d2-8866bc977f06
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8ff7b9b29808e310be2d5568add64a0294bc67e7
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43762376"
---
# <a name="displaying-assertions"></a>Exibindo asserções

Se o cliente conectado ao seu serviço parece parar de responder, o serviço pode ter confirmado e exibida uma caixa de mensagem que não é possível ver. Você pode confirmar isso usando o depurador do Visual C++ para depurar seu código (consulte [usando o Gerenciador de tarefas](../atl/using-task-manager.md) anteriormente nesta seção).

Se você determinar que seu serviço está exibindo uma caixa de mensagem que não é possível ver, talvez você queira definir o **permitir que o serviço interaja com a área de trabalho** opção antes de usar o serviço novamente. Essa opção é um parâmetro de inicialização que permite que todas as caixas de mensagem exibidas pelo serviço apareça na área de trabalho. Para definir essa opção, abra o aplicativo de painel de controle de serviços, selecione o serviço, clique em **inicialização**e, em seguida, selecione o **permitem que o serviço interaja com a área de trabalho** opção.

## <a name="see-also"></a>Consulte também

[Dicas de depuração](../atl/debugging-tips.md)

