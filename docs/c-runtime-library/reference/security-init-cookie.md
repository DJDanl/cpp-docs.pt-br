---
title: __security_init_cookie | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- __security_init_cookie
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
- security_init_cookie
- __security_init_cookie
dev_langs:
- C++
helpviewer_keywords:
- security cookie [C++]
- __security_init_cookie function
- security_init_cookie function
- global security cookie
ms.assetid: 32119905-0897-4a1c-84ca-bffd16c9b2af
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 84edc9fb461a6f0721abb648a88e1d81a4a19d07
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43678951"
---
# <a name="securityinitcookie"></a>__security_init_cookie

Inicializa o cookie de segurança global.

## <a name="syntax"></a>Sintaxe

```C
void __security_init_cookie(void);
```

## <a name="remarks"></a>Comentários

O cookie de segurança global é usado para proteção de estouro de buffer no código compilado com [/GS (Buffer Security Check)](../../build/reference/gs-buffer-security-check.md) e no código que usa a manipulação de exceção. Na entrada para uma função protegida contra estouro, o cookie é colocado na pilha e na saída o valor da pilha é comparado com o cookie global. Qualquer diferença entre eles indica que ocorreu um estouro do buffer e causa o encerramento imediato do programa.

Normalmente, **security_init_cookie** é chamado pelo CRT quando ele é inicializado. Se você ignorar inicialização CRT — por exemplo, se você usar [/ENTRY](../../build/reference/entry-entry-point-symbol.md) para especificar um ponto de entrada, em seguida, você deve chamar **security_init_cookie** por conta própria. Se **security_init_cookie** não for chamado, a global cookie de segurança é definida como um valor padrão e a proteção de estouro de buffer está comprometida. Como um invasor pode explorar esse valor de cookie padrão para vencer as verificações de estouro de buffer, é recomendável que você sempre chame **security_init_cookie** ao definir seu próprio ponto de entrada.

A chamada para **security_init_cookie** devem ser feitas antes de qualquer protegida contra estouro função é inserida; caso contrário, será detectado um estouro de buffer artificiais. Para obter mais informações, consulte [Erro em Tempo de Execução C R6035](../../error-messages/tool-errors/c-runtime-error-r6035.md).

## <a name="example"></a>Exemplo

Consulte os exemplos em [Erro em Tempo de Execução C R6035](../../error-messages/tool-errors/c-runtime-error-r6035.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**__security_init_cookie**|\<process.h>|

**security_init_cookie** é uma extensão da Microsoft para a biblioteca de tempo de execução C padrão. Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Microsoft Security Response Center](https://www.microsoft.com/en-us/msrc?rtc=1)
