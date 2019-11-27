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
ms.openlocfilehash: 0142ffddfb391ae8da878d9e5fe34629cf16cb52
ms.sourcegitcommit: 654aecaeb5d3e3fe6bc926bafd6d5ace0d20a80e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2019
ms.locfileid: "74246699"
---
# <a name="exceptions-catching-and-deleting-exceptions"></a>Exceções: obtendo e excluindo exceções

As instruções e exemplos a seguir mostram como detectar e excluir exceções. Para obter mais informações sobre as palavras-chave **try**, **Catch**e **throw** , consulte [práticas C++ recomendadas modernas para exceções e tratamento de erros](../cpp/errors-and-exception-handling-modern-cpp.md).

Os manipuladores de exceção devem excluir objetos de exceção que manipulam, pois a falha ao excluir a exceção causa um vazamento de memória sempre que esse código captura uma exceção.

Seu bloco **Catch** deve excluir uma exceção quando:

- O bloco **Catch** gera uma nova exceção.

   É claro que você não deve excluir a exceção se lançar a mesma exceção novamente:

   [!code-cpp[NVC_MFCExceptions#3](../mfc/codesnippet/cpp/exceptions-catching-and-deleting-exceptions_1.cpp)]

- A execução retorna de dentro do bloco **Catch** .

> [!NOTE]
>  Ao excluir um `CException`, use a função de membro `Delete` para excluir a exceção. Não use a palavra-chave **delete** , pois ela poderá falhar se a exceção não estiver no heap.

#### <a name="to-catch-and-delete-exceptions"></a>Para detectar e excluir exceções

1. Use a palavra-chave **try** para configurar um bloco **try** . Execute qualquer instrução de programa que possa gerar uma exceção em um bloco **try** .

   Use a palavra-chave **Catch** para configurar um bloco **Catch** . Coloque o código de tratamento de exceção em um bloco **Catch** . O código no bloco **Catch** é executado somente se o código dentro do bloco **try** gera uma exceção do tipo especificado na instrução **Catch** .

   O esqueleto a seguir mostra como blocos **try** e **Catch** normalmente são organizados:

   [!code-cpp[NVC_MFCExceptions#4](../mfc/codesnippet/cpp/exceptions-catching-and-deleting-exceptions_2.cpp)]

   Quando uma exceção é lançada, o controle passa para o primeiro bloco **Catch** cuja declaração de exceção corresponde ao tipo da exceção. Você pode lidar seletivamente com tipos diferentes de exceções com blocos de **Catch** sequenciais, conforme listado abaixo:

   [!code-cpp[NVC_MFCExceptions#5](../mfc/codesnippet/cpp/exceptions-catching-and-deleting-exceptions_3.cpp)]

Para obter mais informações, consulte [exceções: convertendo de macros de exceção do MFC](../mfc/exceptions-converting-from-mfc-exception-macros.md).

## <a name="see-also"></a>Consulte também

[Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)
