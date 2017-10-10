---
title: C2708 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2708
dev_langs:
- C++
helpviewer_keywords:
- C2708
ms.assetid: d52d3088-1141-42f4-829c-74755a7fcc3a
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 8ce9eb29c776c7d98a7fbad4dc95959180045256
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2708"></a>C2708 de erro do compilador
'Identificador': comprimento em bytes de parâmetros reais difere da chamada anterior ou referência  
  
 Um [stdcall](../../cpp/stdcall.md) função deve ser precedida por um protótipo. Caso contrário, o compilador interpreta a primeira chamada para a função como um protótipo e esse erro ocorre quando o compilador encontra uma chamada que não corresponde.  
  
 Para corrigir esse erro adicionar um protótipo de função.
