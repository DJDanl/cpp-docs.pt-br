---
title: Erro M6111 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- M6111
dev_langs:
- C++
helpviewer_keywords:
- M6111
ms.assetid: c0fc13f8-33c8-4e3f-a440-126cc623441b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3b03937ed442b169b960d573b44c0eb6ebca9660
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33317990"
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