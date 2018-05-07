---
title: 'Exceções: Convertendo a partir de Macros de exceção MFC | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: 8953cc28e35974f7a2a63754533ffd851ca62a3e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="exceptions-converting-from-mfc-exception-macros"></a>Exceções: convertendo a partir de macros de exceção MFC
Este é um tópico avançado.  
  
 Este artigo explica como converter o código existente gravado com macros do Microsoft Foundation Class — **tente**, **CATCH**, **lançar**, e assim por diante, para usar a manipulação de exceção de C++ palavras-chave **tente**, **catch**, e `throw`. Os tópicos incluem:  
  
-   [Vantagens de conversão](#_core_advantages_of_converting)  
  
-   [Converter o código com macros de exceção para usar exceções C++](#_core_doing_the_conversion)  
  
##  <a name="_core_advantages_of_converting"></a> Vantagens da conversão  
 Você provavelmente não precisará converter o código existente, embora você deve estar ciente das diferenças entre as implementações de macro em MFC versão 3.0 e as implementações em versões anteriores. Essas diferenças e as alterações subsequentes no comportamento do código são discutidas em [exceções: alterações em Macros de exceção na versão 3.0](../mfc/exceptions-changes-to-exception-macros-in-version-3-0.md).  
  
 As principais vantagens de conversão são:  
  
-   O código que usa as palavras-chave de tratamento de exceções C++ compila um pouco menores. EXE ou. DLL.  
  
-   As palavras-chave de tratamento de exceções C++ são mais versáteis: eles possam lidar com exceções de qualquer tipo de dados que podem ser copiados (`int`, **float**, `char`e assim por diante), enquanto as macros tratam exceções somente da classe `CException` e classes derivadas dele.  
  
 A principal diferença entre as macros e as palavras-chave é que o código usando as macros "automaticamente" exclui uma exceção capturada quando a exceção sai do escopo. Código usando as palavras-chave não, você deve excluir explicitamente uma exceção capturada. Para obter mais informações, consulte o artigo [exceções: exceções de detectar e excluindo](../mfc/exceptions-catching-and-deleting-exceptions.md).  
  
 Outra diferença é a sintaxe. A sintaxe para macros e palavras-chave diferente em três aspectos:  
  
1.  Argumentos de macro e declarações de exceção:  
  
     Um **CATCH** invocação de macro tem a seguinte sintaxe:  
  
     **CATCH (** *exception_class*, *exception_object_pointer_name* **)**  
  
     Observe a vírgula entre o nome da classe e o nome do ponteiro de objeto.  
  
     A declaração de exceção para o **catch** palavra-chave usa esta sintaxe:  
  
     **catch (** *exception_type* *exception_name *)**  
  
     Esta declaração de exceção indica o tipo de exceção catch bloquear identificadores.  
  
2.  Delimitação de blocos catch:  
  
     Com as macros, o **CATCH** macro (com os argumentos) começa o primeiro bloco catch; o `AND_CATCH` macro começa blocos catch subsequentes e o `END_CATCH` macro encerra a sequência de blocos catch.  
  
     Com as palavras-chave, o **catch** palavra-chave (com sua declaração de exceção) começa cada bloco catch. Não há nenhum equivalente para o `END_CATCH` macro; catch bloquear termina com seu colchete de fechamento.  
  
3.  A expressão throw:  
  
     Usam as macros `THROW_LAST` para gerar novamente a exceção atual. O `throw` palavra-chave sem argumento tem o mesmo efeito.  
  
##  <a name="_core_doing_the_conversion"></a> A conversão  
  
#### <a name="to-convert-code-using-macros-to-use-the-c-exception-handling-keywords"></a>Para converter o código usando macros para usar as palavras-chave de tratamento de exceções C++  
  
1.  Localizar todas as ocorrências de macros MFC **tente**, **CATCH**, `AND_CATCH`, `END_CATCH`, **gerar**, e `THROW_LAST`.  
  
2.  Substituir ou excluir todas as ocorrências de macros a seguir:  
  
     **TENTE** (substituí-lo por **tente**)  
  
     **CATCH** (substituí-lo por **catch**)  
  
     `AND_CATCH` (Substitua-o por **catch**)  
  
     `END_CATCH` (Excluir)  
  
     **LANÇAR** (substituí-lo por `throw`)  
  
     `THROW_LAST` (Substitua-o por `throw`)  
  
3.  Modifique os argumentos de macro para que eles fazem declarações de exceção válido.  
  
     Por exemplo, alterar  
  
     [!code-cpp[NVC_MFCExceptions#6](../mfc/codesnippet/cpp/exceptions-converting-from-mfc-exception-macros_1.cpp)]  
  
     para  
  
     [!code-cpp[NVC_MFCExceptions#7](../mfc/codesnippet/cpp/exceptions-converting-from-mfc-exception-macros_2.cpp)]  
  
4.  Modifique o código nos blocos catch, para que ele exclui objetos de exceção conforme necessário. Para obter mais informações, consulte o artigo [exceções: exceções de detectar e excluindo](../mfc/exceptions-catching-and-deleting-exceptions.md).  
  
 Aqui está um exemplo de código de tratamento de exceções usando macros de exceção MFC. Observe que, como o código no exemplo a seguir usa as macros, a exceção `e` é excluído automaticamente:  
  
 [!code-cpp[NVC_MFCExceptions#8](../mfc/codesnippet/cpp/exceptions-converting-from-mfc-exception-macros_3.cpp)]  
  
 O código no exemplo a seguir usa as palavras-chave exceção de C++ para a exceção deve ser explicitamente excluída:  
  
 [!code-cpp[NVC_MFCExceptions#9](../mfc/codesnippet/cpp/exceptions-converting-from-mfc-exception-macros_4.cpp)]  
  
 Para obter mais informações, consulte [exceções: usando Macros de MFC e exceções de C++](../mfc/exceptions-using-mfc-macros-and-cpp-exceptions.md).  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)

