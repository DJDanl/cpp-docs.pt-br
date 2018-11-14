---
title: /hotpatch (Criar imagem hotpatchable)
ms.date: 11/12/2018
f1_keywords:
- /hotpatch
- VC.Project.VCCLCompilerTool.CreateHotpatchableImage
helpviewer_keywords:
- hot patching
- -hotpatch compiler option [C++]
- /hotpatch compiler option [C++]
- hotpatching
ms.assetid: aad539b6-c053-4c78-8682-853d98327798
ms.openlocfilehash: 8c3431067f04ff36c63143f7d0e7483efa5376ba
ms.sourcegitcommit: 99437d7da4528ce72cabe6b6a65a9be5dfd090f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2018
ms.locfileid: "51598789"
---
# <a name="hotpatch-create-hotpatchable-image"></a>/hotpatch (Criar imagem hotpatchable)

Prepara uma imagem para patch instantâneo.

## <a name="syntax"></a>Sintaxe

```
/hotpatch
```

## <a name="remarks"></a>Comentários

Quando **/hotpatch** é usado em uma compilação, o compilador garante a primeira instrução de cada função tenha pelo menos dois bytes, que é necessário para o patch.

Para concluir a preparação e criar uma imagem hotpatchable, depois de usar **/hotpatch** para compilar, você deve usar [/FUNCTIONPADMIN (Criar imagem de Hotpatchable)](../../build/reference/functionpadmin-create-hotpatchable-image.md) para vincular. Quando você compila e vincula uma imagem usando uma invocação de cl.exe, **/hotpatch** implica **/functionpadmin**.

Como as instruções são sempre de dois bytes ou maiores na arquitetura ARM e porque x64 compilação sempre é tratada como se **/hotpatch** tiver sido especificada, você não precisa especificar **/hotpatch** quando Você pode compilar para esses destinos; No entanto, ainda será necessário vincular usando **/functionpadmin** para criar imagens hotpatchable para eles. O **/hotpatch** compilador opção só afeta x86 compilação.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **C/C++** pasta.

1. Selecione o **linha de comando** página de propriedades.

1. Adicione a opção de compilador para o **opções adicionais** caixa.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)