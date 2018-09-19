---
title: Declarações de função e definições | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- local declarations
- function definitions, function declarations
- declaring functions, function definitions
- internal declarations
- external declarations
- function prototypes, basics
- external linkage, function declarations
- declaring functions
ms.assetid: 43fd98eb-7441-4473-a5d9-fc88c75577f7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2bb5a6b1f184775b3e67a03b9544e609b33673ba
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46106112"
---
# <a name="function-declarations-and-definitions"></a>Declarações de função e definições

Os protótipos de função estabelecem o nome da função, seu tipo de retorno, o tipo e o número de seus parâmetros formais. Uma definição de função inclui o corpo da função.

## <a name="remarks"></a>Comentários

As declarações de função e de variável podem aparecer dentro ou fora de uma definição de função. Qualquer declaração dentro de uma definição de função é dita aparecer no nível “interno” ou “local”. Uma declaração fora de todas as definições de função é dita aparecer como “externa”, “global”, ou no nível do “escopo de arquivo”. As definições de variáveis, como declarações, podem aparecer no nível interno (dentro de uma definição de função) ou no nível externo (fora de todas as definições de função). As definições de função sempre ocorrem no nível externo. As definições de função são abordadas em mais detalhes em [Definições de função](../c-language/c-function-definitions.md). Os protótipos de função são abordados em [Protótipos de função](../c-language/function-prototypes.md).

## <a name="see-also"></a>Consulte também

[Arquivos e programas de origem](../c-language/source-files-and-source-programs.md)