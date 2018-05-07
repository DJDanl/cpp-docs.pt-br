---
title: Compilador aviso (nível 3) C4398 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4398
dev_langs:
- C++
helpviewer_keywords:
- C4398
ms.assetid: b6221432-9fed-4272-a547-a73f587904e6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8ace2df75b5d2579b66a4d3930470021726ba4c9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-3-c4398"></a>Compilador C4398 de aviso (nível 3)
'variável': objeto global por processo poderão não funcionar corretamente com múltiplos appdomains; Considere o uso de __declspec(appdomain)  
  
 Uma função virtual com [clrcall](../../cpp/clrcall.md) convenção de chamada em um tipo nativo faz com que a criação de uma por vtable de domínio de aplicativo. Essa variável não pode corrigir corretamente quando usados em vários domínios de aplicativo.  
  
 Você pode resolver este aviso marcando explicitamente a variável `__declspec(appdomain)`. Nas versões do Visual Studio antes de 2017 do Visual Studio, você pode resolver este aviso ao compilar com **/clr: pure**, que torna as variáveis globais por appdomain por padrão.  
  
 Para obter mais informações, consulte [appdomain](../../cpp/appdomain.md) e [domínios do aplicativo e do Visual C++](../../dotnet/application-domains-and-visual-cpp.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4398.  
  
```  
// C4398.cpp  
// compile with: /clr /W3 /c  
struct S {  
   virtual void f( System::String ^ );   // String^ parameter makes function __clrcall  
};  
  
S glob_s;   // C4398  
__declspec(appdomain) S glob_s2;   // OK  
```