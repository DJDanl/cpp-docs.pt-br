---
title: '> de valor deC++ &lt;(comentários de documentação)'
ms.date: 11/04/2016
f1_keywords:
- value
- <value>
helpviewer_keywords:
- value C++ XML tag
- <value> C++ XML tag
ms.assetid: 0ba0a0d5-bcd7-4862-a169-83f2721ad80e
ms.openlocfilehash: de84d1faca59a6c8e4f82fba3605cbd54a05bd2e
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74988600"
---
# <a name="ltvaluegt"></a>&lt;value&gt;

A marcação \<value> permite descrever uma propriedade e os métodos do acessador de propriedade. Observe que, quando você adicionar uma propriedade com um assistente de código no ambiente de desenvolvimento integrado do Visual Studio, ele adicionará uma marcação [\<summary>](summary-visual-cpp.md) à nova propriedade. Então, você deve adicionar manualmente uma marca \<value> para descrever o valor que a propriedade representa.

## <a name="syntax"></a>Sintaxe

```
<value>property-description</value>
```

#### <a name="parameters"></a>Parâmetros

*property-description*<br/>
Uma descrição da propriedade.

## <a name="remarks"></a>Comentários

Compile com [/doc](doc-process-documentation-comments-c-cpp.md) para processar comentários de documentação em um arquivo.

## <a name="example"></a>Exemplo

```cpp
// xml_value_tag.cpp
// compile with: /LD /clr /doc
// post-build command: xdcmake xml_value_tag.dll
using namespace System;
/// Text for class Employee.
public ref class Employee {
private:
   String ^ name;
   /// <value>Name accesses the value of the name data member</value>
public:
   property String ^ Name {
      String ^ get() {
         return name;
      }
      void set(String ^ i) {
         name = i;
      }
   }
};
```

## <a name="see-also"></a>Consulte também

[Documentação XML](xml-documentation-visual-cpp.md)
