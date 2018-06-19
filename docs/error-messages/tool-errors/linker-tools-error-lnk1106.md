---
title: Ferramentas de vinculador LNK1106 erro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1106
dev_langs:
- C++
helpviewer_keywords:
- LNK1106
ms.assetid: 528f7e65-04be-4966-b8af-9276837c7cda
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a3dedaa2bd500b11f06f9cfa98802fdd6ca84534
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33298085"
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