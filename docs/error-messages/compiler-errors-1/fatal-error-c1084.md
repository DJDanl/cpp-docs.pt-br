---
title: Erro fatal C1084
ms.date: 11/04/2016
f1_keywords:
- C1084
helpviewer_keywords:
- C1084
ms.assetid: b2f273ef-3a14-4d5f-8ce0-7a11a0388fe6
ms.openlocfilehash: b0c8e6a8f8321dccdfd7cee128a4cf06cebda991
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69501128"
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