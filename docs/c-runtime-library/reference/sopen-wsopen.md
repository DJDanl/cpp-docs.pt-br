---
title: "_sopen, _wsopen | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_sopen"
  - "_wsopen"
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
  - "api-ms-win-crt-stdio-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_wsopen"
  - "wsopen"
  - "_sopen"
  - "_tsopen"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _sopen"
  - "Função _wsopen"
  - "Arquivos  [C++], abertura"
  - "Arquivos  [C++], compartilhamento"
  - "abrindo arquivos, para compartilhamento"
  - "compartilhando arquivos"
  - "Função sopen"
  - "Função wsopen"
ms.assetid: a9d4cccf-06e9-414d-96fa-453fca88cc1f
caps.latest.revision: 21
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _sopen, _wsopen
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Abre um arquivo para compartilhamento.  Estão disponíveis versões mais seguras dessas funções; consulte [\_sopen\_s, \_wsopen\_s](../../c-runtime-library/reference/sopen-s-wsopen-s.md).  
  
## Sintaxe  
  
```  
int _sopen(    const char *filename,    int oflag,    int shflag [,    int pmode ]  ); int _wsopen(    const wchar_t *filename,    int oflag,    int shflag [,    int pmode ]  );  
```  
  
#### Parâmetros  
 `filename`  
 Nome do arquivo.  
  
 `oflag`  
 Os tipos de operações permitidas.  
  
 `shflag`  
 O tipo de compartilhamento permitido.  
  
 `pmode`  
 Configuração de permissão.  
  
