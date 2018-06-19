---
title: C3393 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3393
dev_langs:
- C++
helpviewer_keywords:
- C3393
ms.assetid: d57f7c69-0a02-4fe3-9e45-bc62644fd77c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: db8e60df6c6f8f1d19b55d78b527cca2755f4ca4
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33254128"
---
# <a name="compiler-error-c3393"></a>C3393 de erro do compilador
Erro de sintaxe em cláusula de restrição: 'Identificador' não é um tipo  
  
 O identificador passado para uma restrição, que deve ser um tipo, não era um tipo.  Para obter mais informações, consulte [restrições em parâmetros de tipo genérico (C + + CLI)](../../windows/constraints-on-generic-type-parameters-cpp-cli.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3393:  
  
```  
// C3393.cpp  
// compile with: /clr /c  
void MyInterface() {}  
interface class MyInterface2 {};  
  
generic<typename T>  
where T : MyInterface   // C3393  
// try the following line instead  
// where T : MyInterface2  
ref class R {};  
```