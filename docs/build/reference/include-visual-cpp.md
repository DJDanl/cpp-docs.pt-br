---
title: '&lt;incluir > (comentários de documentação do C++)'
ms.date: 11/04/2016
f1_keywords:
- include
- <include>
helpviewer_keywords:
- include C++ XML tag
- <include> C++ XML tag
ms.assetid: 392a3e61-0371-4617-8362-446650876ce3
ms.openlocfilehash: b7d1033aa5b6c95c0db8eb9debf74596dc214fb0
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824418"
---
# <a name="ltincludegt"></a>&lt;include&gt;

A marca \<include> permite consultar comentários em outro arquivo que descrevem os tipos e membros em seu código-fonte. Essa é uma alternativa para inserir comentários de documentação diretamente em seu arquivo de código-fonte.  Por exemplo, use \<include> para inserir comentários "clichê" padrão usados por toda a equipe ou empresa.

## <a name="syntax"></a>Sintaxe

```
<include file='filename' path='tagpath' />
```

#### <a name="parameters"></a>Parâmetros

*filename*<br/>
O nome do arquivo que contém a documentação. O nome do arquivo pode ser qualificado com um caminho.  Coloque o nome entre aspas simples ou duplas.  O compilador emite um aviso se não encontra `filename`.

*tagpath*<br/>
Uma expressão XPath válida que seleciona o conjunto de nós desejado contido no arquivo.

*name*<br/>
O especificador de nome na marca que precede os comentários; `name` terá um `id`.

*id*<br/>
A ID da marca que precede os comentários.  Coloque o nome entre aspas simples ou duplas.

## <a name="remarks"></a>Comentários

A marca \<include> usa a sintaxe XML XPath. Veja a documentação do XPath para descobrir outras formas de personalização usando \<include>.

Compile com [/doc](doc-process-documentation-comments-c-cpp.md) para processar comentários de documentação em um arquivo.

## <a name="example"></a>Exemplo

Este é um exemplo de vários arquivos. O primeiro arquivo, que usa \<include>, contém os seguintes comentários da documentação:

```cpp
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

```xml
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

```xml
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

[Documentação XML](xml-documentation-visual-cpp.md)
