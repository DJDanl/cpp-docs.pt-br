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
ms.openlocfilehash: 74810328d654787be46794a31d857eb3fd0731ea
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50478137"
---
# <a name="serialization-ccli"></a>Serialização (C++/CLI)

(O processo de armazenar o estado de um objeto ou membro para uma mídia permanente) de serialização de classes gerenciadas (incluindo campos individuais ou propriedades) é compatível com o <xref:System.SerializableAttribute> e <xref:System.NonSerializedAttribute> classes.

## <a name="remarks"></a>Comentários

Aplicar a **SerializableAttribute** atributo personalizado a uma classe gerenciada para serializar a classe inteira ou aplicar específicos somente para campos ou propriedades para serializar as partes da classe gerenciada. Use o **NonSerializedAttribute** atributo personalizado a isenção campos ou propriedades de uma classe gerenciada do que está sendo serializado.

## <a name="example"></a>Exemplo

### <a name="description"></a>Descrição

No exemplo a seguir, a classe `MyClass` (e a propriedade `m_nCount`) está marcado como serializável. No entanto, o `m_nData` propriedade não é serializada, conforme indicado pelo **NonSerialized** atributo personalizado:

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

Observe que ambos os atributos podem ser referenciados usando o "nome curto" (**Serializable** e **NonSerialized**). Isso será explicado mais [aplicando atributos](/dotnet/standard/attributes/applying-attributes).

## <a name="see-also"></a>Consulte também

[Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)