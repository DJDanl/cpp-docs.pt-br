---
title: Compilador (nível 1) de aviso C4799 | Microsoft Docs
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
ms.openlocfilehash: f888d6a941ad487ce122e46c43582e1c96525c70
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33282932"
---
# <a name="compiler-warning-level-1-c4799"></a>Compilador C4799 de aviso (nível 1)  
  
> Nenhum EMMS no final da função '*função*'  
  
A função tem pelo menos uma instrução de MMX, mas não tem um `EMMS` instrução. Quando uma instrução de multimídia é usada, uma `EMMS` instrução ou `_mm_empty` intrínseco também deve ser usado para limpar a palavra de multimídia marca o final do código MMX.  
  
Você pode obter C4799 quando usando ivec.h, indicando que o código não usa corretamente execute a instrução EMMS antes de retornar. Este é um aviso falso para esses cabeçalhos. Você pode desativá-los ao definir _SILENCE_IVEC_C4799 em ivec.h. No entanto, lembre-se de que isso também evitará que o compilador fornecendo avisos corretos desse tipo.  
  
Para obter informações relacionadas, consulte [do conjunto de instruções MMX da Intel](../../assembler/inline/intel-s-mmx-instruction-set.md).