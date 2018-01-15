---
title: SUPONHA QUE | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: ASSUME
dev_langs: C++
helpviewer_keywords: ASSUME directive
ms.assetid: cd162070-aee9-4c65-babc-005c6cc73d7c
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: bf3e2bc4a29f1f6f2919e19085f73cde566aa5d0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="assume"></a>ASSUME
Habilita a verificação de erros de valores do registro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
ASSUME segregister:name [[, segregister:name]]...  
ASSUME dataregister:type [[, dataregister:type]]...  
ASSUME register:ERROR [[, register:ERROR]]...  
ASSUME [[register:]] NOTHING [[, register:NOTHING]]...  
```  
  
## <a name="remarks"></a>Comentários  
 Após um `ASSUME` é entrem em vigor, o assembler observa as alterações dos valores dos registros determinados. **Erro** gera um erro se o registro for usado. **NADA** remove registrar a verificação de erros. Você pode combinar tipos diferentes de suposições em uma instrução.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)