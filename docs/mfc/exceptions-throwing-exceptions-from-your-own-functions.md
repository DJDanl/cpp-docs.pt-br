---
title: 'Exceções: lançando exceções a partir das funções próprias'
ms.date: 11/04/2016
helpviewer_keywords:
- throwing exceptions [MFC], from functions
- functions [MFC], throwing exceptions
- exceptions [MFC], throwing
ms.assetid: 492976e8-8804-4234-8e8f-30dffd0501be
ms.openlocfilehash: ebdfea18e6e8445dd734bf43fb6a4ecf422975e9
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84622742"
---
# <a name="exceptions-throwing-exceptions-from-your-own-functions"></a>Exceções: lançando exceções a partir das funções próprias

É possível usar o paradigma de manipulação de exceção do MFC unicamente para capturar exceções lançadas por funções no MFC ou em outras bibliotecas. Além de capturar exceções geradas pelo código de biblioteca, você pode gerar exceções de seu próprio código se estiver escrevendo funções que podem encontrar condições excepcionais.

Quando uma exceção é lançada, a execução da função atual é interrompida e salta diretamente para o bloco **Catch** do quadro de exceção mais interno. O mecanismo de exceção ignora o caminho de saída normal de uma função. Portanto, você deve ter certeza de excluir os blocos de memória que seriam excluídos em uma saída normal.

#### <a name="to-throw-an-exception"></a>Para gerar uma exceção

1. Use uma das funções auxiliares do MFC, como `AfxThrowMemoryException` . Essas funções geram um objeto de exceção pré-alocado do tipo apropriado.

   No exemplo a seguir, uma função tenta alocar dois blocos de memória e gera uma exceção se uma das duas alocações falha:

   [!code-cpp[NVC_MFCExceptions#17](codesnippet/cpp/exceptions-throwing-exceptions-from-your-own-functions_1.cpp)]

   Se a primeira alocação falhar, você poderá simplesmente lançar a exceção de memória. Se a primeira alocação for bem-sucedida, mas a segunda falhar, você deverá liberar o primeiro bloco de alocação antes de lançar a exceção. Se ambas as alocações forem bem sucedidos, você poderá prosseguir normalmente e liberar os blocos ao sair da função.

     - ou –

1. Use uma exceção definida pelo usuário para indicar uma condição de problema. Você pode lançar um item de qualquer tipo, até mesmo uma classe inteira, como sua exceção.

   O exemplo a seguir tenta reproduzir um som por meio de um dispositivo wave e gera uma exceção se houver uma falha.

   [!code-cpp[NVC_MFCExceptions#18](codesnippet/cpp/exceptions-throwing-exceptions-from-your-own-functions_2.cpp)]

> [!NOTE]
> O tratamento padrão de exceções do MFC aplica-se apenas a ponteiros para `CException` objetos (e objetos de `CException` classes derivadas). O exemplo acima ignora o mecanismo de exceção do MFC.

## <a name="see-also"></a>Consulte também

[Tratamento de Exceção](exception-handling-in-mfc.md)
