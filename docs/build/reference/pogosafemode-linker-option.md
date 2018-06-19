---
title: / POGOSAFEMODE (PGO executar no modo de segurança de thread) | Microsoft Docs
ms.custom: ''
ms.date: 03/14/2018
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
f1_keywords:
- POGOSAFEMODE
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 81392c67b47a0fa90c057ee4295667a054e34498
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32377327"
---
# <a name="pogosafemode-run-pgo-in-thread-safe-mode"></a>/ POGOSAFEMODE (PGO executar no modo de segurança de thread)

**A opção /POGOSAFEMODE foi preterida a partir do Visual Studio 2015**. Use o [/GENPROFILE: exata](genprofile-fastgenprofile-generate-profiling-instrumented-build.md) e **/GENPROFILE:NOEXACT** opções em vez disso. O **/POGOSAFEMODE** opção de vinculador Especifica que a compilação instrumentada é criada para usar o modo de thread-safe para captura de dados de perfil durante a Otimização Guiada por perfil (PGO) treinamento é executado.

## <a name="syntax"></a>Sintaxe

> **/POGOSAFEMODE**

## <a name="remarks"></a>Comentários

Otimização Guiada por perfil (PGO) tem dois modos possíveis durante a fase de criação de perfil: *modo rápido* e *modo de segurança*. Quando a criação de perfil está no modo rápido, ele usa uma instrução de incremento para aumentar os contadores de dados. A instrução de incremento é mais rápida, mas não é thread-safe. Quando a criação de perfil está no modo de segurança, ele usa a instrução de incremento sincronizada para aumentar os contadores de dados. Esta instrução tem a mesma funcionalidade que tem a instrução de incremento e é thread-safe, mas é mais lento.

O **/POGOSAFEMODE** opção define a compilação instrumentada para usar o modo de segurança. Essa opção só pode ser usado quando preterido [/LTCG:PGINSTRUMENT](ltcg-link-time-code-generation.md) for especificado, durante a fase de vinculador PGO instrumentação.

Por padrão, a criação de perfil de PGO opera em modo rápido. **/ POGOSAFEMODE** é necessário apenas se você deseja usar o modo de segurança.

Para executar a criação de perfil PGO no modo de segurança, você deve usar **/GENPROFILE: exata** (preferencial), ou usar a variável de ambiente [PogoSafeMode](environment-variables-for-profile-guided-optimizations.md) ou a opção de vinculador **/POGOSAFEMODE**, dependendo do sistema. Se você estiver executando a criação de perfil em um x64 computador, você deve usar a opção de vinculador. Se você estiver executando a criação de perfil em um x86 computador, você pode usar a opção de vinculador ou definir a variável de ambiente para qualquer valor antes de iniciar o processo de instrumentação PGO.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **otimização** página de propriedades.

1. No **geração de código de tempo de vinculação** propriedade, escolha **Otimização Guiada por perfil - instrumento (/: pginstrument)**.

1. Selecione o **propriedades de configuração** > **vinculador** > **linha de comando** página de propriedades.

1. Insira o **/POGOSAFEMODE** opção para o **opções adicionais** caixa. Escolha **Okey** para salvar suas alterações.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[/GENPROFILE e /FASTGENPROFILE](genprofile-fastgenprofile-generate-profiling-instrumented-build.md)<br/>
[/LTCG](ltcg-link-time-code-generation.md)<br/>
[Otimizações guiadas por perfil](../../build/reference/profile-guided-optimizations.md)<br/>
[Variáveis de ambiente para otimizações guiadas por perfil](../../build/reference/environment-variables-for-profile-guided-optimizations.md)<br/>
