---
title: Serialização (C++/CLI)
ms.date: 11/04/2016
helpviewer_keywords:
- serialization [C++]
- SerializableAttribute class, managed applications
- NonSerializedAttribute class, managed applications
- managed code [C++], serializing
- .NET Framework [C++], serialization
- serialization [C++], about serialization
ms.assetid: 869010ca-74e1-4989-b409-4643cdb94084
ms.openlocfilehash: b2dfdcaf1a1f33e89d106d4529ffc9af2d08376b
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74988408"
---
# <a name="serialization-ccli"></a>Serialização (C++/CLI)

A serialização (o processo de armazenar o estado de um objeto ou membro para um meio permanente) de classes gerenciadas (incluindo campos ou propriedades individuais) é compatível com as classes <xref:System.SerializableAttribute> e <xref:System.NonSerializedAttribute>.

## <a name="remarks"></a>Comentários

Aplique o atributo personalizado **SerializableAttribute** a uma classe gerenciada para serializar toda a classe ou aplicar somente a campos ou Propriedades específicos para serializar partes da classe gerenciada. Use o atributo personalizado **Nonserializadoattribute** para isentar campos ou propriedades de uma classe gerenciada de ser serializado.

## <a name="example"></a>Exemplo

### <a name="description"></a>Descrição

No exemplo a seguir, a classe `MyClass` (e a propriedade `m_nCount`) está marcada como serializável. No entanto, a propriedade `m_nData` não é serializada conforme indicado pelo atributo personalizado não **serializado** :

### <a name="code"></a>Código

```cpp
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

### <a name="comments"></a>Comments

Observe que ambos os atributos podem ser referenciados usando seu "nome curto" (**serializável** e não **serializado**). Isso é explicado em mais detalhes na [aplicação de atributos](/dotnet/standard/attributes/applying-attributes).

## <a name="see-also"></a>Consulte também

[Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)
