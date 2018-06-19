---
title: Compilador (nível 1) de aviso C4190 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4190
dev_langs:
- C++
helpviewer_keywords:
- C4190
ms.assetid: a4d0ad93-a19a-4063-addd-36d605831567
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e62f6bcfaa499338d5fde1d09cb91574241ce8a0
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33277888"
---
# <a name="compiler-warning-level-1-c4190"></a>Compilador C4190 de aviso (nível 1)
'identifier1' possui vínculo a C especificado, mas retorna UDT 'identifier2', que é incompatível com C  
  
 Uma função ou um ponteiro para função tem um UDT (tipo definido por usuário, que é uma classe, estrutura, enum ou união) como tipo de retorno e `extern` ligação "C". Isso é válido se:  
  
-   Todas as chamadas para essa função ocorrerem de C++.  
  
-   É a definição da função em C++.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// C4190.cpp  
// compile with: /W1 /LD  
struct X  
{  
   int i;  
   X ();  
   virtual ~X ();  
};  
  
extern "C" X func ();   // C4190  
```