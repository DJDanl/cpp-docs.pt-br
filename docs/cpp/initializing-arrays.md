---
title: "Inicializando matrizes | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "inicializando matrizes"
  - "matrizes [C++] Inicializando"
ms.assetid: 41efe5f0-15b5-4f49-9196-c4902f8fc705
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Inicializando matrizes
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

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
  
 Matrizes de membro estático (se **const** ou não) podem ser inicializadas em suas definições (fora da declaração de classe). Por exemplo:  
  
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
  
## <a name="see-also"></a>Consulte também  
 [(NOTINBUILD) Funções de membro especiais](http://msdn.microsoft.com/pt-br/82223d73-64cb-4923-b678-78f9568ff3ca)