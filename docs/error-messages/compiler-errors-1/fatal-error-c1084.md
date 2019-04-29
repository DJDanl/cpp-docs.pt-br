---
title: Erro fatal C1084
ms.date: 11/04/2016
f1_keywords:
- C1084
helpviewer_keywords:
- C1084
ms.assetid: b2f273ef-3a14-4d5f-8ce0-7a11a0388fe6
ms.openlocfilehash: 8c90616165a7b47d4251ace998fd49c613f244b5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62208809"
---
# <a name="fatal-error-c1084"></a>Erro fatal C1084

Não é possível ler o arquivo do tipo de arquivo: 'file': mensagem

Esse erro costuma ser resultado de uma falha na chamada à API do sistema interna feita pelo compilador. A mensagem mostrada quando esse erro for encontrado, geralmente é gerada por um [wcserror_s](../../c-runtime-library/reference/strerror-s-strerror-s-wcserror-s-wcserror-s.md) ou [FormatMessage](/windows/desktop/api/winbase/nf-winbase-formatmessage).

A reprodução das seguintes etapas pode ajudar a resolver C1084:

- Verifique se o arquivo especificado existe.

- Verifique se as permissões apropriadas estão definidas para acessar o arquivo especificado.

- Verifique se a sintaxe de linha de comando respeita as regras descritas em [sintaxe de linha de comando do compilador](../../build/reference/compiler-command-line-syntax.md).

- Verifique se as variáveis de ambiente **TMP** e **TEMP** estão corretamente conjunto, bem como as permissões apropriadas para acessar os diretórios, consultem essas variáveis de ambiente. Além disso, verifique as unidades mencionadas pela **TMP** e **TEMP** variáveis de ambiente contêm uma quantidade suficiente de espaço livre.

- Se a mensagem indicar "número de arquivo incorreto", o arquivo especificado pode estar sendo fechado em primeiro plano durante a compilação em segundo plano.

Depois de realizar o diagnóstico acima, realize uma compilação limpa.