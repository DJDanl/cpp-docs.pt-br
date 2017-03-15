---
title: Erro M6111 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- M6111
dev_langs:
- C++
helpviewer_keywords:
- M6111
ms.assetid: c0fc13f8-33c8-4e3f-a440-126cc623441b
caps.latest.revision: 6
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
ms.openlocfilehash: 906072bdd8fe674d69604ddc6f8ddd66ebad712d
ms.lasthandoff: 02/25/2017

---
# <a name="math-error-m6111"></a>Erro M6111 (Math)
estouro de pilha  
  
 Uma operação de ponto flutuante resultou em um estouro de pilha em coprocessador 8087/287/387 ou no emulador.  
  
 Esse erro geralmente é causado por uma chamada para um `long double` função que não retorna um valor. Por exemplo, a seguir gera este erro quando compilado e executado:  
  
```  
long double ld() {};  
main ()  
{  
  ld();  
}  
```  
  
 Programa é encerrado com código de saída 139.
