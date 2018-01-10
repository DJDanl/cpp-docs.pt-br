---
title: "Sinalizador de direção | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: c.flags
dev_langs: C++
helpviewer_keywords: direction flag
ms.assetid: 0836b4af-dbbb-4ab8-a4b2-156f2e2099e2
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e0a43bac113c013ecb93f5b6e84aa2075a052f8c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="direction-flag"></a>Sinalizador de direção
O sinalizador de direção é um sinalizador de CPU específico aos processadores Intel 80x86. Ele se aplica a todas as instruções de assembly que usam o prefixo REP (repetição), como MOVS, MOVSD, MOVSW e outros. Endereços fornecidos para instruções aplicáveis são aumentados se o sinalizador de direção estiver desmarcado.  
  
 As rotinas de tempo de execução C pressupõem que o sinalizador de direção está desmarcado. Se você estiver usando outras funções com as funções de tempo de execução C, você deve garantir que as outras funções não mexam no sinalizador de direção ou restaurem-no à sua condição original. Esperar o sinalizador de direção clara na entrada torna o código de tempo de execução mais rápido e eficiente.  
  
 As funções de biblioteca em tempo de execução C, como as rotinas de manipulação de cadeia de caracteres e manipulação de buffer, esperam que o sinalizador de direção esteja desmarcado.  
  
## <a name="see-also"></a>Consulte também  
 [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)