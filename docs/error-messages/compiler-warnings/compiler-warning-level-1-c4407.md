---
title: Compilador aviso (nível 1) C4407 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4407
dev_langs:
- C++
helpviewer_keywords:
- C4407
ms.assetid: 32bc2c21-363a-4bb8-b486-725faeaededc
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a9a665dbb71157b37f72d3d0721357d00dc37230
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46032595"
---
# <a name="compiler-warning-level-1-c4407"></a>Compilador aviso (nível 1) C4407

conversão entre diferente ponteiro para representações de membro, compilador pode gerar código incorreto

Foi detectada uma conversão incorreta.

C4407 pode ser gerado devido ao trabalho de conformidade do compilador que foi feito no Visual C++ 2005. Ponteiro para membro agora requer um nome qualificado e o operador address-of (&).

C4407 pode ocorrer se você converter entre vários herança ponteiro-para-membro a um herança única ponteiro para membro. Às vezes, isso pode funcionar, mas, às vezes, ele não é possível porque a representação de ponteiro para membro de herança única não conter informações suficientes. Compilar com o **/vmm** podem ajudar a (para obter mais informações, consulte [/vmm, /vms, /vmv (representação de finalidade geral)](../../build/reference/vmm-vms-vmv-general-purpose-representation.md)). Você também pode tentar reorganizar suas classes base; o compilador está detectando uma perda de informações na conversão porque uma classe base está em um deslocamento diferente de zero de derivada.

O exemplo a seguir gera C4407:

```
// C4407.cpp
// compile with: /W1 /c
struct C1 {};
struct C2 {};
struct C3 : C1, C2 {};

typedef void(C3::*PMF_C3)();
typedef void(C2::*PMF_C2)();

PMF_C2 f1(PMF_C3 pmf) {
   return (PMF_C2)pmf;   // C4407, change type of cast,
   // or reverse base class inheritance of C3 (i.e. : C2, C1)
}
```