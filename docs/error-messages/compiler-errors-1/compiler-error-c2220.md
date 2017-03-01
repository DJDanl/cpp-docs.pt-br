---
title: C2220 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2220
dev_langs:
- C++
helpviewer_keywords:
- C2220
ms.assetid: d610802c-64d7-40ad-a2a6-0ed0b6815a6c
caps.latest.revision: 12
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 12e7cb41c9092db7c62aaab30bec76478123b410
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2220"></a>C2220 de erro do compilador
Aviso tratado como erro - nenhum arquivo de objeto gerado  
  
 [/WX](../../build/reference/compiler-option-warning-level.md) instrui o compilador a tratar todos os avisos como erros. Porque ocorreu um erro, nenhum objeto ou arquivo executável foi gerado.  
  
 Este erro só aparece quando o **/WX** sinalizador está definido e ocorrer um aviso durante a compilação. Para corrigir esse erro, você deve excluir cada aviso em seu projeto.  
  
### <a name="to-fix-use-one-of-the-following-techniques"></a>Para corrigir, use uma das seguintes técnicas  
  
-   Corrija os problemas que causam avisos em seu projeto.  
  
-   Compilar em um nível inferior de aviso — por exemplo, use **/W3** em vez de **/W4**.  
  
-   Use um [aviso](../../preprocessor/warning.md) pragma para desabilitar ou suprimir um aviso específico.  
  
-   Não use **/WX** para compilar.
