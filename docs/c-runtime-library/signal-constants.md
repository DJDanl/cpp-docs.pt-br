---
title: Constantes de sinal | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- SIGTERM
- SIGFPE
- SIGABRT
- SIGILL
- SIGINT
- SIGSEGV
dev_langs:
- C++
helpviewer_keywords:
- SIGTERM constant
- SIGABRT constant
- SIGSEGV constant
- SIGFPE constant
- SIGINT constant
- signal constants
- SIGILL constant
ms.assetid: a3b39281-dae7-4e44-8d68-e6a610c669dd
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 980281dfc313616baffb7942691372585d9c5bb7
ms.lasthandoff: 02/25/2017

---
# <a name="signal-constants"></a>Constantes de sinal
## <a name="syntax"></a>Sintaxe  
  
```  
#include <signal.h>  
```  
  
## <a name="remarks"></a>Comentários  
 O argumento `sig` deve ser uma das constantes de manifesto listadas abaixo (definidas no SIGNAL.H).  
  
 `SIGABRT`  
 Encerramento anormal. A ação padrão encerra o programa de chamada com o código de saída 3.  
  
 `SIGABRT_COMPAT`  
 Mesmo que SIGABRT. Para compatibilidade com outras plataformas.  
  
 `SIGFPE`  
 Erro de ponto flutuante, como estouro, divisão por zero ou operação inválida. A ação padrão encerra o programa de chamada.  
  
 `SIGILL`  
 Instrução ilegal. A ação padrão encerra o programa de chamada.  
  
 `SIGINT`  
 Interrupção CTRL+C. A ação padrão encerra o programa de chamada com o código de saída 3.  
  
 `SIGSEGV`  
 Acesso ao armazenamento inválido. A ação padrão encerra o programa de chamada.  
  
 `SIGTERM`  
 Solicitação de término enviada para o programa. A ação padrão encerra o programa de chamada com o código de saída 3.  
  
 `SIG_ERR`  
 Um tipo de retorno de um sinal que indica que um erro ocorreu.  
  
## <a name="see-also"></a>Consulte também  
 [signal](../c-runtime-library/reference/signal.md)   
 [raise](../c-runtime-library/reference/raise.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)
