---
title: /ZH (algoritmo de hash para cálculo da soma de verificação do arquivo nas informações de depuração)
description: Use a opção de compilador/ZH para habilitar as somas de verificação de arquivo de origem MD5, SHA-1 ou SHA-256 em informações de depuração
ms.date: 09/16/2019
f1_keywords:
- /ZH
- /ZH:MD5
- /ZH:SHA1
- /ZH:SHA_256
helpviewer_keywords:
- /ZH
- /ZH:MD5
- /ZH:SHA1
- /ZH:SHA_256
- /ZH compiler option
- /ZH:MD5 compiler option
- /ZH:SHA1 compiler option
- /ZH:SHA_256 compiler option
- Hash algorithm for file checksum in debug info
ms.openlocfilehash: f05dc2bc3b8ce4502ff16a6e19fdbb10763b34ba
ms.sourcegitcommit: 1e6386be9084f70def7b3b8b4bab319a117102b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2019
ms.locfileid: "71686869"
---
# <a name="zh-hash-algorithm-for-calculation-of-file-checksum-in-debug-info"></a>/ZH (algoritmo de hash para cálculo da soma de verificação do arquivo nas informações de depuração)

Especifica o algoritmo de hash criptográfico a ser usado para gerar uma soma de verificação de cada arquivo de origem.

## <a name="syntax"></a>Sintaxe

> **/ZH:** {**MD5**|**SHA1**|**SHA_256**}

## <a name="arguments"></a>Argumentos

**/ZH: MD5**\
Use um hash MD5 para a soma de verificação. Essa opção é o padrão.

**/ZH: SHA1**\
Use um hash SHA-1 para a soma de verificação.

**/ZH: SHA_256**\
Use um hash SHA-256 para a soma de verificação.

## <a name="remarks"></a>Comentários

Os arquivos PDB armazenam uma soma de verificação para cada arquivo de origem compilado no código do objeto no executável associado. A soma de verificação permite que o depurador Verifique se o código-fonte carregado corresponde ao executável. O compilador e o depurador dão suporte a algoritmos de hash MD5, SHA-1 e SHA-256. Por padrão, o compilador usa um hash MD5 para gerar a soma de verificação. Você pode especificar essa opção explicitamente usando a opção **/zh: MD5** .

Devido a um risco de problemas de colisão no MD5 e no SHA-1, a Microsoft recomenda que você use a opção **/zh: SHA_256** . O hash SHA-256 pode resultar em um pequeno aumento em tempos de compilação.

Quando mais de uma opção **/zh** é especificada, a última opção é usada.

A opção **/zh** está disponível a partir do Visual Studio 2019 versão 16,4.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Defina a lista suspensa **configuração** para **todas as configurações**.

1. Selecione a página de propriedades **Propriedades da Configuração** > **C/C++**  > **Linha de Comando**.

1. Modifique a **Propriedade opções adicionais** para adicionar uma **opção/zh: MD5**, **/zh: SHA1**ou **/zh: SHA_256** e escolha **OK**.

## <a name="see-also"></a>Consulte também

[Opções do compilador](compiler-options.md)\
[Servidor de origem](/windows/win32/debug/source-server-and-source-indexing)
