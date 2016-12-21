---
title: "Constantes errno | Microsoft Docs"
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
  - "ENOEXEC"
  - "ENOMEM"
  - "E2BIG"
  - "STRUNCATE"
  - "ENOENT"
  - "EMFILE"
  - "EBADF"
  - "EDEADLOCK"
  - "EXDEV"
  - "EILSEQ"
  - "EINVAL"
  - "EDOM"
  - "EACCES"
  - "ERANGE"
  - "ENOSPC"
  - "EAGAIN"
  - "EEXIST"
  - "ECHILD"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Constante E2BIG"
  - "Constante EACCES"
  - "Constante EAGAIN"
  - "Constante EBADF"
  - "Constante ECHILD"
  - "Constante EDEADLOCK"
  - "Constante EDOM"
  - "Constante EEXIST"
  - "Constante EILSEQ"
  - "Constante EINVAL"
  - "Constante EMFILE"
  - "Constante ENOENT"
  - "Constante ENOEXEC"
  - "Constante ENOMEM"
  - "Constante ENOSPC"
  - "Constante ERANGE"
  - "Constantes errno"
  - "Constante EXDEV"
  - "Constante STRUNCATE"
ms.assetid: 47089258-d5a5-4cd8-b193-223894dea0cf
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Constantes errno
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
#include <errno.h>  
```  
  
## Comentários  
 Os valores de **errno** constantes são atribuídas a [errno](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md) no caso de várias condições de erro.  
  
 ERRNO.H contém as definições dos valores de **errno** .  Porém, nem todas as definições fornecidas em ERRNO.H são usadas em sistemas operacionais Windows de 32 bits.  Alguns dos valores em ERRNO.H estão presentes para manter a compatibilidade com a família do UNIX de sistemas operacionais.  
  
 Os valores de **errno** em um sistema operacional Windows de 32 bits são um subconjunto dos valores para **errno** em sistemas de XENIX.  Assim, o valor de **errno** não é necessariamente o mesmo que o código de erro real retornado por uma chamada do sistema dos sistemas operacionais Windows.  Para acessar o código de erro real do sistema operacional, use a variável de [\_doserrno](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md) , que contém esse valor.  
  
 Os seguintes valores de **errno** têm suporte:  
  
 **ECHILD**  
 Nenhum processos desovados.  
  
 **EAGAIN**  
 Não mais processos.  Uma tentativa de criar um novo processo falhou porque não há mais slot do processo, ou se não houver memória suficiente, ou o nível de aninhamento máximo for atingido.  
  
 **E2BIG**  
 Lista de argumentos muito longa.  
  
 **EACCES**  
 Permissão negada.  A configuração de permissão do arquivo não permite o acesso especificado.  Esse erro significa que esteve feita uma tentativa de acessar um arquivo \(ou, em alguns casos, um diretório\) de uma maneira que seja incompatível com os atributos de arquivo.  
  
 Por exemplo, o erro pode ocorrer quando for feita uma tentativa de ler de um arquivo que não está aberto, para abrir um arquivo somente leitura existente para escrever, ou para abrir um diretório em vez de um arquivo.  Nas versões 3,0 do sistema operacional do MS\-DOS e posterior, **EACCES** também pode indicar um bloqueio ou violação compartilhar.  
  
 O erro também pode ocorrer na tentativa de renomear um arquivo ou um diretório ou remover um diretório existente.  
  
 **EBADF**  
 Número de arquivo incorreto.  Há duas causas possíveis: 1\) O descritor de arquivo especificado não é um valor válido ou não se refere a um arquivo aberto. 2\) Foi feita uma tentativa de gravar em um arquivo ou um dispositivo aberto para acesso somente leitura.  
  
 **EDEADLOCK**  
 O deadlock de recursos ocorrerá.  O argumento para uma função matemática não estiver no domínio da função.  
  
 **EDOM**  
 Argumento matemática.  
  
 **EEXIST**  
 Os arquivos existentes.  Foi feita uma tentativa de criar um arquivo que já existe.  Por exemplo, **\_O\_CREAT** e sinalizadores de **\_O\_EXCL** são especificados em uma chamada de **\_open** , mas o arquivo nomeado já existe.  
  
 **EILSEQ**  
 Sequência ilegal de bytes \(por exemplo, em uma cadeia de caracteres de MBCS\).  
  
 **EINVAL**  
 Argumento inválido.  Um valor inválido foi atribuído a um dos argumentos para uma função.  Por exemplo, o valor atribuído à origem quando posicionar um ponteiro de arquivo \(por meio de uma chamada a **fseek**\) é antes do início do arquivo.  
  
 **EMFILE**  
 Arquivos abertos demais.  Não mais descritor de arquivo estiver disponível, o que não mais arquivo pode ser aberto.  
  
 **ENOENT**  
 Tal arquivo ou diretório.  O arquivo ou diretório especificado não existir ou não podem ser encontrados.  Essa mensagem pode ocorrer sempre que um arquivo especificado não existe ou um componente de um caminho não especificar um diretório existente.  
  
 **ENOEXEC**  
 Erro de formato exec.  Foi feita uma tentativa de executar um arquivo que não sejam executável ou que tem um formato de arquivo executável inválido.  
  
 **ENOMEM**  
 Insuficiente retiram o principal.  Não há memória suficiente para o operador tentado.  Por exemplo, essa mensagem pode ocorrer quando memória insuficiente disponível para executar um processo filho, ou quando a solicitação de alocação em uma chamada de **\_getcwd** não pode ser atendida.  
  
 **ENOSPC**  
 Nenhum espaço remanescente no dispositivo.  Não mais espaço para gravar está disponível no dispositivo \(por exemplo, quando o disco está cheio\).  
  
 **ERANGE**  
 Resultado muito grande.  Um argumento para uma função matemática é muito grande, o que resulta em perda de significância parcial ou total no resultado.  Esse erro também pode ocorrer em outras funções quando um argumento é maior do que o esperado \(por exemplo, quando o argumento *de buffer* a **\_getcwd** for mais longo que o esperado.\)  
  
 **EXDEV**  
 Link entre de dispositivo.  Foi feita uma tentativa de mover um arquivo a um dispositivo diferente \(que usa a função de **rename** \).  
  
 **STRUNCATE**  
 Uma cópia ou uma concatenação de cadeia de caracteres resultaram em uma cadeia de caracteres truncado.  Consulte [\_TRUNCATE](../c-runtime-library/truncate.md).  
  
 Os seguintes valores têm suporte para compatibilidade com Posix.  Valores são necessários em sistemas de non\-Posix.  
  
```  
#define E2BIG [argument list too long]  
#define EACCES [permission denied]  
#define EADDRINUSE [address in use]  
#define EADDRNOTAVAIL [address not available]  
#define EAFNOSUPPORT [address family not supported]  
#define EAGAIN [resource unavailable try again]  
#define EALREADY [connection already in progress]  
#define EBADF [bad file descriptor]  
#define EBADMSG [bad message]  
#define EBUSY [device or resource busy]  
#define ECANCELED [operation canceled]  
#define ECHILD [no child process]  
#define ECONNABORTED [connection aborted]  
#define ECONNREFUSED [connection refused]  
#define ECONNRESET [connection reset]  
#define EDEADLK [resource deadlock would occur]  
#define EDESTADDRREQ [destination address required]  
#define EDOM [argument out of domain]  
#define EEXIST [file exists]  
#define EFAULT [bad address]  
#define EFBIG [file too large]  
#define EHOSTUNREACH [host unreachable]  
#define EIDRM [identifier removed]  
#define EILSEQ [illegal byte sequence]  
#define EINPROGRESS [operation in progress]  
#define EINTR [interrupted]  
#define EINVAL [invalid argument]  
#define EIO [io error]  
#define EISCONN [already connected]  
#define EISDIR [is a directory]  
#define ELOOP [too many synbolic link levels]  
#define EMFILE [too many files open]  
#define EMLINK [too many links]  
#define EMSGSIZE [message size]  
#define ENAMETOOLONG [filename too long]  
#define ENETDOWN [network down]  
#define ENETRESET [network reset]  
#define ENETUNREACH [network unreachable]  
#define ENFILE [too many files open in system]  
#define ENOBUFS [no buffer space]  
#define ENODATA [no message available]  
#define ENODEV [no such device]  
#define ENOENT [no such file or directory]  
#define ENOEXEC [executable format error]  
#define ENOLCK [no lock available]  
#define ENOLINK [no link]  
#define ENOMEM [not enough memory]  
#define ENOMSG [no message]  
#define ENOPROTOOPT [no protocol option]  
#define ENOSPC [no space on device]  
#define ENOSR [no stream resources]  
#define ENOSTR [not a stream]  
#define ENOSYS [function not supported]  
#define ENOTCONN [not connected]  
#define ENOTDIR [not a directory]  
#define ENOTEMPTY [directory not empty]  
#define ENOTRECOVERABLE [state not recoverable]  
#define ENOTSOCK [not a socket]  
#define ENOTSUP [not supported]  
#define ENOTTY [inappropriate io control operation]  
#define ENXIO [no such device or address]  
#define EOPNOTSUPP [operation not supported]  
#define EOTHER [other]  
#define EOVERFLOW [value too large]  
#define EOWNERDEAD [owner dead]  
#define EPERM [operation not permitted]  
#define EPIPE [broken pipe]  
#define EPROTO [protocol error]  
#define EPROTONOSUPPORT [protocol not supported]  
#define EPROTOTYPE [wrong protocol type]  
#define ERANGE [result out of range]  
#define EROFS [read only file system]  
#define ESPIPE [invalid seek]  
#define ESRCH [no such process]  
#define ETIME [stream timeout]  
#define ETIMEDOUT [timed out]  
#define ETXTBSY [text file busy]  
#define EWOULDBLOCK [operation would block]  
#define EXDEV [cross device link]  
```  
  
## Consulte também  
 [Constantes globais](../c-runtime-library/global-constants.md)