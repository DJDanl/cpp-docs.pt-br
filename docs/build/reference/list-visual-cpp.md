---
title: '&lt;lista > (comentários de documentação do C++)'
ms.date: 11/04/2016
f1_keywords:
- list
- <list>
helpviewer_keywords:
- list C++ XML tag
- <list> C++ XML tag
ms.assetid: c792a10b-0451-422c-9aa0-604116e69d64
ms.openlocfilehash: fd5b97ac518bc4075697da7b6ed88ed46bdd8814
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824598"
---
# <a name="ltlistgt"></a>&lt;list&gt;

O bloco \<listheader> é usado para definir a linha de cabeçalho de uma tabela ou lista de definição. Ao definir uma tabela, é necessário fornecer uma entrada para o termo no título.

## <a name="syntax"></a>Sintaxe

```
<list type="bullet" | "number" | "table">
   <listheader>
      <term>term</term>
      <description>description</description>
   </listheader>
   <item>
      <term>term</term>
      <description>description</description>
   </item>
</list>
```

#### <a name="parameters"></a>Parâmetros

*term*<br/>
Um termo a se definir, que será definido em `description`.

*description*<br/>
Um item em uma lista com marcadores ou numerada ou uma definição de um `term`.

## <a name="remarks"></a>Comentários

Cada item na lista é especificado com um bloco \<item>. Ao criar uma lista de definições, é necessário especificar `term` e `description`. No entanto, para uma tabela, lista com marcadores ou lista numerada, será necessário fornecer apenas uma entrada para `description`.

Uma lista ou tabela pode ter quantos blocos \<item> forem necessários.

Compile com [/doc](doc-process-documentation-comments-c-cpp.md) para processar comentários de documentação em um arquivo.

## <a name="example"></a>Exemplo

```cpp
// xml_list_tag.cpp
// compile with: /doc /LD
// post-build command: xdcmake xml_list_tag.dll
/// <remarks>Here is an example of a bulleted list:
/// <list type="bullet">
/// <item>
/// <description>Item 1.</description>
/// </item>
/// <item>
/// <description>Item 2.</description>
/// </item>
/// </list>
/// </remarks>
class MyClass {};
```

## <a name="see-also"></a>Consulte também

[Documentação XML](xml-documentation-visual-cpp.md)
