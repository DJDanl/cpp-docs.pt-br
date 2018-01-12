---
title: Inicializando matrizes | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords:
- initializing arrays [C++]
- arrays [C++], initializing
ms.assetid: 41efe5f0-15b5-4f49-9196-c4902f8fc705
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 42d47f8ba7f7df8285d3c4f685a212c77974b144
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="initializing-arrays"></a>Inicializando matrizes
Se a classe tiver um construtor, as matrizes dessa classe serão iniciadas por um construtor. Se houver menos itens na lista de inicializadores do que elementos na matriz, o construtor padrão será usado para os elementos restantes. Se nenhum construtor padrão for definido para a classe, a lista de inicializadores deverá estar completa – ou seja, deve haver um inicializador para cada elemento na matriz.  
  
 Considere a classe `Point` que define dois construtores:  
  
```  
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
  
 Matrizes de membro estático (se **const** ou não) pode ser inicializado em suas definições (fora da declaração de classe). Por exemplo:  
  
```  
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
  
