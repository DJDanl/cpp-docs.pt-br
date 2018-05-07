---
title: C3398 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3398
dev_langs:
- C++
helpviewer_keywords:
- C3398
ms.assetid: 26f8c8a4-526f-415b-8047-155c5cd4f180
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b870479977bfb49ff39d5a15fe19fc700ed66b8e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3398"></a>C3398 de erro do compilador
'operator': não é possível converter de 'function_signature' em 'function_pointer'. Expressão fonte deve ser um símbolo de função  
  
 Quando o [clrcall](../../cpp/clrcall.md) convenção de chamada não for especificada durante a compilação com **/clr**, o compilador gera dois pontos de entrada (endereços) para cada função, um ponto de entrada nativo e um ponto de entrada gerenciado.  
  
 Por padrão, o compilador retorna o ponto de entrada nativo, mas há alguns casos em que o ponto de entrada gerenciado é desejado (por exemplo ao atribuir o endereço para um `__clrcall` ponteiro de função). Para o compilador confiável, escolha o ponto de entrada gerenciado em uma atribuição, o lado direito deve ser um símbolo de função.