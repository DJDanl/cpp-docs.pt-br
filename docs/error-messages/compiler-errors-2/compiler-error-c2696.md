---
title: C2696 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2696
dev_langs:
- C++
helpviewer_keywords:
- C2696
ms.assetid: 6c6eb7df-1230-4346-9a73-abf14c20785d
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 70ccaf34a0191f0bd69c95d2cb110f6e6542a6d1
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2696"></a>C2696 de erro do compilador
Não é possível criar um objeto temporário de um tipo gerenciado 'type'  
  
As referências a `const` em um programa não gerenciado com que o compilador chama o construtor e criar um objeto temporário na pilha. No entanto, uma classe gerenciada nunca pode ser criada na pilha.  
  
C2696 só está acessível usando a opção de compilador obsoleto **/CLR: oldSyntax**.  

