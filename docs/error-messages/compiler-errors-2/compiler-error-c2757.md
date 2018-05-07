---
title: C2757 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2757
dev_langs:
- C++
helpviewer_keywords:
- C2757
ms.assetid: 421f102f-8a32-4d47-a109-811ddf2c909d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 14a65233ae0ad0a925d0b0d18cbc1b196fa5949a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2757"></a>C2757 de erro do compilador
'symbol': um símbolo com este nome já existe e, portanto, esse nome não pode ser usado como um nome de namespace  
  
 Um símbolo usado na compilação atual como um identificador de namespace já está sendo usado em um assembly referenciado.  
  
 O exemplo a seguir gera C2757:  
  
```  
// C2757a.cpp  
// compile with: /clr /LD  
public ref class Nes {};  
```  
  
 E, em seguida,  
  
```  
// C2757b.cpp  
// compile with: /clr /c  
#using <C2757a.dll>  
  
namespace Nes {    // C2757  
// try the following line instead  
// namespace Nes2 {  
   public ref class X {};  
}  
```  
