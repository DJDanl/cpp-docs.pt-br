---
title: 'Serialização: Serializando um objeto | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- serializing objects [MFC]
- serialization [MFC], objects
- objects [MFC], serializing
ms.assetid: 1db772b1-ad55-4fcf-b133-126cca082510
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e05cce1132b180ac8f1350b68d951d776a62315f
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46381082"
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

