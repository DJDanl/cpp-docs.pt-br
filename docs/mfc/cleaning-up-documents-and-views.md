---
title: Limpando documentos e exibições | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- views [MFC], cleaning up
- documents [MFC], cleaning up
- documents [MFC], closing
ms.assetid: 0c454db2-3644-434d-9e53-8108a7aedfe1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2dfe54c13db6f44bc70289380ae5f50d99c3722b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33341320"
---
# <a name="cleaning-up-documents-and-views"></a>Limpando documentos e exibições
Quando um documento está sendo fechado, o framework chama primeiro seu [DeleteContents](../mfc/reference/cdocument-class.md#deletecontents) função de membro. Se você tiver atribuído qualquer memória heap durante o curso de operação do documento, `DeleteContents` é o melhor lugar para desalocar a ele.  
  
> [!NOTE]
>  Você não deve ser desalocada dados de documento no destruidor do documento. No caso de um aplicativo SDI, o objeto de documento poderá ser reutilizado.  
  
 Você pode substituir o destruidor de uma exibição para desalocar toda a memória alocada no heap.  
  
## <a name="see-also"></a>Consulte também  
 [Inicializando e limpando documentos e exibições](../mfc/initializing-and-cleaning-up-documents-and-views.md)

