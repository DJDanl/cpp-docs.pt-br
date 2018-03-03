---
title: "Compilador (nível 1) de aviso C4420 | Microsoft Docs"
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9a57803cb584f5ee54ad5533366e6aadc85d1acf
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4420"></a>Compilador C4420 de aviso (nível 1)
'operator': operador não está disponível, usando 'operator'; verificação de tempo de execução pode ser comprometida  
  
 Esse aviso é gerado quando você usar o [/RTCv](../../build/reference/rtc-run-time-error-checks.md) (vector verificando novo/excluir) e quando nenhuma forma de vetor foi encontrada. Nesse caso, o formulário de vetor não é usado.  
  
 Para /RTCv funcione corretamente, o compilador deve sempre chamar o formulário de vetor de [novo](../../cpp/new-operator-cpp.md)/[excluir](../../cpp/delete-operator-cpp.md) se a sintaxe de vetor foi usada.