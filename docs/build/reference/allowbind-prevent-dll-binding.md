---
title: -ALLOWBIND (impedir associação da DLL) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCLinkerTool.PreventDLLBinding
- /allowbind
dev_langs:
- C++
helpviewer_keywords:
- /ALLOWBIND linker option
- binding DLLs
- preventing DLL binding
- ALLOWBIND linker option
- -ALLOWBIND linker option
- DLLs [C++], preventing binding
ms.assetid: 30e37e24-12e4-407e-988a-39d357403598
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 536fc4f43cf227491ecae53cb5960e42ff79e081
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45713616"
---
# <a name="allowbind-prevent-dll-binding"></a>/ALLOWBIND (evitar associação de DLL)

```
/ALLOWBIND[:NO]
```

## <a name="remarks"></a>Comentários

/ALLOWBIND:NO define um bit no cabeçalho de uma DLL, o que indica ao Bind.exe que não é possível associar a imagem. Talvez você não queira que uma DLL seja vinculada caso ela tenha sido assinada digitalmente (a associação invalida a assinatura).

Você pode editar uma DLL existente para a funcionalidade /ALLOWBIND com a [/ALLOWBIND](../../build/reference/allowbind.md) opção do utilitário EDITBIN.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Expandir **propriedades de configuração**, **vinculador**e selecione **linha de comando**.

1. Insira `/ALLOWBIND:NO` em **opções adicionais**.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)<br/>
[Função BindImage](/windows/desktop/api/imagehlp/nf-imagehlp-bindimage)<br/>
[Função BindImageEx](/windows/desktop/api/imagehlp/nf-imagehlp-bindimageex)