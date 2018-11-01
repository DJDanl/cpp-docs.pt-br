---
title: __raise
ms.date: 11/04/2016
f1_keywords:
- __raise
- __raise_cpp
helpviewer_keywords:
- __raise keyword [C++]
ms.assetid: 6f1ae418-5f0f-48b6-9f6e-8ea7e66b239a
ms.openlocfilehash: 865524fe91b7d137e3a943973dcca6d833bd16df
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50471429"
---
# <a name="raise"></a>__raise

Enfatiza o site de chamada de um evento.

## <a name="syntax"></a>Sintaxe

```
__raise method-declarator;
```

## <a name="remarks"></a>Comentários

No código gerenciado, um evento só pode ser acionado de dentro da classe em que é definido. Ver [evento](../windows/event-cpp-component-extensions.md) para obter mais informações.

A palavra-chave **__raise** causa um erro a ser emitido se você chamar um não evento.

> [!NOTE]
>  Uma classe ou um struct modelo não podem conter eventos.

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

## <a name="see-also"></a>Consulte também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Manipulação de eventos](../cpp/event-handling.md)<br/>
[Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)