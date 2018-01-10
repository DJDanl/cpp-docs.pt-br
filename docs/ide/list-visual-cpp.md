---
title: '&lt;lista&gt; (Visual C++) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- list
- <list>
dev_langs: C++
helpviewer_keywords:
- list C++ XML tag
- <list> C++ XML tag
ms.assetid: c792a10b-0451-422c-9aa0-604116e69d64
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e04fb5f7ff2ba22b53c0fe163455bfdb666f9b9f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ltlistgt-visual-c"></a>&lt;lista&gt; (Visual C++)
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
 `term`  
 Um termo a se definir, que será definido em `description`.  
  
 `description`  
 Um item em uma lista com marcadores ou numerada ou uma definição de um `term`.  
  
## <a name="remarks"></a>Comentários  
 Cada item na lista é especificado com um bloco \<item>. Ao criar uma lista de definições, é necessário especificar `term` e `description`. No entanto, para uma tabela, lista com marcadores ou lista numerada, será necessário fornecer apenas uma entrada para `description`.  
  
 Uma lista ou tabela pode ter quantos blocos \<item> forem necessários.  
  
 Compile com [/doc](../build/reference/doc-process-documentation-comments-c-cpp.md) para processar comentários de documentação em um arquivo.  
  
## <a name="example"></a>Exemplo  
  
```  
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
 [Documentação XML](../ide/xml-documentation-visual-cpp.md)