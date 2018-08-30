---
title: 'Exceções: Convertendo de Macros de exceção MFC | Microsoft Docs'
ms.custom: ''
ms.date: 08/27/2018
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 692814a189a4f64cbd1e11e4c8cc4741e2d2dc99
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43212620"
---
# <a name="exceptions-converting-from-mfc-exception-macros"></a>Exceções: convertendo a partir de macros de exceção MFC

Este é um tópico avançado.

Este artigo explica como converter um código escrito com macros do Microsoft Foundation Class — **tente**, **CATCH**, **lançar**e assim por diante — para usar o tratamento de exceções C++ palavras-chave **tente**, **catch**, e **lançar**. Os tópicos incluem:

- [Vantagens de conversão](#_core_advantages_of_converting)

- [Conversão de código com macros de exceção usar exceções do C++](#_core_doing_the_conversion)

##  <a name="_core_advantages_of_converting"></a> Vantagens da conversão

Você provavelmente não precisará converter o código existente, embora você deve estar ciente das diferenças entre as implementações de macro no MFC versão 3.0 e as implementações em versões anteriores. Essas diferenças e as alterações subsequentes no comportamento do código são discutidas [exceções: alterações em Macros de exceção na versão 3.0](../mfc/exceptions-changes-to-exception-macros-in-version-3-0.md).

As principais vantagens de conversão são:

- O código que usa as palavras-chave de tratamento de exceções C++ é compilado em um pouco menores. EXE ou. DLL.

- As palavras-chave de tratamento de exceções C++ são mais versáteis: eles podem tratar exceções de qualquer tipo de dados que podem ser copiados (**int**, **float**, **char**e assim por diante), enquanto o macros de lidar com exceções apenas da classe `CException` e as classes derivadas dela.

A principal diferença entre as macros e as palavras-chave é que o código usando as macros "automaticamente" exclui uma exceção capturada quando a exceção sai do escopo. Código usando as palavras-chave, não, portanto, você deve excluir explicitamente uma exceção capturada. Para obter mais informações, consulte o artigo [exceções: exceções de detectar e exclua](../mfc/exceptions-catching-and-deleting-exceptions.md).

Outra diferença é a sintaxe. A sintaxe de macros e palavras-chave é diferente em três aspectos:

1. Argumentos de macro e declarações de exceção:

   Um **CATCH** invocação de macro tem a seguinte sintaxe:

   **CATCH (** *exception_class*, *exception_object_pointer_name* **)**

   Observe a vírgula entre o nome de classe e o nome do ponteiro de objeto.

   A declaração de exceção para o **catch** palavra-chave usa esta sintaxe:

   **catch (** *exception_type* *exception_name* **)**

   Essa instrução de declaração de exceção indica o tipo de exceção catch bloquear identificadores.

2. Delimitação de blocos catch:

   Com as macros, o **CATCH** macro (com seus argumentos) começa o primeiro bloco catch; o **AND_CATCH** macro começa blocos catch subsequentes e o **END_CATCH** macro encerra a sequência de blocos catch.

   Com as palavras-chave, o **catch** palavra-chave (com a respectiva declaração de exceção) começa cada bloco catch. Não há nenhum equivalente para o **END_CATCH** macro; catch bloquear termina com sua chave de fechamento.

3. A expressão de lançamento:

   Usam as macros **THROW_LAST** para gerar novamente a exceção atual. O **lançar** palavra-chave, com nenhum argumento, tem o mesmo efeito.

##  <a name="_core_doing_the_conversion"></a> Fazer a conversão

#### <a name="to-convert-code-using-macros-to-use-the-c-exception-handling-keywords"></a>Para converter o código usando macros para usar as palavras-chave de tratamento de exceções C++

1. Localize todas as ocorrências das macros MFC **tente**, **CATCH**, **AND_CATCH**, **END_CATCH**, **lançar**, e **THROW_LAST**.

2. Substituir ou excluir todas as ocorrências de macros a seguir:

   **TENTE** (substituí-lo **tente**)

   **CAPTURAR** (substituí-lo **catch**)

   **AND_CATCH** (substituí-lo **catch**)

   **END_CATCH** (excluí-la)

   **LANÇAR** (substituí-lo **lançar**)

   **THROW_LAST** (substituí-lo **lançar**)

3. Modifique os argumentos de macro para que eles formam as declarações de exceção válido.

   Por exemplo, alterar

   [!code-cpp[NVC_MFCExceptions#6](../mfc/codesnippet/cpp/exceptions-converting-from-mfc-exception-macros_1.cpp)]

   para

   [!code-cpp[NVC_MFCExceptions#7](../mfc/codesnippet/cpp/exceptions-converting-from-mfc-exception-macros_2.cpp)]

4. Modificar o código nos blocos catch, de modo que ele exclui objetos de exceção, conforme necessário. Para obter mais informações, consulte o artigo [exceções: exceções de detectar e exclua](../mfc/exceptions-catching-and-deleting-exceptions.md).

Aqui está um exemplo de código de tratamento de exceções usando macros de exceção do MFC. Observe que, como o código no exemplo a seguir usa as macros, a exceção `e` é excluído automaticamente:

[!code-cpp[NVC_MFCExceptions#8](../mfc/codesnippet/cpp/exceptions-converting-from-mfc-exception-macros_3.cpp)]

O código no exemplo a seguir usa as palavras-chave de exceção C++, portanto, a exceção deve ser explicitamente excluída:

[!code-cpp[NVC_MFCExceptions#9](../mfc/codesnippet/cpp/exceptions-converting-from-mfc-exception-macros_4.cpp)]

Para obter mais informações, consulte [exceções: usando Macros MFC e exceções do C++](../mfc/exceptions-using-mfc-macros-and-cpp-exceptions.md).

## <a name="see-also"></a>Consulte também

[Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)<br/>
