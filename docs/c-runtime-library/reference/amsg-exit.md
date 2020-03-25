---
title: _amsg_exit
ms.date: 11/04/2016
api_name:
- _amsg_exit
api_location:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _amsg_exit
helpviewer_keywords:
- _amsg_exit
ms.assetid: 146d4faf-d763-43a4-b264-12711196456b
ms.openlocfilehash: 31979a3181dc57644f1e6877277884e55cebf733
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80170925"
---
# <a name="_amsg_exit"></a>_amsg_exit

Emite uma mensagem de erro de runtime especificada e, em seguida, sai do seu aplicativo com o código de erro 255.

## <a name="syntax"></a>Sintaxe

```cpp
void _amsg_exit ( int rterrnum );
```

### <a name="parameters"></a>parâmetros

*rterrnum*<br/>
O número de identificação de uma mensagem de erro de runtime definida pelo sistema.

## <a name="remarks"></a>Comentários

Essa função emite a mensagem de erro de runtime para **stderr** para aplicativos de console ou exibe a mensagem em uma caixa de mensagem para aplicativos do Windows. No modo de depuração, você pode optar por invocar o depurador antes de sair.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|_amsg_exit|internal.h|
