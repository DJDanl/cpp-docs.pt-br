---
title: Compilador (nível 1) de aviso C4276 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4276
dev_langs:
- C++
helpviewer_keywords:
- C4276
ms.assetid: 9d738c2d-29e5-408a-b9ff-be1a850b2238
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: afedab27c2fb93075aa33053c12ec6973824f144
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4276"></a>Compilador C4276 de aviso (nível 1)
'function': nenhum protótipo fornecido; assumido sem parâmetros  
  
 Quando você faz o endereço de uma função com o [stdcall](../../cpp/stdcall.md) convenção de chamada, você deve fornecer um protótipo para o compilador possa criar o nome da função realçada. Como *função* não tem nenhum protótipo, o compilador, ao criar o nome decorado, assume a função não tem parâmetros.