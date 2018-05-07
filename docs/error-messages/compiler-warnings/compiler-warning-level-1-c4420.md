---
title: Compilador (nível 1) de aviso C4420 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4420
dev_langs:
- C++
helpviewer_keywords:
- C4420
ms.assetid: 44a37754-7ddd-4764-a5f7-d33e05c20091
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 98336a30e7174b62df48e93a04ba9ee7ddcc919a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4420"></a>Compilador C4420 de aviso (nível 1)
'operator': operador não está disponível, usando 'operator'; verificação de tempo de execução pode ser comprometida  
  
 Esse aviso é gerado quando você usar o [/RTCv](../../build/reference/rtc-run-time-error-checks.md) (vector verificando novo/excluir) e quando nenhuma forma de vetor foi encontrada. Nesse caso, o formulário de vetor não é usado.  
  
 Para /RTCv funcione corretamente, o compilador deve sempre chamar o formulário de vetor de [novo](../../cpp/new-operator-cpp.md)/[excluir](../../cpp/delete-operator-cpp.md) se a sintaxe de vetor foi usada.