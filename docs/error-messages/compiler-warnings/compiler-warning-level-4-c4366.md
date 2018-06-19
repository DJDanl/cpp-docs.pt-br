---
title: Compilador (nível 4) de aviso C4366 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4366
dev_langs:
- C++
helpviewer_keywords:
- C4366
ms.assetid: 65d2942f-3741-42f4-adf2-4920d5a055ca
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 12410a567cb55d6dea74b8e5e595009e56b1071f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33293696"
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