---
title: '&lt;paramref > (comentários de documentação do C++)'
ms.date: 11/04/2016
f1_keywords:
- paramref
- <paramref>
helpviewer_keywords:
- paramref C++ XML tag
- <paramref> C++ XML tag
ms.assetid: c5730dc2-7159-421f-b2d5-bb971e307122
ms.openlocfilehash: cee35ddb5fd5cd811e45f0aa49e94dd9c4b8b180
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62319987"
---
# <a name="ltparamrefgt"></a>&lt;paramref&gt;

A marcação \<paramref> fornece uma maneira para indicar que uma palavra é um parâmetro. O arquivo .xml pode ser processado para formatar esse parâmetro de uma forma distinta.

## <a name="syntax"></a>Sintaxe

```
<paramref name="name"/>
```

#### <a name="parameters"></a>Parâmetros

*name*<br/>
O nome do parâmetro ao qual você deseja se referir.  Coloque o nome entre aspas simples ou duplas.  O compilador emite um aviso se não encontra `name`.

## <a name="remarks"></a>Comentários

Compile com [/doc](doc-process-documentation-comments-c-cpp.md) para processar comentários de documentação em um arquivo.

## <a name="example"></a>Exemplo

```
// xml_paramref_tag.cpp
// compile with: /clr /doc /LD
// post-build command: xdcmake xml_paramref_tag.dll
/// Text for class MyClass.
public ref class MyClass {
   /// <summary>MyMethod is a method in the MyClass class.
   /// The <paramref name="Int1"/> parameter takes a number.
   /// </summary>
   void MyMethod(int Int1) {}
};
```

## <a name="see-also"></a>Consulte também

[Documentação XML](xml-documentation-visual-cpp.md)
