---
title: "Compilador (nível 4) de aviso C4937 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C4937
dev_langs: C++
helpviewer_keywords: C4937
ms.assetid: 2bb9f0e7-bbd6-4697-84de-95955e32ae29
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c054051db1b7c765dd2b144b8bd3426593896a91
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-4-c4937"></a>Compilador C4937 de aviso (nível 4)
'text1' e 'text2' são indistinguíveis como argumentos para 'diretiva'  
  
 Por causa da forma, o compilador processa argumentos para diretivas, nomes que têm significado para o compilador, como palavras-chave com várias representações de texto (formulários sublinhado simples e duplas), não podem ser diferenciadas.  
  
 Exemplos de cadeias de caracteres são cdecl e \__forceinline.  Observe, em /Za, que somente os formulários de sublinhado duplo estão habilitados.  
  
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