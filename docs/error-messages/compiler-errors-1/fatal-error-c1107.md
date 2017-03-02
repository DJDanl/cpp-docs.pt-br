---
title: Erro fatal C1107 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
ms.openlocfilehash: c8cf4371b7409fb01f6000eb5abccefc22fcdf21
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1107"></a>Erro fatal C1107
não foi possível encontrar o assembly 'arquivo': especifique o caminho de pesquisa de assembly usando /AI ou definindo a variável de ambiente LIBPATH  
  
 Um arquivo de metadados foi passado para um [#using](../../preprocessor/hash-using-directive-cpp.md) diretiva que o compilador não pôde localizar.  
  
 LIBPATH, que é descrita no tópico para `#using`e o [/AI](../../build/reference/ai-specify-metadata-directories.md) opção de compilador permitem que você especifique os diretórios nos quais o compilador irá procurar arquivos de metadados referenciado.
