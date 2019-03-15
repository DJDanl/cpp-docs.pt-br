---
title: '&lt;c > (comentários de documentação do C++)'
ms.date: 11/04/2016
f1_keywords:
- <c>
helpviewer_keywords:
- <c> C++ XML tag
- c C++ XML tag
ms.assetid: 3b23fc0f-e10d-4dd0-b197-48a46cbddd9f
ms.openlocfilehash: 43e1417e5a749f2ea51346bbf6db235ba08a7bcf
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824263"
---
# <a name="ltcgt"></a>&lt;c&gt;

A marcação \<c> indica que o texto dentro de uma descrição deve ser marcado como código. Use [\<code>](code-visual-cpp.md) para indicar várias linhas como código.

## <a name="syntax"></a>Sintaxe

```
<c>text</c>
```

#### <a name="parameters"></a>Parâmetros

*text*<br/>
O texto que você deseja indicar como código.

## <a name="remarks"></a>Comentários

Compile com [/doc](doc-process-documentation-comments-c-cpp.md) para processar comentários de documentação em um arquivo.

## <a name="example"></a>Exemplo

```cpp
// xml_c_tag.cpp
// compile with: /doc /LD
// post-build command: xdcmake xml_c_tag.xdc

/// Text for class MyClass.
class MyClass {
public:
   int m_i;
   MyClass() : m_i(0) {}

   /// <summary><c>MyMethod</c> is a method in the <c>MyClass</c> class.
   /// </summary>
   int MyMethod(MyClass * a) {
      return a -> m_i;
   }
};
```

## <a name="see-also"></a>Consulte também

[Documentação XML](xml-documentation-visual-cpp.md)
