---
title: Aviso do compilador (nível 1) C4407
ms.date: 11/04/2016
f1_keywords:
- C4407
helpviewer_keywords:
- C4407
ms.assetid: 32bc2c21-363a-4bb8-b486-725faeaededc
ms.openlocfilehash: 8dd78872d4edf82fb61c8ab93639dbcd93085754
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80162537"
---
# <a name="compiler-warning-level-1-c4407"></a>Aviso do compilador (nível 1) C4407

conversão entre um ponteiro diferente para representações de membro, o compilador pode gerar código incorreto

Foi detectada uma conversão incorreta.

C4407 pode ser gerado devido ao trabalho de conformidade do compilador que foi feito no Visual Studio 2005. O ponteiro para membro agora requer um nome qualificado e o operador de endereço (&).

C4407 pode ocorrer se você converter entre um ponteiro para membro de herança múltipla para um único ponteiro para membro de herança. Às vezes, isso pode funcionar, mas às vezes não é possível porque a representação de ponteiro para membro de herança única não contém informações suficientes. A compilação com o **/VMM** pode ajudar (para obter mais informações, consulte [/VMM,/VMS,/vmv (representação uso geral)](../../build/reference/vmm-vms-vmv-general-purpose-representation.md)). Você também pode tentar reorganizar suas classes base; o compilador está detectando uma perda de informações na conversão porque uma classe base está em um deslocamento diferente de zero do derivado.

O exemplo a seguir gera C4407:

```cpp
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
