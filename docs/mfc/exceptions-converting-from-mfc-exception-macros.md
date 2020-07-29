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
ms.openlocfilehash: e8e7f47b66f4263ed55d73c0aac1fda73d72393c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87183806"
---
# <a name="exceptions-converting-from-mfc-exception-macros"></a>Exceções: convertendo a partir de macros de exceção MFC

Este é um tópico avançado.

Este artigo explica como converter o código existente escrito com macros da classe Microsoft Foundation — **try**, **Catch**, **throw**e assim por diante — para usar as palavras-chave de manipulação de exceção do C++ **`try`** , **`catch`** e **`throw`** . Os tópicos incluem:

- [Vantagens de conversão](#_core_advantages_of_converting)

- [Convertendo código com macros de exceção para usar exceções do C++](#_core_doing_the_conversion)

## <a name="advantages-of-converting"></a><a name="_core_advantages_of_converting"></a>Vantagens da conversão

Provavelmente, você não precisa converter o código existente, embora esteja ciente das diferenças entre as implementações de macro na versão 3,0 do MFC e as implementações em versões anteriores. Essas diferenças e alterações subsequentes no comportamento do código são discutidas em [exceções: alterações nas macros de exceção na versão 3,0](exceptions-changes-to-exception-macros-in-version-3-0.md).

As principais vantagens da conversão são:

- O código que usa as palavras-chave de manipulação de exceções do C++ é compilado para um pouco menor. EXE ou. DLL.

- As palavras-chave de manipulação de exceções do C++ são mais versáteis: elas podem manipular exceções de qualquer tipo de dados que possa ser copiado ( **`int`** ,, **`float`** **`char`** e assim por diante), enquanto as macros lidam apenas com exceções de classe `CException` e classes derivadas dela.

A principal diferença entre as macros e as palavras-chave é que o código que usa as macros "automaticamente" exclui uma exceção capturada quando a exceção sai do escopo. O código que usa as palavras-chave não, portanto, você deve excluir explicitamente uma exceção capturada. Para obter mais informações, consulte o artigo [exceções: capturando e excluindo exceções](exceptions-catching-and-deleting-exceptions.md).

Outra diferença é a sintaxe. A sintaxe para macros e palavras-chave difere em três aspectos:

1. Argumentos de macro e declarações de exceção:

   Uma invocação de macro **Catch** tem a seguinte sintaxe:

   **Catch (** *exception_class*, *exception_object_pointer_name* **)**

   Observe a vírgula entre o nome da classe e o nome do ponteiro do objeto.

   A declaração de exceção para a **`catch`** palavra-chave usa essa sintaxe:

   **Catch (** *exception_type* *exception_name* **)**

   Essa instrução de declaração de exceção indica o tipo de exceção que o bloco catch manipula.

2. Deslimitação de blocos catch:

   Com as macros, a macro **Catch** (com seus argumentos) começa o primeiro bloco catch; a macro **AND_CATCH** começa os blocos catch subsequentes e a **END_CATCH** macro encerra a sequência de blocos catch.

   Com as palavras-chaves, a **`catch`** palavra-chave (com sua declaração de exceção) começa cada bloco catch. Não há nenhum equivalente para a macro **END_CATCH** ; o bloco catch termina com sua chave de fechamento.

3. A expressão throw:

   As macros usam **THROW_LAST** para lançar novamente a exceção atual. A **`throw`** palavra-chave, sem argumento, tem o mesmo efeito.

## <a name="doing-the-conversion"></a><a name="_core_doing_the_conversion"></a>Fazendo a conversão

#### <a name="to-convert-code-using-macros-to-use-the-c-exception-handling-keywords"></a>Para converter o código usando macros para usar as palavras-chave de manipulação de exceção do C++

1. Localize todas as ocorrências das macros do MFC **try**, **Catch**, **AND_CATCH**, **END_CATCH**, **throw**e **THROW_LAST**.

2. Substituir ou excluir todas as ocorrências das seguintes macros:

   **Tente** (substitua-o por **`try`** )

   **Catch** (substitua-o por **`catch`** )

   **AND_CATCH** (substituir por **`catch`** )

   **END_CATCH** (exclua-o)

   **Throw** (substituir por **`throw`** )

   **THROW_LAST** (substituir por **`throw`** )

3. Modifique os argumentos da macro para que eles formem declarações de exceção válidas.

   Por exemplo, altere

   [!code-cpp[NVC_MFCExceptions#6](codesnippet/cpp/exceptions-converting-from-mfc-exception-macros_1.cpp)]

   para

   [!code-cpp[NVC_MFCExceptions#7](codesnippet/cpp/exceptions-converting-from-mfc-exception-macros_2.cpp)]

4. Modifique o código nos blocos catch para que ele exclua os objetos de exceção conforme necessário. Para obter mais informações, consulte o artigo [exceções: capturando e excluindo exceções](exceptions-catching-and-deleting-exceptions.md).

Aqui está um exemplo de código de tratamento de exceções usando macros de exceção do MFC. Observe que, como o código no exemplo a seguir usa as macros, a exceção `e` é excluída automaticamente:

[!code-cpp[NVC_MFCExceptions#8](codesnippet/cpp/exceptions-converting-from-mfc-exception-macros_3.cpp)]

O código no exemplo a seguir usa as palavras-chave de exceção do C++, portanto, a exceção deve ser explicitamente excluída:

[!code-cpp[NVC_MFCExceptions#9](codesnippet/cpp/exceptions-converting-from-mfc-exception-macros_4.cpp)]

Para obter mais informações, consulte [exceções: usando macros do MFC e exceções do C++](exceptions-using-mfc-macros-and-cpp-exceptions.md).

## <a name="see-also"></a>Confira também

[Tratamento de exceção](exception-handling-in-mfc.md)<br/>
