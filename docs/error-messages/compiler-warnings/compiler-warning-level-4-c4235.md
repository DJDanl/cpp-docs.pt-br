---
title: "Compilador (nível 4) de aviso C4235 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4235
dev_langs: C++
helpviewer_keywords: C4235
ms.assetid: d4214799-d62c-4674-b4e2-9e201c303303
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b0fea028932a48b9c7ee1a677a3e6dc8078edc35
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-4-c4235"></a>Compilador C4235 de aviso (nível 4)
extensão não padrão usada: palavra-chave de 'palavra-chave' não tem suportada nesta arquitetura  
  
 O compilador não oferece suporte a palavra-chave que você usou.  
  
 Esse aviso é promovido automaticamente a um erro. Se você quiser modificar esse comportamento, use [#pragma aviso](../../preprocessor/warning.md). Por exemplo, para tornar C4235 um aviso de nível 2, use a seguinte linha de código  
  
```  
#pragma warning(2:4235)  
```  
  
 no arquivo de código fonte.