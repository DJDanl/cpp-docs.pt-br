---
title: '&lt;listar> (comentários de documentação do C++)'
ms.date: 11/04/2016
f1_keywords:
- list
helpviewer_keywords:
- list C++ XML tag
- <list> C++ XML tag
ms.assetid: c792a10b-0451-422c-9aa0-604116e69d64
ms.openlocfilehash: 24f9b17c67b8f951743fd51c04266b05dad235c7
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90041959"
---
# <a name="ltlistgt-and-ltlistheadergt"></a>&lt;listar &gt; e &lt; ListHeader&gt;

O \<listheader> bloco é usado para definir a linha de cabeçalho de uma tabela ou lista de definições. Ao definir uma tabela, é necessário fornecer uma entrada para o termo no título.

## <a name="syntax"></a>Sintaxe

```xml
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

*prazo*<br/>
Um termo a se definir, que será definido em `description`.

*descrição*<br/>
Um item em uma lista com marcadores ou numerada ou uma definição de um `term`.

## <a name="remarks"></a>Comentários

Cada item na lista é especificado com um \<item> bloco. Ao criar uma lista de definições, é necessário especificar `term` e `description`. No entanto, para uma tabela, lista com marcadores ou lista numerada, será necessário fornecer apenas uma entrada para `description`.

Uma lista ou tabela pode ter tantos \<item> blocos quantos forem necessários.

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

## <a name="see-also"></a>Confira também

[Documentação XML](xml-documentation-visual-cpp.md)
