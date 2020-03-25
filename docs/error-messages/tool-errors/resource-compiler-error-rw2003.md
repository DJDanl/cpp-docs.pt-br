---
title: Erro RW2003 (compilador de recurso)
ms.date: 11/04/2016
f1_keywords:
- RW2003
helpviewer_keywords:
- RW2003
ms.assetid: 9dc0ba70-6776-4aef-b316-5f1711d8e42e
ms.openlocfilehash: 60e813fff46ebc015f281dfed99d2916ca0eb4bb
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80190606"
---
# <a name="resource-compiler-error-rw2003"></a>Erro RW2003 (compilador de recurso)

Erro de geração

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. **Erro: o arquivo de recurso de bitmap não está no formato 3, 0**

   Bitmaps usando o formato Windows versão 2.x não podem ser usados em arquivos de recursos de versão 3.x. O bitmap deve ser redesenhado ou convertido para o formato 3. x.

1. **Erro: DIB antigo no nome do recurso. Passá-lo por meio de SDKPAINT**

   Um DIB (bitmap independente de dispositivo) no recurso especificado não é compatível com o formato do Windows 3,0. O bitmap deve ser redesenhado ou convertido no formato 3. x.

1. **Erro: o nome do recurso do arquivo de recurso não está no formato 3, 0**

   Um ícone ou cursor no recurso especificado usava um formato de uma versão anterior do Windows. O ícone ou cursor deve ser redesenhado ou convertido no formato 3. x.

1. **Formato de cabeçalho DIB desconhecido**

   O cabeçalho de bitmap não é uma estrutura BITMAPCOREHEADER ou BITMAPINFOHEADER.

1. **Não é possível inicializar informações de símbolo**

   Esse erro ocorre apenas no Visual C++. A causa provável é que você tem muitos arquivos abertos ou não pode abrir ou gravar nos arquivos de dados necessários para que o C++ Visual importe os símbolos em seu script. O C++ Visual tenta criar esses arquivos no diretório especificado pela variável de ambiente **tmp** ou o diretório atual, se nenhum for especificado.

1. **Não é possível salvar informações de símbolo**

   Esse erro ocorre apenas no Visual C++. A causa provável é que você tem muitos arquivos abertos ou não pode fechar ou gravar nos arquivos de dados necessários para que o C++ Visual importe os símbolos em seu script. O C++ Visual tenta usar esses arquivos no diretório especificado pela variável de ambiente **tmp** ou o diretório atual, se nenhum for especificado.

1. **O arquivo de recurso de arquivo de bitmap não está no formato 2, 3**

   Um bitmap usou um formato anterior à versão 2, 3. O bitmap deve ser convertido ou redesenhado usando o formato para a versão 3, 0 ou posterior.

1. **Recurso muito grande**

   Para o Windows 3,1, um recurso não pode exceder aproximadamente 65000 bytes. Se o seu recurso tiver, você não poderá compilá-lo com o Visual C++ ou com o compilador de recurso de linha de comando. Esse limite não se aplica a cursores, ícones, bitmaps ou outros recursos baseados em arquivo.

1. **O arquivo de recurso não está no formato 3, 0**

   Um cursor ou um ícone usava um formato anterior à versão 3, 0. O recurso deve ser convertido ou redesenhado usando o formato para a versão 3, 0 ou posterior.

1. **Não é possível abrir o arquivo temporário**

   O compilador/Visual C++ de recurso não pôde abrir um arquivo temporário. A causa provável é que você não tem permissões de gravação para o diretório ou que o diretório não existe. O compilador de recurso/ C++ Visual tenta usar esses arquivos no diretório especificado pela variável de ambiente **tmp** ou o diretório atual, se nenhum for especificado.
