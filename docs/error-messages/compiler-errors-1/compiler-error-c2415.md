---
title: Erro do compilador C2415
ms.date: 11/04/2016
f1_keywords:
- C2415
helpviewer_keywords:
- C2415
ms.assetid: f225c913-2bea-46b1-b096-3d358ac94a15
ms.openlocfilehash: a0cdd528eca8ea267c62e6d44752d29ae16830c4
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80205615"
---
# <a name="compiler-error-c2415"></a>Erro do compilador C2415

tipo de operando inadequado

O opcode não usa operandos desse tipo.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. O opcode não oferece suporte ao número de operandos usados. Verifique um manual de referência de linguagem de assembly para determinar o número correto de operandos.

1. Um processador mais recente dá suporte à instrução com tipos adicionais. Ajuste a opção [/Arch (arquitetura de CPU mínima)](../../build/reference/arch-minimum-cpu-architecture.md) para usar o processador posterior.
