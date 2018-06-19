---
title: Compilador (nível 1) de aviso C4910 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
dev_langs:
- C++
helpviewer_keywords:
- C4910
ms.assetid: 67963560-fbca-4ca7-93db-06beaf7055f0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 34ed2ec16f579b05a572cf6bfc236cd8d5743f63
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33290342"
---
# <a name="compiler-warning-level-1-c4910"></a>Compilador C4910 de aviso (nível 1)
'\<identificador >': 'dllexport' e 'extern' são incompatíveis em uma instanciação explícita  
  
 A instanciação de template explícitos denominada  *\<identificador >* seja modificada por ambos os `__declspec(dllexport)` e `extern` palavras-chave. No entanto, essas palavras-chave é mutuamente exclusivos. O `__declspec(dllexport)` palavra-chave significa instanciar a classe de modelo, enquanto o `extern` palavra-chave significa automaticamente não instanciar a classe de modelo.  
  
## <a name="see-also"></a>Consulte também  
 [Instanciação explícita](../../cpp/explicit-instantiation.md)   
 [dllexport, dllimport](../../cpp/dllexport-dllimport.md)   
 [Regras e limitações gerais](../../cpp/general-rules-and-limitations.md)