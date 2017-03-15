---
title: C3399 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3399
dev_langs:
- C++
helpviewer_keywords:
- C3399
ms.assetid: 306ad199-d150-4f6c-bcf1-24a7948b93be
caps.latest.revision: 3
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
ms.openlocfilehash: 7886cad8949287ea5a6cf635c8e2ce259709c90a
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3399"></a>C3399 de erro do compilador
'type': não é possível fornecer argumentos ao criar uma instância de um parâmetro genérico  
  
 Quando você especifica o `gcnew()` restrição, você especificar que o tipo de restrição terá um construtor sem parâmetros. Portanto, é um erro ao tentar criar uma instância desse tipo e passar um parâmetro.  
  
 Consulte [restrições em parâmetros de tipo genéricos (C + + / CLI)](../../windows/constraints-on-generic-type-parameters-cpp-cli.md) para obter mais informações.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3399.  
  
```  
// C3399.cpp  
// compile with: /clr /c  
generic <class T>   
where T : gcnew()  
void f() {  
   T t = gcnew T(1);   // C3399  
   T t2 = gcnew T();   // OK  
}  
```
