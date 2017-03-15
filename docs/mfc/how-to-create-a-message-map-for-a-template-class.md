---
title: "Como criar um mapa de mensagem para uma classe de modelo | Microsoft Docs"
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
  - "mapas de mensagem, classes de modelo"
  - "classes de modelo, criando mapas de mensagem"
ms.assetid: 4e7e24f8-06df-4b46-82aa-7435c8650de3
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como criar um mapa de mensagem para uma classe de modelo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O mapeamento de mensagem em MFC fornece uma maneira eficiente de direcionar mensagens do windows a uma instância adequada do objeto C\+\+.  Os exemplos de destinos da mensagem MFC incluem classes do aplicativo, documento e classes de exibição, classes de controle, e assim por diante.  
  
 Os mapas de mensagens tradicionais MFC são declarados usando a macro de [BEGIN\_MESSAGE\_MAP](../Topic/BEGIN_MESSAGE_MAP.md) para declarar o início da mensagem de entrada, uma macro para cada método da classe retornadas a, e a macro de [END\_MESSAGE\_MAP](../Topic/END_MESSAGE_MAP.md) para declarar finalmente ao final da mensagem.  
  
 Uma restrição com a macro de [BEGIN\_MESSAGE\_MAP](../Topic/BEGIN_MESSAGE_MAP.md) ocorre quando é usado junto com uma classe que contém argumentos de modelo.  Quando usado com uma classe do modelo, esta macro causará um erro de tempo de compilação devido aos parâmetros faltantes do modelo durante a expansão macro.  A macro de [BEGIN\_TEMPLATE\_MESSAGE\_MAP](../Topic/BEGIN_TEMPLATE_MESSAGE_MAP.md) foi projetado para permitir classes que contêm um único argumento do modelo para declarar seus próprios mapas da mensagem.  
  
## Exemplo  
 Considere um exemplo na classe de MFC [CListBox](../Topic/CListBox%20Class.md) foi estendido para fornecer a sincronização com uma fonte de dados externa.  A classe de **CSyncListBox** fictícia é declarada como segue:  
  
 [!code-cpp[NVC_MFC_CListBox#42](../mfc/codesnippet/CPP/how-to-create-a-message-map-for-a-template-class_1.h)]  
  
 A classe de **CSyncListBox** templated em um único tipo que descreve a fonte de dados que sincronizará com.  Também declara três métodos que participarão da mensagem da classe: **OnPaint**, **OnDestroy**, e **OnSynchronize**.  O método de **OnSynchronize** é implementado como segue:  
  
 [!code-cpp[NVC_MFC_CListBox#43](../mfc/codesnippet/CPP/how-to-create-a-message-map-for-a-template-class_2.cpp)]  
  
 A implementação acima permite que a classe de **CSyncListBox** é especializada em qualquer tipo de classe que implemente o método de **GetCount** , como **CArray**, **CList**e, em **CMap**.  A função de **StringizeElement** é uma função do modelo protótipo pelo seguinte:  
  
 [!code-cpp[NVC_MFC_CListBox#44](../mfc/codesnippet/CPP/how-to-create-a-message-map-for-a-template-class_3.cpp)]  
  
 Normalmente, o mapa de mensagem para essa classe seria definido como:  
  
 `BEGIN_MESSAGE_MAP(CSyncListBox, CListBox)`  
  
 `ON_WM_PAINT()`  
  
 `ON_WM_DESTROY()`  
  
 `ON_MESSAGE(LBN_SYNCHRONIZE, OnSynchronize)`  
  
 `END_MESSAGE_MAP()`  
  
 onde **LBN\_SYNCHRONIZE** é uma mensagem de usuário personalizado definido pelo aplicativo, como:  
  
 [!code-cpp[NVC_MFC_CListBox#45](../mfc/codesnippet/CPP/how-to-create-a-message-map-for-a-template-class_4.cpp)]  
  
 O mapa macro acima não criará, devido ao fato de que a especificação do modelo para a classe de **CSyncListBox** estarão ausentes durante a expansão macro.  A macro de **BEGIN\_TEMPLATE\_MESSAGE\_MAP** resolve esse inserindo o parâmetro especificado do modelo no mapa macro expandido.  O mapa de mensagem para essa classe é:  
  
 [!code-cpp[NVC_MFC_CListBox#46](../mfc/codesnippet/CPP/how-to-create-a-message-map-for-a-template-class_5.cpp)]  
  
 O seguinte demonstra o uso de exemplo da classe de **CSyncListBox** que usa um objeto de **CStringList** :  
  
 [!code-cpp[NVC_MFC_CListBox#47](../mfc/codesnippet/CPP/how-to-create-a-message-map-for-a-template-class_6.cpp)]  
  
 Para concluir o teste, a função de **StringizeElement** deve ser especializada para trabalhar com a classe de **CStringList** :  
  
 [!code-cpp[NVC_MFC_CListBox#48](../mfc/codesnippet/CPP/how-to-create-a-message-map-for-a-template-class_7.cpp)]  
  
## Consulte também  
 [BEGIN\_TEMPLATE\_MESSAGE\_MAP](../Topic/BEGIN_TEMPLATE_MESSAGE_MAP.md)   
 [Manipulação e mapeamento de mensagem](../mfc/message-handling-and-mapping.md)