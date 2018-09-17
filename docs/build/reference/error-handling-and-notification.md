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
ms.openlocfilehash: 17df0dfd57bf24c7cd442c296409530e521b28de
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45723197"
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