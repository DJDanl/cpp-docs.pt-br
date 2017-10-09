---
title: "Sequências de caracteres | Microsoft Docs"
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
ms.assetid: 1e6961a9-150e-4c13-b427-9af4b6a1fb7a
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: c097f213d790a992d12a8c358282a5340fce52c4
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

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
