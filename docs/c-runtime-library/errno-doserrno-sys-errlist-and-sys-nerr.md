---
title: errno, _doserrno, _sys_errlist, and _sys_nerr | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _errno
apilocation:
- msvcrt.dll
apitype: DLLExport
f1_keywords:
- _sys_errlist
- errno
- _sys_nerr
- _doserrno
dev_langs:
- C++
helpviewer_keywords:
- error codes, printing
- sys_errlist global variable
- doserrno global variable
- errno global variable
- _doserrno global variable
- _sys_errlist global variable
- _sys_nerr global variable
- sys_nerr global variable
ms.assetid: adbec641-6d91-4e19-8398-9a34046bd369
caps.latest.revision: 18
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 1e0d08a2176d338c1ac58e3c9dad3092eae14583
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="errno-doserrno-syserrlist-and-sysnerr"></a>errno, _doserrno, _sys_errlist e _sys_nerr
Macros globais que mantêm códigos de erro definidos durante a execução do programa e equivalentes da cadeia de caracteres dos códigos de erro para exibição.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#define errno   (*_errno())  
#define _doserrno   (*__doserrno())  
#define _sys_errlist (__sys_errlist())  
#define _sys_nerr (*__sys_nerr())  
```  
  
## <a name="remarks"></a>Comentários  
 `errno` e `_doserrno` são definidos como 0 no tempo de execução durante a inicialização do programa. `errno` é definido em um erro em uma chamada do sistema. Como `errno` contém o valor da última chamada que o define, esse valor pode ser alterado pelas chamadas subsequentes. As chamadas da biblioteca em tempo de execução que definem `errno` em um erro não limpam `errno` com êxito. Sempre desmarque `errno` chamando `_set_errno(0)` pouco antes de uma chamada que pode defini-lo e marque-o imediatamente depois da chamada.  
  
 Em um erro, `errno` não é necessariamente definido com o mesmo valor que o código de erro retornado por uma chamada do sistema. No caso de operações de E/S, `_doserrno` armazena os equivalentes de código de erro do sistema operacional dos códigos `errno`. No caso da maioria das operações de E/S, o valor de `_doserrno` não é definido.  
  
 Cada valor `errno` é associado a uma mensagem de erro em `_sys_errlist`, que pode ser impressa usando uma das funções [perror](../c-runtime-library/reference/perror-wperror.md) ou armazenada em uma cadeia de caracteres com uma das funções [strerror](../c-runtime-library/reference/strerror-strerror-wcserror-wcserror.md) ou [strerror_s](../c-runtime-library/reference/strerror-s-strerror-s-wcserror-s-wcserror-s.md). As funções `perror` e `strerror` usam a matriz `_sys_errlist` e `_sys_nerr`, o número de elementos em `_sys_errlist`, para processar informações de erro. O acesso direto a `_sys_errlist` e `_sys_nerr` é removido por motivos de segurança do código. Recomendamos que você use as versões funcionais, mais seguras, em vez das macros globais, como mostrado aqui:  
  
|Macro global|Equivalentes funcionais|  
|------------------|----------------------------|  
|`_doserrno`|[_get_doserrno](../c-runtime-library/reference/get-doserrno.md), [_set_doserrno](../c-runtime-library/reference/set-doserrno.md)|  
|`errno`|[_get_errno](../c-runtime-library/reference/get-errno.md), [_set_errno](../c-runtime-library/reference/set-errno.md)|  
|`_sys_errlist`, `_sys_nerr`|[strerror_s, _strerror_s, _wcserror_s, \__wcserror_s](../c-runtime-library/reference/strerror-s-strerror-s-wcserror-s-wcserror-s.md)|  
  
 As rotinas matemáticas da biblioteca definem `errno` chamando [_matherr](../c-runtime-library/reference/matherr.md). Para tratar erros de matemática de maneira diferente, grave sua própria rotina de acordo com a descrição da referência de `_matherr` e denomine-a `_matherr`.  
  
 Todos os valores `errno` na tabela a seguir são constantes predefinidas em \<errno.h> e compatíveis com UNIX. Somente `ERANGE`, `EILSEQ` e `EDOM` são especificadas no padrão ISO C99.  
  
|Constante|Mensagem de erro do sistema|Valor|  
|--------------|--------------------------|-----------|  
|`EPERM`|Operação não permitida|1|  
|`ENOENT`|Arquivo ou diretório inexistente|2|  
|`ESRCH`|Processo inexistente|3|  
|`EINTR`|Função interrompida|4|  
|`EIO`|Erro de E/S|5|  
|`ENXIO`|Dispositivo ou endereço inexistente|6|  
|`E2BIG`|Lista de argumentos muito longa|7|  
|`ENOEXEC`|Erro de formato exec|8|  
|`EBADF`|Número de arquivo incorreto|9|  
|`ECHILD`|Nenhum processo gerado|10|  
|`EAGAIN`|Não há mais processos ou não há memória suficiente ou nível de aninhamento máximo atingido|11|  
|`ENOMEM`|Não há memória suficiente|12|  
|`EACCES`|Permissão negada|13|  
|`EFAULT`|Endereço incorreto|14|  
|`EBUSY`|Dispositivo ou recurso ocupado|16|  
|`EEXIST`|Arquivo existe|17|  
|`EXDEV`|Vínculo de dispositivo cruzado|18|  
|`ENODEV`|Dispositivo inexistente|19|  
|`ENOTDIR`|Não é um diretório|20|  
|`EISDIR`|É um diretório|21|  
|`EINVAL`|Argumento inválido|22|  
|`ENFILE`|Muitos arquivos abertos no sistema|23|  
|`EMFILE`|Muitos arquivos abertos|24|  
|`ENOTTY`|Operação de controle de E/S inadequada|25|  
|`EFBIG`|Arquivo muito grande|27|  
|`ENOSPC`|Nenhum espaço remanescente no dispositivo|28|  
|`ESPIPE`|Pesquisa inválida|29|  
|`EROFS`|Sistema de arquivos somente leitura|30|  
|`EMLINK`|Muitos links|31|  
|`EPIPE`|Pipe interrompido|32|  
|`EDOM`|Argumento matemático|33|  
|`ERANGE`|Resultado muito grande|34|  
|`EDEADLK`|Ocorreria um deadlock de recursos|36|  
|`EDEADLOCK`|Mesmo que EDEADLK para compatibilidade com versões anteriores do Microsoft C|36|  
|`ENAMETOOLONG`|Nome de arquivo muito longo|38|  
|`ENOLCK`|Não há bloqueios disponíveis|39|  
|`ENOSYS`|Função sem suporte|40|  
|`ENOTEMPTY`|Diretório não vazio|41|  
|`EILSEQ`|Sequência ilegal de bytes|42|  
|`STRUNCATE`|A cadeia de caracteres foi truncada|80|  
  
## <a name="requirements"></a>Requisitos  
  
|Macro global|Cabeçalho necessário|Cabeçalho opcional|  
|------------------|---------------------|---------------------|  
|`errno`|\<errno.h> ou \<stdlib.h>, \<cerrno> ou \<cstdlib> (C++)||  
|`_doserrno`, `_sys_errlist`, `_sys_nerr`|\<stdlib.h>, \<cstdlib> (C++)|\<errno.h>, \<cerrno> (C++)|  
  
 As macros `_doserrno`, `_sys_errlist` e `_sys_nerr` são extensões da Microsoft. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Variáveis globais](../c-runtime-library/global-variables.md)   
 [errno Constants](../c-runtime-library/errno-constants.md)   
 [perror, _wperror](../c-runtime-library/reference/perror-wperror.md)   
 [strerror, _strerror, _wcserror, \__wcserror](../c-runtime-library/reference/strerror-strerror-wcserror-wcserror.md)   
 [strerror_s, _strerror_s, _wcserror_s, \__wcserror_s](../c-runtime-library/reference/strerror-s-strerror-s-wcserror-s-wcserror-s.md)   
 [_get_doserrno](../c-runtime-library/reference/get-doserrno.md)   
 [_set_doserrno](../c-runtime-library/reference/set-doserrno.md)   
 [_get_errno](../c-runtime-library/reference/get-errno.md)   
 [_set_errno](../c-runtime-library/reference/set-errno.md)
