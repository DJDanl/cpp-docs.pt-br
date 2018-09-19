---
title: Compilador aviso (nível 1) C4651 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4651
dev_langs:
- C++
helpviewer_keywords:
- C4651
ms.assetid: f1ea82aa-4dc1-4972-b55a-57fdb962f0dd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b516ef86372901d00dd20d94ed10d5e361bbab8d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46099446"
---
# <a name="compiler-warning-level-1-c4651"></a>Compilador aviso (nível 1) C4651

'definição' especificada para cabeçalho pré-compilado, mas não para compilação atual

A definição foi especificada quando o cabeçalho pré-compilado foi gerado, mas não nesta compilação.

A definição estará em vigor dentro do cabeçalho pré-compilado, mas não no restante do código.

Se um cabeçalho pré-compilado foi criado com /DSYMBOL, o compilador gerará este aviso se a compilação /Yu não tem /DSYMBOL.  Adicionar /DSYMBOL à linha de comando /Yu resolve esse aviso.