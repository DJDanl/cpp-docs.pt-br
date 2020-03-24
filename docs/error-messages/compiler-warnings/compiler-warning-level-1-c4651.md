---
title: Aviso do compilador (nível 1) C4651
ms.date: 11/04/2016
f1_keywords:
- C4651
helpviewer_keywords:
- C4651
ms.assetid: f1ea82aa-4dc1-4972-b55a-57fdb962f0dd
ms.openlocfilehash: bc8131665c970c3b86bb1e84e39636ae8f93897b
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80199523"
---
# <a name="compiler-warning-level-1-c4651"></a>Aviso do compilador (nível 1) C4651

' Definition ' especificado para cabeçalho pré-compilado, mas não para compilação atual

A definição foi especificada quando o cabeçalho pré-compilado foi gerado, mas não nesta compilação.

A definição estará em vigor dentro do cabeçalho pré-compilado, mas não no restante do código.

Se um cabeçalho pré-compilado tiver sido criado com/DSYMBOL, o compilador gerará esse aviso se a compilação de/Yu não tiver/DSYMBOL.  Adicionar/DSYMBOL à linha de comando/Yu resolve esse aviso.
