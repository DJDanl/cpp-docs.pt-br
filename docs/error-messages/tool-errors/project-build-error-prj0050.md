---
title: Erro de Build prj0050 no projeto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- PRJ0050
dev_langs:
- C++
helpviewer_keywords:
- PRJ0050
ms.assetid: ceef3b37-0acf-4abd-ac62-aa830b4fa145
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0ad17614f693e313190dba9cc767c023981dec34
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33318507"
---
# <a name="project-build-error-prj0050"></a>Erro de Build PRJ0050 no Projeto
Falha ao registrar a saída. Verifique se que você tem as permissões apropriadas para modificar o registro.  
  
 O sistema de compilação do Visual C++ não pôde registrar a saída da compilação (dll ou .exe). Você precisa fazer logon como administrador para modificar o registro.  
  
 Se você estiver criando um arquivo. dll, você pode tentar registrar o. dll manualmente usando o regsvr32.exe, isso deve exibir informações sobre por que a compilação falhou.  
  
 Se você não estiver criando um arquivo. dll, consulte o log de compilação para o comando que causa um erro.