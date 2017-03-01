---
title: "Usando operadores de extração | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- extraction operators
- '>> operator, extraction operators'
- operators [C++], extraction
ms.assetid: a961e1a9-4897-41de-b210-89d5b2d051ae
caps.latest.revision: 8
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
ms.sourcegitcommit: 85c900f2263ae1c1089478badc85388e3b5e8548
ms.openlocfilehash: e5dcc1e57b807ee7ff7b4292f31563d4041c0bdd
ms.lasthandoff: 02/25/2017

---
# <a name="using-extraction-operators"></a>Usando operadores de extração
O operador de extração (`>>`), que é previamente programado para todos os tipos de dados padrão do C++, é a maneira mais fácil de obter bytes de um objeto de fluxo de entrada.  
  
 Operadores de extração de entrada de texto formatado dependem de espaço em branco para separar os valores de dados de entrada. Isso é inconveniente quando um campo de texto contém várias palavras ou números separados por vírgulas. Nesse caso, uma alternativa é usar a função membro de entrada não formatada [istream::getline](../standard-library/basic-istream-class.md#basic_istream__getline) para ler um bloco de texto com espaço em branco incluído e, em seguida, analisar o bloco com funções especiais. Outro método é derivar uma classe de fluxo de entrada com uma função membro, como `GetNextToken`, que pode chamar membros istream para extrair e formatar os dados de caractere.  
  
## <a name="see-also"></a>Consulte também  
 [Fluxos de entrada](../standard-library/input-streams.md)


