---
title: "__security_init_cookie | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "__security_init_cookie"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
apitype: "DLLExport"
f1_keywords: 
  - "security_init_cookie"
  - "__security_init_cookie"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função __security_init_cookie"
  - "cookie de segurança global"
  - "cookie de segurança [C++]"
  - "Função security_init_cookie"
ms.assetid: 32119905-0897-4a1c-84ca-bffd16c9b2af
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __security_init_cookie
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Inicializa o cookie de segurança global.  
  
## Sintaxe  
  
```  
void __security_init_cookie(void);  
```  
  
## Comentários  
 O cookie de segurança global é usado para proteção de estouro do buffer no código compilado com [\/GS \(verificação de segurança do buffer\)](../Topic/-GS%20\(Buffer%20Security%20Check\).md) e no código que usa o tratamento de exceção.  Na entrada para uma função protegida contra estouro, o cookie é colocado na pilha e na saída o valor da pilha é comparado com o cookie global.  Qualquer diferença entre eles indica que ocorreu um estouro do buffer e causa o encerramento imediato do programa.  
  
 Normalmente, `__security_init_cookie` é chamado pelo CRT quando é inicializado.  Se você ignorar inicialização CRT, por exemplo, se usar [\/ENTRY](../../build/reference/entry-entry-point-symbol.md) para especificar um ponto de entrada, então deverá chamar `__security_init_cookie` por conta própria.  Se `__security_init_cookie` não for chamado, o cookie de segurança global será definido como um valor padrão e a proteção de estouro do buffer ficará comprometida.  Como um invasor pode explorar esse valor de cookie padrão para vencer as verificações de estouro de buffer, recomendamos que você sempre chame `__security_init_cookie` ao definir seu próprio ponto de entrada.  
  
 A chamada para `__security_init_cookie` deve ser feita antes que qualquer função protegida conta estouro seja inserida. Caso contrário, será detectado um estouro de buffer falso.  Para obter mais informações, consulte [R6035 de erro de tempo de execução do C](../../error-messages/tool-errors/c-runtime-error-r6035.md).  
  
## Exemplo  
 Consulte os exemplos em [R6035 de erro de tempo de execução do C](../../error-messages/tool-errors/c-runtime-error-r6035.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`__security_init_cookie`|\<process.h\>|  
  
 `__security_init_cookie` é uma extensão da Microsoft à biblioteca padrão de tempo de execução do C.  Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Essa função só deve ser chamada a partir do código nativo, não do código gerenciado.  
  
## Consulte também  
 [Verificações de segurança do compilador em profundidade](http://go.microsoft.com/fwlink/?linkid=7260)