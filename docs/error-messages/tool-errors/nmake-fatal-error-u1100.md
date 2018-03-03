---
title: NMAKE Erro Fatal U1100 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- U1100
dev_langs:
- C++
helpviewer_keywords:
- U1100
ms.assetid: c71910a7-c581-4d9c-a38c-d2d557d56289
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e7c4a42e47a29775bb53fdc0fd2f25c7bdc252f0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="nmake-fatal-error-u1100"></a>Erro fatal U1100 (NMAKE)
macro 'nomedamacro' é inválida no contexto da regra de lote 'rule'  
  
 NMAKE gera este erro quando o bloco de comando de uma regra de modo de lote direta ou indiretamente referencia uma macro de arquivo especial que não é $<.  
  
 $< é o único permitido macro para regras de modo de lote.