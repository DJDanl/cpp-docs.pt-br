---
title: noreturn
ms.date: 11/04/2016
f1_keywords:
- noreturn_cpp
helpviewer_keywords:
- __declspec keyword [C++], noreturn
- noreturn __declspec keyword
ms.assetid: 9c6517e5-22d7-4051-9974-3d2200ae4d1d
ms.openlocfilehash: f0b5b17a6d64375f49a6d55021c72ba7119eb976
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213301"
---
# <a name="noreturn"></a>noreturn

**Específico da Microsoft**

Esse **`__declspec`** atributo informa ao compilador que uma função não retorna. Como consequência, o compilador sabe que o código após uma chamada para uma **`__declspec(noreturn)`** função está inacessível.

Se o compilador encontra uma função com um caminho de controle que não retorna um valor, ele gera um aviso (C4715) ou uma mensagem de erro (C2202). Se o caminho de controle não puder ser alcançado devido a uma função que nunca retorna, você poderá usar **`__declspec(noreturn)`** para evitar esse aviso ou erro.

> [!NOTE]
> Adicionar **`__declspec(noreturn)`** a uma função que deve retornar pode resultar em um comportamento indefinido.

## <a name="example"></a>Exemplo

No exemplo a seguir, a **`else`** cláusula não contém uma instrução return.  Declarar `fatal` como **`__declspec(noreturn)`** evita uma mensagem de erro ou de aviso.

```cpp
// noreturn2.cpp
__declspec(noreturn) extern void fatal () {}

int main() {
   if(1)
     return 1;
   else if(0)
     return 0;
   else
     fatal();
}
```

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
