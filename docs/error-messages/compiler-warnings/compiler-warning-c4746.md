---
title: C4746 de aviso do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
dev_langs: C++
ms.assetid: 5e79ab46-6031-499a-a986-716c866b6c0e
caps.latest.revision: "2"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f92bae0e75d9a09de874cd999c044e703b3f3171
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-c4746"></a>C4746 de aviso do compilador
acesso volátil de '\<expressão >' está sujeito a /volatile: [iso &#124; ms] definindo; considere o uso de funções intrínsecas iso_volatile_load/store.  
  
 C4746 é emitido sempre que uma variável volátil é acessada diretamente. Ele se destina a ajudar os desenvolvedores a identificar os locais de código que são afetadas pelo modelo volátil específico no momento especificado (que pode ser controlado com o [/volátil](../../build/reference/volatile-volatile-keyword-interpretation.md) opção de compilador). Em particular, pode ser útil para localizar as barreiras de memória de hardware gerados pelo compilador quando /volatile:ms é usado.  
  
 Os iso_volatile_load/store intrínsecos podem ser usados para acessar explicitamente memória volátil sem ser afetado pelo modelo voláteis. Usar essas intrínsecos não vai disparar C4746.  
  
 Esse aviso é desativada por padrão. Consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.