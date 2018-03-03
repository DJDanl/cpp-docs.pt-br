---
title: "Compilador (nível 1) de aviso C4190 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4190
dev_langs:
- C++
helpviewer_keywords:
- C4190
ms.assetid: a4d0ad93-a19a-4063-addd-36d605831567
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 127eb4327826412d605f2a4a008e411880998073
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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