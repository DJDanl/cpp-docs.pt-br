---
title: 'Controles ActiveX MFC: propriedades'
ms.date: 11/04/2016
helpviewer_keywords:
- properties [MFC], ActiveX controls
- MFC ActiveX controls [MFC], properties
- properties [MFC]
ms.assetid: b678a53c-0d9e-476f-8aa0-23b80baaba46
ms.openlocfilehash: c7ed0fddea660409f5089159b71d39a29b01d538
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84618178"
---
# <a name="mfc-activex-controls-properties"></a>Controles ActiveX MFC: propriedades

Um controle ActiveX dispara eventos para se comunicar com seu contêiner de controle. O contêiner, em retorno, usa métodos e propriedades para se comunicar com o controle. Métodos e propriedades são semelhantes em uso e finalidade, respectivamente, para funções de membro e variáveis de membro de uma classe C++. As propriedades são membros de dados do controle ActiveX que são expostos a qualquer contêiner. As propriedades fornecem uma interface para aplicativos que contêm controles ActiveX, como clientes de automação e contêineres de controle ActiveX.

As propriedades também são chamadas de atributos.

Para obter mais informações sobre os métodos de controle do ActiveX, consulte o artigo [controles ActiveX do MFC: métodos](mfc-activex-controls-methods.md).

Os controles ActiveX podem implementar métodos e propriedades de estoque e personalizados. `COleControl`A classe fornece uma implementação para propriedades de ações. (Para obter uma lista completa das propriedades de ações, consulte o artigo [controles ActiveX do MFC: Adicionando propriedades de estoque](mfc-activex-controls-adding-stock-properties.md).) Propriedades personalizadas, definidas pelo desenvolvedor, adicionam recursos especializados a um controle ActiveX. Para obter mais informações, consulte [controles ActiveX do MFC: Adicionando propriedades personalizadas](mfc-activex-controls-adding-custom-properties.md).

As propriedades personalizadas e de ações, como métodos, têm suporte de um mecanismo que consiste em um mapa de expedição que manipula Propriedades e métodos e funções de membro existentes da `COleControl` classe. Além disso, essas propriedades podem ter parâmetros que o desenvolvedor usa para passar informações extras para o controle.

Os artigos a seguir abordam as propriedades do controle ActiveX mais detalhadamente:

- [Controles ActiveX do MFC: adicionando propriedades de estoque](mfc-activex-controls-adding-stock-properties.md)

- [Controles ActiveX do MFC: adicionando propriedades personalizadas](mfc-activex-controls-adding-custom-properties.md)

- [Controles ActiveX do MFC: implementação da propriedade avançada](mfc-activex-controls-advanced-property-implementation.md)

- [Controles ActiveX do MFC: acessando propriedades ambiente](mfc-activex-controls-accessing-ambient-properties.md)

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](mfc-activex-controls.md)
