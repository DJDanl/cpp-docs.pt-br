---
title: "Compilador aviso (nível 1) C4627 | Documentos do Microsoft"
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
caps.latest.revision: 3
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 92992650559b9c9e4c1a2234991f7368a7135b34
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4627"></a>Compilador C4627 de aviso (nível 1)
'\<identificador >': ignorados quando procurando pré-compilados uso do cabeçalho  
  
 Ao procurar o local onde um cabeçalho pré-compilado é usado, o compilador encontrou uma `#include` diretriz para a * \<identificador >* arquivo de inclusão. O compilador ignora o `#include` diretiva, mas emite aviso **C4627** se o cabeçalho pré-compilado ainda não contiver o * \<identificador >* arquivo de inclusão.  
  
## <a name="see-also"></a>Consulte também  
 [Criando arquivos de cabeçalho pré-compilados](../../build/reference/creating-precompiled-header-files.md)
