---
title: "Aviso do compilador (n&#237;vel 1) C4691 | Microsoft Docs"
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
  - "C4691"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4691"
ms.assetid: 722133d9-87f6-46c1-9e86-9825453d6999
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4691
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“tipo”: o tipo referenciado foi esperado no assembly não referenciada “arquivo”, tipo definido na unidade atual de conversão usado  
  
 O arquivo de metadados que contém a definição do tipo original não é referenciado, e o compilador estiver usando uma definição do tipo local.  
  
 Em casos onde você estiver recompilando *file*, C4691 pode ser ignorado ou desativado com pragma [warning](../../preprocessor/warning.md).  Ou seja, se o arquivo que você está criando é o mesmo que o arquivo onde o compilador espera localizar a definição de tipo, você pode ignorar C4691.  
  
 Porém, o pode ocorrer um comportamento inesperado se o compilador usa uma definição que não seja do mesmo assembly referenciado nos metadados; Os tipos CLR são de tipo não apenas pelo nome do tipo, mas também o assembly.  Isto é, um tipo Z do assembly z.dll é diferente de um tipo Z do assembly y.dll.  
  
## Exemplo  
 Este exemplo contém a definição de tipo original.  
  
```  
// C4691_a.cpp  
// compile with: /clr /LD /W1  
public ref class Original_Type {};  
```  
  
## Exemplo  
 Este exemplo faz referência C4691\_a.dll e declara um campo de tipo Original\_Type.  
  
```  
// C4691_b.cpp  
// compile with: /clr /LD  
#using "C4691_a.dll"  
public ref class Client {  
public:  
   Original_Type^ ot;  
};  
```  
  
## Exemplo  
 O exemplo a seguir produz C4691.  Observe que este exemplo contém uma definição para Original\_Type e não fizer referência C4691a.dll.  
  
 Para resolver, fazer referência aos metadados arquivo que contém a definição do tipo original e remove a declaração e a definição local.  
  
```  
// C4691_c.cpp  
// compile with: /clr /LD /W1  
// C4691 expected  
  
// Uncomment the following line to resolve.  
// #using "C4691_a.dll"  
#using "C4691_b.dll"  
  
// Delete the following line to resolve.  
ref class Original_Type;  
  
public ref class MyClass : Client {};  
```