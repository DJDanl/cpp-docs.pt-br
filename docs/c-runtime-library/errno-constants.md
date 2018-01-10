---
title: Constantes errno | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ENOEXEC
- ENOMEM
- E2BIG
- STRUNCATE
- ENOENT
- EMFILE
- EBADF
- EDEADLOCK
- EXDEV
- EILSEQ
- EINVAL
- EDOM
- EACCES
- ERANGE
- ENOSPC
- EAGAIN
- EEXIST
- ECHILD
dev_langs: C++
helpviewer_keywords:
- ENOEXEC constant
- EBADF constant
- EAGAIN constant
- EINVAL constant
- ENOENT constant
- errno constants
- E2BIG constant
- EMFILE constant
- EDEADLOCK constant
- ENOSPC constant
- EDOM constant
- ENOMEM constant
- EACCES constant
- EEXIST constant
- STRUNCATE constant
- ERANGE constant
- ECHILD constant
- EXDEV constant
- EILSEQ constant
ms.assetid: 47089258-d5a5-4cd8-b193-223894dea0cf
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 98cc4c3afa245c55344454d4c96ea22d70905e0d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="errno-constants"></a>Constantes errno
## <a name="syntax"></a>Sintaxe  
  
```  
  
#include <errno.h>  
```  
  
## <a name="remarks"></a>Comentários  
 Os valores de **errno** são constantes atribuídas a [errno](../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) no caso de várias condições de erro.  
  
 ERRNO.H contém as definições dos valores de **errno**. No entanto, nem todas as definições fornecidas em ERRNO.H são usadas em sistemas operacionais Windows de 32 bits. Alguns dos valores em ERRNO.H estão presentes para manter a compatibilidade com a família UNIX de sistemas operacionais.  
  
 Os valores de **errno** em um sistema de operacional Windows de 32 bits são um subconjunto dos valores de **errno** em sistemas XENIX. Portanto, o valor de **errno** não é necessariamente o mesmo que o código de erro retornado por uma chamada de sistema dos sistemas operacionais Windows. Para acessar o código de erro do sistema operacional, use a variável [doserrno](../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md), que contém esse valor.  
  
 Há suporte para os seguintes valores de **errno**:  
  
 **ECHILD**  
 Nenhum processo gerado.  
  
 **EAGAIN**  
 Sem mais processos. Ocorreu uma falha ao tentar criar um novo processo, pois não há mais slot do processo, ou não há mais memória suficiente ou o nível de aninhamento máximo foi atingido.  
  
 **E2BIG**  
 A lista de argumentos é muito longa.  
  
 **EACCES**  
 Permissão negada. A configuração de permissão do arquivo não permite o acesso especificado. Esse erro indica que foi feita uma tentativa de acessar um arquivo (ou, em alguns casos, um diretório) de um modo incompatível com os atributos do arquivo.  
  
 Por exemplo, o erro pode ocorrer quando é feita uma tentativa de leitura de um arquivo que não está aberto, de abertura de um arquivo existente somente leitura para gravação ou de abertura de um diretório em vez de um arquivo. Em versões do sistema operacional MS-DOS 3.0 e posteriores, **EACCES** também pode indicar um bloqueio ou violação de compartilhamento.  
  
 O erro também pode ocorrer em uma tentativa de renomear um arquivo ou diretório ou remover um diretório existente.  
  
 **EBADF**  
 Número de arquivo incorreto. Há duas causas possíveis: 1) o descritor de arquivo especificado não é um valor válido ou não faz referência a um arquivo aberto. 2) uma tentativa foi feita para gravar em um arquivo ou dispositivo aberto para acesso somente leitura.  
  
 **EDEADLOCK**  
 Ocorreria um deadlock de recursos. O argumento para uma função matemática não está no domínio da função.  
  
 **EDOM**  
 Argumento matemático.  
  
 **EEXIST**  
 Há arquivos. Foi feita uma tentativa de criar um arquivo que já existe. Por exemplo, os sinalizadores **_O_CREAT** e **_O_EXCL** são especificados em uma chamada **_open**, mas o arquivo denominado já existe.  
  
 **EILSEQ**  
 Sequência ilegal de bytes (por exemplo, em uma cadeia de caracteres MBCS).  
  
 **EINVAL**  
 Argumento inválido. Um valor inválido foi fornecido para um dos argumentos de uma função. Por exemplo, o valor fornecido para a origem ao posicionar o ponteiro do arquivo (por meio de uma chamada para **fseek**) ocorre antes do início do arquivo.  
  
 **EMFILE**  
 Muitos arquivos abertos. Não há outros descritores de arquivos disponíveis, portanto, não é possível abrir outros arquivos.  
  
 **ENOENT**  
 Arquivo ou diretório inexistente. O arquivo ou diretório especificado não existe ou não pode ser encontrado. Essa mensagem pode ocorrer sempre que um arquivo especificado não existir ou um componente de um caminho não especificar um diretório existente.  
  
 **ENOEXEC**  
 Erro de formato exec. Foi feita uma tentativa de executar um arquivo que não é executável, ou que tem um formato inválido de arquivo executável.  
  
 **ENOMEM**  
 Não há núcleos suficientes. Não há memória suficiente disponível para o operador tentado. Por exemplo, essa mensagem pode ocorrer quando não houver memória suficiente disponível para executar um processo filho, ou quando a solicitação de alocação em uma chamada **getcwd** não puder ser satisfeita.  
  
 **ENOSPC**  
 Nenhum espaço remanescente no dispositivo. Não há mais espaço para gravação disponível no dispositivo (por exemplo, quando o disco está cheio).  
  
 **ERANGE**  
 Resultado muito grande. Um argumento para uma função matemática é muito grande, resultando na perda parcial ou total de significado no resultado. Esse erro também pode ocorrer em outras funções quando um argumento for maior do que o esperado (por exemplo, quando o argumento *buffer* para **getcwd** for maior do que o esperado).  
  
 **EXDEV**  
 Link de dispositivo cruzado. Foi feita uma tentativa de mover um arquivo para um dispositivo diferente (usando a função **rename**).  
  
 **STRUNCATE**  
 Uma cópia ou concatenação da cadeia de caracteres resultou em uma cadeia de caracteres truncada. Confira [_TRUNCATE](../c-runtime-library/truncate.md).  
  
 Os valores a seguir têm suporte para compatibilidade com o Posix. Eles são os valores necessários em sistemas não Posix.  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Constantes globais](../c-runtime-library/global-constants.md)