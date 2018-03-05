---
title: "Ligação em nomes com escopo de arquivo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- scope [C++], linkage rules
- linkage [C++], scope linkage rules
- names [C++], scope linkage rules
- static modifier, file scope
- static names and file scope
- file scope [C++]
- declarations [C++], external
- external linkage, scope linkage rules
- static variables, external declarations
ms.assetid: 38d3fa5e-1861-466e-a590-84b86f7b184e
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 581d7798f4f3aaa409d843f8b7f3b5869b47407e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linkage-in-names-with-file-scope"></a>Ligação em nomes com escopo de arquivo
As seguintes regras de vinculação se aplicam a nomes (diferentes de `typedef` e nomes de enumeradores) com escopo de arquivo:  
  
-   Se um nome for declarado explicitamente como **estático**, ele tem vinculação interna e identifica um elemento do programa dentro de sua própria unidade de tradução.  
  
-   Os nomes de enumeradores e nomes de `typedef` não têm vínculo.  
  
-   Todos os outros nomes com escopo de arquivo têm vinculação externa.  
  
 **Seção específica da Microsoft**  
  
-   Se um nome de função com escopo de arquivo é declarado explicitamente como **embutido**, ele tem vinculação externa se ele é instanciado ou seu endereço é referenciado. Portanto, é possível para uma função com escopo de arquivo ter vinculação interna ou externa.  
  
 **Fim da seção específica da Microsoft**  
  
 Uma classe tem vinculação interna se:  
  
-   Não usa funcionalidade C++ (por exemplo, controle de acesso de membros, funções de membro, construtores, destruidores, e assim por diante).  
  
-   Não é usada na declaração de outro nome que tem vinculação externa. Essa restrição significa que os objetos de tipo de classe que são passados para as funções com vinculação externa faz com que a classe tenha vinculação externa.  
  
## <a name="see-also"></a>Consulte também  
 [Programa e ligação](../cpp/program-and-linkage-cpp.md)