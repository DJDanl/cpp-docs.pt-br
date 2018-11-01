---
title: 'Exceções: lançando exceções a partir das funções próprias'
ms.date: 11/04/2016
helpviewer_keywords:
- throwing exceptions [MFC], from functions
- functions [MFC], throwing exceptions
- exceptions [MFC], throwing
ms.assetid: 492976e8-8804-4234-8e8f-30dffd0501be
ms.openlocfilehash: 4d0961bff706ccf86eb09d2dcbe695a13bfa8702
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50558974"
---
# <a name="exceptions-throwing-exceptions-from-your-own-functions"></a>Exceções: lançando exceções a partir das funções próprias

É possível usar o paradigma de manipulação de exceção MFC exclusivamente para capturar exceções lançadas pelas funções no MFC ou outras bibliotecas. Além de capturar exceções geradas pelo código da biblioteca, você pode gerar exceções de seu próprio código, se você estiver escrevendo funções que podem encontrar condições excepcionais.

Quando uma exceção é lançada, a execução da função atual for interrompida e pula diretamente para o **catch** bloco do quadro de exceção mais interna. O mecanismo de exceção ignora o caminho de saída normal de uma função. Portanto, você deve ser-se de excluir os blocos de memória que seriam excluídos em uma saída normal.

#### <a name="to-throw-an-exception"></a>Para lançar uma exceção

1. Use uma das funções de auxiliar de MFC, como `AfxThrowMemoryException`. Essas funções geram um objeto de exceção pré-alocado do tipo apropriado.

   No exemplo a seguir, uma função tenta alocar dois blocos de memória e gera uma exceção se a alocação falhar:

   [!code-cpp[NVC_MFCExceptions#17](../mfc/codesnippet/cpp/exceptions-throwing-exceptions-from-your-own-functions_1.cpp)]

   Se a primeira alocação falhar, você pode simplesmente lançar a exceção de memória. Se a primeira alocação for bem-sucedida, mas a segunda falha, você deve liberar o primeiro bloco de alocação antes de lançar a exceção. Se as duas alocações tiver êxito, você pode prosseguir normalmente e liberar os blocos de quando a função de saída.

     - ou –

1. Use uma exceção definidas pelo usuário para indicar uma condição de problema. Você pode lançar um item de qualquer tipo, até mesmo uma classe inteira, como a exceção.

   O exemplo a seguir tenta tocar um som por meio de um dispositivo de som wave e gera uma exceção se houver uma falha.

   [!code-cpp[NVC_MFCExceptions#18](../mfc/codesnippet/cpp/exceptions-throwing-exceptions-from-your-own-functions_2.cpp)]

> [!NOTE]
>  Do MFC tratamento padrão de exceções se aplica somente aos ponteiros para `CException` objetos (e objetos do `CException`-as classes derivadas). O exemplo acima ignora o mecanismo de exceção do MFC.

## <a name="see-also"></a>Consulte também

[Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)

