---
title: "Verificação de erros em tempo de execução | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- c.runtime
dev_langs:
- C++
helpviewer_keywords:
- run-time error checking
- run-time errors, checking
ms.assetid: c965dd01-57ad-4a3c-b1d6-5aa04f920501
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
ms.openlocfilehash: e5ffb6d3321637b662790a32cce65e6908b4778d
ms.lasthandoff: 02/25/2017

---
# <a name="run-time-error-checking"></a>Verificação de erros de tempo de execução
A biblioteca em tempo de execução C contém as funções que oferecem suporte a verificações de erro em tempo de execução (RTC). Verificação de erros em tempo de execução permite que você compilar o programa, de modo que determinados tipos de erros em tempo de execução são relatados. Especifique como os erros são relatados e quais tipos de erros são relatados. Para obter mais informações, consulte [Verificações de erro em tempo de execução](http://msdn.microsoft.com/Library/dc7b2f1e-5ff6-42e0-89b3-dc9dead83ee1).  
  
 Use as funções a seguir para personalizar a forma como o seu programa faz a verificação de erros em tempo de execução.  
  
### <a name="run-time-error-checking-functions"></a>Funções de verificação de erros em tempo de execução  
  
|Função|Uso|Equivalente ao .NET Framework|  
|--------------|---------|-------------------------------|  
|[_RTC_GetErrDesc](../c-runtime-library/reference/rtc-geterrdesc.md)|Retorna uma breve descrição de um tipo de verificação de erro em tempo de execução.||  
|[_RTC_NumErrors](../c-runtime-library/reference/rtc-numerrors.md)|Retorna o número total de erros que podem ser detectados por verificação de erro em tempo de execução.||  
|[_RTC_SetErrorFunc](../c-runtime-library/reference/rtc-seterrorfunc.md)|Designa uma função como o manipulador para verificações de erro em tempo de execução.||  
|[_RTC_SetErrorType](../c-runtime-library/reference/rtc-seterrortype.md)|Associa um erro que é detectado pelas verificações de erro em tempo de execução com um tipo.||  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)   
 [/RTC (verificações de erro em tempo de execução)](../build/reference/rtc-run-time-error-checks.md)   
 [runtime_checks](../preprocessor/runtime-checks.md)   
 [RTC sample](http://msdn.microsoft.com/en-us/b3415b09-f6fd-43dc-8c02-9a910bc2574e)   
 [Rotinas de depuração](../c-runtime-library/debug-routines.md)
