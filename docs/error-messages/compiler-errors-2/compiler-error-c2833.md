---
title: C2833 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2833
dev_langs:
- C++
helpviewer_keywords:
- C2833
ms.assetid: b9418ce1-e2ee-4599-8959-6fde89c27569
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ff066510292690bc940f18ab8d63605eb8627308
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33244104"
---
# <a name="compiler-error-c2833"></a>C2833 de erro do compilador
'operator operador' não é um operador ou tipo reconhecido  
  
 A palavra `operator` deve ser seguido por um operador que você deseja substituir ou um tipo que você deseja converter.  
  
 Para obter uma lista dos operadores que você pode definir um tipo gerenciado, consulte [operadores definidos pelo usuário](../../dotnet/user-defined-operators-cpp-cli.md).  
  
 O exemplo a seguir gera C2833:  
  
```  
// C2833.cpp  
// compile with: /c  
class A {};  
  
void operator ::* ();   // C2833  
void operator :: ();   // OK  
```