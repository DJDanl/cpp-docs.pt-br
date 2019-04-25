---
title: ALIAS (MASM)
ms.date: 08/30/2018
f1_keywords:
- Alias
helpviewer_keywords:
- ALIAS directive
ms.assetid: d9725c49-58de-41da-ab01-b06a56cf5cf2
ms.openlocfilehash: ab00092f410d34119e876db4562e6d0709743d79
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62166484"
---
# <a name="alias-masm"></a>ALIAS (MASM)

O **ALIAS** diretiva cria um nome alternativo para uma função.  Isso permite que você crie vários nomes para uma função, ou crie bibliotecas que permitem que o vinculador (LINK.exe) para mapear uma função antiga para uma nova função.

## <a name="syntax"></a>Sintaxe

> ALIAS \<*alias*> = \<*actual-name*>

#### <a name="parameters"></a>Parâmetros

*actual-name*<br/>
O nome real da função ou procedimento.  Os colchetes angulares são necessários.

*alias*<br/>
O nome de alias ou alternativo.  Os colchetes angulares são necessários.

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>