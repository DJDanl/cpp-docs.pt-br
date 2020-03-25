---
title: Aviso do compilador C4746
ms.date: 11/04/2016
f1_keywords:
- C4746
helpviewer_keywords:
- C4746
ms.assetid: 5e79ab46-6031-499a-a986-716c866b6c0e
ms.openlocfilehash: 7179e2e6d4ec44355e7338ffc4e9ba36f5de47e4
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80165100"
---
# <a name="compiler-warning-c4746"></a>Aviso do compilador C4746

o acesso volátil de '\<Expression > ' está sujeito à configuração/volatile:&#124;[ISO MS]; Considere usar __iso_volatile_load funções intrínsecas/Store.

C4746 é emitido sempre que uma variável volátil é acessada diretamente. Ele destina-se a ajudar os desenvolvedores a identificar os locais de código que são afetados pelo modelo volátil específico especificado no momento (que pode ser controlado com a opção de compilador [/volatile](../../build/reference/volatile-volatile-keyword-interpretation.md) ). Em particular, ele pode ser útil para localizar barreiras de memória de hardware geradas pelo compilador quando/volatile: MS é usado.

O __iso_volatile_load/Store intrínsecos pode ser usado para acessar explicitamente a memória volátil sem ser afetado pelo modelo volátil. Usar esses intrínsecos não irá disparar C4746.

Esse aviso está desativado por padrão. Consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.
