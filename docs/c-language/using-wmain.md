---
title: "Usando wmain | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "função wmain"
ms.assetid: d0300812-adc4-40c6-bba3-b2da25468c80
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando wmain
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 No modelo de programação Unicode, você pode definir uma versão de caractere largo da função **main**.  Use **wmain** em vez de **main** se você quiser escrever o código portátil que obedeça ao modelo de programação de Unicode.  
  
## Sintaxe  
  
```  
wmain( int argc, wchar_t *argv[ ], wchar_t *envp[ ] )  
```  
  
## Comentários  
 Você declara parâmetros formais para **wmain** usando um formato semelhante ao de **main**.  Em seguida, pode passar argumentos de caractere largo e, opcionalmente, um ponteiro de ambiente de caractere largo para o programa.  Os parâmetros `argv` e `envp` de **wmain** são do tipo `wchar_t*`.  Por exemplo:  
  
 Se seu programa usa uma função **main**, o ambiente de caractere multibyte é criado pela biblioteca em tempo de execução na inicialização do programa.  Uma cópia de caractere amplo do ambiente é criada apenas quando necessário \(por exemplo, por uma chamada para as funções `_wgetenv` ou `_wputenv`\).  Na primeira chamada para `_wputenv`, ou na primeira chamada para `_wgetenv` se um ambiente MBCS já existir, um ambiente correspondente de cadeia de caracteres largos será criado. Em seguida, a variável global `_wenviron`, uma versão de caractere largo da variável global `_environ`, apontará para esse ambiente.  Nesse momento, duas cópias do ambiente \(MBCS e Unicode\) existirão simultaneamente e serão mantidas pelo sistema operacional durante toda a vida do programa.  
  
 Da mesma forma, se seu programa usar uma função **wmain**, um ambiente de caractere amplo é criado na inicialização do programa e apontado pela variável global `_wenviron`.  Um ambiente de MBCS \(ASCII\) é criado na primeira chamada para `_putenv` ou `getenv` e apontado pela variável global `_environ`.  
  
 Para obter mais informações sobre o ambiente de MBCS, consulte [Internacionalização](../c-runtime-library/internationalization.md) na *Referência da biblioteca em tempo de execução.*  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Função main e execução do programa](../c-language/main-function-and-program-execution.md)