---
title: C3510 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3510
dev_langs:
- C++
helpviewer_keywords:
- C3510
ms.assetid: c48387bc-0300-4a4d-97f7-3fb90f82a451
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: abb58d8d4fb9008b07579ef7fbc0066d00bcea57
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3510"></a>C3510 de erro do compilador
não é possível localizar a biblioteca de tipos dependente 'type_lib'  
  
 [no_registry](../../preprocessor/no-registry.md) e [auto_search](../../preprocessor/auto-search.md) foram passados para `#import` , mas o compilador não foi possível localizar uma biblioteca de tipos referenciada.  
  
 Para resolver esse erro, certifique-se de que todas as bibliotecas de tipo e bibliotecas de tipo referenciado estão disponíveis para o compilador.  
  
 O exemplo a seguir gera C3510:  
  
 Vamos supor que as bibliotecas de dois tipos a seguir foram criadas e que C3510a.tlb foi excluído ou não no caminho.  
  
```  
// C3510a.idl  
[uuid("f87070ba-c6d9-405c-a8e4-8cd9ca25c12b")]  
library C3510aLib  
{  
   [uuid("f87070ba-c6d9-405c-a8e4-8cd9ca25c12c")]  
   enum E_C3510  
   {  
      one, two, three  
   };  
};  
```  
  
 E, em seguida, o código-fonte para a biblioteca de tipos segundo:  
  
```  
// C3510b.idl  
// post-build command: del /f C3510a.tlb  
[uuid("f87070ba-c6d9-405c-a8e4-8cd9ca25c12e")]  
library C3510bLib  
{  
   importlib ("C3510a.tlb");  
   [uuid("f87070ba-c6d9-405c-a8e4-8cd9ca25c12d")]  
   struct S_C3510 {  
      enum E_C3510 e;  
   };  
};  
```  
  
 E, em seguida, o código do cliente:  
  
```  
// C3510.cpp  
#import "c3510b.tlb" no_registry auto_search   // C3510  
int main() {  
   C3510aLib::S_C4336 ccc;  
}  
```