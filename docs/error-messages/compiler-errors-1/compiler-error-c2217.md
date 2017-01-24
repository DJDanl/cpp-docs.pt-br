---
title: "Erro do Compilador C2217 | Microsoft Docs"
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
  - "C2217"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2217"
ms.assetid: 1ce1e3f5-4171-4376-804d-967f7e612935
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2217
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“attribute1” requer “attribute2”  
  
 O primeiro atributo da função requer o segundo atributo.  
  
### Para corrigir verificando as seguintes causas possíveis  
  
1.  Interrompa a função \(\) de`__interrupt`declarada como `near`.  As funções de interrupção devem ser `far`.  
  
2.  Interrompa a função declarada com `__stdcall`, ou o `__fastcall`.  As funções de interrupção devem usar C que chama convenções.  
  
## Exemplo  
 C2217 também pode ocorrer se você tentar associar um delegado a uma função de CLR que usa um número variável de argumentos.  Se a função também tem sobrecarga da matriz de parâmetro de e, use o em vez disso.  O exemplo a seguir produz C2217.  
  
```  
// C2217.cpp  
// compile with: /clr  
using namespace System;  
delegate void MyDel(String^, Object^, Object^, ...);   // C2217  
delegate void MyDel2(String ^, array<Object ^> ^);   // OK  
  
int main() {  
   MyDel2^ wl = gcnew MyDel2(Console::WriteLine);  
   array<Object ^ > ^ x = gcnew array<Object ^>(2);  
   x[0] = safe_cast<Object^>(0);  
   x[1] = safe_cast<Object^>(1);  
  
   // wl("{0}, {1}", 0, 1);  
   wl("{0}, {1}", x);  
}  
```