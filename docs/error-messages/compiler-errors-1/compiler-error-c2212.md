---
title: C2212 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2212
dev_langs: C++
helpviewer_keywords: C2212
ms.assetid: 3fdab304-272c-4d07-bfd4-fad75170e536
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 0c49161940c1f382a8bf9d82a648cc4396a11e86
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2212"></a>C2212 de erro do compilador
'Identificador': based não disponível a ponteiros para funções  
  
 Ponteiros para funções não podem ser declarados `__based`. Se você precisar de dados com base em código, use o `__declspec` palavra-chave ou o `data_seg` pragma.