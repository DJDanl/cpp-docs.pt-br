---
title: Inicializando matrizes
ms.date: 11/04/2016
helpviewer_keywords:
- initializing arrays [C++]
- arrays [C++], initializing
ms.assetid: 41efe5f0-15b5-4f49-9196-c4902f8fc705
ms.openlocfilehash: e055e7759865fc151176097c6f0afd9ee237f4c1
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62183421"
---
# <a name="initializing-arrays"></a>Inicializando matrizes

Se a classe tiver um construtor, as matrizes dessa classe serão iniciadas por um construtor. Se houver menos itens na lista de inicializadores do que elementos na matriz, o construtor padrão será usado para os elementos restantes. Se nenhum construtor padrão for definido para a classe, a lista de inicializadores deverá estar completa – ou seja, deve haver um inicializador para cada elemento na matriz.

Considere a classe `Point` que define dois construtores:

```cpp
// initializing_arrays1.cpp
class Point
{
public:
   Point()   // Default constructor.
   {
   }
   Point( int, int )   // Construct from two ints
   {
   }
};

// An array of Point objects can be declared as follows:
Point aPoint[3] = {
   Point( 3, 3 )     // Use int, int constructor.
};

int main()
{
}
```

O primeiro elemento de `aPoint` é construído usando o construtor `Point( int, int )`; os dois elementos restantes são construídos com o construtor padrão.

Matrizes de membros estáticos (se **const** ou não) podem ser inicializadas em suas definições (fora da declaração de classe). Por exemplo:

```cpp
// initializing_arrays2.cpp
class WindowColors
{
public:
    static const char *rgszWindowPartList[7];
};

const char *WindowColors::rgszWindowPartList[7] = {
    "Active Title Bar", "Inactive Title Bar", "Title Bar Text",
    "Menu Bar", "Menu Bar Text", "Window Background", "Frame"   };
int main()
{
}
```