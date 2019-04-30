---
title: 'Como: Criar um mapa de mensagem para uma classe de modelo'
ms.date: 11/04/2016
helpviewer_keywords:
- template classes [MFC], creating message maps
- message maps [MFC], template classes
ms.assetid: 4e7e24f8-06df-4b46-82aa-7435c8650de3
ms.openlocfilehash: 676e698a899327eee8305731b5d609b5b95ece76
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62389496"
---
# <a name="how-to-create-a-message-map-for-a-template-class"></a>Como: Criar um mapa de mensagem para uma classe de modelo

Mapeamento de mensagem no MFC fornece uma maneira eficiente de direcionar mensagens do Windows para uma instância de objeto C++ apropriada. Classes de aplicativo, classes de documento e exibição, classes de controle e assim por diante são exemplos de destinos de mapa de mensagem do MFC.

Mapas de mensagem tradicionais do MFC são declarados usando o [BEGIN_MESSAGE_MAP](reference/message-map-macros-mfc.md#begin_message_map) macro para declarar o início do mapa de mensagens, uma entrada de macro para cada método de classe de manipulador de mensagens e, finalmente, o [END_MESSAGE_MAP](reference/message-map-macros-mfc.md#end_message_map)macro para declarar o final do mapa de mensagens.

Uma limitação com o [BEGIN_MESSAGE_MAP](reference/message-map-macros-mfc.md#begin_message_map) macro ocorre quando ele é usado em conjunto com uma classe que contém os argumentos de modelo. Quando usado com uma classe de modelo, essa macro fará com que um erro de tempo de compilação devido a parâmetros de modelo ausentes durante a expansão de macro. O [BEGIN_TEMPLATE_MESSAGE_MAP](reference/message-map-macros-mfc.md#begin_template_message_map) macro foi projetada para permitir que mapeia as classes que contêm um argumento de modelo único para declarar suas próprias mensagens.

## <a name="example"></a>Exemplo

Considere um exemplo em que o MFC [CListBox](../mfc/reference/clistbox-class.md) classe é estendida para fornecer sincronização com uma fonte de dados externa. A empresa fictícia `CSyncListBox` classe é declarada da seguinte maneira:

[!code-cpp[NVC_MFC_CListBox#42](../mfc/codesnippet/cpp/how-to-create-a-message-map-for-a-template-class_1.h)]

O `CSyncListBox` classe é modelada em um único tipo que descreve a fonte de dados, ele é sincronizado com o. Ele também declara três métodos que farão parte de um mapa de mensagens da classe: `OnPaint`, `OnDestroy`, e `OnSynchronize`. O `OnSynchronize` método é implementado da seguinte maneira:

[!code-cpp[NVC_MFC_CListBox#43](../mfc/codesnippet/cpp/how-to-create-a-message-map-for-a-template-class_2.cpp)]

A implementação acima permite que o `CSyncListBox` classe ser especializados em qualquer tipo de classe que implementa o `GetCount` método, como `CArray`, `CList`, e `CMap`. O `StringizeElement` é uma função de modelo com o protótipo a seguir:

[!code-cpp[NVC_MFC_CListBox#44](../mfc/codesnippet/cpp/how-to-create-a-message-map-for-a-template-class_3.cpp)]

Normalmente, o mapa de mensagens para essa classe seria definido como:

```cpp
BEGIN_MESSAGE_MAP(CSyncListBox, CListBox)
  ON_WM_PAINT()
  ON_WM_DESTROY()
  ON_MESSAGE(LBN_SYNCHRONIZE, OnSynchronize)
END_MESSAGE_MAP()
```

em que **LBN_SYNCHRONIZE** é uma mensagem de usuário personalizado definida pelo aplicativo, tais como:

[!code-cpp[NVC_MFC_CListBox#45](../mfc/codesnippet/cpp/how-to-create-a-message-map-for-a-template-class_4.cpp)]

O mapa de macro acima não será compilado, devido ao fato de que a especificação de modelo para o `CSyncListBox` classe estarão ausente durante a expansão de macro. O **BEGIN_TEMPLATE_MESSAGE_MAP** macro resolve esse problema incorporando o parâmetro de modelo especificado no mapa de macro expandida. Mapa de mensagens para essa classe se torna:

[!code-cpp[NVC_MFC_CListBox#46](../mfc/codesnippet/cpp/how-to-create-a-message-map-for-a-template-class_5.cpp)]

A seguir demonstra o uso de exemplo do `CSyncListBox` classe usando um `CStringList` objeto:

[!code-cpp[NVC_MFC_CListBox#47](../mfc/codesnippet/cpp/how-to-create-a-message-map-for-a-template-class_6.cpp)]

Para concluir o teste, o `StringizeElement` função deve ser especializada para trabalhar com o `CStringList` classe:

[!code-cpp[NVC_MFC_CListBox#48](../mfc/codesnippet/cpp/how-to-create-a-message-map-for-a-template-class_7.cpp)]

## <a name="see-also"></a>Consulte também

[BEGIN_TEMPLATE_MESSAGE_MAP](reference/message-map-macros-mfc.md#begin_template_message_map)<br/>
[Tratamento e mapeamento de mensagem](../mfc/message-handling-and-mapping.md)
