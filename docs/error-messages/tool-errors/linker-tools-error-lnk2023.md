---
title: Erro das Ferramentas de Vinculador LNK2023
ms.date: 11/04/2016
f1_keywords:
- LNK2023
helpviewer_keywords:
- LNK2023
ms.assetid: c99e35a8-739a-4a20-a715-29b8c3744703
ms.openlocfilehash: c5bc70aeb3a7e39bc60bb745060e7a5740ad7a28
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62386298"
---
# <a name="linker-tools-error-lnk2023"></a>Erro das Ferramentas de Vinculador LNK2023

dll incorreto ou o ponto de entrada \<dll ou ponto de entrada >

O vinculador está carregando uma versão incorreta do msobj90.dll. Certifique-se de que link.exe e msobj90.dll em seu caminho tenham a mesma versão.

Uma dependência de msobj90.dll pode não estar presente. A lista de dependências para msobj90.dll é:

- Msvcr90.dll

- Kernel32.dll

Verifique seu computador para quaisquer outras cópias msobj90.dll que podem estar desatualizados.