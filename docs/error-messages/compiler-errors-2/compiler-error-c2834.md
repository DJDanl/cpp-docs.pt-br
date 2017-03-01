---
title: C2834 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2834
dev_langs:
- C++
helpviewer_keywords:
- C2834
ms.assetid: 28f9f6eb-ab2a-4e64-aaaa-9d14f955de41
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
ms.openlocfilehash: 418f320e25dd4e681acb3c76557b89a921877d02
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2834"></a>C2834 de erro do compilador
'operador' deve ser qualificado globalmente  
  
 O `new` e `delete` operadores estão vinculados à classe onde eles residem. Resolução de escopo não pode ser usada para selecionar uma versão do `new` ou `delete` de uma classe diferente. Para implementar várias formas dos `new` ou `delete` operador, crie uma versão do operador com parâmetros formais extra.
