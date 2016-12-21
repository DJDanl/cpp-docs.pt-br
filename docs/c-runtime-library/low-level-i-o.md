---
title: "E/S de n&#237;vel inferior | Microsoft Docs"
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
  - "c.io"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "identificadores de arquivo [C++]"
  - "identificadores de arquivo [C++], Funções E/S"
  - "E/S [CRT], Funções "
  - "E/S [CRT], nível inferior"
  - "rotinas de E/S de nível inferior"
ms.assetid: 53e11bdd-6720-481c-8b2b-3a3a569ed534
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# E/S de n&#237;vel inferior
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essas funções invoca o sistema operacional diretamente para a operação de nível inferior de aquele fornecido pelo fluxo de E\/S.  As chamadas de nível baixo de entrada e saída não armazenam em buffer nem formatar dados.  
  
 As rotinas de baixo nível podem acessar os fluxos padrão aberto na inicialização do programa usando os seguintes descritores de arquivo predefinidos.  
  
|Fluxo|O descritor de Arquivo|  
|-----------|----------------------------|  
|`stdin`|0|  
|`stdout`|1|  
|`stderr`|2|  
  
 As rotinas de nível baixo de E\/S definem a variável global de [errno](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md) quando ocorre um erro.  Você deve incluir STDIO.H quando você usa funções de nível baixo apenas se o programa requer uma constante que é definida em STDIO.H, como o indicador de participante de Arquivo \(`EOF`\).  
  
### Funções de nível baixo de E\/S  
  
|Função|Uso|  
|------------|---------|  
|[\_close](../Topic/_close.md)|Próximo arquivo|  
|[\_commit](../c-runtime-library/reference/commit.md)|Arquivo de nível em disco|  
|[\_creat, \_wcreat](../c-runtime-library/reference/creat-wcreat.md)|Crie o arquivo|  
|[\_dup](../c-runtime-library/reference/dup-dup2.md)|O descritor de arquivo disponível seguinte de retorno para o arquivo determinado|  
|[\_dup2](../c-runtime-library/reference/dup-dup2.md)|Crie o segundo descritor para o arquivo determinado|  
|[\_eof](../c-runtime-library/reference/eof.md)|Testar a fim de arquivo|  
|[\_lseek, \_lseeki64](../c-runtime-library/reference/lseek-lseeki64.md)|Reposicione o ponteiro de arquivo no local específico|  
|[\_open, \_wopen](../c-runtime-library/reference/open-wopen.md)|Abrir arquivo|  
|[\_read](../Topic/_read.md)|Ler os dados do arquivo|  
|[\_sopen, \_wsopen](../c-runtime-library/reference/sopen-wsopen.md), [\_sopen\_s, \_wsopen\_s](../c-runtime-library/reference/sopen-s-wsopen-s.md)|Abrir arquivo para o compartilhamento de arquivos|  
|[\_tell, \_telli64](../c-runtime-library/reference/tell-telli64.md)|Obter a posição atual do arquivo do ponteiro|  
|[\_umask](../c-runtime-library/reference/umask.md), [\_umask\_s](../Topic/_umask_s.md)|Defina a máscara de arquivo permissão|  
|[\_write](../c-runtime-library/reference/write.md)|Dados de gravação para arquivo|  
  
 `_dup` e `_dup2` normalmente são usados para associar os descritores de arquivo predefinidos com os arquivos diferentes.  
  
## Consulte também  
 [Entrada e saída](../Topic/Input%20and%20Output.md)   
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)   
 [Chamadas do sistema](../Topic/System%20Calls.md)