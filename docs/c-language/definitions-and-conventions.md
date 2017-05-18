---
title: "Definições e convenções | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- nonterminals definition
ms.assetid: f9b3cf5f-6a7c-4a10-9b18-9d4a43efdaeb
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
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
ms.translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 8fe7870b6e2477b9f1ea27605302e8c5c7f80928
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="definitions-and-conventions"></a>Definições e convenções
Os terminais são pontos de extremidade em uma definição de sintaxe. Nenhuma outra resolução é possível. Os terminais incluem o conjunto de palavras reservadas e identificadores definidos pelo usuário.  
  
 Os não terminais são espaços reservados na sintaxe e são definidos em outra parte deste resumo da sintaxe. As definições podem ser recursivas.  
  
 Um componente opcional é indicado pelo aceitação subscrita. Por exemplo,  
  
```  
  
{  
expression <SUB>opt</SUB> }  
```  
  
 indica uma expressão opcional entre chaves.  
  
 As convenções de sintaxe usam atributos diferentes de fonte para componentes diferentes de sintaxe. Os símbolos e as fontes são os seguintes:  
  
|Atributo|Descrição|  
|---------------|-----------------|  
|*nonterminal*|O tipo em itálico indica não terminais.|  
|**const**|Os terminais de tipo em negrito são palavras reservadas a literais e símbolos que devem ser inseridos como mostrado. Os caracteres nesse contexto sempre diferenciam maiúsculas de minúsculas.|  
|opt|Não terminais seguidos por opt são sempre opcionais.|  
|default typeface|Os caracteres no conjunto listados ou descritos nesta face de tipos podem ser usados como terminais em instruções de C.|  
  
 Um sinal de dois pontos (**:**) depois de um não terminal introduz sua definição. Definições alternativas estão listadas em linhas separadas, exceto quando prefaciadas com as palavras "um de".  
  
## <a name="see-also"></a>Consulte também  
 [Resumo da sintaxe da linguagem C](../c-language/c-language-syntax-summary.md)
