---
title: Aviso LNK4204 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4204
helpviewer_keywords:
- LNK4204
ms.assetid: 14adda20-0cbe-407b-90f6-9f81c93530e2
ms.openlocfilehash: 98c53c9b998e9bd544c1cc72bd2b0c3fd2b0a418
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80193856"
---
# <a name="linker-tools-warning-lnk4204"></a>Aviso LNK4204 (Ferramentas de Vinculador)

' FileName ' não tem informações de depuração para o módulo de referência; Vinculando objeto quando sem informação de depuração

O arquivo. pdb tem uma assinatura incorreta. O vinculador continuará a vincular o objeto sem informações de depuração. Talvez você queira recompilar o arquivo de objeto usando a opção [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md) .

LNK4204 pode ocorrer se alguns dos objetos na biblioteca se referirem a um arquivo que não existe mais. Isso pode acontecer ao recompilar a solução, por exemplo; um arquivo de objeto pode ser excluído e não recriado devido a um erro de compilação. Nesse caso, compile com **/Z7**ou **/FD**para atualizar os objetos para se referir a um único arquivo por biblioteca (que não é o nome de arquivo. PDB padrão).  Para obter mais informações, consulte [/Fd (nome de arquivo de banco de dados do programa)](../../build/reference/fd-program-database-file-name.md).  Certifique-se de que o. pdb seja salvo com a biblioteca sempre que for atualizado no sistema de controle do código-fonte.
