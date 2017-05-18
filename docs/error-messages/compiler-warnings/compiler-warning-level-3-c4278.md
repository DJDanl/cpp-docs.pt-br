---
title: "Compilador aviso (nível 3) C4278 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4278
dev_langs:
- C++
helpviewer_keywords:
- C4278
ms.assetid: 4b6053fb-df62-4c04-b6c8-c011759557b8
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 8b7811a0112e0054e6e1ce1b62f0900f7333ccc6
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-3-c4278"></a>Compilador C4278 de aviso (nível 3)
'identifier': identificador na biblioteca de tipos 'tlb' já é uma macro; Use o qualificador 'Renomear'  
  
 Ao usar [#import](../../preprocessor/hash-import-directive-cpp.md), um identificador em typelib você está importando está tentando declarar um identificador ***identificador***. No entanto, isso já é um símbolo válido.  
  
 Use o `#import` **Renomear** atributo para atribuir um alias para o símbolo na biblioteca de tipos.
