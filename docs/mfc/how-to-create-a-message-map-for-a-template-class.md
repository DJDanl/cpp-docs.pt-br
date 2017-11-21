---
title: 'Como: criar um mapa de mensagem para uma classe de modelo | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- template classes [MFC], creating message maps
- message maps [MFC], template classes
ms.assetid: 4e7e24f8-06df-4b46-82aa-7435c8650de3
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 73f6812b1dcc4652c1cb984ddb0ca67f3e72f631
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="how-to-create-a-message-map-for-a-template-class"></a>Como criar um mapa de mensagem para uma classe de modelo
Mapeamento de mensagem em MFC fornece uma maneira eficiente para direcionar as mensagens do Windows a uma instância de objeto C++ apropriada. Classes de aplicativo, classes de documento e exibição, classes de controle e assim por diante são exemplos de destinos de mapa de mensagem do MFC.  
  
 Mapas de mensagem MFC tradicionais são declarados usando o [BEGIN_MESSAGE_MAP](reference/message-map-macros-mfc.md#begin_message_map) macro para declarar o início do mapa de mensagem, uma entrada de macro para cada método de classe do manipulador de mensagens e, finalmente, o [END_MESSAGE_MAP](reference/message-map-macros-mfc.md#end_message_map)macro para declarar o fim do mapa de mensagem.  
  
 Uma limitação com o [BEGIN_MESSAGE_MAP](reference/message-map-macros-mfc.md#begin_message_map) macro ocorre quando ele é usado em conjunto com uma classe que contém os argumentos de modelo. Quando usado com uma classe de modelo, essa macro causará um erro de tempo de compilação devido aos parâmetros de modelo ausente durante a expansão de macro. O [BEGIN_TEMPLATE_MESSAGE_MAP](reference/message-map-macros-mfc.md#begin_template_message_map) macro foi projetada para permitir que mapeia classes que contêm um argumento de modelo único para declarar sua própria mensagem.  
  
## <a name="example"></a>Exemplo  
 Considere um exemplo onde a MFC [CListBox](../mfc/reference/clistbox-class.md) classe for estendida para fornecer a sincronização com uma fonte de dados externa. O fictícia **CSyncListBox** classe é declarada da seguinte maneira:  
  
 [!code-cpp[NVC_MFC_CListBox#42](../mfc/codesnippet/cpp/how-to-create-a-message-map-for-a-template-class_1.h)]  
  
 O **CSyncListBox** classe é o modelo em um único tipo que descreve a fonte de dados, ele será sincronizado com o. Ele também declara três métodos que participarão no mapa de mensagem da classe: **OnPaint**, **OnDestroy**, e **OnSynchronize**. O **OnSynchronize** método é implementado da seguinte maneira:  
  
 [!code-cpp[NVC_MFC_CListBox#43](../mfc/codesnippet/cpp/how-to-create-a-message-map-for-a-template-class_2.cpp)]  
  
 A implementação acima permite que o **CSyncListBox** classe a ser especializado em qualquer tipo de classe que implementa o **GetCount** método, como **CArray**, **CList**, e **CMap**. O **StringizeElement** é uma função de modelo prototipada pelos seguintes motivos:  
  
 [!code-cpp[NVC_MFC_CListBox#44](../mfc/codesnippet/cpp/how-to-create-a-message-map-for-a-template-class_3.cpp)]  
  
 Normalmente, o mapa de mensagens para essa classe seria definido como:  
  
 `BEGIN_MESSAGE_MAP(CSyncListBox, CListBox)`  
  
 `ON_WM_PAINT()`  
  
 `ON_WM_DESTROY()`  
  
 `ON_MESSAGE(LBN_SYNCHRONIZE, OnSynchronize)`  
  
 `END_MESSAGE_MAP()`  
  
 onde **LBN_SYNCHRONIZE** é uma mensagem de usuário personalizado definida pelo aplicativo, tais como:  
  
 [!code-cpp[NVC_MFC_CListBox#45](../mfc/codesnippet/cpp/how-to-create-a-message-map-for-a-template-class_4.cpp)]  
  
 O mapa de macro acima não será compilado, devido ao fato de que a especificação de modelo para o **CSyncListBox** classe estarão ausente durante a expansão de macro. O **BEGIN_TEMPLATE_MESSAGE_MAP** macro resolve isso incorporando o parâmetro de modelo especificado para o mapa de macro expandido. O mapa de mensagens para essa classe se torna:  
  
 [!code-cpp[NVC_MFC_CListBox#46](../mfc/codesnippet/cpp/how-to-create-a-message-map-for-a-template-class_5.cpp)]  
  
 A seguir demonstra o exemplo de uso de **CSyncListBox** classe usando um **CStringList** objeto:  
  
 [!code-cpp[NVC_MFC_CListBox#47](../mfc/codesnippet/cpp/how-to-create-a-message-map-for-a-template-class_6.cpp)]  
  
 Para concluir o teste, o **StringizeElement** função deve ser especializada para trabalhar com o **CStringList** classe:  
  
 [!code-cpp[NVC_MFC_CListBox#48](../mfc/codesnippet/cpp/how-to-create-a-message-map-for-a-template-class_7.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [BEGIN_TEMPLATE_MESSAGE_MAP](reference/message-map-macros-mfc.md#begin_template_message_map)   
 [Tratamento e mapeamento de mensagem](../mfc/message-handling-and-mapping.md)

