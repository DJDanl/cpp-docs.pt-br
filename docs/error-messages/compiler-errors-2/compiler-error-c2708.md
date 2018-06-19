---
title: C2708 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2708
dev_langs:
- C++
helpviewer_keywords:
- C2708
ms.assetid: d52d3088-1141-42f4-829c-74755a7fcc3a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d30b2e5c1856a604ae314316cd71d6acc00a7c74
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33234754"
---
# <a name="compiler-error-c2708"></a>C2708 de erro do compilador
'Identificador': comprimento em bytes de parâmetros reais difere da chamada anterior ou referência  
  
 Um [stdcall](../../cpp/stdcall.md) função deve ser precedida por um protótipo. Caso contrário, o compilador interpreta a primeira chamada para a função como um protótipo e esse erro ocorre quando o compilador encontra uma chamada que não corresponde.  
  
 Para corrigir esse erro adicionar um protótipo de função.