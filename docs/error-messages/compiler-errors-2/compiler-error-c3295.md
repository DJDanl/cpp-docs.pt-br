---
title: C3295 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3295
dev_langs:
- C++
helpviewer_keywords:
- C3295
ms.assetid: 83f0aa4d-0e0a-4905-9f66-fcf9991fc07a
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 401eafa2cd0129931ca98b0289a60325ec69643a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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