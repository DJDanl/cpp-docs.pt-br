---
title: "Serialização: Serializando um objeto | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- serializing objects [MFC]
- serialization [MFC], objects
- objects [MFC], serializing
ms.assetid: 1db772b1-ad55-4fcf-b133-126cca082510
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 37e688a3619cd203e61997999a9b7eb7651d73fc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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

