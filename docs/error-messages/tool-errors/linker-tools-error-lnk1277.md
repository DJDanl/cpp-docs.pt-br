---
title: Ferramentas de vinculador LNK1277 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1277
dev_langs:
- C++
helpviewer_keywords:
- LNK1277
ms.assetid: afca3de0-50cc-4140-af7a-13493a170835
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3606207afc197dc26ac0540d476b74f52c0dc0a9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-error-lnk1277"></a>Erro das Ferramentas de Vinculador LNK1277
registro de objeto não encontrado no pgd (nome de arquivo)  
  
 Ao usar [/LTCG:PGOPTIMZE](../../build/reference/ltcg-link-time-code-generation.md), o caminho de um dos arquivos de entrada. lib, def ou. obj for diferente do caminho no qual eles foram encontrados durante a /LTCG:PGINSTRUMENT. Isso pode ser explicado por uma alteração na variável de ambiente LIB após /LTCG:PGINSTRUMENT. O caminho completo para os arquivos de entrada é armazenado no arquivo. PGD.  
  
 /LTCG:PGOPTIMIZE requer que as entradas sejam idênticos para a fase de /LTCG:PGINSTRUMENT.  
  
 Para resolver este aviso, siga um destes procedimentos:  
  
-   Executar /LTCG:PGINSTRUMENT, refazer todas as execuções de teste e executar /LTCG:PGOPTIMIZE.  
  
-   Altere a variável de ambiente LIB para qual ela era quando você executou /LTCG:PGINSTRUMENT.  
  
 Não é recomendável que você trabalhe em torno de LNK1277 usando /LTCG:PGUPDATE.