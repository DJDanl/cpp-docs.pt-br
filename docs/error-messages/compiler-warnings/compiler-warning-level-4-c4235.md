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
ms.openlocfilehash: f4266a2aae53254bbb7c2a043ccf3240d69cc63a
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-4-c4235"></a>Compilador C4235 de aviso (nível 4)
extensão não padrão usada: palavra-chave de 'palavra-chave' não tem suportada nesta arquitetura  
  
 O compilador não oferece suporte a palavra-chave que você usou.  
  
 Esse aviso é promovido automaticamente a um erro. Se você quiser modificar esse comportamento, use [#pragma aviso](../../preprocessor/warning.md). Por exemplo, para tornar C4235 um aviso de nível 2, use a seguinte linha de código  
  
```  
#pragma warning(2:4235)  
```  
  
 no arquivo de código fonte.