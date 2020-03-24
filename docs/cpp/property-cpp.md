---
title: property (C++)
ms.date: 11/04/2016
f1_keywords:
- property_cpp
helpviewer_keywords:
- property __declspec keyword
- __declspec keyword [C++], property
ms.assetid: f3b850ba-bf48-4df7-a1d6-8259d97309ce
ms.openlocfilehash: 03f71739698fd20a01fd72567ce5b9babc176327
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80179296"
---
# <a name="property-c"></a>property (C++)

**Seção específica da Microsoft**

Esse atributo pode ser aplicado a “membros de dados virtuais” não estáticos em uma definição de classe ou estrutura. O compilador trata esses “membros de dados virtuais” como membros de dados alterando suas referências em chamadas de função.

## <a name="syntax"></a>Sintaxe

```
   __declspec( property( get=get_func_name ) ) declarator
   __declspec( property( put=put_func_name ) ) declarator
   __declspec( property( get=get_func_name, put=put_func_name ) ) declarator
```

## <a name="remarks"></a>Comentários

Quando o compilador vê um membro de dados declarado com esse atributo à direita de um operador de seleção de membro (" **.** " ou " **->** "), ele converte a operação em uma função `get` ou `put`, dependendo se tal expressão é um l-Value ou um valor r. Em contextos mais complicados, como "`+=`", uma regravação é executada fazendo `get` e `put`.

Esse atributo também pode ser usado na declaração de uma matriz vazia em uma definição de classe ou estrutura. Por exemplo:

```cpp
__declspec(property(get=GetX, put=PutX)) int x[];
```

A instrução anterior indica que `x[]` pode ser usado com um ou mais índices da matriz. Nesse caso, `i=p->x[a][b]` será transformado em `i=p->GetX(a, b)`, e `p->x[a][b] = i` será transformado em `p->PutX(a, b, i);`

**Fim da seção específica da Microsoft**

## <a name="example"></a>Exemplo

```cpp
// declspec_property.cpp
struct S {
   int i;
   void putprop(int j) {
      i = j;
   }

   int getprop() {
      return i;
   }

   __declspec(property(get = getprop, put = putprop)) int the_prop;
};

int main() {
   S s;
   s.the_prop = 5;
   return s.the_prop;
}
```

## <a name="see-also"></a>Confira também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
