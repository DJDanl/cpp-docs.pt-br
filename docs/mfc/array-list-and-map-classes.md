---
title: "Classes de matriz, lista e mapa | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.classes.mfc"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "matrizes [C++], Classes "
  - "classes de coleção, listas"
  - "classes de coleção, mapas"
  - "classes de lista"
  - "classes de mapa"
ms.assetid: 81a13a7f-0c2c-4efd-b6bb-b4e624a0743d
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de matriz, lista e mapa
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para tratar agregações de dados, a biblioteca de classe fornece um grupo de classes de coleção — matrizes, listas, mapas e — que podem manter uma variedade de objeto e tipos predefinidos.  As coleções são feitas dimensionar dinamicamente.  Essas classes podem ser usadas em qualquer programa, se registrado do windows ou não.  No entanto, eles são os mais úteis para implementar as estruturas de dados que definem suas classes do documento na estrutura de aplicativo.  Você pode derivar prontamente especializadas classes de coleção disso, ou é possível criar com base nas classes de modelo.  Para obter mais informações sobre essas abordagens, consulte o artigo [Coleções](../mfc/collections.md).  Para obter uma lista das classes de coleção de modelo, consulte o artigo [Classes de modelo para matrizes, listas, e mapas](../mfc/template-classes-for-arrays-lists-and-maps.md).  
  
 As matrizes são as estruturas de dados unidimensional que são armazenadas contiguamente na memória.  Suporte de acesso aleatório muito rápida porque o endereço de memória de qualquer elemento determinado pode ser calculado multiplicando o índice do elemento pelo tamanho de um elemento e adicionando o resultado para o endereço base da matriz.  Mas as matrizes são muito caras se você precisar inserir os elementos na matriz, desde que a matriz inteira depois do elemento inserido tem que ser movida para liberar espaço para que o elemento a ser inserido.  As matrizes podem aumentar e reduzir conforme necessário.  
  
 Listas são semelhantes às matrizes mas são armazenadas de forma muito diferente.  Cada elemento em uma lista também inclui um ponteiro para os elementos anteriores e seguintes, transformando\-o em uma lista vinculada double.  É muito rapidamente adicionar ou excluir itens como fazer isso envolve alterar apenas alguns dos ponteiros.  No entanto, para pesquisar uma lista pode ser dispendiosa desde que todas as pesquisas precisam começar em uma das extremidades da lista.  
  
 Os mapas relacionam um valor de chave para um valor de dados.  Por exemplo, a chave de um mapa pode ser uma cadeia de caracteres e os dados de um ponteiro em uma lista.  Você solicita o mapa para proporcionar o ponteiro associado a uma cadeia de caracteres específico.  As pesquisas do mapa são rápidas porque o hash dos mapas \- tabelas para pesquisas de chave.  Adicionar e excluir itens também são rápidas.  Os mapas são usados com frequência com outras estruturas de dados como índices auxiliares.  MFC O usa um tipo especial do mapa chamado [mapa de mensagem](../mfc/mapping-messages.md) para mapear mensagens do windows a um ponteiro para a função de manipulador para essa mensagem.  
  
## Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)