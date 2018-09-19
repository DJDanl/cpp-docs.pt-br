---
title: NMAKE Erro Fatal U1001 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- U1001
dev_langs:
- C++
helpviewer_keywords:
- U1001
ms.assetid: 5d7da559-6cbd-44d6-848c-aaf54cae0d1a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e4e465af5b4fa22c5f0ba5a9e01ebde0a7ee89e9
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46068137"
---
# <a name="nmake-fatal-error-u1001"></a>Erro fatal U1001 (NMAKE)

Erro de sintaxe: caractere ilegal 'character' em macro

O caractere especificado é exibido em uma macro, mas não é uma letra, número ou sublinhado.

Esse erro pode ser causado por uma vírgula ausente em uma expansão de macro:

```
syntax error : illegal character '=' in macro
```