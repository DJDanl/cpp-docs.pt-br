---
title: Erro RW2003 (compilador de recurso)
ms.date: 11/04/2016
f1_keywords:
- RW2003
helpviewer_keywords:
- RW2003
ms.assetid: 9dc0ba70-6776-4aef-b316-5f1711d8e42e
ms.openlocfilehash: f359c1f71f03ce0d946579776230398fb31d046f
ms.sourcegitcommit: afd6fac7c519dbc47a4befaece14a919d4e0a8a2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2018
ms.locfileid: "51520602"
---
# <a name="resource-compiler-error-rw2003"></a>Erro RW2003 (compilador de recurso)

Erro de geração

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. **Erro: Arquivo de recurso de arquivo de Bitmap não está no formato 3.00**

   Bitmaps usando o formato Windows versão 2.x não podem ser usados em arquivos de recursos de versão 3.x. O bitmap deve ser redesenhado ou convertido para o formato 3.x.

1. **Erro: DIB antigo no nome do recurso. Passá-lo por meio de SDKPAINT**

   Um Bitmap independente de dispositivo (DIB) no recurso especificado não é compatível com o formato Windows 3.0. O bitmap deve ser redesenhado ou convertido para o formato 3.x.

1. **Erro: Nome de recurso de arquivo de recurso não está no formato 3.00**

   Um ícone ou cursor no recurso especificado usava um formato de uma versão anterior do Windows. O ícone ou cursor deve ser redesenhado ou convertido para o formato 3.x.

1. **formato desconhecido de cabeçalho DIB**

   O cabeçalho de bitmap não é uma estrutura BITMAPCOREHEADER ou BITMAPINFOHEADER.

1. **Não foi possível inicializar as informações de símbolo**

   Esse erro ocorre apenas no Visual C++. A causa provável é que você tem muitos arquivos abertos ou você não pode abrir ou gravar os arquivos de dados necessários para o Visual C++ importar os símbolos em seu script. Visual C++ tenta criar esses arquivos no diretório especificado o **TMP** variável de ambiente ou o diretório atual se nenhum for especificado.

1. **Não é possível salvar as informações de símbolo**

   Esse erro ocorre apenas no Visual C++. A causa provável é que você tem muitos arquivos abertos ou você não pode fechar ou gravar os arquivos de dados necessários para o Visual C++ importar os símbolos em seu script. Visual C++ tenta usar esses arquivos no diretório especificado o **TMP** variável de ambiente ou o diretório atual se nenhum for especificado.

1. **Arquivo de recurso do arquivo de bitmap não está no formato 2,03**

   Um bitmap usado em um formato anterior à versão 2.03. O bitmap deve ser convertido ou reemitida usando o formato de versão 3,00 ou posterior.

1. **Recurso muito grande**

   Para o Windows 3.1 um recurso não pode exceder aproximadamente 65000 bytes. Se seu recurso, em seguida, você não poderá compilá-lo com o Visual C++ ou o compilador de recurso de linha de comando. Esse limite não se aplica a cursores, ícones, bitmaps ou outros recursos baseados em arquivo.

1. **Arquivo de recurso não está no formato 3.00**

   Um ícone ou cursor usava um formato anterior à versão 3,00. O recurso deve ser convertido ou reemitida usando o formato de versão 3,00 ou posterior.

1. **Não é possível abrir o arquivo temporário**

   O recurso de compilador/Visual C++ não pôde abrir um arquivo temporário. A causa provável é que você não tem permissões de gravação para o diretório ou o diretório não existe. O recurso de compilador/Visual C++ tenta usar esses arquivos no diretório especificado pela **TMP** variável de ambiente ou o diretório atual se nenhum for especificado.