---
title: /USEPROFILE (dados de uso PGO com /ltcg) | Microsoft Docs
ms.custom: ''
ms.date: 03/14/2018
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
f1_keywords:
- USEPROFILE
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b12c2e63d5e65d2528f77852d9466d4161d7cc6a
ms.sourcegitcommit: ee7d74683af7631441c8c7f65ef5ceceaee4a5ee
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/22/2018
---
# <a name="useprofile-run-pgo-in-thread-safe-mode"></a>/USEPROFILE (PGO executar no modo de segurança de thread)

Essa opção de vinculador junto com [/LTCG (geração de código Link-time](ltcg-link-time-code-generation.md) informa o vinculador para criar, usando dados de treinamento de Otimização Guiada por perfil (PGO).

## <a name="syntax"></a>Sintaxe

> **/USEPROFILE**[**:**{**AGGRESSIVE**|**PGD=**_filename_}]

### <a name="arguments"></a>Arguments

**AGGRESSIVE**<br/>
Esse argumento opcional especifica que as otimizações de velocidade agressiva devem ser usadas durante a geração de código otimizado.

**PGD**=*filename*<br/>
Especifica um nome de arquivo de base para o arquivo. PGD. Por padrão, o vinculador usa o nome do arquivo executável base com uma extensão. PGD.

## <a name="remarks"></a>Comentários

O **/USEPROFILE** opção de vinculador é usada junto com **/LTCG** para gerar ou atualizar uma compilação otimizada com base nos dados de treinamento PGO. É o equivalente de preterido **/LTCG:PGUPDATE** e **/LTCG:PGOPTIMIZE** opções.

Opcional **AGRESSIVO** argumento desabilita relacionados a tamanho heurística para tentar otimizar a velocidade. Isso pode resultar em otimizações que substancialmente aumentam o tamanho de seu executável e não podem aumentar a velocidade resultante. Você deve criar o perfil e comparar os resultados de uso e não **AGRESSIVO**. Esse argumento deve ser especificado explicitamente. ele não está habilitado por padrão.

O **PGD** argumento especifica um nome opcional para o arquivo de PGD de dados de treinamento usar as mesmas que na [/GENPROFILE ou /FASTGENPROFILE](genprofile-fastgenprofile-generate-profiling-instrumented-build.md). É o equivalente de preterido **/PGD** alternar. Por padrão, ou se nenhum *filename* for especificado, um arquivo. PGD que tem o mesmo nome base como o executável é usado.

O **/USEPROFILE** opção de vinculador é nova no Visual Studio 2015.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **otimização** página de propriedades.

1. No **geração de código de tempo de vinculação** propriedade, escolha **usar geração de código de tempo de vinculação (/ /ltcg)**.

1. Selecione o **propriedades de configuração** > **vinculador** > **linha de comando** página de propriedades.

1. Insira o **/USEPROFILE** opção e argumentos opcionais para o **opções adicionais** caixa. Escolha **Okey** para salvar suas alterações.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[/GENPROFILE e /FASTGENPROFILE](genprofile-fastgenprofile-generate-profiling-instrumented-build.md)<br/>
[/LTCG](ltcg-link-time-code-generation.md)<br/>
[Otimizações guiadas por perfil](../../build/reference/profile-guided-optimizations.md)<br/>
[Variáveis de ambiente para otimizações guiadas por perfil](../../build/reference/environment-variables-for-profile-guided-optimizations.md)<br/>
