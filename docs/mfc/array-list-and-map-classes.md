---
title: Classes de matriz, lista e mapa
ms.date: 11/04/2016
f1_keywords:
- vc.classes.mfc
helpviewer_keywords:
- arrays [MFC], classes
- list classes [MFC]
- collection classes [MFC], maps
- map classes [MFC]
- collection classes [MFC], lists
ms.assetid: 81a13a7f-0c2c-4efd-b6bb-b4e624a0743d
ms.openlocfilehash: 0856a9de06d07b3851dc748644e84ba9c4b56c4f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50601039"
---
# <a name="array-list-and-map-classes"></a>Classes de matriz, lista e mapa

Para manipular agregações de dados, a biblioteca de classes fornece um grupo de classes de coleção – matrizes, listas e mapas — que pode conter uma variedade de tipos predefinidos e objeto. As coleções são dimensionadas dinamicamente. Essas classes podem ser usadas em qualquer programa, independentemente se escritos para Windows ou não. No entanto, eles são mais úteis para implementar as estruturas de dados que definem suas classes de documento em que a estrutura de aplicativo. Você prontamente pode derivar classes de coleção especializada desses, ou você pode criá-los com base em classes de modelo. Para obter mais informações sobre essas abordagens, consulte o artigo [coleções](../mfc/collections.md). Para obter uma lista das classes de coleção de modelo, consulte o artigo [Classes de modelo para matrizes, listas e mapas](../mfc/template-classes-for-arrays-lists-and-maps.md).

Matrizes são estruturas de dados unidimensional que são armazenadas contiguamente na memória. Eles oferecem suporte acesso aleatório muito rápido, pois o endereço de memória de qualquer determinado elemento pode ser calculado multiplicando o índice do elemento pelo tamanho de um elemento e adicionar o resultado para o endereço básico da matriz. Mas matrizes são muito caras, se você tiver que inserir elementos na matriz, desde a últimos toda a matriz elemento inserido deve ser movida para liberar espaço para o elemento a ser inserido. Matrizes podem aumentar e reduzir conforme necessário.

Listas são semelhantes a matrizes, mas são armazenadas de forma muito diferente. Cada elemento em uma lista também inclui um ponteiro para os elementos anteriores e seguintes, tornando-a como uma lista duplamente vinculada. É muito rápido para adicionar ou excluir itens, porque isso envolve apenas alterando alguns ponteiros. No entanto, a pesquisa em uma lista pode ser caro, pois todas as pesquisas precisam iniciar em uma das extremidades da lista.

Mapas se relacionam a um valor de chave com um valor de dados. Por exemplo, a chave de um mapa pode ser uma cadeia de caracteres e os dados de um ponteiro para uma lista. Você deve pedir o mapa para lhe dar o ponteiro associado a uma determinada cadeia de caracteres. Pesquisas de mapa são rápidas porque os mapas usam tabelas de hash para pesquisas de chave. Adicionar e excluir itens também são rápida. Mapas geralmente são usados com outras estruturas de dados, como índices auxiliares. Um tipo especial de mapa chamado o MFC usa um [mapa de mensagem](../mfc/mapping-messages.md) para mapear as mensagens do Windows para um ponteiro para a função do manipulador para a mensagem.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)

