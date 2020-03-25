---
title: Erro de Build PRJ0050 no Projeto
ms.date: 11/04/2016
f1_keywords:
- PRJ0050
helpviewer_keywords:
- PRJ0050
ms.assetid: ceef3b37-0acf-4abd-ac62-aa830b4fa145
ms.openlocfilehash: 56e092b5f7c33ad9543951621b2a9d8f6992331f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80191984"
---
# <a name="project-build-error-prj0050"></a>Erro de Build PRJ0050 no Projeto

Falha ao registrar a saída. Verifique se você tem as permissões apropriadas para modificar o registro.

O sistema C++ de compilação Visual não pôde registrar a saída da compilação (DLL ou. exe). Você precisa estar conectado como administrador para modificar o registro.

Se você estiver criando uma. dll, poderá tentar registrar o. dll manualmente usando regsvr32. exe, que deve exibir informações sobre o motivo da falha da compilação.

Se você não estiver criando uma. dll, examine o log de compilação do comando que causa um erro.
