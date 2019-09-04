---
title: atributo de importação de no_implementation
ms.date: 08/29/2019
f1_keywords:
- no_implementation
helpviewer_keywords:
- no_implementation attribute
ms.assetid: bdc67785-e131-409c-87bc-f4d2f4abb07b
ms.openlocfilehash: 8f0a7454fdbedc1959b665ccb2a23748d21c342d
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70220775"
---
# <a name="no_implementation-import-attribute"></a>atributo de importação de no_implementation

**C++Determinados**

Suprime a geração do `.tli` cabeçalho, que contém as implementações das funções de membro do wrapper.

## <a name="syntax"></a>Sintaxe

> **#import** *biblioteca de tipos* **no_implementation**

## <a name="remarks"></a>Comentários

Se esse atributo for especificado, o `.tlh` cabeçalho, com as declarações para expor itens de biblioteca de tipos, será gerado sem uma `#include` instrução para incluir o `.tli` arquivo de cabeçalho.

Esse atributo é usado em conjunto com [implementation_only](../preprocessor/implementation-only.md).

**FINAL C++ específico**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)\
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)
