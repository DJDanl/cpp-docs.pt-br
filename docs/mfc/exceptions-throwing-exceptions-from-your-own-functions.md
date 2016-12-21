---
title: "Exce&#231;&#245;es: lan&#231;ando exce&#231;&#245;es a partir das fun&#231;&#245;es pr&#243;prias | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "exceções, lançando"
  - "funções [C++], lançando exceções"
  - "lançando exceções, de funções"
ms.assetid: 492976e8-8804-4234-8e8f-30dffd0501be
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Exce&#231;&#245;es: lan&#231;ando exce&#231;&#245;es a partir das fun&#231;&#245;es pr&#243;prias
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

É possível usar somente o paradigmas manipulação de exceções gerais de MFC para capturar as exceções lançadas por funções em MFC ou em outras bibliotecas.  Além de capturar as exceções lançadas pelo código de biblioteca, você pode lançar exceções de seu próprio código se você estiver escrevendo as funções que podem encontrar condições excepcionais.  
  
 Quando uma exceção é gerada, a execução da função atual será interrompida e ignorará diretamente ao bloco de **catch** do quadro da exceção interna especificados.  O mecanismo de exceção ignora o caminho de saída normal de uma função.  Em virtude disso, você deve ter a certeza de excluir os blocos de memória que serão excluídos em uma saída regular.  
  
#### Para gerar uma exceção  
  
1.  Use uma das funções auxiliares MFC, como `AfxThrowMemoryException`.  Essas funções emitem um objeto pré\-alocados de exceção do tipo apropriado.  
  
     No exemplo a seguir, uma função tenta atribuir dois blocos de memória e lançará uma exceção se qualquer alocação falhar:  
  
     [!code-cpp[NVC_MFCExceptions#17](../mfc/codesnippet/CPP/exceptions-throwing-exceptions-from-your-own-functions_1.cpp)]  
  
     Se a primeira alocação falhar, basta lançar exceção de memória.  Se a primeira alocação é com êxito mas segunda falha, você deve liberar o primeiro bloco de alocação antes de gerar a exceção.  Se ambas as alocações êxito, você pode continuar normalmente e liberar os blocos ao sair da função.  
  
     \-ou\-  
  
2.  Use uma exceção definido pelo usuário para indicar uma condição do problema.  Você pode gerar um item de qualquer tipo, até mesmo uma classe inteira, como a exceção.  
  
     O exemplo a seguir tenta executar um som por um dispositivo de onda e lançará uma exceção se houver uma falha.  
  
     [!code-cpp[NVC_MFCExceptions#18](../mfc/codesnippet/CPP/exceptions-throwing-exceptions-from-your-own-functions_2.cpp)]  
  
> [!NOTE]
>  Os MFC usam como padrão a manipulação de exceções são válidas somente para ponteiros para os objetos de `CException` \(e os objetos de `CException`\- classes derivadas.\)  O mecanismo de exceção MFC acima dos desvios de exemplo.  
  
## Consulte também  
 [Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)