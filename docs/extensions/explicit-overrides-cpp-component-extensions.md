---
title: Substituições explícitas (C++/CLI e C++/CX)
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- overriding, override [C++]
ms.assetid: 4ec3eaf5-163b-4df8-8f16-7a2ec04c3d0f
ms.openlocfilehash: c199301794daaa140ede2fd99b0ae755cea70f97
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80172367"
---
# <a name="explicit-overrides--ccli-and-ccx"></a>Substituições explícitas (C++/CLI e C++/CX)

Este tópico discute como substituir explicitamente um membro de uma classe ou interface base. Uma substituição nomeada (explícita) deve ser usada apenas para substituir um método por um método derivado que tenha um nome diferente.

## <a name="all-runtimes"></a>Todos os Runtimes

### <a name="syntax"></a>Sintaxe

```cpp
overriding-function-declarator = type::function [,type::function] { overriding-function-definition }
overriding-function-declarator = function { overriding-function-definition }
```

### <a name="parameters"></a>parâmetros

*overriding-function-declarator*<br/>
O tipo de retorno, nome e lista de argumentos da função de substituição.  Observe que a função de substituição não precisa ter o mesmo nome da função que está sendo substituída.

*tipo*<br/>
O tipo base que contém uma função para substituir.

*função*<br/>
Uma lista delimitada por vírgulas de um ou mais nomes de função a serem substituídos.

*overriding-function-definition*<br/>
As instruções do corpo da função que definem a função de substituição.

### <a name="remarks"></a>Comentários

Use substituições explícitas para criar um alias para uma assinatura de método ou para fornecer implementações diferentes para métodos com a mesma assinatura.

Saiba mais sobre como modificar o comportamento de tipos e membros de tipo herdados em [Especificadores de Substituição](override-specifiers-cpp-component-extensions.md).

## <a name="windows-runtime"></a>Tempo de Execução do Windows

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

### <a name="remarks"></a>Comentários

Saiba mais sobre substituições explícitas em código nativo ou compilado com `/clr:oldSyntax` em [Substituições explícitas](../cpp/explicit-overrides-cpp.md).

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

O exemplo de código a seguir mostra uma substituição simples e implícita e a implementação de um membro em uma interface base, não usando substituições explícitas.

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

O exemplo de código a seguir mostra como implementar todos os membros da interface com uma assinatura comum, usando a sintaxe de substituição explícita.

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

O exemplo de código a seguir mostra uma implementação de interface explícita que implementa uma coleção segura de tipo.

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

## <a name="see-also"></a>Confira também

[Extensões de componentes para .NET e UWP](component-extensions-for-runtime-platforms.md)
