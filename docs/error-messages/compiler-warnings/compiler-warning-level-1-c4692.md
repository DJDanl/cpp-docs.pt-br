---
title: Compilador (nível 1) de aviso C4692 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4692
dev_langs:
- C++
helpviewer_keywords:
- C4692
ms.assetid: f6fb3acc-8228-491a-9c30-ce302d8a9c75
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a908aae7e561f78514cda1f31b78060ce88d90ee
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4692"></a>Compilador C4692 de aviso (nível 1)
'function': assinatura de membro não privado contém tipo nativo privado de assembly 'native_type'  
  
 Um tipo que é visível fora do assembly contém uma função de membro cuja assinatura contém um tipo nativo que não é visível fora do assembly. Portanto, a função de membro não deve ser chamada se seu tipo recipiente for instanciado fora do assembly.  
  
 Para obter mais informações, consulte [visibilidade de tipo](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Type_visibility).  
  
 Esse aviso é desativada por padrão. Para obter mais informações, consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4692.  
  
```  
// C4692.cpp  
// compile with: /W1 /c /clr  
#pragma warning(default:4692)  
class Private_Native_Class {};  
public class Public_Native_Class {};  
public ref class Public_Ref_Class {  
public:  
   void Test(Private_Native_Class *) {}   // C4692  
   void Test2(Public_Native_Class *) {}   // OK  
};  
```