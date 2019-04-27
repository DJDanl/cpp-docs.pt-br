---
title: Erro fatal C1902
ms.date: 11/04/2016
f1_keywords:
- C1902
helpviewer_keywords:
- C1902
ms.assetid: 2dc066cc-fcb1-4725-8bcb-9f44dd0905b7
ms.openlocfilehash: c425430a6d08ae8a97c4dcd0f5764f44dee43e5f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62165860"
---
# <a name="fatal-error-c1902"></a>Erro fatal C1902

incompatibilidade de Gerenciador de banco de dados do programa; Verifique sua instalação

Um arquivo de banco de dados do programa (. PDB) foi criado usando uma versão mais recente do mspdb*XXX*. dll que o compilador encontrado em seu sistema. Esse erro geralmente indica que mspdbsrv.exe ou mspdbcore.dll estão faltando ou tiver diferentes versões de mspdb*XXX*. dll. (O *XXX* espaço reservado no mspdb*XXX*alterações de nome de arquivo. dll com cada versão do produto. Por exemplo, no Visual Studio 2015, o nome do arquivo é mspdb140.dll.)

Verifique se as versões correspondentes do mspdbsrv.exe, mspdbcore.dll e mspdb*XXX*. dll estão instaladas em seu sistema. Certifique-se de que as versões incompatíveis não foram copiadas para o diretório que contém as ferramentas de compilador e o link para sua plataforma de destino. Por exemplo, talvez você tenha copiado os arquivos para que você pode invocar a ferramenta de compilador ou o link do prompt de comando sem definir a **caminho** variável de ambiente adequadamente.