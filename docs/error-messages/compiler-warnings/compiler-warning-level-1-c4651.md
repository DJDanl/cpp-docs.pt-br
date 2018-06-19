---
title: Compilador (nível 1) de aviso C4651 | Microsoft Docs
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
ms.openlocfilehash: 0015102a44b71f342b125532d20849590157ee0c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33283361"
---
# <a name="compiler-warning-level-1-c4651"></a>Compilador C4651 de aviso (nível 1)
'definição' especificada para cabeçalho pré-compilado, mas não para compilação atual  
  
 A definição foi especificada quando o cabeçalho pré-compilado foi gerado, mas não nesta compilação.  
  
 A definição estará em vigor dentro do cabeçalho pré-compilado, mas não no restante do código.  
  
 Se um cabeçalho pré-compilado foi criado com /DSYMBOL, o compilador gerará este aviso se a compilação /Yu não tem /DSYMBOL.  Adicionar /DSYMBOL à linha de comando /Yu resolve esse aviso.