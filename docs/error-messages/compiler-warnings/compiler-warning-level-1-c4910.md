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
ms.openlocfilehash: f0402e03d77968de3b4c1addf58c481ec85a61b8
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-1-c4910"></a>Compilador C4910 de aviso (nível 1)
'\<identificador >': 'dllexport' e 'extern' são incompatíveis em uma instanciação explícita  
  
 A instanciação de template explícitos denominada  *\<identificador >* seja modificada por ambos os `__declspec(dllexport)` e `extern` palavras-chave. No entanto, essas palavras-chave é mutuamente exclusivos. O `__declspec(dllexport)` palavra-chave significa instanciar a classe de modelo, enquanto o `extern` palavra-chave significa automaticamente não instanciar a classe de modelo.  
  
## <a name="see-also"></a>Consulte também  
 [Instanciação explícita](../../cpp/explicit-instantiation.md)   
 [dllexport, dllimport](../../cpp/dllexport-dllimport.md)   
 [Regras e limitações gerais](../../cpp/general-rules-and-limitations.md)