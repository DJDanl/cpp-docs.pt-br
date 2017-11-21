---
title: "-Zc: trigraphs (substituição de Trígrafos) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /Zc
dev_langs: C++
helpviewer_keywords:
- -Zc compiler options (C++)
- /Zc compiler options (C++)
- Conformance compiler options
- Zc compiler options (C++)
ms.assetid: e3d6058f-400d-4966-a3aa-800cfdf69cbf
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 56068f6cb630ac12b9c8417940411616cec65c69
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="zctrigraphs-trigraphs-substitution"></a>/Zc:trigraphs (substituição de trígrafos)
Quando **/ZC: trigraphs** for especificado, o compilador substitui uma sequência de caracteres trigraph usando um caractere de pontuação correspondente. Para desativar a substituição de trigraph, especifique **/Zc:trigraphs-**. Por padrão, **/ZC: trigraphs** está desativado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Zc:trigraphs[-]  
```  
  
## <a name="remarks"></a>Comentários  
 Um trígrafo consiste em dois pontos de interrogação consecutivos ("??") seguidos por um terceiro caractere exclusivo. Por exemplo, o compilador substitui o "? = "trigraph usando o caractere '#'. Use trígrafos em arquivos de origem de C que usam um conjunto de caracteres que não contém representações gráficas convenientes para alguns caracteres de pontuação.  
  
 Para obter uma lista de trígrafos C/C++ e um exemplo que mostra como usar trígrafos, consulte [Trígrafos](../../c-language/trigraphs.md).  
  
## <a name="see-also"></a>Consulte também  
 [/ZC (conformidade)](../../build/reference/zc-conformance.md)   
 [Trígrafos](../../c-language/trigraphs.md)