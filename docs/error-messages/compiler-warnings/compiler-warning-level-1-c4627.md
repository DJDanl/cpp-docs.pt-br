---
title: "Compilador (nível 1) de aviso C4627 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C4627
dev_langs: C++
helpviewer_keywords: C4627
ms.assetid: 8840f3e6-b496-423a-8635-eb55d5f854a2
caps.latest.revision: "3"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 7290a7b85be1c27fd33b11507bb2b2994ed5aaad
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-1-c4627"></a>Compilador C4627 de aviso (nível 1)
'\<identificador >': ignorada durante a procura de uso de cabeçalho pré-compilado  
  
 Ao procurar o local em que um cabeçalho pré-compilado é usado, o compilador encontrou um `#include` diretiva para o  *\<identificador >* incluem o arquivo. O compilador ignora o `#include` diretiva, mas emite o aviso **C4627** se o cabeçalho pré-compilado ainda não contiver o  *\<identificador >* incluem o arquivo.  
  
## <a name="see-also"></a>Consulte também  
 [Criando arquivos de cabeçalho pré-compilado](../../build/reference/creating-precompiled-header-files.md)