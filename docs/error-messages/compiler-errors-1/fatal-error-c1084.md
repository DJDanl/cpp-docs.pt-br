---
title: Erro fatal C1084 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1084
dev_langs:
- C++
helpviewer_keywords:
- C1084
ms.assetid: b2f273ef-3a14-4d5f-8ce0-7a11a0388fe6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 47d56641209ea1fe192bf0c32ace7701a1e579dc
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46054526"
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