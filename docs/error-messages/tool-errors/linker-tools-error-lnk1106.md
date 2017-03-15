---
title: Ferramentas de vinculador LNK1106 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1106
dev_langs:
- C++
helpviewer_keywords:
- LNK1106
ms.assetid: 528f7e65-04be-4966-b8af-9276837c7cda
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
ms.openlocfilehash: a98d4a4f1565fe492cb319ba08322609a63754f6
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk1106"></a>Erro das Ferramentas de Vinculador LNK1106
arquivo inválido ou disco cheio: não é possível buscar o local  
  
 A ferramenta não pôde ler ou gravar em `location` em um arquivo de memória mapeada.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  Disco cheio.  
  
     Libere algum espaço e vincular novamente.  
  
2.  Tentando vincular através de uma rede.  
  
     Algumas redes totalmente não dão suporte os arquivos mapeados na memória usados pelo vinculador. Tente vincular em seu disco local.  
  
3.  Bloco inválido no disco.  
  
     Embora o sistema operacional e hardware de disco devem ter detectado um erro, você talvez queira executar um programa de verificação de disco.  
  
4.  Sem espaço de heap.  
  
     Consulte [C1060](../../error-messages/compiler-errors-1/fatal-error-c1060.md) para obter mais informações.
