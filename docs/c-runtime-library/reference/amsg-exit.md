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
ms.openlocfilehash: 2d577bfcf0584ef982ab43ff98674d0cfadd14ba
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70939692"
---
# <a name="_amsg_exit"></a>_amsg_exit

Emite uma mensagem de erro de tempo de execução especificada e, em seguida, sai do seu aplicativo com o código de erro 255.

## <a name="syntax"></a>Sintaxe

```cpp
void _amsg_exit ( int rterrnum );
```

### <a name="parameters"></a>Parâmetros

*rterrnum*<br/>
O número de identificação de uma mensagem de erro de tempo de execução definida pelo sistema.

## <a name="remarks"></a>Comentários

Essa função emite a mensagem de erro de tempo de execução para **stderr** para aplicativos de console ou exibe a mensagem em uma caixa de mensagem para aplicativos do Windows. No modo de depuração, você pode optar por invocar o depurador antes de sair.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|_amsg_exit|internal.h|