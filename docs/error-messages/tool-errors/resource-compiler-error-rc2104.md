---
title: RC2104 de erro do compilador de recurso | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- RC2104
dev_langs:
- C++
helpviewer_keywords:
- RC2104
ms.assetid: 792a3bd8-cb4c-4817-b288-4ce37082b582
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ce7fa189e03ec907c4b42f381096f095d5df734a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="resource-compiler-error-rc2104"></a>Erro RC2104 (compilador de recurso)
palavra-chave ou a nome da chave indefinido: chave  
  
 A palavra-chave especificada ou o nome da chave não está definido.  
  
 Este erro geralmente é causado por um erro de digitação na definição do recurso ou no arquivo de cabeçalho incluído. Também pode ser causado por um arquivo de cabeçalho ausente.  
  
 Para corrigir o problema, localize o arquivo de cabeçalho que deve conter o nome da chave ou a palavra-chave definida e verifique se ele está incluído em seu arquivo de recurso, e se o nome da chave ou a palavra-chave está escrito corretamente. Se o projeto foi criado com um cabeçalho pré-compilado e você subsequentemente o removeu, certifique-se de que o arquivo de recurso ainda inclui quaisquer cabeçalhos necessários.  
  
 Para verificar se as palavras-chave definidas e nomes de chave em seu arquivo de recurso, no Visual Studio, abra o **exibição recursos** janela — na barra de menus, escolha **exibição**, **exibição recursos**— e em seguida, abra o menu de atalho para o arquivo. RC e escolha **símbolos de recurso** para exibir a lista de símbolos definidos. Para modificar os cabeçalhos incluídos, abra o menu de atalho para o arquivo. RC e escolha **inclui recursos**.  
  
 Se você encontrar esta mensagem:  
  
```  
undefined keyword or key name: MFT_STRING   
```  
  
 Abra \MCL\MFC\Include\AfxRes.h e adicione esta diretiva de inclusão:  
  
```  
#include <winresrc.h>  
```