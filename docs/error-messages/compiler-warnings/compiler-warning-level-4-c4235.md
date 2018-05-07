---
title: Compilador (nível 4) de aviso C4235 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4235
dev_langs:
- C++
helpviewer_keywords:
- C4235
ms.assetid: d4214799-d62c-4674-b4e2-9e201c303303
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dc63640bc58caefa281b9207b9796ffdf387a7a8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-4-c4235"></a>Compilador C4235 de aviso (nível 4)
extensão não padrão usada: palavra-chave de 'palavra-chave' não tem suportada nesta arquitetura  
  
 O compilador não oferece suporte a palavra-chave que você usou.  
  
 Esse aviso é promovido automaticamente a um erro. Se você quiser modificar esse comportamento, use [#pragma aviso](../../preprocessor/warning.md). Por exemplo, para tornar C4235 um aviso de nível 2, use a seguinte linha de código  
  
```  
#pragma warning(2:4235)  
```  
  
 no arquivo de código fonte.