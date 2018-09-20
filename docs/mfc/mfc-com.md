---
title: MFC COM | Microsoft Docs
ms.custom: ''
ms.date: 09/12/2018
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- MFC COM (MFC)
dev_langs:
- C++
helpviewer_keywords:
- MFC, COM support
- MFC ActiveX controls [MFC], COM support in MFC
- MFC COM [MFC]
- ActiveX controls [MFC], COM object model
- Active technology [MFC]
- COM [MFC], MFC support
ms.assetid: 7646bdcb-3a06-4ed5-9386-9b00f3979dcb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d23a9be38ebb870adf098b34fac79afff6345cd8
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46394732"
---
# <a name="mfc-com"></a>MFC COM

Um subconjunto do MFC foi projetado para dar suporte a COM, enquanto a maioria da biblioteca ATL (Active Template) foi projetado para a programação COM. Esta seção de tópicos descreve o suporte do MFC para COM.

Tecnologias do Active Directory (como o ActiveX controles, confinamento do documento ativo, OLE e assim por diante) usam o modelo de objeto de componente (COM) para habilitar os componentes de software interajam uns com os outros em um ambiente de rede, independentemente do idioma com o qual eles foram criado. Tecnologias de Active Directory podem ser usadas para criar aplicativos que são executados na área de trabalho ou na Internet. Para obter mais informações, consulte [Introdução a COM](../atl/introduction-to-com.md) ou [o modelo de objeto de componente](/windows/desktop/com/the-component-object-model).

Tecnologias do Active Directory incluem tecnologias de cliente e servidor, incluindo o seguinte:

- Controles ActiveX são objetos interativos que podem ser usados em contêineres como um site da Web. Para obter mais informações sobre os controles ActiveX, consulte:

   - [Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)

   - [Controles ActiveX na Internet](../mfc/activex-controls-on-the-internet.md)

   - [Visão geral: Internet](../mfc/mfc-internet-programming-basics.md)

   - [Atualizar um controle ActiveX existente a ser usado na Internet](../mfc/upgrading-an-existing-activex-control.md)

   - [Depuração de um controle ActiveX](/visualstudio/debugger/how-to-debug-an-activex-control)

- Script ativo controla o comportamento integrado de um ou mais controles ActiveX em um navegador ou servidor. Para obter mais informações sobre scripts do Active Directory, consulte [tecnologia ativa na Internet](../mfc/active-technology-on-the-internet.md).

- [Automação](../mfc/automation.md) (anteriormente conhecido como automação OLE) torna possível para um aplicativo para manipular objetos implementados em outro aplicativo ou "expor" objetos para que eles podem ser manipulados.

     O objeto automatizado pode ser local ou remoto (em outro computador acessível em uma rede). Automação está disponível para objetos OLE e COM.

- Esta seção também fornece informações sobre como escrever componentes usando o MFC, por exemplo, no [pontos de Conexão](../mfc/connection-points.md).

Para uma discussão sobre o que ainda é chamado de OLE versus o que agora é chamado de tecnologia do Active Directory, consulte os tópicos sobre [OLE](../mfc/ole-in-mfc.md).

Além disso, consulte o artigo da Base de dados de Conhecimento Q248019: HOWTO: evitar servidor ocupado caixa de diálogo caixa do que aparecem durante um COM operação demorada.

## <a name="in-this-section"></a>Nesta seção

[Contenção de documentos ativos](../mfc/active-document-containment.md)

[Automação](../mfc/automation.md)

[Pontos de conexão](../mfc/connection-points.md)

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)

## <a name="see-also"></a>Consulte também

[Conceitos](../mfc/mfc-concepts.md)

