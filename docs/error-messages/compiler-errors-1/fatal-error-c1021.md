---
title: Erro fatal C1021 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1021
dev_langs:
- C++
helpviewer_keywords:
- C1021
ms.assetid: e23171f4-ca6b-40c0-a913-a2edc6fa3766
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 06ec8f9aeca3b88b1c14c8dddfc625aae0b185d0
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33198801"
---
# <a name="fatal-error-c1021"></a>Erro fatal C1021
comando de pré-processador inválido 'string'  
  
 `string` não é válido [diretiva de pré-processador](../../preprocessor/preprocessor-directives.md). Para resolver o erro, use um nome válido de pré-processador para `string`.  
  
 O exemplo a seguir gera C1021:  
  
```  
// C1021.cpp  
#BadPreProcName    // C1021 delete line  
```