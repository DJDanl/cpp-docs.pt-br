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
ms.openlocfilehash: 5db90422f78fc6ca3bc2a182f9569c33db56cad1
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84623218"
---
# <a name="creating-stack-and-queue-collections"></a>Criando coleções de pilhas e filas

Este artigo explica como criar outras estruturas de dados, como [pilhas](#_core_stacks) e [filas](#_core_queues), de classes de lista do MFC. Os exemplos usam classes derivadas de `CList` , mas você pode usar `CList` diretamente, a menos que precise adicionar funcionalidade.

## <a name="stacks"></a><a name="_core_stacks"></a>Pilhas

Como a coleção de listas padrão tem tanto um cabeçalho quanto uma parte final, é fácil criar uma coleção de lista derivada que imita o comportamento de uma pilha de último a entrar, primeiro a sair. Uma pilha é como uma pilha de bandejas em uma lanchonete. À medida que as bandejas são adicionadas à pilha, elas são passadas para cima da pilha. A última bandeja adicionada é a primeira a ser removida. As funções de membro da coleção de lista `AddHead` e `RemoveHead` podem ser usadas para adicionar e remover elementos especificamente do início da lista; portanto, o elemento adicionado mais recentemente é o primeiro a ser removido.

#### <a name="to-create-a-stack-collection"></a>Para criar uma coleção de pilha

1. Derive uma nova classe List de uma das classes de lista MFC existentes e adicione mais funções de membro para dar suporte à funcionalidade de operações de pilha.

   O exemplo a seguir mostra como adicionar funções de membro para enviar elementos por push para a pilha, espiar no elemento superior da pilha e pop-up do elemento superior da pilha:

   [!code-cpp[NVC_MFCCollections#20](codesnippet/cpp/creating-stack-and-queue-collections_1.h)]

Observe que essa abordagem expõe a `CObList` classe subjacente. O usuário pode chamar qualquer `CObList` função de membro, quer faça sentido para uma pilha ou não.

## <a name="queues"></a>Filas do <a name="_core_queues"></a>

Como a coleção de listas padrão tem um cabeçalho e uma parte final, também é fácil criar uma coleção de lista derivada que imita o comportamento de uma fila de primeiro a entrar, primeiro a sair. Uma fila é como uma linha de pessoas em uma lanchonete. A primeira pessoa na linha é a primeira a ser servida. À medida que mais pessoas chegam, elas vão até o final da linha para aguardar a sua rodada. As funções de membro de coleção de lista `AddTail` e `RemoveHead` podem ser usadas para adicionar e remover elementos especificamente do cabeçalho ou da parte final da lista; portanto, o elemento adicionado mais recentemente é sempre o último a ser removido.

#### <a name="to-create-a-queue-collection"></a>Para criar uma coleção de filas

1. Derive uma nova classe List de uma das classes de lista predefinidas fornecidas com o biblioteca MFC e adicione mais funções de membro para dar suporte à semântica de operações de fila.

   O exemplo a seguir mostra como você pode acrescentar funções de membro para adicionar um elemento ao final da fila e obter o elemento da frente da fila.

   [!code-cpp[NVC_MFCCollections#21](codesnippet/cpp/creating-stack-and-queue-collections_2.h)]

## <a name="see-also"></a>Consulte também

[Coleções](collections.md)
