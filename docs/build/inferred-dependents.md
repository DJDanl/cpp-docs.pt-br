---
title: Dependentes inferidos | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- inferred dependents in NMAKE
- dependents, inferred
ms.assetid: 9303045c-69b3-4f35-bffc-19d5cd6ea3c3
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: eaf75c067b2e96e5ae4a893b56376bfc1b9bd1e7
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="inferred-dependents"></a>Dependentes inferidos
Um dependente deduzido é derivado de uma regra de inferência e é avaliado antes dependentes explícitas. Se um dependentes inferidos está desatualizado em relação ao seu destino, NMAKE invoca o bloco de comandos para a dependência. Se um dependentes inferidos não existem ou está desatualizado em relação à suas própria dependentes, NMAKE atualiza primeiro deduzido dependente. Para obter mais informações sobre dependentes inferidos, consulte [regras de inferência](../build/inference-rules.md).  
  
## <a name="see-also"></a>Consulte também  
 [Dependentes](../build/dependents.md)