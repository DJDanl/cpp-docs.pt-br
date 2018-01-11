---
title: "Compilador (nível 1) de aviso C4910 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: C4910
ms.assetid: 67963560-fbca-4ca7-93db-06beaf7055f0
caps.latest.revision: "3"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9f758e2e15d5492724e9b819622202831d4e9f5d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4910"></a>Compilador C4910 de aviso (nível 1)
'\<identificador >': 'dllexport' e 'extern' são incompatíveis em uma instanciação explícita  
  
 A instanciação de template explícitos denominada  *\<identificador >* seja modificada por ambos os `__declspec(dllexport)` e `extern` palavras-chave. No entanto, essas palavras-chave é mutuamente exclusivos. O `__declspec(dllexport)` palavra-chave significa instanciar a classe de modelo, enquanto o `extern` palavra-chave significa automaticamente não instanciar a classe de modelo.  
  
## <a name="see-also"></a>Consulte também  
 [Instanciação explícita](../../cpp/explicit-instantiation.md)   
 [dllexport, dllimport](../../cpp/dllexport-dllimport.md)   
 [Regras e limitações gerais](../../cpp/general-rules-and-limitations.md)