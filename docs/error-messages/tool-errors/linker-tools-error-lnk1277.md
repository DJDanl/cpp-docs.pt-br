---
title: Ferramentas de vinculador LNK1277 erro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1277
dev_langs:
- C++
helpviewer_keywords:
- LNK1277
ms.assetid: afca3de0-50cc-4140-af7a-13493a170835
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ec8f00793fcda748c60d9d8ea775611e3d025cd9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33298724"
---
# <a name="linker-tools-error-lnk1277"></a>Erro das Ferramentas de Vinculador LNK1277
registro de objeto não encontrado no pgd (nome de arquivo)  
  
 Ao usar [/LTCG:PGOPTIMZE](../../build/reference/ltcg-link-time-code-generation.md), o caminho de um dos arquivos de entrada. lib, def ou. obj for diferente do caminho no qual eles foram encontrados durante a /LTCG:PGINSTRUMENT. Isso pode ser explicado por uma alteração na variável de ambiente LIB após /LTCG:PGINSTRUMENT. O caminho completo para os arquivos de entrada é armazenado no arquivo. PGD.  
  
 /LTCG:PGOPTIMIZE requer que as entradas sejam idênticos para a fase de /LTCG:PGINSTRUMENT.  
  
 Para resolver este aviso, siga um destes procedimentos:  
  
-   Executar /LTCG:PGINSTRUMENT, refazer todas as execuções de teste e executar /LTCG:PGOPTIMIZE.  
  
-   Altere a variável de ambiente LIB para qual ela era quando você executou /LTCG:PGINSTRUMENT.  
  
 Não é recomendável que você trabalhe em torno de LNK1277 usando /LTCG:PGUPDATE.