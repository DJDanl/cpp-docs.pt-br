---
title: "O que é um objeto CArchive | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: CArchive
dev_langs: C++
helpviewer_keywords:
- archive objects [MFC]
- archives [MFC], for serialization
- buffers, serializable objects
- CArchive class [MFC], about CArchive class [MFC]
- buffering, serializable objects
ms.assetid: 843f1825-288d-4d89-a1fa-70e1f92d9b8b
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: cb9b0c3e24094deb0d4fd4ac20d673d9ffafca6d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="what-is-a-carchive-object"></a>O que é um objeto CArchive
Um `CArchive` objeto fornece um mecanismo de buffer de tipo seguro para gravar ou ler objetos serializáveis para ou de um `CFile` objeto. Geralmente o `CFile` objeto representa um arquivo de disco; no entanto, ele também pode ser um arquivo de memória (`CSharedFile` objeto), talvez que representa a área de transferência.  
  
 Um determinado `CArchive` qualquer um dos repositórios do objeto (grava, serializa) de dados ou carrega (lê, desserializa) dados, mas não ambos. A vida útil de um `CArchive` objeto é limitado a uma passagem pela gravar objetos em um arquivo ou ler objetos de um arquivo. Assim, dois sucessivamente criado `CArchive` objetos são necessários para serializar os dados em um arquivo e, em seguida, desserializá-la novamente a partir do arquivo.  
  
 Quando um arquivo morto armazena objetos em um arquivo, o arquivo morto anexa o `CRuntimeClass` nome aos objetos. Em seguida, quando outro carrega os objetos de um arquivo para a memória, o `CObject`-objetos derivados são reconstruídos dinamicamente com base no `CRuntimeClass` dos objetos. Um determinado objeto pode ser referenciado mais de uma vez que ele é gravado no arquivo, o arquivo de armazenamento. O arquivo de carregamento, no entanto, reconstruirá o objeto apenas uma vez. Os detalhes sobre como um arquivo morto anexa `CRuntimeClass` informações para objetos e reconstrói, levando em conta possíveis várias referências, são descritas em [técnica Observação 2](../mfc/tn002-persistent-object-data-format.md).  
  
 Como os dados são serializados para um arquivo, o arquivamento acumula os dados até que o buffer estiver cheio. Em seguida, o arquivo morto grava seu buffer para o `CFile` objeto apontada pelo `CArchive` objeto. Da mesma forma, como ler dados de um arquivo, ele lê dados do arquivo para o buffer e, em seguida, do buffer para o objeto desserializado. Esse buffer reduz o número de vezes que um disco rígido fisicamente é lida, o que melhora o desempenho do aplicativo.  
  
## <a name="see-also"></a>Consulte também  
 [Serialização: serializando um objeto](../mfc/serialization-serializing-an-object.md)

