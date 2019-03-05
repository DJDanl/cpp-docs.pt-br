---
title: Classes de arquitetura do aplicativo MFC
ms.date: 11/04/2016
f1_keywords:
- vc.classes.mfc
helpviewer_keywords:
- MFC, classes
- MFC, application development
- classes [MFC], MFC
- application architecture classes [MFC]
ms.assetid: 71b2de54-b44d-407e-9c71-9baf954e18d9
ms.openlocfilehash: 47feeb056d02b81bb88ccf3c5fd49bc983583ee7
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57277593"
---
# <a name="mfc-application-architecture-classes"></a>Classes de arquitetura do aplicativo MFC

Classes nessa categoria contribuem para a arquitetura de um aplicativo do framework. Eles fornecem funcionalidade comum à maioria dos aplicativos. Preencha a estrutura para adicionar funcionalidade específica do aplicativo. Normalmente, você faz isso por derivar novas classes de classes de arquitetura e, em seguida, adicionar novos membros ou substituindo as funções de membro existente.

[Assistentes de aplicativo](../mfc/reference/mfc-application-wizard.md) gerar vários tipos de aplicativos, todos os que usam a estrutura de aplicativo de maneiras diferentes. SDI (interface de documento único) e aplicativos MDI (interface de documentos múltiplos) fazem uso integral de uma parte do framework chamado arquitetura de documento/exibição. Outros tipos de aplicativos, como aplicativos baseados na caixa de diálogo, aplicativos baseados em formulário e DLLs, usam apenas alguns dos recursos de arquitetura de documento/exibição.

Aplicativos de documento/exibição contêm um ou mais conjuntos de documentos, exibições e janelas de quadro. Um objeto de modelo de documento associa as classes para cada conjunto de documento/exibição/quadro.

Embora você não precisa usar a arquitetura de documento/exibição em seu aplicativo do MFC, há uma série de vantagens fazê-lo. O OLE do MFC contêiner e o servidor de suporte é baseado em arquitetura de documento/exibição, como suporte para impressão e visualização de impressão.

Todos os aplicativos do MFC tem pelo menos dois objetos: um objeto de aplicativo derivado [CWinApp](../mfc/reference/cwinapp-class.md)e algum tipo de objeto de janela principal, (geralmente indiretamente) derivado de [CWnd](../mfc/reference/cwnd-class.md). (Geralmente, a janela principal é derivada de [CFrameWnd](../mfc/reference/cframewnd-class.md), [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md), ou [CDialog](../mfc/reference/cdialog-class.md), que são derivados de `CWnd`.)

Aplicativos que usam a arquitetura de documento/exibição contêm os objetos adicionais. Os objetos de entidade de segurança são:

- Um objeto de aplicativo derivada da classe [CWinApp](../mfc/reference/cwinapp-class.md), conforme mencionado anteriormente.

- Um ou mais objetos de classe de documento é derivada da classe [CDocument](../mfc/reference/cdocument-class.md). Objetos de classe de documento são responsáveis pela representação interna dos dados manipulados no modo de exibição. Eles podem estar associados um arquivo de dados.

- Um ou mais objetos de exibição é derivado da classe [CView](../mfc/reference/cview-class.md). Cada modo de exibição é uma janela que é anexada a um documento e associada a uma janela do quadro. Exibições de exibem e manipulam os dados contidos em um objeto de classe de documento.

Aplicativos de documento/exibição também contêm janelas com moldura (derivado de [CFrameWnd](../mfc/reference/cframewnd-class.md)) e modelos de documento (derivado de [CDocTemplate](../mfc/reference/cdoctemplate-class.md)).

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)
