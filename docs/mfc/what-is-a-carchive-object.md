---
title: O que é um objeto CArchive
ms.date: 11/04/2016
f1_keywords:
- CArchive
helpviewer_keywords:
- archive objects [MFC]
- archives [MFC], for serialization
- buffers, serializable objects
- CArchive class [MFC], about CArchive class [MFC]
- buffering, serializable objects
ms.assetid: 843f1825-288d-4d89-a1fa-70e1f92d9b8b
ms.openlocfilehash: 4bae451168449ce3e120ba9d172a615864ac2157
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57270391"
---
# <a name="what-is-a-carchive-object"></a>O que é um objeto CArchive

Um `CArchive` objeto fornece um mecanismo de armazenamento em buffer de tipo seguro para gravar ou ler objetos serializáveis ou para um `CFile` objeto. Normalmente, o `CFile` objeto representa um arquivo de disco; no entanto, ele também pode ser um arquivo de memória (`CSharedFile` objeto), talvez que representa a área de transferência.

Uma determinada `CArchive` qualquer um dos repositórios do objeto (grava, serializa) dados ou cargas (lê, desserializa) dados, mas nunca a ambos. A vida útil de um `CArchive` objeto é limitado a uma passagem por gravar objetos em um arquivo ou ler objetos a partir de um arquivo. Dessa forma, dois sucessivamente criado `CArchive` objetos são necessários para serializar os dados em um arquivo e, em seguida, desserializá-lo a partir do arquivo.

Quando um arquivo morto armazena objetos em um arquivo, o arquivo morto anexa o `CRuntimeClass` nome aos objetos. Em seguida, quando outro arquivo carrega os objetos de um arquivo para a memória, o `CObject`-objetos derivados são dinamicamente reconstruídos com base no `CRuntimeClass` dos objetos. Um determinado objeto pode ser referenciado mais de uma vez, conforme eles são gravados no arquivo pelo arquivamento de armazenamento. O carregamento de arquivo, no entanto, será reconstruir o objeto apenas uma vez. Os detalhes sobre como um arquivo morto anexa `CRuntimeClass` informações para objetos e reconstrói, levando em conta possíveis várias referências, são descritas na [técnico Observação 2](../mfc/tn002-persistent-object-data-format.md).

Como os dados são serializados para um arquivo morto, o arquivo morto acumula os dados até que o buffer estiver cheio. Em seguida, o arquivo morto grava seu buffer para o `CFile` objeto apontado pelo `CArchive` objeto. Da mesma forma, conforme você lê dados de um arquivo, ele lê os dados do arquivo para o buffer e, em seguida, do buffer para o objeto desserializado. Esse buffer reduz o número de vezes que um disco rígido fisicamente é lido, o que melhora o desempenho do aplicativo.

## <a name="see-also"></a>Consulte também

[Serialização: Serializando um objeto](../mfc/serialization-serializing-an-object.md)
