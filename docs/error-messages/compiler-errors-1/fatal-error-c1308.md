---
title: Erro fatal C1308
ms.date: 11/04/2016
f1_keywords:
- C1308
helpviewer_keywords:
- C1308
ms.assetid: 46177997-069e-433a-8e20-93c846d78ffd
ms.openlocfilehash: 0128953b3b3fa0f29a6764c1d7dab0ece67dfae7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50640616"
---
# <a name="fatal-error-c1308"></a>Erro fatal C1308

Não há suporte para a vinculação de assemblies

Um. netmodule é permitido como entrada para o vinculador, mas não é de um assembly. Esse erro pode ser gerado quando é feita uma tentativa de vincular a um assembly compilado com `/clr:safe`.

Para obter mais informações, consulte [arquivos. netmodule como entrada de vinculador](../../build/reference/netmodule-files-as-linker-input.md).

O exemplo a seguir gera C1308:

```
// C1308.cpp
// compile with: /clr:safe /LD
public ref class MyClass {
public:
   int i;
};
```

E, em seguida,

```
// C1308b.cpp
// compile with: /clr /link C1308b.obj C1308.dll
// C1308 expected
#using "C1308.dll"
int main() {
   MyClass ^ my = gcnew MyClass();
}
```