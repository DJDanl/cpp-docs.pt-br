---
title: Compilador (nível 1) de aviso C4627 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4627
dev_langs:
- C++
helpviewer_keywords:
- C4627
ms.assetid: 8840f3e6-b496-423a-8635-eb55d5f854a2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dcde9e6707465fd95dbcb10e073a852624f0de0a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33284180"
---
# <a name="compiler-warning-level-1-c4627"></a>Compilador C4627 de aviso (nível 1)
'\<identificador >': ignorada durante a procura de uso de cabeçalho pré-compilado  
  
 Ao procurar o local em que um cabeçalho pré-compilado é usado, o compilador encontrou um `#include` diretiva para o  *\<identificador >* incluem o arquivo. O compilador ignora o `#include` diretiva, mas emite o aviso **C4627** se o cabeçalho pré-compilado ainda não contiver o  *\<identificador >* incluem o arquivo.  
  
## <a name="see-also"></a>Consulte também  
 [Criando arquivos de cabeçalho pré-compilado](../../build/reference/creating-precompiled-header-files.md)