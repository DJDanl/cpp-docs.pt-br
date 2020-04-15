---
title: MFC COM
ms.date: 09/12/2018
f1_keywords:
- MFC COM (MFC)
helpviewer_keywords:
- MFC, COM support
- MFC ActiveX controls [MFC], COM support in MFC
- MFC COM [MFC]
- ActiveX controls [MFC], COM object model
- Active technology [MFC]
- COM [MFC], MFC support
ms.assetid: 7646bdcb-3a06-4ed5-9386-9b00f3979dcb
ms.openlocfilehash: 514251475050e728be1959417ead1dbdf96e4800
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81358186"
---
# <a name="mfc-com"></a>MFC COM

Um subconjunto de MFC foi projetado para suportar com, enquanto a maior parte da Active Template Library (ATL) foi projetada para programação COM. Esta seção de tópicos descreve o suporte do MFC ao COM.

As tecnologias ativas (como controles ActiveX, contenção ativa de documentos, OLE e assim por diante) usam o Component Object Model (COM) para permitir que os componentes do software interajam entre si em um ambiente em rede, independentemente da linguagem com a qual foram criados. Tecnologias ativas podem ser usadas para criar aplicativos executados na área de trabalho ou na Internet. Para obter mais informações, consulte [Introdução ao COM](../atl/introduction-to-com.md) ou [ao modelo de objeto componente](/windows/win32/com/the-component-object-model).

As tecnologias ativas incluem tecnologias de cliente e servidor, incluindo as seguintes:

- Os controles ActiveX são objetos interativos que podem ser usados em contêineres, como um site da Web. Para obter mais informações sobre os controles ActiveX, consulte:

  - [Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)

  - [Controles ActiveX na Internet](../mfc/activex-controls-on-the-internet.md)

  - [Visão geral: Internet](../mfc/mfc-internet-programming-basics.md)

  - [Atualize um controle ActiveX existente para ser usado na Internet](../mfc/upgrading-an-existing-activex-control.md)

  - [Depuração de um controle ActiveX](/visualstudio/debugger/how-to-debug-an-activex-control)

- O scripting ativo controla o comportamento integrado de um ou mais controles ActiveX de um navegador ou servidor. Para obter mais informações sobre scripting ativo, consulte [Active Technology na Internet](../mfc/active-technology-on-the-internet.md).

- [A automação](../mfc/automation.md) (anteriormente conhecida como Automação OLE) permite que um aplicativo manipule objetos implementados em outro aplicativo ou "exponha" objetos para que possam ser manipulados.

   O objeto automatizado pode ser local ou remoto (em outra máquina acessível em uma rede). A automação está disponível para objetos OLE e COM.

- Esta seção também fornece informações sobre como escrever componentes COM usando MFC, por exemplo, em [Pontos de Conexão](../mfc/connection-points.md).

Para uma discussão sobre o que ainda é chamado de OLE versus o que hoje é chamado de tecnologia ativa, consulte os tópicos sobre [OLE](../mfc/ole-in-mfc.md).

## <a name="in-this-section"></a>Nesta seção

[Contenção de documentos ativos](../mfc/active-document-containment.md)

[Automação](../mfc/automation.md)

[Pontos de conexão](../mfc/connection-points.md)

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)

## <a name="see-also"></a>Confira também

[Conceitos](../mfc/mfc-concepts.md)
