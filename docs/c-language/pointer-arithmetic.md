---
title: "Ponteiro aritmético | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- pointer arithmetic
- arithmetic pointer
ms.assetid: eb924a29-59d3-48a5-9d62-9424790730eb
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 94f18b8a81cfde8d45a4e9e0256dd99a21bdd6a8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="pointer-arithmetic"></a>Ponteiro aritmético
As operações de adição envolvendo um ponteiro e um inteiro fornecem resultados significativos apenas se o operando do ponteiro endereçar um membro de matriz e o valor inteiro produzir um deslocamento dentro dos limites da mesma matriz. Quando o valor inteiro é convertido em um deslocamento de endereço, o compilador pressupõe que somente as posições de memória do mesmo tamanho se encontram entre o endereço original e o endereço mais o deslocamento.  
  
 Esse pressuposto é válido para membros de matriz. Por definição, uma matriz é uma série de valores do mesmo tipo; seus elementos residem em locais de memória contíguos. Porém, o armazenamento para alguns tipos exceto elementos da matriz não têm garantia de preenchimento pelo mesmo tipo de identificadores. Ou seja, os espaços em branco podem aparecer entre as posições de memória, até mesmo posições do mesmo tipo. Consequentemente, os resultados da adição a ou da subtração de endereços de quaisquer valores que não os elementos da matriz serão indefinidos.  
  
 Da mesma forma, quando dois valores de ponteiro são subtraídos, a conversão pressupõe que somente valores do mesmo tipo, sem espaços em branco, se encontram entre os endereços dados pelos operandos.  
  
## <a name="see-also"></a>Consulte também  
 [Operadores aditivos C](../c-language/c-additive-operators.md)