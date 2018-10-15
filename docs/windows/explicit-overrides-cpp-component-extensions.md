---
title: Substituições explícitas (C + + c++ /CLI e c++ /CLI CX) | Microsoft Docs
ms.custom: ''
ms.date: 10/12/2018
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- overriding, override [C++]
ms.assetid: 4ec3eaf5-163b-4df8-8f16-7a2ec04c3d0f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 689c8420c2526f94f88c8b2ba8433c2310281874
ms.sourcegitcommit: 3f4e92266737ecb70507871e87dc8e2965ad7e04
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/15/2018
ms.locfileid: "49328032"
---
# <a name="explicit-overrides--ccli-and-ccx"></a>Substituições explícitas (C + + c++ /CLI e c++ /CLI CX)

Este tópico discute como substituir explicitamente um membro de uma classe base ou interface. Uma substituição (explícita) nomeada só deve ser usada para substituir um método com um método derivado que tem um nome diferente.

## <a name="all-runtimes"></a>Todos os Tempos de Execução

### <a name="syntax"></a>Sintaxe

```cpp
overriding-function-declarator = type::function [,type::function] { overriding-function-definition }
overriding-function-declarator = function { overriding-function-definition }
```

### <a name="parameters"></a>Parâmetros

*substituindo--Declarador de função*<br/>
A lista de argumentos, nome e tipo de retorno da função de substituição.  Observe que a função de substituição não precisam ter o mesmo nome que a função que está sendo substituído.

*type*<br/>
O tipo base que contém uma função para substituir.

*function*<br/>
Uma lista delimitada por vírgula de um ou mais nomes de função para substituir.

*substituindo-function-definition*<br/>
As instruções do corpo de função que definem a função de substituição.

### <a name="remarks"></a>Comentários

Use explícito substituições para criar um alias para uma assinatura de método, ou para fornecer implementações diferentes para métodos witht a mesma assinatura.

Para obter informações sobre como modificar o comportamento de tipos herdados e membros de tipo herdado, consulte [especificadores de substituição](../windows/override-specifiers-cpp-component-extensions.md).

## <a name="windows-runtime"></a>Tempo de Execução do Windows

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

### <a name="remarks"></a>Comentários

Para obter informações sobre explícita substituem no código nativo ou código compilado com `/clr:oldSyntax`, consulte [substituições explícitas](../cpp/explicit-overrides-cpp.md).

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

O exemplo de código a seguir mostra uma substituição simple, implícita e a implementação de um membro em uma interface base, não usando substituições explícitas.

```cpp
// explicit_override_1.cpp
// compile with: /clr
interface struct I1 {
   virtual void f();
};

ref class X : public I1 {
public:
   virtual void f() {
      System::Console::WriteLine("X::f override of I1::f");
   }
};

int main() {
   I1 ^ MyI = gcnew X;
   MyI -> f();
}
```

```Output
X::f override of I1::f
```

O exemplo de código a seguir mostra como implementar todos os membros de interface com uma assinatura comum, usando a sintaxe de substituição explícita.

```cpp
// explicit_override_2.cpp
// compile with: /clr
interface struct I1 {
   virtual void f();
};

interface struct I2 {
   virtual void f();
};

ref struct X : public I1, I2 {
   virtual void f() = I1::f, I2::f {
      System::Console::WriteLine("X::f override of I1::f and I2::f");
   }
};

int main() {
   I1 ^ MyI = gcnew X;
   I2 ^ MyI2 = gcnew X;
   MyI -> f();
   MyI2 -> f();
}
```

```Output
X::f override of I1::f and I2::f
X::f override of I1::f and I2::f
```

O exemplo de código a seguir mostra como uma substituição de função pode ter um nome diferente da função que está implementando.

```cpp
// explicit_override_3.cpp
// compile with: /clr
interface struct I1 {
   virtual void f();
};

ref class X : public I1 {
public:
   virtual void g() = I1::f {
      System::Console::WriteLine("X::g");
   }
};

int main() {
   I1 ^ a = gcnew X;
   a->f();
}
```

```Output
X::g
```

O exemplo de código a seguir mostra uma implementação de interface explícita que implementa uma coleção de tipo seguro.

```cpp
// explicit_override_4.cpp
// compile with: /clr /LD
using namespace System;
ref class R : ICloneable {
   int X;

   virtual Object^ C() sealed = ICloneable::Clone {
      return this->Clone();
   }

public:
   R() : X(0) {}
   R(int x) : X(x) {}

   virtual R^ Clone() {
      R^ r = gcnew R;
      r->X = this->X;
      return r;
   }
};
```

## <a name="see-also"></a>Consulte também

[Extensões de componentes para .NET e UWP](../windows/component-extensions-for-runtime-platforms.md)