---
title: C3552 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3552
dev_langs:
- C++
helpviewer_keywords:
- C3552
ms.assetid: 83401524-1bf1-44c0-8aca-a6eb35c4224c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a5f1453a6175019ad7c90471330d11c77da26134
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3552"></a>C3552 de erro do compilador
'typename': um tipo de retorno especificado tardia não pode conter 'auto'  
  
 Se você usar o `auto` palavra-chave como um espaço reservado para o tipo de retorno de uma função, você deve fornecer um tipo de retorno tardia especificado. No entanto, você não pode usar outro `auto` palavra-chave para especificar o tipo de retorno de tardia especificado. Por exemplo, o fragmento de código a seguir gera erro C3552.  
  
 `auto myFunction->auto; // C3552`