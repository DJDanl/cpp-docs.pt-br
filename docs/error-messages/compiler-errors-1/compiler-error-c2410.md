---
title: C2410 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2410
dev_langs:
- C++
helpviewer_keywords:
- C2410
ms.assetid: b69b2de1-56f3-4ebc-8913-04ac57ffe8a1
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3cd5dfa7b33f5af5c57f6479170a7a56df39a0e9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2410"></a>C2410 de erro do compilador
'Identificador': nome de membro ambíguo em 'contexto'  
  
 O identificador é um membro de mais de uma estrutura ou união neste contexto.  
  
 Use um especificador de estrutura ou união no operando que causou o erro. Um especificador de estrutura ou união é um identificador de tipo `struct` ou `union` (um `typedef` nome ou uma variável do mesmo tipo que a estrutura ou união que está sendo referenciado). O especificador deve ser o operando esquerdo do operador de seleção de membro (.) primeiro usar o operando.