---
title: C3166 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3166
dev_langs:
- C++
helpviewer_keywords:
- C3166
ms.assetid: ec3e330d-c15d-4158-8268-09101486c566
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d08206d9dace801ec18056e749d8bd24ab3190a1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3166"></a>C3166 de erro do compilador
'ponteiro': não é possível declarar um ponteiro para um ponteiro interior GC como um membro de 'type'  
  
O compilador encontrada uma declaração de ponteiro inválido (um `__nogc` ponteiro para um `__gc` ponteiro.). 
  
C3166 só está acessível usando a opção de compilador obsoleto **/CLR: oldSyntax**.  
