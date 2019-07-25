---
title: Usando operadores de extração
ms.date: 11/04/2016
helpviewer_keywords:
- extraction operators [C++]
- '&gt;&gt; operator [C++], extraction operators'
- operators [C++], extraction
ms.assetid: a961e1a9-4897-41de-b210-89d5b2d051ae
ms.openlocfilehash: 7950984973f8df236905128ce4b5336ecb874b7f
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68458033"
---
# <a name="using-extraction-operators"></a>Usando operadores de extração

O operador de extração (`>>`), que é previamente programado para todos os tipos de dados padrão do C++, é a maneira mais fácil de obter bytes de um objeto de fluxo de entrada.

Operadores de extração de entrada de texto formatado dependem de espaço em branco para separar os valores de dados de entrada. Isso é inconveniente quando um campo de texto contém várias palavras ou números separados por vírgulas. Nesse caso, uma alternativa é usar a função membro de entrada não formatada [istream::getline](../standard-library/basic-istream-class.md#getline) para ler um bloco de texto com espaço em branco incluído e, em seguida, analisar o bloco com funções especiais. Outro método é derivar uma classe de fluxo de entrada com uma função membro, como `GetNextToken`, que pode chamar membros istream para extrair e formatar os dados de caractere.

## <a name="see-also"></a>Consulte também

[Fluxos de entrada](../standard-library/input-streams.md)
