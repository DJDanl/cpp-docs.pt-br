---
title: "Compilador (nível 4) de aviso C4960 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C4960
dev_langs: C++
helpviewer_keywords: C4960
ms.assetid: 3b4ed286-9e8d-46f1-af0c-00ba669693a9
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 160ae5a50d55ab0ebc89335aa3951aa781175feb
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-4-c4960"></a>Compilador C4960 de aviso (nível 4)
'function' é muito grande para ser analisado  
  
 Ao usar [/LTCG:PGOPTIMIZE](../../build/reference/ltcg-link-time-code-generation.md), o compilador detectou um módulo de entrada com uma função maior que 65.535 instruções. Tal função não está disponível para otimizações guiadas por perfil.  
  
 Para resolver este aviso, reduza o tamanho da função.