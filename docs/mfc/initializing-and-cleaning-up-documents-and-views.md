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
ms.openlocfilehash: c5beed5618d4fa991160ad1688a5a686aeaa842f
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84626362"
---
# <a name="initializing-and-cleaning-up-documents-and-views"></a>Inicializando e limpando documentos e exibições

Use as seguintes diretrizes para inicializar e limpar após seus documentos e exibições:

- A estrutura MFC Inicializa documentos e exibições; você inicializa os dados adicionados a eles.

- A estrutura limpa à medida que os documentos e as exibições são fechados; Você deve desalocar qualquer memória alocada no heap de dentro das funções de membro desses documentos e exibições.

> [!NOTE]
> Lembre-se de que a inicialização para todo o aplicativo é melhor feita na substituição da função de membro [InitInstance](reference/cwinapp-class.md#initinstance) da classe `CWinApp` , e a limpeza de todo o aplicativo é melhor feita na substituição da `CWinApp` função membro [ExitInstance](reference/cwinapp-class.md#exitinstance).

O ciclo de vida de um documento (e sua janela de quadro e exibição ou exibições) em um aplicativo MDI é o seguinte:

1. Durante a criação dinâmica, o construtor do documento é chamado.

1. Para cada novo documento, o [OnNewDocument](reference/cdocument-class.md#onnewdocument) ou [OnOpenDocument](reference/cdocument-class.md#onopendocument) do documento é chamado.

1. O usuário interage com o documento durante todo o seu tempo de vida. Normalmente, isso ocorre quando o usuário trabalha em dados de documento por meio da exibição, selecionando e editando os dados. A exibição passa as alterações no documento para armazenamento e atualização de outras exibições. Durante esse tempo, o documento e a exibição podem manipular comandos.

1. A estrutura chama [DeleteContents](reference/cdocument-class.md#deletecontents) para excluir dados específicos de um documento.

1. O destruidor do documento é chamado.

Em um aplicativo SDI, a etapa 1 é executada uma vez, quando o documento é criado pela primeira vez. Em seguida, as etapas de 2 a 4 são executadas repetidamente cada vez que um novo documento é aberto. O novo documento reutiliza o objeto de documento existente. Por fim, a etapa 5 é executada quando o aplicativo termina.

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Inicializando documentos e exibições](initializing-documents-and-views.md)

- [Limpando documentos e exibições](cleaning-up-documents-and-views.md)

## <a name="see-also"></a>Consulte também

[Arquitetura de documento/exibição](document-view-architecture.md)
