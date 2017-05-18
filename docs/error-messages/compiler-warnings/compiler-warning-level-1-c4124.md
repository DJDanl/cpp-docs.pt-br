---
title: "Compilador aviso (nível 1) C4124 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4124
dev_langs:
- C++
helpviewer_keywords:
- C4124
ms.assetid: c08c3a65-9584-47a1-a147-44f00c4b230e
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 8f367d8ec2360939d499c9f4e53ee690f860cc18
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4124"></a>Compilador C4124 de aviso (nível 1)
__fastcall com verificação de pilha é ineficiente  
  
 O `__fastcall` palavra-chave foi usado com a verificação da pilha habilitado.  
  
 O `__fastcall` convenção gera código mais rápido, mas a verificação da pilha faz com que o código mais lento. Ao usar `__fastcall`, desative a verificação da pilha com o **check_stack** pragma ou /Gs.  
  
 Esse aviso é emitido apenas para a primeira função declarada sob essas condições.
