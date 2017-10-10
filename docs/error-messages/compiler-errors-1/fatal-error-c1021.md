---
title: Erro fatal C1021 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C1021
dev_langs:
- C++
helpviewer_keywords:
- C1021
ms.assetid: e23171f4-ca6b-40c0-a913-a2edc6fa3766
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: aa56ca51293bd5afd6baeeabe11b21159ce8b98e
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="fatal-error-c1021"></a>Erro fatal C1021
comando de pré-processador inválido 'string'  
  
 `string`não é válido [diretiva de pré-processador](../../preprocessor/preprocessor-directives.md). Para resolver o erro, use um nome válido de pré-processador para `string`.  
  
 O exemplo a seguir gera C1021:  
  
```  
// C1021.cpp  
#BadPreProcName    // C1021 delete line  
```
