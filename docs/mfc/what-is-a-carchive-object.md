---
title: "O que &#233; um objeto CArchive | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CArchive"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "objetos de arquivamento [C++]"
  - "arquivamentos [C++], para serialização"
  - "buffer, objetos que podem ser serializados"
  - "buffers, objetos que podem ser serializados"
  - "Classe CArchive, sobre classe CArchive"
ms.assetid: 843f1825-288d-4d89-a1fa-70e1f92d9b8b
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# O que &#233; um objeto CArchive
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um objeto de `CArchive` fornece um mecanismo fortemente tipado de proteção para gravar ou os objetos serializáveis ler a ou de `CFile` objeto.  Geralmente o objeto de `CFile` representa um arquivo de disco; no entanto, também pode ser um arquivo de memória \(objeto\) de`CSharedFile` , talvez representando a área de transferência.  
  
 Um determinado objeto de `CArchive` \(armazena as gravações, são serializados dados \(\) ou carrega as leituras, desserializa dados\), mas nunca ambos.  A vida de um objeto de `CArchive` é limitada a uma passagem de objetos de gravada em um arquivo ou objetos de leitura de um arquivo.  Assim, sucessivamente criados dois objetos de `CArchive` são necessários para serializar dados em um arquivo e desserializar os posteriores do arquivo.  
  
 Quando um arquivo morto armazena objetos em um arquivo, o arquivo morto anexar o nome de `CRuntimeClass` a objetos.  Então, quando outro arquivo morto carregar objetos de um arquivo para a memória, `CObject`\- os objetos derivadas são recriados dinamicamente com base em `CRuntimeClass` de objetos.  Um determinado objeto pode ser referenciado mais de uma vez como é gravado no arquivo do arquivo morto armazenando.  O arquivo morto de carga, porém, reconstruirá o objeto somente uma vez.  Detalhes sobre como anexar um arquivo morto informações de `CRuntimeClass` a objetos e recriar objetos, levando em consideração vários possíveis referências, são descritos em [Observação 2 técnica](../mfc/tn002-persistent-object-data-format.md).  
  
 à medida que os dados são serializados em um arquivo, o arquivo morto acumula os dados até que seu buffer seja concluída.  No arquivo morto grava seu buffer ao objeto de `CFile` apontado pelo objeto de `CArchive` .  De maneira semelhante, como você leia dados de um arquivo, ler dados do arquivo ao seu buffer e no buffer ao objeto desserializado.  Essa proteção reduz o número de vezes que um disco rígido é lido fisicamente, assim melhorar o desempenho de seu aplicativo.  
  
## Consulte também  
 [Serialização: serializando um objeto](../Topic/Serialization:%20Serializing%20an%20Object.md)