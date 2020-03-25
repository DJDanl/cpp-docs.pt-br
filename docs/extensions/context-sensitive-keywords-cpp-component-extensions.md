---
title: Palavras-chave contextuais (C++/CLI e C++/CX)
ms.date: 10/12/2018
ms.topic: reference
f1_keywords:
- internal_CPP
helpviewer_keywords:
- context-sensitive keywords
ms.assetid: e33da089-f434-44e9-8cce-4668d05a8939
ms.openlocfilehash: 53fcaf13eb56ae14841861bffd1a29376304b8d6
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80182169"
---
# <a name="context-sensitive-keywords--ccli-and-ccx"></a>Palavras-chave contextuais (C++/CLI e C++/CX)

*Palavras-chave contextuais* são elementos de linguagem reconhecidos apenas em contextos específicos. Fora do contexto específico, uma palavra-chave contextual pode ser um símbolo definido pelo usuário.

## <a name="all-runtimes"></a>Todos os Runtimes

### <a name="remarks"></a>Comentários

Segue abaixo uma lista de palavras-chave contextuais:

- [abstract](abstract-cpp-component-extensions.md)

- [delegate](delegate-cpp-component-extensions.md)

- [event](event-cpp-component-extensions.md)

- [finally](../dotnet/finally.md)

- [for each, in](../dotnet/for-each-in.md)

- [initonly](../dotnet/initonly-cpp-cli.md)

- `internal`

- [literal](literal-cpp-component-extensions.md)

- [override](override-cpp-component-extensions.md)

- [property](property-cpp-component-extensions.md)

- [sealed](sealed-cpp-component-extensions.md)

- `where` (parte de [Genéricos](generics-cpp-component-extensions.md))

Para fins de legibilidade, talvez você queira limitar o uso de palavras-chave contextuais como símbolos definidos pelo usuário.

## <a name="windows-runtime"></a>Tempo de Execução do Windows

### <a name="remarks"></a>Comentários

(Não há comentários específicos da plataforma para esse recurso.)

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

### <a name="remarks"></a>Comentários

(Não há comentários específicos da plataforma para esse recurso.)

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

O exemplo de código a seguir mostra que, no contexto apropriado, a palavra-chave contextual **property** pode ser usada para definir uma propriedade e uma variável.

```cpp
// context_sensitive_keywords.cpp
// compile with: /clr
public ref class C {
   int MyInt;
public:
   C() : MyInt(99) {}

   property int Property_Block {   // context-sensitive keyword
      int get() { return MyInt; }
   }
};

int main() {
   int property = 0;               // variable name
   C ^ MyC = gcnew C();
   property = MyC->Property_Block;
   System::Console::WriteLine(++property);
}
```

```Output
100
```

## <a name="see-also"></a>Confira também

[Extensões de componentes para .NET e UWP](component-extensions-for-runtime-platforms.md)
