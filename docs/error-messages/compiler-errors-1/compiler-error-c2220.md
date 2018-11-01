---
title: Erro do compilador C2220
ms.date: 11/04/2016
f1_keywords:
- C2220
helpviewer_keywords:
- C2220
ms.assetid: d610802c-64d7-40ad-a2a6-0ed0b6815a6c
ms.openlocfilehash: 3ff730c6fea7d2c57c4ec3054fc627cdc6227e2d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50603405"
---
# <a name="compiler-error-c2220"></a>Erro do compilador C2220

Aviso tratado como erro - nenhum arquivo de objeto gerado

[/WX](../../build/reference/compiler-option-warning-level.md) instrui o compilador a tratar todos os avisos como erros. Porque ocorreu um erro, nenhum objeto ou arquivo executável foi gerado.

Esse erro aparece somente quando o **/WX** sinalizador está definido e ocorrer um aviso durante a compilação. Para corrigir esse erro, você deve eliminar cada aviso em seu projeto.

### <a name="to-fix-use-one-of-the-following-techniques"></a>Para corrigir, use uma das seguintes técnicas

- Corrija os problemas que causam avisos em seu projeto.

- Compilar em um nível inferior do aviso — por exemplo, use **/w3** em vez de **/W4**.

- Use uma [aviso](../../preprocessor/warning.md) pragma para desabilitar ou suprimir um aviso específico.

- Não use **/WX** para compilar.