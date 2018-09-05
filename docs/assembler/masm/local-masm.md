---
title: LOCAL (MASM) | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- Local
dev_langs:
- C++
helpviewer_keywords:
- LOCAL directive
ms.assetid: 76147e2d-23ca-4f1e-8817-81428becd113
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e8105bc8168ce28d468a1378c5cf7889907a7c9f
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43685057"
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