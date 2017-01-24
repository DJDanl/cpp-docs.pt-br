---
title: "_splitpath_s, _wsplitpath_s | Microsoft Docs"
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
  - "_wsplitpath_s"
  - "_splitpath_s"
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
  - "api-ms-win-crt-filesystem-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_wsplitpath_s"
  - "splitpath_s"
  - "_splitpath_s"
  - "wsplitpath_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _splitpath_s"
  - "Função _wsplitpath_s"
  - "nomes de caminho"
  - "nomes de caminho"
  - "Função splitpath_s"
  - "Função wsplitpath_s"
ms.assetid: 30fff3e2-cd00-4eb6-b5a2-65db79cb688b
caps.latest.revision: 29
caps.handback.revision: 29
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _splitpath_s, _wsplitpath_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Interrompe um nome de caminho em componentes.  Essas são versões de [\_splitpath, \_wsplitpath](../Topic/_splitpath,%20_wsplitpath.md) com aprimoramentos de segurança conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
errno_t _splitpath_s(  
   const char * path,  
   char * drive,  
   size_t driveNumberOfElements,  
   char * dir,  
   size_t dirNumberOfElements,  
   char * fname,  
   size_t nameNumberOfElements,  
   char * ext,   
   size_t extNumberOfElements  
);  
errno_t _wsplitpath_s(  
   const wchar_t * path,  
   wchar_t * drive,  
   size_t driveNumberOfElements,  
   wchar_t *dir,  
   size_t dirNumberOfElements,  
   wchar_t * fname,  
   size_t nameNumberOfElements,  
   wchar_t * ext,  
   size_t extNumberOfElements  
);  
template <size_t drivesize, size_t dirsize, size_t fnamesize, size_t extsize>  
errno_t _splitpath_s(  
   const char *path,  
   char (&drive)[drivesize],  
   char (&dir)[dirsize],  
   char (&fname)[fnamesize],  
   char (&ext)[extsize]  
); // C++ only  
template <size_t drivesize, size_t dirsize, size_t fnamesize, size_t extsize>  
errno_t _wsplitpath_s(  
   const wchar_t *path,  
   wchar_t (&drive)[drivesize],  
   wchar_t (&dir)[dirsize],  
   wchar_t (&fname)[fnamesize],  
   wchar_t (&ext)[extsize]  
); // C++ only  
```  
  
#### Parâmetros  
 \[entrada\] `path`  
 Caminho completo.  
  
 \[saída\] `drive`  
 Letra de unidade, seguido por dois\-pontos \(`:`\).  Você pode passar `NULL` para este parâmetro se você não precisar mais da letra da unidade.  
  
 \[entrada\] `driveNumberOfElements`  
 O tamanho do buffer de `drive` em um byte ou em caracteres amplos.  Se `drive` é `NULL`, este valor deve ser 0.  
  
 \[saída\] `dir`  
 Caminho de diretório, inclusive a barra à direita.  As barras \( `/` \), as barras invertidas \( `\` \), ou ambos podem ser usadas.  Você pode passar `NULL` para este parâmetro se você não precisa do caminho de diretório.  
  
 \[entrada\] `dirNumberOfElements`  
 O tamanho do buffer de `dir` em um byte ou em caracteres amplos.  Se `dir` é `NULL`, este valor deve ser 0.  
  
 \[saída\] `fname`  
 Nome de arquivo base \(sem a extensão\).  Você pode passar `NULL` para este parâmetro se você não precisa do nome de arquivo.  
  
 \[entrada\] `nameNumberOfElements`  
 O tamanho do buffer de `fname` em um byte ou em caracteres amplos.  Se `fname` é `NULL`, este valor deve ser 0.  
  
 \[saída\] `ext`  
 Extensão de nome de arquivo, incluindo período principal \(**.**\). Você pode passar `NULL` para este parâmetro se você não precisar mais da extensão de nome de arquivo.  
  
 \[entrada\] `extNumberOfElements`  
 O tamanho do buffer de `ext` em um byte ou em caracteres amplos.  Se `ext` é `NULL`, este valor deve ser 0.  
  
## Valor de retorno  
 Zero se tiver êxito; um código de erro em falha.  
  
### Condições de erro  
  
|Condição|Valor de Retorno|  
|--------------|----------------------|  
|`path` é `NULL`|`EINVAL`|  
|`drive` é `NULL`, `driveNumberOfElements` for diferente de zero|`EINVAL`|  
|`drive` é`NULL`não, `driveNumberOfElements` é zero|`EINVAL`|  
|`dir` é `NULL`, `dirNumberOfElements` for diferente de zero|`EINVAL`|  
|`dir` é`NULL`não, `dirNumberOfElements` é zero|`EINVAL`|  
|`fname` é `NULL`, `nameNumberOfElements` for diferente de zero|`EINVAL`|  
|`fname` é`NULL`não, `nameNumberOfElements` é zero|`EINVAL`|  
|`ext` é `NULL`, `extNumberOfElements` for diferente de zero|`EINVAL`|  
|`ext` é`NULL`não, `extNumberOfElements` é zero|`EINVAL`|  
  
 Se qualquer uma das condições anteriores ocorrerem, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md) .  Se a execução puder continuar, essas funções definirão `errno` como `EINVAL` e retornarão `EINVAL`.  
  
 Se algum dos buffers são muito curtos manter o resultado, essas funções desmarque todos os buffers em cadeias de caracteres vazias, definem `errno` a `ERANGE`, e o retorno `ERANGE`.  
  
## Comentários  
 A função de `_splitpath_s` interrompe um caminho nos quatro componentes.  `_splitpath_s` controla automaticamente argumentos de cadeia de caracteres de multibyte\- caracteres conforme apropriado, confirmando sequências de multibyte\- caractere de acordo com a página de código de multibyte atualmente em uso.  `_wsplitpath_s` é uma versão de ampla caractere de `_splitpath_s`; os argumentos a `_``wsplitpath_s`são cadeias de caracteres de ampla caractere.  Essas funções se comportam de outra forma idêntica  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tsplitpath_s`|`_splitpath_s`|`_splitpath_s`|`_wsplitpath_s`|  
  
 Cada componente do caminho completo é armazenado em um buffer separado; as constantes manifestas `_MAX_DRIVE`, `_MAX_DIR`, `_MAX_FNAME`, e `_MAX_EXT` \(\) definido em STDLIB.H especificar o tamanho máximo permitido para cada componente do arquivo.  Arquivo dos componentes maiores que o dano manifesto correspondente do heap da causa das constantes.  
  
 A tabela a seguir lista os valores de constantes manifestas.  
  
