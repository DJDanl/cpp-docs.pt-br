---
title: "Exce&#231;&#245;es: obtendo e excluindo exce&#231;&#245;es | Microsoft Docs"
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
  - "Macro AND_CATCH"
  - "blocos catch, obtendo e excluindo exceções"
  - "tratamento de exceção, obtendo e excluindo exceções"
  - "exceções, excluindo"
  - "execução, retornos do bloco catch"
  - "tratamento de exceções de try-catch, obtendo e excluindo exceções"
ms.assetid: 7c233ff0-89de-4de0-a68a-9e9cdb164311
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Exce&#231;&#245;es: obtendo e excluindo exce&#231;&#245;es
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As seguintes instruções e exemplos a seguir mostram como capturar exceções e excluir.  Para obter mais informações sobre como **try**, **catch**, e as palavras\-chave de `throw` , consulte [Manipulação de exceção C\+\+](../cpp/cpp-exception-handling.md).  
  
 Os manipuladores de exceção deverá excluir objetos que manipulam exceção de, porque a falha ao excluir a exceção faz com que um vazamento de memória sempre que o código captura uma exceção.  
  
 O bloco de **catch** deve excluir uma exceção quando:  
  
-   O bloco de **catch** gerará uma nova exceção.  
  
     Naturalmente, você não deve excluir a exceção se você gerou a mesma exceção novamente:  
  
     [!code-cpp[NVC_MFCExceptions#3](../mfc/codesnippet/CPP/exceptions-catching-and-deleting-exceptions_1.cpp)]  
  
-   Retorna a execução de dentro do bloco de **catch** .  
  
> [!NOTE]
>  Ao excluir `CException`, use a função de membro de **Excluir** para excluir a exceção.  Não use a palavra\-chave de **delete** , pois pode falhar se a exceção não estiver no heap.  
  
#### Para capturar exceções e excluir  
  
1.  Use a palavra\-chave de **try** para configurar um bloco de **try** .  Executar todas as instruções de programa que possa gerar uma exceção dentro de um bloco de **try** .  
  
     Use a palavra\-chave de **catch** para configurar um bloco de **catch** .  Código de manipulação de exceções gerais de local em um bloco de **catch** .  O código no bloco de **catch** é executado apenas se o código dentro do bloco de **try** gerará uma exceção do tipo especificado na instrução de **catch** .  
  
     O esqueleto seguir mostra como **try** e blocos de **catch** são organizados normalmente:  
  
     [!code-cpp[NVC_MFCExceptions#4](../mfc/codesnippet/CPP/exceptions-catching-and-deleting-exceptions_2.cpp)]  
  
     Quando uma exceção é gerada, passa de controle ao primeiro bloco de **catch** cuja exceções gerais declaração corresponde ao tipo da exceção.  Você pode controlar seletivamente tipos diferentes de exceções com blocos sequenciais de **catch** como listados abaixo:  
  
     [!code-cpp[NVC_MFCExceptions#5](../mfc/codesnippet/CPP/exceptions-catching-and-deleting-exceptions_3.cpp)]  
  
 Para obter mais informações, consulte [Exceções: A conversão de macros de exceção MFC](../mfc/exceptions-converting-from-mfc-exception-macros.md).  
  
## Consulte também  
 [Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)