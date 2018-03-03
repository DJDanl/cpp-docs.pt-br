---
title: "Compilador aviso (nível 3) C4023 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4023
dev_langs:
- C++
helpviewer_keywords:
- C4023
ms.assetid: 615d5374-d7c1-42eb-acfd-917c053270c8
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e22ba0ed3d91f75ba73e68817611302d15fa2039
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-3-c4023"></a>Compilador C4023 de aviso (nível 3)
'symbol': ponteiro baseado transmitido para uma função sem protótipo: o número do parâmetro  
  
 Transmitindo um ponteiro com base em uma função sem protótipo faz com que o ponteiro ser normalizados, com resultados imprevisíveis.  
  
 Esse aviso pode ser corrigido, se você usar funções de protótipo que são passadas ponteiros com base.