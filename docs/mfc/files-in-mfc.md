---
title: "Arquivos no MFC | Microsoft Docs"
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
  - "acesso binário"
  - "acesso binário, extensões de arquivo binário em MFC"
  - "Classes de E/S de arquivo [C++]"
  - "Arquivos  [C++], manipulando"
  - "Arquivos  [C++], MFC"
  - "Arquivos  [C++], serialização"
  - "E/S [C++], Classes MFC"
  - "E/S [MFC]"
  - "MFC [C++], operações de arquivo"
  - "persistência [C++]"
  - "serialização [C++], arquivos MFC"
ms.assetid: ae25e2c5-2859-4679-ab97-438824e93ce1
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Arquivos no MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Na biblioteca de classes do Microsoft \(MFC\), a classe [CFile](../mfc/reference/cfile-class.md) trata as operações de E\/S de arquivos normais.  Esta família de artigos explica como abrir e fechar arquivos bem como ler e gravar dados 2 esses arquivos.  Também discute operações de status do arquivo.  Para obter uma descrição de como usar os recursos de objetos baseados de serialização MFC como uma maneira alternativa de dados de leitura e gravação em arquivos, consulte o artigo [Serialização](../Topic/Serialization%20in%20MFC.md).  
  
> [!NOTE]
>  Quando você usa objetos de MFC **CDocument** , a estrutura usa muito de trabalho de serialização para você.  Em particular, a estrutura cria e usa o objeto de `CFile` .  Você só precisa escrever o código na sua substituição da função de membro de `Serialize` da classe **CDocument**.  
  
 A classe de `CFile` fornece uma interface para operações de arquivo binário.  As classes de `CStdioFile` e de `CMemFile` derivadas de `CFile` e a classe de `CSharedFile` derivada de `CMemFile` fornecem serviços de arquivo mais qualificados.  
  
 Para obter mais informações sobre alternativas a manipulação de arquivo MFC, consulte [Tratamento de Arquivo](../c-runtime-library/file-handling.md)*na referência da biblioteca de tempo de execução*.  
  
 Para obter mais informações sobre classes derivadas de `CFile` , consulte [Gráfico da hierarquia de MFC](../mfc/hierarchy-chart.md).  
  
## O que você deseja fazer?  
 *Use o CFile*  
  
-   [Abrir um arquivo com CFile](../Topic/Opening%20Files.md)  
  
-   [Lê e grava um arquivo com CFile](../mfc/reading-and-writing-files.md)  
  
-   [Fechar um arquivo com CFile](../mfc/closing-files.md)  
  
-   [Acessar o status de arquivo com CFile](../mfc/accessing-file-status.md)  
  
 *Use a serialização \(MFC a persistência de objeto\)*  
  
-   [Crie uma classe serializável](../mfc/serialization-making-a-serializable-class.md)  
  
-   [Serializar um objeto por meio de um objeto de CArchive](../Topic/Serialization:%20Serializing%20an%20Object.md)  
  
-   [Crie um objeto de CArchive](../mfc/two-ways-to-create-a-carchive-object.md)  
  
-   [Use CArchive \<\< e \>\> operadores](../mfc/using-the-carchive-output-and-input-operators.md)  
  
-   [Armazenar e carregar CObjects e objetos CObject\- derivados por meio de um arquivo morto](../Topic/Storing%20and%20Loading%20CObjects%20via%20an%20Archive.md)  
  
## Consulte também  
 [Conceitos](../mfc/mfc-concepts.md)   
 [Tópicos MFC gerais](../mfc/general-mfc-topics.md)   
 [Classe de CArchive](../mfc/reference/carchive-class.md)   
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Como fazer: Use a classe de CFile?](http://go.microsoft.com/fwlink/?LinkId=128046)