---
title: atributo de importação de inject_statement
ms.date: 08/29/2019
f1_keywords:
- inject_statement
helpviewer_keywords:
- inject_statement attribute
ms.assetid: 07d6f0f4-d9fb-4e18-aa62-f235f142ff5e
ms.openlocfilehash: 25dee621ff8af2c9a39e605b9da2c29d80f9570a
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70221000"
---
# <a name="inject_statement-import-attribute"></a>atributo de importação de inject_statement

**C++Determinados**

Insere seu argumento como texto de origem no cabeçalho da biblioteca de tipos.

## <a name="syntax"></a>Sintaxe

> **#import** *biblioteca de tipos* **inject_statement (** "*origem-texto*" **)**

### <a name="parameters"></a>Parâmetros

*origem-texto*\
Texto de origem a ser inserido no arquivo de cabeçalho da biblioteca de tipos.

## <a name="remarks"></a>Comentários

O texto é colocado no início da declaração do namespace que encapsula o conteúdo da *biblioteca de tipos* no arquivo de cabeçalho.

**FINAL C++ específico**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)\
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)
