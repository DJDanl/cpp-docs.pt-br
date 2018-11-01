---
title: Erro do compilador C2414
ms.date: 11/04/2016
f1_keywords:
- C2414
helpviewer_keywords:
- C2414
ms.assetid: bbe94e03-862e-4990-b15e-544ae464727d
ms.openlocfilehash: 84fa715c8bd567770f361552e203a37c44ffdde4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50451045"
---
# <a name="compiler-error-c2414"></a>Erro do compilador C2414

número de operandos inválido

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. O opcode não oferece suporte para o número de operandos usados. Verifique um manual de referência de linguagem de assembly para determinar o número correto de operandos.

1. Um processador mais recente oferece suporte a instrução com um número diferente de operandos. Ajustar a [/arch (arquitetura mínima de CPU)](../../build/reference/arch-minimum-cpu-architecture.md) opção para usar o processador posterior.