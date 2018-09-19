---
title: NMAKE Erro Fatal U1099 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- U1099
dev_langs:
- C++
helpviewer_keywords:
- U1099
ms.assetid: 6688a805-43e6-4247-a2d0-14be082f0b13
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f3ef75a1435d8c922087fcdd21d1941961bc82cd
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46113377"
---
# <a name="nmake-fatal-error-u1099"></a>Erro fatal U1099 (NMAKE)

estouro de pilha

O makefile que está sendo processado era muito complexo para a alocação de pilha atual em NMAKE. NMAKE tem uma alocação de 0x3000 (12K).

Para aumentar a alocação da pilha do NMAKE, execute as [/stack (editbin)](../../build/reference/stack.md) utilitário com uma maior opção de pilha:

**editbin /STACK:reserve NMAKE. EXE**

em que *reservar* é um número maior que a alocação de pilha atual em NMAKE.