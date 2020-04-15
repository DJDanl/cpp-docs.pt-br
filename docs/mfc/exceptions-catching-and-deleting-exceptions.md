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
ms.openlocfilehash: 74022c8bc6af1d2cdf74fa452d4e0483637e542e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365525"
---
# <a name="exceptions-catching-and-deleting-exceptions"></a>Exceções: obtendo e excluindo exceções

As instruções e exemplos a seguir mostram como capturar e excluir exceções. Para obter mais informações sobre a **tentativa**, **pegar**e **lançar** palavras-chave, consulte as melhores [práticas modernas c++ para exceções e manipulação de erros](../cpp/errors-and-exception-handling-modern-cpp.md).

Os manipuladores de exceção devem excluir objetos de exceção que eles manipulam, porque a falha em excluir a exceção causa um vazamento de memória sempre que esse código pega uma exceção.

Seu bloco **de captura** deve excluir uma exceção quando:

- O bloco **de captura** lança uma nova exceção.

   É claro que você não deve excluir a exceção se lançar a mesma exceção novamente:

   [!code-cpp[NVC_MFCExceptions#3](../mfc/codesnippet/cpp/exceptions-catching-and-deleting-exceptions_1.cpp)]

- A execução retorna de dentro do bloco **de captura.**

> [!NOTE]
> Ao excluir `CException`um , `Delete` use a função membro para excluir a exceção. Não use a palavra-chave **excluir,** porque ela pode falhar se a exceção não estiver no heap.

#### <a name="to-catch-and-delete-exceptions"></a>Para capturar e excluir exceções

1. Use a palavra-chave **try** para configurar um bloco **de tentativa.** Execute quaisquer instruções de programa que possam abrir uma exceção dentro de um bloco **de tentativa.**

   Use a palavra-chave de **captura** para configurar um bloco **de captura.** Coloque o código de manipulação de exceções em um bloco **de captura.** O código no bloco **de captura** só é executado se o código dentro do bloco **de tentativa** lançar uma exceção do tipo especificado na declaração **de captura.**

   O esqueleto a seguir mostra como os blocos **de tentativa** e **captura** são normalmente organizados:

   [!code-cpp[NVC_MFCExceptions#4](../mfc/codesnippet/cpp/exceptions-catching-and-deleting-exceptions_2.cpp)]

   Quando uma exceção é lançada, o controle passa para o primeiro bloco de **captura** cuja declaração de exceção corresponde ao tipo de exceção. Você pode lidar seletivamente com diferentes tipos de exceções com blocos de **captura** seqüenciais, conforme listado abaixo:

   [!code-cpp[NVC_MFCExceptions#5](../mfc/codesnippet/cpp/exceptions-catching-and-deleting-exceptions_3.cpp)]

Para obter mais informações, consulte [Exceções: Conversão de Macros de Exceção mfc](../mfc/exceptions-converting-from-mfc-exception-macros.md).

## <a name="see-also"></a>Confira também

[Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)
