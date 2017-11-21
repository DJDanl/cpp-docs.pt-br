---
title: Erro M6111 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: M6111
dev_langs: C++
helpviewer_keywords: M6111
ms.assetid: c0fc13f8-33c8-4e3f-a440-126cc623441b
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 80bca2ae3462bf67bc017de0f77ce56b4a45994b
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="math-error-m6111"></a>Erro M6111 (Math)
estouro de pilha  
  
 Uma operação de ponto flutuante resultou em um estouro de pilha no coprocessador 287/8087/387 ou o emulador.  
  
 Esse erro geralmente é causado por uma chamada para um `long double` função que não retorna um valor. Por exemplo, a seguir gera este erro quando compilado e executado:  
  
```  
long double ld() {};  
main ()  
{  
  ld();  
}  
```  
  
 Programa será encerrado com código de saída 139.