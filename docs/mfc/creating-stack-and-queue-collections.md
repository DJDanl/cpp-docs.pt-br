---
title: Criando coleções de pilhas e filas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5545a1803675965cdea716e009ab70d2d72a31f4
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="creating-stack-and-queue-collections"></a>Criando coleções de pilhas e filas
Este artigo explica como criar outras estruturas de dados, como [pilhas](#_core_stacks) e [filas](#_core_queues), lista de classes do MFC. Os exemplos usam classes derivadas de `CList`, mas você pode usar `CList` diretamente, a menos que você precisa adicionar funcionalidade.  
  
##  <a name="_core_stacks"></a> Pilhas  
 Como a coleção de lista padrão tem um cabeçalho e uma final, é fácil criar uma coleção de lista derivada que imita o comportamento de uma pilha de último a entrar, primeiro a sair. Uma pilha é como uma pilha de bandejas em uma lanchonete. Como bandejas são adicionadas para a pilha, que entram na parte superior da pilha. Bandeja do último adicionada será o primeiro a ser removido. As funções de membro de coleção lista `AddHead` e `RemoveHead` podem ser usados para adicionar e remover elementos especificamente do início da lista; assim, mais recentemente adicionado elemento é o primeiro a ser removido.  
  
#### <a name="to-create-a-stack-collection"></a>Para criar uma coleção de pilha  
  
1.  Derivar uma nova classe de lista de uma das classes de lista MFC existentes e adicionar mais funções de membro para oferecer suporte à funcionalidade de operações de pilha.  
  
     O exemplo a seguir mostra como adicionar funções de membro para enviar elementos na pilha, inspecionar o elemento superior da pilha e inserir o elemento superior da pilha:  
  
     [!code-cpp[NVC_MFCCollections#20](../mfc/codesnippet/cpp/creating-stack-and-queue-collections_1.h)]  
  
 Observe que essa abordagem expõe subjacente `CObList` classe. O usuário pode chamar qualquer `CObList` função de membro, se ele faz sentido para uma pilha ou não.  
  
##  <a name="_core_queues"></a> Filas  
 Como a coleção de lista padrão tem um cabeçalho e uma final, também é fácil criar uma coleção de lista derivada que imita o comportamento de uma fila primeiro a entrar, primeiro a sair. Uma fila é como uma linha de pessoas em uma lanchonete. A primeira pessoa na linha é o primeiro a ser servido. À medida que mais pessoas, eles vá até o final da linha para aguardar sua vez. As funções de membro de coleção lista `AddTail` e `RemoveHead` podem ser usados para adicionar e remover elementos especificamente do início ou final da lista; assim, mais recentemente adicionado elemento é sempre a última a ser removido.  
  
#### <a name="to-create-a-queue-collection"></a>Para criar uma coleção de fila  
  
1.  Derivar uma nova classe de lista de uma das classes de lista predefinidos fornecidas com a biblioteca Microsoft Foundation Class e adicionar mais funções de membro para oferecer suporte a semântica de operações de fila.  
  
     O exemplo a seguir mostra como você pode acrescentar funções de membro para adicionar um elemento ao final da fila e obter o elemento do início da fila.  
  
     [!code-cpp[NVC_MFCCollections#21](../mfc/codesnippet/cpp/creating-stack-and-queue-collections_2.h)]  
  
## <a name="see-also"></a>Consulte também  
 [Coleções](../mfc/collections.md)

