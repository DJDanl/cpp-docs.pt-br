---
title: LOCAL (MASM)
ms.date: 08/30/2018
f1_keywords:
- Local
helpviewer_keywords:
- LOCAL directive
ms.assetid: 76147e2d-23ca-4f1e-8817-81428becd113
ms.openlocfilehash: 94af498865151ff5c49fac9dbc03de65c4ecb934
ms.sourcegitcommit: 1819bd2ff79fba7ec172504b9a34455c70c73f10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2018
ms.locfileid: "51327597"
---
# <a name="local-masm"></a>LOCAL (MASM)

Na primeira diretiva, dentro de uma macro **LOCAL** define rótulos que são exclusivos para cada instância da macro.

## <a name="syntax"></a>Sintaxe

> LOCAL *localname* \[, *localname*]...
>
> LOCAL *etiqueta* \[ __\[__ *contagem*__]__ ] \[ __:__  *tipo de*] \[ __,__ *rótulo* \[ __\[__ *contagem* __]__  ] \[ *tipo*]]...

## <a name="remarks"></a>Comentários

Na segunda diretiva, dentro de uma definição de procedimento (**PROC**), **LOCAL** cria variáveis baseada em pilha que existem para a duração do procedimento. O *etiqueta* pode ser uma variável simples ou uma matriz que contém *contagem* elementos.

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>