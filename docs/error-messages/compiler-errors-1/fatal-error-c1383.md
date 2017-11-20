---
title: Erro fatal C1383 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C1383
dev_langs: C++
helpviewer_keywords: C1383
ms.assetid: ca224d14-d687-4fd6-80c2-8b82f28924ea
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: ff620211470e82cd53a893bdee94fb1ca5d405c9
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="fatal-error-c1383"></a>Erro fatal C1383
opção de compilador /GL é incompatível com a versão instalada do common language runtime  
  
 C1383 ocorre quando você estiver usando uma versão anterior do common language runtime com um compilador mais recente, e quando você compilar com **/clr** e **/GL.**  
  
 Para resolver, não use **/GL** com **/clr** ou instale a versão do common language runtime fornecido com o compilador.  
  
 Para obter mais informações, consulte [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md) e [/GL (otimização de programa total)](../../build/reference/gl-whole-program-optimization.md).