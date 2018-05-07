---
title: 'Exceções: Liberando objetos em exceções | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- throwing exceptions [MFC], freeing objects in exceptions
- local exception handling
- memory leaks, caused by exception
- try-catch exception handling [MFC], destroying objects
- destroying objects [MFC]
- freeing objects [MFC]
- throwing exceptions [MFC], after destroying
- exception handling [MFC], destroying objects
ms.assetid: 3b14b4ee-e789-4ed2-b8e3-984950441d97
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 21a63a55103cbefda2ba501c5609b772b2203166
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="exceptions-freeing-objects-in-exceptions"></a>Exceções: liberando objetos em exceções
Este artigo explica a necessidade e o método de liberação de objetos quando ocorre uma exceção. Os tópicos incluem:  
  
-   [Tratamento de exceção localmente](#_core_handling_the_exception_locally)  
  
-   [Lançando exceções após a destruição de objetos](#_core_throwing_exceptions_after_destroying_objects)  
  
 Exceções geradas pelo framework ou por seu fluxo de programa normal de interrupção do aplicativo. Portanto, é muito importante controlar fechar objetos para que você possa corretamente descartá-los no caso de uma exceção será lançada.  
  
 Há dois métodos principais para fazer isso.  
  
-   Tratar exceções localmente usando o **tente** e **catch** palavras-chave, em seguida, destruir todos os objetos com uma instrução.  
  
-   Destruir a qualquer objeto no **catch** bloco antes de lançar a exceção fora do bloco para manipulação adicional.  
  
 Essas duas abordagens são ilustradas abaixo como soluções para problema exemplo a seguir:  
  
 [!code-cpp[NVC_MFCExceptions#14](../mfc/codesnippet/cpp/exceptions-freeing-objects-in-exceptions_1.cpp)]  
  
 Conforme descrito acima, `myPerson` não serão excluídos se uma exceção é lançada por `SomeFunc`. Execução vai diretamente para o manipulador de exceção externa Avançar, ignorando a saída da função normal e o código que exclui o objeto. O ponteiro para o objeto sai do escopo quando a exceção deixa a função e a memória ocupada pelo objeto nunca será recuperada como a execução do programa. Este é um vazamento de memória; ele seria detectado usando o diagnóstico de memória.  
  
##  <a name="_core_handling_the_exception_locally"></a> Tratamento de exceção localmente  
 O **try/catch** paradigma fornece um método de programação de defesa para evitar perdas de memória e garantir que os objetos são destruídos quando ocorrerem exceções. Por exemplo, o exemplo mostrado anteriormente neste artigo pode ser reescrito da seguinte maneira:  
  
 [!code-cpp[NVC_MFCExceptions#15](../mfc/codesnippet/cpp/exceptions-freeing-objects-in-exceptions_2.cpp)]  
  
 Este novo exemplo configura um manipulador de exceção para capturar a exceção e trate-o localmente. Em seguida, ele sai da função normalmente e destrói o objeto. O aspecto importante deste exemplo é que um contexto para capturar a exceção é estabelecido com o **try/catch** blocos. Sem um quadro de exceção de local, a função nunca saberia que uma exceção tive sido lançada e não terá a oportunidade de sair normalmente e destruir o objeto.  
  
##  <a name="_core_throwing_exceptions_after_destroying_objects"></a> Lançando exceções após a destruição de objetos  
 É outra maneira de lidar com exceções para passá-las para o contexto de manipulação de exceção externo Avançar. No seu **catch** bloco, você pode fazer uma limpeza de seus objetos alocados localmente e, em seguida, lançar a exceção para processamento adicional.  
  
 A função de lançamento pode ou não seja necessário desalocar objetos do heap. Se a função sempre desaloca o objeto heap antes de retornar o caso normal, em seguida, a função também deve ser desalocada o objeto do heap antes de lançar a exceção. Por outro lado, se a função normalmente não desalocar o objeto antes de retornar o caso normal, em seguida, você deve decidir caso a caso se o objeto de pilha deve ser desalocado.  
  
 A exemplo a seguir mostra como localmente alocada a objetos pode ser limpos:  
  
 [!code-cpp[NVC_MFCExceptions#16](../mfc/codesnippet/cpp/exceptions-freeing-objects-in-exceptions_3.cpp)]  
  
 O mecanismo de exceção desaloca automaticamente objetos de quadro. o destruidor do objeto de quadro também é chamado.  
  
 Se você chamar funções que podem gerar exceções, você pode usar **try/catch** blocos para certificar-se de que você capture as exceções e terá a oportunidade de destruir todos os objetos criados por você. Em particular, lembre-se de que muitas funções MFC podem gerar exceções.  
  
 Para obter mais informações, consulte [exceções: exceções de detectar e excluindo](../mfc/exceptions-catching-and-deleting-exceptions.md).  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)

