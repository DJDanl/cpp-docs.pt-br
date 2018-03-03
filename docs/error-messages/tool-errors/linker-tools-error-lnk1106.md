---
title: Ferramentas de vinculador LNK1106 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1106
dev_langs:
- C++
helpviewer_keywords:
- LNK1106
ms.assetid: 528f7e65-04be-4966-b8af-9276837c7cda
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 793d788462a3a449c654c30ec874399a3bb85728
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-error-lnk1106"></a>Erro das Ferramentas de Vinculador LNK1106
arquivo inválido ou disco cheio: não é possível buscar o local  
  
 A ferramenta não foi possível ler ou gravar `location` em um arquivo de mapeamento de memória.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  Disco está cheio.  
  
     Libere espaço e vincule novamente.  
  
2.  Tentativa de link em uma rede.  
  
     Algumas redes totalmente não dão suporte os arquivos mapeados na memória usados pelo vinculador. Tente vincular em seu disco local.  
  
3.  Bloco inválido no disco.  
  
     Embora o sistema operacional e o hardware de disco devem ter detectado um erro, convém executar um programa de verificação de disco.  
  
4.  Não há espaço de pilha.  
  
     Consulte [C1060](../../error-messages/compiler-errors-1/fatal-error-c1060.md) para obter mais informações.