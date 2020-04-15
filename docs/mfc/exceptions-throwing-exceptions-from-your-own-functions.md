---
title: 'Exceções: lançando exceções a partir das funções próprias'
ms.date: 11/04/2016
helpviewer_keywords:
- throwing exceptions [MFC], from functions
- functions [MFC], throwing exceptions
- exceptions [MFC], throwing
ms.assetid: 492976e8-8804-4234-8e8f-30dffd0501be
ms.openlocfilehash: 6484594df7636fd52ac46ab1cc212c8e2ec0278e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81359285"
---
# <a name="exceptions-throwing-exceptions-from-your-own-functions"></a>Exceções: lançando exceções a partir das funções próprias

É possível usar o paradigma de manipulação de exceções do MFC apenas para capturar exceções lançadas por funções em MFC ou outras bibliotecas. Além de capturar exceções lançadas pelo código da biblioteca, você pode lançar exceções do seu próprio código se estiver escrevendo funções que podem encontrar condições excepcionais.

Quando uma exceção é lançada, a execução da função atual é interrompida e salta diretamente para o bloco de **captura** do quadro de exceção mais interno. O mecanismo de exceção contorna o caminho de saída normal de uma função. Portanto, você deve ter certeza de excluir os blocos de memória que seriam excluídos em uma saída normal.

#### <a name="to-throw-an-exception"></a>Para abrir uma exceção

1. Use uma das funções auxiliares do `AfxThrowMemoryException`MFC, tais como . Essas funções lançam um objeto de exceção pré-alocado do tipo apropriado.

   No exemplo a seguir, uma função tenta alocar dois blocos de memória e lança uma exceção se qualquer uma das alocações falhar:

   [!code-cpp[NVC_MFCExceptions#17](../mfc/codesnippet/cpp/exceptions-throwing-exceptions-from-your-own-functions_1.cpp)]

   Se a primeira alocação falhar, você pode simplesmente jogar a exceção de memória. Se a primeira alocação for bem sucedida, mas a segunda falhar, você deve liberar o primeiro bloco de alocação antes de lançar a exceção. Se ambas as alocações forem bem sucedidas, você pode proceder normalmente e liberar os blocos ao sair da função.

     - ou –

1. Use uma exceção definida pelo usuário para indicar uma condição de problema. Você pode jogar um item de qualquer tipo, até mesmo uma classe inteira, como sua exceção.

   O exemplo a seguir tenta reproduzir um som através de um dispositivo de onda e lança uma exceção se houver uma falha.

   [!code-cpp[NVC_MFCExceptions#18](../mfc/codesnippet/cpp/exceptions-throwing-exceptions-from-your-own-functions_2.cpp)]

> [!NOTE]
> O manuseio padrão de exceções do MFC se `CException` aplica apenas `CException`a ponteiros para objetos (e objetos de classes derivadas). O exemplo acima ignora o mecanismo de exceção do MFC.

## <a name="see-also"></a>Confira também

[Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)
