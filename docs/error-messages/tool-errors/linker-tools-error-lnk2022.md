---
title: Erro das Ferramentas de Vinculador LNK2022
ms.date: 11/04/2016
f1_keywords:
- LNK2022
helpviewer_keywords:
- LNK2022
ms.assetid: d2128c73-dde3-4b8e-a9b2-0a153acefb3b
ms.openlocfilehash: e55202274c5ec3982f784ad6cdf074a5a99e922f
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64345331"
---
# <a name="linker-tools-error-lnk2022"></a>Erro das Ferramentas de Vinculador LNK2022

> Falha na operação de metadados (*HRESULT*): *error_message*

O vinculador detectou um erro durante a mesclagem de metadados. Os erros de metadados devem ser resolvidos para vincular com êxito.

Uma maneira para diagnosticar esse problema é executar **ildasm-tokens** nos arquivos de objeto para localizar quais tipos têm os tokens listados no `error_message`e procure as diferenças.  Nos metadados, dois tipos diferentes com o mesmo nome não é válido, mesmo se o atributo LayoutType apenas é diferente.

Um motivo para das LNK2022 é quando há um tipo (como um struct) em vários compilandos com o mesmo nome, mas com definições conflitantes e quando você compila com [/clr](../../build/reference/clr-common-language-runtime-compilation.md).  Nesse caso, certifique-se de que o tipo tem uma definição de idêntica em todos os compilandos.  O nome do tipo está listado no `error_message`.

Outra possível causa das LNK2022 é quando o vinculador encontra um arquivo de metadados em um local diferente do que foi especificado para o compilador (com [#using](../../preprocessor/hash-using-directive-cpp.md) ). Verifique se o arquivo de metadados (. dll ou. netmodule) está no mesmo local quando passados para o vinculador, como ele era quando ele foi passado para o compilador.

Ao criar um aplicativo ATL, o uso da macro `_ATL_MIXED` é necessário em todos os compilandos, se ele for usado em pelo menos um.

## <a name="example"></a>Exemplo

O exemplo a seguir define um tipo vazio.

```cpp
// LNK2022_a.cpp
// compile with: /clr /c
public ref class Test {};
```

## <a name="example"></a>Exemplo

Este exemplo mostra que não é possível vincular dois arquivos de código de origem que contêm tipos de mesmo nome mas de diferentes definições.

O exemplo a seguir gera das LNK2022.

```cpp
// LNK2022_b.cpp
// compile with: LNK2022_a.cpp /clr /LD
// LNK2022 expected
public ref class Test {
   void func() {}
   int var;
};
```