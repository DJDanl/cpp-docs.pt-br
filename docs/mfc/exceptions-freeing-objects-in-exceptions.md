---
title: 'Exceções: liberando objetos em exceções'
ms.date: 11/04/2016
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
ms.openlocfilehash: 6e03d46a2600458f3107efa6e0b6b0d643c9b160
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50442465"
---
# <a name="exceptions-freeing-objects-in-exceptions"></a>Exceções: liberando objetos em exceções

Este artigo explica a necessidade e o método de liberação de objetos quando ocorre uma exceção. Os tópicos incluem:

- [Tratamento da exceção localmente](#_core_handling_the_exception_locally)

- [Lançando exceções após a destruição de objetos](#_core_throwing_exceptions_after_destroying_objects)

Exceções geradas pelo framework ou por seu fluxo de programa normal de interrupção do aplicativo. Portanto, é muito importante manter o controle de fechamento de objetos, de modo que você pode corretamente descartá-los no caso de uma exceção será lançada.

Há dois métodos principais para fazer isso.

- Tratar exceções localmente usando o **tente** e **catch** palavras-chave, em seguida, destrua todos os objetos com uma instrução.

- Destruir a qualquer objeto na **catch** bloco antes de lançar a exceção fora do bloco para manipulação adicional.

Essas duas abordagens são ilustradas abaixo como soluções para o exemplo a seguir problemático:

[!code-cpp[NVC_MFCExceptions#14](../mfc/codesnippet/cpp/exceptions-freeing-objects-in-exceptions_1.cpp)]

Conforme descrito acima, `myPerson` não será excluído se uma exceção é lançada pelo `SomeFunc`. Execução saltará diretamente para o próximo manipulador de exceção externa, ignorando a saída da função normal e o código que exclui o objeto. O ponteiro para o objeto sai do escopo quando a exceção deixa a função e a memória ocupada pelo objeto nunca será recuperada, desde a execução do programa. Isso é um vazamento de memória; ele seria detectado usando o diagnóstico de memória.

##  <a name="_core_handling_the_exception_locally"></a> Tratamento da exceção localmente

O **try/catch** paradigma fornece um método de programação defensivo para evitar vazamentos de memória e garantindo que seus objetos são destruídos quando ocorrerem exceções. Por exemplo, o exemplo mostrado anteriormente neste artigo poderia ser reescrito da seguinte maneira:

[!code-cpp[NVC_MFCExceptions#15](../mfc/codesnippet/cpp/exceptions-freeing-objects-in-exceptions_2.cpp)]

Esse novo exemplo configura um manipulador de exceção para capturar a exceção e tratá-la localmente. Em seguida, ele sai da função normalmente e destrói o objeto. O aspecto importante desse exemplo é que um contexto para capturar a exceção é estabelecido com o **try/catch** blocos. Sem um quadro de local de exceção, a função jamais saberia que uma exceção tivesse sido lançada e não terá a oportunidade de se sair normalmente e destruir o objeto.

##  <a name="_core_throwing_exceptions_after_destroying_objects"></a> Lançando exceções após a destruição de objetos

Outra maneira de lidar com exceções é transferi-los para o contexto de manipulação de exceção externo Avançar. No seu **catch** bloco, você pode fazer uma limpeza de seus objetos alocados localmente e, em seguida, lance a exceção para processamento adicional.

A função gerando pode ou não, talvez seja necessário desalocar objetos da pilha. Se a função sempre desaloca o objeto da pilha antes de retornar no caso normal, em seguida, a função também deverá desalocar o objeto da pilha antes de lançar a exceção. Por outro lado, se a função normalmente não desalocar o objeto antes de retornar no caso normal, em seguida, você deve decidir caso a caso se o objeto da pilha deve ser desalocado.

A exemplo a seguir mostra objetos alocados como localmente pode ser limpos:

[!code-cpp[NVC_MFCExceptions#16](../mfc/codesnippet/cpp/exceptions-freeing-objects-in-exceptions_3.cpp)]

O mecanismo de exceção desaloca automaticamente objetos de quadro; o destruidor do objeto de quadro também é chamado.

Se você chamar funções que podem gerar exceções, você pode usar **try/catch** blocos para certificar-se de que você capture as exceções e tenha a oportunidade para destruir todos os objetos criados por você. Em particular, lembre-se de que muitas funções MFC podem lançar exceções.

Para obter mais informações, consulte [exceções: exceções de detectar e exclua](../mfc/exceptions-catching-and-deleting-exceptions.md).

## <a name="see-also"></a>Consulte também

[Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)

