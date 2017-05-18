---
title: "Compilador aviso (nível 4) C4001 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4001
dev_langs:
- C++
helpviewer_keywords:
- C4001
ms.assetid: 414a47fe-d597-425e-9374-6a569231dc0a
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
ms.openlocfilehash: bbcf2db5f6650bd9118b28c8bbfe921d13306410
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4001"></a>Compilador C4001 de aviso (nível 4)
extensão não padrão 'comentário de linha única' foi usada  
  
 Comentários de linha única estão em C++ padrão e em C. Em compatibilidade estrita com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)), arquivos de C que contêm comentários de linha única, gerar C4001 devido ao uso de uma extensão não padrão. Como comentários de linha única são padrão em C++, arquivos de C que contém comentários de linha única não produzem C4001 ao compilar com extensões da Microsoft (/Ze).  
  
## <a name="example"></a>Exemplo  
 Para desabilitar o aviso, remova os comentários [#pragma warning(disable:4001)](../../preprocessor/warning.md).  
  
```  
// C4001.cpp  
// compile with: /W4 /Za /TC  
// #pragma warning(disable:4001)  
int main()  
{  
   // single-line comment in main  
   // C4001  
}  
```
