---
title: "Aviso do compilador (n&#237;vel 1) C4377 | Microsoft Docs"
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
  - "C4377"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4377"
ms.assetid: a1c797b8-cd5e-4a56-b430-d07932e811cf
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4377
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

os tipos nativos são privativos por padrão; \- d1PrivateNativeTypes é substituído  
  
 Em versões anteriores, nativos nos assemblies eram público por padrão, e um padrão interna, não documentado do compilador \(**\/d1PrivateNativeTypes**\) foi usada torná\-las privados.  
  
 Todos os tipos, nativo e CLR, agora é particular por padrão em um assembly, portanto **\/d1PrivateNativeTypes** não é mais necessário.  
  
## Exemplo  
 O exemplo a seguir produz C4377.  
  
```  
// C4377.cpp  
// compile with: /clr /d1PrivateNativeTypes /W1  
// C4377 warning expected  
int main() {}  
```