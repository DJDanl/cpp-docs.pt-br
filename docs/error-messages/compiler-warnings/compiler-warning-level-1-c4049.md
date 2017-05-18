---
title: "Compilador aviso (nível 1) C4049 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4049
dev_langs:
- C++
helpviewer_keywords:
- C4049
ms.assetid: d11c1870-bcfc-4d71-8945-b87ec6ec3514
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
ms.openlocfilehash: 56a1dff328480d419eb82f01815392b3cc1e23df
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4049"></a>Compilador C4049 de aviso (nível 1)
limite do compilador : encerrando emissão de números de linha  
  
 O arquivo contém mais de 16.777.215 (2<sup>24</sup>-1) linhas de origem. O compilador para numeração em 16.777.215.  
  
 Para o código após a linha 16.777.215:  
  
-   A imagem não conterá nenhuma informação de depuração para números de linha.  
  
-   Alguns diagnósticos podem ser relatados com números de linha incorreta.  
  
-   listagens de .asm (/ FAs) podem ter números de linha incorreta.
