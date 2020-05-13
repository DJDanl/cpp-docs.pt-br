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
ms.openlocfilehash: 49c7c6b0481f90baa23609c1bb1596deda49f7bd
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371992"
---
# <a name="exceptions-freeing-objects-in-exceptions"></a>Exceções: liberando objetos em exceções

Este artigo explica a necessidade e o método de libertação de objetos quando ocorre uma exceção. Os tópicos incluem:

- [Lidar com a exceção localmente](#_core_handling_the_exception_locally)

- [Atirando exceções depois de destruir objetos](#_core_throwing_exceptions_after_destroying_objects)

Exceções lançadas pelo framework ou pelo aplicativo interrompem o fluxo normal do programa. Assim, é muito importante manter o controle atento dos objetos para que você possa descartá-los adequadamente no caso de uma exceção ser lançada.

Há dois métodos primários para fazer isso.

- Lidar com exceções localmente usando as palavras-chave **try** e **catch** e, em seguida, destruir todos os objetos com uma declaração.

- Destrua qualquer objeto no bloco **de captura** antes de jogar a exceção fora do bloco para posterior manuseio.

Essas duas abordagens são ilustradas abaixo como soluções para o seguinte exemplo problemático:

[!code-cpp[NVC_MFCExceptions#14](../mfc/codesnippet/cpp/exceptions-freeing-objects-in-exceptions_1.cpp)]

Como escrito `myPerson` acima, não será excluído se `SomeFunc`uma exceção for lançada por . A execução salta diretamente para o próximo manipulador de exceção externo, contornando a saída de função normal e o código que exclui o objeto. O ponteiro para o objeto fica fora de escopo quando a exceção deixa a função, e a memória ocupada pelo objeto nunca será recuperada enquanto o programa estiver em execução. Isto é um vazamento de memória; seria detectado usando o diagnóstico de memória.

## <a name="handling-the-exception-locally"></a><a name="_core_handling_the_exception_locally"></a>Manipulação da exceção localmente

O paradigma **de tentativa/captura** fornece um método de programação defensiva para evitar vazamentos de memória e garantir que seus objetos sejam destruídos quando exceções ocorrem. Por exemplo, o exemplo mostrado anteriormente neste artigo pode ser reescrito da seguinte forma:

[!code-cpp[NVC_MFCExceptions#15](../mfc/codesnippet/cpp/exceptions-freeing-objects-in-exceptions_2.cpp)]

Este novo exemplo configura um manipulador de exceção para pegar a exceção e manuseá-la localmente. Em seguida, ele sai da função normalmente e destrói o objeto. O aspecto importante deste exemplo é que um contexto para capturar a exceção é estabelecido com os blocos **de tentativa/captura.** Sem um quadro de exceção local, a função nunca saberia que uma exceção havia sido lançada e não teria a chance de sair normalmente e destruir o objeto.

## <a name="throwing-exceptions-after-destroying-objects"></a><a name="_core_throwing_exceptions_after_destroying_objects"></a>Jogando exceções depois de destruir objetos

Outra maneira de lidar com exceções é passá-las para o próximo contexto externo de tratamento de exceções. No seu bloco **de captura,** você pode fazer alguma limpeza de seus objetos alocados localmente e, em seguida, jogar a exceção para processamento adicional.

A função de arremesso pode ou não precisar desalocar objetos de pilha. Se a função sempre desalocar o objeto heap antes de retornar no caso normal, então a função também deve desalocar o objeto heap antes de lançar a exceção. Por outro lado, se a função normalmente não dealoca o objeto antes de retornar no caso normal, então você deve decidir caso a caso se o objeto heap deve ser desalocado.

O exemplo a seguir mostra como objetos alocados localmente podem ser limpos:

[!code-cpp[NVC_MFCExceptions#16](../mfc/codesnippet/cpp/exceptions-freeing-objects-in-exceptions_3.cpp)]

O mecanismo de exceção desaloca automaticamente objetos de quadro; o destruidor do objeto quadro também é chamado.

Se você chamar funções que podem lançar exceções, você pode usar blocos **de tentativa/captura** para garantir que você pegue as exceções e tenha a chance de destruir quaisquer objetos que você criou. Em particular, esteja ciente de que muitas funções de MFC podem lançar exceções.

Para obter mais informações, consulte [Exceções: Captura e Exclusão de Exceções](../mfc/exceptions-catching-and-deleting-exceptions.md).

## <a name="see-also"></a>Confira também

[Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)
