---
title: "Testando erros de extração | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- extraction errors
ms.assetid: 6a681028-adba-4557-8f7b-f137932905f8
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 232dbd4312bbb8a0f16b6095622680f070ff2905
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="testing-for-extraction-errors"></a>Testando erros de extração
Gere as funções de processamento de erro, abordadas em [Funções de processamento de erro](../standard-library/output-file-stream-member-functions.md), aplicadas a fluxos de entrada. É importante testar erros durante a extração. Considere esta instrução:  
  
```  
cin>> n;  
```  
  
 Se `n` for um inteiro com sinal, um valor maior que 32.767 (o valor máximo permitido ou MAX_INT) definirá o bit `fail` do fluxo e o objeto `cin` se tornará inutilizável. Todas as extrações posteriores resultam em um retorno imediato sem valor armazenado.  
  
## <a name="see-also"></a>Consulte também  
 [Fluxos de entrada](../standard-library/input-streams.md)

