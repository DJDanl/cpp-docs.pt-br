---
title: atributo de importação de raw_dispinterfaces
ms.date: 08/29/2019
f1_keywords:
- raw_dispinterfaces
helpviewer_keywords:
- raw_dispinterfaces attribute
ms.assetid: f762864d-29bf-445b-825a-ba7b29a95409
ms.openlocfilehash: 73c58b72b27de8dcf96e8ab9464d0fb6bce12b66
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70216219"
---
# <a name="raw_dispinterfaces-import-attribute"></a>atributo de importação de raw_dispinterfaces

**C++Determinados**

Informa ao compilador para gerar funções de wrapper de baixo nível para métodos de dispinterface e para propriedades que `IDispatch::Invoke` chamam e retornam o código de erro HRESULT.

## <a name="syntax"></a>Sintaxe

> **#import** *biblioteca de tipos* **raw_dispinterfaces**

## <a name="remarks"></a>Comentários

Se esse atributo não for especificado, somente os wrappers de alto nível serão gerados, C++ o que gerará exceções em caso de falha.

**FINAL C++ específico**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)\
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)
