---
title: "Aviso C4742 (compilador) (n&#237;vel 1) | Microsoft Docs"
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
  - "C4742"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4742"
ms.assetid: e520881d-1eeb-48b1-9df0-8017ee8ba076
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso C4742 (compilador) (n&#237;vel 1)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“var” tem o alinhamento diferente em “file1” e “file2”: número e número  
  
 Uma variável externa que é referenciado ou definida em dois arquivos tem o alinhamento diferente nesses arquivos.  Esse aviso é emitido quando encontra do compilador que `__alignof` para a variável em *file1* difere de `__alignof` para a variável em *file2*.  Isso pode ser causado usando tipos incompatíveis ao declarar a variável em arquivos diferentes, ou usando a `#pragma pack` não correspondentes em arquivos diferentes.  
  
 Para resolver esse aviso, use a mesma definição de tipo ou usar nomes diferentes para as variáveis.  
  
 Para obter mais informações, consulte [pack](../../preprocessor/pack.md) e [Operador \_\_alignof](../../cpp/alignof-operator.md).  
  
## Exemplo  
 Este é o primeiro arquivo que define o tipo.  
  
```  
// C4742a.c  
// compile with: /c  
struct X {  
   char x, y, z, w;  
} global;  
```  
  
## Exemplo  
 O exemplo a seguir produz C4742.  
  
```  
// C4742b.c  
// compile with: C4742a.c /W1 /GL  
// C4742 expected  
extern struct X {  
   int a;  
} global;  
  
int main() {  
   global.a = 0;  
}  
```