---
title: Aviso LNK4078 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4078
helpviewer_keywords:
- LNK4078
ms.assetid: 5a16796d-6caf-42d9-8f65-b042843eafb8
ms.openlocfilehash: 9ce72f476aa85434acd5277d0307ffc61e0a0214
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74990993"
---
# <a name="linker-tools-warning-lnk4078"></a>Aviso LNK4078 (Ferramentas de Vinculador)

várias seções de ' nome da seção ' encontradas com atributos diferentes

O LINK encontrou duas ou mais seções que têm o mesmo nome, mas atributos diferentes.

Esse aviso pode ser causado por uma biblioteca de importação ou arquivo de exportação que foi criado por uma versão anterior do LINK ou da LIB.

Recrie o arquivo e vincule novamente.

## <a name="example"></a>Exemplo

LNK4078 também pode ser causado por uma alteração significativa: a seção nomeada por [init_seg](../../preprocessor/init-seg.md) em x86 foi de leitura/gravação, agora ela é somente leitura.

O exemplo a seguir gera LNK4078.

```cpp
// LNK4078.cpp
// compile with: /W1
// LNK4078 expected
#include <stdio.h>
#pragma warning(disable : 4075)
typedef void (__cdecl *PF)(void);
int cxpf = 0;   // number of destructors to call
PF pfx[200];   // pointers to destructors.

struct A { A() {} };

int myexit (PF pf) { return 0; }

#pragma section(".mine$a", read, write)
// try the following line instead
// #pragma section(".mine$a", read)
__declspec(allocate(".mine$a")) int ii = 1;

#pragma section(".mine$z", read, write)
// try the following line instead
// #pragma section(".mine$z", read)
__declspec(allocate(".mine$z")) int i = 1;

#pragma data_seg()
#pragma init_seg(".mine$m", myexit)
A bbbb;
A cccc;
int main() {}
```
