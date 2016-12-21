---
title: "Aviso do compilador (n&#237;vel 4) C4366 | Microsoft Docs"
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
  - "C4366"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4366"
ms.assetid: 65d2942f-3741-42f4-adf2-4920d5a055ca
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 4) C4366
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O resultado do operador unário “operador” pode ser não alinhados  
  
 Se um membro da estrutura nunca pode ser não alinhado por causa de maiúsculas e minúsculas, o compilador advertirá quando o endereço desse membro é atribuído a um ponteiro alinhados.  Por padrão, todos os ponteiros são alinhados.  
  
 Para resolver C4366, altera o alinhamento da estrutura ou declara o ponteiro com a palavra\-chave de [\_\_unaligned](../../cpp/unaligned.md) .  
  
 Para obter mais informações, consulte \_\_unaligned e [pack](../../preprocessor/pack.md).  
  
## Exemplo  
 O exemplo a seguir produz C4366.  
  
```  
// C4366.cpp  
// compile with: /W4 /c  
// processor: IPF x64  
#pragma pack(1)  
struct X {  
   short s1;  
   int s2;  
};  
  
int main() {  
   X x;  
   short * ps1 = &x.s1;   // OK  
   int * ps2 = &x.s2;   // C4366  
}  
```