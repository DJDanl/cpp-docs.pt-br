---
title: Erro fatal C1107 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C1107
dev_langs: C++
helpviewer_keywords: C1107
ms.assetid: 541a4d9f-10bc-4dd8-b68e-15e548f3dc0a
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 50a8524cdaddf3d160a2a718a1efbac2562f4127
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="fatal-error-c1107"></a>Erro fatal C1107
não foi possível encontrar o assembly 'file': especifique o caminho de pesquisa de assembly usando /AI ou definindo a variável de ambiente LIBPATH  
  
 Um arquivo de metadados foi passado para um [#using](../../preprocessor/hash-using-directive-cpp.md) diretiva que o compilador não pôde localizar.  
  
 LIBPATH, que é descrito no tópico para `#using`e o [/AI](../../build/reference/ai-specify-metadata-directories.md) opção de compilador permitem que você especifique os diretórios em que o compilador vai procurar arquivos de metadados referenciado.