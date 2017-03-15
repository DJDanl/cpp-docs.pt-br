---
title: Aviso LNK4204 das ferramentas de vinculador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4204
dev_langs:
- C++
helpviewer_keywords:
- LNK4204
ms.assetid: 14adda20-0cbe-407b-90f6-9f81c93530e2
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
ms.openlocfilehash: a77aadcc9fbdb52e1146ac7a093ab94b8aba16ee
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-warning-lnk4204"></a>Aviso LNK4204 (Ferramentas de Vinculador)
'filename' está faltando informações de referência de módulo; de depuração Vinculando objeto como se nenhuma informação de depuração  
  
 O arquivo. PDB tem uma assinatura incorreta. O vinculador continuará vincular o objeto sem informações de depuração. Talvez seja necessário recompilar o arquivo de objeto usando o [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md) opção.  
  
 LNK4204 pode ocorrer se alguns dos objetos na biblioteca de referem a um arquivo que não existe mais. Isso pode acontecer durante a recriação da solução, por exemplo: um arquivo de objeto pode ser excluído e recriado não devido a um erro de compilação. Nesse caso, uma compilação com **/Z7**, ou **/Fd**, atualize os objetos para se referir a uma único arquivo por biblioteca (que não seja o nome padrão do arquivo. PDB).  Para obter mais informações, consulte [/Fd (nome de arquivo de banco de dados do programa)](../../build/reference/fd-program-database-file-name.md).  Certifique-se de que o. PDB é salvo com a biblioteca sempre que ele for atualizado no sistema de controle de origem.
