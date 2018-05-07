---
title: Compilador (nível 1) de aviso C4678 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4678
dev_langs:
- C++
helpviewer_keywords:
- C4678
ms.assetid: 0c588f34-595d-4e5c-9470-8723fca2cc06
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 73871d69198752e12a629d441982c2da47146517
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4678"></a>Compilador C4678 de aviso (nível 1)
classe base 'base_type' é menos acessível que 'derived_type'  
  
Um tipo público deriva de um tipo particular. Se o tipo de público é instanciado em um assembly referenciado, os membros do tipo base particular não estarão acessíveis.  
  
C4678 só está acessível usando a opção de compilador obsoleto **/CLR: oldSyntax**. É um erro ao usar **/clr**, para ter uma classe base que é menos acessível que a classe derivada.  
