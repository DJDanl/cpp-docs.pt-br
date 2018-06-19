---
title: C2346 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2346
dev_langs:
- C++
helpviewer_keywords:
- C2346
ms.assetid: 246145be-5645-4cd6-867c-e3bc39e33dca
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9459d7330738180e92776e93fcba9a07bfd39640
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33222287"
---
# <a name="compiler-error-c2346"></a>C2346 de erro do compilador
'function' não pode ser compilado como nativo: motivo  
  
 O compilador não pôde compilar uma função para MSIL.  
  
 Para obter mais informações, consulte [gerenciado, não gerenciado](../../preprocessor/managed-unmanaged.md) e [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md).  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Remova o código na função que não pode ser compilada para MSIL.  
  
2.  O não compilar o módulo com **/clr**, ou marcar a função como não gerenciado com o pragma não gerenciado.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2346.  
  
```  
// C2346.cpp  
// processor: x86  
// compile with: /clr   
// C2346 expected  
struct S  
{  
   S()  
   {  
      { __asm { nop } }  
   }  
   virtual __clrcall ~S() { }  
};  
  
void main()  
{  
   S s;  
}  
```