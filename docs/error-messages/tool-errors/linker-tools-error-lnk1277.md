---
title: Ferramentas de vinculador LNK1277 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1277
dev_langs:
- C++
helpviewer_keywords:
- LNK1277
ms.assetid: afca3de0-50cc-4140-af7a-13493a170835
caps.latest.revision: 7
author: corob-msft
ms.author: corob
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: c10ea2fe5a18e9eb27da68003c73c484fd14e921
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk1277"></a>Erro das Ferramentas de Vinculador LNK1277
registro de objeto não encontrado no pgd (nome do arquivo)  
  
 Ao usar [/LTCG:PGOPTIMZE](../../build/reference/ltcg-link-time-code-generation.md), o caminho de um dos arquivos de entrada. obj, def ou. lib é diferente do caminho no qual eles foram encontrados durante a /LTCG:PGINSTRUMENT. Isso pode ser explicado por uma alteração na variável de ambiente LIB após /LTCG:PGINSTRUMENT. O caminho completo para os arquivos de entrada é armazenado no arquivo. PGD.  
  
 /LTCG:PGOPTIMIZE requer que as entradas sejam idênticos para a fase de /LTCG:PGINSTRUMENT.  
  
 Para resolver esse aviso, siga um destes procedimentos:  
  
-   Executar /LTCG:PGINSTRUMENT, refazer todas as execuções de teste e executar /LTCG:PGOPTIMIZE.  
  
-   Altere a variável de ambiente LIB ao que era quando você executou /LTCG:PGINSTRUMENT.  
  
 Não é recomendável que você contornar LNK1277 usando /LTCG:PGUPDATE.
