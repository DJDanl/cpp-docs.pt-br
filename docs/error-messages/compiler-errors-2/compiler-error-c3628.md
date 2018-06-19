---
title: C3628 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3628
dev_langs:
- C++
helpviewer_keywords:
- C3628
ms.assetid: 0ff5a4a4-fcc9-47a0-a4d8-8af9cf2815f6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5210a9bb91b86c63f0cebabce8901c9af50ae896
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33266409"
---
# <a name="compiler-error-c3628"></a>C3628 de erro do compilador
classe de base: gerenciados ou WinRTclasses suportam apenas herança public  
  
Foi feita uma tentativa para usar um gerenciado ou WinRT da classe como um [privada](../../cpp/private-cpp.md) ou [protegido](../../cpp/protected-cpp.md) classe base. Um gerenciado ou classe WinRT somente pode ser usado como uma classe base com [pública](../../cpp/public-cpp.md) acesso.  
  
O exemplo a seguir gera C3628 e mostra como corrigi-lo:  
  
```  
// C3628a.cpp  
// compile with: /clr  
ref class B {  
};  
  
ref class D : private B {   // C3628  
  
// The following line resolves the error.  
// ref class D : public B {  
};  
  
int main() {  
}  
```  
