---
title: "Exceções: Obtendo e excluindo exceções | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- exceptions [MFC], deleting
- AND_CATCH macro [MFC]
- try-catch exception handling [MFC], catching and deleting exceptions
- exception handling [MFC], catching and deleting exceptions
- catch blocks [MFC], catching and deleting exceptions
- execution [MFC], returns from within catch block
ms.assetid: 7c233ff0-89de-4de0-a68a-9e9cdb164311
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 23988e9d8669bee558ec5418f44921d60bec08d5
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="exceptions-catching-and-deleting-exceptions"></a>Exceções: obtendo e excluindo exceções
As instruções e os exemplos a seguir mostram como capturar e excluir exceções. Para obter mais informações sobre o **tente**, **catch**, e `throw` palavras-chave, consulte [manipulação de exceção C++](../cpp/cpp-exception-handling.md).  
  
 Seus manipuladores de exceção devem excluir objetos de exceção tratam, pois a falha ao excluir a exceção faz com que um vazamento de memória sempre que esse código captura uma exceção.  
  
 O **catch** bloco deve excluir uma exceção quando:  
  
-   O **catch** bloco lançar uma exceção de novo.  
  
     Naturalmente, você não deve excluir a exceção se você gerar novamente a mesma exceção:  
  
     [!code-cpp[NVC_MFCExceptions#3](../mfc/codesnippet/cpp/exceptions-catching-and-deleting-exceptions_1.cpp)]  
  
-   Retorna a execução de dentro do **catch** bloco.  
  
> [!NOTE]
>  Ao excluir um `CException`, use o **excluir** a função de membro para excluir a exceção. Não use o **excluir** palavra-chave, pois ele pode falhar se a exceção não estiver na pilha.  
  
#### <a name="to-catch-and-delete-exceptions"></a>Capturar e excluir exceções  
  
1.  Use o **tente** palavra-chave para configurar um **tente** bloco. Execute as instruções de programa que podem lançar uma exceção dentro de um **tente** bloco.  
  
     Use o **catch** palavra-chave para configurar um **catch** bloco. Coloque o código de tratamento de exceção em uma **catch** bloco. O código no **catch** bloco é executado somente se o código dentro de **tente** bloco lançar uma exceção do tipo especificado no **catch** instrução.  
  
     A seguir mostra esqueleto como **tente** e **catch** blocos normalmente são organizados:  
  
     [!code-cpp[NVC_MFCExceptions#4](../mfc/codesnippet/cpp/exceptions-catching-and-deleting-exceptions_2.cpp)]  
  
     Quando uma exceção for lançada, o controle passará para o primeiro **catch** bloco cuja declaração de exceção corresponde ao tipo da exceção. Seletivamente lidar com diferentes tipos de exceção com sequencial **catch** bloqueia como listado abaixo:  
  
     [!code-cpp[NVC_MFCExceptions#5](../mfc/codesnippet/cpp/exceptions-catching-and-deleting-exceptions_3.cpp)]  
  
 Para obter mais informações, consulte [exceções: Convertendo a partir de Macros de exceção MFC](../mfc/exceptions-converting-from-mfc-exception-macros.md).  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)

