---
title: Erro do compilador C2414
ms.date: 11/04/2016
f1_keywords:
- C2414
helpviewer_keywords:
- C2414
ms.assetid: bbe94e03-862e-4990-b15e-544ae464727d
ms.openlocfilehash: fbe627a57e5defc499a4bc5d463e0bf33494acba
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80205654"
---
# <a name="compiler-error-c2414"></a>Erro do compilador C2414

número ilegal de operandos

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. O opcode não oferece suporte ao número de operandos usados. Verifique um manual de referência de linguagem de assembly para determinar o número correto de operandos.

1. Um processador mais recente dá suporte à instrução com um número diferente de operandos. Ajuste a opção [/Arch (arquitetura de CPU mínima)](../../build/reference/arch-minimum-cpu-architecture.md) para usar o processador posterior.
