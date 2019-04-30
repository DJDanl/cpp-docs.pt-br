---
title: Compilador aviso (nível 1) C4407
ms.date: 11/04/2016
f1_keywords:
- C4407
helpviewer_keywords:
- C4407
ms.assetid: 32bc2c21-363a-4bb8-b486-725faeaededc
ms.openlocfilehash: 5142e3800f3ad716166a27e3b0407a40999b5746
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62408401"
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