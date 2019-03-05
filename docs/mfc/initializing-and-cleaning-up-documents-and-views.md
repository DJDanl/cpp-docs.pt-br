---
title: Inicializando e limpando documentos e exibições
ms.date: 11/04/2016
helpviewer_keywords:
- initializing documents [MFC]
- views [MFC], cleaning up
- documents [MFC], initializing
- documents [MFC], cleaning up
- views [MFC], initializing
- initializing objects [MFC], document objects
- document objects [MFC], life cycle of
- initializing views [MFC]
ms.assetid: 95d6f09b-a047-4079-856a-ae7d0548e9d2
ms.openlocfilehash: 59e86f4000e2da588749ca48887d34c3effdfc3a
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57286841"
---
# <a name="initializing-and-cleaning-up-documents-and-views"></a>Inicializando e limpando documentos e exibições

Use as seguintes diretrizes para Inicializando e limpando após seus documentos e exibições:

- Estrutura MFC inicializa documentos e exibições; você inicializa quaisquer dados que você adicionar a eles.

- A estrutura limpa como documentos e exibições fechar; Você deverá desalocar qualquer memória alocada no heap de dentro das funções de membro desses documentos e exibições.

> [!NOTE]
>  Lembre-se de que a inicialização para todo o aplicativo é mais bem efetuado em seu substituto do [InitInstance](../mfc/reference/cwinapp-class.md#initinstance) função de membro da classe `CWinApp`, e a limpeza de todo o aplicativo é mais bem efetuada em seu substituto do `CWinApp`função de membro [ExitInstance](../mfc/reference/cwinapp-class.md#exitinstance).

Ciclo de vida de um documento (e sua janela de quadro e modo de exibição ou exibições) em um MDI aplicativo é o seguinte:

1. Durante a criação dinâmica, o construtor de documento é chamado.

1. Para da cada novo documento, o documento [OnNewDocument](../mfc/reference/cdocument-class.md#onnewdocument) ou [OnOpenDocument](../mfc/reference/cdocument-class.md#onopendocument) é chamado.

1. O usuário interage com o documento em todo seu ciclo de vida. Normalmente, isso acontece conforme o usuário trabalha nos dados de documento por meio da exibição, selecionar e editar os dados. O modo de exibição passa as alterações para o documento para o armazenamento e atualizando a outros modos de exibição. Durante esse tempo, o documento e o modo de exibição podem lidar com comandos.

1. A estrutura chama [DeleteContents](../mfc/reference/cdocument-class.md#deletecontents) para excluir dados específicos a um documento.

1. Destruidor do documento é chamado.

Em um aplicativo SDI, etapa 1 é executada uma vez, quando o documento é criado. Em seguida, as etapas 2 a 4 são executadas várias vezes sempre que um novo documento for aberto. O novo documento reutiliza o objeto de documento existente. Por fim, a etapa 5 é executada quando o aplicativo termina.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Inicializando documentos e exibições](../mfc/initializing-documents-and-views.md)

- [Limpando documentos e exibições](../mfc/cleaning-up-documents-and-views.md)

## <a name="see-also"></a>Consulte também

[Arquitetura de documento/exibição](../mfc/document-view-architecture.md)
