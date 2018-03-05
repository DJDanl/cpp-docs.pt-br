---
title: "Constantes de ação de sinal | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- SIG_IGN
- SIG_DFL
dev_langs:
- C++
helpviewer_keywords:
- signal action constants
- SIG_IGN constant
- SIG_DFL constant
ms.assetid: c3cb4f15-d39e-4d9d-84f9-0d33e3eb5993
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 256f11d3f8daa8a00e70e24aa19c31b71413c13c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="signal-action-constants"></a>Constantes de ação de sinal
A ação tomada quando o sinal de interrupção for recebido depende do valor de `func`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#include <signal.h>  
```  
  
## <a name="remarks"></a>Comentários  
 O argumento `func` deve ser um endereço de função ou uma das constantes de manifesto listados abaixo e definido no SIGNAL.H.  
  
 `SIG_DFL`  
 Usa a resposta padrão do sistema. Se o programa de chamada usa e/s de fluxo, buffers criados pela biblioteca em tempo de execução não são liberados.  
  
 `SIG_IGN`  
 Ignora o sinal de interrupção. Esse valor nunca deve ser fornecido para `SIGFPE`, uma vez que o estado de ponto flutuante do processo é deixado indefinido.  
  
 `SIG_SGE`  
 Indica que ocorreu um erro no sinal.  
  
 `SIG_ACK`  
 Indica que uma confirmação foi recebida.  
  
 `SIG_ERR`  
 Um tipo de retorno de um sinal que indica que um erro ocorreu.  
  
## <a name="see-also"></a>Consulte também  
 [signal](../c-runtime-library/reference/signal.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)