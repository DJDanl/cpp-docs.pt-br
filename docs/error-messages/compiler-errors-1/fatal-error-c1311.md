---
title: Erro fatal C1311 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1311
dev_langs:
- C++
helpviewer_keywords:
- C1311
ms.assetid: 6590a06c-ce9d-4f17-8f62-c809343143b8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 53b3759a5fec4b072f9a9b300670d61cb0d101c5
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33226665"
---
# <a name="fatal-error-c1311"></a>Erro fatal C1311
Formato COFF não pode inicializar estaticamente 'var' com número bytes de um endereço  
  
 Um endereço cujo valor não é conhecido em tempo de compilação não pode ser atribuído estaticamente a uma variável cujo tipo tem o armazenamento de menos de quatro bytes.  
  
 Esse erro pode ocorrer em código que seja C++ válido.  
  
 O exemplo a seguir mostra uma condição que pode causar C1311.  
  
```  
char c = (char)"Hello, world";   // C1311  
char *d = (char*)"Hello, world";   // OK  
```