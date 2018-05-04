---
title: Tratamento de erro e notificação | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- error handling, and notification
ms.assetid: b621cf60-d869-451a-b05e-dc86d78addaa
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e2edec23da89766a45545566b0a689001d3ca75f
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="error-handling-and-notification"></a>Tratamento de erro e notificação
Para obter mais informações sobre o tratamento de erro e notificação, consulte [Noções básicas sobre a função auxiliar](understanding-the-helper-function.md).  
  
 Para obter mais informações sobre funções de gancho, consulte [estrutura e definições de constantes](../../build/reference/structure-and-constant-definitions.md).  
  
 Se seu programa usa DLLs carregadas com atraso, ele deve tratar erros robustez desde falhas que ocorrem durante a execução do programa resultará em exceções sem tratamento. Tratamento de falha é composto de duas partes:  
  
 Recuperação por meio de um gancho.  
 Se seu código precisa para recuperar ou fornecer uma rotina de e/ou biblioteca alternativa em caso de falha, um gancho pode ser fornecido para a função auxiliar que pode fornecer ou corrigir a situação. As necessidades de rotina de gancho para retornar um valor adequado, para que o processamento podem continuar (um HINSTANCE ou FARPROC) ou 0 para indicar que uma exceção deve ser gerada. Ele também pode gerar seu próprio exceção ou **longjmp** fora o gancho. Há ganchos de notificação e ganchos de falha.  
  
 Emissão de relatórios por meio de uma exceção.  
 Não se tudo o que é necessário para manipular o erro for cancelar o procedimento, é necessário nenhum gancho desde que o código de usuário pode lidar com a exceção.  
  
 Os tópicos a seguir abordam a notificação e tratamento de erros:  
  
-   [Ganchos de notificação](../../build/reference/notification-hooks.md)  
  
-   [Ganchos de falha](../../build/reference/failure-hooks.md)  
  
-   [Exceções](../../build/reference/exceptions-c-cpp.md)  
  
## <a name="see-also"></a>Consulte também  
 [Suporte do vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md)