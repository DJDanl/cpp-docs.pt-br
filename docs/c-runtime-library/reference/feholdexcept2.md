---
title: "feholdexcept | Microsoft Docs"
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
  - "feholdexcept"
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
  - "api-ms-win-crt-runtime-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "feholdexcept"
  - "fenv/feholdexcept"
dev_langs: 
  - "C"
  - "C++"
helpviewer_keywords: 
  - "função feholdexcept"
ms.assetid: 88e512ae-b5d8-452c-afe9-c824cd3ef1d8
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# feholdexcept
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Salva o ambiente atual de ponto flutuante no objeto especificado, limpa os sinalizadores de status do ponto flutuante e, se possível, coloca o ambiente de ponto flutuante no modo contínuo.  
  
## Sintaxe  
  
```  
int feholdexcept(  
   fenv_t *penv  
);  
  
```  
  
#### Parâmetros  
 `penv`  
 Ponteiro para uma `fenv_t` objeto contenha uma cópia do ambiente de ponto flutuante.  
  
## Valor de retorno  
 Retorna zero se e somente se a função é capaz de ativar o tratamento de exceções de ponto flutuante contínuas com êxito.  
  
## Comentários  
 O `feholdexcept` função é usada para armazenar o estado do atual ambiente de ponto flutuante no `fenv_t` objeto apontado por `penv`, e para definir o ambiente para não interromper a execução em exceções de ponto flutuante. Isso é conhecido como modo contínuo.  Esse modo continua até que o ambiente é restaurado usando [fesetenv](../Topic/fesetenv2.md) ou [feupdateenv](../Topic/feupdateenv.md).  
  
 Você pode usar essa função no início de uma sub\-rotina que precisa para ocultar uma ou mais exceções de ponto flutuantes do chamador. Para relatar uma exceção, basta limpar as exceções indesejadas usando [feclearexcept,](../../c-runtime-library/reference/feclearexcept1.md) e encerre o modo contínuo com uma chamada para `feupdateenv`.  
  
 Para usar essa função, você deve desativar otimizações de ponto flutuantes que poderiam impedir o acesso usando a `#pragma fenv_access(on)` diretiva antes da chamada. Para obter mais informações, consulte [fenv\_access](../../preprocessor/fenv-access.md).  
  
## Requisitos  
  
|Função|Cabeçalho C|Cabeçalho C\+\+|  
|------------|-----------------|---------------------|  
|`feholdexcept`|\< fenv \>|\< cfenv \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Consulte também  
 [Referência da função alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [feclearexcept](../../c-runtime-library/reference/feclearexcept1.md)   
 [fesetenv](../Topic/fesetenv2.md)   
 [feupdateenv](../Topic/feupdateenv.md)