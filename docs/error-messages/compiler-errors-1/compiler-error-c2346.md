---
title: "Erro do Compilador C2346 | Microsoft Docs"
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
  - "C2346"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2346"
ms.assetid: 246145be-5645-4cd6-867c-e3bc39e33dca
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2346
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

a função “” não pode ser criada como o nativo: motivo  
  
 O compilador não pôde criar uma função a MSIL.  
  
 Para obter mais informações, consulte [gerenciado, não gerenciado](../../preprocessor/managed-unmanaged.md) e [\/clr \(compilação do Common Language Runtime\)](../../build/reference/clr-common-language-runtime-compilation.md).  
  
### Para corrigir este erro  
  
1.  Remover o código da função que não pode ser criada a MSIL.  
  
2.  Não crie ou o módulo com **\/clr**, ou marcar a função como não gerenciado com o pragma não gerenciado.  
  
## Exemplo  
 O exemplo a seguir produz C2346.  
  
```  
// C2346.cpp  
// processor: x86  
// compile with: /clr   
// C2346 expected  
struct S  
{  
   S()  
   {  
      { __asm { nop } }  
   }  
   virtual __clrcall ~S() { }  
};  
  
void main()  
{  
   S s;  
}  
```