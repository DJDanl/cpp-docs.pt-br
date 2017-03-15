---
title: C3821 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3821
dev_langs:
- C++
helpviewer_keywords:
- C3821
ms.assetid: 2b327c7a-5faf-443c-ae82-944fae25b4df
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: c243063a9770542f137d5950e8a269f771960f74
ms.openlocfilehash: 24212b0df7b665f8c8ab2614b9a23e66f19586af
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3821"></a>C3821 de erro do compilador
'function': tipo gerenciado ou função não pode ser usada em uma função não gerenciada  
  
 Funções com assembly embutido ou [setjmp](../../c-runtime-library/reference/setjmp.md) não pode conter tipos de valor ou classes gerenciadas. Para corrigir esse erro, remova o assembly embutido e `setjmp` ou remover os objetos gerenciados.  
  
 C3821 também pode ocorrer se você tentar usar o armazenamento automático em uma função vararg.  Para obter mais informações, consulte [listas de argumentos variáveis (...) (C + + / CLI) ](../../windows/variable-argument-lists-dot-dot-dot-cpp-cli.md) e [semântica da pilha do C++ para tipos de referência](../../dotnet/cpp-stack-semantics-for-reference-types.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3821.  
  
```  
// C3821a.cpp  
// compile with: /clr /c  
public ref struct R {};  
void test1(...) {  
   R r;   // C3821  
}  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3821.  
  
```  
// C3821b.cpp  
// compile with: /clr  
// processor: /x86  
ref class A {  
   public:  
   int i;  
};  
  
int main() {  
   // cannot use managed classes in this function  
   A ^a;     
  
   __asm {  
      nop  
   }  
} // C3821  
```  

