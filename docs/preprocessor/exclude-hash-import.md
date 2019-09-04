---
title: excluir atributo de importação
ms.date: 08/29/2019
f1_keywords:
- exclude
helpviewer_keywords:
- exclude attribute
ms.assetid: 0883248a-d4bf-420e-9848-807b28fa976e
ms.openlocfilehash: 6a3625ee0dd44f3e2731e1240fea5f3dd4ed109e
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70218725"
---
# <a name="exclude-import-attribute"></a>excluir atributo de importação

**C++Determinados**

Exclui itens dos arquivos de cabeçalho da biblioteca de tipos que estão sendo gerados.

## <a name="syntax"></a>Sintaxe

> **#import** *biblioteca de tipos* **Exclude (** "*Nome1*" [ **,** "*nome2*"...] **)**

### <a name="parameters"></a>Parâmetros

*Nome1*\
O primeiro item a ser excluído.

*Nome2*\
Adicional O segundo e os itens posteriores a serem excluídos, se necessário.

## <a name="remarks"></a>Comentários

As bibliotecas de tipos podem conter definições dos itens definidos em cabeçalhos do sistema ou em outras bibliotecas de tipos. Esse atributo pode ter qualquer número de argumentos, onde cada um é um item de biblioteca de tipo de nível superior a ser excluído.

**FINAL C++ específico**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)\
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)
