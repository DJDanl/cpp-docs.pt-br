---
title: C3554 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3554
dev_langs:
- C++
helpviewer_keywords:
- C3554
ms.assetid: aede18d5-fefc-4da9-9b69-adfe90bfa742
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4fb374e028097157ae72b621593a899af9fe2f91
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33255447"
---
# <a name="compiler-error-c3554"></a>C3554 de erro do compilador
'decltype' não pode ser combinado com nenhum outro especificador de tipo  
  
 Você não pode qualificar o `decltype()` palavra-chave com qualquer especificador de tipo. Por exemplo, o fragmento de código a seguir gera erro C3554.  
  
```  
int x;  
unsigned decltype(x); // C3554  
```