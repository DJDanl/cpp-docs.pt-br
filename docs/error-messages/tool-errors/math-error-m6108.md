---
title: Erro M6108 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- M6108
dev_langs:
- C++
helpviewer_keywords:
- M6108
ms.assetid: 054893b4-49bc-45d9-882f-7cb50ba387c0
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 4c1378cbef93581262b56cb91cb321d7714fb635
ms.lasthandoff: 02/25/2017

---
# <a name="math-error-m6108"></a>Erro M6108 (Math)
raiz quadrada  
  
 O operando em uma operação de raiz quadrada estava negativo.  
  
 Programa é encerrado com código de saída 136.  
  
> [!NOTE]
>  O `sqrt` função na biblioteca de tempo de execução C e a função intrínseca FORTRAN **SQRT** gera esse erro. O C `sqrt` função verifica o argumento antes de executar a operação e retorna um valor de erro se o operando for negativo. O padrão FORTRAN **SQRT** função gera o erro de domínio [M6201](../../error-messages/tool-errors/math-error-m6201.md) em vez desse erro.
