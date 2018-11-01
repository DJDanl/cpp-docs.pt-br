---
title: 'Serialização: serializando um objeto'
ms.date: 11/04/2016
helpviewer_keywords:
- serializing objects [MFC]
- serialization [MFC], objects
- objects [MFC], serializing
ms.assetid: 1db772b1-ad55-4fcf-b133-126cca082510
ms.openlocfilehash: 10a7c52e6187f4db8345e1eadb88faeefa50b419
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50588510"
---
# <a name="serialization-serializing-an-object"></a>Serialização: serializando um objeto

O artigo [serialização: Criando uma classe serializável](../mfc/serialization-making-a-serializable-class.md) mostra como tornar uma classe serializável. Quando você tiver uma classe serializável, você pode serializar objetos dessa classe para e de um arquivo por meio de um [CArchive](../mfc/reference/carchive-class.md) objeto. Este artigo explica:

- [É o que um objeto CArchive](../mfc/what-is-a-carchive-object.md).

- [Duas maneiras de criar um CArchive](../mfc/two-ways-to-create-a-carchive-object.md).

- [Como usar o CArchive <\< e >> operadores](../mfc/using-the-carchive-output-and-input-operators.md).

- [Armazenando e carregando CObjects por meio de um arquivo morto](../mfc/storing-and-loading-cobjects-via-an-archive.md).

Você pode permitir que a estrutura de criar o arquivo morto do seu documento serializável ou criar explicitamente o `CArchive` objeto por conta própria. Você pode transferir dados entre um arquivo e seu objeto serializável por meio de <\< e >> operadores para `CArchive` ou, em alguns casos, chamando o `Serialize` a função de um `CObject`-classe derivada.

## <a name="see-also"></a>Consulte também

[Serialização](../mfc/serialization-in-mfc.md)

