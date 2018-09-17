---
title: Regras para instruções de definição de módulo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- .def
dev_langs:
- C++
helpviewer_keywords:
- module definition files, statement syntax
- module definition files
ms.assetid: f65cd3a7-65d7-4d06-939f-a8b1ecd50f2d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a31927bb1ce3667367eff8f38268b4b3b24ac82c
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45726473"
---
# <a name="rules-for-module-definition-statements"></a>Regras para instruções de definição do módulo

As regras de sintaxe a seguir se aplicam a todas as instruções em um arquivo. def. Outras regras que se aplicam a instruções específicas são descritas com cada instrução.

- Instruções, palavras-chave de atributo e identificadores especificados pelo usuário diferenciam maiusculas de minúsculas.

- Arquivo extensos nomes que contêm espaços ou ponto e vírgula (;) devem ser colocados entre aspas (").

- Use um ou mais espaços, tabulações ou caracteres de nova linha para separar uma palavra-chave de instrução de seus argumentos e para separar instruções uns dos outros. Dois-pontos (:) ou sinal de igual (=) que designa um argumento está circundada por zero ou mais espaços, tabulações ou caracteres de nova linha.

- Um **nome** ou **biblioteca** instrução, se usado, deve preceder todas as outras instruções.

- O **seções** e **exportações** instruções podem aparecer mais de uma vez no arquivo. def. Cada instrução pode levar várias especificações, que devem ser separadas por um ou mais espaços, tabulações ou caracteres de nova linha. A palavra-chave de instrução deve aparecer uma vez antes da primeira especificação e pode ser repetida antes de cada uma especificação adicional.

- Muitas instruções têm uma opção de linha de comando equivalente do LINK. Consulte a descrição da opção LINK correspondente para obter mais detalhes.

- Comentários no arquivo. def são designados por um ponto e vírgula (;) no início de cada linha de comentário. Um comentário não pode compartilhar uma linha com uma instrução, mas ela pode aparecer entre as especificações em uma instrução de várias linhas. (**Seções** e **exportações** são instruções de várias linhas.)

- Argumentos numéricos que são especificados na base 10 ou hexadecimal.

- Se um argumento de cadeia de caracteres corresponde a um [palavra reservada](../../build/reference/reserved-words.md), ele deve estar entre aspas duplas (").

## <a name="see-also"></a>Consulte também

[Arquivos de definição do módulo (.Def)](../../build/reference/module-definition-dot-def-files.md)