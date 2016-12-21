---
title: "Liga&#231;&#227;o em nomes com escopo de arquivo | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "declarações [C++], externo"
  - "vinculação externa, regras de vinculação de escopo"
  - "escopo de arquivo [C++]"
  - "vinculação [C++], regras de vinculação de escopo"
  - "nomes [C++], regras de vinculação de escopo"
  - "escopo [C++], regras de vinculação"
  - "modificador estático, escopo de arquivo"
  - "nomes estáticos e escopo de arquivo"
  - "variáveis estáticas, declarações externas"
ms.assetid: 38d3fa5e-1861-466e-a590-84b86f7b184e
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Liga&#231;&#227;o em nomes com escopo de arquivo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As seguintes regras de vinculação se aplicam a nomes \(diferentes de `typedef` e nomes de enumeradores\) com escopo de arquivo:  
  
-   Se um nome for declarado explicitamente como **static**, ele terá vinculação interna e identificará um elemento do programa dentro de sua própria unidade de conversão.  
  
-   Os nomes de enumeradores e nomes de `typedef` não têm vínculo.  
  
-   Todos os outros nomes com escopo de arquivo têm vinculação externa.  
  
 **Específico da Microsoft**  
  
-   Se um nome de função com escopo de arquivo for declarado explicitamente como **inline**, ele terá vinculação externa se for instanciado ou se seu endereço for referenciado.  Portanto, é possível para uma função com escopo de arquivo ter vinculação interna ou externa.  
  
 **FIM de Específico da Microsoft**  
  
 Uma classe tem vinculação interna se:  
  
-   Não usa funcionalidade C\+\+ \(por exemplo, controle de acesso de membros, funções de membro, construtores, destruidores, e assim por diante\).  
  
-   Não é usada na declaração de outro nome que tem vinculação externa.  Essa restrição significa que os objetos de tipo de classe que são passados para as funções com vinculação externa faz com que a classe tenha vinculação externa.  
  
## Consulte também  
 [Programa e ligação](../cpp/program-and-linkage-cpp.md)