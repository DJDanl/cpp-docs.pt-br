---
title: __security_init_cookie | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: __security_init_cookie
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
dev_langs: C++
helpviewer_keywords:
- security cookie [C++]
- __security_init_cookie function
- security_init_cookie function
- global security cookie
ms.assetid: 32119905-0897-4a1c-84ca-bffd16c9b2af
caps.latest.revision: "12"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 249fc38a36ee0f3a61b6347b48219154bada7d22
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="securityinitcookie"></a>__security_init_cookie
Inicializa o cookie de segurança global.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void __security_init_cookie(void);  
```  
  
## <a name="remarks"></a>Comentários  
 O cookie de segurança global é usado para proteção de estouro de buffer no código compilado com [/GS (Buffer Security Check)](../../build/reference/gs-buffer-security-check.md) e no código que usa a manipulação de exceção. Na entrada para uma função protegida contra estouro, o cookie é colocado na pilha e na saída o valor da pilha é comparado com o cookie global. Qualquer diferença entre eles indica que ocorreu um estouro do buffer e causa o encerramento imediato do programa.  
  
 Normalmente, `__security_init_cookie` é chamado pelo CRT quando é inicializado. Se você ignorar a inicialização CRT – por exemplo, se usar [/ENTRY](../../build/reference/entry-entry-point-symbol.md) para especificar um ponto de entrada – você deverá chamar `__security_init_cookie` por conta própria. Se `__security_init_cookie` não for chamado, o cookie de segurança global será definido como um valor padrão e a proteção de estouro do buffer ficará comprometida. Como um invasor pode explorar esse valor de cookie padrão para vencer as verificações de estouro de buffer, recomendamos que você sempre chame `__security_init_cookie` ao definir seu próprio ponto de entrada.  
  
 A chamada para `__security_init_cookie` deve ser feita antes que qualquer função protegida conta estouro seja inserida. Caso contrário, será detectado um estouro de buffer falso. Para obter mais informações, consulte [Erro em Tempo de Execução C R6035](../../error-messages/tool-errors/c-runtime-error-r6035.md).  
  
## <a name="example"></a>Exemplo  
 Consulte os exemplos em [Erro em Tempo de Execução C R6035](../../error-messages/tool-errors/c-runtime-error-r6035.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`__security_init_cookie`|\<process.h>|  
  
 `__security_init_cookie` é uma extensão da Microsoft à biblioteca padrão de tempo de execução do C. Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Análise aprofundada das verificações de segurança do compilador](http://go.microsoft.com/fwlink/?linkid=7260)