---
title: "Compilador aviso (nível 3) C4023 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C4023
dev_langs: C++
helpviewer_keywords: C4023
ms.assetid: 615d5374-d7c1-42eb-acfd-917c053270c8
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 170a76381dac09ad0543b30e71aedb306b514379
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-3-c4023"></a>Compilador C4023 de aviso (nível 3)
'symbol': ponteiro baseado transmitido para uma função sem protótipo: o número do parâmetro  
  
 Transmitindo um ponteiro com base em uma função sem protótipo faz com que o ponteiro ser normalizados, com resultados imprevisíveis.  
  
 Esse aviso pode ser corrigido, se você usar funções de protótipo que são passadas ponteiros com base.