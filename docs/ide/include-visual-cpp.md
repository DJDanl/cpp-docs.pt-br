---
title: "&lt;incluir&gt; (Visual C++) | Microsoft Docs"
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
  - "include"
  - "<include>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "marca XML C++ <include>"
  - "marca XML C++ include"
ms.assetid: 392a3e61-0371-4617-8362-446650876ce3
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# &lt;incluir&gt; (Visual C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A marca de \<include\> permite consultar os comentários em outro arquivo que descrevem os tipos e membros no código\-fonte.  Esta é uma alternativa para colocar comentários de documentação diretamente no seu arquivo de código\-fonte.  Por exemplo, você pode usar \<include\> para inserir comentários padrão “texto” constante que são usados em toda sua equipe ou empresa.  
  
## Sintaxe  
  
```  
<include file='filename' path='tagpath' />  
```  
  
#### Parâmetros  
 `filename`  
 O nome do arquivo que contém documentação.  O nome de arquivo pode ser qualificada com um caminho.  Envolva\-o com aspas simples ou double \- marcas.  O compilador emite um aviso se não encontrar `filename`.  
  
 `tagpath`  
 Uma expressão XPath válida que seleciona desejado nó\- definido contido no arquivo.  
  
 `name`  
 O especificador do nome na marca que precede comentários; `name` terá `id`.  
  
 `id`  
 O ID para a marca que precede comentários.  Envolva\-o com aspas simples ou double \- marcas.  
  
## Comentários  
 A marca de \<include\> usa a sintaxe XPath XML.  Consulte a documentação XPath para que as maneiras personalizem usando \<include\>.  
  
 Compile com [\/doc](../build/reference/doc-process-documentation-comments-c-cpp.md) para processar comentários de documentação para um arquivo.  
  
## Exemplo  
 Este é um exemplo de arquivos múltiplos.  O primeiro arquivo, que usa \<include\>, contém os seguintes comentários de documentação:  
  
```  
// xml_include_tag.cpp  
// compile with: /clr /doc /LD  
// post-build command: xdcmake xml_include_tag.dll  
  
/// <include file='xml_include_tag.doc' path='MyDocs/MyMembers[@name="test"]/*' />  
public ref class Test {  
   void TestMethod() {  
   }  
};  
  
/// <include file='xml_include_tag.doc' path='MyDocs/MyMembers[@name="test2"]/*' />  
public ref class Test2 {  
   void Test() {  
   }  
};  
```  
  
 O segundo arquivo, xml\_include\_tag.doc, contém os seguintes comentários de documentação:  
  
```  
<MyDocs>  
  
<MyMembers name="test">  
<summary>  
The summary for this type.  
</summary>  
</MyMembers>  
  
<MyMembers name="test2">  
<summary>  
The summary for this other type.  
</summary>  
</MyMembers>  
  
</MyDocs>  
```  
  
## Saída do programa  
  
```  
<?xml version="1.0"?>  
<doc>  
    <assembly>  
        <name>t2</name>  
    </assembly>  
    <members>  
        <member name="T:Test">  
            <summary>  
The summary for this type.  
</summary>  
        </member>  
        <member name="T:Test2">  
            <summary>  
The summary for this other type.  
</summary>  
        </member>  
    </members>  
</doc>  
```  
  
## Consulte também  
 [A Documentação XML](../ide/xml-documentation-visual-cpp.md)