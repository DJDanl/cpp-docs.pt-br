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
ms.openlocfilehash: 3c92d60941cd6542bd0d6c27e8a879dc85e3a3d6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81377211"
---
# <a name="initializing-and-cleaning-up-documents-and-views"></a>Inicializando e limpando documentos e exibições

Use as seguintes diretrizes para inicializar e limpar após seus documentos e visualizações:

- O quadro do MFC inicializa documentos e visualizações; inicializar todos os dados que você adicionar a eles.

- A estrutura se limpa à medida que documentos e pontos de vista se fecham; você deve desalocar qualquer memória que você alocou no heap de dentro das funções de membro desses documentos e visualizações.

> [!NOTE]
> Lembre-se de que a inicialização de todo o aplicativo é melhor `CWinApp`feita em sua substituição da função de membro `CWinApp` [InitInstance](../mfc/reference/cwinapp-class.md#initinstance) da classe, e a limpeza para todo o aplicativo é melhor feita em sua substituição da função de membro [ExitInstance](../mfc/reference/cwinapp-class.md#exitinstance).

O ciclo de vida de um documento (e sua janela de quadro e exibição ou visualização) em um aplicativo MDI é o seguinte:

1. Durante a criação dinâmica, o construtor de documentos é chamado.

1. Para cada novo documento, o documento [onNewDocument](../mfc/reference/cdocument-class.md#onnewdocument) ou [OnOpenDocument](../mfc/reference/cdocument-class.md#onopendocument) é chamado.

1. O usuário interage com o documento durante toda a sua vida. Normalmente isso acontece à medida que o usuário trabalha com dados de documentos através da exibição, selecionando e editando os dados. A exibição passa alterações no documento para armazenamento e atualização de outras visualizações. Durante este tempo, tanto o documento quanto a exibição podem lidar com comandos.

1. A estrutura chama [DeleteContents](../mfc/reference/cdocument-class.md#deletecontents) para excluir dados específicos de um documento.

1. O destruidor do documento é chamado.

Em um aplicativo SDI, a etapa 1 é realizada uma vez, quando o documento é criado pela primeira vez. Em seguida, as etapas 2 a 4 são executadas repetidamente cada vez que um novo documento é aberto. O novo documento reutiliza o objeto de documento existente. Finalmente, a etapa 5 é realizada quando a aplicação termina.

## <a name="what-do-you-want-to-know-more-about"></a>O que você quer saber mais sobre

- [Inicializando documentos e exibições](../mfc/initializing-documents-and-views.md)

- [Limpando documentos e exibições](../mfc/cleaning-up-documents-and-views.md)

## <a name="see-also"></a>Confira também

[Arquitetura de documento/exibição](../mfc/document-view-architecture.md)
