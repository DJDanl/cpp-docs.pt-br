---
title: Inicializando matrizes | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- initializing arrays [C++]
- arrays [C++], initializing
ms.assetid: 41efe5f0-15b5-4f49-9196-c4902f8fc705
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 5370633ac0d73815c048153f7025ea50b990a3f4
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

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
  

