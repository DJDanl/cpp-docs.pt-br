---
title: Classes de arquitetura do aplicativo MFC
ms.date: 11/04/2016
helpviewer_keywords:
- MFC, classes
- MFC, application development
- classes [MFC], MFC
- application architecture classes [MFC]
ms.assetid: 71b2de54-b44d-407e-9c71-9baf954e18d9
ms.openlocfilehash: 455a49a4f93f2fb2590447071edca76a32cbc5dd
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84618029"
---
# <a name="mfc-application-architecture-classes"></a>Classes de arquitetura do aplicativo MFC

As classes nessa categoria contribuem para a arquitetura de um aplicativo do Framework. Eles fornecem funcionalidade comum para a maioria dos aplicativos. Você preenche a estrutura para adicionar funcionalidade específica do aplicativo. Normalmente, você faz isso derivando novas classes das classes de arquitetura e, em seguida, adicionando novos membros ou substituindo funções de membro existentes.

Os [assistentes de aplicativo](reference/mfc-application-wizard.md) geram vários tipos de aplicativos, que usam a estrutura do aplicativo de maneiras diferentes. Os aplicativos SDI (interface de documento único) e MDI fazem uso completo de uma parte da estrutura denominada arquitetura de documento/exibição. Outros tipos de aplicativos, como aplicativos baseados em caixa de diálogo, aplicativos baseados em formulário e DLLs, usam apenas alguns recursos de arquitetura de documento/exibição.

Os aplicativos de documento/exibição contêm um ou mais conjuntos de documentos, exibições e janelas de quadros. Um objeto de modelo de documento associa as classes para cada conjunto de documentos/exibição/quadro.

Embora você não precise usar a arquitetura de documento/exibição em seu aplicativo MFC, há uma série de vantagens para fazer isso. O suporte ao contêiner OLE do MFC e ao servidor baseia-se na arquitetura de documento/exibição, assim como o suporte para impressão e visualização de impressão.

Todos os aplicativos MFC têm pelo menos dois objetos: um objeto de aplicativo derivado de [CWinApp](reference/cwinapp-class.md)e algum tipo de objeto de janela principal, derivado (geralmente indiretamente) de [CWnd](reference/cwnd-class.md). (Na maioria das vezes, a janela principal é derivada de [CFrameWnd](reference/cframewnd-class.md), [CMDIFrameWnd](reference/cmdiframewnd-class.md)ou [CDialog](reference/cdialog-class.md), todas derivadas de `CWnd` .)

Os aplicativos que usam a arquitetura de documento/exibição contêm objetos adicionais. Os objetos principais são:

- Um objeto de aplicativo derivado da classe [CWinApp](reference/cwinapp-class.md), conforme mencionado anteriormente.

- Um ou mais objetos de classe de documento derivados da classe [CDocument](reference/cdocument-class.md). Os objetos de classe de documento são responsáveis pela representação interna dos dados manipulados na exibição. Eles podem estar associados a um arquivo de dados.

- Um ou mais objetos de exibição derivados da classe [cvisualização](reference/cview-class.md). Cada exibição é uma janela anexada a um documento e associada a uma janela do quadro. Exibições exibem e manipulam os dados contidos em um objeto de classe de documento.

Os aplicativos de documento/exibição também contêm janelas de quadro (derivadas de [CFrameWnd](reference/cframewnd-class.md)) e modelos de documento (derivados de [CDocTemplate](reference/cdoctemplate-class.md)).

## <a name="see-also"></a>Consulte também

[Visão geral da classe](class-library-overview.md)
