---
title: "Compilador aviso (nível 4) C4092 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4092
dev_langs:
- C++
helpviewer_keywords:
- C4092
ms.assetid: 396ae826-a892-4327-bd66-f4762376d72b
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
ms.openlocfilehash: 41afb38ca31349f54f0f542d50be61e19eedcc5c
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4092"></a>Compilador C4092 de aviso (nível 4)
sizeof retorna 'unsigned long'  
  
 O operando do `sizeof` operador era muito grande, então `sizeof` retornou um unsigned **longo**. Esse aviso ocorre sob as extensões da Microsoft ([/Ze](../../build/reference/za-ze-disable-language-extensions.md)). Em compatibilidade com ANSI (/Za), o resultado será truncado em vez disso.
