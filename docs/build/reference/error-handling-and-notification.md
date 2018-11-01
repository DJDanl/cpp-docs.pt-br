---
title: Tratamento de erro e notificação
ms.date: 11/04/2016
helpviewer_keywords:
- error handling, and notification
ms.assetid: b621cf60-d869-451a-b05e-dc86d78addaa
ms.openlocfilehash: 845a79e035943dbbde0d498702f70ec7dd6b4d3b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50432378"
---
# <a name="error-handling-and-notification"></a>Tratamento de erro e notificação

Para obter mais informações sobre o tratamento de erro e notificação, consulte [Noções básicas sobre a função auxiliar](understanding-the-helper-function.md).

Para obter mais informações sobre funções de gancho, consulte [definições de estrutura e constante](../../build/reference/structure-and-constant-definitions.md).

Se seu programa usa DLLs carregadas com atraso, ele deve tratar erros robusto, pois as falhas que ocorrem durante a execução do programa resultarão em exceções sem tratamento. Tratamento de falhas é composto de duas partes:

Recuperação por meio de um gancho.
Se seu código precisa recuperar ou fornecer uma rotina de e/ou biblioteca alternativa em caso de falha, um gancho pode ser fornecido para a função auxiliar que pode fornecer ou corrigir a situação. As necessidades de rotina de gancho para retornar um valor adequado, para que o processamento podem continuar (um HINSTANCE ou FARPROC) ou 0 para indicar que uma exceção deve ser gerada. Ele também poderia lançar sua própria exceção ou **longjmp** fora o gancho. Há ganchos de notificação e ganchos de falha.

Emissão de relatórios por meio de uma exceção.
Não se tudo o que é necessário para lidar com o erro é anular o procedimento, é necessário nenhum gancho desde que o código do usuário pode tratar a exceção.

Os tópicos a seguir abordam a notificação e tratamento de erro:

- [Ganchos de notificação](../../build/reference/notification-hooks.md)

- [Ganchos de falha](../../build/reference/failure-hooks.md)

- [Exceções](../../build/reference/exceptions-c-cpp.md)

## <a name="see-also"></a>Consulte também

[Suporte do vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md)