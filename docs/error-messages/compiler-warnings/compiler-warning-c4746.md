---
title: C4746 de aviso do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
dev_langs:
- C++
ms.assetid: 5e79ab46-6031-499a-a986-716c866b6c0e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9d00c75b2b7cdf2fdafb4e109496a701fb561cb9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33270892"
---
# <a name="compiler-warning-c4746"></a>C4746 de aviso do compilador
acesso volátil de '\<expressão >' está sujeito a /volatile: [iso&#124;ms] definindo; considere o uso de funções intrínsecas iso_volatile_load/store.  
  
 C4746 é emitido sempre que uma variável volátil é acessada diretamente. Ele se destina a ajudar os desenvolvedores a identificar os locais de código que são afetadas pelo modelo volátil específico no momento especificado (que pode ser controlado com o [/volátil](../../build/reference/volatile-volatile-keyword-interpretation.md) opção de compilador). Em particular, pode ser útil para localizar as barreiras de memória de hardware gerados pelo compilador quando /volatile:ms é usado.  
  
 Os iso_volatile_load/store intrínsecos podem ser usados para acessar explicitamente memória volátil sem ser afetado pelo modelo voláteis. Usar essas intrínsecos não vai disparar C4746.  
  
 Esse aviso é desativada por padrão. Consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.