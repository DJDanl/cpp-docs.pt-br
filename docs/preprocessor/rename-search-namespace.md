---
title: atributo de importação de rename_search_namespace
ms.date: 08/29/2019
f1_keywords:
- rename_search_namespace
helpviewer_keywords:
- rename_search_namespace attribute
ms.assetid: 47c9d7fd-59dc-4c62-87a1-9011a0040167
ms.openlocfilehash: 42c6edb6aa34b441db8041dd2974728c138b2c82
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70216626"
---
# <a name="rename_search_namespace-import-attribute"></a>atributo de importação de rename_search_namespace

**C++Determinados**

Tem a mesma funcionalidade que o atributo [rename_namespace](../preprocessor/rename-namespace.md) , mas é usado em bibliotecas de tipos em que você `#import` usa a diretiva junto com o atributo [auto_search](../preprocessor/auto-search.md) .

## <a name="syntax"></a>Sintaxe

> **#import** *biblioteca de tipos* **rename_search_namespace (** "*NewName*" **)**

### <a name="parameters"></a>Parâmetros

*NewName*\
O nome do novo namespace.

## <a name="remarks"></a>Comentários

**FINAL C++ específico**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)\
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)
