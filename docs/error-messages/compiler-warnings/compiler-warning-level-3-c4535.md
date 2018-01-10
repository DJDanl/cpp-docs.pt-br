---
title: "Compilador aviso (nível 3) C4535 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4535
dev_langs: C++
helpviewer_keywords: C4535
ms.assetid: 2c5ad1aa-2558-41d1-8f06-47fef74c8d9b
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a6079066a29d7d22430e8707d6548d8a4d53d231
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-3-c4535"></a>Compilador C4535 de aviso (nível 3)
chamada _set_se_translator() requer /EHa  
  
 O uso de [set_se_translator](../../c-runtime-library/reference/set-se-translator.md) requer o [/EHa](../../build/reference/eh-exception-handling-model.md) opção de compilador e não **/EHs**.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4535.  
  
```  
// C4535.cpp  
// compile with: /W3 /EHsc /c  
// C4535 expected  
// to fix, compile with /EHa instead  
#include <stdio.h>  
#include <windows.h>  
#include <eh.h>  
  
void SEFunc();  
void trans_func( unsigned int, EXCEPTION_POINTERS* );  
  
class SE_Exception {  
private:  
   unsigned int nSE;  
public:  
   SE_Exception() {}  
   SE_Exception( unsigned int n ) : nSE( n ) {}  
   ~SE_Exception() {}  
   unsigned int getSeNumber() { return nSE; }  
};  
  
int main() {  
   try {  
      _set_se_translator( trans_func );  
      SEFunc();  
   }  
   catch( SE_Exception e ) {  
      printf_s( "Caught a __try exception with SE_Exception.\n" );  
   }  
}  
  
void SEFunc() {  
   __try {  
      int x, y=0;  
      x = 5 / y;  
   }  
   __finally {  
      printf_s( "In finally\n" );  
   }  
}  
  
void trans_func( unsigned int u, EXCEPTION_POINTERS* pExp ) {  
   printf_s( "In trans_func.\n" );  
   throw SE_Exception();  
}  
```