---
title: C2978 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2978
dev_langs:
- C++
helpviewer_keywords:
- C2978
ms.assetid: 5e7bee82-e266-4ccd-ad2e-ee89606ec5bf
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: cabf938343b375fdd27647711bb3e5b1d1f16d39
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33244993"
---
# <a name="compiler-error-c2978"></a>C2978 de erro do compilador
Erro de sintaxe: era esperado 'keyword1' ou 'keyword2'; encontrado o tipo 'keyword3'; Não há suporte para parâmetros de tipo não em genéricos  
  
 Uma classe genérica foi declarada incorretamente. Consulte [genéricos](../../windows/generics-cpp-component-extensions.md)para obter mais informações.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2978.  
  
```  
// C2978.cpp  
// compile with: /clr /c  
generic <ref class T>   // C2978  
// try the following line instead  
// generic <typename T>   // OK  
ref class Utils {  
   static void sort(T elems, size_t size);  
};  
  
generic <int>  
// try the following line instead  
// generic <class T>  
ref class Utils2 {  
   static void sort(T elems, size_t size);  
};  
```