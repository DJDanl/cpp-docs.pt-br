---
title: Dependentes inferidos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- inferred dependents in NMAKE
- dependents, inferred
ms.assetid: 9303045c-69b3-4f35-bffc-19d5cd6ea3c3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a86ed1a8fe6c97ae11af50f59cb639ef6fd7c1da
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32367892"
---
# <a name="inferred-dependents"></a>Dependentes inferidos
Um dependente deduzido é derivado de uma regra de inferência e é avaliado antes dependentes explícitas. Se um dependentes inferidos está desatualizado em relação ao seu destino, NMAKE invoca o bloco de comandos para a dependência. Se um dependentes inferidos não existem ou está desatualizado em relação à suas própria dependentes, NMAKE atualiza primeiro deduzido dependente. Para obter mais informações sobre dependentes inferidos, consulte [regras de inferência](../build/inference-rules.md).  
  
## <a name="see-also"></a>Consulte também  
 [Dependentes](../build/dependents.md)