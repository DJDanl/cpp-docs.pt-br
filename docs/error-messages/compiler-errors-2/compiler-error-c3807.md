---
title: C3807 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3807
dev_langs:
- C++
helpviewer_keywords:
- C3807
ms.assetid: 7e2b0aab-8c61-4e71-b9c1-fcaeb6a1b5ea
caps.latest.revision: 7
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
ms.openlocfilehash: 73d27c611fe268d6b7073cdbb73b7606e28e5765
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3807"></a>C3807 de erro do compilador
'type': uma classe com o atributo ComImport não pode derivar de 'type2', é permitida apenas a implementação de interface  
  
 Um tipo derivado de <xref:System.Runtime.InteropServices.ComImportAttribute>só pode implementar uma interface.</xref:System.Runtime.InteropServices.ComImportAttribute>  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3807.  
  
```  
// C3807.cpp  
// compile with: /clr /c  
ref struct S {};  
interface struct I {};  
  
[System::Runtime::InteropServices::ComImportAttribute()]  
ref struct S1 : S {};   // C3807  
ref struct S2 : I {};  
```
