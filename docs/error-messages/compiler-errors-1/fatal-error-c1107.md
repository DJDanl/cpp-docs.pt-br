---
title: Erro fatal C1107 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1107
dev_langs:
- C++
helpviewer_keywords:
- C1107
ms.assetid: 541a4d9f-10bc-4dd8-b68e-15e548f3dc0a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 949ee09244a106984522fb35dd13c0b3426fc820
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="fatal-error-c1107"></a>Erro fatal C1107
não foi possível encontrar o assembly 'file': especifique o caminho de pesquisa de assembly usando /AI ou definindo a variável de ambiente LIBPATH  
  
 Um arquivo de metadados foi passado para um [#using](../../preprocessor/hash-using-directive-cpp.md) diretiva que o compilador não pôde localizar.  
  
 LIBPATH, que é descrito no tópico para `#using`e o [/AI](../../build/reference/ai-specify-metadata-directories.md) opção de compilador permitem que você especifique os diretórios em que o compilador vai procurar arquivos de metadados referenciado.