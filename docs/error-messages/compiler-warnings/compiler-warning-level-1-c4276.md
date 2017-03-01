---
title: "Compilador aviso (nível 1) C4276 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4276
dev_langs:
- C++
helpviewer_keywords:
- C4276
ms.assetid: 9d738c2d-29e5-408a-b9ff-be1a850b2238
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
ms.openlocfilehash: 88871206840e06fb06b90ed669f5684647bd5ce5
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4276"></a>Compilador C4276 de aviso (nível 1)
'function': nenhum protótipo fornecido. considerado sem parâmetros  
  
 Quando você toma o endereço de uma função com o [stdcall](../../cpp/stdcall.md) convenção de chamada, você deve fornecer um protótipo para que o compilador possa criar nome decorado da função. Como *função* não tem nenhum protótipo, o compilador, ao criar o nome decorado, assume a função não tem parâmetros.
