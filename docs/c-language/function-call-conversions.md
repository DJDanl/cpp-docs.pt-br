---
title: "Conversões de função de chamada | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- function calls, converting
- function calls, argument type conversions
- functions [C], argument conversions
ms.assetid: 04ea0f81-509a-4913-8b12-0937a81babcf
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 9f45a7b3b4aecfd25d1973e1e95ec787e958025e
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="function-call-conversions"></a>Conversões de função de chamada
O tipo de conversão executado nos argumentos em uma chamada de função depende da presença de um protótipo de função (declaração de encaminhamento) com tipos de argumentos declarados para a função chamada.  
  
 Se um protótipo da função estiver presente e incluir tipos de argumentos declarados, o compilador fará a verificação de tipo (consulte [Funções](../c-language/functions-c.md)).  
  
 Se nenhum protótipo da função estiver presente, somente as conversões aritméticas comuns serão executadas nos argumentos na chamada da função. Essas conversões são executadas independentemente em cada argumento na chamada. Isso significa que um valor **float** será convertido em **double**; um valor `char` ou **short** será convertido em `int`; e `unsigned char` ou **unsigned short** será convertido em `unsigned int`.  
  
## <a name="see-also"></a>Consulte também  
 [Conversões de Tipo](../c-language/type-conversions-c.md)