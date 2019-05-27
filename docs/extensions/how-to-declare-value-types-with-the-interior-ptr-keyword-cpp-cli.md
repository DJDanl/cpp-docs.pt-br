---
title: 'Como: declarar tipos de valor com a palavra-chave interior_ptr (C++/CLI)'
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- _ptr keyword
- value types, declaring
ms.assetid: 49eea66e-eeba-49bd-95b0-ba297be436e3
ms.openlocfilehash: 2b75f6c4763ddd7d3fd2d802371e21c40d506b16
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "65515751"
---
# <a name="how-to-declare-value-types-with-the-interiorptr-keyword-ccli"></a>Como: declarar tipos de valor com a palavra-chave interior_ptr (C++/CLI)

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

Em um tipo de valor, o ponteiro **this** é avaliado como interior_ptr.

No corpo de uma função de membro não estático de um tipo de valor `V`, **this** é uma expressão do tipo `interior_ptr<V>` cujo valor é o endereço do objeto para o qual a função é chamada.

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

O endereço de um membro do tipo Visual C++ estático produz um ponteiro nativo.  O endereço de um membro de tipo de valor estático é um ponteiro gerenciado porque o membro de tipo de valor é alocado no heap de tempo de execução e pode ser movido pelo coletor de lixo.

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

## <a name="see-also"></a>Consulte também

[interior_ptr (C++/CLI)](interior-ptr-cpp-cli.md)