---
title: 'Exceções: obtendo e excluindo exceções'
ms.date: 11/04/2016
helpviewer_keywords:
- exceptions [MFC], deleting
- AND_CATCH macro [MFC]
- try-catch exception handling [MFC], catching and deleting exceptions
- exception handling [MFC], catching and deleting exceptions
- catch blocks [MFC], catching and deleting exceptions
- execution [MFC], returns from within catch block
ms.assetid: 7c233ff0-89de-4de0-a68a-9e9cdb164311
ms.openlocfilehash: 5c1edd4c5d31d9a0e8e5270d074d25b5dd129a0f
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87184241"
---
# <a name="exceptions-catching-and-deleting-exceptions"></a>Exceções: obtendo e excluindo exceções

As instruções e exemplos a seguir mostram como detectar e excluir exceções. Para obter mais informações sobre **`try`** as **`catch`** **`throw`** palavras-chave, e, consulte [práticas recomendadas do C++ moderno para exceções e tratamento de erros](../cpp/errors-and-exception-handling-modern-cpp.md).

Os manipuladores de exceção devem excluir objetos de exceção que manipulam, pois a falha ao excluir a exceção causa um vazamento de memória sempre que esse código captura uma exceção.

Seu **`catch`** bloco deve excluir uma exceção quando:

- O **`catch`** bloco gera uma nova exceção.

   É claro que você não deve excluir a exceção se lançar a mesma exceção novamente:

   [!code-cpp[NVC_MFCExceptions#3](codesnippet/cpp/exceptions-catching-and-deleting-exceptions_1.cpp)]

- A execução retorna de dentro do **`catch`** bloco.

> [!NOTE]
> Ao excluir um `CException` , use a `Delete` função de membro para excluir a exceção. Não use a **`delete`** palavra-chave, pois ela poderá falhar se a exceção não estiver no heap.

#### <a name="to-catch-and-delete-exceptions"></a>Para detectar e excluir exceções

1. Use a **`try`** palavra-chave para configurar um **`try`** bloco. Executar qualquer instrução de programa que possa gerar uma exceção em um **`try`** bloco.

   Use a **`catch`** palavra-chave para configurar um **`catch`** bloco. Coloque o código de tratamento de exceção em um **`catch`** bloco. O código no **`catch`** bloco é executado somente se o código dentro do **`try`** bloco gera uma exceção do tipo especificado na **`catch`** instrução.

   O esqueleto a seguir mostra como os **`try`** **`catch`** blocos e são normalmente organizados:

   [!code-cpp[NVC_MFCExceptions#4](codesnippet/cpp/exceptions-catching-and-deleting-exceptions_2.cpp)]

   Quando uma exceção é lançada, o controle passa para o primeiro **`catch`** bloco cuja declaração de exceção corresponde ao tipo da exceção. Você pode lidar seletivamente com tipos diferentes de exceções com **`catch`** blocos sequenciais, conforme listado abaixo:

   [!code-cpp[NVC_MFCExceptions#5](codesnippet/cpp/exceptions-catching-and-deleting-exceptions_3.cpp)]

Para obter mais informações, consulte [exceções: convertendo de macros de exceção do MFC](exceptions-converting-from-mfc-exception-macros.md).

## <a name="see-also"></a>Confira também

[Tratamento de exceção](exception-handling-in-mfc.md)
