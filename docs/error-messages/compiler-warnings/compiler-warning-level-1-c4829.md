---
title: Compilador (nível 1) de aviso C4829 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4829
dev_langs:
- C++
helpviewer_keywords:
- C4829
ms.assetid: 4ffabe2b-2ddc-4c52-8564-d1355c93cfa6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1c27ca268a3c873474cd4ed79a2b843642087c34
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4829"></a>Compilador C4829 de aviso (nível 1)
Parâmetros possivelmente incorretos para a função principal. Considere ' intmain (Platform:: array\<Platform:: String ^ > ^ argv)'  
  
 Determinadas funções, como principal, não é possível fazer referência parâmetros de tipo. Enquanto a compilação terá êxito, a imagem resultante provavelmente não será executado.  
  
 O exemplo a seguir gera C4829:  
  
```  
// C4829.cpp  
// compile by using: cl /EHsc /ZW /W4 /c C4829.cpp  
int main(Platform::String ^ s) {}   // C4829  
  
```