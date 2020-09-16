---
title: Erro das Ferramentas de Vinculador LNK2022
ms.date: 11/04/2016
f1_keywords:
- LNK2022
helpviewer_keywords:
- LNK2022
ms.assetid: d2128c73-dde3-4b8e-a9b2-0a153acefb3b
ms.openlocfilehash: 187a63cb4bd22fc5e0d35523d97f438ba56b8576
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90686352"
---
# <a name="linker-tools-error-lnk2022"></a>Erro das Ferramentas de Vinculador LNK2022

> falha na operação de metadados (*HRESULT*): *ERROR_MESSAGE*

O vinculador detectou um erro ao mesclar metadados. Os erros de metadados devem ser resolvidos para vincular com êxito.

Uma maneira de diagnosticar esse problema é executar **ILDASM-tokens** nos arquivos de objeto para descobrir quais tipos têm os tokens listados em `error_message` e procurar diferenças.  Nos metadados, dois tipos diferentes com o mesmo nome não são válidos, mesmo que o atributo apenas layout seja diferente.

Um motivo para LNK2022 é quando um tipo (como uma struct) existe em vários compilandos com o mesmo nome, mas com definições conflitantes e quando você compila com [/CLR](../../build/reference/clr-common-language-runtime-compilation.md).  Nesse caso, verifique se o tipo tem uma definição idêntica em todos os compilandos.  O nome do tipo é listado em `error_message` .

Outra causa possível para LNK2022 é quando o vinculador encontra um arquivo de metadados em um local diferente do que foi especificado para o compilador (com [#using](../../preprocessor/hash-using-directive-cpp.md) ). Certifique-se de que o arquivo de metadados (. dll ou. netmodule) esteja no mesmo local quando passado para o vinculador, como foi quando ele foi passado para o compilador.

Ao criar um aplicativo ATL, o uso da macro `_ATL_MIXED` será necessário em todos os compilandos, se for usado em pelo menos um.

## <a name="examples"></a>Exemplos

O exemplo a seguir define um tipo vazio.

```cpp
// LNK2022_a.cpp
// compile with: /clr /c
public ref class Test {};
```

Este exemplo mostra que não é possível vincular dois arquivos de código-fonte que contêm tipos de mesmo nome, mas definições diferentes.

O exemplo a seguir gera LNK2022.

```cpp
// LNK2022_b.cpp
// compile with: LNK2022_a.cpp /clr /LD
// LNK2022 expected
public ref class Test {
   void func() {}
   int var;
};
```
