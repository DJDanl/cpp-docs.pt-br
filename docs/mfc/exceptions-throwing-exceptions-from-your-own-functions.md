---
title: "Exceções: Lançando exceções a partir das funções próprias | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- throwing exceptions [MFC], from functions
- functions [MFC], throwing exceptions
- exceptions [MFC], throwing
ms.assetid: 492976e8-8804-4234-8e8f-30dffd0501be
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 15aeb1af7f41cf2df8be3f69657ec6870c55ab34
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="exceptions-throwing-exceptions-from-your-own-functions"></a>Exceções: lançando exceções a partir das funções próprias
É possível usar o paradigma de tratamento de exceção MFC exclusivamente para capturar exceções geradas por funções em MFC ou outras bibliotecas. Além de capturar exceções geradas pelo código da biblioteca, você pode lançar exceções de seu próprio código, se você estiver escrevendo funções que podem encontrar condições excepcionais.  
  
 Quando uma exceção for lançada, a execução da função atual está parada e vai diretamente para o **catch** bloco do quadro de exceção mais interna. O mecanismo de exceção ignora o caminho de saída normal de uma função. Portanto, você deve ser certeza que deseja excluir esses blocos de memória que seriam excluídos em uma saída normal.  
  
#### <a name="to-throw-an-exception"></a>Para lançar uma exceção  
  
1.  Use uma das funções de auxiliar MFC, como `AfxThrowMemoryException`. Essas funções geram um objeto de exceção pré-alocados do tipo apropriado.  
  
     No exemplo a seguir, uma função tenta alocar dois blocos de memória e lança uma exceção se a alocação falhar:  
  
     [!code-cpp[NVC_MFCExceptions#17](../mfc/codesnippet/cpp/exceptions-throwing-exceptions-from-your-own-functions_1.cpp)]  
  
     Se a primeira alocação falhar, você pode simplesmente lançar a exceção de memória. Se a primeira alocação for bem-sucedida, mas o outro falha, você deve liberar o primeiro bloco de alocação antes de lançar a exceção. Se ambas as alocações tiver êxito, você pode prosseguir normalmente e liberar os blocos quando a função de saída.  
  
     - ou –  
  
2.  Use uma exceção definido pelo usuário para indicar uma condição de problema. Você pode lançar um item de qualquer tipo, até mesmo toda uma classe, como a exceção.  
  
     O exemplo a seguir tenta executar um som por meio de um dispositivo de onda e lança uma exceção se houver uma falha.  
  
     [!code-cpp[NVC_MFCExceptions#18](../mfc/codesnippet/cpp/exceptions-throwing-exceptions-from-your-own-functions_2.cpp)]  
  
> [!NOTE]
>  Do MFC manipulação de padrão de exceções só se aplica a ponteiros para `CException` objetos (e objetos do `CException`-classes derivadas). O exemplo acima ignora o mecanismo de exceção do MFC.  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)

