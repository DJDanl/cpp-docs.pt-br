---
title: "Compilador aviso (nível 3) C4398 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4398
dev_langs:
- C++
helpviewer_keywords:
- C4398
ms.assetid: b6221432-9fed-4272-a547-a73f587904e6
caps.latest.revision: 6
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: cc82b83860786ffc3f0aee73ede18ecadef16a7a
ms.openlocfilehash: 18270bb89bcc5d1855750c572a5b6fb9e51c2ba3
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-3-c4398"></a>Compilador C4398 de aviso (nível 3)
'variável': objeto global por processo talvez não funcionem corretamente com vários appdomains; Considere o uso de declspec  
  
 Uma função virtual com [clrcall](../../cpp/clrcall.md) convenção de chamada em um tipo nativo faz com que a criação de um por vtable de domínio de aplicativo. Essa variável não pode corrigir corretamente quando usados em vários domínios de aplicativo.  
  
 Você pode resolver este aviso marcando explicitamente a variável `__declspec(appdomain)`. Em versões do Visual Studio antes de 2017 do Visual Studio, você pode resolver este aviso compilando com **/clr: puro**, que torna as variáveis globais por appdomain por padrão.  
  
 Para obter mais informações, consulte [appdomain](../../cpp/appdomain.md) e [domínios de aplicativo e do Visual C++](../../dotnet/application-domains-and-visual-cpp.md).  
  
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
