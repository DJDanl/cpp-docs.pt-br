---
title: Aviso LNK4204 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4204
dev_langs:
- C++
helpviewer_keywords:
- LNK4204
ms.assetid: 14adda20-0cbe-407b-90f6-9f81c93530e2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f000fa42357a299c943eda0cd5f8697aee138f4a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="linker-tools-warning-lnk4204"></a>Aviso LNK4204 (Ferramentas de Vinculador)
'filename' está faltando informações para a referência de módulo; de depuração Vinculando objeto quando sem informação de depuração  
  
 O arquivo. PDB tem uma assinatura incorreta. O vinculador continuará vincular o objeto sem informações de depuração. Talvez seja necessário recompilar o arquivo de objeto usando o [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md) opção.  
  
 LNK4204 pode ocorrer se alguns dos objetos na biblioteca de referem a um arquivo que não existe mais. Isso pode acontecer quando a solução, por exemplo; um arquivo de objeto pode ser excluído e recriado não devido a um erro de compilação. Nesse caso, a compilação com **/Z7**, ou **/Fd**para atualizar os objetos para se referir a uma único arquivo por biblioteca (que não seja o nome padrão do arquivo. PDB).  Para obter mais informações, consulte [/Fd (nome de arquivo de banco de dados do programa)](../../build/reference/fd-program-database-file-name.md).  Certifique-se de que o. PDB é salvo com a biblioteca toda vez que ele é atualizado no sistema de controle de origem.