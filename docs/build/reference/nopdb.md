---
title: /NOPDB
description: A opção/NOPDB impede que o DUMPBIN carregue e pesquise arquivos PDB para obter informações de símbolo.
ms.date: 12/04/2019
f1_keywords:
- /NOPDB
helpviewer_keywords:
- /NOPDB dumpbin option
- /NOPDB
ms.openlocfilehash: 7b0c01e59b52bcec6ddf09416dd6aac9999527a6
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74856963"
---
# <a name="nopdb"></a>/NOPDB

Informa ao DUMPBIN para não carregar e Pesquisar arquivos de banco de dados do programa (PDB) para obter informações de símbolo.

## <a name="syntax"></a>Sintaxe

> **/NOPDB**

## <a name="remarks"></a>Comentários

Por padrão, o DUMPBIN tenta carregar arquivos PDB para seus executáveis de destino. DUMPBIN usa essas informações para corresponder endereços a nomes de símbolo. O processo pode ser demorado se os arquivos PDB forem grandes ou devem ser carregados a partir de um servidor remoto. A opção **/NOPDB** informa DUMPBIN para ignorar esta etapa. Ele apenas imprime os endereços e as informações de símbolo disponíveis no executável.

### <a name="to-set-the-nopdb-linker-option-in-visual-studio"></a>Para definir a opção de vinculador/NOPDB no Visual Studio

1. Abra a caixa de diálogo **páginas de propriedades** do projeto. Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **página de propriedades de** linha de **comando** do > **vinculador > conexão** .

1. Na caixa **Opções adicionais** , adicione a opção **/NOPDB** . Escolha **OK** ou **aplicar** para salvar suas alterações.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Essa opção não tem um equivalente programático.

## <a name="see-also"></a>Consulte também

\ de [linha de comando DUMPBIN](dumpbin-command-line.md)
[Opções de DUMPBIN](dumpbin-options.md)\
[Referência de DUMPBIN](dumpbin-reference.md)
