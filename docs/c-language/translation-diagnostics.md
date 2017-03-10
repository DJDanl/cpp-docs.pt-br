---
title: "Translação: diagnóstico | Microsoft Docs"
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
ms.assetid: 3730ca7c-0147-452d-bd4a-6a1e97e9793e
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
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
ms.openlocfilehash: edad1196350fab29774dbac2b1cce20de0892607
ms.lasthandoff: 02/25/2017

---
# <a name="translation-diagnostics"></a>Translação: diagnóstico
**ANSI 2.1.1.3** Como um diagnóstico é identificado  
  
 O Microsoft C gera mensagens de erro no formato:  
  
```  
  
filename( line-number ) : diagnostic Cnumbermessage  
```  
  
 em que *filename* é o nome do arquivo de origem em que o erro foi encontrado; *line-number* é o número de linha em que o compilador detectou o erro; `diagnostic` é um "erro" ou um "aviso"; `number` é um número exclusivo de quatro dígitos (precedido de **C**, conforme observado na sintaxe) que identifica o erro ou o aviso; `message` é uma mensagem explicativa.  
  
## <a name="see-also"></a>Consulte também  
 [Comportamento definido pela implementação](../c-language/implementation-defined-behavior.md)
