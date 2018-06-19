---
title: Erro fatal C1197 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1197
dev_langs:
- C++
helpviewer_keywords:
- C1197
ms.assetid: 22b801b7-e792-41f6-a461-973c03c69f25
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dacd459729161cf635287697a4a6d35c15eab3e4
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33227262"
---
# <a name="fatal-error-c1197"></a>Erro fatal C1197
não é possível fazer referência a 'mscorlib.dll_1' como o programa já referenciou 'mscorlib.dll_2'  
  
 O compilador está de acordo com uma versão do common language runtime.  No entanto, houve uma tentativa para fazer referência a uma versão de um arquivo de tempo de execução de linguagem comum de uma versão anterior.  
  
 Para resolver esse erro, somente os arquivos de referência da versão do common language runtime que acompanha a versão do Visual C++, você estão compilando com.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C1197:  
  
```  
// C1197.cpp  
// compile with: /clr /c  
// processor: x86  
#using "C:\Windows\Microsoft.NET\Framework\v1.1.4322\mscorlib.dll"   // C1197  
// try the following line instead  
// #using "mscorlib.dll"  
```