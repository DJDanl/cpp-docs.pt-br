---
title: C3610 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3610
dev_langs:
- C++
helpviewer_keywords:
- C3610
ms.assetid: 9349a348-9d37-4a00-9eab-481039268d31
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 0cacac87535864c6268d0f078566b9ab224e9151
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3610"></a>C3610 de erro do compilador
'valuetype': tipo de valor deve ser 'boxed' antes do método 'method' pode ser chamado  
  
 Por padrão, um tipo de valor não é no heap gerenciado. Antes de chamar métodos das classes de tempo de execução do .NET, como `Object`, você precisa mover o tipo de valor para o heap gerenciado.  
  
 C3610 só está acessível usando a opção de compilador obsoleto **/CLR: oldSyntax**.  

