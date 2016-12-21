---
title: "raise | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "raise"
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
  - "Raise"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "sinais, enviando aos programas em execução"
  - "Função raise"
  - "sinais"
  - "programas [C++], enviando sinais aos programas em execução"
ms.assetid: a3ccd3ad-f68f-4a7b-a005-c3ebfb217e8b
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# raise
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Envia um sinal para o programa em execução.  
  
> [!NOTE]
>  Não use esse método para desligar um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo, exceto em teste ou cenários de depuração. Formas de programação ou da interface do usuário para fechar um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo não são permitidos de acordo com a seção 3.6 do [requisitos de certificação de aplicativos do Windows 8](http://go.microsoft.com/fwlink/?LinkId=262889). Para obter mais informações, consulte [ciclo de vida do aplicativo \(aplicativos da Windows Store\)](http://go.microsoft.com/fwlink/?LinkId=262853).  
  
## Sintaxe  
  
```  
  
int  
raise(  
int  
sig  
);  
  
```  
  
#### Parâmetros  
 *SIG*  
 Sinal a ser gerado.  
  
## Valor de retorno  
 Se for bem\-sucedido, **Gerar** retornará 0. Caso contrário, ele retorna um valor diferente de zero.  
  
## Comentários  
 O **Gerar** função envia *sig* para o programa em execução. Se uma chamada anterior a **sinal** instalou uma função de manipulação de sinal para *sig*, **Gerar** executa essa função. Se nenhuma função de manipulador tiver sido instalada, a ação padrão associada com o valor de sinal *sig* é obtido, da seguinte maneira.  
  
|Sinal|Significado|Padrão|  
|-----------|-----------------|------------|  
|`SIGABRT`|Encerramento anormal|Encerra o programa de chamada com o código de saída 3|  
|`SIGFPE`|Erro de ponto flutuante|Encerra o programa de chamada|  
|`SIGILL`|Instrução ilegal|Encerra o programa de chamada|  
|`SIGINT`|Interrupção CTRL \+ C|Encerra o programa de chamada|  
|`SIGSEGV`|Acesso de armazenamento inválido|Encerra o programa de chamada|  
|`SIGTERM`|Solicitação de encerramento enviada ao programa|Ignora o sinal|  
  
 Se o argumento não é um sinal válido especificados acima, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se não tratada, define a função `errno` para `EINVAL` e retorna um valor diferente de zero.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|**raise**|\< signal \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Libraries  
 Todas as versões do [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Processo e controle de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [abort](../../c-runtime-library/reference/abort.md)   
 [signal](../../c-runtime-library/reference/signal.md)