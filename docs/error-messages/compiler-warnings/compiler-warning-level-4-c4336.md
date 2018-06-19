---
title: Compilador (nível 4) de aviso C4336 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4336
dev_langs:
- C++
helpviewer_keywords:
- C4336
ms.assetid: 93f199dd-d6dd-42c0-82d8-c12d101a7235
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4da5302df9b2072089ce84c349577e1ea8ea236f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33295240"
---
# <a name="compiler-warning-level-4-c4336"></a>Compilador C4336 de aviso (nível 4)
Importar biblioteca 'type_lib1' de tipo de referência cruzado antes de importar 'type_lib2'  
  
 Uma biblioteca de tipo referenciada com o [#import](../../preprocessor/hash-import-directive-cpp.md) diretiva. No entanto, a biblioteca de tipos continha uma referência a outra biblioteca de tipos que não foi referenciada com `#import`. Esse outro arquivo. tlb foi encontrado pelo compilador.  
  
 Bibliotecas de tipo dois determinado em disco criado a partir de dois arquivos a seguir (compilados com midl.exe):  
  
```  
// c4336a.idl  
[uuid("f87070ba-c6d9-405c-a8e4-8cd9ca25c12b")]  
library c4336aLib  
{  
   [uuid("f87070ba-c6d9-405c-a8e4-8cd9ca25c12c")]  
   enum E_C4336  
   {  
      one, two, three  
   };  
};  
```  
  
 A segunda biblioteca de tipos:  
  
```  
// c4336b.idl  
[uuid("f87070ba-c6d9-405c-a8e4-8cd9ca25c12d")]  
library C4336bLib  
{  
   importlib ("c4336a.tlb");  
   [uuid("f87070ba-c6d9-405c-a8e4-8cd9ca25c12e")]  
   struct S_C4336  
   {  
      enum E_C4336 e;  
   };  
};  
```  
  
 O exemplo a seguir gera C4336:  
  
```  
// C4336.cpp  
// compile with: /W4 /LD  
// #import "C4336a.tlb"  
#import "C4336b.tlb"   // C4336, uncomment previous line to resolve  
```