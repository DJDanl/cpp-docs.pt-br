---
title: "Compilador aviso (nível 1) C4910 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- C4910
ms.assetid: 67963560-fbca-4ca7-93db-06beaf7055f0
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: c5d0a1873fef53b64c74c5971068214252ef80a0
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4910"></a>Compilador C4910 de aviso (nível 1)
'\<identificador >': 'dllexport' e 'extern' são incompatíveis em uma instanciação explícita  
  
 A instanciação explícita de modelo chamada * \<identificador >* é modificado por ambos os `__declspec(dllexport)` e `extern` palavras-chave. No entanto, essas palavras-chave é mutuamente exclusivos. O `__declspec(dllexport)` palavra-chave significa criar uma instância da classe de modelo, enquanto o `extern` meios de palavra-chave não instanciar a classe de modelo automaticamente.  
  
## <a name="see-also"></a>Consulte também  
 [Instanciação explícita](../../cpp/explicit-instantiation.md)   
 [dllexport, dllimport](../../cpp/dllexport-dllimport.md)   
 [Regras gerais e limitações](../../cpp/general-rules-and-limitations.md)
