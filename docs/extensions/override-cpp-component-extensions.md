---
title: substituir (C++/CLI e C++/CX)
ms.date: 11/04/2016
ms.topic: reference
helpviewer_keywords:
- overriding, override keyword [C++]
- override keyword [C++]
ms.assetid: 34d19257-1686-4fcd-96f5-af07c70ba914
ms.openlocfilehash: 8dc7a0a0e6cf759d956fd701d033bd773e572af3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "65515651"
---
# <a name="override--ccli-and-ccx"></a>substituir (C++/CLI e C++/CX)

A palavra-chave **override** sensível ao contexto indica que um membro de um tipo substitui uma classe base ou um membro da interface base.

## <a name="remarks"></a>Comentários

A palavra-chave **override** é válida ao compilar para destinos nativos (opção do compilador padrão), destinos do Windows Runtime (opção do compilador `/ZW`) ou destinos do Common Language Runtime (opção do compilador `/clr`).

Confira mais informações sobre especificadores de substituição em [Especificador de substituição](../cpp/override-specifier.md) e [Especificadores de substituição e compilações nativas](../dotnet/how-to-declare-override-specifiers-in-native-compilations-cpp-cli.md).

Saiba mais sobre palavras-chave contextuais em [Palavras-chave contextuais](context-sensitive-keywords-cpp-component-extensions.md).

## <a name="examples"></a>Exemplos

O exemplo de código a seguir mostra que **override** também pode ser usado em compilações nativas.

```cpp
// override_keyword_1.cpp
// compile with: /c
struct I1 {
   virtual void f();
};

struct X : public I1 {
   virtual void f() override {}
};
```

### <a name="example"></a>Exemplo

O exemplo de código a seguir mostra que **override** pode ser usado em compilações do Windows Runtime.

```cpp
// override_keyword_2.cpp
// compile with: /ZW /c
ref struct I1 {
   virtual void f();
};

ref struct X : public I1 {
   virtual void f() override {}
};
```

#### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

### <a name="example"></a>Exemplo

O exemplo de código a seguir mostra que **override** pode ser usado em compilações do Common Language Runtime.

```cpp
// override_keyword_3.cpp
// compile with: /clr /c
ref struct I1 {
   virtual void f();
};

ref struct X : public I1 {
   virtual void f() override {}
};
```

#### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

## <a name="see-also"></a>Consulte também

[Especificador override](../cpp/override-specifier.md)<br/>
[Especificadores de substituição](override-specifiers-cpp-component-extensions.md)