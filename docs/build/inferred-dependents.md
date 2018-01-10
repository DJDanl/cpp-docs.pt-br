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
ms.workload: cplusplus
ms.openlocfilehash: 410e52dd9ee9605f6e29b81491bda0f4883e1cf9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="inferred-dependents"></a>Dependentes inferidos
Um dependente deduzido é derivado de uma regra de inferência e é avaliado antes dependentes explícitas. Se um dependentes inferidos está desatualizado em relação ao seu destino, NMAKE invoca o bloco de comandos para a dependência. Se um dependentes inferidos não existem ou está desatualizado em relação à suas própria dependentes, NMAKE atualiza primeiro deduzido dependente. Para obter mais informações sobre dependentes inferidos, consulte [regras de inferência](../build/inference-rules.md).  
  
## <a name="see-also"></a>Consulte também  
 [Dependentes](../build/dependents.md)