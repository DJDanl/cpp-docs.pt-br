---
title: Aviso LNK4204 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4204
helpviewer_keywords:
- LNK4204
ms.assetid: 14adda20-0cbe-407b-90f6-9f81c93530e2
ms.openlocfilehash: 790b0fa25bbf41c38b843e1a2ea757fdc0d10b9a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62395099"
---
# <a name="linker-tools-warning-lnk4204"></a>Aviso LNK4204 (Ferramentas de Vinculador)

'filename' não tem informações de depuração para módulo de referência; Vinculando objeto quando sem informação de depuração

O arquivo. PDB tem uma assinatura incorreta. O vinculador continuará vincular o objeto sem informações de depuração. Talvez você queira recompilar o arquivo de objeto usando o [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md) opção.

LNK4204 pode ocorrer se alguns dos objetos na biblioteca de referem a um arquivo que não existe mais. Isso pode acontecer durante a recriação da solução, por exemplo: um arquivo de objeto pode ser excluído e recriado não devido a um erro de compilação. Nesse caso, a compilar com **/Z7**, ou **/Fd**para atualizar os objetos para se referir a uma único arquivo por biblioteca (que não seja o nome padrão do arquivo. PDB).  Para obter mais informações, consulte [/Fd (nome de arquivo de banco de dados do programa)](../../build/reference/fd-program-database-file-name.md).  Certifique-se de que o. PDB é salvo com a biblioteca sempre que ele é atualizado no sistema de controle de origem.