---
title: Ferramentas de vinculador LNK1181 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1181
dev_langs:
- C++
helpviewer_keywords:
- LNK1181
ms.assetid: 984b0db6-e331-4284-b2a7-a212fe96c486
caps.latest.revision: 10
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
ms.openlocfilehash: ab1aa9ceba8355b3f06c469d52248aa982cfdb71
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk1181"></a>Erro das Ferramentas de Vinculador LNK1181
não é possível abrir o arquivo de entrada 'filename'  
  
 Não foi possível localizar o vinculador `filename` porque ele não existe ou o caminho não foi encontrado.  
  
 Algumas causas comuns de erro LNK1181 incluem:  
  
-   `filename`é referenciada como uma dependência adicional na linha de vinculador, mas o arquivo não existe.  
  
-   A **/LIBPATH** instrução que especifica o diretório que contém `filename` está ausente.  
  
 Para resolver os problemas acima, verifique todos os arquivos referenciados na linha de vinculador estão presentes no sistema.  Também verifique se há um **/LIBPATH** instrução para cada diretório que contém um arquivo dependente do vinculador.  
  
 Outra causa possível para LNK1181 é que um nome de arquivo longo com espaços inseridos não foi colocado entre aspas.  Nesse caso, o vinculador reconhecer apenas um nome de arquivo até o primeiro espaço e, em seguida, suponha que uma extensão de arquivo. obj.  A solução para essa situação é colocar o nome de arquivo longo (nome do caminho e arquivo) devem estar entre aspas.  
  
 Para obter mais informações, consulte [arquivos. lib como entrada de vinculador](../../build/reference/dot-lib-files-as-linker-input.md).  
  
## <a name="see-also"></a>Consulte também  
 [/LIBPATH (Libpath adicional)](../../build/reference/libpath-additional-libpath.md)
