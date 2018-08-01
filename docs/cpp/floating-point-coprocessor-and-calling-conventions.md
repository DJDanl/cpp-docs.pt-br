---
title: Coprocessador de ponto flutuante e convenções de chamada | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- floating-point numbers [C++]
- floating-point coprocessor
ms.assetid: 3cc6615a-b308-4cf7-9570-83e192a832b3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 66ccd54c4abb1d8d9761d5ded88beba76bfae043
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39401348"
---
# <a name="floating-point-coprocessor-and-calling-conventions"></a>Coprocessador de ponto flutuante e convenções de chamada
Se você estiver escrevendo assembly rotinas para flutuante coprocessador de ponto, você deve preservar flutuante palavra de controle de ponto e limpar a pilha do coprocessador a menos que você está retornando um **float** ou **duplo** valor (que sua função deve retornar no ST(0)).  
  
## <a name="see-also"></a>Consulte também  
 [Convenções de chamada](../cpp/calling-conventions.md)