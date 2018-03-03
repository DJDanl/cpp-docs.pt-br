---
title: "Compilador (nível 1) de aviso C4276 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4276
dev_langs:
- C++
helpviewer_keywords:
- C4276
ms.assetid: 9d738c2d-29e5-408a-b9ff-be1a850b2238
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: af9a32da86a0ea9e530af03a2175976d4cd9f091
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4276"></a>Compilador C4276 de aviso (nível 1)
'function': nenhum protótipo fornecido; assumido sem parâmetros  
  
 Quando você faz o endereço de uma função com o [stdcall](../../cpp/stdcall.md) convenção de chamada, você deve fornecer um protótipo para o compilador possa criar o nome da função realçada. Como *função* não tem nenhum protótipo, o compilador, ao criar o nome decorado, assume a função não tem parâmetros.