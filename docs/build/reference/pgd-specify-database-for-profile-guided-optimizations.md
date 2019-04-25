---
title: /PGD (especificar banco de dados para otimizações orientadas por perfil)
ms.date: 03/14/2018
f1_keywords:
- VC.Project.VCLinkerTool.ProfileGuidedDatabase
helpviewer_keywords:
- -PGD linker option
- /PGD linker option
ms.assetid: 9f312498-493b-461f-886f-92652257e443
ms.openlocfilehash: e1d7c9fcb94a9351ce94b66e04b4bfc523248f4e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62319792"
---
# <a name="pgd-specify-database-for-profile-guided-optimizations"></a>/PGD (especificar banco de dados para otimizações orientadas por perfil)

**A opção /PGD. é preterida.** A partir do Visual Studio 2015, prefira a [/GENPROFILE ou /FASTGENPROFILE](genprofile-fastgenprofile-generate-profiling-instrumented-build.md) opções de vinculador. Essa opção é usada para especificar o nome do arquivo. PGD usado pelo processo de Otimização Guiada por perfil.

## <a name="syntax"></a>Sintaxe

> **/PGD:**_filename_

## <a name="argument"></a>Argumento

*filename*<br/>
Especifica o nome do arquivo. PGD que é usado para manter informações sobre o programa em execução.

## <a name="remarks"></a>Comentários

Ao usar preteridas [/LTCG:PGINSTRUMENT](ltcg-link-time-code-generation.md) opção, use **/PGD.** para especificar um nome de não-padrão ou local para o arquivo. PGD. Se você não especificar **/PGD.**, o nome base do arquivo. PGD é o mesmo que a saída (.exe ou. dll) nome base do arquivo e é criado no mesmo diretório do qual o link foi invocado.

Ao usar preteridas **/LTCG:PGOPTIMIZE** opção, use o **/PGD.** opção para especificar o nome do arquivo. PGD para usar para criar a imagem otimizada. O *filename* argumento deve corresponder a *filename* especificado para **/LTCG:PGINSTRUMENT**.

Para obter mais informações, consulte [otimizações guiadas pelo perfil](../profile-guided-optimizations.md).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **otimização** página de propriedades.

1. Modificar a **banco de dados guiada por perfil** propriedade. Escolha **OK** para salvar suas alterações.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.ProfileGuidedDatabase%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)<br/>
