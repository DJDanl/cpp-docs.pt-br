---
title: LOCAL (MASM)
ms.date: 08/30/2018
f1_keywords:
- Local
helpviewer_keywords:
- LOCAL directive
ms.assetid: 76147e2d-23ca-4f1e-8817-81428becd113
ms.openlocfilehash: c8ea49b9862159a5a56bfb3d2c3cd0c1f4cd7413
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50596866"
---
# <a name="local-masm"></a>LOCAL (MASM)

Na primeira diretiva, dentro de uma macro **LOCAL** define rótulos que são exclusivos para cada instância da macro.

## <a name="syntax"></a>Sintaxe

> LOCAL *localname* [[, *localname*]]...

> LOCAL *etiqueta* [[[*contagem*]]] [[:*tipo*]] [[, *rótulo* [[[*contagem*]]] [[ *tipo*]]]]...

## <a name="remarks"></a>Comentários

Na segunda diretiva, dentro de uma definição de procedimento (**PROC**), **LOCAL** cria variáveis baseada em pilha que existem para a duração do procedimento. O *etiqueta* pode ser uma variável simples ou uma matriz que contém *contagem* elementos.

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>