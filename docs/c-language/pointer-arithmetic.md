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
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: 6d74dfdf716065384a1c0a65a6a2bf0e5437dc1e
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="pointer-arithmetic"></a>Ponteiro aritmético
As operações de adição envolvendo um ponteiro e um inteiro fornecem resultados significativos apenas se o operando do ponteiro endereçar um membro de matriz e o valor inteiro produzir um deslocamento dentro dos limites da mesma matriz. Quando o valor inteiro é convertido em um deslocamento de endereço, o compilador pressupõe que somente as posições de memória do mesmo tamanho se encontram entre o endereço original e o endereço mais o deslocamento.  
  
 Esse pressuposto é válido para membros de matriz. Por definição, uma matriz é uma série de valores do mesmo tipo; seus elementos residem em locais de memória contíguos. Porém, o armazenamento para alguns tipos exceto elementos da matriz não têm garantia de preenchimento pelo mesmo tipo de identificadores. Ou seja, os espaços em branco podem aparecer entre as posições de memória, até mesmo posições do mesmo tipo. Consequentemente, os resultados da adição a ou da subtração de endereços de quaisquer valores que não os elementos da matriz serão indefinidos.  
  
 Da mesma forma, quando dois valores de ponteiro são subtraídos, a conversão pressupõe que somente valores do mesmo tipo, sem espaços em branco, se encontram entre os endereços dados pelos operandos.  
  
## <a name="see-also"></a>Consulte também  
 [Operadores aditivos C](../c-language/c-additive-operators.md)
