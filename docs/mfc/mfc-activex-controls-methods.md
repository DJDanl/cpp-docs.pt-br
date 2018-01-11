---
title: "Controles ActiveX MFC: Métodos | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: MFC ActiveX controls [MFC], methods
ms.assetid: e20271de-6ffa-4ba0-848b-bafe6c9e510c
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 8e3b343b13118930612e4adfed4c33a65a9e7be8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="mfc-activex-controls-methods"></a>Controles ActiveX MFC: métodos
Um controle ActiveX dispara eventos para se comunicar entre si mesma e seu contêiner de controle. Um contêiner também pode se comunicar com um controle por meio de métodos e propriedades. Métodos também são chamados de funções.  
  
 Métodos e propriedades fornecem uma interface exportada para uso por outros aplicativos, como clientes de automação e contêineres de controle ActiveX. Para obter mais informações sobre propriedades do controle ActiveX, consulte o artigo [controles ActiveX MFC: propriedades](../mfc/mfc-activex-controls-properties.md).  
  
 Métodos são semelhantes em uso e a finalidade para as funções de membro de uma classe do C++. Há dois tipos de métodos de seu controle pode implementar: personalizados e ações. Semelhantes a eventos de estoque, métodos de estoque são os métodos para os quais [COleControl](../mfc/reference/colecontrol-class.md) fornece uma implementação. Para obter mais informações sobre métodos de estoque, consulte o artigo [controles ActiveX MFC: adicionando métodos de estoque](../mfc/mfc-activex-controls-adding-stock-methods.md). Métodos personalizados, definidos pelo desenvolvedor de permitem personalização adicional do controle. Para obter mais informações, consulte o artigo [controles ActiveX MFC: adicionando métodos de personalizado](../mfc/mfc-activex-controls-adding-custom-methods.md).  
  
 O Microsoft Foundation Class Library (MFC) implementa um mecanismo que permite que o controle dar suporte a ações e métodos personalizados. A primeira parte é a classe `COleControl`. Derivado `CWnd`, `COleControl` métodos de estoque que são comuns a todos os controles ActiveX de suporte a funções de membro. A segunda parte desse mecanismo é o mapa de expedição. Um mapa de expedição é semelhante a um mapa de mensagem; No entanto, em vez de uma função de mapeamento para uma ID de mensagem do Windows, um mapa de expedição mapeia as funções de membro virtual para IDS de IDispatch.  
  
 Para um controle dar suporte a vários métodos corretamente, sua classe deve declarar um mapa de expedição. Isso é feito usando a seguinte linha de código localizado no cabeçalho de classe de controle (. H) arquivo:  
  
 [!code-cpp[NVC_MFC_AxUI#13](../mfc/codesnippet/cpp/mfc-activex-controls-methods_1.h)]  
  
 A principal finalidade do mapa de expedição é estabelecer a relação entre os nomes de método usada por um chamador externo (como o contêiner) e as funções de membro de classe do controle que implementam os métodos. Depois que o mapa de expedição foi declarado, ele precisa ser definido na implementação do controle (. Arquivo CPP). Linhas de código a seguir definem o mapa de distribuição:  
  
 [!code-cpp[NVC_MFC_AxUI#14](../mfc/codesnippet/cpp/mfc-activex-controls-methods_2.cpp)]  
[!code-cpp[NVC_MFC_AxUI#15](../mfc/codesnippet/cpp/mfc-activex-controls-methods_3.cpp)]  
  
 Se você usou o [Assistente de controle ActiveX MFC](../mfc/reference/mfc-activex-control-wizard.md) para criar o projeto, essas linhas foram adicionadas automaticamente. Se o Assistente de controle ActiveX MFC não foi usado, você deve adicionar essas linhas manualmente.  
  
 Os artigos a seguir abordam métodos em detalhes:  
  
-   [Controles ActiveX do MFC: adicionando métodos de estoque](../mfc/mfc-activex-controls-adding-stock-methods.md)  
  
-   [Controles ActiveX do MFC: adicionando métodos personalizados](../mfc/mfc-activex-controls-adding-custom-methods.md)  
  
-   [Controles ActiveX do MFC: retornando códigos de erro de um método](../mfc/mfc-activex-controls-returning-error-codes-from-a-method.md)  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)

