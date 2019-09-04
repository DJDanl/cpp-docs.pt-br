---
title: atributo de importação de rename_namespace
ms.date: 08/29/2019
f1_keywords:
- rename_namespace
helpviewer_keywords:
- rename_namespace attribute
ms.assetid: 45006d2b-36cd-4bec-98b9-3b8ec45299e3
ms.openlocfilehash: d319d7390e7c7dce070a35be44aad37c7a34e1a0
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70216646"
---
# <a name="rename_namespace-import-attribute"></a>atributo de importação de rename_namespace

**C++Determinados**

Renomeia o namespace que contém o conteúdo da biblioteca de tipos.

## <a name="syntax"></a>Sintaxe

> **#import** *biblioteca de tipos* **rename_namespace (** "*NewName*" **)**

### <a name="parameters"></a>Parâmetros

*NewName*\
O nome do novo namespace.

## <a name="remarks"></a>Comentários

O atributo **rename_namespace** usa um único argumento, *NewName*, que especifica o novo nome para o namespace.

Para remover o namespace, use o atributo [no_namespace](../preprocessor/no-namespace.md) em vez disso.

**FINAL C++ específico**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)\
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)
