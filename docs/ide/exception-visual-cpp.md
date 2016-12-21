---
title: "&lt;exce&#231;&#227;o&gt; (Visual C++) | Microsoft Docs"
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
  - "exception"
  - "<exception>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "marca XML C++ <exception>"
  - "marca XML C++ exception"
ms.assetid: 24451e79-9b89-4b77-98fb-702c6516b818
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# &lt;exce&#231;&#227;o&gt; (Visual C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A marca de \<exception\> permite que você especifique que exceções podem ser geradas.  Essa marca é aplicada a uma definição de método.  
  
## Sintaxe  
  
```  
<exception cref="member">description</exception>  
```  
  
#### Parâmetros  
 `member`  
 Uma referência a uma exceção que está disponível no ambiente de compilação atual.  Usando regras de pesquisa de nome, o compilador verifica se a exceção determinada existir, e converte `member` para o nome canônico de elemento na saída XML.  O compilador emite um aviso se não encontrar `member`.  
  
 Envolva\-o com aspas simples ou double \- marcas.  
  
 Para obter informações sobre como criar uma referência de cref a um tipo genérico, consulte [\<see\>](../ide/see-visual-cpp.md).  
  
 `description`  
 Uma descrição.  
  
## Comentários  
 Compile com [\/doc](../build/reference/doc-process-documentation-comments-c-cpp.md) para processar comentários de documentação para um arquivo.  
  
 O compilador do Visual C\+\+ tentará resolver referências de cref em uma passagem com comentários de documentação.  Portanto, se usando as regras de pesquisa de C\+\+, um símbolo não for encontrado pelo compilador a referência não será marcada como resolvida.  Consulte [\<seealso\>](../Topic/%3Cseealso%3E%20\(Visual%20C++\).md) para maiores informações.  
  
## Exemplo  
  
```  
// xml_exception_tag.cpp  
// compile with: /clr /doc /LD  
// post-build command: xdcmake xml_exception_tag.dll  
using namespace System;  
  
/// Text for class EClass.  
public ref class EClass : public Exception {  
   // class definition ...  
};  
  
/// <exception cref="System.Exception">Thrown when... .</exception>  
public ref class TestClass {  
   void Test() {  
      try {  
      }  
      catch(EClass^) {  
      }  
   }  
};  
```  
  
## Consulte também  
 [A Documentação XML](../ide/xml-documentation-visual-cpp.md)