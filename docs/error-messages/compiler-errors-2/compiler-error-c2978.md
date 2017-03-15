---
title: C2978 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2978
dev_langs:
- C++
helpviewer_keywords:
- C2978
ms.assetid: 5e7bee82-e266-4ccd-ad2e-ee89606ec5bf
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: e6b0a081587c0195674fa418da6dbc00c443c5bf
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2978"></a>C2978 de erro do compilador
Erro de sintaxe: esperava-se 'keyword1' ou 'keyword2'; encontrado o tipo 'keyword3'; Não há suporte para parâmetros de tipo não genéricos  
  
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
