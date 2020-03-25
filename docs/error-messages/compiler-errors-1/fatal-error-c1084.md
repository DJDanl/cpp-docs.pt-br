---
title: Erro fatal C1084
ms.date: 11/04/2016
f1_keywords:
- C1084
helpviewer_keywords:
- C1084
ms.assetid: b2f273ef-3a14-4d5f-8ce0-7a11a0388fe6
ms.openlocfilehash: 649686857000b2bee469f0e3ec551d49717c1d7b
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80204068"
---
# <a name="fatal-error-c1084"></a>Erro fatal C1084

Não é possível ler o arquivo filetype: ' file ': Message

Esse erro costuma ser resultado de uma falha na chamada à API do sistema interna feita pelo compilador. A mensagem mostrada quando esse erro é encontrado geralmente é gerada por [_wcserror_s](../../c-runtime-library/reference/strerror-s-strerror-s-wcserror-s-wcserror-s.md) ou [FormatMessage](/windows/win32/api/winbase/nf-winbase-formatmessage).

A reprodução das seguintes etapas pode ajudar a resolver C1084:

- Verifique se o arquivo especificado existe.

- Verifique se as permissões apropriadas estão definidas para acessar o arquivo especificado.

- Verifique se a sintaxe da linha de comando está de acordo com as regras descritas em [sintaxe de linha de comando do compilador](../../build/reference/compiler-command-line-syntax.md).

- Verifique se as variáveis de ambiente **tmp** e **Temp** estão definidas corretamente, bem como as permissões apropriadas para acessar os diretórios aos quais essas variáveis de ambiente se referem. Além disso, certifique-se de que as unidades referenciadas pelas variáveis de ambiente **tmp** e **Temp** contenham uma quantidade adequada de espaço livre.

- Se a mensagem indicar "número de arquivo incorreto", o arquivo especificado pode estar sendo fechado em primeiro plano durante a compilação em segundo plano.

Depois de realizar o diagnóstico acima, realize uma compilação limpa.
