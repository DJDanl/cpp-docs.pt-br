---
title: C2584 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2584
dev_langs:
- C++
helpviewer_keywords:
- C2584
ms.assetid: 836e2c0a-86c0-4742-b432-beb0191ad20e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ae9ea7a4b0ce44231925f4231c5876f352765ad6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33231067"
---
# <a name="compiler-error-c2584"></a>C2584 de erro do compilador
'Class': direta base 'Base2' é inacessível; já é uma base de 'Base1'  
  
 `Class` já deriva diretamente da `Base1`. `Base2` também deriva de `Base1`. `Class` não é possível derivar de `Base2` porque isso significaria herdando (indiretamente) `Base1` novamente, que não é válido porque `Base1` já é uma classe base direta.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2584.  
  
```  
// C2584.cpp  
// compile with: /c  
struct A1 {  
   virtual int MyFunction();  
};  
  
struct A2 {  
    virtual int MyFunction();  
};  
  
struct B1: public virtual A1, virtual A2 {  
    virtual int MyFunction();  
};  
  
struct B2: public virtual A2, virtual A1 {  
    virtual int MyFunction();  
};  
  
struct C: virtual B1, B2 {  
    virtual int MyFunction();  
};  
  
struct Z : virtual B2, virtual C {   // C2584  
// try the following line insted  
// struct Z : virtual C {  
    virtual int MyFunction();  
};  
```