## Valor de retorno  
 Cada uma destas funções mostra um descritor de arquivo do arquivo aberto.  
  
 Se `filename` ou `oflag` for um ponteiro `NULL`, ou se `oflag` ou `shflag` não for um intervalo de valores válido, o manipulador de parâmetros será invocado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções retornarão \-1 e definirão `errno` como um dos valores a seguir.  
  
 `EACCES`  
 O caminho determinado é um diretório ou o arquivo é somente leitura, mas foi realizada uma tentativa de operação de abertura para gravação.  
  
 `EEXIST`  
 `_O_CREAT` e sinalizadores `_O_EXCL` foram especificados, mas `filename` já existe.  
  
 `EINVAL`  
 Argumento `oflag` ou `shflag` inválido.  
  
 `EMFILE`  
 Nenhum outro descritor de arquivo disponível.  
  
 `ENOENT`  
 Arquivo ou caminho não encontrado.  
  
 Para obter mais informações sobre esses e outros códigos de retorno, consulte [\_doserrno, errno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 A função `_sopen` abre o arquivo especificado por `filename` e prepara o arquivo para leitura ou gravação compartilhada, como definido por `oflag` e `shflag`.  `_wsopen` é uma versão de caractere largo de `_sopen`; o argumento `filename` para `_wsopen` é uma cadeia de caracteres larga.  Caso contrário, `_wsopen` e `_sopen` se comportam de forma idêntica.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tsopen`|`_sopen`|`_sopen`|`_wsopen`|  
  
 A expressão do inteiro `oflag` é formada combinando uma ou mais das constantes de manifesto a seguir, definidas em \<fcntl.h\>.  Quando duas ou mais constantes formam o argumento `oflag`, elas são combinadas com o operador OR bit a bit \(  `|` \).  
  
 `_O_APPEND`  
 Reposiciona um ponteiro de arquivo no final do arquivo, antes de cada operação de gravação.  
  
 `_O_BINARY`  
 Abre um arquivo no modo binário \(não convertido\).  \(Consulte [fopen](../../c-runtime-library/reference/fopen-wfopen.md) para obter uma descrição do modo binário.\)  
  
 `_O_CREAT`  
 Cria um arquivo e o abre para gravação.  Não terá efeito algum se o arquivo especificado por `filename` já existir.  O argumento `pmode` é necessário quando `_O_CREAT` é especificada.  
  
 `_O_CREAT | _O_SHORT_LIVED`  
 Cria um arquivo temporário e, se possível, não alinha com o disco.  O argumento `pmode` é necessário quando `_O_CREAT` é especificada.  
  
 `_O_CREAT | _O_TEMPORARY`  
 Cria um arquivo temporário, que é excluído quando o último descritor de arquivo é fechado.  O argumento `pmode` é necessário quando `_O_CREAT` é especificada.  
  
 `_O_CREAT | _O_EXCL`  
 Retorna um valor de erro se o arquivo especificado por `filename` existir.  Aplica\-se somente quando usado com `_O_CREAT`.  
  
 `_O_NOINHERIT`  
 Impede a criação de um descritor de arquivo compartilhado.  
  
 `_O_RANDOM`  
 Especifica principalmente acesso aleatório do disco.  
  
 `_O_RDONLY`  
 Abre um arquivo somente leitura.  Não pode ser especificado com `_O_RDWR` ou `_O_WRONLY`.  
  
 `_O_RDWR`  
 Abre um arquivo para leitura e gravação.  Não pode ser especificado com  ou `_O_WRONLY`.  
  
 `_O_SEQUENTIAL`  
 Especifica principalmente acesso sequencial do disco.  
  
 `_O_TEXT`  
 Abre um arquivo no modo de texto \(convertido\).  \(Para obter mais informações, consulte [E\/S de Texto e Arquivo de Modo Binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md) e [fopen](../../c-runtime-library/reference/fopen-wfopen.md).\)  
  
 `_O_TRUNC`  
 Abre um arquivo e o trunca para que ele fique com tamanho zero; o arquivo deve ter permissão de gravação.  Não pode ser especificado com `_O_RDONLY`.  `_O_TRUNC` usado com `_O_CREAT` abre um arquivo existente ou cria um.  
  
> [!NOTE]
>  ‏O sinalizador `_O_TRUNC` destrói o conteúdo do arquivo especificado.  
  
 `_O_WRONLY`  
 Abre um arquivo somente gravação.  Não pode ser especificado com `_O_RDONLY` ou `_O_RDWR`.  
  
 `_O_U16TEXT`  
 Abre um arquivo no modo Unicode UTF\-16.  
  
 `_O_U8TEXT`  
 Abre um arquivo no modo Unicode UTF\-8.  
  
 `_O_WTEXT`  
 Abre um arquivo no modo Unicode.  
  
 Para especificar o modo de acesso ao arquivo, você deve especificar `_O_RDONLY`, `_O_RDWR` ou `_O_WRONLY`.  Não há um valor padrão para o modo de acesso.  
  
 Quando o arquivo é aberto no modo Unicode com a constante `_O_WTEXT`, `_O_U8TEXT` ou `_O_U16TEXT`, as funções de entrada convertem os dados do arquivo em dados UTF\-16 armazenados como tipo `wchar_t`.  Funções que gravam em arquivos abertos no modo Unicode esperam buffers que contenham dados UTF\-16 armazenados como tipo `wchar_t`.  Se o arquivo estiver codificado como UTF\-8, os dados em UTF\-16 serão convertidos em UTF\-8 no momento da gravação. O conteúdo do arquivo codificado como UTF\-8 será convertido em UTF\-16 no momento da leitura.  Tentar ler ou gravar uma quantidade ímpar de bytes no modo Unicode gera um erro de validação de parâmetro.  Para ler ou gravar dados armazenados em seu programa como UTF\-8, use um modo de arquivo de texto ou binário em vez do modo Unicode.  Você é responsável por toda a conversão de codificação necessária.  
  
 Se `_sopen` for chamado com `_O_WRONLY | _O_APPEND` \(modo de acréscimo\) e `_O_WTEXT`, `_O_U16TEXT` ou `_O_U8TEXT`, ela tentará abrir o arquivo para leitura e gravação, lerá a BOM e reabrirá o arquivo somente gravação.  Se uma falha impedir de abrir o arquivo para leitura e gravação, ele será aberto somente para gravação e usará o valor padrão na configuração do modo Unicode.  
  
 O argumento `shflag` é uma expressão constante formada por uma das seguintes constantes de manifesto, definidas em \<share.h\>.  
  
 `_SH_DENYRW`  
 Nega acesso de leitura e gravação a um arquivo.  
  
 `_SH_DENYWR`  
 Nega acesso de gravação a um arquivo.  
  
 `_SH_DENYRD`  
 Nega acesso de leitura a um arquivo.  
  
 `_SH_DENYNO`  
 Permite acesso de leitura e gravação.  
  
 O argumento `pmode` só é necessário quando `_O_CREAT` é especificada.  Caso o arquivo não exista, `pmode` especifica as configurações de permissão do arquivo, que são definidas quando o novo arquivo é fechado pela primeira vez.  Caso contrário, `pmode` é ignorado.  `pmode` é uma expressão de inteiro que contém uma ou ambas as constantes de manifesto `_S_IWRITE` e `_S_IREAD`, definidas em \<sys\\stat.h\>.  Quando as duas constantes são fornecidas, elas são combinadas com o operador OR bit a bit.  O significado de `pmode` é o seguinte.  
  
 `_S_IWRITE`  
 Gravação permitida.  
  
 `_S_IREAD`  
 Leitura permitida.  
  
 `_S_IREAD | _S_IWRITE`  
 Leitura e gravação permitidas.  
  
 Se a permissão de gravação não for fornecida, o arquivo será somente leitura.  No sistema operacional Windows, todos os arquivos podem ser lidos; não é possível conceder permissão de somente gravação.  Portanto, os modos `_S_IWRITE` e `_S_IREAD | _S_IWRITE` são equivalentes.  
  
 `_sopen` aplica a máscara de permissão de arquivo atual a `pmode` antes que as permissões sejam definidas.  \(Consulte [\_umask](../../c-runtime-library/reference/umask.md).\)  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|------------|--------------------------|------------------------|  
|`_sopen`|\<io.h\>|\<fcntl.h\>, \<sys\\types.h\>, \<sys\\stat.h\>, \<share.h\>|  
|`_wsopen`|\<io.h\> ou \<wchar.h\>|\<fcntl.h\>, \<sys\\types.h\>, \<sys\\stat.h\>, \<share.h\>|  
  
 Para obter mais informações de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
 Veja o exemplo de [\_locking](../Topic/_locking.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [E\/S de nível inferior](../../c-runtime-library/low-level-i-o.md)   
 [\_close](../Topic/_close.md)   
 [\_creat, \_wcreat](../../c-runtime-library/reference/creat-wcreat.md)   
 [fopen, \_wfopen](../../c-runtime-library/reference/fopen-wfopen.md)   
 [\_fsopen, \_wfsopen](../../c-runtime-library/reference/fsopen-wfsopen.md)   
 [\_open, \_wopen](../../c-runtime-library/reference/open-wopen.md)