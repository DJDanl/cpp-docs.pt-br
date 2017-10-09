---
title: "Compatibilidade com versões anteriores | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
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
ms.translationtype: HT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: 341dc7f2b16449356fab60f79424f5031ceefd6d
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="backward-compatibility"></a>Compatibilidade com versões anteriores
Para compatibilidade entre versões do produto, a biblioteca OLDNAMES.LIB mapeia nomes antigos em relação a novos nomes. Por exemplo, `open` mapeia para `_open`. Você deve vincular explicitamente com OLDNAMES. LIB somente quando você compilar com as seguintes combinações de opções de linha de comando:  
  
-   `/Zl`(omitir nome da biblioteca padrão do arquivo de objeto) e `/Ze` (o padrão — use extensões da Microsoft)  
  
-   `/link`(vinculador controle), `/NOD` (nenhuma pesquisa de biblioteca padrão) e `/Ze`  
  
 Para obter mais informações sobre opções de linha de comando do compilador, consulte [Referência de compilador](../build/reference/compiler-options.md).  
  
## <a name="see-also"></a>Consulte também  
 [Compatibilidade](../c-runtime-library/compatibility.md)
