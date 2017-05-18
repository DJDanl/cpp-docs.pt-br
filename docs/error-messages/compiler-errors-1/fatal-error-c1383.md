---
title: Erro fatal C1383 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C1383
dev_langs:
- C++
helpviewer_keywords:
- C1383
ms.assetid: ca224d14-d687-4fd6-80c2-8b82f28924ea
caps.latest.revision: 5
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 4e88d0556ad6d1316346fe821ec6d6e0f077e176
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1383"></a>Erro fatal C1383
opção de compilador /GL é incompatível com a versão instalada de common language runtime  
  
 C1383 ocorre quando você estiver usando uma versão anterior do common language runtime com um compilador mais recente e, quando você compila com **/clr** e **/GL.**  
  
 Para resolver, não use **/GL** com **/clr** ou instale a versão do common language runtime fornecido com seu compilador.  
  
 Para obter mais informações, consulte [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md) e [/GL (otimização de programa total)](../../build/reference/gl-whole-program-optimization.md).