|Nome|Valor|  
|----------|-----------|  
|\_MAX\_DRIVE|3|  
|\_MAX\_DIR|256|  
|\_MAX\_FNAME|256|  
|\_MAX\_EXT|256|  
  
 Se o caminho completo não tiver um componente \(por exemplo, um nome de arquivo\), `_splitpath_s` atribui uma cadeia de caracteres vazia ao buffer correspondente.  
  
 No C\+\+, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem interpretar o tamanho do buffer automaticamente, eliminando a necessidade de especificar um argumento de tamanho.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
 As versões de depuração dessas funções preenchem primeiro o buffer com 0xFD.  Para desabilitar esse comportamento, use [\_CrtSetDebugFillThreshold](../../c-runtime-library/reference/crtsetdebugfillthreshold.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_splitpath_s`|\<stdlib.h\>|  
|`_wsplitpath_s`|\<stdlib.h\> ou \<wchar.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
 Consulte o exemplo de [\_makepath\_s, \_wmakepath\_s](../../c-runtime-library/reference/makepath-s-wmakepath-s.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Manipulação de arquivos](../../c-runtime-library/file-handling.md)   
 [\_splitpath, \_wsplitpath](../Topic/_splitpath,%20_wsplitpath.md)   
 [\_fullpath, \_wfullpath](../../c-runtime-library/reference/fullpath-wfullpath.md)   
 [\_getmbcp](../../c-runtime-library/reference/getmbcp.md)   
 [\_makepath, \_wmakepath](../../c-runtime-library/reference/makepath-wmakepath.md)   
 [\_setmbcp](../../c-runtime-library/reference/setmbcp.md)