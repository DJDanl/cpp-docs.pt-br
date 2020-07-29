---
title: Ponteiros baseados (C++)
ms.date: 10/09/2018
f1_keywords:
- __based
- _based
- __based_cpp
helpviewer_keywords:
- __based keyword [C++]
- based pointers
- pointers, based
ms.assetid: 1e5f2e96-c52e-4738-8e14-87278681205e
ms.openlocfilehash: a76fe56e0e6bd0501bbc3e23e138cb2e75055c73
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229136"
---
# <a name="based-pointers-c"></a>Ponteiros baseados (C++)

A **`__based`** palavra-chave permite declarar ponteiros com base em ponteiros (ponteiros que são deslocamentos de ponteiros existentes). A **`__based`** palavra-chave é específica da Microsoft.

## <a name="syntax"></a>Sintaxe

```
type __based( base ) declarator
```

## <a name="remarks"></a>Comentários

Ponteiros baseados em endereços de ponteiro são a única forma da **`__based`** palavra-chave válida em compilações de 32 bits ou 64 bits. Para os compiladores C/C++ de 32 bits da Microsoft, um ponteiro baseado é um deslocamento de 32 bits de uma base de ponteiro de 32 bits. Uma restrição semelhante é mantida para ambientes de 64 bits, onde um ponteiro baseado é um deslocamento de 64 bits da base de 64 bits.

Um uso para ponteiros baseados em ponteiros é para identificadores persistentes que contêm ponteiros. Uma lista vinculada que consiste em ponteiros baseados em um ponteiro pode ser salva em disco e depois ser recarregada em outro local na memória, com os ponteiros permanecendo válidos. Por exemplo:

```cpp
// based_pointers1.cpp
// compile with: /c
void *vpBuffer;
struct llist_t {
   void __based( vpBuffer ) *vpData;
   struct llist_t __based( vpBuffer ) *llNext;
};
```

O ponteiro `vpBuffer` é atribuído ao endereço da memória alocada em algum momento posterior no programa. A lista vinculada é realocada em relação ao valor de `vpBuffer`.

> [!NOTE]
> Os identificadores de persistência contendo ponteiros também podem ser obtidos com o uso [de arquivos mapeados para memória](/windows/win32/Memory/file-mapping).

Ao desreferenciar um ponteiro baseado, a base deve ser especificada explicitamente ou implicitamente conhecida na declaração.

Para compatibilidade com versões anteriores, **_based** é um sinônimo para **`__based`** a menos que a opção do compilador [/za \( desabilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) seja especificada.

## <a name="example"></a>Exemplo

O código a seguir demonstra a alteração de um ponteiro baseado alterando sua base.

```cpp
// based_pointers2.cpp
// compile with: /EHsc
#include <iostream>

int a1[] = { 1,2,3 };
int a2[] = { 10,11,12 };
int *pBased;

typedef int __based(pBased) * pBasedPtr;

using namespace std;
int main() {
   pBased = &a1[0];
   pBasedPtr pb = 0;

   cout << *pb << endl;
   cout << *(pb+1) << endl;

   pBased = &a2[0];

   cout << *pb << endl;
   cout << *(pb+1) << endl;
}
```

```Output
1
2
10
11
```

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[alloc_text](../preprocessor/alloc-text.md)
