---
title: Criando janelas com moldura de documento
ms.date: 11/04/2016
helpviewer_keywords:
- frame windows [MFC], creating
- document templates [MFC], and document frame windows
- windows [MFC], creating
- runtime, class information
- run-time class [MFC], and document frame window creation
- document frame windows [MFC], creating
- MFC, frame windows
ms.assetid: 8671e239-b76f-4dea-afa8-7024e6e58ff5
ms.openlocfilehash: e15a2a6bc016bf23bc0decf529b4c3ffeecc3a4c
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84621954"
---
# <a name="creating-document-frame-windows"></a>Criando janelas com moldura de documento

A [criação de documento/exibição](document-view-creation.md) mostra como o objeto [CDocTemplate](reference/cdoctemplate-class.md) orquestra a criação da janela do quadro, do documento e da exibição e da conexão. Três argumentos [CRuntimeClass](reference/cruntimeclass-structure.md) para o `CDocTemplate` Construtor especificam a janela do quadro, o documento e as classes de exibição que o modelo de documento cria dinamicamente em resposta aos comandos do usuário, como o novo comando no menu arquivo ou o comando nova janela em um menu de janela MDI. O modelo de documento armazena essas informações para uso posterior ao criar uma janela de quadro para uma exibição e um documento.

Para que o mecanismo de [RUNTIME_CLASS](reference/run-time-object-model-services.md#runtime_class) funcione corretamente, suas classes de janela de quadro derivadas devem ser declaradas com a macro [DECLARE_DYNCREATE](reference/run-time-object-model-services.md#declare_dyncreate) . Isso ocorre porque a estrutura precisa criar janelas de quadros de documentos usando o mecanismo de construção dinâmico da classe `CObject` .

Quando o usuário escolhe um comando que cria um documento, a estrutura chama o modelo de documento para criar o objeto de documento, sua exibição e a janela do quadro que exibirá a exibição. Quando ele cria a janela de quadro do documento, o modelo de documento cria um objeto da classe apropriada — uma classe derivada de [CFrameWnd](reference/cframewnd-class.md) para um aplicativo SDI ou de [CMDIChildWnd](reference/cmdichildwnd-class.md) para um aplicativo MDI. Em seguida, a estrutura chama a função de membro [LoadFrame](reference/cframewnd-class.md#loadframe) do objeto de janela do quadro para obter informações de criação de recursos e para criar a janela do Windows. A estrutura anexa o identificador de janela ao objeto quadro-janela. Em seguida, ele cria a exibição como uma janela filho da janela do quadro do documento.

Tome cuidado ao decidir [quando inicializar](when-to-initialize-cwnd-objects.md) o `CWnd` objeto derivado.

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Derivando uma classe de CObject (seu mecanismo de criação dinâmico)](deriving-a-class-from-cobject.md)

- [Criação de documento/exibição (modelos e criação de janela de quadro)](document-view-creation.md)

- [Destruindo janelas com moldura](destroying-frame-windows.md)

## <a name="see-also"></a>Consulte também

[Usando janelas de quadros](using-frame-windows.md)
