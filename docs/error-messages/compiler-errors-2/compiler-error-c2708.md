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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 495fd9aeaad785edd8653e46ae666f60c337b12d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2708"></a>C2708 de erro do compilador
'Identificador': comprimento em bytes de parâmetros reais difere da chamada anterior ou referência  
  
 Um [stdcall](../../cpp/stdcall.md) função deve ser precedida por um protótipo. Caso contrário, o compilador interpreta a primeira chamada para a função como um protótipo e esse erro ocorre quando o compilador encontra uma chamada que não corresponde.  
  
 Para corrigir esse erro adicionar um protótipo de função.