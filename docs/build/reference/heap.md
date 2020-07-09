---
title: /HEAP
description: A opção MSVC linker ou EDITBIN/HEAP define o tamanho total do heap e, opcionalmente, o tamanho dos blocos de heap adicionais.
ms.date: 07/07/2020
f1_keywords:
- /heap
helpviewer_keywords:
- heap allocation, setting heap size
- HEAP editbin option
- -HEAP editbin option
- /HEAP editbin option
ms.assetid: 6ce759b5-75b7-44ff-a5fd-3a83a0ba9a48
ms.openlocfilehash: 7976ae2927ca731c83fa42e87da182fee4df3d7c
ms.sourcegitcommit: e17cc8a478b51739d67304d7d82422967b35f716
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/08/2020
ms.locfileid: "86127837"
---
# `/HEAP`

Define o tamanho do heap em bytes. Essa opção se aplica somente a arquivos executáveis.

## <a name="syntax"></a>Sintaxe

> **`/HEAP:`**_`reserve`_\[**`,`**_`commit`_]

## <a name="remarks"></a>Comentários

O *`reserve`* argumento especifica a alocação de heap inicial total na memória virtual. A **`/HEAP`** opção linker ou [EDITBIN](editbin-reference.md) arredonda o valor especificado para o múltiplo mais próximo de 4 bytes. Por padrão, o tamanho do heap é 1 MB.

O *`commit`* argumento opcional está sujeito à interpretação do sistema operacional. Em um sistema operacional Windows, ele especifica a quantidade inicial de memória física a ser alocada. Ele também especifica a quantidade de memória a ser alocada quando o heap é expandido. A memória virtual confirmada faz com que o espaço seja reservado no arquivo de paginação. Um valor mais alto *`commit`* permite que o sistema aloque memória com menos frequência quando o aplicativo precisa de mais espaço de heap, mas aumenta os requisitos de memória e, possivelmente, a duração da inicialização do aplicativo. O *`commit`* valor deve ser menor ou igual ao *`reserve`* valor. O valor padrão é 4 KB.

Especifique os *`reserve`* *`commit`* valores e em notação decimal, hexadecimal C-Language ou octal. Por exemplo, um valor de 1 MB pode ser especificado como 1048576 em decimal, ou como 0x100000 em hexadecimal, ou como 04000000 em octal. Os valores padrão são equivalentes à opção **`/HEAP:1048576,4096`** .

### <a name="example"></a>Exemplo

Este exemplo de comando de link cria um *main.exe* executável com reserva de heap de 2 MB. O heap inicial e as expansões de heap posteriores vêm em blocos de 64 KB:

**`link /heap:0x200000,0x10000 main.obj`**

### <a name="to-set-this-linker-option-in-visual-studio"></a>Para definir essa opção do vinculador no Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**página de propriedades do  >  **sistema vinculador**da propriedade de configuração  >  **System** .

1. Defina as propriedades **tamanho de reserva de heap** e tamanho de confirmação de **heap** e escolha **OK** ou **aplicar** para salvar suas alterações.

## <a name="see-also"></a>Confira também

[Opções de EDITBIN](editbin-options.md)\
[Opções de vinculador MSVC](linker-options.md)
