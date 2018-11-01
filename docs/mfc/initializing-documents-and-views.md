---
title: Inicializando documentos e exibições
ms.date: 11/04/2016
helpviewer_keywords:
- initializing documents [MFC]
- documents [MFC], initializing
- views [MFC], initializing
- initializing objects [MFC], document objects
- initializing views [MFC]
ms.assetid: 33cb8643-8a16-478c-bc26-eccc734e3661
ms.openlocfilehash: 2fb557d55576678d8c1199bec20e1fa4c849e1b4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50612245"
---
# <a name="initializing-documents-and-views"></a>Inicializando documentos e exibições

Documentos são criados de duas maneiras diferentes, portanto, sua classe de documento deve dar suporte a ambos os sentidos. Primeiro, o usuário pode criar um novo documento vazio com o comando novo arquivo. Nesse caso, inicializar o documento em seu substituto do [OnNewDocument](../mfc/reference/cdocument-class.md#onnewdocument) função de membro da classe [CDocument](../mfc/reference/cdocument-class.md). Em segundo lugar, o usuário pode usar o comando Abrir no menu arquivo para criar um novo documento cujo conteúdo é lido de um arquivo. Nesse caso, inicializar o documento em seu substituto do [OnOpenDocument](../mfc/reference/cdocument-class.md#onopendocument) função de membro da classe `CDocument`. Se ambas as inicializações são os mesmos, você pode chamar uma função de membro comum de ambas as substituições, ou `OnOpenDocument` pode chamar `OnNewDocument` para inicializar um documento limpo e, em seguida, concluir a operação de abertura.

Modos de exibição são criados após a criação de seus documentos. O melhor momento para inicializar um modo de exibição é depois que o framework terminar de criar o documento, a janela do quadro e a exibição. Você pode inicializar o modo de exibição, substituindo o [OnInitialUpdate](../mfc/reference/cview-class.md#oninitialupdate) função de membro [CView](../mfc/reference/cview-class.md). Se você precisar reinicializar ou ajustar qualquer coisa cada vez que as alterações de documento, você pode substituir [OnUpdate](../mfc/reference/cview-class.md#onupdate).

## <a name="see-also"></a>Consulte também

[Inicializando e limpando documentos e exibições](../mfc/initializing-and-cleaning-up-documents-and-views.md)

