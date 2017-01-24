---
title: "&lt;resumo&gt; (Visual C++) | Microsoft Docs"
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
  - "<summary>"
  - "summary"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "marca XML C++ <summary>"
  - "marca XML C++ summary"
ms.assetid: cdeeefbb-1339-45d6-9002-10042a9a2726
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# &lt;resumo&gt; (Visual C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A marca de \<summary\> deve ser usada para descrever um tipo ou membro de tipo.  Use [\<remarks\>](../ide/remarks-visual-cpp.md) para adicionar informações suplementares a uma descrição de tipo.  
  
## Sintaxe  
  
```  
<summary>description</summary>  
```  
  
#### Parâmetros  
 `description`  
 Um resumo do objeto.  
  
## Comentários  
 O texto para a marca de \<summary\> é a única ofnte de informações sobre o tipo IntelliSense, e também é exibido em [Pesquisador de objetos](http://msdn.microsoft.com/pt-br/f89acfc5-1152-413d-9f56-3dc16e3f0470) e no relatório da Web de comentário de código.  
  
 Compile com [\/doc](../build/reference/doc-process-documentation-comments-c-cpp.md) para processar comentários de documentação para um arquivo.  
  
## Exemplo  
  
```  
// xml_summary_tag.cpp  
// compile with: /LD /clr /doc  
// post-build command: xdcmake xml_summary_tag.dll  
  
/// Text for class MyClass.  
public ref class MyClass {  
public:  
   /// <summary>MyMethod is a method in the MyClass class.  
   /// <para>Here's how you could make a second paragraph in a description. <see cref="System::Console::WriteLine"/> for information about output statements.</para>  
   /// <seealso cref="MyClass::MyMethod2"/>  
   /// </summary>  
   void MyMethod(int Int1) {}  
  
   /// text  
   void MyMethod2() {}  
};  
```  
  
## Consulte também  
 [A Documentação XML](../ide/xml-documentation-visual-cpp.md)