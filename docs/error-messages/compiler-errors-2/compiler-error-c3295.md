---
title: C3295 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3295
dev_langs:
- C++
helpviewer_keywords:
- C3295
ms.assetid: 83f0aa4d-0e0a-4905-9f66-fcf9991fc07a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 25fd1a04e0be46943b4fd183b470b369f810a0d1
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33253951"
---
# <a name="compiler-error-c3295"></a>C3295 de erro do compilador
'#pragma pragma' só pode ser usada em global ou escopo de namespace  
  
 Alguns pragmas não pode ser usados em uma função.  Consulte [diretivas Pragma e a palavra-chave de pragma](../../preprocessor/pragma-directives-and-the-pragma-keyword.md) para obter mais informações.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3295.  
  
```  
// C3295.cpp  
int main() {  
   #pragma managed   // C3295  
}  
```