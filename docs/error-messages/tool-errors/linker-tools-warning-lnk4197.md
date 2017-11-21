---
title: Aviso LNK4197 das ferramentas de vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK4197
dev_langs: C++
helpviewer_keywords: LNK4197
ms.assetid: 8a976fd7-a74b-4c83-ab66-a9e7d7073c4a
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 5977095609dc123866afc39ac610bb0ff9d1619c
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="linker-tools-warning-lnk4197"></a>Aviso LNK4197 (Ferramentas de Vinculador)
Exportar 'exportname' especificado várias vezes; usando primeira especificação  
  
 Uma exportação é especificada em várias e diferentes maneiras. O vinculador usa a primeira especificação e ignora o resto.  
  
 Se você estiver recriando a biblioteca de tempo de execução C, você pode ignorar essa mensagem.  
  
 Se uma exportação for especificada, exatamente da mesma forma, com várias vezes, o vinculador não emitirá um aviso.  
  
 Por exemplo, o seguinte conteúdo de um arquivo. def poderia causar este aviso:  
  
```  
EXPORTS  
   functioname      NONAME  
   functioname      @10  
```  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  A exportação mesmo for especificada na linha de comando (por meio da exportação:) e no arquivo. def  
  
2.  A exportação mesmo é listada duas vezes no arquivo. def com atributos diferentes.