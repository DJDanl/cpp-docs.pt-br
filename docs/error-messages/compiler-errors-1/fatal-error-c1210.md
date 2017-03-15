---
title: Erro fatal C1210 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C1210
dev_langs:
- C++
helpviewer_keywords:
- C1210
ms.assetid: e2208309-c284-425c-a7e8-48e96e66f35b
caps.latest.revision: 7
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
translationtype: Machine Translation
ms.sourcegitcommit: cc82b83860786ffc3f0aee73ede18ecadef16a7a
ms.openlocfilehash: f3abd56aebdf7e83bbab10b6083ad6fc14987fbd
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1210"></a>Erro fatal C1210
/clr:pure e /clr:safe não são suportados pela versão de tempo de execução instalada  
  
 O **/clr: puro** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015.  
  
 C1210 ocorre quando você tem um compilador para a versão atual, mas um common language runtime de uma versão anterior.  
  
 Algumas funcionalidades do compilador não podem funcionar em uma versão anterior do tempo de execução.  
  
 Para resolver C1210 instalar a versão de tempo de execução de linguagem comum que é destinada para uso com o compilador.
