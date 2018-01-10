---
title: -PDBALTPATH (usar demarcador de PDB alternativo) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /pdbaltpath
dev_langs: C++
helpviewer_keywords:
- .pdb files, path
- PDBALTPATH dumpbin option
- -PDBALTPATH dumpbin option
- /PDBALTPATH dumpbin option
- PDB files, path
ms.assetid: 72e200aa-e2c3-4ad8-b687-25528da1aaaf
caps.latest.revision: "12"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9053bc206a465eb32d8007fb8d58d13d45eb4a0b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="pdbaltpath-use-alternate-pdb-path"></a>/PDBALTPATH (usar demarcador de PDB alternativo)
```  
/PDBALTPATH:pdb_file_name  
```  
  
## <a name="remarks"></a>Comentários  
 em que:  
  
 *pdb_file_name*  
 O caminho e o nome de arquivo para o arquivo .pdb.  
  
## <a name="remarks"></a>Comentários  
 Use essa opção para oferecer um local alternativo para o arquivo Program Database (.pdb) em um arquivo binário compilado. Normalmente, o vinculador registra o local do arquivo .pdb nos binários que o reproduzem. Você pode usar essa opção para oferecer um caminho e o nome de arquivo diferentes para o arquivo .pdb. As informações fornecidas com /PDBALTPATH não alteram o local ou o nome do arquivo .pdb real; o que muda são as informações que o vinculador grava no arquivo binário. Isso faz com que seja possível fornecer um caminho independente da estrutura do arquivo do computador da compilação. Dois usos comuns dessa opção são: oferecer um caminho de rede ou um arquivo sem informações de caminho.  
  
 O valor de *pdb_file_name* pode ser uma cadeia de caracteres arbitrária, uma variável de ambiente ou **_PDB %**. O vinculador vai expandir uma variável de ambiente, como **% SystemRoot %**, para seu valor. O vinculador define as variáveis de ambiente **_PDB %** e **_EXT %**. **% _PDB %** expande o nome de arquivo do arquivo. PDB real sem qualquer informação de caminho e **_EXT %** é a extensão do executável gerado.  
  
## <a name="see-also"></a>Consulte também  
 [Opções de DUMPBIN](../../build/reference/dumpbin-options.md)   
 [/ PDBPATH](../../build/reference/pdbpath.md)