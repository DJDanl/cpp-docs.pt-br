---
title: Linha de comando D9043 de aviso | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: D9043
dev_langs: C++
helpviewer_keywords: D9043
ms.assetid: 9263e28d-217b-414c-bfb6-86efd3c27a77
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 88e38b333ab28ec15a567d813f09201fd9218060
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="command-line-warning-d9043"></a>Aviso D9043 (linha de comando)
valor inválido 'warning_level' para 'compiler_option'; Supondo que '4999'; Avisos da análise de código não estão associados com níveis de aviso  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C9043.  
  
```  
// D9043.cpp  
// compile with: /analyze /w16001  
// D9043 warning expected  
int main() {}  
```