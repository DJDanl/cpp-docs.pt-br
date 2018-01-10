---
title: Erro de Build prj0050 no projeto | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: PRJ0050
dev_langs: C++
helpviewer_keywords: PRJ0050
ms.assetid: ceef3b37-0acf-4abd-ac62-aa830b4fa145
caps.latest.revision: "4"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e9d9b123da2e32db0f695c31bc9643a481d352b8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="project-build-error-prj0050"></a>Erro de Build PRJ0050 no Projeto
Falha ao registrar a saída. Verifique se que você tem as permissões apropriadas para modificar o registro.  
  
 O sistema de compilação do Visual C++ não pôde registrar a saída da compilação (dll ou .exe). Você precisa fazer logon como administrador para modificar o registro.  
  
 Se você estiver criando um arquivo. dll, você pode tentar registrar o. dll manualmente usando o regsvr32.exe, isso deve exibir informações sobre por que a compilação falhou.  
  
 Se você não estiver criando um arquivo. dll, consulte o log de compilação para o comando que causa um erro.