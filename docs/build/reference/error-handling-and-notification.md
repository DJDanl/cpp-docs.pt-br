---
title: Tratamento de erro e notificação
ms.date: 11/04/2016
helpviewer_keywords:
- error handling, and notification
ms.assetid: b621cf60-d869-451a-b05e-dc86d78addaa
ms.openlocfilehash: 29fe46e15712609ec0c4f268749aaefed103117e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62293180"
---
# <a name="error-handling-and-notification"></a>Tratamento de erro e notificação

Para obter mais informações sobre o tratamento de erro e notificação, consulte [Noções básicas sobre a função auxiliar](understanding-the-helper-function.md).

Para obter mais informações sobre funções de gancho, consulte [definições de estrutura e constante](structure-and-constant-definitions.md).

Se seu programa usa DLLs carregadas com atraso, ele deve tratar erros robusto, pois as falhas que ocorrem durante a execução do programa resultarão em exceções sem tratamento. Tratamento de falhas é composto de duas partes:

Recuperação por meio de um gancho.
Se seu código precisa recuperar ou fornecer uma rotina de e/ou biblioteca alternativa em caso de falha, um gancho pode ser fornecido para a função auxiliar que pode fornecer ou corrigir a situação. As necessidades de rotina de gancho para retornar um valor adequado, para que o processamento podem continuar (um HINSTANCE ou FARPROC) ou 0 para indicar que uma exceção deve ser gerada. Ele também poderia lançar sua própria exceção ou **longjmp** fora o gancho. Há ganchos de notificação e ganchos de falha.

Emissão de relatórios por meio de uma exceção.
Não se tudo o que é necessário para lidar com o erro é anular o procedimento, é necessário nenhum gancho desde que o código do usuário pode tratar a exceção.

Os tópicos a seguir abordam a notificação e tratamento de erro:

- [Ganchos de notificação](notification-hooks.md)

- [Ganchos de falha](failure-hooks.md)

- [Exceções](exceptions-c-cpp.md)

## <a name="see-also"></a>Consulte também

[Suporte do vinculador para DLLs carregadas com atraso](linker-support-for-delay-loaded-dlls.md)
