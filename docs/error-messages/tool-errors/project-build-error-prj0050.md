---
title: "PRJ0050 de erro de compilação de projeto | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- PRJ0050
dev_langs:
- C++
helpviewer_keywords:
- PRJ0050
ms.assetid: ceef3b37-0acf-4abd-ac62-aa830b4fa145
caps.latest.revision: 4
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
ms.openlocfilehash: c434e329846967544d4cb2a84c7b48c83ba6f55f
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="project-build-error-prj0050"></a>Erro de Build PRJ0050 no Projeto
Falha ao registrar a saída. Verifique se que você tem as permissões apropriadas para modificar o registro.  
  
 O sistema de compilação do Visual C++ não pôde registrar a saída da compilação (dll ou .exe). Você precisa estar conectado como administrador para modificar o registro.  
  
 Se você estiver criando um arquivo. dll, você pode tentar registrar o arquivo. dll manualmente usando regsvr32.exe, isso deve exibir informações sobre por que a compilação falhou.  
  
 Se você não estiver criando um arquivo. dll, examine o log de compilação para o comando que causa um erro.
