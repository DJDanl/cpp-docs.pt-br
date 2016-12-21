---
title: "_environ, _wenviron | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "environ"
  - "wenviron"
  - "_wenviron"
  - "_environ"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _environ"
  - "Função _wenviron"
  - "Função environ"
  - "ambiente de processo"
  - "Função wenviron"
ms.assetid: 7e639962-6536-47cd-8095-0cbe44a56e03
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _environ, _wenviron
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O `_environ` variável é um ponteiro para uma matriz de ponteiros para as cadeias de caracteres multibyte que constituem o ambiente do processo.  Essa variável global foi substituído para as versões funcionais mais seguras [getenv\_s, \_wgetenv\_s](../c-runtime-library/reference/getenv-s-wgetenv-s.md) e [\_putenv\_s, \_wputenv\_s](../c-runtime-library/reference/putenv-s-wputenv-s.md), que deve ser usado no lugar de variável global.  `_environ` é declarado em stdlib. h.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções de CRT sem suporte com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
extern char **_environ;  
```  
  
## Comentários  
 Em um programa que usa a `main` função `_environ` inicializados na inicialização do programa de acordo com as obtidas do ambiente do sistema operacional.  O ambiente consiste em uma ou mais entradas do formulário  
  
 `ENVVARNAME` `=string`  
  
 `getenv_s` e `putenv_s` usar o `_environ` variável para acessar e modificar a tabela de ambiente.  Quando `_putenv` é chamado para adicionar ou excluir configurações de ambiente, a tabela de ambiente muda de tamanho.  Sua localização na memória também pode mudar, dependendo dos requisitos de memória do programa.  O valor de `_environ` será automaticamente ajustada.  
  
 O `_wenviron` variável declarada em stdlib. h como:  
  
```  
extern wchar_t **_wenviron;  
```  
  
 é uma versão de caractere largo de `_environ`.  Em um programa que usa a `wmain` função `_wenviron` inicializados na inicialização do programa de acordo com as obtidas do ambiente do sistema operacional.  
  
 Em um programa que usa `main`, `_wenviron` é inicialmente `NULL` porque o ambiente é composto de cadeias de caracteres multibyte.  Na primeira chamada para `_wgetenv` ou `_wputenv`, um ambiente de cadeia de caracteres largos correspondente é criado e é apontado pelo `_wenviron`.  
  
 Da mesma forma, em um programa que usa `wmain`, `_environ` é inicialmente `NULL` porque o ambiente é composto de cadeias de caracteres largos.  Na primeira chamada para `_getenv` ou `_putenv`, um ambiente de cadeia de caracteres multibyte correspondente é criado e é apontado pelo `_environ`.  
  
 Quando duas cópias do ambiente \(MBCS e Unicode\) existem simultaneamente em um programa, o sistema de tempo de execução deve manter as duas cópias, resultando em tempo de execução mais lento.  Por exemplo, sempre que você chamar `_putenv`, uma chamada para `_wputenv` também é executado automaticamente, para que as cadeias de caracteres de dois ambiente correspondem.  
  
> [!CAUTION]
>  Em casos raros, quando o sistema de tempo de execução é manter uma versão Unicode e uma multibyte versão do ambiente, essas versões dois ambiente podem não corresponder exatamente.  Isso ocorre porque, embora qualquer cadeia de caracteres multibyte exclusiva é mapeado para uma cadeia de caracteres Unicode exclusiva, o mapeamento de uma cadeia de caracteres Unicode exclusivo para uma cadeia de caracteres multibyte não é necessariamente exclusivo.  Portanto, duas cadeias de caracteres distintas do Unicode podem ser mapeado para a mesma cadeia de caracteres multibyte.  
  
 Sondagem `_environ` em Unicode contexto é insignificante quando [\/MD](../build/reference/md-mt-ld-use-run-time-library.md) ou `/MDd` vinculação é usada.  Para a DLL de CRT, o tipo \(multibyte ou largo\) do programa é desconhecido.  Somente o tipo de multibyte é criado porque esse é o cenário mais provável.  
  
 O pseudocódigo a seguir ilustra como isso pode acontecer.  
  
```  
int i, j;  
i = _wputenv( "env_var_x=string1" );  // results in the implicit call:  
                                      // putenv ("env_var_z=string1")  
j = _wputenv( "env_var_y=string2" );  // also results in implicit call:  
                                      // putenv("env_var_z=string2")  
```  
  
 A notação usada para este exemplo, as cadeias de caracteres não são literais de cadeia de caracteres C; em vez disso, eles são espaços reservados que representam os literais de cadeia de caracteres de ambiente Unicode no `_wputenv` cadeias de caracteres de ambiente chamada e multibyte no `putenv` chamar.  Espaços reservados de caractere`x`'e'`y`' no Unicode distintos duas cadeias de caracteres de ambiente não mapeiam exclusivamente aos caracteres MBCS o atual.  Em vez disso, são mapeados para alguns caracteres MBCS '`z`' que é o resultado padrão de tentativa de converter as cadeias de caracteres.  
  
 Assim, no ambiente de vários bytes, o valor de "`env_var_z`" após a primeira chamada implícita para `putenv` seria "`string1`", mas esse valor será substituída na segunda implícita chamada `putenv`, quando o valor de "`env_var_z`"é definido como"`string2`".  O ambiente de Unicode \(em `_wenviron`\) e o ambiente de vários bytes \(em `_environ`\) seriam diferentes, portanto, seguindo essa série de chamadas.  
  
## Consulte também  
 [Variáveis globais](../c-runtime-library/global-variables.md)   
 [getenv, \_wgetenv](../c-runtime-library/reference/getenv-wgetenv.md)   
 [getenv\_s, \_wgetenv\_s](../c-runtime-library/reference/getenv-s-wgetenv-s.md)   
 [\_putenv, \_wputenv](../c-runtime-library/reference/putenv-wputenv.md)   
 [\_putenv\_s, \_wputenv\_s](../c-runtime-library/reference/putenv-s-wputenv-s.md)