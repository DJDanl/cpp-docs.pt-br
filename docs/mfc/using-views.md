---
title: Usando exibições
ms.date: 11/04/2016
helpviewer_keywords:
- interacting with users and role of view class [MFC]
- drawing [MFC], data
- rendering data
- view classes [MFC], role in managing user interaction
- CView class [MFC], view architecture
- MFC, views
- views [MFC], using
- painting data
- user input [MFC], interpreting through view class [MFC]
- view classes [MFC], role in displaying application data
ms.assetid: dc3de6ad-5c64-4317-8f10-8bdcc38cdbd5
ms.openlocfilehash: 2038f2669d3aa8b5c4bf91b0ba0b38fbec9a1fc8
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50605693"
---
# <a name="using-views"></a>Usando exibições

Responsabilidades da exibição são para exibir os dados do documento graficamente para o usuário e aceitar e interpretar a entrada do usuário como operações no documento. Suas tarefas em escrever a classe de exibição são:

- Gravar sua classe de exibição [OnDraw](../mfc/reference/cview-class.md#ondraw) função de membro, que renderiza os dados do documento.

- Conecte-se as mensagens apropriadas do Windows e objetos de interface do usuário como itens de menu para funções de membro de manipulador de mensagens na classe de exibição.

- Implemente esses manipuladores para interpretar a entrada do usuário.

Além disso, talvez seja necessário substituir outros `CView` funções de membro em sua classe derivada de modo de exibição. Em particular, talvez você queira substituir [OnInitialUpdate](../mfc/reference/cview-class.md#oninitialupdate) para executar uma inicialização especial para o modo de exibição e [OnUpdate](../mfc/reference/cview-class.md#onupdate) fazer qualquer processamento especial necessário antes que o modo de exibição se redesenha. Para documentos de várias páginas, você também deve substituir [OnPreparePrinting](../mfc/reference/cview-class.md#onprepareprinting) para inicializar a caixa de diálogo de impressão com o número de páginas a serem impressas e outras informações. Para obter mais informações sobre substituição `CView` funções de membro, consulte a classe [CView](../mfc/reference/cview-class.md) no *referência da MFC*.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Classes de exibição derivadas disponíveis no MFC](../mfc/derived-view-classes-available-in-mfc.md)

- [Desenhando uma exibição](../mfc/drawing-in-a-view.md)

- [Interpretando a entrada do usuário por meio de um modo de exibição](../mfc/interpreting-user-input-through-a-view.md)

- [A função da exibição na impressão](../mfc/role-of-the-view-in-printing.md)

- [Rolando e colocando exibições em escala](../mfc/scrolling-and-scaling-views.md)

- [Inicializando e limpando documentos e exibições](../mfc/initializing-and-cleaning-up-documents-and-views.md)

## <a name="see-also"></a>Consulte também

[Arquitetura de documento/exibição](../mfc/document-view-architecture.md)<br/>
[Classe CFormView](../mfc/reference/cformview-class.md)<br/>
[Exibição de registro (Acesso a dados MFC)](../data/record-views-mfc-data-access.md)<br/>
[Fazendo bypass do mecanismo de serialização](../mfc/bypassing-the-serialization-mechanism.md)

