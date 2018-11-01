---
title: Compilador aviso (nível 4) C4131
ms.date: 11/04/2016
f1_keywords:
- C4131
helpviewer_keywords:
- C4131
ms.assetid: 7903b3e1-454f-4be2-aa9b-230992f96a2d
ms.openlocfilehash: 24872bb0b42de77dde358dc29f99826b41638628
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50516045"
---
# <a name="compiler-warning-level-4-c4131"></a>Compilador aviso (nível 4) C4131

'function': usa Declarador de estilo antigo

A declaração da função especificada não está na forma de protótipo.

Declarações de função antiga devem ser convertidas em forma de protótipo.

O exemplo a seguir mostra uma declaração de função de estilo antigo:

```
// C4131.c
// compile with: /W4 /c
void addrec( name, id ) // C4131 expected
char *name;
int id;
{ }
```

O exemplo a seguir mostra um formulário de protótipo:

```
void addrec( char *name, int id )
{ }
```