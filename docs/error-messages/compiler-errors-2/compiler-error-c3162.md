---
title: "Erro do Compilador C3162 | Microsoft Docs"
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
  - "C3162"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3162"
ms.assetid: 0d4c4a24-1456-4191-b7d8-c38cb7b17c32
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3162
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“tipo”: um tipo de referência que tem um destruidor não pode ser usado como tipo de membro de dados membro estático “”  
  
 Common Language Runtime não pode saber quando executar um destruidor definido pelo usuário quando a classe também contém a função de membro estático.  
  
 Um destruidor será executado nunca a menos que o objeto é excluído explicitamente.  
  
 Para obter mais informações, consulte,  
  
-   [\/clr \(compilação do Common Language Runtime\)](../../build/reference/clr-common-language-runtime-compilation.md)  
  
-   [Problemas de migração de 64 bits do Visual C\+\+comuns](../../build/common-visual-cpp-64-bit-migration-issues.md)  
  
## Exemplo  
 O exemplo a seguir produz C3162.  
  
```  
// C3162.cpp  
// compile with: /clr /c  
ref struct A {  
   ~A() { System::Console::WriteLine("in destructor"); }  
   static A i;   // C3162  
   static A^ a = gcnew A;   // OK  
};  
  
int main() {  
   A ^ a = gcnew A;  
   delete a;  
}  
```