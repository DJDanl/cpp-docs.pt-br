---
title: -PDBPATH | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /pdbpath
dev_langs: C++
helpviewer_keywords:
- .pdb files, path
- -PDBPATH dumpbin option
- /PDBPATH dumpbin option
- PDBPATH dumpbin option
- PDB files, path
ms.assetid: ccf67dcd-0b23-4250-ad47-06c48acbe82b
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 0ccbcedbf9cdd376fa7d9bced5c9d49542cee9f6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="pdbpath"></a>/PDBPATH
```  
/PDBPATH[:VERBOSE] filename  
```  
  
## <a name="remarks"></a>Comentários  
 em que:  
  
 *filename*  
 O nome do arquivo. dll ou .exe para o qual você deseja localizar o arquivo. PDB.  
  
 DETALHADO (opcional)  
 Relata todos os diretórios em que foi feita uma tentativa para localizar o arquivo. PDB.  
  
## <a name="remarks"></a>Comentários  
 / PDBPATH irá procurar seu computador em caminhos mesmo que o depurador procura um arquivo. PDB e relatará que, se houver, arquivos. PDB correspondem ao arquivo especificado em *filename*.  
  
 Ao usar o depurador do Visual Studio, você pode enfrentar um problema devido ao fato de que o depurador está usando um arquivo. PDB para uma versão diferente do arquivo que você está depurando.  
  
 / PDBPATH irá procurar por arquivos. PDB ao longo dos seguintes caminhos:  
  
-   Verifique o local em que reside o executável.  
  
-   Verifique a localização do PDB gravado no executável. Isso geralmente é o local no momento em que a imagem foi vinculada.  
  
-   Verifique ao longo do caminho de pesquisa configurado no IDE do Visual Studio.  
  
-   Verifique em caminhos no NT_SYMBOL_PATH e _NT_ALT_SYMBOL_PATH variáveis de ambiente.  
  
-   Verifique no diretório do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Opções de DUMPBIN](../../build/reference/dumpbin-options.md)   
 [/PDBALTPATH (usar demarcador de PDB alternativo)](../../build/reference/pdbaltpath-use-alternate-pdb-path.md)