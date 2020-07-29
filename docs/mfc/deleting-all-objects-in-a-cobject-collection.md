---
title: Excluindo todos os objetos em uma coleção CObject
ms.date: 11/04/2016
helpviewer_keywords:
- objects [MFC], deleting in collections
- objects in CObject collections, deleting
- CObject class [MFC], deleting in collection
- collection classes [MFC], deleting all objects
- CObject class collection
- objects in CObject collections
- collection classes [MFC], shared objects
ms.assetid: 81d2c1d5-a0a5-46e1-8ab9-82b45cf7afd2
ms.openlocfilehash: 5aac324b6af50db019c2a4b55b26a612cc081894
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225066"
---
# <a name="deleting-all-objects-in-a-cobject-collection"></a>Excluindo todos os objetos em uma coleção CObject

Este artigo explica como excluir todos os objetos em uma coleção (sem excluir o objeto de coleção em si).

Para excluir todos os objetos em uma coleção de `CObject` s (ou de objetos derivados de `CObject` ), use uma das técnicas de iteração descritas no artigo [acessando todos os membros de uma coleção](accessing-all-members-of-a-collection.md) para excluir cada objeto por vez.

> [!CAUTION]
> Os objetos em coleções podem ser compartilhados. Ou seja, a coleção mantém um ponteiro para o objeto, mas outras partes do programa também podem ter ponteiros para o mesmo objeto. Você deve ter cuidado para não excluir um objeto que é compartilhado até que todas as partes terminem de usar o objeto.

Este artigo mostra como excluir os objetos no:

- [Uma lista](#_core_to_delete_all_objects_in_a_list_of_pointers_to_cobject)

- [Uma matriz](#_core_to_delete_all_elements_in_an_array)

- [Um mapa](#_core_to_delete_all_elements_in_a_map)

#### <a name="to-delete-all-objects-in-a-list-of-pointers-to-cobject"></a><a name="_core_to_delete_all_objects_in_a_list_of_pointers_to_cobject"></a>Para excluir todos os objetos em uma lista de ponteiros para CObject

1. Use `GetHeadPosition` e `GetNext` para iterar na lista.

1. Use o **`delete`** operador para excluir cada objeto conforme ele for encontrado na iteração.

1. Chame a `RemoveAll` função para remover todos os elementos da lista depois que os objetos associados a esses elementos tiverem sido excluídos.

O exemplo a seguir mostra como excluir todos os objetos de uma lista de `CPerson` objetos. Cada objeto na lista é um ponteiro para um `CPerson` objeto que foi originalmente alocado no heap.

[!code-cpp[NVC_MFCCollections#17](codesnippet/cpp/deleting-all-objects-in-a-cobject-collection_1.cpp)]

A última chamada de função, `RemoveAll` , é uma função de membro de lista que remove todos os elementos da lista. A função de membro `RemoveAt` Remove um único elemento.

Observe a diferença entre excluir o objeto de um elemento e remover o próprio elemento. Remover um elemento da lista simplesmente remove a referência da lista para o objeto. O objeto ainda existe na memória. Quando você exclui um objeto, ele deixa de existir e sua memória é recuperada. Portanto, é importante remover um elemento imediatamente após o objeto do elemento ter sido excluído para que a lista não tente acessar objetos que não existem mais.

#### <a name="to-delete-all-elements-in-an-array"></a><a name="_core_to_delete_all_elements_in_an_array"></a>Para excluir todos os elementos em uma matriz

1. Use `GetSize` e valores de índice inteiro para iterar na matriz.

1. Use o **`delete`** operador para excluir cada elemento conforme ele for encontrado na iteração.

1. Chame a `RemoveAll` função para remover todos os elementos da matriz depois que eles tiverem sido excluídos.

   O código para excluir todos os elementos de uma matriz é o seguinte:

   [!code-cpp[NVC_MFCCollections#18](codesnippet/cpp/deleting-all-objects-in-a-cobject-collection_2.cpp)]

Assim como no exemplo de lista acima, você pode chamar `RemoveAll` para remover todos os elementos em uma matriz ou `RemoveAt` remover um elemento individual.

#### <a name="to-delete-all-elements-in-a-map"></a><a name="_core_to_delete_all_elements_in_a_map"></a>Para excluir todos os elementos em um mapa

1. Use `GetStartPosition` e `GetNextAssoc` para iterar na matriz.

1. Use o **`delete`** operador para excluir a chave e/ou o valor de cada elemento do mapa, pois ele é encontrado na iteração.

1. Chame a `RemoveAll` função para remover todos os elementos do mapa depois que eles tiverem sido excluídos.

   O código para excluir todos os elementos de uma `CMap` coleção é o seguinte. Cada elemento no mapa tem uma cadeia de caracteres como a chave e um `CPerson` objeto (derivado de `CObject` ) como o valor.

   [!code-cpp[NVC_MFCCollections#19](codesnippet/cpp/deleting-all-objects-in-a-cobject-collection_3.cpp)]

Você pode chamar `RemoveAll` para remover todos os elementos em um mapa ou `RemoveKey` remover um elemento individual com a chave especificada.

## <a name="see-also"></a>Confira também

[Acessando todos os membros de uma coleção](accessing-all-members-of-a-collection.md)
