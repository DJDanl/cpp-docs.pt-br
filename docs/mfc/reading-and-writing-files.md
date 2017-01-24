---
title: "Lendo e gravando arquivos | Microsoft Docs"
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
  - "Classe CFile, Objetos "
  - "Classe CFile, lendo e gravando objetos CFile"
  - "exemplos [MFC], lendo arquivos"
  - "exemplos [MFC], escrevendo em arquivos"
  - "Arquivos  [C++], lendo"
  - "Arquivos  [C++], gravando em"
  - "MFC [C++], operações de arquivo"
  - "lendo arquivos"
  - "escrevendo em arquivos [C++]"
ms.assetid: cac0c826-ba56-495f-99b3-ce6336f65763
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Lendo e gravando arquivos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se você usou as funções de manipulação arquivo de biblioteca de tempo de execução C, a leitura de MFC e as operações de gravação parecerão familiares.  Este artigo descreve diretamente de ler e gravar diretamente a um objeto de `CFile` .  Você também pode fazer o arquivo armazenado no buffer de E\/S com a classe de [CArchive](../mfc/reference/carchive-class.md) .  
  
#### Para ler e gravar no arquivo  
  
1.  Use as funções de membro de **Ler** e de **Gravar** para ler e gravar dados no arquivo.  
  
     \- ou \-  
  
2.  A função de membro de `Seek` também está disponível para ir para um deslocamento específico dentro do arquivo.  
  
 **Ler** usa um ponteiro para um buffer e o número de bytes a serem lidos e retorna o número real de bytes que foi lido.  Se o número de bytes exigido não pôde ser lido como participante \(EOF\) de Arquivo for atingido, o número real de bytes é retornado.  Se qualquer erro de leitura, ocorre uma exceção será lançada.  **Gravar** é semelhante a **Ler**, mas o número de bytes gravados não é retornado.  Se um ocorrerem erros, incluindo a gravação de todos os bytes especificado, será lançada uma exceção.  Se você tiver um objeto válido de `CFile` , você pode ler deles ser gravada nele conforme mostrado no seguinte exemplo:  
  
 [!code-cpp[NVC_MFCFiles#2](../mfc/codesnippet/CPP/reading-and-writing-files_1.cpp)]  
  
> [!NOTE]
>  Você normalmente deve realizar operações de entrada\/saída dentro de um bloco de manipulação de exceção de **try**\/**catch** .  Para obter mais informações, consulte [Manipulação de exceções \(MFC\)](../mfc/exception-handling-in-mfc.md).  
  
## Consulte também  
 [Arquivos](../mfc/files-in-mfc.md)