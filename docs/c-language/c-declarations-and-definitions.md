---
title: Declarações e definições C | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: 575f0c9b-5554-4346-be64-b2129ca9227f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c459999ab902a2498d4ffe4cc2d437a0a432b9b7
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32381559"
---
# <a name="c-declarations-and-definitions"></a>Declarações e definições C
Uma "declaração" estabelece uma associação entre uma variável, uma função ou um tipo específico e os respectivos atributos. A [visão geral das declarações](../c-language/overview-of-declarations.md) apresenta a sintaxe ANSI para o não terminal `declaration`. Uma declaração também especifica onde e quando um identificador pode ser acessado (a "vinculação" de um identificador). Consulte [Tempo de vida, escopo, visibilidade e vinculação](../c-language/lifetime-scope-visibility-and-linkage.md) para obter informações sobre vinculação.  
  
 Uma "definição" de uma variável estabelece as mesmas associações que uma declaração, mas também faz com que ocorra a alocação de armazenamento para a variável.  
  
 Por exemplo, as funções `main`, `find` e `count` e as variáveis `var` e `val` são definidas em um arquivo de origem, nesta ordem:  
  
```  
int main() {}  
  
int var = 0;  
double val[MAXVAL];  
char find( fileptr ) {}  
int count( double f ) {}  
```  
  
 As variáveis `var` e `val` podem ser usadas nas funções `find` e `count`; nenhuma declaração adicional é necessária. Porém, esses nomes não são visíveis (não podem ser acessados) em `main`.  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos e programas de origem](../c-language/source-files-and-source-programs.md)