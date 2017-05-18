---
title: "Compilador aviso (nível 1) C4420 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4420
dev_langs:
- C++
helpviewer_keywords:
- C4420
ms.assetid: 44a37754-7ddd-4764-a5f7-d33e05c20091
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 479947ac089d5fc6b743c961ffab8c770d132f3e
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4420"></a>Compilador C4420 de aviso (nível 1)
'operator': operador não está disponível, usando 'operator'; verificação de tempo de execução pode ser comprometida  
  
 Esse aviso é gerado quando você usar o [/RTCv](../../build/reference/rtc-run-time-error-checks.md) (verificação novo/exclusão de vetor) e quando nenhuma forma vetorial for encontrada. Nesse caso, a forma de vetor não é usada.  
  
 Para /RTCv funcione corretamente, o compilador deve sempre chamar o formulário de vetor de [novo](../../cpp/new-operator-cpp.md)/[excluir](../../cpp/delete-operator-cpp.md) se a sintaxe do vetor foi usada.
