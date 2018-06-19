---
title: Sinalizador de direção | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- c.flags
dev_langs:
- C++
helpviewer_keywords:
- direction flag
ms.assetid: 0836b4af-dbbb-4ab8-a4b2-156f2e2099e2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3737304d2443b4f67f00a03e23a0529ad5bcbfe3
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32387844"
---
# <a name="direction-flag"></a>Sinalizador de direção
O sinalizador de direção é um sinalizador de CPU específico aos processadores Intel 80x86. Ele se aplica a todas as instruções de assembly que usam o prefixo REP (repetição), como MOVS, MOVSD, MOVSW e outros. Endereços fornecidos para instruções aplicáveis são aumentados se o sinalizador de direção estiver desmarcado.  
  
 As rotinas de tempo de execução C pressupõem que o sinalizador de direção está desmarcado. Se você estiver usando outras funções com as funções de tempo de execução C, você deve garantir que as outras funções não mexam no sinalizador de direção ou restaurem-no à sua condição original. Esperar o sinalizador de direção clara na entrada torna o código de tempo de execução mais rápido e eficiente.  
  
 As funções de biblioteca em tempo de execução C, como as rotinas de manipulação de cadeia de caracteres e manipulação de buffer, esperam que o sinalizador de direção esteja desmarcado.  
  
## <a name="see-also"></a>Consulte também  
 [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)