---
title: C3610 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3610
dev_langs:
- C++
helpviewer_keywords:
- C3610
ms.assetid: 9349a348-9d37-4a00-9eab-481039268d31
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f58d66e9d3dacfa2c0b38eb84fe51e0813a892d3
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3610"></a>C3610 de erro do compilador
'valuetype': tipo de valor deve ser 'boxed' antes do método 'method' pode ser chamado  
  
 Por padrão, um tipo de valor não é no heap gerenciado. Antes de chamar métodos das classes de tempo de execução do .NET, como `Object`, você precisa mover o tipo de valor para o heap gerenciado.  
  
 C3610 só está acessível usando a opção de compilador obsoleto **/CLR: oldSyntax**.  
