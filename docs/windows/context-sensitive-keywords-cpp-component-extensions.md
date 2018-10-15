---
title: Palavras-chave contextuais (C + + c++ /CLI e c++ /CLI CX) | Microsoft Docs
ms.custom: ''
ms.date: 10/12/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- internal_CPP
dev_langs:
- C++
helpviewer_keywords:
- context-sensitive keywords
ms.assetid: e33da089-f434-44e9-8cce-4668d05a8939
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5d02939e61da4a247b46da5637c38d01e7990c49
ms.sourcegitcommit: 3f4e92266737ecb70507871e87dc8e2965ad7e04
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/15/2018
ms.locfileid: "49327928"
---
# <a name="context-sensitive-keywords--ccli-and-ccx"></a>Palavras-chave contextuais (C + + c++ /CLI e c++ /CLI CX)

*Palavras-chave contextuais* são elementos de linguagem que são reconhecidos apenas em contextos específicos. Fora do contexto específico, uma palavra-chave contextual pode ser um símbolo definido pelo usuário.

## <a name="all-runtimes"></a>Todos os Tempos de Execução

### <a name="remarks"></a>Comentários

A seguir está uma lista de palavras-chave contextuais:

- [abstract](../windows/abstract-cpp-component-extensions.md)

- [delegate](../windows/delegate-cpp-component-extensions.md)

- [event](../windows/event-cpp-component-extensions.md)

- [finally](../dotnet/finally.md)

- [for each, in](../dotnet/for-each-in.md)

- [InitOnly](../dotnet/initonly-cpp-cli.md)

- `internal`

- [literal](../windows/literal-cpp-component-extensions.md)

- [override](../windows/override-cpp-component-extensions.md)

- [propriedade](../windows/property-cpp-component-extensions.md)

- [sealed](../windows/sealed-cpp-component-extensions.md)

- `where` (parte do [genéricos](../windows/generics-cpp-component-extensions.md))

Para fins de legibilidade, você talvez queira limitar o uso de palavras-chave contextuais como símbolos definidos pelo usuário.

## <a name="windows-runtime"></a>Tempo de Execução do Windows

### <a name="remarks"></a>Comentários

(Não há nenhum comentário específico da plataforma para esse recurso.)

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

### <a name="remarks"></a>Comentários

(Não há nenhum comentário específico da plataforma para esse recurso.)

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

O exemplo de código a seguir mostra que o contexto apropriado, o **propriedade** palavra-chave contextual pode ser usado para definir uma propriedade e uma variável.

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

## <a name="see-also"></a>Consulte também

[Extensões de componentes para .NET e UWP](../windows/component-extensions-for-runtime-platforms.md)