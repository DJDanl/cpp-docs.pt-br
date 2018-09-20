---
title: Criando o documento quadro Windows | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- frame windows [MFC], creating
- document templates [MFC], and document frame windows
- windows [MFC], creating
- runtime, class information
- run-time class [MFC], and document frame window creation
- document frame windows [MFC], creating
- MFC, frame windows
ms.assetid: 8671e239-b76f-4dea-afa8-7024e6e58ff5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 172076113a6bd7e223d99c238d0e05987cdcaae6
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46433681"
---
# <a name="creating-document-frame-windows"></a>Criando janelas com moldura de documento

[Criação de documento/exibição](../mfc/document-view-creation.md) mostra como o [CDocTemplate](../mfc/reference/cdoctemplate-class.md) objeto orquestra criando a janela do quadro, o documento e o modo de exibição e conectá-los juntos. Três [CRuntimeClass](../mfc/reference/cruntimeclass-structure.md) argumentos para o `CDocTemplate` construtor especifique a janela do quadro, documento e as classes de exibição do modelo de documento cria dinamicamente em resposta a comandos do usuário, como o novo comando no arquivo menu ou o comando nova janela no menu de uma janela MDI. O modelo de documento armazena essas informações para uso posterior quando ele cria uma janela do quadro para um modo de exibição e o documento.

Para o [RUNTIME_CLASS](../mfc/reference/run-time-object-model-services.md#runtime_class) mecanismo para funcionar corretamente, seu derivado classes de janela de quadro devem ser declaradas com o [DECLARE_DYNCREATE](../mfc/reference/run-time-object-model-services.md#declare_dyncreate) macro. Isso ocorre porque o framework precisa criar janelas de quadro usando o mecanismo dinâmico de construção da classe de documento `CObject`.

Quando o usuário escolhe um comando que cria um documento, o framework chama o modelo de documento para criar o objeto de documento, seu modo de exibição e a janela do quadro que exibirá o modo de exibição. Quando ele cria a janela de quadro do documento, o modelo de documento cria um objeto da classe apropriada — uma classe derivada de [CFrameWnd](../mfc/reference/cframewnd-class.md) para um aplicativo SDI ou da [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md) para um MDI aplicativo. A estrutura, em seguida, chama o objeto de janela com moldura [LoadFrame](../mfc/reference/cframewnd-class.md#loadframe) função de membro para obter informações de criação de recursos e criar a janela do Windows. O framework anexa o identificador de janela para o objeto de janela do quadro. Em seguida, ele cria a exibição como uma janela filho da janela de quadro do documento.

Tome cuidado ao decidir [quando inicializar](../mfc/when-to-initialize-cwnd-objects.md) seu `CWnd`-objeto derivado.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Derivando uma classe de CObject (seu mecanismo de criação dinâmica)](../mfc/deriving-a-class-from-cobject.md)

- [Criação de documento/exibição (modelos e criação de janelas de quadro)](../mfc/document-view-creation.md)

- [Destruindo janelas com moldura](../mfc/destroying-frame-windows.md)

## <a name="see-also"></a>Consulte também

[Usando janelas com moldura](../mfc/using-frame-windows.md)

