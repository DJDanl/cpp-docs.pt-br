---
title: "Compilador (nível 1) de aviso C4651 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4651
dev_langs:
- C++
helpviewer_keywords:
- C4651
ms.assetid: f1ea82aa-4dc1-4972-b55a-57fdb962f0dd
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: dce099d657341ebc957c95ab0cd14f508f9e36ee
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4651"></a>Compilador C4651 de aviso (nível 1)
'definição' especificada para cabeçalho pré-compilado, mas não para compilação atual  
  
 A definição foi especificada quando o cabeçalho pré-compilado foi gerado, mas não nesta compilação.  
  
 A definição estará em vigor dentro do cabeçalho pré-compilado, mas não no restante do código.  
  
 Se um cabeçalho pré-compilado foi criado com /DSYMBOL, o compilador gerará este aviso se a compilação /Yu não tem /DSYMBOL.  Adicionar /DSYMBOL à linha de comando /Yu resolve esse aviso.