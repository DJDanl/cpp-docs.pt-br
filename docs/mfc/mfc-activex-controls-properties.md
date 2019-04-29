---
title: 'Controles ActiveX MFC: Propriedades'
ms.date: 11/04/2016
helpviewer_keywords:
- properties [MFC], ActiveX controls
- MFC ActiveX controls [MFC], properties
- properties [MFC]
ms.assetid: b678a53c-0d9e-476f-8aa0-23b80baaba46
ms.openlocfilehash: 5e01854e7ae7acdc33275351d0d26a76dfeabc9b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62324318"
---
# <a name="mfc-activex-controls-properties"></a>Controles ActiveX MFC: Propriedades

Um controle ActiveX aciona eventos para se comunicar com seu contêiner de controle. O contêiner, em troca, usa métodos e propriedades para se comunicar com o controle. Métodos e propriedades são semelhantes em uso e finalidade, respectivamente, para funções de membro e variáveis de membro de uma classe C++. Propriedades são membros de dados do controle ActiveX que são expostos a qualquer contêiner. As propriedades fornecem uma interface para aplicativos que contêm controles ActiveX, como clientes de automação e contêineres de controle ActiveX.

As propriedades também são chamadas de atributos.

Para obter mais informações sobre métodos de controle ActiveX, consulte o artigo [controles ActiveX MFC: Métodos](../mfc/mfc-activex-controls-methods.md).

Controles ActiveX podem implementar tanto estoque e métodos e propriedades personalizados. Classe `COleControl` fornece uma implementação para propriedades de estoque. (Para obter uma lista completa de propriedades de estoque, consulte o artigo [controles ActiveX MFC: Adicionando propriedades de estoque](../mfc/mfc-activex-controls-adding-stock-properties.md).) Propriedades personalizadas, definidas pelo desenvolvedor, adicione recursos especializados para um controle ActiveX. Para obter mais informações, consulte [controles ActiveX MFC: Adicionando propriedades personalizadas](../mfc/mfc-activex-controls-adding-custom-properties.md).

Propriedades de estoque e personalizadas, como métodos, têm suporte por um mecanismo que consiste em um mapa de expedição que lida com propriedades e métodos e funções de membro existente do `COleControl` classe. Além disso, essas propriedades podem ter parâmetros que o desenvolvedor usa para passar informações extras para o controle.

Os artigos a seguir discutem as propriedades do controle ActiveX em mais detalhes:

- [Controles ActiveX MFC: adicionar propriedades de estoque](../mfc/mfc-activex-controls-adding-stock-properties.md)

- [Controles ActiveX MFC: adicionar propriedades personalizadas](../mfc/mfc-activex-controls-adding-custom-properties.md)

- [Controles ActiveX MFC: implementação da propriedade avançada](../mfc/mfc-activex-controls-advanced-property-implementation.md)

- [Controles ActiveX MFC: acessar propriedades de ambiente](../mfc/mfc-activex-controls-accessing-ambient-properties.md)

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)
