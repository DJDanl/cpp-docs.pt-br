---
title: "&lt;consulte&gt; (Visual C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "<see>"
  - "see"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "marca XML C++ <see>"
  - "marca XML C++ see"
ms.assetid: 20ef66f4-b278-45cf-8613-63919edf5720
caps.latest.revision: 15
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# &lt;consulte&gt; (Visual C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A marca de \<see\> permite que você especifique um link de dentro do texto.  Use [\<seealso\>](../Topic/%3Cseealso%3E%20\(Visual%20C++\).md) para indicar que o texto que você pode querer aparecer na seção consulte consulte também.  
  
## Sintaxe  
  
```  
<see cref="member"/>  
```  
  
#### Parâmetros  
 `member`  
 Uma referência a um membro ou campo que está disponível para ser chamado a partir do ambiente de compilação atual.  Envolva\-o com aspas simples ou double \- marcas.  
  
 O compilador verifica se o elemento de código existe e resolve `member` o nome de elemento no XML.  O compilador emite um aviso se não encontrar `member`.  
  
## Comentários  
 Compile com [\/doc](../build/reference/doc-process-documentation-comments-c-cpp.md) para processar comentários de documentação para um arquivo.  
  
 Consulte [\<summary\>](../ide/summary-visual-cpp.md) para um exemplo de como usar \<see\>.  
  
 O compilador do Visual C\+\+ tentará resolver referências de cref em uma passagem com comentários de documentação.  Portanto, se usando as regras de pesquisa de C\+\+, um símbolo não for encontrado pelo compilador a referência não será marcada como resolvida.  Consulte [\<seealso\>](../Topic/%3Cseealso%3E%20\(Visual%20C++\).md) para maiores informações.  
  
## Exemplo  
 O exemplo a seguir mostra como você pode fazer a referência de cref a um tipo genérico, de forma que, o compilador resolverá a referência.  
  
```  
// xml_see_cref_example.cpp  
// compile with: /LD /clr /doc  
// the following cref shows how to specify the reference, such that,  
// the compiler will resolve the reference  
/// <see cref="C{T}">  
/// </see>  
ref class A {};  
  
// the following cref shows another way to specify the reference,   
// such that, the compiler will resolve the reference  
/// <see cref="C < T >"/>  
  
// the following cref shows how to hard-code the reference  
/// <see cref="T:C`1">  
/// </see>  
ref class B {};  
  
/// <see cref="A">  
/// </see>  
/// <typeparam name="T"></typeparam>  
generic<class T>  
ref class C {};  
```  
  
## Consulte também  
 [A Documentação XML](../ide/xml-documentation-visual-cpp.md)