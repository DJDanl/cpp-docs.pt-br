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
ms.openlocfilehash: bc896f08ac161cae4e4fab5e991da810f3faf195
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46016631"
---
# <a name="fatal-error-c1107"></a>Erro fatal C1107

não foi possível encontrar o assembly 'file': especifique o caminho de pesquisa de assembly usando /AI ou definindo a variável de ambiente LIBPATH

Um arquivo de metadados foi passado para um [#using](../../preprocessor/hash-using-directive-cpp.md) diretiva que o compilador não pôde localizar.

LIBPATH, que é descrito no tópico de `#using`e o [/AI](../../build/reference/ai-specify-metadata-directories.md) opção de compilador permitem que você especifique os diretórios em que o compilador procurará arquivos de metadados referenciados.