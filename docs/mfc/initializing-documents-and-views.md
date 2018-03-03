---
title: "Inicializando documentos e exibições | Microsoft Docs"
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
- initializing documents [MFC]
- documents [MFC], initializing
- views [MFC], initializing
- initializing objects [MFC], document objects
- initializing views [MFC]
ms.assetid: 33cb8643-8a16-478c-bc26-eccc734e3661
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f80d870f9804454dc652fdda00f34fcdb7a52062
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="initializing-documents-and-views"></a>Inicializando documentos e exibições
Os documentos são criados de duas maneiras diferentes, para que sua classe de documento deve oferecer suporte a ambos os modos. Primeiro, o usuário pode criar um documento novo e vazio com o comando novo arquivo. Nesse caso, inicializar o documento em sua substituição do [OnNewDocument](../mfc/reference/cdocument-class.md#onnewdocument) função de membro de classe [CDocument](../mfc/reference/cdocument-class.md). Segundo, o usuário pode usar o comando Abrir no menu arquivo para criar um novo documento cujo conteúdo é lido de um arquivo. Nesse caso, inicializar o documento em sua substituição do [OnOpenDocument](../mfc/reference/cdocument-class.md#onopendocument) função de membro de classe **CDocument**. Se ambas as inicializações são os mesmos, você pode chamar uma função de membro comum de ambas as substituições ou `OnOpenDocument` pode chamar `OnNewDocument` para inicializar um documento limpo e, em seguida, concluir a operação de abertura.  
  
 Modos de exibição são criados após a criação de seus documentos. O melhor momento para inicializar uma exibição é depois que a estrutura acabou de criar o documento, a janela do quadro e a exibição. Você pode inicializar o modo de exibição, substituindo o [OnInitialUpdate](../mfc/reference/cview-class.md#oninitialupdate) função membro de [CView](../mfc/reference/cview-class.md). Se você precisar reinicializar ou ajustar qualquer coisa sempre que as alterações de documento, você pode substituir [OnUpdate](../mfc/reference/cview-class.md#onupdate).  
  
## <a name="see-also"></a>Consulte também  
 [Inicializando e limpando documentos e exibições](../mfc/initializing-and-cleaning-up-documents-and-views.md)

