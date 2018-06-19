---
title: _amsg_exit | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _amsg_exit
apilocation:
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
apitype: DLLExport
f1_keywords:
- _amsg_exit
dev_langs:
- C++
helpviewer_keywords:
- _amsg_exit
ms.assetid: 146d4faf-d763-43a4-b264-12711196456b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dbb7f46bb4f3c942fd1c9e1a1d45c1ccf48739f7
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32392790"
---
# <a name="amsgexit"></a>_amsg_exit

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