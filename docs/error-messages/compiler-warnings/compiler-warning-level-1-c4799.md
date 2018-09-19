---
title: Compilador aviso (nível 1) C4799 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4799
dev_langs:
- C++
helpviewer_keywords:
- C4799
ms.assetid: 8ecbd06f-c778-4371-a2fb-c690b6743ec8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b3d83917289e5ad76a874587894a66e163fed90a
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46088222"
---
# <a name="compiler-warning-level-1-c4799"></a>Compilador aviso (nível 1) C4799

> Nenhum EMMS no final da função '*função*'

A função tem pelo menos uma instrução de MMX, mas não tem um `EMMS` instrução. Quando uma instrução de multimídia é usada, uma `EMMS` instrução ou `_mm_empty` intrínseco também deve ser usado para limpar a palavra de marca de multimídia no final do código MMX.

Você pode obter C4799 quando usando ivec.h, indicando que o código não usa corretamente executa a instrução EMMS antes de retornar. Este é um aviso falso para esses cabeçalhos. Você pode desativá-los, definindo _SILENCE_IVEC_C4799 em ivec.h. No entanto, lembre-se de que isso também impedirá o compilador dando avisos corretos desse tipo.

Para obter informações relacionadas, consulte [do conjunto de instruções MMX da Intel](../../assembler/inline/intel-s-mmx-instruction-set.md).