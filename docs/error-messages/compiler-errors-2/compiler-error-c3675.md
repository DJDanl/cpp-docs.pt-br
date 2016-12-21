---
title: "Erro do Compilador C3675 | Microsoft Docs"
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
  - "C3675"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3675"
ms.assetid: 87461613-6633-430b-b95d-c7cb1bb63776
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3675
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: é permitido porque a propriedade é definida” “  
  
 Quando declara uma propriedade simples, o compilador gerencia os métodos de acessador obter e de conjunto, e esses nomes devem estar presentes no escopo do programa.  Os nomes gerados completo são formados acrescentando o get\_ e o set\_ ao nome da propriedade.  Consequentemente, você não pode declarar funções com o mesmo nome que os acessadores completo gerados.  
  
 Consulte [property](../../windows/property-cpp-component-extensions.md) para maiores informações.  
  
## Exemplo  
 O exemplo a seguir produz C3675.  
  
```  
// C3675.cpp  
// compile with: /clr /c  
ref struct C {  
public:  
   property int Size;  
   int get_Size() { return 0; }   // C3675  
};  
```