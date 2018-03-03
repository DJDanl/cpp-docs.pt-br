---
title: C2414 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2414
dev_langs:
- C++
helpviewer_keywords:
- C2414
ms.assetid: bbe94e03-862e-4990-b15e-544ae464727d
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c6238cf17686eb168a2f120c00fc34655715a950
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2414"></a>C2414 de erro do compilador
número de operandos inválido  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  O código de operação não oferece suporte para o número de operandos usados. Verificar um manual de referência de linguagem de assembly para determinar o número correto de operandos.  
  
2.  Um processador mais recente der suporte à instrução com um número diferente de operandos. Ajustar o [/arch (arquitetura mínima de CPU)](../../build/reference/arch-minimum-cpu-architecture.md) opção para usar o processador posterior.