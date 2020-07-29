---
title: Enumeração BufferCommand
description: 'Descreve o BufferCommand enum, que é usado para trabalhar com arquivos de memória por meio de CMemFile:: GetBufferPtr ()'
ms.date: 07/23/2020
f1_keywords:
- afx/buffercommand
helpviewer_keywords:
- buffercommand enumeration [MFC]
ms.openlocfilehash: f2f553df56fadd99b65b04cce9a97917425ed70b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87246089"
---
# <a name="buffercommand-enumeration"></a>Enumeração BufferCommand

Usado por [CMemFile:: GetBufferPtr](cmemfile-class.md#getbufferptr) para determinar a ação a ser tomada no buffer de memória com suporte de arquivo.

## <a name="syntax"></a>Sintaxe

``` cpp
public enum BufferCommand
{
   bufferRead,
   bufferWrite,
   bufferCommit,
   bufferCheck
};
```

## <a name="members"></a>Membros

|Nome|Descrição|
|-|-|
| `bufferRead` | Leia o buffer de memória com backup em arquivo. |
| `bufferWrite` | Gravar no buffer de memória com backup em arquivo. |
| `bufferCommit` | Avança a posição atual no buffer de memória com backup em arquivo até o final do buffer confirmado. |
| `bufferCheck` | Determine se o buffer de memória com backup em arquivo pode aumentar em tamanho. |

## <a name="requirements"></a>Requisitos

**Header:** afxwinforms. h (definido no assembly atlmfc\lib\mfcmifc80.dll)
