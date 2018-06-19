---
title: C2410 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2410
dev_langs:
- C++
helpviewer_keywords:
- C2410
ms.assetid: b69b2de1-56f3-4ebc-8913-04ac57ffe8a1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f9c2a2df0941130c4f2416806a05ce0378373eb4
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33226424"
---
# <a name="compiler-error-c2410"></a>C2410 de erro do compilador
'Identificador': nome de membro ambíguo em 'contexto'  
  
 O identificador é um membro de mais de uma estrutura ou união neste contexto.  
  
 Use um especificador de estrutura ou união no operando que causou o erro. Um especificador de estrutura ou união é um identificador de tipo `struct` ou `union` (um `typedef` nome ou uma variável do mesmo tipo que a estrutura ou união que está sendo referenciado). O especificador deve ser o operando esquerdo do operador de seleção de membro (.) primeiro usar o operando.