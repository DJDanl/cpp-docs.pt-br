---
title: '&lt;paramref&gt; (Visual C++) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- paramref
- <paramref>
dev_langs:
- C++
helpviewer_keywords:
- paramref C++ XML tag
- <paramref> C++ XML tag
ms.assetid: c5730dc2-7159-421f-b2d5-bb971e307122
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a63caea7186114244927b9ede4c63ed97871d6e9
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46111258"
---
# <a name="ltparamrefgt-visual-c"></a>&lt;paramref&gt; (Visual C++)
A marcação \<paramref> fornece uma maneira para indicar que uma palavra é um parâmetro. O arquivo .xml pode ser processado para formatar esse parâmetro de uma forma distinta.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
<paramref name="name"/>  
```  
  
#### <a name="parameters"></a>Parâmetros  
*name*<br/>
O nome do parâmetro ao qual você deseja se referir.  Coloque o nome entre aspas simples ou duplas.  O compilador emite um aviso se não encontra `name`.  
  
## <a name="remarks"></a>Comentários  
 Compile com [/doc](../build/reference/doc-process-documentation-comments-c-cpp.md) para processar comentários de documentação em um arquivo.  
  
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
 [Documentação XML](../ide/xml-documentation-visual-cpp.md)