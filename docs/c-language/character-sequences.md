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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 09134a17ad8711169a3afc30490c188af47a3f42
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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