---
title: O ALIAS (MASM) | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- Alias
dev_langs:
- C++
helpviewer_keywords:
- ALIAS directive
ms.assetid: d9725c49-58de-41da-ab01-b06a56cf5cf2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c6a977d35040d8ca25cd3bd4ae4def233092b37a
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43691056"
---
# <a name="alias-masm"></a>ALIAS (MASM)

O **ALIAS** diretiva cria um nome alternativo para uma função.  Isso permite que você crie vários nomes para uma função, ou crie bibliotecas que permitem que o vinculador (LINK.exe) para mapear uma função antiga para uma nova função.

## <a name="syntax"></a>Sintaxe

> ALIAS \< *alias*> = \< *nome real*>

#### <a name="parameters"></a>Parâmetros

*nome real*<br/>
O nome real da função ou procedimento.  Os colchetes angulares são necessários.

*alias*<br/>
O nome de alias ou alternativo.  Os colchetes angulares são necessários.

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>