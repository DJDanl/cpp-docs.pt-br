---
title: '&lt;Resumo > (comentários de documentação do C++)'
ms.date: 11/04/2016
f1_keywords:
- <summary>
- summary
helpviewer_keywords:
- <summary> C++ XML tag
- summary C++ XML tag
ms.assetid: cdeeefbb-1339-45d6-9002-10042a9a2726
ms.openlocfilehash: 68bb8b7c269b3406438e5cf21dde7179f7e67646
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62318180"
---
# <a name="ltsummarygt"></a>&lt;summary&gt;

A marca \<summary> deve ser usada para descrever um tipo ou um membro de tipo. Use [\<remarks>](remarks-visual-cpp.md) para adicionar mais informações a uma descrição de tipo.

## <a name="syntax"></a>Sintaxe

```
<summary>description</summary>
```

#### <a name="parameters"></a>Parâmetros

*description*<br/>
Um resumo do objeto.

## <a name="remarks"></a>Comentários

O texto da marcação \<summary> é a única fonte de informações sobre o tipo no IntelliSense e também é exibido no [Pesquisador de Objetos](/visualstudio/ide/viewing-the-structure-of-code) e no relatório Web de comentários sobre código.

Compile com [/doc](doc-process-documentation-comments-c-cpp.md) para processar comentários de documentação em um arquivo.

## <a name="example"></a>Exemplo

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

## <a name="see-also"></a>Consulte também

[Documentação XML](xml-documentation-visual-cpp.md)
