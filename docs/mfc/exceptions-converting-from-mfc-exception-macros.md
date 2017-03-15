---
title: "Exce&#231;&#245;es: convertendo a partir de macros de exce&#231;&#227;o MFC | Microsoft Docs"
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
  - "blocos catch, delimitando"
  - "Classe CException, excluindo objetos de classe CException"
  - "conversões, código gravado com macros MFC"
  - "convertendo exceções"
  - "tratamento de exceção, convertendo exceções"
  - "objetos de exceção"
  - "objetos de exceção, excluindo"
  - "exceções, convertendo"
  - "exceções, excluindo objetos de exceção"
  - "palavras-chave [C++], Macros "
  - "Macros , Palavras-chave em C++"
ms.assetid: bd3ac3b3-f3ce-4fdd-a168-a2cff13ed796
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Exce&#231;&#245;es: convertendo a partir de macros de exce&#231;&#227;o MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este é um tópico avançada.  
  
 Este artigo explica como converter o código existente gravado com macros da classe do Microsoft — **TRY**, **CATCH**, **THROW**, etc — para usar as palavras\-chave **try**, **catch**, e `throw`de controle de exceções das linguagens C\+\+.  Os tópicos incluem:  
  
-   [Vantagens de conversão](#_core_advantages_of_converting)  
  
-   [Convertendo o código com macros de exceção para usar exceções C\+\+](#_core_doing_the_conversion)  
  
##  <a name="_core_advantages_of_converting"></a> Vantagens de conversão  
 Você provavelmente não precisa converter o código existente, embora você deve estar ciente das diferenças entre as implementações macro na versão 3,0 do MFC e as implementações em versões anteriores.  Essas diferenças e as alterações subsequentes no comportamento do código são discutidas em [Exceções: Alterações em macros de exceção na versão 3,0](../mfc/exceptions-changes-to-exception-macros-in-version-3-0.md).  
  
 As principais vantagens de conversão são:  
  
-   O código que usa palavras\-chave de controle de exceções das linguagens C\+\+ compila a um .EXE ou a um .DLL ligeiramente menor.  
  
-   As palavras\-chave de controle de exceções das linguagens C\+\+ são mais versáteis: Podem tratar exceções de qualquer tipo de dados que podem ser copiadas \(`int`, **float**, `char`, e assim por diante\), enquanto que as macros controlam somente exceções da classe `CException` e das classes derivadas delas.  
  
 A principal diferença entre as macros e keywords é aquele código que usa macros “automaticamente” exclui uma exceção capturada quando a exceção sai do escopo.  O código que usa palavras\-chave não faz, assim você deve excluir explicitamente uma exceção capturada.  Para obter mais informações, consulte o artigo [Exceções: Capturando e excluindo exceções](../mfc/exceptions-catching-and-deleting-exceptions.md).  
  
 Outra diferença é sintaxe.  A sintaxe para macros e palavra\-chave difere em três aspectos:  
  
1.  Argumentos e declarações macro de exceção:  
  
     Uma invocação macro de **CATCH** tem a seguinte sintaxe:  
  
     *Exception\_class de* **CATCH\(**, *exception\_object\_pointer\_name* **\)**  
  
     Observe a vírgula entre o nome da classe e o nome do ponteiro do objeto.  
  
     A declaração de exceção para a palavra\-chave de **catch** usa esta sintaxe:  
  
     *exception\_name*  **\)** *de exception\_type*de**catch\(**  
  
     Essa instrução de declaração de exceção indica o tipo de exceção os identificadores do bloco de captura.  
  
2.  Delimitação de blocos de try\/catch:  
  
     Com macros, a macro de **CATCH** \(com seus argumentos\) inicia o primeiro bloco de captura; a macro de `AND_CATCH` inicia blocos subsequentes de captura, e a macro de `END_CATCH` finaliza a sequência de blocos de try\/catch.  
  
     Com as palavras\-chave, a palavra\-chave de **catch** \(com sua declaração de exceção\) inicia cada bloco de captura.  Não há nenhuma contraparte a macro de `END_CATCH` ; o bloco de captura termina com a chave de fechamento.  
  
3.  A expressão de lançamento:  
  
     Macros usam o novo lançamento de `THROW_LAST` a exceção atual.  A palavra\-chave de `throw` , sem o argumento, tem o mesmo efeito.  
  
##  <a name="_core_doing_the_conversion"></a> Para fazer a conversão  
  
#### Para converter o código usando macros para usar as palavras\-chave de controle de exceções das linguagens C\+\+  
  
1.  Localize todas as ocorrências de macros **TRY**, **CATCH**, `AND_CATCH`, `END_CATCH`, **THROW**, e `THROW_LAST`MFC.  
  
2.  Substituir ou excluir todas as ocorrências de macros seguintes:  
  
     **TRY** \(substitua pelo **try**\)  
  
     **CATCH** \(substitua pelo **catch**\)  
  
     `AND_CATCH` \(substitua pelo **catch**\)  
  
     `END_CATCH` \(excluir ele\)  
  
     **THROW** \(substitua pelo `throw`\)  
  
     `THROW_LAST` \(substitua pelo `throw`\)  
  
3.  Modifique os argumentos macro de modo que formem declarações válidos de exceção.  
  
     Por exemplo, alteração  
  
     [!code-cpp[NVC_MFCExceptions#6](../mfc/codesnippet/CPP/exceptions-converting-from-mfc-exception-macros_1.cpp)]  
  
     para  
  
     [!code-cpp[NVC_MFCExceptions#7](../mfc/codesnippet/CPP/exceptions-converting-from-mfc-exception-macros_2.cpp)]  
  
4.  Modifique o código em blocos de try\/catch de modo que exclui objetos de exceção conforme necessário.  Para obter mais informações, consulte o artigo [Exceções: Capturando e excluindo exceções](../mfc/exceptions-catching-and-deleting-exceptions.md).  
  
 Aqui está um exemplo do código de manipulação de exceções gerais usando macros de exceção MFC.  Observe que porque o código no exemplo a seguir usa macros, a exceção `e` será excluída automaticamente:  
  
 [!code-cpp[NVC_MFCExceptions#8](../mfc/codesnippet/CPP/exceptions-converting-from-mfc-exception-macros_3.cpp)]  
  
 O código no exemplo seguinte usa palavras\-chave de exceção C\+\+, a exceção deve ser explicitamente excluída:  
  
 [!code-cpp[NVC_MFCExceptions#9](../mfc/codesnippet/CPP/exceptions-converting-from-mfc-exception-macros_4.cpp)]  
  
 Para obter mais informações, consulte [Exceções: Usando macros de MFC e exceções C\+\+](../mfc/exceptions-using-mfc-macros-and-cpp-exceptions.md).  
  
## Consulte também  
 [Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)