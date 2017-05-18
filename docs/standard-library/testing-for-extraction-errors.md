---
title: "Testando erros de extração | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- extraction errors
ms.assetid: 6a681028-adba-4557-8f7b-f137932905f8
caps.latest.revision: 9
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 05e2c94cc23a7ad75edcd92721de538ac008d65b
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="testing-for-extraction-errors"></a>Testando erros de extração
Gere as funções de processamento de erro, abordadas em [Funções de processamento de erro](../standard-library/output-file-stream-member-functions.md), aplicadas a fluxos de entrada. É importante testar erros durante a extração. Considere esta instrução:  
  
```  
cin>> n;  
```  
  
 Se `n` for um inteiro com sinal, um valor maior que 32.767 (o valor máximo permitido ou MAX_INT) definirá o bit `fail` do fluxo e o objeto `cin` se tornará inutilizável. Todas as extrações posteriores resultam em um retorno imediato sem valor armazenado.  
  
## <a name="see-also"></a>Consulte também  
 [Fluxos de entrada](../standard-library/input-streams.md)


