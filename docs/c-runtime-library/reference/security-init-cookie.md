---
title: __security_init_cookie | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
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
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c905004702fe7a767ea7d91285a66d6b91465fd7
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="securityinitcookie"></a>__security_init_cookie

Inicializa o cookie de segurança global.

## <a name="syntax"></a>Sintaxe

```C
void __security_init_cookie(void);
```

## <a name="remarks"></a>Comentários

O cookie de segurança global é usado para proteção de estouro de buffer no código compilado com [/GS (Buffer Security Check)](../../build/reference/gs-buffer-security-check.md) e no código que usa a manipulação de exceção. Na entrada para uma função protegida contra estouro, o cookie é colocado na pilha e na saída o valor da pilha é comparado com o cookie global. Qualquer diferença entre eles indica que ocorreu um estouro do buffer e causa o encerramento imediato do programa.

Normalmente, **security_init_cookie** é chamado pelo CRT quando ele é inicializado. Se você ignorar inicialização CRT — por exemplo, se você usar [/ENTRY](../../build/reference/entry-entry-point-symbol.md) para especificar um ponto de entrada, em seguida, você deve chamar **security_init_cookie** por conta própria. Se **security_init_cookie** não for chamado, global cookie de segurança é definido como um valor padrão e proteção de estouro de buffer for comprometida. Como um invasor pode explorar esse valor de cookie padrão para anular as verificações de estouro de buffer, é recomendável que você sempre chamar **security_init_cookie** ao definir seu próprio ponto de entrada.

A chamada para **security_init_cookie** devem ser feitas antes de qualquer protegido saturação de função é inserida; caso contrário, será detectada uma saturação de buffer artificiais. Para obter mais informações, consulte [Erro em Tempo de Execução C R6035](../../error-messages/tool-errors/c-runtime-error-r6035.md).

## <a name="example"></a>Exemplo

Consulte os exemplos em [Erro em Tempo de Execução C R6035](../../error-messages/tool-errors/c-runtime-error-r6035.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**__security_init_cookie**|\<process.h>|

**security_init_cookie** é uma extensão da Microsoft para a biblioteca de tempo de execução C padrão. Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Análise aprofundada das verificações de segurança do compilador](http://go.microsoft.com/fwlink/p/?linkid=7260)<br/>
