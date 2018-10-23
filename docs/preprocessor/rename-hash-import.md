---
title: Renomear (#import) | Microsoft Docs
ms.custom: ''
ms.date: 10/18/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- Rename
dev_langs:
- C++
helpviewer_keywords:
- rename attribute
ms.assetid: 5c5c6153-1087-4b7b-87fb-fc59b90b9975
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2b8525a321f56ab5e9bfe2f8e8cee7be9cd26788
ms.sourcegitcommit: 0164af5615389ffb1452ccc432eb55f6dc931047
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/23/2018
ms.locfileid: "49808180"
---
# <a name="rename-import"></a>Renomear (\#importar)

**Específico do C++**

Soluciona os problemas de colisão de nome.

## <a name="syntax"></a>Sintaxe

```
rename("OldName","NewName")
```

### <a name="parameters"></a>Parâmetros

*OldName*<br/>
Nome antigo na biblioteca de tipos.

*NewName*<br/>
Nome a ser usado em vez do nome antigo.

## <a name="remarks"></a>Comentários

Se esse atributo for especificado, o compilador substitui todas as ocorrências de *OldName* em uma biblioteca de tipos com o usuário forneceu *NewName* nos arquivos de cabeçalho resultante.

Esse atributo pode ser usado quando um nome na biblioteca de tipos coincide com uma definição de macro nos arquivos de cabeçalho do sistema. Se essa situação não for resolvida, vários erros de sintaxe serão gerados, tais como [erro do compilador C2059](../error-messages/compiler-errors-1/compiler-error-c2059.md) e [erro do compilador C2061](../error-messages/compiler-errors-1/compiler-error-c2061.md).

> [!NOTE]
> A substituição é para um nome usado na biblioteca de tipos, e não para um nome usado no arquivo de cabeçalho resultante.

Por exemplo, suponha que exista uma propriedade chamada `MyParent` em uma biblioteca de tipos, e uma macro `GetMyParent` seja definida em um arquivo de cabeçalho e usada antes de `#import`. Uma vez que `GetMyParent` é o nome padrão de uma função de wrapper para o tratamento de erros `get` propriedade, uma colisão de nomes ocorrerá. Para contornar o problema, use o seguinte atributo na instrução `#import`:

```cpp
rename("MyParent","MyParentX")
```

que altera o nome `MyParent` na biblioteca de tipos. Uma tentativa de alterar o nome do wrapper `GetMyParent` falhará:

```cpp
rename("GetMyParent","GetMyParentX")
```

Isso acontece porque o nome `GetMyParent` ocorre apenas no arquivo de cabeçalho resultante da biblioteca de tipos.

**FIM de específico de C++**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)