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
ms.openlocfilehash: c84284b765e740fa0a13972e9902e7737e15bbab
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84623168"
---
# <a name="derived-window-classes"></a>Classes de janela derivadas

Você pode criar o Windows diretamente do [CWnd](reference/cwnd-class.md)ou derivar novas classes de janela do `CWnd` . É assim que você normalmente cria suas próprias janelas personalizadas. No entanto, a maioria das janelas usadas em um programa de estrutura é criada em uma das `CWnd` classes de janela de quadro derivadas fornecidas pelo MFC.

## <a name="frame-window-classes"></a>Classes de janela do quadro

[CFrameWnd](reference/cframewnd-class.md)<br/>
Usado para janelas de quadro SDI que estruturam um único documento e sua exibição. A janela do quadro é a janela do quadro principal para o aplicativo e a janela do quadro do documento atual.

[CMDIFrameWnd](reference/cmdiframewnd-class.md)<br/>
Usado como a janela principal do quadro para aplicativos MDI. A janela do quadro principal é um contêiner para todas as janelas de documentos MDI e compartilha sua barra de menus com elas. Uma janela de quadro MDI é uma janela de nível superior que aparece na área de trabalho.

[CMDIChildWnd](reference/cmdichildwnd-class.md)<br/>
Usado para documentos individuais abertos em uma janela de quadro principal MDI. Cada documento e sua exibição são emoldurados por uma janela de quadro filho MDI contida na janela do quadro principal MDI. Uma janela filho MDI se parece muito com uma janela de quadro típica, mas está contida em uma janela de quadro MDI, em vez de estar colocada na área de trabalho. No entanto, a janela filho MDI não tem uma barra de menus própria e deve compartilhar a barra de menus da janela de quadro MDI que a contém.

Para obter mais informações, consulte [janelas de quadros](frame-windows.md).

## <a name="other-window-classes-derived-from-cwnd"></a>Outras classes de janela derivadas de CWnd

Além das janelas de quadros, várias outras categorias principais do Windows são derivadas de `CWnd` :

*Exibições*<br/>
As exibições são criadas usando a `CWnd` classe derivada de [cvisualização](reference/cview-class.md) (ou uma de suas classes derivadas). Uma exibição é anexada a um documento e atua como um intermediário entre o documento e o usuário. Uma exibição é uma janela filho (não um filho MDI) que normalmente preenche a área do cliente de uma janela de quadro SDI ou uma janela de quadro filho MDI (ou essa parte da área do cliente não coberta por uma barra de ferramentas e/ou uma barra de status).

*Caixas de diálogo*<br/>
As caixas de diálogo são criadas usando a `CWnd` classe derivada de [CDialog](reference/cdialog-class.md).

*Formulários*<br/>
Exibições de formulário com base em recursos de modelo de caixa de diálogo, como caixas de diálogo, são criadas usando classes [CFormView](reference/cformview-class.md), [CRecordView](reference/crecordview-class.md)ou [CDaoRecordView](reference/cdaorecordview-class.md).

*Controles*<br/>
Controles como botões, caixas de listagem e caixas de combinação são criados usando outras classes derivadas de `CWnd` . Consulte os [Tópicos de controle](controls-mfc.md).

*Barras de controle*<br/>
Janelas filhas que contêm controles. Os exemplos incluem barras de ferramentas e de status. Consulte [barras de controle](control-bars.md).

## <a name="window-class-hierarchy"></a>Hierarquia de classes de janela

Consulte o [gráfico de hierarquia do MFC](hierarchy-chart.md) na *referência do MFC*. As exibições são explicadas em [arquitetura de documento/exibição](document-view-architecture.md). As caixas de diálogo são explicadas em [caixas de diálogo](dialog-boxes.md).

## <a name="creating-your-own-special-purpose-window-classes"></a>Criando suas próprias classes de janela de finalidade especial

Além das classes de janela fornecidas pela biblioteca de classes, você pode precisar de janelas filhas de uso especial. Para criar uma janela desse tipo, crie sua própria classe derivada de [CWnd](reference/cwnd-class.md)e transforme-a em uma janela filho de um quadro ou exibição. Tenha em mente que a estrutura gerencia a extensão da área do cliente de uma janela de quadro do documento. A maior parte da área do cliente é gerenciada por uma exibição, mas outras janelas, como barras de controle ou suas próprias janelas personalizadas, podem compartilhar o espaço com a exibição. Talvez seja necessário interagir com os mecanismos nas classes [cvisualização](reference/cview-class.md) e [CControlBar](reference/ccontrolbar-class.md) para posicionar as janelas filhas na área do cliente da janela do quadro.

A [criação de janelas](creating-windows.md) discute a criação de objetos de janela e as janelas que eles gerenciam.

## <a name="see-also"></a>Consulte também

[Objetos de janela](window-objects.md)
