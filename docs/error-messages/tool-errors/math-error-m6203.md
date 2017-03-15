---
title: Erro M6203 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- M6203
dev_langs:
- C++
helpviewer_keywords:
- M6203
ms.assetid: bd7fdd1c-83e4-4d6a-901e-10a0308bf5be
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
ms.openlocfilehash: b58f9eec4974a151ef7e99cd7022bc3b89024997
ms.lasthandoff: 02/25/2017

---
# <a name="math-error-m6203"></a>Erro M6203 (Math)
'function': erro de overflow  
  
 O resultado de determinada função era muito grande para ser representado.  
  
 Esse erro chama o `_matherr` função com o nome da função, os argumentos e o tipo de erro. Você pode reescrever o `_matherr` função para personalizar o tratamento de certos erros de matemática de ponto flutuante de tempo de execução.
