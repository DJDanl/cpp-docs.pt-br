---
title: C2696 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2696
dev_langs:
- C++
helpviewer_keywords:
- C2696
ms.assetid: 6c6eb7df-1230-4346-9a73-abf14c20785d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 65ccdd6d2c8c34c360811b80d5a93abe76f5ef8e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33235033"
---
# <a name="compiler-error-c2696"></a>C2696 de erro do compilador
Não é possível criar um objeto temporário de um tipo gerenciado 'type'  
  
As referências a `const` em um programa não gerenciado com que o compilador chama o construtor e criar um objeto temporário na pilha. No entanto, uma classe gerenciada nunca pode ser criada na pilha.  
  
C2696 só está acessível usando a opção de compilador obsoleto **/CLR: oldSyntax**.  
