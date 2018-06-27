---
title: Inicializando documentos e exibições | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- initializing documents [MFC]
- documents [MFC], initializing
- views [MFC], initializing
- initializing objects [MFC], document objects
- initializing views [MFC]
ms.assetid: 33cb8643-8a16-478c-bc26-eccc734e3661
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 43610a08d5a3713cc40de0a2279286735a27d1da
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36928176"
---
# <a name="initializing-documents-and-views"></a>Inicializando documentos e exibições
Os documentos são criados de duas maneiras diferentes, para que sua classe de documento deve oferecer suporte a ambos os modos. Primeiro, o usuário pode criar um documento novo e vazio com o comando novo arquivo. Nesse caso, inicializar o documento em sua substituição do [OnNewDocument](../mfc/reference/cdocument-class.md#onnewdocument) função de membro de classe [CDocument](../mfc/reference/cdocument-class.md). Segundo, o usuário pode usar o comando Abrir no menu arquivo para criar um novo documento cujo conteúdo é lido de um arquivo. Nesse caso, inicializar o documento em sua substituição do [OnOpenDocument](../mfc/reference/cdocument-class.md#onopendocument) função de membro de classe `CDocument`. Se ambas as inicializações são os mesmos, você pode chamar uma função de membro comum de ambas as substituições ou `OnOpenDocument` pode chamar `OnNewDocument` para inicializar um documento limpo e, em seguida, concluir a operação de abertura.  
  
 Modos de exibição são criados após a criação de seus documentos. O melhor momento para inicializar uma exibição é depois que a estrutura acabou de criar o documento, a janela do quadro e a exibição. Você pode inicializar o modo de exibição, substituindo o [OnInitialUpdate](../mfc/reference/cview-class.md#oninitialupdate) função membro de [CView](../mfc/reference/cview-class.md). Se você precisar reinicializar ou ajustar qualquer coisa sempre que as alterações de documento, você pode substituir [OnUpdate](../mfc/reference/cview-class.md#onupdate).  
  
## <a name="see-also"></a>Consulte também  
 [Inicializando e limpando documentos e exibições](../mfc/initializing-and-cleaning-up-documents-and-views.md)

