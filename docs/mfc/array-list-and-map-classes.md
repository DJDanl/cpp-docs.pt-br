---
title: Matriz, lista e, em seguida, mapear Classes | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.classes.mfc
dev_langs:
- C++
helpviewer_keywords:
- arrays [MFC], classes
- list classes [MFC]
- collection classes [MFC], maps
- map classes [MFC]
- collection classes [MFC], lists
ms.assetid: 81a13a7f-0c2c-4efd-b6bb-b4e624a0743d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 41dfe0b36548d87b5e0501c557e70f3cf11eea5d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="array-list-and-map-classes"></a>Classes de matriz, lista e mapa
Para tratar de agregações de dados, a biblioteca de classe fornece um grupo de classes de coleção – matrizes, listas e mapas — que pode conter uma variedade de tipos predefinidos e objeto. As coleções são dimensionadas dinamicamente. Essas classes podem ser usadas em qualquer programa, se escritos para o Windows ou não. No entanto, eles são mais úteis para implementar as estruturas de dados que definem as classes de documento na estrutura de aplicativo. Você pode facilmente derivar classes de coleção especializadas esses, ou você pode criá-los com base nas classes de modelo. Para obter mais informações sobre esses métodos, consulte o artigo [coleções](../mfc/collections.md). Para obter uma lista das classes de coleção do modelo, consulte o artigo [Classes de modelo para matrizes, listas e mapas](../mfc/template-classes-for-arrays-lists-and-maps.md).  
  
 As matrizes são estruturas de dados unidimensional que são armazenadas de forma contígua na memória. Dão suporte a acesso aleatório muito rápido porque o endereço de memória de um determinado elemento pode ser calculado multiplicando o índice do elemento o tamanho de um elemento e adicionando o resultado para o endereço base da matriz. Mas matrizes são muito caras de se você precisa inserir elementos na matriz, pois a matriz inteira últimos o elemento inserido deve ser movida para liberar espaço para o elemento a ser inserido. Matrizes podem aumentar ou diminuir conforme necessário.  
  
 Listas são semelhantes a matrizes, mas são armazenadas de forma muito diferente. Cada elemento em uma lista também inclui um ponteiro para os elementos anteriores e posteriores, tornando-a como uma lista duplamente vinculada. É muito rápido para adicionar ou excluir itens porque isso envolve apenas alguns ponteiros a alteração. No entanto, a pesquisa de uma lista pode ser cara, já que todas as pesquisas começam em uma das extremidades da lista.  
  
 Mapas estão relacionados a um valor de chave para um valor de dados. Por exemplo, a chave de um mapa pode ser uma cadeia de caracteres e um ponteiro para uma lista de dados. É preciso fazer o mapa para dar a você o ponteiro associado com uma cadeia de caracteres específica. Pesquisas de mapa são rápidas porque os mapas usam tabelas de hash para pesquisas de chave. Adicionando e excluindo itens também são rápida. Mapas são geralmente usados com outras estruturas de dados como índices auxiliares. MFC usa um tipo especial de mapa chamado um [mapa de mensagem](../mfc/mapping-messages.md) para mapear as mensagens do Windows para um ponteiro para a função de manipulador para essa mensagem.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)

