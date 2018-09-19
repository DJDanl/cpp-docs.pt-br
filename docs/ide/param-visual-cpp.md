---
title: '&lt;param&gt; (Visual C++) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- param
- <param>
dev_langs:
- C++
helpviewer_keywords:
- param C++ XML tag
- <param> C++ XML tag
ms.assetid: 66c1a1c3-4f98-4bcf-8c7d-9a40308982fb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e88890917986e54b3b912d50e97da77032abab34
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46078784"
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