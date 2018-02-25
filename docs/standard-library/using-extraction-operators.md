---
title: "Usando operadores de extração | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- extraction operators [C++]
- '&gt;&gt; operator [C++], extraction operators'
- operators [C++], extraction
ms.assetid: a961e1a9-4897-41de-b210-89d5b2d051ae
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: bb9e62ffd1e466fd220012717e278b79bbce3e1f
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="using-extraction-operators"></a>Usando operadores de extração
O operador de extração (`>>`), que é previamente programado para todos os tipos de dados padrão do C++, é a maneira mais fácil de obter bytes de um objeto de fluxo de entrada.  
  
 Operadores de extração de entrada de texto formatado dependem de espaço em branco para separar os valores de dados de entrada. Isso é inconveniente quando um campo de texto contém várias palavras ou números separados por vírgulas. Nesse caso, uma alternativa é usar a função membro de entrada não formatada [istream::getline](../standard-library/basic-istream-class.md#getline) para ler um bloco de texto com espaço em branco incluído e, em seguida, analisar o bloco com funções especiais. Outro método é derivar uma classe de fluxo de entrada com uma função membro, como `GetNextToken`, que pode chamar membros istream para extrair e formatar os dados de caractere.  
  
## <a name="see-also"></a>Consulte também  
 [Fluxos de entrada](../standard-library/input-streams.md)

