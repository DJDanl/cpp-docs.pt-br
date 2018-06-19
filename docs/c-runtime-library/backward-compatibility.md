---
title: Compatibilidade com versões anteriores | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e9a04dec046435478ca621ad8f5e2e3c4323f3e2
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32386232"
---
# <a name="backward-compatibility"></a>Compatibilidade com versões anteriores
Para compatibilidade entre versões do produto, a biblioteca OLDNAMES.LIB mapeia nomes antigos em relação a novos nomes. Por exemplo, `open` mapeia para `_open`. Você deve vincular explicitamente com OLDNAMES. LIB somente quando você compilar com as seguintes combinações de opções de linha de comando:  
  
-   `/Zl`(omitir nome da biblioteca padrão do arquivo de objeto) e `/Ze` (o padrão — use extensões da Microsoft)  
  
-   `/link`(vinculador controle), `/NOD` (nenhuma pesquisa de biblioteca padrão) e `/Ze`  
  
 Para obter mais informações sobre opções de linha de comando do compilador, consulte [Referência de compilador](../build/reference/compiler-options.md).  
  
## <a name="see-also"></a>Consulte também  
 [Compatibilidade](../c-runtime-library/compatibility.md)