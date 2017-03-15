---
title: "&lt;permiss&#227;o&gt; (Visual C++) | Microsoft Docs"
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
  - "permission"
  - "<permission>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "marca XML C++ <permission>"
  - "marca XML C++ permission"
ms.assetid: 537ee2bc-95bd-48e4-9ce6-3420c3da87f4
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# &lt;permiss&#227;o&gt; (Visual C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A marca de \<permission\> documentar permite o acesso de um membro.  <xref:System.Security.PermissionSet> permite que você especifique o acesso a um membro.  
  
## Sintaxe  
  
```  
<permission cref="member">description</permission>  
```  
  
#### Parâmetros  
 `member`  
 Uma referência a um membro ou campo que está disponível para ser chamado a partir do ambiente de compilação atual.  O compilador verifica se o elemento de código fornecido existe e converte `member` para o nome canônico de elemento na saída XML.  Envolva\-o com aspas simples ou double \- marcas.  
  
 O compilador emite um aviso se não encontrar `member`.  
  
 Para obter informações sobre como criar uma referência de cref a um tipo genérico, consulte [\<see\>](../ide/see-visual-cpp.md).  
  
 `description`  
 Uma descrição do acesso ao membro.  
  
## Comentários  
 Compile com [\/doc](../build/reference/doc-process-documentation-comments-c-cpp.md) para processar comentários de documentação para um arquivo.  
  
 O compilador do Visual C\+\+ tentará resolver referências de cref em uma passagem com comentários de documentação.  Portanto, se usando as regras de pesquisa de C\+\+, um símbolo não for encontrado pelo compilador a referência não será marcada como resolvida.  Consulte [\<seealso\>](../Topic/%3Cseealso%3E%20\(Visual%20C++\).md) para maiores informações.  
  
## Exemplo  
  
```  
// xml_permission_tag.cpp  
// compile with: /clr /doc /LD  
// post-build command: xdcmake xml_permission_tag.dll  
using namespace System;  
/// Text for class TestClass.  
public ref class TestClass {  
   /// <permission cref="System::Security::PermissionSet">Everyone can access this method.</permission>  
   void Test() {}  
};  
```  
  
## Consulte também  
 [A Documentação XML](../ide/xml-documentation-visual-cpp.md)