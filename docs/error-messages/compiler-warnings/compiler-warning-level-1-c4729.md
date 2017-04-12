---
title: "Compilador aviso (nível 1) C4729 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4729
dev_langs:
- C++
helpviewer_keywords:
- C4729
ms.assetid: 36a0151f-f258-48d9-9444-ae6d41ff70a4
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: babe4bf05b93d92584cea952d6b70da008223260
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4729"></a>Compilador C4729 de aviso (nível 1)
função muito grande para avisos baseados em gráfico de fluxo  
  
 Esse aviso é gerado quando uma função é muito grande para ser compilado com verificação confiável para situações que geram um aviso. Este aviso só é gerado quando o [/Od](../../build/reference/od-disable-debug.md) opção de compilador usada.  
  
 Para resolver esse aviso, divida a função em funções menores.
