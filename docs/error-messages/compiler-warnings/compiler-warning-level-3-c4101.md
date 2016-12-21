---
title: "Aviso do compilador (n&#237;vel 3) C4101 | Microsoft Docs"
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
  - "C4101"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4101"
ms.assetid: d98563cd-9dce-4aae-8f12-bd552a4ea677
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 3) C4101
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“identificador”: variável local não referenciada  
  
 A variável local nunca é usado.  Esse aviso ocorrerá na situação óbvia:  
  
```  
// C4101a.cpp  
// compile with: /W3  
int main() {  
int i;   // C4101  
}  
```  
  
 No entanto, esse aviso também ocorrerá ao chamar uma função de membro de **static** por uma instância da classe:  
  
```  
// C4101b.cpp  
// compile with:  /W3  
struct S {  
   static int func()  
   {  
      return 1;  
   }  
};  
  
int main() {  
   S si;   // C4101, si is never used  
   int y = si.func();  
   return y;  
}  
```  
  
 Nessa situação, o usa informações do compilador sobre `si` para acessar a função de **static** , mas a instância da classe não é necessária para chamar a função de **static** ; consequentemente o aviso.  Para resolver esse aviso, você pode:  
  
-   Adicionar um construtor, em que o compilador usaria a instância de `si` na chamada de `func`.  
  
-   Remover a palavra\-chave de **static** de definição de `func`.  
  
-   Chame a função de **static** explicitamente: `int y = S::func();`.