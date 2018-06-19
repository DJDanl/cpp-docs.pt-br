---
title: C2212 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2212
dev_langs:
- C++
helpviewer_keywords:
- C2212
ms.assetid: 3fdab304-272c-4d07-bfd4-fad75170e536
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 152b38be30b50684684bb0c2c39a035b748915b6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33168731"
---
# <a name="compiler-error-c2212"></a>C2212 de erro do compilador
'Identificador': based não disponível a ponteiros para funções  
  
 Ponteiros para funções não podem ser declarados `__based`. Se você precisar de dados com base em código, use o `__declspec` palavra-chave ou o `data_seg` pragma.