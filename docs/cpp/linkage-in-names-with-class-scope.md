---
title: Ligação em nomes com escopo de classe | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- scope [C++], linkage rules
- linkage [C++], scope linkage rules
- names [C++], scope linkage rules
- classes [C++], scope
- external linkage, scope linkage rules
- class names [C++], linkage
- classes [C++], names
- scope [C++], class names
- class scope [C++], linkage in names with
ms.assetid: 45275ff3-6e94-4967-82c8-ba540ef4da28
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9eb58f87e998fbe1eeeb9b26eb0da75046a9079d
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32418966"
---
# <a name="linkage-in-names-with-class-scope"></a>Ligação em nomes com escopo de classe
As regras de vinculação a seguir se aplicam aos nomes com escopo de classe:  
  
-   Os membros da classe Static têm vinculação externa.  
  
-   As funções de membro da classe têm vinculação externa.  
  
-   Os enumeradores e os nomes `typedef` não têm vínculo.  
  
 **Seção específica da Microsoft**  
  
-   As funções declaradas como `friend` devem ter vinculação externa. Declarar uma função estática como `friend` gera um erro.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Programa e ligação](../cpp/program-and-linkage-cpp.md)