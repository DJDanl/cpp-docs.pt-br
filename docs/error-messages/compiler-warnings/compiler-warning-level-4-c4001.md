---
title: Compilador (nível 4) de aviso C4001 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4001
dev_langs:
- C++
helpviewer_keywords:
- C4001
ms.assetid: 414a47fe-d597-425e-9374-6a569231dc0a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dc728fa5c66fb4b42c8fe4a785f36048ffbaed4e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-4-c4001"></a>Compilador C4001 de aviso (nível 4)
extensão não padrão 'comentário de linha única' foi usado  

> [!NOTE] 
> Esse aviso é removido no Visual Studio 2017 versão 15,5 como comentários de linha única são padrão de C99.
  
 Comentários de linha única são em C++ padrão e em C começando com C99. Em compatibilidade estrita de ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)), arquivos de C que contêm comentários de linha única, gerar C4001 devido ao uso de uma extensão não padrão. Como comentários de linha única são padrão em C++, arquivos de C que contém comentários de linha única não produzem C4001 ao compilar com extensões da Microsoft (/Ze).  
  
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