---
title: noreturn
ms.date: 11/04/2016
f1_keywords:
- noreturn_cpp
helpviewer_keywords:
- __declspec keyword [C++], noreturn
- noreturn __declspec keyword
ms.assetid: 9c6517e5-22d7-4051-9974-3d2200ae4d1d
ms.openlocfilehash: f9ca61c9d734ccdd6b8d8374ed3a7c4128ee3d5e
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857366"
---
# <a name="noreturn"></a>noreturn

**Seção específica da Microsoft**

Esse atributo de **__declspec** informa ao compilador que uma função não retorna. Como consequência, o compilador sabe que o código após uma chamada para uma função **__declspec (noreturn)** está inacessível.

Se o compilador encontra uma função com um caminho de controle que não retorna um valor, ele gera um aviso (C4715) ou uma mensagem de erro (C2202). Se o caminho de controle não puder ser alcançado devido a uma função que nunca retorna, você poderá usar **__declspec (noreturn)** para evitar esse aviso ou erro.

> [!NOTE]
>  Adicionar **__declspec (noreturn)** a uma função que deve retornar pode resultar em um comportamento indefinido.

## <a name="example"></a>Exemplo

No exemplo a seguir, a cláusula **else** não contém uma instrução return.  Declarar `fatal` como **__declspec (noreturn)** evita uma mensagem de erro ou de aviso.

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

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)