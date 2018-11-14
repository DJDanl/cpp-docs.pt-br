---
title: /DEFAULTLIB (especificar biblioteca padrão)
ms.date: 05/29/2018
f1_keywords:
- VC.Project.VCLinkerTool.DefaultLibraries
- /defaultlib
helpviewer_keywords:
- -DEFAULTLIB linker option
- DEFAULTLIB linker option
- /DEFAULTLIB linker option
- libraries, adding to list of
ms.assetid: 6af7ff49-c170-4a13-97e2-2b9ae2de20c9
ms.openlocfilehash: 59a4b48e412cee6b2a90608747aa6fb3e1b79ca7
ms.sourcegitcommit: 1819bd2ff79fba7ec172504b9a34455c70c73f10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2018
ms.locfileid: "51326380"
---
# <a name="defaultlib-specify-default-library"></a>/DEFAULTLIB (especificar biblioteca padrão)

Especifique uma biblioteca padrão de pesquisa para resolver referências externas.

## <a name="syntax"></a>Sintaxe

> **/DEFAULTLIB**:_biblioteca_

### <a name="arguments"></a>Arguments

*Biblioteca*<br/>
O nome de uma biblioteca para pesquisar ao resolver referências externas.

## <a name="remarks"></a>Comentários

O **/DEFAULTLIB** opção adiciona uma *biblioteca* à lista de bibliotecas de LINK busca ao resolver referências. Uma biblioteca especificada com **/DEFAULTLIB** é pesquisada após bibliotecas explicitamente especificadas na linha de comando e antes de bibliotecas padrão chamadas nos arquivos. obj.

Quando usada sem argumentos, o [/NODEFAULTLIB (ignorar todas as bibliotecas de padrão)](../../build/reference/nodefaultlib-ignore-libraries.md) opção substitui todos **/DEFAULTLIB**:*biblioteca* opções. O **/NODEFAULTLIB**:*biblioteca* opção substituições **/DEFAULTLIB**:*biblioteca* quando o mesmo *biblioteca*nome é especificado em ambos.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **linha de comando** página de propriedades.

1. Na **opções adicionais**, insira um **/DEFAULTLIB**:*biblioteca* opção para cada biblioteca pesquisar. Escolher **Okey** para salvar suas alterações.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

- [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)
- [Opções do vinculador](../../build/reference/linker-options.md)
