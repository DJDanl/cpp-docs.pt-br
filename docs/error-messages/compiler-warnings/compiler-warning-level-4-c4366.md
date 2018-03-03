---
title: "Compilador (nível 4) de aviso C4366 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4366
dev_langs:
- C++
helpviewer_keywords:
- C4366
ms.assetid: 65d2942f-3741-42f4-adf2-4920d5a055ca
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 221cc02e5a2592599bad0ee9a77de59b19dda6f5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-4-c4366"></a>Compilador C4366 de aviso (nível 4)
O resultado do operador unário 'operator' deve ser unaligned  
  
 Se um membro da estrutura nunca pode ser não alinhado devido a remessa, o compilador avisará a quando se o endereço do membro está atribuído a um ponteiro alinhado. Por padrão, todos os ponteiros são alinhados.  
  
 Para resolver C4366, altere o alinhamento da estrutura ou declarar o ponteiro com o [unaligned](../../cpp/unaligned.md) palavra-chave.  
  
 Para obter mais informações, consulte unaligned e [pacote](../../preprocessor/pack.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4366.  
  
```  
// C4366.cpp  
// compile with: /W4 /c  
// processor: IPF x64  
#pragma pack(1)  
struct X {  
   short s1;  
   int s2;  
};  
  
int main() {  
   X x;  
   short * ps1 = &x.s1;   // OK  
   int * ps2 = &x.s2;   // C4366  
}  
```