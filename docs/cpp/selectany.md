---
title: selectany
ms.date: 11/04/2016
f1_keywords:
- selectany_cpp
helpviewer_keywords:
- __declspec keyword [C++], selectany
- selectany __declspec keyword
ms.assetid: 9c353017-5a42-4f50-b741-bd13da1ce84d
ms.openlocfilehash: e8ca82900ffd16264aca494950d4793029e55d9c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365593"
---
# <a name="selectany"></a>selectany

**Específico da Microsoft**

Informa ao compilador que o item de dados global declarado (variável ou objeto) é uma COMDAT aleatória (uma função compactada).

## <a name="syntax"></a>Sintaxe

```
__declspec( selectany ) declarator
```

## <a name="remarks"></a>Comentários

No tempo de link, se várias definições de uma COMDAT forem consideradas, o vinculador escolherá uma e descartará o restante. Se a opção linker [/OPT:REF](../build/reference/opt-optimizations.md) (Otimizações) for selecionada, ocorrerá a eliminação do COMDAT para remover todos os itens de dados não referenciados na saída do linker.

Os construtores e a atribuição pela função ou por métodos estáticos globais na declaração não criarão uma referência e não impedirão a eliminação de /OPT:REF. Os efeitos colaterais desse código não devem depender de quando não houver nenhuma outra referência aos dados.

Para objetos globais dinamicamente inicializados, **a selectany** descartará o código de inicialização de um objeto não referenciado, também.

Um item de dados global normalmente pode ser inicializado apenas uma vez em um projeto EXE ou DLL. **selectany** pode ser usado na inicialização de dados globais definidos por cabeçalhos, quando o mesmo cabeçalho aparece em mais de um arquivo de origem. **selectany** está disponível nos compiladores C e C++.

> [!NOTE]
> **selectany** só pode ser aplicado à inicialização real de itens de dados globais que são externamente visíveis.

## <a name="example"></a>Exemplo

Este código mostra como usar o atributo **selectany:**

```cpp
//Correct - x1 is initialized and externally visible
__declspec(selectany) int x1=1;

//Incorrect - const is by default static in C++, so
//x2 is not visible externally (This is OK in C, since
//const is not by default static in C)
const __declspec(selectany) int x2 =2;

//Correct - x3 is extern const, so externally visible
extern const __declspec(selectany) int x3=3;

//Correct - x4 is extern const, so it is externally visible
extern const int x4;
const __declspec(selectany) int x4=4;

//Incorrect - __declspec(selectany) is applied to the uninitialized
//declaration of x5
extern __declspec(selectany) int x5;

// OK: dynamic initialization of global object
class X {
public:
X(int i){i++;};
int i;
};

__declspec(selectany) X x(1);
```

## <a name="example"></a>Exemplo

Este código mostra como usar o atributo **selectany** para garantir que os dados COMDAT dobrem quando você também usa a opção de linker [/OPT:ICF.](../build/reference/opt-optimizations.md) Observe que os dados devem ser marcados com **selectany** e colocados em uma seção **const** (readonly). Você deve especificar explicitamente a seção somente leitura.

```cpp
// selectany2.cpp
// in the following lines, const marks the variables as read only
__declspec(selectany) extern const int ix = 5;
__declspec(selectany) extern const int jx = 5;
int main() {
   int ij;
   ij = ix + jx;
}
```

**Fim específico da Microsoft**

## <a name="see-also"></a>Confira também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
