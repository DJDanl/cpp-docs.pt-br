---
title: "Sequências de caracteres | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 1e6961a9-150e-4c13-b427-9af4b6a1fb7a
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 3919e560a8a99a18e11b73248b50e5cc79281b23
ms.lasthandoff: 02/25/2017

---
# <a name="character-sequences"></a>Sequências de caracteres
**ANSI 3.8.2** O mapeamento de sequências de caracteres do arquivo de origem  
  
 As instruções do pré-processador usam o mesmo conjunto de caracteres das instruções de arquivo de origem, com exceção das sequências de escape, que não têm suporte.  
  
 Assim, para especificar um caminho para um arquivo de inclusão, use somente uma barra invertida:  
  
```  
#include "path1\path2\myfile"  
```  
  
 No código-fonte, duas barras invertidas são necessárias:  
  
```  
fil = fopen( "path1\\path2\\myfile", "rt" );  
```  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas de pré-processamento](../c-language/preprocessing-directives.md)
