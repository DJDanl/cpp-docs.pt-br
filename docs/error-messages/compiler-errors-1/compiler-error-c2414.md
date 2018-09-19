---
title: Erro do compilador C2414 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2414
dev_langs:
- C++
helpviewer_keywords:
- C2414
ms.assetid: bbe94e03-862e-4990-b15e-544ae464727d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 642cb00605ed13146288edf5d39cb5d0c14c6e9f
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46089912"
---
# <a name="compiler-error-c2414"></a>Erro do compilador C2414

número de operandos inválido

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. O opcode não oferece suporte para o número de operandos usados. Verifique um manual de referência de linguagem de assembly para determinar o número correto de operandos.

1. Um processador mais recente oferece suporte a instrução com um número diferente de operandos. Ajustar a [/arch (arquitetura mínima de CPU)](../../build/reference/arch-minimum-cpu-architecture.md) opção para usar o processador posterior.