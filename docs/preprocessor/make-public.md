---
title: make_public
ms.date: 11/04/2016
f1_keywords:
- vc-pragma.make_public
- make_public_CPP
helpviewer_keywords:
- pragmas, make_public
- make_public pragma
ms.assetid: c3665f4d-268a-4932-9661-c37c8ae6a341
ms.openlocfilehash: d569758f90b9e55f65ad13517f86dea41d151ca8
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59039118"
---
# <a name="makepublic"></a>make_public
Indica que um tipo nativo deve ter a acessibilidade pública de assembly.

## <a name="syntax"></a>Sintaxe

```
#pragma make_public(type)
```

### <a name="parameters"></a>Parâmetros

*tipo* é o nome do tipo que você deseja ter acessibilidade pública de assembly.

## <a name="remarks"></a>Comentários

**make_public** é útil para quando o tipo nativo que você deseja referenciar é de um arquivo. h que você não pode alterar. Se você desejar usar o tipo nativo na assinatura de uma função pública em um tipo com visibilidade pública de assembly, o tipo nativo também deve ter a acessibilidade pública do assembly. Caso contrário, o compilador emitirá um aviso.

**make_public** deve ser especificado no escopo global e tem efeito somente do ponto no qual ele é declarado até ao final do arquivo de código fonte.

O tipo nativo pode ser implicitamente ou explicitamente particular; ver [visibilidade de tipo](../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Type_visibility) para obter mais informações.

## <a name="examples"></a>Exemplos

O exemplo a seguir é o conteúdo de um arquivo .h que contém as definições para duas estruturas nativas.

```cpp
// make_public_pragma.h
struct Native_Struct_1 { int i; };
struct Native_Struct_2 { int i; };
```

O exemplo de código a seguir consome o arquivo de cabeçalho e mostra que, a menos que você marque explicitamente as estruturas nativas como públicas usando **make_public**, o compilador gerará um aviso quando você tenta usar as estruturas nativas no assinatura da função pública em um tipo gerenciado público.

```cpp
// make_public_pragma.cpp
// compile with: /c /clr /W1
#pragma warning (default : 4692)
#include "make_public_pragma.h"
#pragma make_public(Native_Struct_1)

public ref struct A {
   void Test(Native_Struct_1 u) {u.i = 0;}   // OK
   void Test(Native_Struct_2 u) {u.i = 0;}   // C4692
};
```

## <a name="see-also"></a>Consulte também

[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)