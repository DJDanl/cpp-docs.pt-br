---
title: "Compatibilidade com versões anteriores | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- c.programs
dev_langs:
- C++
helpviewer_keywords:
- CRT, compatibility
- backward compatibility, C run-time libraries
- compatibility, C run-time libraries
- backward compatibility
ms.assetid: cc3175cf-97fd-492f-b329-5791aea63090
caps.latest.revision: 7
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
ms.openlocfilehash: c4295d2f45322e4c472a8cd391d0f52ab256c366
ms.lasthandoff: 02/25/2017

---
# <a name="backward-compatibility"></a>Compatibilidade com versões anteriores
Para compatibilidade entre versões do produto, a biblioteca OLDNAMES.LIB mapeia nomes antigos em relação a novos nomes. Por exemplo, `open` mapeia para `_open`. Você deve vincular explicitamente com OLDNAMES. LIB somente quando você compilar com as seguintes combinações de opções de linha de comando:  
  
-   `/Zl`(omitir nome da biblioteca padrão do arquivo de objeto) e `/Ze` (o padrão — use extensões da Microsoft)  
  
-   `/link`(vinculador controle), `/NOD` (nenhuma pesquisa de biblioteca padrão) e `/Ze`  
  
 Para obter mais informações sobre opções de linha de comando do compilador, consulte [Referência de compilador](../build/reference/compiler-options.md).  
  
## <a name="see-also"></a>Consulte também  
 [Compatibilidade](../c-runtime-library/compatibility.md)
