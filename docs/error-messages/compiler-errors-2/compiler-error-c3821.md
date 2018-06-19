---
title: C3821 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3821
dev_langs:
- C++
helpviewer_keywords:
- C3821
ms.assetid: 2b327c7a-5faf-443c-ae82-944fae25b4df
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e0d9c880cb2bc5f4b4a25d37afe80ca2a316a4f8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33268075"
---
# <a name="compiler-error-c3821"></a>C3821 de erro do compilador
'function': tipo ou função gerenciados não pode ser usada em uma função não gerenciada  
  
 Funções com assembly embutido ou [setjmp](../../c-runtime-library/reference/setjmp.md) não pode conter tipos de valor ou classes gerenciadas. Para corrigir esse erro, remova o assembly embutido e `setjmp` ou remover os objetos gerenciados.  
  
 C3821 também poderá ocorrer se você tentar usar o armazenamento automático em uma função de vararg.  Para obter mais informações, consulte [listas de argumentos variáveis (...) (C + + CLI) ](../../windows/variable-argument-lists-dot-dot-dot-cpp-cli.md) e [semântica de pilha do C++ para tipos de referência](../../dotnet/cpp-stack-semantics-for-reference-types.md).  
  
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
