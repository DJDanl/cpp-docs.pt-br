---
title: "Compilador (nível 1) de aviso C4810 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C4810
dev_langs: C++
helpviewer_keywords: C4810
ms.assetid: 39e2cae0-9c1c-4ac1-aaa0-5f661d06085b
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 65c9c51a7672bea5d6aec81d8b1ee2363519e488
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-1-c4810"></a>Compilador C4810 de aviso (nível 1)
valor de pragma Pack (show) o usuário = = n  
  
 Esse aviso é emitido quando você usa o **Mostrar** opção do [pacote](../../preprocessor/pack.md) pragma. *n*é o valor atual do pacote.  
  
 Por exemplo, o código a seguir mostra como o aviso C4810 funciona com o pragma pack:  
  
```  
// C4810.cpp  
// compile with: /W1 /LD  
// C4810 expected  
#pragma pack(show)  
#pragma pack(4)  
#pragma pack(show)  
```