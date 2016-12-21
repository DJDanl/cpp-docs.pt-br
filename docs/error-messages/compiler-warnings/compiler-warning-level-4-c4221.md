---
title: "Aviso do compilador (n&#237;vel 4) C4221 | Microsoft Docs"
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
  - "C4221"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4221"
ms.assetid: 8532bd68-54dc-4526-8597-f61dcb0a0129
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 4) C4221
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

extensão não padrão usada: “identificador”: não pode ser iniciado usando o endereço da variável automático  
  
 Com as extensões padrão da Microsoft \(\/Ze\), você pode inicializar um tipo agregado \(**array**, `struct`, ou **union**\) com o endereço de uma variável local \(automático\).  
  
## Exemplo  
  
```  
// C4221.c  
// compile with: /W4  
struct S  
{  
   int *i;  
};  
  
void func()  
{  
   int j;  
   struct S s1 = { &j };   // C4221  
}  
  
int main()  
{  
}  
```  
  
 Tais inicializações não são válidos na compatibilidade ANSI \([\/Za](../../build/reference/za-ze-disable-language-extensions.md)\).