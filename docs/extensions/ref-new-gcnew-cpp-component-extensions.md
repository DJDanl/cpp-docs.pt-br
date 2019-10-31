---
title: ref new, gcnew (C++/CLI e C++/CX)
ms.date: 10/12/2018
ms.topic: reference
f1_keywords:
- gcnew
- ref new
- gcnew_cpp
helpviewer_keywords:
- ref new keyword (C++)
- gcnew keyword [C++]
ms.assetid: 388a62da-c2df-4a94-a9a2-205b53e577da
ms.openlocfilehash: f3dd0b73e300b44cb4f35e42683725813453d7de
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "65516641"
---
# <a name="ref-new-gcnew--ccli-and-ccx"></a>ref new, gcnew (C++/CLI e C++/CX)

A palavra-chave agregada **ref new** aloca uma instância de um tipo que é coletado como lixo quando o objeto se torna inacessível e retorna um identificador ([^](handle-to-object-operator-hat-cpp-component-extensions.md)) para o objeto alocado.

## <a name="all-runtimes"></a>Todos os Tempos de Execução

A memória de uma instância de um tipo alocada por **ref new** é desalocada automaticamente.

Uma operação **ref new** lança `OutOfMemoryException` se não conseguir alocar memória.

Saiba mais sobre como a memória para tipos C++ nativos é alocada e desalocada em [operadores new e delete](../cpp/new-and-delete-operators.md).

## <a name="windows-runtime"></a>Tempo de Execução do Windows

Use **ref new** para alocar memória para objetos do Windows Runtime cujo tempo de vida você deseja administrar automaticamente. O objeto é desalocado automaticamente quando sua contagem de referência vai para zero, o que ocorre após a última cópia da referência ter saído do escopo. Saiba mais em [Classes e structs ref](../cppcx/ref-classes-and-structs-c-cx.md).

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

A memória de um tipo gerenciado (referência ou tipo de valor) é alocada por **gcnew** e desalocada usando a coleta de lixo.

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

O exemplo a seguir usa **gcnew** para alocar um objeto Message.

```cpp
// mcppv2_gcnew_1.cpp
// compile with: /clr
ref struct Message {
   System::String^ sender;
   System::String^ receiver;
   System::String^ data;
};

int main() {
   Message^ h_Message  = gcnew Message;
  //...
}
```

O exemplo a seguir usa **gcnew** para criar um tipo de valor demarcado para uso como um tipo de referência.

```cpp
// example2.cpp : main project file.
// compile with /clr
using namespace System;
value class Boxed {
    public:
        int i;
};
int main()
{
    Boxed^ y = gcnew Boxed;
    y->i = 32;
    Console::WriteLine(y->i);
    return 0;
}
```

```Output
32
```

## <a name="see-also"></a>Consulte também

[Extensões de componentes para .NET e UWP](component-extensions-for-runtime-platforms.md)