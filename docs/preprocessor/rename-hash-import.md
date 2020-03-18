---
title: Renomear atributo de importação
ms.date: 08/29/2019
helpviewer_keywords:
- rename attribute
ms.assetid: 5c5c6153-1087-4b7b-87fb-fc59b90b9975
ms.openlocfilehash: 520369f0308078fead2947e27a512f25a3ad3fab
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79447488"
---
# <a name="rename-import-attribute"></a>Renomear atributo de importação

**C++Determinados**

Soluciona os problemas de colisão de nome.

## <a name="syntax"></a>Sintaxe

> **#import** *tipo-* **renomeação** da biblioteca ("*OldName*" **,** "*NewName*" **)**

### <a name="parameters"></a>Parâmetros

\ *OldName*
Nome antigo na biblioteca de tipos.

*NewName*\
Nome a ser usado em vez do nome antigo.

## <a name="remarks"></a>Comentários

Quando o atributo **Rename** é especificado, o compilador substitui todas as ocorrências de *OldName* na *biblioteca de tipos* pelo *NewName* fornecido pelo usuário nos arquivos de cabeçalho resultantes.

O atributo **Rename** pode ser usado quando um nome na biblioteca de tipos coincide com uma definição de macro nos arquivos de cabeçalho do sistema. Se essa situação não for resolvida, o compilador poderá emitir vários erros de sintaxe, como o [erro do compilador C2059](../error-messages/compiler-errors-1/compiler-error-c2059.md) e o [erro do compilador C2061](../error-messages/compiler-errors-1/compiler-error-c2061.md).

> [!NOTE]
> A substituição é para um nome usado na biblioteca de tipos, e não para um nome usado no arquivo de cabeçalho resultante.

Por exemplo, suponha que exista uma propriedade chamada `MyParent` em uma biblioteca de tipos, e uma macro `GetMyParent` seja definida em um arquivo de cabeçalho e usada antes de `#import`. Como `GetMyParent` é o nome padrão de uma função de wrapper para a propriedade `get` de tratamento de erros, ocorrerá uma colisão de nomes. Para contornar o problema, use o seguinte atributo na instrução `#import`:

```cpp
#import MyTypeLib.tlb rename("MyParent","MyParentX")
```

que altera o nome `MyParent` na biblioteca de tipos. Uma tentativa de alterar o nome do wrapper `GetMyParent` falhará:

```cpp
#import MyTypeLib.tlb rename("GetMyParent","GetMyParentX")
```

É porque o nome `GetMyParent` ocorre apenas no arquivo de cabeçalho da biblioteca de tipos resultante.

**FINAL C++ específico**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)\
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)
