---
title: 'Exceções: convertendo a partir de macros de exceção MFC'
ms.date: 08/27/2018
helpviewer_keywords:
- converting exceptions [MFC]
- exception objects [MFC]
- conversions [MFC], code written with MFC macros
- keywords [MFC], macros
- macrosv, C++ keywords
- exception objects [MFC], deleting
- CException class [MFC], deleting CException class objects
- exceptions [MFC], converting
- exceptions [MFC], deleting exception objects
- catch blocks [MFC], delimiting
- exception handling [MFC], converting exceptions
ms.assetid: bd3ac3b3-f3ce-4fdd-a168-a2cff13ed796
ms.openlocfilehash: 330f66b1f46542082637645ad53da016b434d4a2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372023"
---
# <a name="exceptions-converting-from-mfc-exception-macros"></a>Exceções: convertendo a partir de macros de exceção MFC

Este é um tópico avançado.

Este artigo explica como converter o código existente escrito com as macros microsoft foundation class — **TRY**, **CATCH**, **THROW**, e assim por diante — para usar as palavras-chave c++ de manipulação de exceções **try**, **catch**e **throw**. Os tópicos incluem:

- [Vantagens de conversão](#_core_advantages_of_converting)

- [Conversão de código com macros de exceção para usar exceções C++](#_core_doing_the_conversion)

## <a name="advantages-of-converting"></a><a name="_core_advantages_of_converting"></a>Vantagens da Conversão

Você provavelmente não precisa converter o código existente, embora você deve estar ciente das diferenças entre as implementações de macro na versão 3.0 do MFC e as implementações em versões anteriores. Essas diferenças e alterações subseqüentes no comportamento do código são discutidas em [Exceções: Alterações para Macros de Exceção na Versão 3.0](../mfc/exceptions-changes-to-exception-macros-in-version-3-0.md).

As principais vantagens da conversão são:

- Código que usa as palavras-chave c++ de manipulação de exceções compila-se para um pouco menor . EXE ou . Dll.

- As palavras-chave c++ de manipulação de exceção são mais versáteis: elas podem lidar com exceções de qualquer tipo de dados `CException` que possam ser copiadas **(int,** **float,** **char,** e assim por diante), enquanto as macros lidam com exceções apenas de classes e classes derivadas dele.

A principal diferença entre as macros e as palavras-chave é que o código usando as macros "automaticamente" exclui uma exceção capturada quando a exceção sai do escopo. O código usando as palavras-chave não, então você deve excluir explicitamente uma exceção capturada. Para obter mais informações, consulte o artigo [Exceções: Captura e Exclusão exceções](../mfc/exceptions-catching-and-deleting-exceptions.md).

Outra diferença é a sintaxe. A sintaxe para macros e palavras-chave difere em três aspectos:

1. Argumentos macro e declarações de exceção:

   Uma invocação macro **CATCH** tem a seguinte sintaxe:

   **CATCH (** *exception_class*, *exception_object_pointer_name* **)**

   Observe a comma entre o nome da classe e o nome do ponteiro do objeto.

   A declaração de exceção para a palavra-chave **de captura** usa esta sintaxe:

   **catch (exception_type** *exception_type* *exception_name)* **)**

   Esta declaração de declaração de exceção indica o tipo de exceção que as alças do bloco de captura manipulam.

2. Delimitação de blocos de captura:

   Com as macros, a macro **CATCH** (com seus argumentos) inicia o primeiro bloco de captura; a **macro AND_CATCH** começa blocos de captura subseqüentes, e a macro **END_CATCH** encerra a seqüência de blocos de captura.

   Com as palavras-chave, a palavra-chave **de captura** (com sua declaração de exceção) começa a cada bloco de captura. Não há contrapartida para a **macro END_CATCH;** o bloco de captura termina com sua cinta de fechamento.

3. A expressão de arremesso:

   As macros usam **THROW_LAST** para relançar a exceção atual. A palavra-chave **de lançamento,** sem argumento, tem o mesmo efeito.

## <a name="doing-the-conversion"></a><a name="_core_doing_the_conversion"></a>Fazendo a Conversão

#### <a name="to-convert-code-using-macros-to-use-the-c-exception-handling-keywords"></a>Para converter código usando macros para usar as palavras-chave c++ de manipulação de exceções

1. Localize todas as ocorrências das macros MFC **TRY**, **CATCH**, **AND_CATCH**, **END_CATCH**, **THROW**e **THROW_LAST**.

2. Substitua ou exclua todas as ocorrências das seguintes macros:

   **TRY** (Substitua-o por **try)**

   **CATCH** (Substitua-o por **captura)**

   **AND_CATCH** (Substitua-o por **captura)**

   **END_CATCH** (Delete-o)

   **THROW** (Substitua-o por **arremesso)**

   **THROW_LAST** (Substitua-o por **arremesso)**

3. Modifique os argumentos de macro para que eles formem declarações de exceção válidas.

   Por exemplo, altere

   [!code-cpp[NVC_MFCExceptions#6](../mfc/codesnippet/cpp/exceptions-converting-from-mfc-exception-macros_1.cpp)]

   para

   [!code-cpp[NVC_MFCExceptions#7](../mfc/codesnippet/cpp/exceptions-converting-from-mfc-exception-macros_2.cpp)]

4. Modifique o código nos blocos de captura para que ele exclua objetos de exceção conforme necessário. Para obter mais informações, consulte o artigo [Exceções: Captura e Exclusão exceções](../mfc/exceptions-catching-and-deleting-exceptions.md).

Aqui está um exemplo de código de manipulação de exceções usando macros de exceção do MFC. Observe que, como o código no exemplo a `e` seguir usa as macros, a exceção é excluída automaticamente:

[!code-cpp[NVC_MFCExceptions#8](../mfc/codesnippet/cpp/exceptions-converting-from-mfc-exception-macros_3.cpp)]

O código no próximo exemplo usa as palavras-chave de exceção C++, de modo que a exceção deve ser explicitamente excluída:

[!code-cpp[NVC_MFCExceptions#9](../mfc/codesnippet/cpp/exceptions-converting-from-mfc-exception-macros_4.cpp)]

Para obter mais informações, consulte [Exceções: Usando Macros MFC e Exceções C++.](../mfc/exceptions-using-mfc-macros-and-cpp-exceptions.md)

## <a name="see-also"></a>Confira também

[Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)<br/>
