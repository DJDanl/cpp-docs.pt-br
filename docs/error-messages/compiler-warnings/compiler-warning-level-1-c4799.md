---
title: Aviso do compilador (nível 1) C4799
ms.date: 11/04/2016
f1_keywords:
- C4799
helpviewer_keywords:
- C4799
ms.assetid: 8ecbd06f-c778-4371-a2fb-c690b6743ec8
ms.openlocfilehash: ec92da425718cd5ddc579d1d733a0bc4e56dc04a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80175097"
---
# <a name="compiler-warning-level-1-c4799"></a>Aviso do compilador (nível 1) C4799

> Nenhum EMMS no final da função '*Function*'

A função tem pelo menos uma instrução MMX, mas não tem uma instrução `EMMS`. Quando uma instrução multimídia é usada, uma instrução `EMMS` ou `_mm_empty` intrínseco também deve ser usado para limpar a palavra de marca multimídia no final do código de MMX.

Você pode obter C4799 ao usar ivec. h, indicando que o código não usa corretamente a instrução EMMS antes de retornar. Esse é um aviso falso para esses cabeçalhos. Você pode desativá-las definindo _SILENCE_IVEC_C4799 em IVEC. h. No entanto, lembre-se de que isso também impedirá que o compilador forneça avisos corretos desse tipo.

Para obter informações relacionadas, consulte [conjunto de instruções MMX da Intel](../../assembler/inline/intel-s-mmx-instruction-set.md).
