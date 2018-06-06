---
title: /DEFAULTLIB (especificar biblioteca padrão) | Microsoft Docs
ms.custom: ''
ms.date: 05/29/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCLinkerTool.DefaultLibraries
- /defaultlib
dev_langs:
- C++
helpviewer_keywords:
- -DEFAULTLIB linker option
- DEFAULTLIB linker option
- /DEFAULTLIB linker option
- libraries, adding to list of
ms.assetid: 6af7ff49-c170-4a13-97e2-2b9ae2de20c9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9afcaa0e229ec34ba91b4d60a7a4fa9acec2d7e3
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/01/2018
ms.locfileid: "34569775"
---
# <a name="defaultlib-specify-default-library"></a>/DEFAULTLIB (especificar biblioteca padrão)

Especifique uma biblioteca de padrão de pesquisa para resolver referências externas.

## <a name="syntax"></a>Sintaxe

> **/DEFAULTLIB**:_biblioteca_

### <a name="arguments"></a>Arguments

|Argumento|Descrição|
|-|-|
*Biblioteca*|O nome de uma biblioteca de pesquisa ao resolver referências externas.

## <a name="remarks"></a>Comentários

O **/DEFAULTLIB** opção adiciona uma *biblioteca* à lista de bibliotecas de LINK busca ao resolver referências. Uma biblioteca especificada com **/DEFAULTLIB** é pesquisado após bibliotecas explicitamente especificadas na linha de comando e antes de bibliotecas padrão chamadas nos arquivos. obj.

Quando usada sem argumentos, o [/NODEFAULTLIB (ignorar todas as bibliotecas de padrão)](../../build/reference/nodefaultlib-ignore-libraries.md) opção substitui todos os **/DEFAULTLIB**:*biblioteca* opções. O **/NODEFAULTLIB**:*biblioteca* opção substituições **/DEFAULTLIB**:*biblioteca* quando o mesmo *biblioteca*nome é especificado em ambos.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **linha de comando** página de propriedades.

1. Em **opções adicionais**, insira um **/DEFAULTLIB**:*biblioteca* opção para cada biblioteca a ser pesquisado. Escolha **Okey** para salvar suas alterações.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

- [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)
- [Opções do vinculador](../../build/reference/linker-options.md)
