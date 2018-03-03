---
title: C2856 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2856
dev_langs:
- C++
helpviewer_keywords:
- C2856
ms.assetid: fe616c51-124e-49e3-9dd8-883ec1660680
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ab5fdd09fbbd7c6b1f213404dfbf6d9d9e5612ea
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2856"></a>C2856 de erro do compilador
\#pragma hdrstop não pode estar dentro de um bloco de #if  
  
 O `hdrstop` pragma não pode ser colocado dentro do corpo de um bloco de compilação condicional.  
  
 Mover o `#pragma hdrstop` instrução para uma área que não está contida em um `#if/#endif` bloco.