---
title: atributo de importação de no_namespace
ms.date: 08/29/2019
f1_keywords:
- no_namespace
helpviewer_keywords:
- no_namespace attribute
ms.assetid: 5d81b741-a558-451b-b493-1f3b18967337
ms.openlocfilehash: ba52aed69cdbb46c135e6de5078d718e93f99c87
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70220728"
---
# <a name="no_namespace-import-attribute"></a>atributo de importação de no_namespace

**C++Determinados**

Especifica que o compilador não gera um nome de namespace.

## <a name="syntax"></a>Sintaxe

> **#import** *biblioteca de tipos* **no_namespace**

## <a name="remarks"></a>Comentários

O conteúdo da biblioteca de tipos no arquivo de cabeçalho de `#import` normalmente é definido em um namespace. O nome do namespace é especificado na `library` instrução do arquivo IDL original. Se o atributo **no_namespace** for especificado, esse namespace não será gerado pelo compilador.

Se você quiser usar um nome de namespace diferente, use o atributo [rename_namespace](../preprocessor/rename-namespace.md) em vez disso.

**FINAL C++ específico**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)\
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)
