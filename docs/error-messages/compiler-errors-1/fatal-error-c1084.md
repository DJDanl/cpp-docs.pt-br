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
ms.openlocfilehash: a7266a2158c3e6ccd02ea82de22c6f90a8b6363d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="fatal-error-c1084"></a>Erro fatal C1084
Não é possível ler o arquivo de tipo de arquivo: 'file': mensagem  
  
 Esse erro costuma ser resultado de uma falha na chamada à API do sistema interna feita pelo compilador. A mensagem mostrada quando este erro ocorre geralmente é gerada pelo [wcserror_s](../../c-runtime-library/reference/strerror-s-strerror-s-wcserror-s-wcserror-s.md) ou [FormatMessage](http://msdn.microsoft.com/library/windows/desktop/ms679351.aspx).  
  
 A reprodução das seguintes etapas pode ajudar a resolver C1084:  
  
-   Verifique se o arquivo especificado existe.  
  
-   Verifique se as permissões apropriadas estão definidas para acessar o arquivo especificado.  
  
-   Certifique-se de que a sintaxe de linha de comando cumpre as regras descritas em [sintaxe de linha de comando do compilador](../../build/reference/compiler-command-line-syntax.md).  
  
-   Verifique se as variáveis de ambiente **TMP** e **TEMP** estão corretamente conjunto, bem como as permissões apropriadas para acessar os diretórios, consultem essas variáveis de ambiente. Também verifique se as unidades referenciadas pelo **TMP** e **TEMP** variáveis de ambiente contém uma quantidade suficiente de espaço livre.  
  
-   Se a mensagem indicar "número de arquivo incorreto", o arquivo especificado pode estar sendo fechado em primeiro plano durante a compilação em segundo plano.  
  
 Depois de realizar o diagnóstico acima, realize uma compilação limpa.