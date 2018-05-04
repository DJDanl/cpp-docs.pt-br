---
title: E/S de nível inferior | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: article
f1_keywords:
- c.io
dev_langs:
- C++
helpviewer_keywords:
- I/O [CRT], low-level
- I/O [CRT], functions
- low-level I/O routines
- file handles [C++]
- file handles [C++], I/O functions
ms.assetid: 53e11bdd-6720-481c-8b2b-3a3a569ed534
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0da1e604a901c09897c8b504d7fbdbf41057af37
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="low-level-io"></a>E/S de nível inferior

Essas funções invocam o sistema operacional diretamente para a operação de nível mais baixo do que o fornecido pelo fluxo de E/S. As chamadas de entrada e saída de nível inferior não fazem buffer nem formatam dados.

 As rotinas de nível inferior podem acessar os fluxos padrão abertos na inicialização do programa, usando os seguintes descritores de arquivo predefinidos.

|Fluxo|Descritor de arquivo|
|------------|---------------------|
|**stdin**|0|
|**stdout**|1|
|**stderr**|2|

 As rotinas de E/S de nível inferior definem a variável global [errno](../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) quando ocorre um erro. Será necessário incluir STDIO.H ao usar funções de nível inferior somente se seu programa exigir uma constante que está definida no STDIO.H, como o indicador de fim do arquivo (**EOF**).

## <a name="low-level-io-functions"></a>Funções de E/S de nível inferior

|Função|Use|
|--------------|---------|
|[_close](../c-runtime-library/reference/close.md)|Fechar arquivo|
|[_commit](../c-runtime-library/reference/commit.md)|Liberar o arquivo no disco|
|[_creat, _wcreat](../c-runtime-library/reference/creat-wcreat.md)|Criar arquivo|
|[_dup](../c-runtime-library/reference/dup-dup2.md)|Retornar o próximo descritor de arquivo disponível para determinado arquivo|
|[_dup2](../c-runtime-library/reference/dup-dup2.md)|Criar um segundo descritor para determinado arquivo|
|[_eof](../c-runtime-library/reference/eof.md)|Teste para o final do arquivo|
|[_lseek, _lseeki64](../c-runtime-library/reference/lseek-lseeki64.md)|Reposicionar ponteiro do arquivo para determinado local|
|[_open, _wopen](../c-runtime-library/reference/open-wopen.md)|Abrir arquivo|
|[_read](../c-runtime-library/reference/read.md)|Ler dados do arquivo|
|[_sopen, _wsopen](../c-runtime-library/reference/sopen-wsopen.md), [_sopen_s, _wsopen_s](../c-runtime-library/reference/sopen-s-wsopen-s.md)|Abrir arquivo para compartilhamento de arquivos|
|[_tell, _telli64](../c-runtime-library/reference/tell-telli64.md)|Obter a posição atual do ponteiro do arquivo|
|[_umask](../c-runtime-library/reference/umask.md), [_umask_s](../c-runtime-library/reference/umask-s.md)|Definir máscara de permissão do arquivo|
|[_write](../c-runtime-library/reference/write.md)|Gravar dados no arquivo|

 Normalmente, **_dup** e **_dup2** são usados para associar os descritores de arquivo predefinidos a arquivos diferentes.

## <a name="see-also"></a>Consulte também

[Entrada e saída](../c-runtime-library/input-and-output.md)<br/>
 [Rotinas de tempo de execução C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)<br/>
 [Chamadas do sistema](../c-runtime-library/system-calls.md)<br/>
