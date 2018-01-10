---
title: Constantes de sinal | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- SIGTERM
- SIGFPE
- SIGABRT
- SIGILL
- SIGINT
- SIGSEGV
dev_langs: C++
helpviewer_keywords:
- SIGTERM constant
- SIGABRT constant
- SIGSEGV constant
- SIGFPE constant
- SIGINT constant
- signal constants
- SIGILL constant
ms.assetid: a3b39281-dae7-4e44-8d68-e6a610c669dd
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 4e47e3e7bce5a41e055f251d906ec72d98c5b285
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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