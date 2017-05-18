---
title: Erro fatal C1084 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1084
dev_langs:
- C++
helpviewer_keywords:
- C1084
ms.assetid: b2f273ef-3a14-4d5f-8ce0-7a11a0388fe6
caps.latest.revision: 8
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 6b6b181fbc885282dd5f89c4bcfb9c3440094000
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1084"></a>Erro fatal C1084
Não é possível ler o arquivo do tipo de arquivo: 'arquivo': mensagem  
  
 Esse erro costuma ser resultado de uma falha na chamada à API do sistema interna feita pelo compilador. A mensagem mostrada quando esse erro geralmente é gerada por [wcserror_s](../../c-runtime-library/reference/strerror-s-strerror-s-wcserror-s-wcserror-s.md) ou [FormatMessage](http://msdn.microsoft.com/library/windows/desktop/ms679351.aspx).  
  
 A reprodução das seguintes etapas pode ajudar a resolver C1084:  
  
-   Verifique se o arquivo especificado existe.  
  
-   Verifique se as permissões apropriadas estão definidas para acessar o arquivo especificado.  
  
-   Certifique-se de que a sintaxe de linha de comando segue as regras descritas em [sintaxe de linha de comando do compilador](../../build/reference/compiler-command-line-syntax.md).  
  
-   Verifique se as variáveis de ambiente **TMP** e **TEMP** estão corretamente conjunto, bem como as permissões apropriadas para acessar os diretórios consultem essas variáveis de ambiente. Também verifique se as unidades mencionadas pelo **TMP** e **TEMP** variáveis de ambiente contêm uma quantidade suficiente de espaço livre.  
  
-   Se a mensagem indicar "número de arquivo incorreto", o arquivo especificado pode estar sendo fechado em primeiro plano durante a compilação em segundo plano.  
  
 Depois de realizar o diagnóstico acima, realize uma compilação limpa.
