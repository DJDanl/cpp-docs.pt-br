---
title: Classes de matriz, lista e mapa
ms.date: 11/04/2016
helpviewer_keywords:
- arrays [MFC], classes
- list classes [MFC]
- collection classes [MFC], maps
- map classes [MFC]
- collection classes [MFC], lists
ms.assetid: 81a13a7f-0c2c-4efd-b6bb-b4e624a0743d
ms.openlocfilehash: f5fe4acb35074e924555029d715ccbc23b55f49a
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79446503"
---
# <a name="array-list-and-map-classes"></a>Classes de matriz, lista e mapa

Para lidar com agregações de dados, a biblioteca de classes fornece um grupo de classes de coleção (matrizes, listas e mapas) que pode conter uma variedade de objetos e tipos predefinidos. As coleções são dimensionadas dinamicamente. Essas classes podem ser usadas em qualquer programa, sejam elas escritas para Windows ou não. No entanto, elas são mais úteis para implementar as estruturas de dados que definem suas classes de documento na estrutura do aplicativo. Você pode rapidamente derivar classes de coleção especializadas desses ou pode criá-las com base nas classes de modelo. Para obter mais informações sobre essas abordagens, consulte o artigo [coleções](../mfc/collections.md). Para obter uma lista das classes de coleção de modelos, consulte o artigo [classes de modelo para matrizes, listas e mapas](../mfc/template-classes-for-arrays-lists-and-maps.md).

As matrizes são estruturas de dados unidimensionais que são armazenadas de forma contígua na memória. Eles dão suporte a acesso aleatório muito rápido, pois o endereço de memória de qualquer elemento pode ser calculado multiplicando o índice do elemento pelo tamanho de um elemento e adicionando o resultado ao endereço base da matriz. Mas as matrizes são muito caras se você precisa inserir elementos na matriz, já que a matriz inteira após o elemento inserido precisa ser movida para liberar espaço para o elemento a ser inserido. As matrizes podem aumentar e reduzir conforme necessário.

As listas são semelhantes às matrizes, mas são armazenadas de forma muito diferente. Cada elemento em uma lista também inclui um ponteiro para os elementos anteriores e seguintes, tornando-o uma lista de links duplas. É muito rápido adicionar ou excluir itens, pois fazer isso envolve apenas a alteração de algumas ponteiros. No entanto, a pesquisa de uma lista pode ser cara, já que todas as pesquisas precisam ser iniciadas em uma das extremidades da lista.

Os mapas relacionam um valor de chave a um valor de dados. Por exemplo, a chave de um mapa pode ser uma cadeia de caracteres e os dados de um ponteiro em uma lista. Você pediria ao mapa que lhe dê o ponteiro associado a uma cadeia de caracteres específica. As pesquisas de mapa são rápidas porque os mapas usam tabelas de hash para pesquisas de chave. Adicionar e excluir itens também é rápido. Os mapas são frequentemente usados com outras estruturas de dados como índices auxiliares. O MFC usa um tipo especial de mapa chamado de [mapa de mensagens](../mfc/mapping-messages.md) para mapear mensagens do Windows para um ponteiro para a função de manipulador para essa mensagem.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)
