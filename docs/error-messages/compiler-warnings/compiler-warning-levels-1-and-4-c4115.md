---
title: "Compilador (níveis 1 e 4) de aviso C4115 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C4115
dev_langs: C++
helpviewer_keywords: C4115
ms.assetid: f3f94e72-fc49-4d09-b3e7-23d68e61152f
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ec1c4377c2b7670b9d934d13d09bc5336fe5f30b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-levels-1-and-4-c4115"></a>Compilador C4115 de aviso (níveis 1 e 4)
'type': definição de tipo entre parênteses nomeado  
  
 O símbolo em questão é usado para definir uma estrutura, união ou tipo enumerado dentro de uma expressão entre parênteses. A definição do escopo pode ser inesperado.  
  
 Em uma chamada de função C, a definição tem escopo global. Em uma chamada de C++, a definição tem o mesmo escopo de função que está sendo chamado.  
  
 Esse aviso também pode ser causado por declaradores dentro dos parênteses (como protótipos) que não são expressões entre parênteses.  
  
 Este é um aviso de nível 1 com programas de C++ e C compilado no compatibilidade ANSI (/Za). Caso contrário, é o nível 3.