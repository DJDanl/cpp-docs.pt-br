---
title: "Erro do Compilador C3904 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C3904"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3904"
ms.assetid: 08297605-e4f2-4c6c-b637-011f1fd40631
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3904
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“property\_accessor”: deve especificar parâmetros de número  
  
 Verifique o número de parâmetros em seus métodos de `get` e de `set` em dimensões da propriedade.  
  
-   O número de parâmetros para o método de `get` deve ser igual ao número de dimensões da propriedade ou ser zero para propriedades não indexada.  
  
-   O número de parâmetros do método de `set` deve ser um número maior que o número de dimensões da propriedade.  
  
 Para obter mais informações, consulte [propriedade](../../windows/property-cpp-component-extensions.md).  
  
## Exemplo  
 O exemplo a seguir produz C3904.  
  
```  
// C3904.cpp  
// compile with: /clr /c  
ref class X {  
   property int P {  
      // set  
      void set();   // C3904  
      // try the following line instead  
      // void set(int);  
  
      // get  
      int get(int, int);   // C3904  
      // try the following line instead  
      // int get();  
   };  
};  
```  
  
## Exemplo  
 O exemplo a seguir produz C3904.  
  
```  
// C3904b.cpp  
// compile with: /clr /c  
ref struct X {  
   property int Q[double, double, float, float, void*, int] {  
      // set  
      void set(double, void*);   // C3904  
      // try the following line instead  
      // void set(double, double, float, float, void*, int, int);  
  
      // get  
      int get();   // C3904  
      // try the following line instead  
      // int get(double, double, float, float, void*, int);  
   }  
};  
```