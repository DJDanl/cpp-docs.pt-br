---
title: 'Controles ActiveX MFC: Propriedades | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- properties [MFC], ActiveX controls
- MFC ActiveX controls [MFC], properties
- properties [MFC]
ms.assetid: b678a53c-0d9e-476f-8aa0-23b80baaba46
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: eea42401255f0aa99dd7a42b8e9b69e45dfe7b5b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="mfc-activex-controls-properties"></a>Controles ActiveX MFC: propriedades
Um controle ActiveX dispara eventos para se comunicar com seu contêiner de controle. O contêiner usa, métodos e propriedades para se comunicar com o controle. Métodos e propriedades são semelhantes em uso e a finalidade, respectivamente, para funções de membro e variáveis de membro de uma classe do C++. Propriedades são membros de dados do controle ActiveX que são expostos para qualquer contêiner. Propriedades fornecem uma interface para aplicativos que contêm os controles ActiveX, como clientes de automação e contêineres de controle ActiveX.  
  
 Propriedades também são chamadas de atributos.  
  
 Para obter mais informações sobre métodos de controle ActiveX, consulte o artigo [controles ActiveX MFC: métodos](../mfc/mfc-activex-controls-methods.md).  
  
 Controles ActiveX podem implementar as ações e métodos e propriedades personalizados. Classe `COleControl` fornece uma implementação para propriedades de estoque. (Para obter uma lista completa de propriedades de estoque, consulte o artigo [controles ActiveX MFC: Adicionando propriedades de estoque](../mfc/mfc-activex-controls-adding-stock-properties.md).) Propriedades personalizadas, definidas pelo desenvolvedor de adicionar recursos especializados para um controle ActiveX. Para obter mais informações, consulte [controles ActiveX MFC: adicionando Custom Properties](../mfc/mfc-activex-controls-adding-custom-properties.md).  
  
 Propriedades personalizadas e estoque, assim como os métodos, são suportadas por um mecanismo que consiste em um mapa de despacho que manipula propriedades e métodos e funções de membro existente do `COleControl` classe. Além disso, essas propriedades podem ter parâmetros que o desenvolvedor usa para passar informações adicionais para o controle.  
  
 Os artigos a seguir discutem as propriedades do controle ActiveX em mais detalhes:  
  
-   [Controles ActiveX do MFC: adicionando propriedades de estoque](../mfc/mfc-activex-controls-adding-stock-properties.md)  
  
-   [Controles ActiveX do MFC: adicionando propriedades personalizadas](../mfc/mfc-activex-controls-adding-custom-properties.md)  
  
-   [Controles ActiveX do MFC: implementação da propriedade avançada](../mfc/mfc-activex-controls-advanced-property-implementation.md)  
  
-   [Controles ActiveX do MFC: acessando propriedades ambiente](../mfc/mfc-activex-controls-accessing-ambient-properties.md)  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)

