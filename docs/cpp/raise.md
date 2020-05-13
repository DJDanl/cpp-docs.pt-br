---
title: __raise
ms.date: 11/04/2016
f1_keywords:
- __raise
- __raise_cpp
helpviewer_keywords:
- __raise keyword [C++]
ms.assetid: 6f1ae418-5f0f-48b6-9f6e-8ea7e66b239a
ms.openlocfilehash: eb3ab24378071663b2a6a1abab700b81c3172419
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81317229"
---
# <a name="__raise"></a>__raise

Enfatiza o site de chamada de um evento.

## <a name="syntax"></a>Sintaxe

```
__raise method-declarator;
```

## <a name="remarks"></a>Comentários

No código gerenciado, um evento só pode ser acionado de dentro da classe em que é definido. Consulte [o evento](../extensions/event-cpp-component-extensions.md) para obter mais informações.

A palavra-chave **__raise** faz com que um erro seja emitido se você chamar um não-evento.

> [!NOTE]
> Uma classe ou um struct modelo não podem conter eventos.

## <a name="example"></a>Exemplo

```cpp
// EventHandlingRef_raise.cpp
struct E {
   __event void func1();
   void func1(int) {}

   void func2() {}

   void b() {
      __raise func1();
      __raise func1(1);  // C3745: 'int Event::bar(int)':
                         // only an event can be 'raised'
      __raise func2();   // C3745
   }
};

int main() {
   E e;
   __raise e.func1();
   __raise e.func1(1);  // C3745
   __raise e.func2();   // C3745
}
```

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Manipulação de eventos](../cpp/event-handling.md)<br/>
[Extensões de componentes para plataformas de runtime](../extensions/component-extensions-for-runtime-platforms.md)
