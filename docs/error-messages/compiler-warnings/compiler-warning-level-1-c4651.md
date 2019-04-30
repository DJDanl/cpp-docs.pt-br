---
title: Compilador aviso (nível 1) C4651
ms.date: 11/04/2016
f1_keywords:
- C4651
helpviewer_keywords:
- C4651
ms.assetid: f1ea82aa-4dc1-4972-b55a-57fdb962f0dd
ms.openlocfilehash: 01e2472a547e73eda5fcc56952949a0d9611029f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62393513"
---
# <a name="compiler-warning-level-1-c4651"></a>Compilador aviso (nível 1) C4651

'definição' especificada para cabeçalho pré-compilado, mas não para compilação atual

A definição foi especificada quando o cabeçalho pré-compilado foi gerado, mas não nesta compilação.

A definição estará em vigor dentro do cabeçalho pré-compilado, mas não no restante do código.

Se um cabeçalho pré-compilado foi criado com /DSYMBOL, o compilador gerará este aviso se a compilação /Yu não tem /DSYMBOL.  Adicionar /DSYMBOL à linha de comando /Yu resolve esse aviso.