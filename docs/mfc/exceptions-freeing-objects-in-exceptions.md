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
ms.openlocfilehash: a02b71609ec19d6106153bf67e9d56b860cfdfff
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217929"
---
# <a name="exceptions-freeing-objects-in-exceptions"></a>Exceções: liberando objetos em exceções

Este artigo explica a necessidade e o método de liberação de objetos quando ocorre uma exceção. Os tópicos incluem:

- [Manipulando a exceção localmente](#_core_handling_the_exception_locally)

- [Lançando exceções depois de destruir objetos](#_core_throwing_exceptions_after_destroying_objects)

Exceções lançadas pela estrutura ou pelo seu aplicativo interrompe o fluxo do programa normal. Portanto, é muito importante manter o controle do fechamento de objetos para que você possa descartá-los corretamente no caso de uma exceção ser lançada.

Há dois métodos principais para fazer isso.

- Manipule exceções localmente usando as **`try`** **`catch`** palavras-chave e, em seguida, destrua todos os objetos com uma instrução.

- Destrua qualquer objeto no **`catch`** bloco antes de lançar a exceção fora do bloco para tratamento adicional.

Essas duas abordagens são ilustradas abaixo como soluções para o seguinte exemplo problemático:

[!code-cpp[NVC_MFCExceptions#14](codesnippet/cpp/exceptions-freeing-objects-in-exceptions_1.cpp)]

Conforme escrito acima, `myPerson` não será excluído se uma exceção for lançada pelo `SomeFunc` . A execução salta diretamente para o próximo manipulador de exceção externa, ignorando a saída da função normal e o código que exclui o objeto. O ponteiro para o objeto sai do escopo quando a exceção sai da função e a memória ocupada pelo objeto nunca será recuperada enquanto o programa estiver em execução. Esse é um vazamento de memória; Ele seria detectado usando o diagnóstico de memória.

## <a name="handling-the-exception-locally"></a><a name="_core_handling_the_exception_locally"></a>Manipulando a exceção localmente

O paradigma **try/catch** fornece um método de programação defensiva para evitar vazamentos de memória e garantir que seus objetos sejam destruídos quando ocorrerem exceções. Por exemplo, o exemplo mostrado anteriormente neste artigo poderia ser reescrito da seguinte maneira:

[!code-cpp[NVC_MFCExceptions#15](codesnippet/cpp/exceptions-freeing-objects-in-exceptions_2.cpp)]

Este novo exemplo configura um manipulador de exceção para capturar a exceção e tratá-la localmente. Em seguida, ele sai da função normalmente e destrói o objeto. O aspecto importante desse exemplo é que um contexto para capturar a exceção é estabelecido com os blocos **try/catch** . Sem um quadro de exceção local, a função nunca saberia que uma exceção foi gerada e não teria a chance de sair normalmente e destruir o objeto.

## <a name="throwing-exceptions-after-destroying-objects"></a><a name="_core_throwing_exceptions_after_destroying_objects"></a>Lançando exceções depois de destruir objetos

Outra maneira de lidar com exceções é passá-las para o próximo contexto de tratamento de exceção externo. Em seu **`catch`** bloco, você pode fazer uma limpeza de seus objetos alocados localmente e, em seguida, lançar a exceção em para processamento adicional.

A função de lançamento pode ou não precisar desalocar objetos heap. Se a função sempre desalocar o objeto de heap antes de retornar no caso normal, a função também deverá desalocar o objeto de heap antes de lançar a exceção. Por outro lado, se a função normalmente não desalocar o objeto antes de retornar no caso normal, você deverá decidir caso a caso, se o objeto de heap deve ser desalocado.

O exemplo a seguir mostra como os objetos alocados localmente podem ser limpos:

[!code-cpp[NVC_MFCExceptions#16](codesnippet/cpp/exceptions-freeing-objects-in-exceptions_3.cpp)]

O mecanismo de exceção desaloca automaticamente objetos de quadro; o destruidor do objeto frame também é chamado.

Se você chamar funções que podem gerar exceções, poderá usar blocos **try/catch** para certificar-se de capturar as exceções e ter a chance de destruir todos os objetos que você criou. Em particular, lembre-se de que muitas funções MFC podem gerar exceções.

Para obter mais informações, consulte [exceções: capturando e excluindo exceções](exceptions-catching-and-deleting-exceptions.md).

## <a name="see-also"></a>Confira também

[Tratamento de exceção](exception-handling-in-mfc.md)
