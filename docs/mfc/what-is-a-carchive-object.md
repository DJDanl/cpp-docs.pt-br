---
title: O que é um objeto CArchive
ms.date: 11/04/2016
helpviewer_keywords:
- archive objects [MFC]
- archives [MFC], for serialization
- buffers, serializable objects
- CArchive class [MFC], about CArchive class [MFC]
- buffering, serializable objects
ms.assetid: 843f1825-288d-4d89-a1fa-70e1f92d9b8b
ms.openlocfilehash: 0a78385c81c43a4b0c925bbe89ccd3937873ee8b
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79446024"
---
# <a name="what-is-a-carchive-object"></a>O que é um objeto CArchive

Um objeto `CArchive` fornece um mecanismo de buffer de tipo seguro para gravar ou ler objetos serializáveis de ou para um objeto `CFile`. Geralmente, o objeto `CFile` representa um arquivo de disco; no entanto, ele também pode ser um arquivo de memória (`CSharedFile` objeto), talvez representando a área de transferência.

Um determinado objeto `CArchive` armazena (grava, serializa) dados ou cargas (leituras, desserializa) dados, mas nunca ambos. A vida de um objeto de `CArchive` é limitada a um passo de gravação de objetos em um arquivo ou leitura de objetos de um arquivo. Assim, dois objetos `CArchive` criados sucessivamente são necessários para serializar dados em um arquivo e, em seguida, desserializá-los de volta do arquivo.

Quando um arquivo armazena objetos em um arquivo, o arquivo anexa o nome do `CRuntimeClass` aos objetos. Em seguida, quando outro arquivo carrega objetos de um arquivo para a memória, os objetos derivados de `CObject`são reconstruídos dinamicamente com base na `CRuntimeClass` dos objetos. Um determinado objeto pode ser referenciado mais de uma vez, pois ele é gravado no arquivo pelo arquivo de armazenamento. O arquivo de carregamento, no entanto, reconstruirá o objeto apenas uma vez. Os detalhes sobre como um arquivo anexa informações de `CRuntimeClass` a objetos e reconstrói objetos, levando em conta possíveis referências múltiplas, são descritos na [Observação técnica 2](../mfc/tn002-persistent-object-data-format.md).

Como os dados são serializados para um arquivo morto, o arquivo acumula os dados até que seu buffer esteja cheio. Em seguida, o arquivo morto grava seu buffer no objeto `CFile` apontado pelo objeto `CArchive`. Da mesma forma, à medida que você lê dados de um arquivo, ele lê dados do arquivo para seu buffer e, em seguida, do buffer para o objeto desserializado. Esse buffer reduz o número de vezes que um disco rígido é fisicamente lido, melhorando assim o desempenho do aplicativo.

## <a name="see-also"></a>Consulte também

[Serialização: serializando um objeto](../mfc/serialization-serializing-an-object.md)
