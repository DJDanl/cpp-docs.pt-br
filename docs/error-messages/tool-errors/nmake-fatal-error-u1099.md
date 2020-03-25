---
title: Erro fatal U1099 (NMAKE)
ms.date: 11/04/2016
f1_keywords:
- U1099
helpviewer_keywords:
- U1099
ms.assetid: 6688a805-43e6-4247-a2d0-14be082f0b13
ms.openlocfilehash: c963180059a48d9aa0b09103df1ed54f82b8a2f1
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80193388"
---
# <a name="nmake-fatal-error-u1099"></a>Erro fatal U1099 (NMAKE)

estouro de pilha

O makefile que está sendo processado era muito complexo para a alocação de pilha atual em NMAKE. NMAKE tem uma alocação de 0x3000 (12K).

Para aumentar a alocação de pilha do NMAKE, execute o utilitário [editbin/stack](../../build/reference/stack.md) com uma opção de pilha maior:

**EDITBIN/STACK: Reserve NMAKE. EXE**

em que *Reserve* é um número maior que a alocação de pilha atual em NMAKE.
