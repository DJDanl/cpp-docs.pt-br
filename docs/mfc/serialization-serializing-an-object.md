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
ms.openlocfilehash: 3439857f14f4c4fa78aa2df3e3da8e5c8941938d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33379652"
---
# <a name="serialization-serializing-an-object"></a>Serialização: serializando um objeto
O artigo [serialização: Criando uma classe serializável](../mfc/serialization-making-a-serializable-class.md) mostra como tornar uma classe serializável. Uma vez que uma classe serializável, você pode serializar objetos dessa classe para e de um arquivo por meio de um [CArchive](../mfc/reference/carchive-class.md) objeto. Este artigo explica:  
  
-   [É o que um objeto CArchive](../mfc/what-is-a-carchive-object.md).  
  
-   [Duas maneiras de criar um CArchive](../mfc/two-ways-to-create-a-carchive-object.md).  
  
-   [Como usar o CArchive <\< e >> operadores](../mfc/using-the-carchive-output-and-input-operators.md).  
  
-   [Armazenando e carregando CObjects por meio de um arquivo morto](../mfc/storing-and-loading-cobjects-via-an-archive.md).  
  
 Você pode permitir que a estrutura de criar o arquivo do seu documento serializável ou criar explicitamente o `CArchive` objeto por conta própria. Você pode transferir dados entre um arquivo e seu objeto serializável usando o <\< e >> operadores para `CArchive` ou, em alguns casos, chamando o `Serialize` a função de um `CObject`-classe derivada.  
  
## <a name="see-also"></a>Consulte também  
 [Serialização](../mfc/serialization-in-mfc.md)

