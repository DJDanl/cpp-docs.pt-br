---
title: Como criar um mapa de mensagem para uma classe de modelo
ms.date: 11/04/2016
helpviewer_keywords:
- template classes [MFC], creating message maps
- message maps [MFC], template classes
ms.assetid: 4e7e24f8-06df-4b46-82aa-7435c8650de3
ms.openlocfilehash: 65ddc77b4e8fd466c7d651e54e93a504b4858da1
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84620060"
---
# <a name="how-to-create-a-message-map-for-a-template-class"></a>Como criar um mapa de mensagem para uma classe de modelo

O mapeamento de mensagens no MFC fornece uma maneira eficiente de direcionar mensagens do Windows para uma instância de objeto C++ apropriada. Exemplos de destinos do mapa de mensagens do MFC incluem classes de aplicativo, classes de documento e exibição, classes de controle e assim por diante.

Os mapas de mensagens do MFC tradicionais são declarados usando a macro [BEGIN_MESSAGE_MAP](reference/message-map-macros-mfc.md#begin_message_map) para declarar o início do mapa de mensagens, uma entrada de macro para cada método de classe de manipulador de mensagens e, por fim, a macro [END_MESSAGE_MAP](reference/message-map-macros-mfc.md#end_message_map) para declarar o final do mapa de mensagens.

Uma limitação com a macro [BEGIN_MESSAGE_MAP](reference/message-map-macros-mfc.md#begin_message_map) ocorre quando ela é usada em conjunto com uma classe que contém argumentos de modelo. Quando usado com uma classe de modelo, essa macro causará um erro de tempo de compilação devido aos parâmetros de modelo ausentes durante a expansão de macro. A macro [BEGIN_TEMPLATE_MESSAGE_MAP](reference/message-map-macros-mfc.md#begin_template_message_map) foi projetada para permitir que classes contendo um único argumento de modelo declarem seus próprios mapas de mensagem.

## <a name="example"></a>Exemplo

Considere um exemplo em que a classe MFC [CListBox](reference/clistbox-class.md) é estendida para fornecer sincronização com uma fonte de dados externa. A `CSyncListBox` classe fictícia é declarada da seguinte maneira:

[!code-cpp[NVC_MFC_CListBox#42](codesnippet/cpp/how-to-create-a-message-map-for-a-template-class_1.h)]

A `CSyncListBox` classe é modelada em um único tipo que descreve a fonte de dados com a qual ela será sincronizada. Ele também declara três métodos que participarão do mapa de mensagens da classe: `OnPaint` , `OnDestroy` e `OnSynchronize` . O `OnSynchronize` método é implementado da seguinte maneira:

[!code-cpp[NVC_MFC_CListBox#43](codesnippet/cpp/how-to-create-a-message-map-for-a-template-class_2.cpp)]

A implementação acima permite que a `CSyncListBox` classe seja especializada em qualquer tipo de classe que implemente o `GetCount` método, como `CArray` , `CList` e `CMap` . A `StringizeElement` função é uma função de modelo com protótipos do seguinte:

[!code-cpp[NVC_MFC_CListBox#44](codesnippet/cpp/how-to-create-a-message-map-for-a-template-class_3.cpp)]

Normalmente, o mapa de mensagens para essa classe seria definido como:

```cpp
BEGIN_MESSAGE_MAP(CSyncListBox, CListBox)
  ON_WM_PAINT()
  ON_WM_DESTROY()
  ON_MESSAGE(LBN_SYNCHRONIZE, OnSynchronize)
END_MESSAGE_MAP()
```

em que **LBN_SYNCHRONIZE** é uma mensagem de usuário personalizada definida pelo aplicativo, como:

[!code-cpp[NVC_MFC_CListBox#45](codesnippet/cpp/how-to-create-a-message-map-for-a-template-class_4.cpp)]

O mapa de macro acima não será compilado, devido ao fato de que a especificação de modelo para a `CSyncListBox` classe estará ausente durante a expansão da macro. A macro **BEGIN_TEMPLATE_MESSAGE_MAP** resolve isso incorporando o parâmetro de modelo especificado ao mapa de macro expandido. O mapa de mensagens para essa classe se torna:

[!code-cpp[NVC_MFC_CListBox#46](codesnippet/cpp/how-to-create-a-message-map-for-a-template-class_5.cpp)]

O exemplo a seguir demonstra o uso da `CSyncListBox` classe usando um `CStringList` objeto:

[!code-cpp[NVC_MFC_CListBox#47](codesnippet/cpp/how-to-create-a-message-map-for-a-template-class_6.cpp)]

Para concluir o teste, a `StringizeElement` função deve ser especializada para trabalhar com a `CStringList` classe:

[!code-cpp[NVC_MFC_CListBox#48](codesnippet/cpp/how-to-create-a-message-map-for-a-template-class_7.cpp)]

## <a name="see-also"></a>Consulte também

[BEGIN_TEMPLATE_MESSAGE_MAP](reference/message-map-macros-mfc.md#begin_template_message_map)<br/>
[Tratamento e mapeamento de mensagem](message-handling-and-mapping.md)
