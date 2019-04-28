---
title: Erro de Build PRJ0050 no Projeto
ms.date: 11/04/2016
f1_keywords:
- PRJ0050
helpviewer_keywords:
- PRJ0050
ms.assetid: ceef3b37-0acf-4abd-ac62-aa830b4fa145
ms.openlocfilehash: ec2490bad70d2b2eb72cbb48771900f09f8c2f67
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62226485"
---
# <a name="project-build-error-prj0050"></a>Erro de Build PRJ0050 no Projeto

Falha ao registrar a saída. Verifique se que você tem as permissões apropriadas para modificar o registro.

O sistema de compilação do Visual C++ não pôde registrar a saída da compilação (dll ou .exe). Você precisa estar conectado como um administrador para modificar o registro.

Se você estiver criando um arquivo. dll, você pode tentar registrar o arquivo. dll manualmente usando o regsvr32.exe, isso deve exibir informações sobre por que a compilação falhou.

Se você não estiver criando um arquivo. dll, examine o log de compilação para o comando que causa um erro.