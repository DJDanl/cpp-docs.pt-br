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
ms.openlocfilehash: 1f8fae2d8af1b7121290bfbd42b2668afc50034c
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43217247"
---
# <a name="ltparamgt-visual-c"></a>&lt;param&gt; (Visual C++)
A marca \<param> deve ser usada no comentário para uma declaração de método para descrever um dos parâmetros do método.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
<param name='name'>description</param>  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `name`  
 O nome do parâmetro de um método.  Coloque o nome entre aspas simples ou duplas.  O compilador emite um aviso se não encontra `name`.  
  
 `description`  
 Uma descrição do parâmetro.  
  
## <a name="remarks"></a>Comentários  
 O texto da marcação \<param> será exibido no IntelliSense, no [Pesquisador de Objetos](https://msdn.microsoft.com/f89acfc5-1152-413d-9f56-3dc16e3f0470) e no relatório Web de comentários sobre código.  
  
 Compile com [/doc](../build/reference/doc-process-documentation-comments-c-cpp.md) para processar comentários de documentação em um arquivo.  
  
## <a name="example"></a>Exemplo  
  
```  
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