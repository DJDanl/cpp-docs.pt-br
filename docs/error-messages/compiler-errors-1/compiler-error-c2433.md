---
title: C2433 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2433
dev_langs:
- C++
helpviewer_keywords:
- C2433
ms.assetid: 7079fedd-6059-4125-82ef-ebe275f1f9d1
caps.latest.revision: 11
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 9e3116ae4055f2fc0a13de03fcba0d51e52d4aa0
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2433"></a>C2433 de erro do compilador
'identifier': 'modificador' não é permitido em declarações de dados  
  
 O `friend`, `virtual`, e `inline` modificadores não podem ser usados para declarações de dados.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2433.  
  
```  
// C2433.cpp  
class C{};  
  
int main() {  
   inline C c;   // C2433  
}  
```
