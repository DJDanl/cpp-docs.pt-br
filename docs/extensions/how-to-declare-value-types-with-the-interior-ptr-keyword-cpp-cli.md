---
title: Como declarar tipos de valores com a palavra-chave interior_ptr (C++/CLI)
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- _ptr keyword
- value types, declaring
ms.assetid: 49eea66e-eeba-49bd-95b0-ba297be436e3
ms.openlocfilehash: 46f8c39affe5a3c0ad8648162f0fde5371eb30ca
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87195571"
---
# <a name="how-to-declare-value-types-with-the-interior_ptr-keyword-ccli"></a>Como declarar tipos de valores com a palavra-chave interior_ptr (C++/CLI)

Um **interior_ptr** pode ser usado com um tipo de valor.

> [!IMPORTANT]
> Esse recurso de linguagem é compatível com a opção do compilador `/clr`, mas não pela opção do compilador `/ZW`.

## <a name="example"></a>Exemplo

### <a name="description"></a>Descrição

O seguinte exemplo em C++/CLI mostra como usar um **interior_ptr** com um tipo de valor.

### <a name="code"></a>Código

```cpp
// interior_ptr_value_types.cpp
// compile with: /clr
value struct V {
   V(int i) : data(i){}
   int data;
};

int main() {
   V v(1);
   System::Console::WriteLine(v.data);

   // pointing to a value type
   interior_ptr<V> pv = &v;
   pv->data = 2;

   System::Console::WriteLine(v.data);
   System::Console::WriteLine(pv->data);

   // pointing into a value type
   interior_ptr<int> pi = &v.data;
   *pi = 3;
   System::Console::WriteLine(*pi);
   System::Console::WriteLine(v.data);
   System::Console::WriteLine(pv->data);
}
```

```Output
1
2
2
3
3
3
```

## <a name="example"></a>Exemplo

### <a name="description"></a>Descrição

Em um tipo de valor, o **`this`** ponteiro é avaliado como um interior_ptr.

No corpo de uma função membro não estática de um tipo de valor `V` , **`this`** é uma expressão do tipo `interior_ptr<V>` cujo valor é o endereço do objeto para o qual a função é chamada.

### <a name="code"></a>Código

```cpp
// interior_ptr_value_types_this.cpp
// compile with: /clr /LD
value struct V {
   int data;
   void f() {
      interior_ptr<V> pv1 = this;
      // V* pv2 = this;   error
   }
};
```

## <a name="example"></a>Exemplo

### <a name="description"></a>Descrição

O exemplo a seguir mostra como usar o operador address-of com membros estáticos.

O endereço de um membro do tipo Visual C++ estático produz um ponteiro nativo.  O endereço de um membro de tipo de valor estático é um ponteiro gerenciado porque o membro de tipo de valor é alocado no heap de runtime e pode ser movido pelo coletor de lixo.

### <a name="code"></a>Código

```cpp
// interior_ptr_value_static.cpp
// compile with: /clr
using namespace System;
value struct V { int i; };

ref struct G {
   static V v = {22};
   static int i = 23;
   static String^ pS = "hello";
};

int main() {
   interior_ptr<int> p1 = &G::v.i;
   Console::WriteLine(*p1);

   interior_ptr<int> p2 = &G::i;
   Console::WriteLine(*p2);

   interior_ptr<String^> p3 = &G::pS;
   Console::WriteLine(*p3);
}
```

```Output
22
23
hello
```

## <a name="see-also"></a>Confira também

[interior_ptr (C++/CLI)](interior-ptr-cpp-cli.md)
