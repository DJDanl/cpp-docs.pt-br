---
title: Criando coleções de pilhas e filas
ms.date: 11/04/2016
helpviewer_keywords:
- MFC collection classes [MFC], stack collections
- collections, stack
- stack
- collection classes [MFC], creating
- queue collections
- MFC collection classes [MFC], queue collections
- stack collections
- collections, queue
ms.assetid: 3c7bc198-35f0-4fc3-aaed-6005a0f22638
ms.openlocfilehash: 5b3427f7bb2e46435ddf2768bcbb816f9d7e5c1a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371600"
---
# <a name="creating-stack-and-queue-collections"></a>Criando coleções de pilhas e filas

Este artigo explica como criar outras estruturas de dados, como [pilhas](#_core_stacks) e [filas,](#_core_queues)a partir de classes de listas de MFC. Os exemplos usam classes `CList`derivadas, mas `CList` você pode usar diretamente, a menos que precise adicionar funcionalidade.

## <a name="stacks"></a><a name="_core_stacks"></a>Pilhas

Como a coleção de listas padrão tem uma cabeça e uma cauda, é fácil criar uma coleção de listas derivadas que imita o comportamento de uma pilha de última entrada. Uma pilha é como uma pilha de bandejas em uma cafeteria. À medida que as bandejas são adicionadas à pilha, elas vão para cima da pilha. A última bandeja adicionada é a primeira a ser removida. O membro da `AddHead` coleção `RemoveHead` de listas funciona e pode ser usado para adicionar e remover elementos especificamente do chefe da lista; assim, o elemento adicionado mais recentemente é o primeiro a ser removido.

#### <a name="to-create-a-stack-collection"></a>Para criar uma coleção de pilhas

1. Obtenha uma nova classe de lista de uma das classes de lista mfc existentes e adicione mais funções de membro para suportar a funcionalidade das operações de pilha.

   O exemplo a seguir mostra como adicionar funções de membro para empurrar elementos para a pilha, espiar o elemento superior da pilha e colocar o elemento superior da pilha:

   [!code-cpp[NVC_MFCCollections#20](../mfc/codesnippet/cpp/creating-stack-and-queue-collections_1.h)]

Observe que esta abordagem `CObList` expõe a classe subjacente. O usuário pode `CObList` chamar qualquer função de membro, quer faça sentido para uma pilha ou não.

## <a name="queues"></a>Filas do <a name="_core_queues"></a>

Como a coleção de listas padrão tem uma cabeça e uma cauda, também é fácil criar uma coleção de listas derivadas que imita o comportamento de uma fila de primeira entrada. Uma fila é como uma fila de pessoas em uma cafeteria. A primeira pessoa na fila é a primeira a ser atendida. À medida que mais pessoas vêm, eles vão para o fim da linha para esperar sua vez. O membro da `AddTail` coleção `RemoveHead` de listas funciona e pode ser usado para adicionar e remover elementos especificamente da cabeça ou cauda da lista; assim, o elemento adicionado mais recentemente é sempre o último a ser removido.

#### <a name="to-create-a-queue-collection"></a>Para criar uma coleção de filas

1. Obtenha uma nova classe de lista de uma das classes de lista predefinidas fornecidas com a Biblioteca de Classes da Microsoft Foundation e adicione mais funções de membros para suportar a semântica das operações de fila.

   O exemplo a seguir mostra como você pode anexar funções de membro para adicionar um elemento ao final da fila e obter o elemento da frente da fila.

   [!code-cpp[NVC_MFCCollections#21](../mfc/codesnippet/cpp/creating-stack-and-queue-collections_2.h)]

## <a name="see-also"></a>Confira também

[Coleções](../mfc/collections.md)
