---
title: Aviso LNK4197 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4197
dev_langs:
- C++
helpviewer_keywords:
- LNK4197
ms.assetid: 8a976fd7-a74b-4c83-ab66-a9e7d7073c4a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dfef7f0fe2d9cd50fa6a18ad682c3e4d80df99c8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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