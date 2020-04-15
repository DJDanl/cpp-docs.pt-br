---
title: noreturn
ms.date: 11/04/2016
f1_keywords:
- noreturn_cpp
helpviewer_keywords:
- __declspec keyword [C++], noreturn
- noreturn __declspec keyword
ms.assetid: 9c6517e5-22d7-4051-9974-3d2200ae4d1d
ms.openlocfilehash: a30840aa0556a7324ba24c0f2aaec57dea88d082
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367862"
---
# <a name="noreturn"></a>noreturn

**Específico da Microsoft**

Este **atributo __declspec** diz ao compilador que uma função não retorna. Como conseqüência, o compilador sabe que o código após uma chamada para uma função **__declspec (sem retorno)** é inalcançável.

Se o compilador encontra uma função com um caminho de controle que não retorna um valor, ele gera um aviso (C4715) ou uma mensagem de erro (C2202). Se o caminho de controle não puder ser alcançado devido a uma função que nunca retorna, você pode usar **__declspec (sem retorno)** para evitar esse aviso ou erro.

> [!NOTE]
> Adicionar **__declspec (sem retorno)** a uma função que se espera que retorne pode resultar em comportamento indefinido.

## <a name="example"></a>Exemplo

Na amostra a seguir, a **outra** cláusula não contém uma declaração de devolução.  Declarar `fatal` como **__declspec (sem retorno)** evita um erro ou mensagem de aviso.

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

**Fim específico da Microsoft**

## <a name="see-also"></a>Confira também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
