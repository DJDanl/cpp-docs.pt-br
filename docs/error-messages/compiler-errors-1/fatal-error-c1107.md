---
title: Erro fatal C1107 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1107
dev_langs:
- C++
helpviewer_keywords:
- C1107
ms.assetid: 541a4d9f-10bc-4dd8-b68e-15e548f3dc0a
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 7746c880b251eccfa1d2688d3ab91b7893970f5c
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="fatal-error-c1107"></a>Erro fatal C1107
não foi possível encontrar o assembly 'file': especifique o caminho de pesquisa de assembly usando /AI ou definindo a variável de ambiente LIBPATH  
  
 Um arquivo de metadados foi passado para um [#using](../../preprocessor/hash-using-directive-cpp.md) diretiva que o compilador não pôde localizar.  
  
 LIBPATH, que é descrito no tópico para `#using`e o [/AI](../../build/reference/ai-specify-metadata-directories.md) opção de compilador permitem que você especifique os diretórios em que o compilador vai procurar arquivos de metadados referenciado.
