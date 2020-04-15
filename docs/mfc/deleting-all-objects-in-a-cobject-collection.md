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
ms.openlocfilehash: 303b8a566a730c5abd06d51fb7977174e19a6435
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370532"
---
# <a name="deleting-all-objects-in-a-cobject-collection"></a>Excluindo todos os objetos em uma coleção CObject

Este artigo explica como excluir todos os objetos em uma coleção (sem excluir o objeto de coleta em si).

Para excluir todos os objetos em uma coleção `CObject` `CObject`de s (ou de objetos derivados), você usa uma das técnicas de iteração descritas no artigo [Acessando todos os membros de uma coleção](../mfc/accessing-all-members-of-a-collection.md) para excluir cada objeto por sua vez.

> [!CAUTION]
> Objetos em coleções podem ser compartilhados. Ou seja, a coleção mantém um ponteiro para o objeto, mas outras partes do programa também podem ter ponteiros para o mesmo objeto. Você deve ter cuidado para não excluir um objeto que é compartilhado até que todas as partes tenham terminado usando o objeto.

Este artigo mostra como excluir os objetos em:

- [Uma lista](#_core_to_delete_all_objects_in_a_list_of_pointers_to_cobject)

- [Uma matriz](#_core_to_delete_all_elements_in_an_array)

- [Um mapa](#_core_to_delete_all_elements_in_a_map)

#### <a name="to-delete-all-objects-in-a-list-of-pointers-to-cobject"></a><a name="_core_to_delete_all_objects_in_a_list_of_pointers_to_cobject"></a>Para excluir todos os objetos em uma lista de ponteiros para CObject

1. Use `GetHeadPosition` `GetNext` e iterrate através da lista.

1. Use o operador **de exclusão** para excluir cada objeto como ele é encontrado na iteração.

1. Chame `RemoveAll` a função para remover todos os elementos da lista depois que os objetos associados a esses elementos tiverem sido excluídos.

O exemplo a seguir mostra como excluir `CPerson` todos os objetos de uma lista de objetos. Cada objeto na lista é `CPerson` um ponteiro para um objeto que foi originalmente alocado no heap.

[!code-cpp[NVC_MFCCollections#17](../mfc/codesnippet/cpp/deleting-all-objects-in-a-cobject-collection_1.cpp)]

A última chamada `RemoveAll`de função, é uma função membro da lista que remove todos os elementos da lista. A função `RemoveAt` do membro remove um único elemento.

Observe a diferença entre excluir o objeto de um elemento e remover o elemento em si. A remoção de um elemento da lista apenas remove a referência da lista ao objeto. O objeto ainda existe na memória. Quando você exclui um objeto, ele deixa de existir e sua memória é recuperada. Assim, é importante remover um elemento imediatamente após o objeto do elemento ter sido excluído para que a lista não tente acessar objetos que não existem mais.

#### <a name="to-delete-all-elements-in-an-array"></a><a name="_core_to_delete_all_elements_in_an_array"></a>Para excluir todos os elementos em uma matriz

1. Use `GetSize` e os valores do índice inteiro para iterar através da matriz.

1. Use o operador **de exclusão** para excluir cada elemento como ele é encontrado na iteração.

1. Chame `RemoveAll` a função para remover todos os elementos da matriz depois de excluídos.

   O código para excluir todos os elementos de uma matriz é o seguinte:

   [!code-cpp[NVC_MFCCollections#18](../mfc/codesnippet/cpp/deleting-all-objects-in-a-cobject-collection_2.cpp)]

Como no exemplo da lista `RemoveAll` acima, você pode chamar `RemoveAt` para remover todos os elementos em uma matriz ou para remover um elemento individual.

#### <a name="to-delete-all-elements-in-a-map"></a><a name="_core_to_delete_all_elements_in_a_map"></a>Para excluir todos os elementos em um mapa

1. Use `GetStartPosition` `GetNextAssoc` e iterrate através da matriz.

1. Use o operador **de exclusão** para excluir a chave e/ou o valor de cada elemento do mapa, como ele é encontrado na iteração.

1. Chame `RemoveAll` a função para remover todos os elementos do mapa depois de excluídos.

   O código para excluir todos `CMap` os elementos de uma coleção é o seguinte. Cada elemento no mapa tem uma seqüência como chave e um `CPerson` objeto (derivado) `CObject`como o valor.

   [!code-cpp[NVC_MFCCollections#19](../mfc/codesnippet/cpp/deleting-all-objects-in-a-cobject-collection_3.cpp)]

Você pode `RemoveAll` ligar para remover todos `RemoveKey` os elementos em um mapa ou para remover um elemento individual com a chave especificada.

## <a name="see-also"></a>Confira também

[Acessando todos os membros de uma coleção](../mfc/accessing-all-members-of-a-collection.md)
