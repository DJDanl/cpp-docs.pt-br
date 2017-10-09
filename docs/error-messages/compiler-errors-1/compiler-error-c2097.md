---
title: C2097 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2097
dev_langs:
- C++
helpviewer_keywords:
- C2097
ms.assetid: 7e5b2fd4-f61c-4b8a-b265-93e987a04bd3
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: d6955a610e3109c3b16edf96913be4503ee4c647
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2097"></a>C2097 de erro do compilador
inicialização ilegal  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  Inicialização de uma variável usando um valor constante.  
  
2.  Inicialização de um endereço curto com um endereço de tempo.  
  
3.  Inicialização de uma estrutura local, união ou de matriz com uma expressão não constante ao compilar com **/Za**.  
  
4.  Inicialização com uma expressão que contém um operador de vírgula.  
  
5.  Inicialização com uma expressão que não é constante nem simbólico.
