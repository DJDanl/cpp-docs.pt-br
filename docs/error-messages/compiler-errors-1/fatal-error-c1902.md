---
title: Erro fatal C1902 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1902
dev_langs:
- C++
helpviewer_keywords:
- C1902
ms.assetid: 2dc066cc-fcb1-4725-8bcb-9f44dd0905b7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e5a443b5f80eabe9691cf8ff5220bb9b66da51e4
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46052552"
---
# <a name="fatal-error-c1902"></a>Erro fatal C1902

incompatibilidade de Gerenciador de banco de dados do programa; Verifique sua instalação

Um arquivo de banco de dados do programa (. PDB) foi criado usando uma versão mais recente do mspdb*XXX*. dll que o compilador encontrado em seu sistema. Esse erro geralmente indica que mspdbsrv.exe ou mspdbcore.dll estão faltando ou tiver diferentes versões de mspdb*XXX*. dll. (O *XXX* espaço reservado no mspdb*XXX*alterações de nome de arquivo. dll com cada versão do produto. Por exemplo, no Visual Studio 2015, o nome do arquivo é mspdb140.dll.)

Verifique se as versões correspondentes do mspdbsrv.exe, mspdbcore.dll e mspdb*XXX*. dll estão instaladas em seu sistema. Certifique-se de que as versões incompatíveis não foram copiadas para o diretório que contém as ferramentas de compilador e o link para sua plataforma de destino. Por exemplo, talvez você tenha copiado os arquivos para que você pode invocar a ferramenta de compilador ou o link do prompt de comando sem definir a **caminho** variável de ambiente adequadamente.