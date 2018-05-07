---
title: Ferramentas de vinculador LNK1181 erro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1181
dev_langs:
- C++
helpviewer_keywords:
- LNK1181
ms.assetid: 984b0db6-e331-4284-b2a7-a212fe96c486
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 617678e5453acdafaf72875857b0e0f9b84a110a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="linker-tools-error-lnk1181"></a>Erro das Ferramentas de Vinculador LNK1181
não é possível abrir o arquivo de entrada 'filename'  
  
 Não foi possível encontrar o vinculador `filename` porque ele não existe ou o caminho não foi encontrado.  
  
 Algumas causas comuns para erro LNK1181 incluem:  
  
-   `filename` é referenciada como uma dependência adicional na linha de vinculador, mas o arquivo não existe.  
  
-   Um **/LIBPATH** instrução que especifica o diretório que contém `filename` está ausente.  
  
 Para resolver os problemas acima, certifique-se de todos os arquivos referenciados na linha de vinculador estão presentes no sistema.  Também verifique se há um **/LIBPATH** instrução para cada diretório que contém um arquivo dependente do vinculador.  
  
 Outra causa possível para LNK1181 é que um nome de arquivo longo com espaços incorporados não foi colocado entre aspas.  Nesse caso, o vinculador reconhece apenas um nome de arquivo até o primeiro espaço e, em seguida, suponha que uma extensão de arquivo. obj.  A solução para essa situação é colocar o nome de arquivo longos (nome do caminho e arquivo) entre aspas.  
  
 Para obter mais informações, consulte [arquivos. lib como entrada de vinculador](../../build/reference/dot-lib-files-as-linker-input.md).  
  
## <a name="see-also"></a>Consulte também  
 [/LIBPATH (Libpath adicional)](../../build/reference/libpath-additional-libpath.md)