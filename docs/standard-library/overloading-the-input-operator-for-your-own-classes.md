---
title: "Sobrecarregando o operador &gt;&gt; para as suas próprias classes | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- operator>>
- operator>>, overloading for your own classes
- operator >>, overloading for your own classes
ms.assetid: 40dab4e0-3f97-4745-9cc8-b86e740fa246
caps.latest.revision: 8
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
ms.openlocfilehash: 4ac48927cc0b68dc958a09ee541c41895f11f86b
ms.lasthandoff: 02/25/2017

---
# <a name="overloading-the-gtgt-operator-for-your-own-classes"></a>Sobrecarregando o operador &gt;&gt; para as suas próprias classes
Fluxos de entrada usam o operador de extração (`>>`) para os tipos padrão. Você pode escrever operadores de extração semelhantes para seus próprios tipos. Seu êxito depende do uso preciso do espaço em branco.  
  
 Veja aqui um exemplo de um operador de extração para a classe `Date` apresentada anteriormente:  
  
```  
istream& operator>> (istream& is, Date& dt)  
{  
    is>> dt.mo>> dt.da>> dt.yr;  
    return is;  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Fluxos de entrada](../standard-library/input-streams.md)


