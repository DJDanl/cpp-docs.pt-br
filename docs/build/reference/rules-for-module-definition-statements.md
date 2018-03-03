---
title: "Regras para instruções de definição de módulo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- .def
dev_langs:
- C++
helpviewer_keywords:
- module definition files, statement syntax
- module definition files
ms.assetid: f65cd3a7-65d7-4d06-939f-a8b1ecd50f2d
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 40eb4875b195871aff8d274667e005d63424a110
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="rules-for-module-definition-statements"></a>Regras para instruções de definição do módulo
As regras de sintaxe a seguir se aplicam a todas as instruções em um arquivo. def. Outras regras que se aplicam a instruções específicas são descritas com cada instrução.  
  
-   Instruções, palavras-chave do atributo e identificadores especificado pelo usuário diferenciam maiusculas de minúsculas.  
  
-   Arquivo extensos nomes que contêm espaços ou ponto e vírgula (;) devem ser colocados entre aspas (").  
  
-   Use um ou mais espaços, tabulações ou caracteres de nova linha para separar uma palavra-chave de instrução de seus argumentos e para separar instruções uns dos outros. Dois-pontos (:) ou sinal de igual (=) que designa um argumento está circundada por zero ou mais espaços, tabulações ou caracteres de nova linha.  
  
-   Um **nome** ou **biblioteca** instrução, se usado, deve preceder todas as outras instruções.  
  
-   O **seções** e **exportações** instruções podem aparecer mais de uma vez no arquivo. def. Cada instrução pode levar várias especificações, que devem ser separadas por um ou mais espaços, tabulações ou caracteres de nova linha. A palavra-chave de instrução deve aparecer uma vez antes da primeira especificação e pode ser repetida antes de cada especificação adicional.  
  
-   Muitas instruções tem uma opção de linha de comando equivalente do LINK. Consulte a descrição da opção de LINK correspondente para obter detalhes adicionais.  
  
-   Comentários no arquivo. def são designados por um ponto e vírgula (;) no início de cada linha de comentário. Um comentário não pode compartilhar uma linha com uma instrução, mas ele pode aparecer entre especificações em uma instrução de várias linhas. (**Seções** e **exportações** são instruções multilinha.)  
  
-   Todos os argumentos são especificados na base 10 ou hexadecimal.  
  
-   Se um argumento de cadeia de caracteres corresponder um [palavra reservada](../../build/reference/reserved-words.md), ele deve estar entre aspas duplas (").  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos de definição do módulo (.Def)](../../build/reference/module-definition-dot-def-files.md)  