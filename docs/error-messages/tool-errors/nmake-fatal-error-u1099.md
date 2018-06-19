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
ms.openlocfilehash: 7be09691de4212d07b1452ffe33725a3978fc053
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33322098"
---
# <a name="nmake-fatal-error-u1099"></a>Erro fatal U1099 (NMAKE)
estouro de pilha  
  
 Makefile processado era muito complexo para a alocação da pilha atual em NMAKE. NMAKE possui uma alocação de 0x3000 (12K).  
  
 Para aumentar a alocação da pilha do NMAKE, execute o [editbin /stack](../../build/reference/stack.md) utilitário com uma opção maior de pilha:  
  
 **editbin /STACK:reserve NMAKE. EXE**  
  
 onde *reservar* é um número maior que a alocação da pilha atual em NMAKE.