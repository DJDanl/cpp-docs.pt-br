---
title: Classes de janela derivadas
ms.date: 11/04/2016
helpviewer_keywords:
- window class hierarchy
- hierarchies, window classes
- classes [MFC], derived
- CWnd class [MFC], classes derived from
- derived classes [MFC], window classes
- window classes [MFC], derived
ms.assetid: 6f7e437e-fbde-4a06-bfab-72d9dbf05292
ms.openlocfilehash: bf0d8e82f1a1793f4e5561e24ed9ca173511d07c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50462108"
---
# <a name="derived-window-classes"></a>Classes de janela derivadas

Você pode criar janelas diretamente a partir [CWnd](../mfc/reference/cwnd-class.md), ou derivar novas classes de janela de `CWnd`. Isso é como você normalmente cria suas próprias janelas personalizadas. No entanto, a maioria das janelas usadas em um programa do framework em vez disso, são criados de um do `CWnd`-classes de janela com moldura fornecidas pelo MFC derivadas.

## <a name="frame-window-classes"></a>Classes de janela com moldura

[CFrameWnd](../mfc/reference/cframewnd-class.md)<br/>
Usado para janelas de quadro SDI que moldam um único documento e sua exibição. A janela do quadro é a janela do quadro principal para o aplicativo e a janela do quadro para o documento atual.

[CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md)<br/>
Usado como a janela de quadro principal para aplicativos MDI. A janela do quadro principal é um contêiner para todas as janelas de documento MDI e compartilha sua barra de menus com elas. Uma janela de quadro MDI é uma janela de nível superior que aparece na área de trabalho.

[CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md)<br/>
Usado para documentos individuais abertos em uma janela de quadro principal de MDI. Cada documento e sua exibição são moldados por uma janela de quadro filho MDI contida pela janela de quadro principal de MDI. Uma janela filho MDI se parece muito com uma janela de quadro típicas, mas está contida dentro de uma janela de quadro MDI em vez de ficar na área de trabalho. No entanto, a janela filho MDI não tem uma barra de menus própria e deve compartilhar a barra de menus da janela de quadro MDI que o contém.

Para obter mais informações, consulte [quadro Windows](../mfc/frame-windows.md).

## <a name="other-window-classes-derived-from-cwnd"></a>Outras Classes de janela derivadas de CWnd

Além das janelas de quadro, várias outras categorias principais do windows são derivadas de `CWnd`:

*Exibições*<br/>
As exibições são criadas usando o `CWnd`-classe derivada [CView](../mfc/reference/cview-class.md) (ou uma de suas classes derivadas). Um modo de exibição é anexado a um documento e atua como um intermediário entre o documento e o usuário. Uma exibição é uma janela filho (não um MDI filho) que geralmente preenche a área de cliente de uma janela de quadro SDI ou uma janela de quadro MDI filho (ou parte da área de cliente não coberta por uma barra de ferramentas e/ou uma barra de status).

*Caixas de diálogo*<br/>
Caixas de diálogo são criadas usando o `CWnd`-classe derivada [CDialog](../mfc/reference/cdialog-class.md).

*Formulários*<br/>
Modos de exibição de formulário com base nos recursos de modelo de caixa de diálogo, como caixas de diálogo, são criados usando as classes [CFormView](../mfc/reference/cformview-class.md), [CRecordView](../mfc/reference/crecordview-class.md), ou [CDaoRecordView](../mfc/reference/cdaorecordview-class.md).

*Controles*<br/>
Controles como botões, caixas de listagem e caixas de combinação são criados usando outras classes derivadas de `CWnd`. Ver [controlar tópicos](../mfc/controls-mfc.md).

*Barras de controle*<br/>
Janelas filho que contêm controles. Exemplos incluem barras de ferramentas e barras de status. Ver [barras de controle](../mfc/control-bars.md).

## <a name="window-class-hierarchy"></a>Hierarquia de classes de janela

Consulte a [gráfico da hierarquia MFC](../mfc/hierarchy-chart.md) na *referência da MFC*. Modos de exibição são explicados [arquitetura de documento/exibição](../mfc/document-view-architecture.md). Caixas de diálogo são explicadas [caixas de diálogo](../mfc/dialog-boxes.md).

## <a name="creating-your-own-special-purpose-window-classes"></a>Criar suas próprias Classes de janela de propósito especial

Além das classes de janela fornecidas pela biblioteca de classes, talvez seja necessário janelas filhas de propósito especial. Para criar tal janela, criar seus próprios [CWnd](../mfc/reference/cwnd-class.md)-classe derivada e torná-lo em uma janela filho de um quadro ou uma exibição. Tenha em mente que a estrutura gerencia a extensão da área de cliente de uma janela de quadro do documento. A maioria da área de cliente é gerenciado por um modo de exibição, mas outras janelas, como controle de barras ou suas próprias janelas personalizados, podem compartilhar o espaço com o modo de exibição. Você pode precisar interagir com os mecanismos nas classes [CView](../mfc/reference/cview-class.md) e [CControlBar](../mfc/reference/ccontrolbar-class.md) para posicionar janelas filho na área de cliente de uma janela de quadro.

[Criando Windows](../mfc/creating-windows.md) aborda a criação de objetos de janela e as janelas que eles gerenciam.

## <a name="see-also"></a>Consulte também

[Objetos de janela](../mfc/window-objects.md)

