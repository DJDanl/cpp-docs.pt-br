---
title: C2708 de erro do compilador | Documentos do Microsoft
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
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: aab3d7817c1150b1197989ce42085708394c6eab
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2708"></a>C2708 de erro do compilador
'identifier': comprimento de parâmetros reais em bytes difere da chamada anterior ou referência  
  
 A [stdcall](../../cpp/stdcall.md) função deve ser precedida por um protótipo. Caso contrário, o compilador interpreta a primeira chamada para a função como um protótipo e esse erro ocorre quando o compilador encontra uma chamada que não corresponde.  
  
 Para corrigir esse erro adicione um protótipo de função.
