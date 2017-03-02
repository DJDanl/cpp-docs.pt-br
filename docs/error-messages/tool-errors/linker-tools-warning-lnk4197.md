---
title: Aviso LNK4197 das ferramentas de vinculador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4197
dev_langs:
- C++
helpviewer_keywords:
- LNK4197
ms.assetid: 8a976fd7-a74b-4c83-ab66-a9e7d7073c4a
caps.latest.revision: 6
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
ms.openlocfilehash: 3ef9f4ad3822e6fbe3f323fe985b3d4330753df4
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-warning-lnk4197"></a>Aviso LNK4197 (Ferramentas de Vinculador)
Exportar 'exportname' especificado várias vezes; usando a primeira especificação  
  
 Uma exportação é especificada em várias e diferentes maneiras. O vinculador usa a primeira especificação e ignora o resto.  
  
 Se você estiver recriando a biblioteca de tempo de execução C, você pode ignorar essa mensagem.  
  
 Se uma exportação é especificada exatamente da mesma maneira, várias vezes, o vinculador não emitirá um aviso.  
  
 Por exemplo, o seguinte conteúdo de um arquivo. def poderia causar este aviso:  
  
```  
EXPORTS  
   functioname      NONAME  
   functioname      @10  
```  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  A mesma exportação for especificada na linha de comando (através de exportação:) e no arquivo. def  
  
2.  A mesma exportação é listada duas vezes no arquivo. def com atributos diferentes.
