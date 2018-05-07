---
title: Compilador (níveis 1 e 4) de aviso C4115 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4115
dev_langs:
- C++
helpviewer_keywords:
- C4115
ms.assetid: f3f94e72-fc49-4d09-b3e7-23d68e61152f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2edfdc84ee38e20f7193d720eab0ccb58d30790b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-levels-1-and-4-c4115"></a>Compilador C4115 de aviso (níveis 1 e 4)
'type': definição de tipo entre parênteses nomeado  
  
 O símbolo em questão é usado para definir uma estrutura, união ou tipo enumerado dentro de uma expressão entre parênteses. A definição do escopo pode ser inesperado.  
  
 Em uma chamada de função C, a definição tem escopo global. Em uma chamada de C++, a definição tem o mesmo escopo de função que está sendo chamado.  
  
 Esse aviso também pode ser causado por declaradores dentro dos parênteses (como protótipos) que não são expressões entre parênteses.  
  
 Este é um aviso de nível 1 com programas de C++ e C compilado no compatibilidade ANSI (/Za). Caso contrário, é o nível 3.