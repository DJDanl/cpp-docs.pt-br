---
title: "Compilador aviso (nível 4) C4985 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- C4985
ms.assetid: 832f001c-afe7-403d-a8b4-02334724c79e
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 08b491e0e2278bf827cd986baa64d133d5ea4305
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4985"></a>Compilador C4985 de aviso (nível 4)
'nome do símbolo': atributos não está presente na declaração anterior.  
  
 As anotações de linguagem (SAL) de anotação do origem código na declaração do método atual ou definição diferem das anotações em uma declaração anterior. As anotações de SAL mesmo devem ser usadas na definição e declarações de um método.  
  
 O SAL fornece um conjunto de anotações que você pode usar para descrever como uma função usa seus parâmetros, as suposições faz sobre eles e as garantias faz em Concluir. As anotações são definidas no arquivo de cabeçalho sal.h.  
  
 Observe que as macros SAL não expandirá a menos que o projeto tem o [/ANALYZE](../../build/reference/analyze-code-analysis.md) sinalizador especificado. Quando você especifica **/ANALYZE**, o compilador pode gerar C4985, mesmo que nenhum aviso ou erro apareceu sem **/ANALYZE**.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Use as anotações de SAL mesmo na definição de um método e todas as suas declarações.  
  
## <a name="see-also"></a>Consulte também  
 [Anotações de SAL](../../c-runtime-library/sal-annotations.md)
