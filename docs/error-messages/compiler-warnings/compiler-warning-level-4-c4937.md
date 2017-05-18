---
title: "Compilador aviso (nível 4) C4937 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4937
dev_langs:
- C++
helpviewer_keywords:
- C4937
ms.assetid: 2bb9f0e7-bbd6-4697-84de-95955e32ae29
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: d2e76c52ea1c24266940d07f04e9d962fc948d95
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4937"></a>Compilador C4937 de aviso (nível 4)
'text1' e 'text2' não podem ser diferenciados como argumentos para 'diretiva'  
  
 Devido ao modo como o compilador processa argumentos para diretivas, os nomes que tenham significado para o compilador, como palavras-chave com várias representações de texto (formulários simples e duplas sublinhado), não podem ser diferenciadas.  
  
 Exemplos de cadeias de caracteres são cdecl e \__forceinline.  Observe, sob /Za, que somente os formulários de sublinhado duplo são habilitados.  
  
 O exemplo a seguir gera C4937:  
  
```  
// C4937.cpp  
// compile with: /openmp /W4  
#include "omp.h"  
int main() {  
   #pragma omp critical ( __leave )   // C4937  
   ;  
  
   // OK  
   #pragma omp critical ( leave )  
   ;  
}  
```
