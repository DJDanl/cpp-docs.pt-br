---
title: Erro fatal C1037 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C1037
dev_langs:
- C++
helpviewer_keywords:
- C1037
ms.assetid: 79103bca-ccfb-42e7-aef9-9b90c15b162f
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: c1f358201b36b73e1db41f2f72e1f92deb44f368
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="fatal-error-c1037"></a>Erro fatal C1037
não é possível abrir o arquivo de objeto  
  
 O arquivo de objeto especificado por [/Fo](../../build/reference/fo-object-file-name.md) não pode ser aberto.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  O nome de arquivo inválido.  
  
2.  Memória insuficiente para abrir o arquivo.  
  
3.  Outro processo está usando o arquivo.  
  
4.  Um arquivo somente leitura tem o mesmo nome.  
  
 No Visual C++ .NET (versão 1300 do compilador), há um bug que requer a localidade do usuário para definir corretamente quando o nome de arquivo (ou o caminho de diretório para o nome do arquivo) contém caracteres MBCS. Definir a localidade do sistema não é suficiente; a localidade do usuário deve ser configurada para processar caracteres MBCS.
