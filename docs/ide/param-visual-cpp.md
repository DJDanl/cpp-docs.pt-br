---
title: '&lt;param&gt; (Visual C++)'
ms.date: 11/04/2016
f1_keywords:
- param
- <param>
helpviewer_keywords:
- param C++ XML tag
- <param> C++ XML tag
ms.assetid: 66c1a1c3-4f98-4bcf-8c7d-9a40308982fb
ms.openlocfilehash: ec570a1c8b66e12474a2d960ed1b4f4b5e21b219
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50651328"
---
# <a name="ltparamgt-visual-c"></a>&lt;param&gt; (Visual C++)

A marca \<param> deve ser usada no comentário para uma declaração de método para descrever um dos parâmetros do método.

## <a name="syntax"></a>Sintaxe

```
<param name='name'>description</param>
```

#### <a name="parameters"></a>Parâmetros

*name*<br/>
O nome do parâmetro de um método.  Coloque o nome entre aspas simples ou duplas.  O compilador emite um aviso se não encontra `name`.

*description*<br/>
Uma descrição do parâmetro.

## <a name="remarks"></a>Comentários

O texto da marcação \<param> será exibido no IntelliSense, no [Pesquisador de Objetos](/visualstudio/ide/viewing-the-structure-of-code) e no relatório Web de comentários sobre código.

Compile com [/doc](../build/reference/doc-process-documentation-comments-c-cpp.md) para processar comentários de documentação em um arquivo.

## <a name="example"></a>Exemplo

```cpp
// xml_param_tag.cpp
// compile with: /clr /doc /LD
// post-build command: xdcmake xml_param_tag.dll
/// Text for class MyClass.
public ref class MyClass {
   /// <param name="Int1">Used to indicate status.</param>
   void MyMethod(int Int1) {
   }
};
```

## <a name="see-also"></a>Consulte também

[Documentação XML](../ide/xml-documentation-visual-cpp.md)