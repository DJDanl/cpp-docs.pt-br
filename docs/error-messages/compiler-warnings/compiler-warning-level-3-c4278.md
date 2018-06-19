---
title: Compilador aviso (nível 3) C4278 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4278
dev_langs:
- C++
helpviewer_keywords:
- C4278
ms.assetid: 4b6053fb-df62-4c04-b6c8-c011759557b8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7b556166f61c5d77ac34fb7243ac25d5baeaa2b1
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33296670"
---
# <a name="compiler-warning-level-3-c4278"></a>Compilador C4278 de aviso (nível 3)
'Identificador': identificador em biblioteca de tipos 'tlb' já é uma macro; Use o qualificador 'rename'  
  
 Ao usar [#import](../../preprocessor/hash-import-directive-cpp.md), um identificador em typelib que você está importando está tentando declarar um identificador ***identificador***. No entanto, isso já é um símbolo válido.  
  
 Use o `#import` **Renomear** atributo para atribuir um alias para o símbolo na biblioteca de tipos.