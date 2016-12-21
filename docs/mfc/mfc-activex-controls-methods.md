---
title: "Controles ActiveX MFC: m&#233;todos | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Controles ActiveX MFC, métodos"
ms.assetid: e20271de-6ffa-4ba0-848b-bafe6c9e510c
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles ActiveX MFC: m&#233;todos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um controle ActiveX será acionado eventos para comunicação entre ele e seu contêiner do controle.  Um contêiner também pode se comunicar com um controle por meio de métodos e propriedades.  Os métodos também são chamadas de funções.  
  
 Os métodos e as propriedades fornecem uma interface exportada para o uso de outros aplicativos, como clientes de automação e contêiner do controle ActiveX.  Para obter mais informações sobre as propriedades do controle ActiveX, consulte o artigo [Controles ActiveX MFC: Propriedades](../mfc/mfc-activex-controls-properties.md).  
  
 Os métodos são semelhantes em uso e a finalidade das funções de membro da classe c. criando  Há dois tipos de métodos que seu controle pode implementar: estoque e personalizados.  Semelhante aos eventos de estoque, os métodos de estoque são os métodos para que [COleControl](../mfc/reference/colecontrol-class.md) fornece uma implementação.  Para obter mais informações sobre os métodos de estoque, consulte o artigo [Controles ActiveX MFC: Adicionando os métodos de estoque](../mfc/mfc-activex-controls-adding-stock-methods.md).  Os métodos, personalizados definidos pelo desenvolvedor, permitem para personalizações adicionais do controle.  Para obter mais informações, consulte o artigo [Controles ActiveX MFC: Adicionando métodos personalizados](../mfc/mfc-activex-controls-adding-custom-methods.md).  
  
 A biblioteca de classes do Microsoft \(MFC\) implementa um mecanismo que permite que o controle da suporte aos métodos de estoque e personalizados.  A primeira parte é `COleControl`classe.  Derivada de `CWnd`, métodos de estoque das funções de membro de `COleControl` que são comuns a todos os controles ActiveX.  A segunda parte desse mecanismo é o mapa de distribuição.  Um mapa de distribuição é semelhante a um mapa de mensagem; no entanto, em vez de mapear uma função a um ID de mensagem do windows, um mapa de expedição mapeia as funções de membro virtuais a ID IDispatch.  
  
 Para que um controle suporte a vários métodos corretamente, a sua classe deve declarar um mapa de distribuição.  Isso é realizado pela seguinte linha de código localizada no cabeçalho da classe de controle \(. H\) arquivo:  
  
 [!code-cpp[NVC_MFC_AxUI#13](../mfc/codesnippet/CPP/mfc-activex-controls-methods_1.h)]  
  
 A finalidade principal do mapa de distribuição é estabelecer a relação entre os nomes do método usados por um chamador externa \(como o contêiner\) e as funções de membro da classe de controle que implementam os métodos.  Depois que o mapa de distribuição tiver sido declarado, precisa ser definido no arquivo de implementação de controle \(.CPP\).  As seguintes linhas de código definem o mapa de distribuição:  
  
 [!code-cpp[NVC_MFC_AxUI#14](../mfc/codesnippet/CPP/mfc-activex-controls-methods_2.cpp)]  
[!code-cpp[NVC_MFC_AxUI#15](../mfc/codesnippet/CPP/mfc-activex-controls-methods_3.cpp)]  
  
 Se você usou [Assistente de controle ActiveX de MFC](../mfc/reference/mfc-activex-control-wizard.md) para criar o projeto, essas linhas foram adicionadas automaticamente.  Se o assistente de controle ActiveX de MFC não tiver sido usado, você deve adicionar essas linhas manualmente.  
  
 Os artigos a seguir discutem métodos em detalhes:  
  
-   [Controles ActiveX MFC: Adicionando os métodos de estoque](../mfc/mfc-activex-controls-adding-stock-methods.md)  
  
-   [Controles ActiveX MFC: Adicionando métodos personalizados](../mfc/mfc-activex-controls-adding-custom-methods.md)  
  
-   [Controles ActiveX MFC: Retornando códigos de erro de um método](../mfc/mfc-activex-controls-returning-error-codes-from-a-method.md)  
  
## Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)