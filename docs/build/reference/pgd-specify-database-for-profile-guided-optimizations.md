---
title: /PGD (especificar o banco de dados para otimizações guiadas por perfil) | Microsoft Docs
ms.custom: ''
ms.date: 03/14/2018
ms.technology:
- cpp-tools
ms.topic: article
f1_keywords:
- VC.Project.VCLinkerTool.ProfileGuidedDatabase
dev_langs:
- C++
helpviewer_keywords:
- -PGD linker option
- /PGD linker option
ms.assetid: 9f312498-493b-461f-886f-92652257e443
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9947e95e3d6c96d07eb12eb2f2a579e0ea1b3a6a
ms.sourcegitcommit: ee7d74683af7631441c8c7f65ef5ceceaee4a5ee
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/22/2018
---
# <a name="pgd-specify-database-for-profile-guided-optimizations"></a>/PGD (especificar banco de dados para otimizações orientadas por perfil)

**A opção /PGD é preterida.** A partir do Visual Studio 2015, prefira o [/GENPROFILE ou /FASTGENPROFILE](genprofile-fastgenprofile-generate-profiling-instrumented-build.md) opções de vinculador em vez disso. Essa opção é usada para especificar o nome do arquivo. PGD usado pelo processo de Otimização Guiada por perfil.

## <a name="syntax"></a>Sintaxe

> **/PGD:**_filename_

## <a name="argument"></a>Argumento

*filename*<br/>
Especifica o nome do arquivo. PGD que é usado para manter informações sobre o programa em execução.

## <a name="remarks"></a>Comentários

Ao usar preterido [/LTCG:PGINSTRUMENT](../../build/reference/ltcg-link-time-code-generation.md) opção, use **/PGD** para especificar um nome não padrão ou local para o arquivo. PGD. Se você não especificar **/PGD**, o nome base do arquivo. PGD é o mesmo que a saída (.exe ou. dll) nome base do arquivo e é criado no mesmo diretório do qual o link foi invocado.

Ao usar preterido **/LTCG:PGOPTIMIZE** opção, use o **/PGD** opção para especificar o nome do arquivo. PGD para usar para criar a imagem otimizada. O *filename* argumento deve corresponder a *filename* especificado para **/LTCG:PGINSTRUMENT**.

Para obter mais informações, consulte [Otimização Guiada por perfil](../../build/reference/profile-guided-optimizations.md).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **otimização** página de propriedades.

1. Modificar o **banco de dados do perfil interativa** propriedade. Escolha **Okey** para salvar suas alterações.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.ProfileGuidedDatabase%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)<br/>
