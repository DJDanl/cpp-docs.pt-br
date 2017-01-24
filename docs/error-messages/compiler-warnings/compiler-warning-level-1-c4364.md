---
title: "Aviso do compilador (n&#237;vel 1) C4364 | Microsoft Docs"
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
  - "C4364"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4364"
ms.assetid: 1477634c-d60f-4570-ad16-1aaeae24ac7f
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4364
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

\#using para o assembly “arquivo” consultado anteriormente no local \(line\_number\) sem atributo de as\_friend; as\_friend não aplicado  
  
 Uma política de `#using` foi repetida para um dado arquivo de metadados, mas o qualificador de `as_friend` não foi usada na primeira ocorrência; o compilador ignorará segundo `as_friend`.  
  
 Para obter mais informações, consulte [Assemblies amigáveis \(C\+\+\)](../../dotnet/friend-assemblies-cpp.md).  
  
## Exemplo  
 O exemplo a seguir cria um componente.  
  
```  
// C4364.cpp  
// compile with: /clr /LD  
ref class A {};  
```  
  
## Exemplo  
 O exemplo a seguir produz C4364.  
  
```  
// C4364_b.cpp  
// compile with: /clr /W1 /c  
#using " C4364.dll"  
#using " C4364.dll" as_friend   // C4364  
```