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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e50154d88a5019cdc181c4921c09cbd222d8b530
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2097"></a>C2097 de erro do compilador
inicialização ilegal  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  Inicialização de uma variável usando um valor constante.  
  
2.  Inicialização de um endereço curto com um endereço de tempo.  
  
3.  Inicialização de uma estrutura local, união ou de matriz com uma expressão não constante ao compilar com **/Za**.  
  
4.  Inicialização com uma expressão que contém um operador de vírgula.  
  
5.  Inicialização com uma expressão que não é constante nem simbólico.