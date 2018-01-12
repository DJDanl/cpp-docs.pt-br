---
title: Ferramentas de vinculador LNK1181 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK1181
dev_langs: C++
helpviewer_keywords: LNK1181
ms.assetid: 984b0db6-e331-4284-b2a7-a212fe96c486
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 8f5092d4f3ce7b4f96ca4dc5c1554483a7fc3a0b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-error-lnk1181"></a>Erro das Ferramentas de Vinculador LNK1181
não é possível abrir o arquivo de entrada 'filename'  
  
 Não foi possível encontrar o vinculador `filename` porque ele não existe ou o caminho não foi encontrado.  
  
 Algumas causas comuns para erro LNK1181 incluem:  
  
-   `filename`é referenciada como uma dependência adicional na linha de vinculador, mas o arquivo não existe.  
  
-   Um **/LIBPATH** instrução que especifica o diretório que contém `filename` está ausente.  
  
 Para resolver os problemas acima, certifique-se de todos os arquivos referenciados na linha de vinculador estão presentes no sistema.  Também verifique se há um **/LIBPATH** instrução para cada diretório que contém um arquivo dependente do vinculador.  
  
 Outra causa possível para LNK1181 é que um nome de arquivo longo com espaços incorporados não foi colocado entre aspas.  Nesse caso, o vinculador reconhece apenas um nome de arquivo até o primeiro espaço e, em seguida, suponha que uma extensão de arquivo. obj.  A solução para essa situação é colocar o nome de arquivo longos (nome do caminho e arquivo) entre aspas.  
  
 Para obter mais informações, consulte [arquivos. lib como entrada de vinculador](../../build/reference/dot-lib-files-as-linker-input.md).  
  
## <a name="see-also"></a>Consulte também  
 [/LIBPATH (Libpath adicional)](../../build/reference/libpath-additional-libpath.md)