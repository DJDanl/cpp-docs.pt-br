---
title: '&lt;incluir&gt; (Visual C++) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- include
- <include>
dev_langs: C++
helpviewer_keywords:
- include C++ XML tag
- <include> C++ XML tag
ms.assetid: 392a3e61-0371-4617-8362-446650876ce3
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f9a6b07ce540d67a44e46a24fb943dac93bb95a4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ltincludegt-visual-c"></a>&lt;incluir&gt; (Visual C++)
A marca \<include> permite consultar comentários em outro arquivo que descrevem os tipos e membros em seu código-fonte. Essa é uma alternativa para inserir comentários de documentação diretamente em seu arquivo de código-fonte.  Por exemplo, você pode usar \<incluem > inserir comentários "boilerplate" padrão que são usados em toda a sua equipe ou da empresa.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
<include file='filename' path='tagpath' />  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `filename`  
 O nome do arquivo que contém a documentação. O nome do arquivo pode ser qualificado com um caminho.  Coloque o nome entre aspas simples ou duplas.  O compilador emite um aviso se ele não encontrar `filename`.  
  
 `tagpath`  
 Uma expressão XPath válida que seleciona o nó-conjunto desejado contido no arquivo.  
  
 `name`  
 O especificador de nome na marca que precede os comentários; `name` terá um `id`.  
  
 `id`  
 A ID da marca que precede os comentários.  Coloque o nome entre aspas simples ou duplas.  
  
## <a name="remarks"></a>Comentários  
 A marca \<include> usa a sintaxe XML XPath. Consulte a documentação do XPath para maneiras de personalizar usando \<incluem >.  
  
 Compile com [/doc](../build/reference/doc-process-documentation-comments-c-cpp.md) para processar comentários de documentação em um arquivo.  
  
## <a name="example"></a>Exemplo  
 Este é um exemplo de vários arquivos. O primeiro arquivo usa \<incluem >, contém os comentários de documentação a seguir:  
  
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
  
 O segundo arquivo, xml_include_tag.doc, contém os comentários de documentação a seguir:  
  
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
  
## <a name="program-output"></a>Saída do Programa  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Documentação XML](../ide/xml-documentation-visual-cpp.md)