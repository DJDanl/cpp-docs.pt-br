---
title: incluir () atributo de importação
ms.date: 08/29/2019
f1_keywords:
- include()
helpviewer_keywords:
- include() attribute
ms.assetid: 86c9dcb2-d9e0-4fd5-97d7-0bb3e23d6ecc
ms.openlocfilehash: 39ab63525b2b83781cbcaf86a61742c5fb767b72
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70218871"
---
# <a name="include-import-attribute"></a>incluir () atributo de importação

**C++Determinados**

Desabilita a exclusão automática.

## <a name="syntax"></a>Sintaxe

> **#import** *biblioteca de tipos* **include ("** _Nome1_ **"** [ __, "__ *nome2* __"__ ...] __)__

### <a name="parameters"></a>Parâmetros

*Nome1*\
Primeiro item a ser incluído de modo forçado.

*Nome2*\
O segundo item a ser incluído de modo forçado (se necessário).

## <a name="remarks"></a>Comentários

As bibliotecas de tipos podem conter definições dos itens definidos em cabeçalhos do sistema ou em outras bibliotecas de tipos. `#import` tenta impedir vários erros de definição excluindo automaticamente esses itens. Se alguns itens não devem ser excluídos automaticamente, você poderá ver o [aviso do compilador (nível 3) C4192](../error-messages/compiler-warnings/compiler-warning-level-3-c4192.md). Você pode usar esse atributo para desabilitar a exclusão automática. Esse atributo pode ter qualquer número de argumentos, um para cada nome de um item de biblioteca de tipos a ser incluído.

**FINAL C++ específico**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)\
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)
