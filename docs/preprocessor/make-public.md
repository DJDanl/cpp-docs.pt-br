---
title: Pragma make_public
ms.date: 08/29/2019
f1_keywords:
- vc-pragma.make_public
- make_public_CPP
helpviewer_keywords:
- pragmas, make_public
- make_public pragma
ms.assetid: c3665f4d-268a-4932-9661-c37c8ae6a341
ms.openlocfilehash: d12fab685e0088993cb43073c3603bda12edd2f3
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70218826"
---
# <a name="make_public-pragma"></a>Pragma make_public

Indica que um tipo nativo deve ter a acessibilidade pública de assembly.

## <a name="syntax"></a>Sintaxe

> **#pragma make_public (** *tipo* **)**

### <a name="parameters"></a>Parâmetros

*Escreva*\
O nome do tipo que você deseja ter acessibilidade de assembly público.

## <a name="remarks"></a>Comentários

**make_public** é útil para quando o tipo nativo que você deseja referenciar é de um arquivo de cabeçalho que você não pode alterar. Se você quiser usar o tipo nativo na assinatura de uma função pública em um tipo com visibilidade de assembly público, o tipo nativo também deverá ter acessibilidade pública de assembly, ou o compilador emitirá um aviso.

**make_public** deve ser especificado em escopo global. Ele só está em vigor a partir do ponto no qual ele é declarado até o final do arquivo de código-fonte.

O tipo nativo pode ser implicitamente ou explicitamente privado. Para obter mais informações, consulte [visibilidade de tipo](../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Type_visibility).

## <a name="examples"></a>Exemplos

O exemplo a seguir é o conteúdo de um arquivo de cabeçalho que contém as definições de duas estruturas nativas.

```cpp
// make_public_pragma.h
struct Native_Struct_1 { int i; };
struct Native_Struct_2 { int i; };
```

O exemplo de código a seguir consome o arquivo de cabeçalho. Ele mostra que, a menos que você marque explicitamente as estruturas nativas como públicas usando **make_public**, o compilador gerará um aviso quando você tentar usar as estruturas nativas na assinatura da função pública em um tipo gerenciado público.

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

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
