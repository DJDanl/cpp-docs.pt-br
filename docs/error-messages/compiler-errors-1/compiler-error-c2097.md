---
title: C2097 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2097
dev_langs:
- C++
helpviewer_keywords:
- C2097
ms.assetid: 7e5b2fd4-f61c-4b8a-b265-93e987a04bd3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fa4b867c7f043d796f208fdc7100509893147daf
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33168354"
---
# <a name="compiler-error-c2097"></a>C2097 de erro do compilador
inicialização ilegal  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  Inicialização de uma variável usando um valor constante.  
  
2.  Inicialização de um endereço curto com um endereço de tempo.  
  
3.  Inicialização de uma estrutura local, união ou de matriz com uma expressão não constante ao compilar com **/Za**.  
  
4.  Inicialização com uma expressão que contém um operador de vírgula.  
  
5.  Inicialização com uma expressão que não é constante nem simbólico.