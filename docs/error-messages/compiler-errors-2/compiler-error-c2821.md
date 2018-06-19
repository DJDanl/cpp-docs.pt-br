---
title: C2821 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2821
dev_langs:
- C++
helpviewer_keywords:
- C2821
ms.assetid: e8d71988-a968-4484-94db-e8c3bad74a4a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f8c134d84ef27110cde83d54cbb8e46aa6a39efa
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33236553"
---
# <a name="compiler-error-c2821"></a>C2821 de erro do compilador
o primeiro parâmetro formal para 'operator new' deve ser 'unsigned int'  
  
O primeiro parâmetro formal do [operador novo](../../standard-library/new-operators.md#op_new) deve ser um unsigned `int`.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2821:  
  
```cpp  
// C2821.cpp  
// compile with: /c  
void * operator new( /* unsigned int,*/ void * );   // C2821  
void * operator new( unsigned int, void * );  
```