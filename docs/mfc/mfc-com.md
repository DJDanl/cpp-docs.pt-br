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
ms.openlocfilehash: da194510938e3fe02eba5993182e811fdf2e1b7c
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84618006"
---
# <a name="mfc-com"></a>MFC COM

Um subconjunto de MFC foi projetado para dar suporte a COM, enquanto a maior parte do Active Template Library (ATL) foi projetada para programação COM. Esta seção de tópicos descreve o suporte do MFC para COM.

As tecnologias ativas (como controles ActiveX, contenção de documento ativo, OLE e assim por diante) usam o Component Object Model (COM) para permitir que os componentes de software interajam entre si em um ambiente de rede, independentemente do idioma com o qual foram criados. As tecnologias ativas podem ser usadas para criar aplicativos que são executados na área de trabalho ou na Internet. Para obter mais informações, consulte [introdução ao com](../atl/introduction-to-com.md) ou [ao Component Object Model](/windows/win32/com/the-component-object-model).

As tecnologias ativas incluem as tecnologias de cliente e de servidor, incluindo as seguintes:

- Os controles ActiveX são objetos interativos que podem ser usados em contêineres como um site da Web. Para obter mais informações sobre controles ActiveX, consulte:

  - [Controles ActiveX do MFC](mfc-activex-controls.md)

  - [Controles ActiveX na Internet](activex-controls-on-the-internet.md)

  - [Visão geral: Internet](mfc-internet-programming-basics.md)

  - [Atualizar um controle ActiveX existente para ser usado na Internet](upgrading-an-existing-activex-control.md)

  - [Depurando um controle ActiveX](/visualstudio/debugger/how-to-debug-an-activex-control)

- O script ativo controla o comportamento integrado de um ou mais controles ActiveX de um navegador ou servidor. Para obter mais informações sobre scripts ativos, consulte [Active Technology na Internet](active-technology-on-the-internet.md).

- A [automação](automation.md) (anteriormente conhecida como automação OLE) possibilita que um aplicativo manipule objetos implementados em outro aplicativo ou "exponha" objetos para que possam ser manipulados.

   O objeto automatizado pode ser local ou remoto (em outro computador acessível em uma rede). A automação está disponível para objetos OLE e COM.

- Esta seção também fornece informações sobre como escrever componentes COM usando o MFC, por exemplo, em [pontos de conexão](connection-points.md).

Para obter uma discussão sobre o que ainda é chamado de OLE versus o que agora é chamado de tecnologia ativa, consulte os tópicos sobre [OLE](ole-in-mfc.md).

## <a name="in-this-section"></a>Nesta seção

[Contenção de documentos ativos](active-document-containment.md)

[Automação](automation.md)

[Pontos de conexão](connection-points.md)

[Controles ActiveX do MFC](mfc-activex-controls.md)

## <a name="see-also"></a>Consulte também

[Conceitos](mfc-concepts.md)
