---
title: "Limpando documentos e exibições | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- views [MFC], cleaning up
- documents [MFC], cleaning up
- documents [MFC], closing
ms.assetid: 0c454db2-3644-434d-9e53-8108a7aedfe1
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6a95193d5ca3df890c9c97f458b76413e588bc59
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cleaning-up-documents-and-views"></a>Limpando documentos e exibições
Quando um documento está sendo fechado, o framework chama primeiro seu [DeleteContents](../mfc/reference/cdocument-class.md#deletecontents) função de membro. Se você tiver atribuído qualquer memória heap durante o curso de operação do documento, `DeleteContents` é o melhor lugar para desalocar a ele.  
  
> [!NOTE]
>  Você não deve ser desalocada dados de documento no destruidor do documento. No caso de um aplicativo SDI, o objeto de documento poderá ser reutilizado.  
  
 Você pode substituir o destruidor de uma exibição para desalocar toda a memória alocada no heap.  
  
## <a name="see-also"></a>Consulte também  
 [Inicializando e limpando documentos e exibições](../mfc/initializing-and-cleaning-up-documents-and-views.md)

