---
title: "Tamanhos de tipo e variável em Assembly embutido | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- length
- Type
dev_langs:
- C++
helpviewer_keywords:
- variables, length
- size, getting in inline assembly
- size
- LENGTH operator
- TYPE operator
- SIZE operator
- inline assembly, operators
- variables, type
- variables, size
ms.assetid: b62c2f2b-a7ad-4145-bae4-d890db86d348
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 38cbbd292ea662a725a8356b53fd0c1686e698e1
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="type-and-variable-sizes-in-inline-assembly"></a>Tamanhos de tipo e variável em assembly embutido
**Seção específica da Microsoft**  
  
 O **comprimento**, **tamanho**, e **tipo** operadores têm um significado limitado em assembly embutido. Não pode ser usados em todos os com o `DUP` operador (porque você não pode definir dados com diretivas MASM ou operadores). Mas você pode usá-los para encontrar o tamanho de tipos ou variáveis de C ou C++:  
  
-   O **comprimento** operador pode retornar o número de elementos em uma matriz. Retorna o valor 1 para variáveis de matriz não.  
  
-   O **tamanho** operador pode retornar o tamanho de uma variável C ou C++. Tamanho da variável é o produto de sua **comprimento** e **tipo**.  
  
-   O **tipo** operador pode retornar o tamanho de um tipo de C ou C++ ou uma variável. Se a variável for uma matriz, **tipo** retorna o tamanho de um único elemento da matriz.  
  
 Por exemplo, se seu programa tem um elemento de 8 `int` matriz,  
  
```  
int arr[8];  
```  
  
 as seguintes expressões C e assembly produzem o tamanho de `arr` e seus elementos.  
  
|__asm|C|Tamanho|  
|-------------|-------|----------|  
|**COMPRIMENTO** arr|`sizeof`(arr) /`sizeof`(arr[0])|8|  
|**TAMANHO** arr|`sizeof`(arr)|32|  
|**TIPO** arr|`sizeof`(arr[0])|4|  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)