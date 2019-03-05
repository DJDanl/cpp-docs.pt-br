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
ms.openlocfilehash: ed0ad9b98a69e56df4e66b25bc6ca08cdaaad413
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57301461"
---
# <a name="creating-stack-and-queue-collections"></a>Criando coleções de pilhas e filas

Este artigo explica como criar outras estruturas de dados, tais como [pilhas](#_core_stacks) e [filas](#_core_queues), da MFC classes de lista. Os exemplos usam classes derivadas `CList`, mas você pode usar `CList` diretamente, a menos que você precisa adicionar a funcionalidade.

##  <a name="_core_stacks"></a> Stacks

Como a coleção de lista padrão tem um cabeçalho e uma cauda, é fácil criar uma coleção de lista derivado que imita o comportamento de uma pilha de último a entrar, primeiro a sair. Uma pilha é como uma pilha de bandejas em uma lanchonete. Como bandejas são adicionadas à pilha, entram no topo da pilha. A bandeja do último adicionada é a primeira a ser removido. As funções de membro da coleção de lista `AddHead` e `RemoveHead` pode ser usado para adicionar e remover elementos especificamente do cabeçalho da lista; portanto, mais recentemente adicionado elemento é o primeiro a ser removido.

#### <a name="to-create-a-stack-collection"></a>Para criar uma coleção de pilha

1. Derivar uma nova classe de lista de uma das classes de lista MFC existentes e adicionar mais funções de membro para oferecer suporte a funcionalidade de operações de pilha.

   O exemplo a seguir mostra como adicionar funções de membro para elementos na pilha, inspecionar o elemento superior da pilha, de push e pop-o elemento superior da pilha:

   [!code-cpp[NVC_MFCCollections#20](../mfc/codesnippet/cpp/creating-stack-and-queue-collections_1.h)]

Observe que essa abordagem expõe subjacente `CObList` classe. O usuário pode chamar qualquer `CObList` função de membro, se faz sentido para uma pilha ou não.

##  <a name="_core_queues"></a> Filas

Como a coleção de lista padrão tem um cabeçalho e uma cauda, também é fácil criar uma coleção de lista derivado que imita o comportamento de uma fila primeiro a entrar, primeiro a sair. Uma fila é como uma linha de pessoas em uma lanchonete. A primeira pessoa em linha é o primeiro a ser atendido. À medida que mais pessoas, elas vá até o final da linha de esperar sua vez. As funções de membro da coleção de lista `AddTail` e `RemoveHead` pode ser usado para adicionar e remover elementos especificamente do início ou final da lista; assim, mais recentemente adicionado elemento sempre é a última a ser removido.

#### <a name="to-create-a-queue-collection"></a>Para criar uma coleção de fila

1. Derivar uma nova classe de lista de uma das classes de lista predefinidos fornecidas com a biblioteca Microsoft Foundation Class e adicionar mais funções de membro para oferecer suporte a semântica das operações de fila.

   O exemplo a seguir mostra como você pode acrescentar funções de membro para adicionar um elemento ao final da fila e obter o elemento do início da fila.

   [!code-cpp[NVC_MFCCollections#21](../mfc/codesnippet/cpp/creating-stack-and-queue-collections_2.h)]

## <a name="see-also"></a>Consulte também

[Coleções](../mfc/collections.md)
