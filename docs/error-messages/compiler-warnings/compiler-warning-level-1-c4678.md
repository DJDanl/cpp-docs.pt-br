---
title: "Compilador (nível 1) de aviso C4678 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4678
dev_langs:
- C++
helpviewer_keywords:
- C4678
ms.assetid: 0c588f34-595d-4e5c-9470-8723fca2cc06
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7648101a0862aa2006feff73a5ebe32bd0f424a1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4678"></a>Compilador C4678 de aviso (nível 1)
classe base 'base_type' é menos acessível que 'derived_type'  
  
Um tipo público deriva de um tipo particular. Se o tipo de público é instanciado em um assembly referenciado, os membros do tipo base particular não estarão acessíveis.  
  
C4678 só está acessível usando a opção de compilador obsoleto **/CLR: oldSyntax**. É um erro ao usar **/clr**, para ter uma classe base que é menos acessível que a classe derivada.  
