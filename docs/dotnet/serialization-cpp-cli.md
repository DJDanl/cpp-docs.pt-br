---
title: Serialização (C + + CLI) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- serialization [C++]
- SerializableAttribute class, managed applications
- NonSerializedAttribute class, managed applications
- managed code [C++], serializing
- .NET Framework [C++], serialization
- serialization [C++], about serialization
ms.assetid: 869010ca-74e1-4989-b409-4643cdb94084
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: f4a410da74c37ee722c04f21e2cde906b9d061d2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33164551"
---
# <a name="serialization-ccli"></a>Serialização (C++/CLI)
Serialização (o processo de armazenar o estado de um objeto ou membro de uma mídia permanente) de classes gerenciadas (incluindo propriedades ou campos individuais) é suportado pelo <xref:System.SerializableAttribute> e <xref:System.NonSerializedAttribute> classes.  
  
## <a name="remarks"></a>Comentários  
 Aplicar o **SerializableAttribute** atributo personalizado para uma classe gerenciada para serializar a classe inteira ou aplicar específicos somente para campos ou propriedades para serializar partes da classe gerenciada. Use o **NonSerializedAttribute** atributo personalizado para isentos campos ou propriedades de uma classe gerenciada do que está sendo serializado.  
  
## <a name="example"></a>Exemplo  
  
### <a name="description"></a>Descrição  
 No exemplo a seguir, a classe `MyClass` (e a propriedade `m_nCount`) está marcado como serializável. No entanto, o `m_nData` propriedade não é serializada conforme indicado pelo **NonSerialized** atributo personalizado:  
  
### <a name="code"></a>Código  
  
```  
// serialization_and_mcpp.cpp  
// compile with: /LD /clr  
using namespace System;  
  
[ Serializable ]  
public ref class MyClass {  
public:  
   int m_nCount;  
private:  
   [ NonSerialized ]  
   int m_nData;  
};  
```  
  
### <a name="comments"></a>Comentários  
 Observe que ambos os atributos podem ser referenciados usando o "nome curto" (**Serializable** e **NonSerialized**). Isso é explicado mais [aplicar atributos](/dotnet/standard/attributes/applying-attributes).  
  
## <a name="see-also"></a>Consulte também  
 [Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)