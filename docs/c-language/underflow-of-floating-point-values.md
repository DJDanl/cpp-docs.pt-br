---
title: Estouro negativo de valores de ponto flutuante | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 78af8016-643c-47db-b4f1-7f06cb4b243e
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ecea42172ed285f24a22cba004fb156784483643
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="underflow-of-floating-point-values"></a>Estouro negativo de valores de ponto flutuante
**ANSI 4.5.1** Se as funções matemáticas definem a expressão de inteiro `errno` como o valor da macro `ERANGE` em erros de alcance de estouro negativo  
  
 Um estouro negativo de ponto flutuante não define a expressão `errno` como `ERANGE`. Quando um valor se aproxima de zero e acaba sofrendo um estouro negativo, o valor é definido como zero.  
  
## <a name="see-also"></a>Consulte também  
 [Funções de biblioteca](../c-language/library-functions.md)