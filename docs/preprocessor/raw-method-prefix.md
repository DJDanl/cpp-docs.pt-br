---
title: raw_method_prefix
ms.date: 08/29/2019
f1_keywords:
- raw_method_prefix
helpviewer_keywords:
- raw_method_prefix attribute
ms.assetid: 71490313-af78-4bb2-b28a-eee67950d30b
ms.openlocfilehash: b1bc536507716e5c117718ec825bf7fe76c84b61
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70216149"
---
# <a name="raw_method_prefix"></a>raw_method_prefix

**C++Determinados**

Especifica um prefixo diferente para evitar colisões de nome.

## <a name="syntax"></a>Sintaxe

> **#import** *biblioteca de tipos* **raw_method_prefix (** "*prefix*" **)**

### <a name="parameters"></a>Parâmetros

*Prefixo*\
O prefixo a ser usado.

## <a name="remarks"></a>Comentários

Propriedades e métodos de baixo nível são expostos por funções de membro chamadas usando um prefixo padrão de **raw_** , para evitar colisões de nome com as funções de membro de tratamento de erros de alto nível.

> [!NOTE]
> Os efeitos do atributo **raw_method_prefix** são inalterados pela presença do atributo [raw_interfaces_only](raw-interfaces-only.md) . O **raw_method_prefix** sempre tem precedência `raw_interfaces_only` sobre a especificação de um prefixo. Se ambos os atributos forem usados na mesma `#import` instrução, o prefixo especificado pelo atributo **raw_method_prefix** será usado.

**FINAL C++ específico**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)\
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)
