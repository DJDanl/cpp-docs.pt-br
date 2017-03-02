---
title: Ferramentas de vinculador LNK1201 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1201
dev_langs:
- C++
helpviewer_keywords:
- LNK1201
ms.assetid: 64c3f496-a428-4b54-981e-faa82ef9c8a1
caps.latest.revision: 7
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
ms.openlocfilehash: 146d4910c755e77b5cc6675a0112c0490ed5e41e
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk1201"></a>Erro das Ferramentas de Vinculador LNK1201
Erro ao gravar no banco de dados do programa 'filename'; Verifique se há espaço em disco insuficiente, caminho inválido ou privilégios insuficientes  
  
 LINK não pôde gravar no banco de dados do programa (PDB) para o arquivo de saída.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  O arquivo está danificado. Exclua o arquivo PDB e vincular novamente.  
  
2.  Espaço em disco insuficiente para gravar o arquivo.  
  
3.  Unidade não estiver disponível, possivelmente devido a um problema de rede.  
  
4.  O depurador está ativo o programa que você está tentando se vincular.  
  
5.  Sem espaço de heap.  Consulte [C1060](../../error-messages/compiler-errors-1/fatal-error-c1060.md) para obter mais informações.
