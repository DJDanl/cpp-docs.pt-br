---
title: C2856 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2856
dev_langs:
- C++
helpviewer_keywords:
- C2856
ms.assetid: fe616c51-124e-49e3-9dd8-883ec1660680
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ac67538a10d39bc68059b0a7d1aaf73a381abb2a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33244127"
---
# <a name="compiler-error-c2856"></a>C2856 de erro do compilador
\#pragma hdrstop não pode estar dentro de um bloco de #if  
  
 O `hdrstop` pragma não pode ser colocado dentro do corpo de um bloco de compilação condicional.  
  
 Mover o `#pragma hdrstop` instrução para uma área que não está contida em um `#if/#endif` bloco.