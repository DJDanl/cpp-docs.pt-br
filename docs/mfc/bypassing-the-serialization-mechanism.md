---
title: "Fazendo bypass do mecanismo de serializa&#231;&#227;o | Microsoft Docs"
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
  - "objetos de arquivamento [C++]"
  - "arquivamentos [C++]"
  - "arquivamentos [C++], serialização"
  - "ignorando a serialização"
  - "serialização [C++], ignorando"
  - "serialização [C++], substituição"
  - "serialização [C++], função da estrutura"
ms.assetid: 48d4a279-b51c-4ba5-81cd-ed043312b582
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fazendo bypass do mecanismo de serializa&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você viu como, a estrutura fornece uma maneira padrão de ler e gravar dados em e arquivos.  Serializar por meio de um objeto de arquivo morto atenda às necessidades de um grande muitos aplicativos.  Esse aplicativo lê um arquivo completamente na memória, permite que o usuário atualizar o arquivo e, em seguida a versão atualizada em disco novamente.  
  
 No entanto, alguns aplicativos funcionam em dados de forma muito diferente e, para esses aplicativos a serialização meio de um arquivo morto não é adequada.  Os exemplos incluem programas da base de dados, os programas que editam somente as partes de arquivos grandes, os programas que gravam arquivos de texto somente leitura, e os programas que compartilham arquivos de dados.  
  
 Nesses casos, você pode substituir a função de [Serializar](../Topic/CObject::Serialize.md) de uma maneira diferente para negociar ações de arquivo por meio de um objeto de [CFile](../mfc/reference/cfile-class.md) em vez de um objeto de [CArchive](../mfc/reference/carchive-class.md) .  
  
 Você pode usar **Abrir**, **Ler**, **Gravar**, **Fechar**, e as funções de membro de `Seek` da classe `CFile` para abrir um arquivo, para mover o ponteiro de arquivo \(pesquisa\) até um ponto específico no arquivo, ler um registro \(um número especificado de bytes\) nesse ponto, deixa o usuário atualizar o registro, então buscar\-lo no mesmo point\-in\-time novamente e redigem\-no o registro de volta ao arquivo.  A estrutura abrir o arquivo para você, e você pode usar a função de membro de `GetFile` da classe `CArchive` para obter um ponteiro para o objeto de `CFile` .  Para uso ainda mais sofisticado e flexível, você pode substituir as funções de membro de [OnOpenDocument](../Topic/CDocument::OnOpenDocument.md) e de [OnSaveDocument](../Topic/CDocument::OnSaveDocument.md) da classe `CWinApp`.  Classe de [CFile](../mfc/reference/cfile-class.md) Para obter mais informações, consulte *na referência de MFC*.  
  
 Neste cenário, a substituição de `Serialize` não fará nada, a menos que, por exemplo, se você desejar solicitar ler e gravar um cabeçalho de arquivo para mantê\-lo atualizado quando o documento é encerrada.  
  
## Consulte também  
 [Usando documentos](../mfc/using-documents.md)