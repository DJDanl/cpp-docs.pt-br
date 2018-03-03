---
title: "Compilador (nível 1) de aviso C4627 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4627
dev_langs:
- C++
helpviewer_keywords:
- C4627
ms.assetid: 8840f3e6-b496-423a-8635-eb55d5f854a2
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 66d199b8dede21f94a963113341eb6426f66a807
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4627"></a>Compilador C4627 de aviso (nível 1)
'\<identificador >': ignorada durante a procura de uso de cabeçalho pré-compilado  
  
 Ao procurar o local em que um cabeçalho pré-compilado é usado, o compilador encontrou um `#include` diretiva para o  *\<identificador >* incluem o arquivo. O compilador ignora o `#include` diretiva, mas emite o aviso **C4627** se o cabeçalho pré-compilado ainda não contiver o  *\<identificador >* incluem o arquivo.  
  
## <a name="see-also"></a>Consulte também  
 [Criando arquivos de cabeçalho pré-compilado](../../build/reference/creating-precompiled-header-files.md)