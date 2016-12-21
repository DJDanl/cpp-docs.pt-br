---
title: "Erro das Ferramentas de Vinculador LNK2028 | Microsoft Docs"
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
  - "LNK2028"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK2028"
ms.assetid: e2b03293-6066-464d-a050-ce747bcf7f0e
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK2028
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o “exported\_function” \(\) decorated\_name mencionado na função “function\_containing\_function\_call” \(o decorated\_name\)  
  
 Ao tentar importar uma função nativo em uma imagem pura, lembre\-se de que as convenções implícitas de chamada diferem entre compilações nativas e puras.  
  
## Exemplo  
 Este exemplo de código gerenciado um componente COM exportado, nativo, a função cuja convenção de chamada é implicitamente [\_\_cdecl](../Topic/__cdecl.md).  
  
```  
// LNK2028.cpp  
// compile with: /LD  
__declspec(dllexport) int func() {  
   return 3;  
}  
```  
  
## Exemplo  
 O exemplo a seguir cria um puro cliente que consome a função nativo.  No entanto, a convenção de chamada em **\/clr:pure** é [\_\_clrcall](../../cpp/clrcall.md).  O exemplo a seguir produz LNK2028.  
  
```  
// LNK2028_b.cpp  
// compile with: /clr:pure lnk2028.lib  
// LNK2028 expected  
int func();  
  
int main() {  
   return func();  
}  
```