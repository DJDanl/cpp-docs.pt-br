---
title: /ALLOWBIND (evitar associação de DLL)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCLinkerTool.PreventDLLBinding
- /allowbind
helpviewer_keywords:
- /ALLOWBIND linker option
- binding DLLs
- preventing DLL binding
- ALLOWBIND linker option
- -ALLOWBIND linker option
- DLLs [C++], preventing binding
ms.assetid: 30e37e24-12e4-407e-988a-39d357403598
ms.openlocfilehash: bd9976e434441d2480386ee6fa3d0315fd8d2ef5
ms.sourcegitcommit: faa42c8a051e746d99dcebe70fd4bbaf3b023ace
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/15/2019
ms.locfileid: "57818837"
---
# <a name="allowbind-prevent-dll-binding"></a>/ALLOWBIND (evitar associação de DLL)

```
/ALLOWBIND[:NO]
```

## <a name="remarks"></a>Comentários

/ALLOWBIND:NO define um bit no cabeçalho de uma DLL, o que indica ao Bind.exe que não é possível associar a imagem. Talvez você não queira que uma DLL seja vinculada caso ela tenha sido assinada digitalmente (a associação invalida a assinatura).

Você pode editar uma DLL existente para a funcionalidade /ALLOWBIND com a [/ALLOWBIND](allowbind.md) opção do utilitário EDITBIN.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Expandir **propriedades de configuração**, **vinculador**e selecione **linha de comando**.

1. Insira `/ALLOWBIND:NO` em **opções adicionais**.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções do vinculador MSVC](linker-options.md)<br/>
[Função BindImage](/windows/desktop/api/imagehlp/nf-imagehlp-bindimage)<br/>
[Função BindImageEx](/windows/desktop/api/imagehlp/nf-imagehlp-bindimageex)
