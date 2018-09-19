---
title: Erro do compilador C2220 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2220
dev_langs:
- C++
helpviewer_keywords:
- C2220
ms.assetid: d610802c-64d7-40ad-a2a6-0ed0b6815a6c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7f4179b396e732ceeea20aeb9428d841a357a6d1
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46051315"
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