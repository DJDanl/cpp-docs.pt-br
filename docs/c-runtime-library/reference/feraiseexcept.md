---
title: "feraiseexcept | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "cpp"
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "feraiseexcept"
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
apitype: "HeaderDef"
f1_keywords: 
  - "feraiseexcept"
  - "fenv/feraiseexcept"
dev_langs: 
  - "C"
  - "C++"
helpviewer_keywords: 
  - "função feraiseexcept"
ms.assetid: 87e89151-83c2-4563-9a9a-45666245d437
caps.latest.revision: 3
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# feraiseexcept
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Gera as exceções de ponto flutuantes especificadas.  
  
## Sintaxe  
  
```  
int feraiseexcept(  
   int excepts  
);  
```  
  
#### Parâmetros  
 `excepts`  
 As exceções de ponto flutuantes para elevar.  
  
## Valor de retorno  
 Se todas as exceções especificadas são geradas com êxito, retornará 0.  
  
## Comentários  
 O `feraiseexcept` função tenta gerar as exceções de ponto flutuantes especificadas por `excepts`.   O `feraiseexcept` função oferece suporte a essas macros de exceção, definidas em \< fenv \>:  
  
|Macro de exceção|Descrição|  
|----------------------|---------------|  
|FE\_DIVBYZERO|Ocorreu um erro singularidade da ou poste em uma operação ponto flutuante anteriormente; um valor infinito foi criado.|  
|FE\_INEXACT|A função foi forçada a arredondar o resultado de uma operação de ponto flutuante anteriormente armazenado.|  
|FE\_INVALID|Ocorreu um erro de domínio em uma operação de ponto flutuante anteriormente.|  
|FE\_OVERFLOW|Ocorreu um erro de intervalo. o resultado de uma operação de ponto flutuante anterior era muito grande para ser representado.|  
|FE\_UNDERFLOW|O resultado de uma operação de ponto flutuante anterior era muito pequeno para ser representado na precisão total; um valor de denormal foi criado.|  
|FE\_ALLEXCEPT|O OR bit a bit de todos com suporte a exceções de ponto flutuante.|  
  
 O `excepts` argumento pode ser zero, um dos valores de exceção de macro ou bit a bit ou de duas ou mais das macros de exceção com suporte. Se uma das macros de exceção especificada é FE\_OVERFLOW ou FE\_UNDERFLOW, a exceção FE\_INEXACT poderá ser gerada como um efeito colateral.  
  
 Para usar essa função, você deve desativar otimizações de ponto flutuantes que poderiam impedir o acesso usando a `#pragma fenv_access(on)` diretiva antes da chamada. Para obter mais informações, consulte [fenv\_access](../../preprocessor/fenv-access.md).  
  
 **Specific da Microsoft:** exceções especificadas na `excepts` são gerados na ordem FE\_INVALID, FE\_DIVBYZERO, FE\_OVERFLOW, FE\_UNDERFLOW, FE\_INEXACT. No entanto, FE\_INEXACT pode ser gerado quando FE\_OVERFLOW ou FE\_UNDERFLOW é gerado, mesmo se não for especificado em `excepts`.**Fim de específico da Microsoft**  
  
## Requisitos  
  
|Função|Cabeçalho C|Cabeçalho C\+\+|  
|------------|-----------------|---------------------|  
|`feraiseexcept`|\< fenv \>|\< cfenv \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Consulte também  
 [Referência da função alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [fesetexceptflag](../Topic/fesetexceptflag2.md)   
 [feholdexcept](../../c-runtime-library/reference/feholdexcept2.md)   
 [fetestexcept](../Topic/fetestexcept1.md)   
 [feupdateenv](../Topic/feupdateenv.md)